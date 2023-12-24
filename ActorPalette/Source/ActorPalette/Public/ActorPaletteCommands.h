// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ActorPaletteStyle.h"

// 对象绘制命令 
class FActorPaletteCommands : public TCommands<FActorPaletteCommands>
{
public:
	// 对象绘制命令的构造（名称“ActorPalette”,本地化文本为（关联菜单,"ActorPalette","ActorPalettePlugin"）,它的父类为空，他的样式为FActorPaletteStyle）
	FActorPaletteCommands()
		: TCommands<FActorPaletteCommands>(TEXT("ActorPalette"), NSLOCTEXT("Contexts", "ActorPalette", "ActorPalette Plugin"), NAME_None, FActorPaletteStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface 注册命令接口
	virtual void RegisterCommands() override;

public:
	// 注册两个指针
	TSharedPtr<FUICommandInfo> ToggleGameView;
	TSharedPtr<FUICommandInfo> ResetCameraView;
};