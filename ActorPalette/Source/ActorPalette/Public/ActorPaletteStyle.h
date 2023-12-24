// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

/**  */
class FActorPaletteStyle
{
public:
	// 初始化样式
	static void Initialize();

	// 结束
	static void Shutdown();

	/** reloads textures used by slate renderer */
	// 重新载入纹理
	static void ReloadTextures();

	/** @return The Slate style set for the Shooter game */
	// 获取样式的实例
	static const ISlateStyle& Get();
	// 获取样式集的名称
	static FName GetStyleSetName();

private:
	// 创建实例
	static TSharedRef< class FSlateStyleSet > Create();

private:
	// 样式实例
	static TSharedPtr< class FSlateStyleSet > StyleInstance;
};