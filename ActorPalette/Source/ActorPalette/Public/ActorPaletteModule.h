// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class SActorPalette;

// 最大Actor绘制板
#define MAX_ACTOR_PALETTES 4

// 定义一个模块接口类
class FActorPaletteModule : public IModuleInterface
{
public:

	// 模块接口实现
	/** IModuleInterface implementation */
	// 启动模块
	virtual void StartupModule() override;
	// 结束模块
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	// 这个函数将呗绑定到命令（通过默认的，它将打开插件窗口）
	void PluginButtonClicked();
	
private:
	// 生成插件标签，它可以生成标签。主要也是负责注册标签用
	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs, int32 TabIndex);
	// 获取Actor绘制标签带有编号
	static FText GetActorPaletteLabelWithIndex(int32 TabIndex);
	// 获取Actor绘制标签标题
	FText GetActorPaletteTabLabel(int32 TabIndex) const;

private:
	// Actor绘制板的标签信息
	struct FActorPaletteTabInfo
	{
		// 标签ID
		FName TabID;
		// 打开的实例指针
		TWeakPtr<SActorPalette> OpenInstance;
	};
	// Actor绘板的白标签信息数组 Actor绘制板标签【最大Actor绘制板】
	FActorPaletteTabInfo ActorPaletteTabs[MAX_ACTOR_PALETTES];
	// 插件命令的共享指针
	TSharedPtr<class FUICommandList> PluginCommands;
};
