// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPalette.h"
#include "ActorPaletteViewport.h"
#include "ActorPaletteViewportClient.h"

//////////////////////////////////////////////////////////////////////
// SActorPalette

void SActorPalette::Construct(const FArguments& InArgs, int32 InTabIndex)
{
	// Tab编号 
	TabIndex = InTabIndex;
	// Actor绘板视口客户端  这个共享指针，为的是不存在引用计数就自动释放。（简直棒呆.）
	ActorPaletteViewportClient = MakeShareable(new FActorPaletteViewportClient(TabIndex));
	// Actor绘制板视窗 = SNew是新建一个Widget对象（SActor绘板视口，视口的客户端，标签编号）
	ActorPaletteViewport = SNew(SActorPaletteViewport, ActorPaletteViewportClient, TabIndex);
	// Actor绘制视口客户端->设置它拥有的部件
	ActorPaletteViewportClient->SetOwnerWidget(ActorPaletteViewport);
	// 子插槽
	ChildSlot
	[
		// Actor绘板视口，转成共享引用
		ActorPaletteViewport.ToSharedRef()
	];
}
