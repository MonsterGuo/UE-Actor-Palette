// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPaletteCommands.h"

#define LOCTEXT_NAMESPACE "ActorPalette"

void FActorPaletteCommands::RegisterCommands()
{
	// UI_命令绑定（开启游戏视图, "游戏视图"， 启用游戏视图，接口类型为::勾选键，输入快捷建为（G））
	UI_COMMAND(ToggleGameView, "Game View", "Toggles game view.  Game view shows the scene as it appears in game", EUserInterfaceActionType::ToggleButton, FInputChord(EKeys::G));
	// UI_命令绑定（重置相机视图，用户接口类型按键，输入快捷键没有）
	UI_COMMAND(ResetCameraView, "Reset Camera", "Resets the camera view", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
