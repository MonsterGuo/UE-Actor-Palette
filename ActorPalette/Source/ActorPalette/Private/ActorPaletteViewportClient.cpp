// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPaletteViewportClient.h"
#include "Framework/Application/SlateApplication.h"
#include "EngineUtils.h"
#include "Engine/LevelStreamingDynamic.h"
#include "DragAndDrop/AssetDragDropOp.h"
#include "InputKeyEventArgs.h"
#include "MouseDeltaTracker.h"
#include "ActorPaletteSettings.h"
#include "Misc/ScopedSlowTask.h"
#include "Selection.h"
#include "Widgets/SWindow.h"
#include "SEditorViewport.h"
#include "Components/DirectionalLightComponent.h"
#include "Engine/StaticMesh.h"
#include "UnrealClient.h"

#define LOCTEXT_NAMESPACE "ActorPalette"

//////////////////////////////////////////////////////////////////////////
// FActorPaletteViewportClient

FActorPaletteViewportClient::FActorPaletteViewportClient(int32 InTabIndex)
	: FEditorViewportClient(nullptr, nullptr, nullptr)
	, TabIndex(InTabIndex)
{
	SetViewModes(VMI_Lit, VMI_Lit);
	// Get the correct general direction of the perspective mode; the distance doesn't matter much as we've queued up a deferred zoom that will calculate a much better distance
	//@TODO: Save/load camera views into settings... (SetInitialViewTransform + SetViewportType)
	MyBGColor = FLinearColor::Black;
	SetRealtime(false);
	SetPreviewingScreenPercentage(true);
	SetPreviewScreenPercentage(80);
	PreviewScene = &OwnedPreviewScene;
	PreviewScene->DirectionalLight->SetVisibility(false);
	PreviewScene->DirectionalLight->SetActive(false);
	EngineShowFlags.Selection = true;
	EngineShowFlags.SelectionOutline = true;
	EngineShowFlags.Grid = true;
	DrawHelper.bDrawGrid = true;
	EngineShowFlags.DisableAdvancedFeatures();
}

