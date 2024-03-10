// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Game/ABGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABGameMode() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABGameMode();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AABGameMode::StaticRegisterNativesAABGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABGameMode);
	UClass* Z_Construct_UClass_AABGameMode_NoRegister()
	{
		return AABGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AABGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Game/ABGameMode.h" },
		{ "ModuleRelativePath", "Game/ABGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABGameMode_Statics::ClassParams = {
		&AABGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AABGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AABGameMode()
	{
		if (!Z_Registration_Info_UClass_AABGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABGameMode.OuterSingleton, Z_Construct_UClass_AABGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABGameMode.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AABGameMode>()
	{
		return AABGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABGameMode);
	AABGameMode::~AABGameMode() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Game_ABGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Game_ABGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABGameMode, AABGameMode::StaticClass, TEXT("AABGameMode"), &Z_Registration_Info_UClass_AABGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABGameMode), 1694216282U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Game_ABGameMode_h_631005674(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Game_ABGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Game_ABGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
