// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPaletteSettings.h"
#include "AssetRegistry/AssetData.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Modules/ModuleManager.h"

// 获取作为资产数据
FAssetData FActorPaletteMapEntry::GetAsAssetData() const
{
	// 资产注册模块 资产注册模块 = 模块管理器::获取到实例.载入模块（资产注册模块）
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	// 资产注册模块.获取到实例（单例）。获取资源通过对象路径（）
	return AssetRegistryModule.Get().GetAssetByObjectPath(FSoftObjectPath(MapPath));
}

// 设置Actor绘板的类别
UActorPaletteSettings::UActorPaletteSettings()
{
	CategoryName = TEXT("Plugins");
}

// 编辑更改参数后
#if WITH_EDITOR
void UActorPaletteSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	// 
	Super::PostEditChangeProperty(PropertyChangedEvent);
	// 刷新近期列表
	TrimRecentList();
}
#endif


// 查找Map选项
int32 UActorPaletteSettings::FindMapEntry(const FString& DesiredName) const
{
	// 设置每一个关卡.谓词编号（这里是谓词表达式）
	return SettingsPerLevel.IndexOfByPredicate([&](const FActorPaletteMapEntry& Entry) { return Entry.MapPath == DesiredName; });
}

// 查找最后的关卡为Tab()
int32 UActorPaletteSettings::FindLastLevelForTab(int32 TabIndex) const
{
	// 最近关卡标签Tab.是否为有效的编号（标签编号）？查找地图选项（最近的关卡Tab[Tab编号]）:不然就是空
	return MostRecentLevelByTab.IsValidIndex(TabIndex) ? FindMapEntry(MostRecentLevelByTab[TabIndex]) : INDEX_NONE;
}

// 表姐为最近使用的
void UActorPaletteSettings::MarkAsRecentlyUsed(const FAssetData& MapAsset, int32 TabIndex)
{
	// 如果Map资产是有效的
	if (MapAsset.IsValid())
	{
		// Map资产路径 = Map资产获取对象路径
		const FString MapAssetPath = MapAsset.GetObjectPathString();

		// Remember as the most recent for this tab
		// 记住作为最近的Tab

		// 如果不是（最近的关卡通过Tab。是有效的编号）
		if (!MostRecentLevelByTab.IsValidIndex(TabIndex))
		{
			// 比如当前只有2个， 第4个窗口，但是Tab的Index=3,所以3+1-2 = 2;就是得添加两个
			// 最近关卡的标签
			MostRecentLevelByTab.AddDefaulted(TabIndex + 1 - MostRecentLevelByTab.Num());
		}
		// 这个得话就直接设置标签的值
		MostRecentLevelByTab[TabIndex] = MapAssetPath;

		// Remember as a recent entry across all tabs, bubbling to the top if is already present
		// 记住作为一个最近的选项 在所有Tab,浮出到顶端如果已经是预设的。
		const int32 RecentIndex = RecentlyUsedList.IndexOfByKey(MapAssetPath);
		// 如果最近的编号存在，我们就和0号元素互换位置。
		if (RecentIndex != INDEX_NONE)
		{
			// 最近的使用列表（将当前编号与第一个元素互换）
			RecentlyUsedList.Swap(0, RecentIndex);
		}
		else
		{
			// 如果不存在，就在0号元素前插入
			RecentlyUsedList.Insert(MapAssetPath, 0);
		}

		// Make sure it's in our list of settings per level
		// 确保它在每个关卡的设置列表中
		// 设置编号 = 查找Map的编号（Map资产路径）
		const int32 SettingsIndex = FindMapEntry(MapAssetPath);
		// 如果设置中编号不存在
		if (SettingsIndex == INDEX_NONE)
		{
			// New entry
			// 新的Entry = 数组中的[添加到末尾]
			FActorPaletteMapEntry& NewEntry = SettingsPerLevel[SettingsPerLevel.AddDefaulted()];
			// 新的枚举 地图路径 = 地图资源中获取的路劲字符串
			NewEntry.MapPath = MapAsset.GetObjectPathString();
		}
	}
	// 剪裁最近列表
	TrimRecentList();

#if WITH_EDITOR
	// 编辑更改后执行
	PostEditChange();
	// 保存配置
	SaveConfig();
#endif
}

// 勾选Favorite(资产数据 Map资产)
void UActorPaletteSettings::ToggleFavorite(const FAssetData& MapAsset)
{
	// 如果最喜欢的列表中包含了路径
	if (FavoritesList.Contains(MapAsset.GetObjectPathString()))
	{
		// 再点一下就相当于移除
		FavoritesList.Remove(MapAsset.GetObjectPathString());
	}
	else
	{
		// 否则就是添加
		FavoritesList.Add(MapAsset.GetObjectPathString());
	}

#if WITH_EDITOR
	// 发布/提交 编辑更改
	PostEditChange();
	// 保存配置
	SaveConfig();
#endif
}

// 修检最近列表
void UActorPaletteSettings::TrimRecentList()
{
	// Trim the end of the recent list
	// 剪裁 最近列表的末端
	const int32 EffectiveLimit = FMath::Max(NumRecentLevelsToKeep, 0);
	// 如果 最近列表的数目 大于 有效列表数目
	while (RecentlyUsedList.Num() > EffectiveLimit)
	{
		// 最近列表就移除最后一个
		RecentlyUsedList.RemoveAt(RecentlyUsedList.Num() - 1);
	}

	// Determine what per-map settings to keep alive
	// 确定 每个地图的设置保持有效
	
	// 这里将所有列表汇总
	TSet<FString> InterestingLevels;
	InterestingLevels.Append(RecentlyUsedList);
	InterestingLevels.Append(FavoritesList);
	InterestingLevels.Append(MostRecentLevelByTab);

	// And remove settings that are no longer in any list
	// 并删除不再在任何列表中的设置
	SettingsPerLevel.RemoveAllSwap([&](const FActorPaletteMapEntry& Entry) { return !InterestingLevels.Contains(Entry.MapPath); });
}
