// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DeveloperSettings.h"
#include "UObject/Package.h"
#include "ActorPaletteSettings.generated.h"

// Information about a single recent/favorite map
// 信息关于一个简单的 最近的/喜欢的Map
USTRUCT()
struct FActorPaletteMapEntry
{
	GENERATED_BODY()
	// 这个参数加入了反射，可以在蓝图的任意位置调用
	UPROPERTY(EditAnywhere, Category=ActorPalette)
	FString MapPath; // 地图的路径

	//@TODO: Store viewpoint

	// Was game mode enabled?
// 	UPROPERTY()
// 	uint8 bGameMode : 1;
	// 资产数据 获取资产数据
	FAssetData GetAsAssetData() const;
};

// Settings/preferences for Actor Palettes
// 设置/偏好 为 Actor 绘制板
UCLASS(config=EditorPerProjectUserSettings)
class UActorPaletteSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	// 构造函数
	UActorPaletteSettings();

	// Data model note:
	//  - Every tab remembers the last map they had open
	//  - There is a shared recent maps list (opening a map in any tab will bubble it to the top of the recent list)
	//  - There is a shared favorites list
	//  - While a tab is open it has unique viewport settings, but only the most recent user interaction updates the data in the recent/favorites list
	//@TODO: Nothing purges items out of the recent/favorites list if the map is deleted, though recent list is bounded in size

	// 数据模型 提示：
	// - 每一个Tab推荐最后打开的 map ,那些他们打开的
	// - 这儿共享一个 共享的最近开的Maps列表（打开一个Map在任意tab将被弹出它到里“最近列表的顶端”）
public:
	// Remembered settings for any recent/current/favorite actor palette maps
	// 推荐设置 为 任意 最近/当前/最喜欢 Actor绘制Maps
	// 这里指的是设置里的每个关卡，它是一个汇总的作用
	UPROPERTY(config)
	TArray<FActorPaletteMapEntry> SettingsPerLevel;

	// List of levels that were recently open in any Actor Palette tab
	// 列出关卡 那些 最近打开在任意Actor绘板的Tab
	UPROPERTY(config)
	TArray<FString> RecentlyUsedList;

	// List of levels that were last open in each Actor Palette tab (indexed by tab index)
	// 关卡列表 那些 最后打开 在 Actor 绘板 标签中（编号通过tab的编号）
	UPROPERTY(config)
	TArray<FString> MostRecentLevelByTab;

	// List of levels that were marked as favorite actor palettes
	// 关卡泪飙 被标记为Favorite Actor绘板
	UPROPERTY(config)
	TArray<FString> FavoritesList;

	// Should the 'game mode' show flag be set by default for newly opened actor palettes?
	//UPROPERTY(config, EditAnywhere, Category=ActorPalette)
	//bool bEnableGameModeByDefault = true;

	// How many recent levels will be remembered?
	// 多少最近打开的关卡将被推荐
	UPROPERTY(config, EditAnywhere, Category=ActorPalette, meta=(ClampMin=0, ClampMax=25))
	int32 NumRecentLevelsToKeep = 10;

#if WITH_EDITOR
	//~UObject interface
	// 对象接口
	// 编辑更改参数之后
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	//~End of UObject interface
#endif
	// 查找Map选项
	int32 FindMapEntry(const FString& MapName) const;
	// 查找最后关卡标签
	int32 FindLastLevelForTab(int32 TabIndex) const;

public:
	// 编辑作为最近被使用的
	void MarkAsRecentlyUsed(const FAssetData& MapAsset, int32 TabIndex);
	// 点击Favorite
	void ToggleFavorite(const FAssetData& MapAsset);
	// 修整最近列表
	void TrimRecentList();
};

