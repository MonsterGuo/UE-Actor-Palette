// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPaletteModule.h"
// Actor绘制命令
#include "ActorPaletteCommands.h"
// Docking栏
#include "Widgets/Docking/SDockTab.h"
// UI命令列表
#include "Framework/Commands/UICommandList.h"

// 工作空间菜单结构体模块
#include "WorkspaceMenuStructureModule.h"
// 工作空间菜单结构体
#include "WorkspaceMenuStructure.h"
// Actor绘制
#include "ActorPalette.h"

// Core functionality/bugs:
//@TODO: Clear selection state (& invalidate) when drop finished or aborted
//@TODO: Support factorying using actual actor settings (everything but position / rotation, including scale, different material, etc...)
//@TODO: See if we can proper drag-drop behavior (right now the fake drag doesn't fizzle if the mouse is released, and in fact only renders correctly as a preview into the main frame if you release first)
//@TODO: Better workaround (or real fix) for the RenameForPIE hack 

// 核心 功能/bugs
//@TODO: 清除选中状态（& 无效） 当拖拽结束或者取消
//@TODO: 支持工厂 使用实际Actor的设置（所有事情，但是不包括位置/旋转，包括缩放，不同的材质，等等）
//@TODO: 查看 是否有更好的拖拽行为（现在，如果释放鼠标，假拖动不会失败，事实上，只有在您首先释放的情况下，才能正确地呈现为主框架的预览）
//@TODO：RenameForPIE破解的更好的解决方案(或真正的修复)

// Important UX stuff:
//@TODO: Save/restore camera position for LRU/favorites
//@TODO: Try doing a timer or something to refresh the non-realtime viewport a few seconds after map load to compensate for texture streaming blurriness 

// 重要的用户体验选项
//@TODO: 保存/恢复相机位置从LRU和最喜欢的
//@TODO: 尝试做一个 事件条 或者 在地图加载后几秒钟刷新非实时视口，以补偿纹理流模糊

// Random ideas:
// - Bookmark support (using existing ones, not setting them IMO)
// - Better bookmarks (setting names for example) then showing them as preset buttons on the left side of the viewport
// - Click-drag to pan on LMB that misses meshes
// - Setting for whether or not 'game mode' is enabled by default / remember game mode setting
// - Auto-reload if map being viewed gets saved in the editor
// - Same but for links to other maps, or just create something visual I can double-click on the map itself (or teleport hyperlinks)
// - Support for materials (e.g., detect if it's a material demo kiosk and drag-drop the material instead of the mesh)
// - Store the source map..actor path in package metadata for placed instances and provide a key bind to focus it back (Shift+Ctrl+B maybe?)
// - Add keybinds to cycle between related objects in a set (using metadata on the placed instance linking it back to template map, along with set/chain metadata in the template map or via an associated collection)
//     Should this destroy the existing actor and spawn a new one, only copying transform, or should it do something crazier like try to delta
//     serialize against old template and apply diffs to new template (getting into CPFUO land...)
// - Keybind to randomize Z rotation for selected object (totally unrelated to actor palette, just might be a nice level editor feature?)
// - Picker-style shortcut to let it be used without keeping it up all the time
// - Multi-select (Ctrl+click) when in click but not drag mode?  (unsure if I want to keep it working like it is, see note above in core functionality; could lean on grouping instead if stuff is meant to be placed together)

// 自由的想法
// - 书签支持（使用现有的，而不是设置它们）
// - 更好的书签 （设置名称为示例） 然后 显示他们作为预设按键，在视窗的左侧
// - 单击并拖动以在缺少网格的LMB上平移
// - 默认情况下是否启用‘游戏模式’的设置/记住游戏模式设置
// - 如果在编辑器中保存了正在查看的地图，则自动重新加载
// - 相同的，但链接到其他地图，或只是创建一些可视化的东西，我可以双击地图本身(或传送超链接)
// - 支持材质（例如，检测它是否是材质演示场景，并拖放材质而不是网格体）
// - 将源map..actor路径存储在放置实例的包元数据中，并提供一个键绑定来聚焦它(可能是Shift+Ctrl+B ?)
// - 添加“键值绑定”去循环相关对象在一个Set中（在放置的实例上使用元数据将其链接回模板映射，
//		以及模板映射中的set/chain元数据或通过关联的集合)这是否应该破坏现有的actor并产生一个新的actor，仅复制转换，
//		或者应该做一些更疯狂的事情，例如尝试对旧模板进行增量序列化并对新模板应用差异(进入CPFUO领域…)）
// - 键绑定到可以选择对象的随机Z轴旋转(与角色调色板完全无关，可能只是一个不错的关卡编辑器功能?)
// - 选择风格的快捷方式，让它可以使用，而不必一直保持它
// - 多选（Ctrl+Click）当 点击，但不是拖拽模式下？（不确定如果我们想要保持它工作像这样，查看提示在核心函数之上，如果要把东西放在一起，可以采用分组方式。）

// Might be bridging too far into foliage / placement tools land here:
// - Support for stamp mode (keep placing instances until you press Escape)
// - Support for optional random z rotation?


//可能在这里过多地使用了树叶/放置工具
// - 支持图章模式(一直放置实例，直到按Esc键)
// - 支持可选的随机z旋转？


#define LOCTEXT_NAMESPACE "ActorPalette"

//////////////////////////////////////////////////////////////////////
// FActorPaletteModule

