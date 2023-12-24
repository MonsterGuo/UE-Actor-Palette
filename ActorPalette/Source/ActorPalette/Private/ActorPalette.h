// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/SCompoundWidget.h"

class SActorPaletteViewport;
class FActorPaletteViewportClient;

//////////////////////////////////////////////////////////////////////
// Actor绘制板的Slate 来自 组件Widget的Slate
class SActorPalette : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SActorPalette) {}
	SLATE_END_ARGS()

public:
	// 构造函数（参数，输入的Tab编号）
	void Construct(const FArguments& InArgs, int32 InTabIndex);

private:
	// Actor绘制视口
	TSharedPtr<SActorPaletteViewport> ActorPaletteViewport;
	// Actor绘制视口的客户端
	TSharedPtr<FActorPaletteViewportClient> ActorPaletteViewportClient;
	// Tab编号
	int32 TabIndex;
};
