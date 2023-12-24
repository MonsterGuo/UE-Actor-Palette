// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPaletteStyle.h"
#include "Brushes/SlateBoxBrush.h"
#include "Styling/SlateStyleRegistry.h"
#include "Brushes/SlateImageBrush.h"
#include "Framework/Application/SlateApplication.h"
#include "Interfaces/IPluginManager.h"
#include "Rendering/SlateRenderer.h"
#include "Styling/CoreStyle.h"
#include "Styling/SlateStyle.h"

// 先将样式实例滞空
TSharedPtr< FSlateStyleSet > FActorPaletteStyle::StyleInstance = NULL;

// 初始化
void FActorPaletteStyle::Initialize()
{
	// 如果样式实例是不存在的
	if (!StyleInstance.IsValid())
	{
		// 样式实例 为 创建的
		StyleInstance = Create();
		// Slate样式注册 ：： 注册Slate样式（*样式实例）
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

// 关闭
void FActorPaletteStyle::Shutdown()
{
	// 注销样式（获取样式的实例）
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	//确保这个实例不被引用
	ensure(StyleInstance.IsUnique());
	// 样式实例共享实例，对象重置 （指向nullptr）
	StyleInstance.Reset();
}

// 获取样式，设置名称
FName FActorPaletteStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ActorPaletteStyle"));
	return StyleSetName;
}

// 用宏定义来实现创建一个 FState样式刷（样式中获取“根容器目录”（这个容器的相对路径加尾缀），其他参数）
#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

// 定义一些图标大小的对象，便于复用
const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FActorPaletteStyle::Create()
{
	// 创建一个样式集合，并且命名为（“ActorPaletteStyle”）
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ActorPaletteStyle"));
	// 设置Content的根目录（用插件管理器,查找插件，然后获得基础的目录，拼接目录）
	Style->SetContentRoot(IPluginManager::Get().FindPlugin(TEXT("ActorPalette"))->GetBaseDir() / TEXT("Resources"));

	// 设置“ActorPalette.OpenPluginWindow”，的样式为“ButtonIcon_40x”，这个是插件图标
	Style->Set("ActorPalette.OpenPluginWindow", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));

	// 定义文本块样式 NormalText = 从APP样式中获取，获取部件样式<文本块样式>（NormalText）
	const FTextBlockStyle& NormalText = FAppStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");

	// 设置“ActorPalette.ViewportTitleTextStyle”文本样式
	Style->Set("ActorPalette.ViewportTitleTextStyle", FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 18))		// 设置字体
		.SetColorAndOpacity(FLinearColor(1.0, 1.0f, 1.0f, 0.5f)) // 设置颜色和透明度
		);

	// 设置“ActorPalette.Palette”
	Style->Set("ActorPalette.Palette", new IMAGE_BRUSH(TEXT("Palette_40x"), Icon40x40));
	Style->Set("ActorPalette.Palette.Small", new IMAGE_BRUSH(TEXT("Palette_40x"), Icon20x20));
	// 设置标签图标
	Style->Set("ActorPalette.TabIcon", new IMAGE_BRUSH(TEXT("Palette_16x"), Icon16x16));
	// 设置图标的背景图片
	Style->Set("ActorPalette.ViewportTitleBackground", new BOX_BRUSH("GraphTitleBackground", FMargin(0)));
	// 返回样式
	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

// 重新载入纹理
void FActorPaletteStyle::ReloadTextures()
{
	// Slate应用已经初始化
	if (FSlateApplication::IsInitialized())
	{
		// slateapp，获取到渲染，重新载入纹理资源
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

// 返回指针，以便获取到样式实例
const ISlateStyle& FActorPaletteStyle::Get()
{
	return *StyleInstance;
}