// 输入键（输入事件参数）
bool FActorPaletteViewportClient::InputKey(const FInputKeyEventArgs& InEventArgs)
{
	// 如果输入参数为左键
	if (InEventArgs.Key == EKeys::LeftMouseButton)
	{
		FString re = EngineShowFlags.BillboardSprites? "True":"false";
		UE_LOG(LogTemp,Warning,TEXT("%s"),*re)
		// 如果（拖拽放下就是直接返回）
		if (FSlateApplication::Get().IsDragDropping())
		{
			//UE_LOG(LogTemp,Warning,TEXT("DragDropping"))
			if(InEventArgs.Viewport->GetMouseX() >0 && InEventArgs.Viewport->GetMouseX() < InEventArgs.Viewport->GetSizeXY().X &&
			InEventArgs.Viewport->GetMouseY()>0 && InEventArgs.Viewport->GetMouseY() < InEventArgs.Viewport->GetSizeXY().Y
			 )
			{
				FSlateApplication::Get().CancelDragDrop();
				USelection* CBSelection = GEditor->GetSelectedActors();
				CBSelection->DeselectAll();
			}
			return true;
		}
		
		// 获取碰撞的X坐标
		const int32	HitX = InEventArgs.Viewport->GetMouseX();
		// 获取碰撞的Y坐标
		const int32	HitY = InEventArgs.Viewport->GetMouseY();
		
		// Calc the raw delta from the mouse to detect if there was any movement
		// 计算来自鼠标的原始增量，以检测是否有任何移动
		FVector RawMouseDelta = MouseDeltaTracker->GetRawDelta();
		
		// Note: We are using raw mouse movement to double check distance moved in low performance situations.  In low performance situations its possible
		// that we would get a mouse down and a mouse up before the next tick where GEditor->MouseMovment has not been updated.
		// In that situation, legitimate drags are incorrectly considered clicks
		
		// 提示: 我们使用原始鼠标移动来双重检查在低性能情况下移动的距离。
		// 在GEditor->MouseMovment尚未更新的下一个滴答之前，我们会先按下鼠标，然后再按下鼠标。
		// 在这种情况下，合法的拖动会被错误地视为点击
		//bool bNoMouseMovment = RawMouseDelta.SizeSquared() < MOUSE_CLICK_DRAG_DELTA && GEditor->MouseMovement.SizeSquared() < MOUSE_CLICK_DRAG_DELTA;
		bool bNoMouseMovment = GEditor->MouseMovement.SizeSquared() < MOUSE_CLICK_DRAG_DELTA;
		// 如果（不存在鼠标移动 并且 鼠标增量跟踪器不存在有效的移动）
		if (bNoMouseMovment && !MouseDeltaTracker->WasExternalMovement())
		{
			// If the mouse haven't moved too far, treat the button release as a click.
			// 如果鼠标没有移动太远，则将按钮释放视为单击。
		}
		else
		{
			// 点击代理 = 事件参数.视口->获取点击的代理（坐标）
			HHitProxy* HitProxy = InEventArgs.Viewport->GetHitProxy(HitX, HitY);
			// HActor是HitActor = 集中的代理中<HActor>（击中的代理）
			if (HActor* ActorProxy = HitProxyCast<HActor>(HitProxy))
			{
				// 如果（击中的Actor不为空 并且 Actor代理的对象没锁定位置）
				if ((ActorProxy->Actor != nullptr) && !ActorProxy->Actor->IsLockLocation())
				{
					// 资产
					TArray<UObject*> Assets;
					// 对象代理 ->Actor->获取引用的内容对象（资产数）
					ActorProxy->Actor->GetReferencedContentObjects(Assets);
					// 如果（资产数目>0 并且 资产[0]不为空）
					if ((Assets.Num() > 0) && (Assets[0] != nullptr))
					{
						// 选择的对象（他是用来管理选择对象的）  = 从引擎获取选择对象
						USelection* CBSelection = GEditor->GetSelectedActors();
						// 让选择器
						CBSelection->Select(ActorProxy->Actor,true);
						//CBSelection->ToggleSelect(ActorProxy->Actor);
						// 对象代理->拿到对象->标记组件渲染状态”Dirty“
						ActorProxy->Actor->MarkComponentsRenderStateDirty();
						// 无效
						Invalidate();
						// 取消拖拽
						FSlateApplication::Get().CancelDragDrop();
						// 当前鼠标坐标 = 获取鼠标位置
						const FVector2D CurrentCursorPosition = FSlateApplication::Get().GetCursorPos();
						// 最后鼠标位置 = 获取最后的鼠标位置
						const FVector2D LastCursorPosition = FSlateApplication::Get().GetLastCursorPos();
						TArray<FAssetData> AssetDatas;
						
						// 拖放操作 = 资产拖拽操作
						TSharedPtr<FAssetDragDropOp> DragDropOperation = FAssetDragDropOp::New(FAssetData(Assets[0], true));
						
						// 点击鼠标按键
						TSet<FKey> PressedMouseButtons;
						PressedMouseButtons.Add(InEventArgs.Key);
				
						FModifierKeysState ModifierKeyState;
				
						FPointerEvent FakePointerEvent(
							FSlateApplication::Get().GetUserIndexForMouse(),
							FSlateApplicationBase::CursorPointerIndex,
							CurrentCursorPosition,
							LastCursorPosition,
							PressedMouseButtons,
							EKeys::Invalid,
							0,
							ModifierKeyState);
				
						// Tell slate to enter drag and drop mode.
						// 告诉slate进入拖放模式。
						// Make a faux mouse event for slate, so we can initiate a drag and drop.
						// 为slate创建一个伪鼠标事件，这样我们就可以启动一个拖放操作。
						FDragDropEvent DragDropEvent(FakePointerEvent, DragDropOperation);
						// 获取拥有的窗口
						TSharedPtr<SWindow> OwnerWindow = FSlateApplication::Get().FindWidgetWindow(GetEditorViewportWidget().ToSharedRef());
						
						FSlateApplication::Get().ProcessDragEnterEvent(OwnerWindow.ToSharedRef(), DragDropEvent);
					}
				}
			}
			
		}
		return true;
	}
	else
	{
		FInputKeyEventArgs Args = InEventArgs;
		Args.Key = (InEventArgs.Key == EKeys::RightMouseButton) ? EKeys::LeftMouseButton : InEventArgs.Key;
		return FEditorViewportClient::InputKey(Args);
	}
}


