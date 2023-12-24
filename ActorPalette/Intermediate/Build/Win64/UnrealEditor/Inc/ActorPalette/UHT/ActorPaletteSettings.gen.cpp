// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActorPalette/Private/ActorPaletteSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorPaletteSettings() {}
// Cross Module References
	ACTORPALETTE_API UClass* Z_Construct_UClass_UActorPaletteSettings();
	ACTORPALETTE_API UClass* Z_Construct_UClass_UActorPaletteSettings_NoRegister();
	ACTORPALETTE_API UScriptStruct* Z_Construct_UScriptStruct_FActorPaletteMapEntry();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	UPackage* Z_Construct_UPackage__Script_ActorPalette();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry;
class UScriptStruct* FActorPaletteMapEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActorPaletteMapEntry, (UObject*)Z_Construct_UPackage__Script_ActorPalette(), TEXT("ActorPaletteMapEntry"));
	}
	return Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry.OuterSingleton;
}
template<> ACTORPALETTE_API UScriptStruct* StaticStruct<FActorPaletteMapEntry>()
{
	return FActorPaletteMapEntry::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MapPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_MapPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "// Information about a single recent/favorite map\n// \xe4\xbf\xa1\xe6\x81\xaf\xe5\x85\xb3\xe4\xba\x8e\xe4\xb8\x80\xe4\xb8\xaa\xe7\xae\x80\xe5\x8d\x95\xe7\x9a\x84 \xe6\x9c\x80\xe8\xbf\x91\xe7\x9a\x84/\xe5\x96\x9c\xe6\xac\xa2\xe7\x9a\x84Map\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "Information about a single recent/favorite map\n\xe4\xbf\xa1\xe6\x81\xaf\xe5\x85\xb3\xe4\xba\x8e\xe4\xb8\x80\xe4\xb8\xaa\xe7\xae\x80\xe5\x8d\x95\xe7\x9a\x84 \xe6\x9c\x80\xe8\xbf\x91\xe7\x9a\x84/\xe5\x96\x9c\xe6\xac\xa2\xe7\x9a\x84Map" },
	};
