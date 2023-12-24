// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "PreviewScene.h"
#include "EditorViewportClient.h"
#include "DragAndDrop/AssetDragDropOp.h"

class FCanvas;
class FScopedTransaction;
class FUICommandList;
class ULevelStreamingDynamic;

//////////////////////////////////////////////////////////////////////////
// FActorPaletteViewportClient

class FActorPaletteViewportClient : public FEditorViewportClient
{
public:
	FActorPaletteViewportClient(int32 InTabIndex);

	// FViewportClient interface
	virtual bool InputKey(const FInputKeyEventArgs& InEventArgs) override;
	virtual void Tick(float DeltaSeconds) override;
	// End of FViewportClient interface

	// FEditorViewportClient interface
	virtual FLinearColor GetBackgroundColor() const override;
	// End of FEditorViewportClient interface
	// 打开世界作为绘板
	void OpenWorldAsPalette(const FAssetData& SourceWorldAsset);
	// 获取当前世界的资产数据
	FAssetData GetCurrentWorldAssetData() const { return SourceWorldAsset; }

	// 设置它拥有的视口
	void SetOwnerWidget(const TWeakPtr<SEditorViewport> OwnerPtr)
	{
		EditorViewportWidget = OwnerPtr;
	}
	// 重置相机视口
	void ResetCameraView();

private:
	int32 TabIndex;

	// The preview scene 预览场景
	FPreviewScene OwnedPreviewScene;
	// 源的世界资产
	FAssetData SourceWorldAsset;
	// 当前的关卡流送
	ULevelStreamingDynamic* CurrentLevelStreaming = nullptr;
	// 背景颜色
	FLinearColor MyBGColor;
};