// 打开世界作为 
void FActorPaletteViewportClient::OpenWorldAsPalette(const FAssetData& InSourceWorldAsset)
{
	// 打开操作是一个缓慢操作，这么标记可以避免崩溃
	FScopedSlowTask SlowTask(0.0f, LOCTEXT("LoadingLevelAsPalette", "Loading Level into Actor Palette..."));
	// 目标世界
	UWorld* TargetWorld = OwnedPreviewScene.GetWorld();

	// 如果当前关卡流不为空
	if (CurrentLevelStreaming != nullptr)
	{
		// 设置是否请求卸载并且移除
		CurrentLevelStreaming->SetIsRequestingUnloadAndRemoval(true);
		// 清空关卡流
		TargetWorld->FlushLevelStreaming(EFlushLevelStreamingType::Full);
		// 把当前关卡流清空
		CurrentLevelStreaming = nullptr;
	}

	// Copy if the source world is valid
	// 拷贝 如果 源世界是有效的
	SourceWorldAsset = InSourceWorldAsset;
	// 源世界能被正常的转换
	if (UWorld* SourceWorld = Cast<UWorld>(SourceWorldAsset.GetAsset()))
	{
		// 是否成功
		bool bSucceeded;
		// 新的关卡 = 动态关卡流::载入关卡实例（目标世界，关卡名，位置，旋转，成功的标识）
		ULevelStreamingDynamic* NewLevel = ULevelStreamingDynamic::LoadLevelInstance(TargetWorld, SourceWorld->GetPathName(), FVector::ZeroVector, FRotator::ZeroRotator, /*out*/ bSucceeded);

		// 如果成功
		if (bSucceeded)
		{
			//@TODO: This is a squiffy workaround for ULevelStreamingDynamic::LoadLevelInstance doing the wrong thing if the level is already loaded and we're not in PIE
			// (this doesn't make it go down the code path that makes it work in PIE, it just guarantees the destination name isn't the same as the asset name anymore...)
			
			//@TODO: 这是ULevelStreamingDynamic::LoadLevelInstance做错误的事情，如果关卡已经加载，我们不在PIE中
			// (这不会使其沿着使其在PIE中工作的代码路径运行，它只是保证目标名称不再与资产名称相同……)
			NewLevel->RenameForPIE(1);
			// 将关卡流赋予新的值
			CurrentLevelStreaming = NewLevel;
			// 再次刷新
			TargetWorld->FlushLevelStreaming(EFlushLevelStreamingType::Full);
			// 目标世界.编辑视图 = 源世界。编辑视图
			TargetWorld->EditorViews = SourceWorld->EditorViews;
			// 重置相机视图
			ResetCameraView();
		}
	}

	// Update the most-recently used list
	// 更新最近的被用的列表 
	UActorPaletteSettings* Settings = GetMutableDefault<UActorPaletteSettings>();
	// 设置中标记最近被使用的部分（世界的资产，还要标签的编号）
	Settings->MarkAsRecentlyUsed(SourceWorldAsset, TabIndex);

	// Redraw the viewport
	// 重新绘制视口
	Invalidate();
}

// 获取背景颜色
FLinearColor FActorPaletteViewportClient::GetBackgroundColor() const
{
	return MyBGColor;
}
// 重置相机
void FActorPaletteViewportClient::ResetCameraView()
{
	UWorld* World = OwnedPreviewScene.GetWorld();

	// 如果（获取当前的世界，是否为有效的编号（获取视窗类型））
	if (World->EditorViews.IsValidIndex(GetViewportType()))
	{
		// 获取关卡视图的信息
		FLevelViewportInfo& ViewportInfo = World->EditorViews[GetViewportType()];
		//UE_LOG(LogTemp,Warning,TEXT("Current Viewport Type:%d"),GetViewportType())
		// 设置初始的位移
		SetInitialViewTransform(
			// 获取视口的类型
			GetViewportType(),
			// 相机的位置
			ViewportInfo.CamPosition,
			// 相机的旋转
			ViewportInfo.CamRotation,
			// 相机正射影变焦
			ViewportInfo.CamOrthoZoom);
	}
}



// 这个是为了可以Tick
void FActorPaletteViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);
	
	// Tick the preview scene world.
	PreviewScene->GetWorld()->Tick(LEVELTICK_ViewportsOnly, DeltaSeconds);
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