#endif
	void* Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActorPaletteMapEntry>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewProp_MapPath_MetaData[] = {
		{ "Category", "ActorPalette" },
		{ "Comment", "// \xe8\xbf\x99\xe4\xb8\xaa\xe5\x8f\x82\xe6\x95\xb0\xe5\x8a\xa0\xe5\x85\xa5\xe4\xba\x86\xe5\x8f\x8d\xe5\xb0\x84\xef\xbc\x8c\xe5\x8f\xaf\xe4\xbb\xa5\xe5\x9c\xa8\xe8\x93\x9d\xe5\x9b\xbe\xe7\x9a\x84\xe4\xbb\xbb\xe6\x84\x8f\xe4\xbd\x8d\xe7\xbd\xae\xe8\xb0\x83\xe7\x94\xa8\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "\xe8\xbf\x99\xe4\xb8\xaa\xe5\x8f\x82\xe6\x95\xb0\xe5\x8a\xa0\xe5\x85\xa5\xe4\xba\x86\xe5\x8f\x8d\xe5\xb0\x84\xef\xbc\x8c\xe5\x8f\xaf\xe4\xbb\xa5\xe5\x9c\xa8\xe8\x93\x9d\xe5\x9b\xbe\xe7\x9a\x84\xe4\xbb\xbb\xe6\x84\x8f\xe4\xbd\x8d\xe7\xbd\xae\xe8\xb0\x83\xe7\x94\xa8" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewProp_MapPath = { "MapPath", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActorPaletteMapEntry, MapPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewProp_MapPath_MetaData), Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewProp_MapPath_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewProp_MapPath,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ActorPalette,
		nullptr,
		&NewStructOps,
		"ActorPaletteMapEntry",
		Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::PropPointers),
		sizeof(FActorPaletteMapEntry),
		alignof(FActorPaletteMapEntry),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FActorPaletteMapEntry()
	{
		if (!Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry.InnerSingleton, Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry.InnerSingleton;
	}
	void UActorPaletteSettings::StaticRegisterNativesUActorPaletteSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UActorPaletteSettings);
	UClass* Z_Construct_UClass_UActorPaletteSettings_NoRegister()
	{
		return UActorPaletteSettings::StaticClass();
	}
	struct Z_Construct_UClass_UActorPaletteSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SettingsPerLevel_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SettingsPerLevel_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SettingsPerLevel;
		static const UECodeGen_Private::FStrPropertyParams NewProp_RecentlyUsedList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RecentlyUsedList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RecentlyUsedList;
		static const UECodeGen_Private::FStrPropertyParams NewProp_MostRecentLevelByTab_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MostRecentLevelByTab_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_MostRecentLevelByTab;
		static const UECodeGen_Private::FStrPropertyParams NewProp_FavoritesList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FavoritesList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_FavoritesList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumRecentLevelsToKeep_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumRecentLevelsToKeep;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorPaletteSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_ActorPalette,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorPaletteSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Settings/preferences for Actor Palettes\n// \xe8\xae\xbe\xe7\xbd\xae/\xe5\x81\x8f\xe5\xa5\xbd \xe4\xb8\xba Actor \xe7\xbb\x98\xe5\x88\xb6\xe6\x9d\xbf\n" },
		{ "IncludePath", "ActorPaletteSettings.h" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "Settings/preferences for Actor Palettes\n\xe8\xae\xbe\xe7\xbd\xae/\xe5\x81\x8f\xe5\xa5\xbd \xe4\xb8\xba Actor \xe7\xbb\x98\xe5\x88\xb6\xe6\x9d\xbf" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel_Inner = { "SettingsPerLevel", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActorPaletteMapEntry, METADATA_PARAMS(0, nullptr) }; // 3663705510
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel_MetaData[] = {
		{ "Comment", "// Remembered settings for any recent/current/favorite actor palette maps\n// \xe6\x8e\xa8\xe8\x8d\x90\xe8\xae\xbe\xe7\xbd\xae \xe4\xb8\xba \xe4\xbb\xbb\xe6\x84\x8f \xe6\x9c\x80\xe8\xbf\x91/\xe5\xbd\x93\xe5\x89\x8d/\xe6\x9c\x80\xe5\x96\x9c\xe6\xac\xa2 Actor\xe7\xbb\x98\xe5\x88\xb6Maps\n// \xe8\xbf\x99\xe9\x87\x8c\xe6\x8c\x87\xe7\x9a\x84\xe6\x98\xaf\xe8\xae\xbe\xe7\xbd\xae\xe9\x87\x8c\xe7\x9a\x84\xe6\xaf\x8f\xe4\xb8\xaa\xe5\x85\xb3\xe5\x8d\xa1\xef\xbc\x8c\xe5\xae\x83\xe6\x98\xaf\xe4\xb8\x80\xe4\xb8\xaa\xe6\xb1\x87\xe6\x80\xbb\xe7\x9a\x84\xe4\xbd\x9c\xe7\x94\xa8\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "Remembered settings for any recent/current/favorite actor palette maps\n\xe6\x8e\xa8\xe8\x8d\x90\xe8\xae\xbe\xe7\xbd\xae \xe4\xb8\xba \xe4\xbb\xbb\xe6\x84\x8f \xe6\x9c\x80\xe8\xbf\x91/\xe5\xbd\x93\xe5\x89\x8d/\xe6\x9c\x80\xe5\x96\x9c\xe6\xac\xa2 Actor\xe7\xbb\x98\xe5\x88\xb6Maps\n\xe8\xbf\x99\xe9\x87\x8c\xe6\x8c\x87\xe7\x9a\x84\xe6\x98\xaf\xe8\xae\xbe\xe7\xbd\xae\xe9\x87\x8c\xe7\x9a\x84\xe6\xaf\x8f\xe4\xb8\xaa\xe5\x85\xb3\xe5\x8d\xa1\xef\xbc\x8c\xe5\xae\x83\xe6\x98\xaf\xe4\xb8\x80\xe4\xb8\xaa\xe6\xb1\x87\xe6\x80\xbb\xe7\x9a\x84\xe4\xbd\x9c\xe7\x94\xa8" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel = { "SettingsPerLevel", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UActorPaletteSettings, SettingsPerLevel), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel_MetaData), Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel_MetaData) }; // 3663705510
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList_Inner = { "RecentlyUsedList", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList_MetaData[] = {
		{ "Comment", "// List of levels that were recently open in any Actor Palette tab\n// \xe5\x88\x97\xe5\x87\xba\xe5\x85\xb3\xe5\x8d\xa1 \xe9\x82\xa3\xe4\xba\x9b \xe6\x9c\x80\xe8\xbf\x91\xe6\x89\x93\xe5\xbc\x80\xe5\x9c\xa8\xe4\xbb\xbb\xe6\x84\x8f""Actor\xe7\xbb\x98\xe6\x9d\xbf\xe7\x9a\x84Tab\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "List of levels that were recently open in any Actor Palette tab\n\xe5\x88\x97\xe5\x87\xba\xe5\x85\xb3\xe5\x8d\xa1 \xe9\x82\xa3\xe4\xba\x9b \xe6\x9c\x80\xe8\xbf\x91\xe6\x89\x93\xe5\xbc\x80\xe5\x9c\xa8\xe4\xbb\xbb\xe6\x84\x8f""Actor\xe7\xbb\x98\xe6\x9d\xbf\xe7\x9a\x84Tab" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList = { "RecentlyUsedList", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UActorPaletteSettings, RecentlyUsedList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList_MetaData), Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab_Inner = { "MostRecentLevelByTab", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab_MetaData[] = {
		{ "Comment", "// List of levels that were last open in each Actor Palette tab (indexed by tab index)\n// \xe5\x85\xb3\xe5\x8d\xa1\xe5\x88\x97\xe8\xa1\xa8 \xe9\x82\xa3\xe4\xba\x9b \xe6\x9c\x80\xe5\x90\x8e\xe6\x89\x93\xe5\xbc\x80 \xe5\x9c\xa8 Actor \xe7\xbb\x98\xe6\x9d\xbf \xe6\xa0\x87\xe7\xad\xbe\xe4\xb8\xad\xef\xbc\x88\xe7\xbc\x96\xe5\x8f\xb7\xe9\x80\x9a\xe8\xbf\x87tab\xe7\x9a\x84\xe7\xbc\x96\xe5\x8f\xb7\xef\xbc\x89\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "List of levels that were last open in each Actor Palette tab (indexed by tab index)\n\xe5\x85\xb3\xe5\x8d\xa1\xe5\x88\x97\xe8\xa1\xa8 \xe9\x82\xa3\xe4\xba\x9b \xe6\x9c\x80\xe5\x90\x8e\xe6\x89\x93\xe5\xbc\x80 \xe5\x9c\xa8 Actor \xe7\xbb\x98\xe6\x9d\xbf \xe6\xa0\x87\xe7\xad\xbe\xe4\xb8\xad\xef\xbc\x88\xe7\xbc\x96\xe5\x8f\xb7\xe9\x80\x9a\xe8\xbf\x87tab\xe7\x9a\x84\xe7\xbc\x96\xe5\x8f\xb7\xef\xbc\x89" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab = { "MostRecentLevelByTab", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UActorPaletteSettings, MostRecentLevelByTab), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab_MetaData), Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList_Inner = { "FavoritesList", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList_MetaData[] = {
		{ "Comment", "// List of levels that were marked as favorite actor palettes\n// \xe5\x85\xb3\xe5\x8d\xa1\xe6\xb3\xaa\xe9\xa3\x99 \xe8\xa2\xab\xe6\xa0\x87\xe8\xae\xb0\xe4\xb8\xba""Favorite Actor\xe7\xbb\x98\xe6\x9d\xbf\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "List of levels that were marked as favorite actor palettes\n\xe5\x85\xb3\xe5\x8d\xa1\xe6\xb3\xaa\xe9\xa3\x99 \xe8\xa2\xab\xe6\xa0\x87\xe8\xae\xb0\xe4\xb8\xba""Favorite Actor\xe7\xbb\x98\xe6\x9d\xbf" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList = { "FavoritesList", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UActorPaletteSettings, FavoritesList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList_MetaData), Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_NumRecentLevelsToKeep_MetaData[] = {
		{ "Category", "ActorPalette" },
		{ "ClampMax", "25" },
		{ "ClampMin", "0" },
		{ "Comment", "// How many recent levels will be remembered?\n// \xe5\xa4\x9a\xe5\xb0\x91\xe6\x9c\x80\xe8\xbf\x91\xe6\x89\x93\xe5\xbc\x80\xe7\x9a\x84\xe5\x85\xb3\xe5\x8d\xa1\xe5\xb0\x86\xe8\xa2\xab\xe6\x8e\xa8\xe8\x8d\x90\n" },
		{ "ModuleRelativePath", "Private/ActorPaletteSettings.h" },
		{ "ToolTip", "How many recent levels will be remembered?\n\xe5\xa4\x9a\xe5\xb0\x91\xe6\x9c\x80\xe8\xbf\x91\xe6\x89\x93\xe5\xbc\x80\xe7\x9a\x84\xe5\x85\xb3\xe5\x8d\xa1\xe5\xb0\x86\xe8\xa2\xab\xe6\x8e\xa8\xe8\x8d\x90" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_NumRecentLevelsToKeep = { "NumRecentLevelsToKeep", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UActorPaletteSettings, NumRecentLevelsToKeep), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_NumRecentLevelsToKeep_MetaData), Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_NumRecentLevelsToKeep_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UActorPaletteSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_SettingsPerLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_RecentlyUsedList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_MostRecentLevelByTab,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_FavoritesList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActorPaletteSettings_Statics::NewProp_NumRecentLevelsToKeep,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorPaletteSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActorPaletteSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UActorPaletteSettings_Statics::ClassParams = {
		&UActorPaletteSettings::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UActorPaletteSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::PropPointers),
		0,
		0x000000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UActorPaletteSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UActorPaletteSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UActorPaletteSettings()
	{
		if (!Z_Registration_Info_UClass_UActorPaletteSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActorPaletteSettings.OuterSingleton, Z_Construct_UClass_UActorPaletteSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UActorPaletteSettings.OuterSingleton;
	}
	template<> ACTORPALETTE_API UClass* StaticClass<UActorPaletteSettings>()
	{
		return UActorPaletteSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorPaletteSettings);
	UActorPaletteSettings::~UActorPaletteSettings() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics::ScriptStructInfo[] = {
		{ FActorPaletteMapEntry::StaticStruct, Z_Construct_UScriptStruct_FActorPaletteMapEntry_Statics::NewStructOps, TEXT("ActorPaletteMapEntry"), &Z_Registration_Info_UScriptStruct_ActorPaletteMapEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActorPaletteMapEntry), 3663705510U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UActorPaletteSettings, UActorPaletteSettings::StaticClass, TEXT("UActorPaletteSettings"), &Z_Registration_Info_UClass_UActorPaletteSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActorPaletteSettings), 952079654U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_2509121578(TEXT("/Script/ActorPalette"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_ActorPalette_Source_ActorPalette_Private_ActorPaletteSettings_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