// 启动模块
void FActorPaletteModule::StartupModule()
{
	// 初始化
	FActorPaletteStyle::Initialize();
	// 重新载入纹理
	FActorPaletteStyle::ReloadTextures();
	// 注册
	FActorPaletteCommands::Register();
	// 插件命令 创建一个新的（UI命令列表）
	PluginCommands = MakeShareable(new FUICommandList);

	// Register tab spawners for the actor palette tabs
	// 注册标签生成器 为 Actor画板标签（获取样式集，中名为“ActorPalette.TabIcon”）
	const FSlateIcon ActorPaletteIcon(FActorPaletteStyle::GetStyleSetName(), "ActorPalette.TabIcon");
	// 获取一个工作区菜单的结构体
	const IWorkspaceMenuStructure& MenuStructure = WorkspaceMenu::GetMenuStructure();
	// Actor绘制组 = 菜单结构体，获取工具类别， 添加组（“ActorPalette”,文本解释“打开一个Actor绘制板标签”。Actor绘制板图标，是否包含子集）
	TSharedRef<FWorkspaceItem> ActorPaletteGroup = MenuStructure.GetToolsCategory()->AddGroup(
		LOCTEXT("WorkspaceMenu_ActorPaletteCategory", "Actor Palette"),
		LOCTEXT("ActorPaletteMenuTooltipText", "Open an Actor Palette tab."),
		ActorPaletteIcon,
		true);
	// 遍历ActorPaletteTabs的数目
	for (int32 TabIndex = 0; TabIndex < UE_ARRAY_COUNT(ActorPaletteTabs); TabIndex++)
	{
		// 给定标签ID
		const FName TabID = FName(*FString::Printf(TEXT("ActorPaletteTab%d"), TabIndex + 1));
		// Actor绘板标签信息 给标签ID赋值
		ActorPaletteTabs[TabIndex].TabID = TabID;
		// 全局Tab管理器::然后获取到实例-> 注册游动的Tab生成器（标签ID,然后生成标签的回调::创建绑定（this(对象),Actor绘制模块::生成插件标签，带有一个参数））
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabID, FOnSpawnTab::CreateRaw(this, &FActorPaletteModule::OnSpawnPluginTab, TabIndex))
			// 设置显示名称（）
			.SetDisplayName(GetActorPaletteLabelWithIndex(TabIndex))
			// 设置提示文本文字（"Open an Actor Palette tab."）
			.SetTooltipText(LOCTEXT("ActorPaletteMenuTooltipText", "Open an Actor Palette tab."))
			// 设置所属的组（）
 			.SetGroup(ActorPaletteGroup)
			// 设置图标
 			.SetIcon(ActorPaletteIcon);
	}
}


// 结束模块
void FActorPaletteModule::ShutdownModule()
{
	// 结束样式
	FActorPaletteStyle::Shutdown();
	// 注销命令
	FActorPaletteCommands::Unregister();
	// 注销所有游动的标签生成器
	for (int32 TabIndex = 0; TabIndex < UE_ARRAY_COUNT(ActorPaletteTabs); ++TabIndex)
	{
		// 从全局的Tab管理器卸载这些标签
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(ActorPaletteTabs[TabIndex].TabID);
	}
}

// 生成插件Tab(生成Tab参数，Tab的编号)
TSharedRef<SDockTab> FActorPaletteModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs, int32 TabIndex)
{
	// 新的绘制板的引用 
	TSharedRef<SActorPalette> NewPalette = SNew(SActorPalette, TabIndex);
	// 校验这个是不是空的
	check(!ActorPaletteTabs[TabIndex].OpenInstance.IsValid());
	// Actor绘制标签
	ActorPaletteTabs[TabIndex].OpenInstance = NewPalette;
	// 选项卡标签 = 参数<文字>::创建（Text参数：：获取器：：创建绑定（这个，Actor绘板::获取Actor绘板选项卡标签，选项卡编号））
	TAttribute<FText> TabLabel = TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateRaw(this, &FActorPaletteModule::GetActorPaletteTabLabel, TabIndex));

	// 共享引用<SDockTab> 结果Tab = 新建（SDockTab）
	TSharedRef<SDockTab> ResultTab = SNew(SDockTab)
		//Tab的角色(标签类型)
		.TabRole(ETabRole::NomadTab)
		// 标签名
		.Label(TabLabel)
		[
			NewPalette
		];

	return ResultTab;
}

// 获取Actor绘制标签带有编号
FText FActorPaletteModule::GetActorPaletteLabelWithIndex(int32 TabIndex)
{
	// 格式化输出文本
	return FText::Format(LOCTEXT("ActorPaletteTabNameWithIndex", "Actor Palette {0}"), FText::AsNumber(TabIndex + 1));
}

// 获取Actor绘制Tab标签
FText FActorPaletteModule::GetActorPaletteTabLabel(int32 TabIndex) const
{
	// 打开绘板的数目
	int32 NumOpenPalettes = 0;
	// Actor绘Tab
	for (const FActorPaletteTabInfo& TabInfo : ActorPaletteTabs)
	{
		// 如果Tab信息，打开的实例是有效的。打开的绘板数量+1
		NumOpenPalettes += TabInfo.OpenInstance.IsValid() ? 1 : 0;
	}
	// 返回 （如果打开绘制板数目大于1） 那么绘制板的名字就是Actor Palette 加编号 ：不然就是Actor Palette
	return (NumOpenPalettes > 1) ? GetActorPaletteLabelWithIndex(TabIndex) : LOCTEXT("ActorPaletteTabNoIndex", "Actor Palette");
}

// 关闭本地文本命名空间
#undef LOCTEXT_NAMESPACE

// 实现模块
IMPLEMENT_MODULE(FActorPaletteModule, ActorPalette)
