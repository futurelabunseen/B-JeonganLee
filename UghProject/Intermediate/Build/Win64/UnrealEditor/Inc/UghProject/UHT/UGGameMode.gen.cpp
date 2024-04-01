// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UghProject/UGGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UGHPROJECT_API UClass* Z_Construct_UClass_AUGGameMode();
	UGHPROJECT_API UClass* Z_Construct_UClass_AUGGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UghProject();
// End Cross Module References
	void AUGGameMode::StaticRegisterNativesAUGGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUGGameMode);
	UClass* Z_Construct_UClass_AUGGameMode_NoRegister()
	{
		return AUGGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUGGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUGGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UghProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUGGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUGGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UGGameMode.h" },
		{ "ModuleRelativePath", "UGGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUGGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUGGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUGGameMode_Statics::ClassParams = {
		&AUGGameMode::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUGGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUGGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AUGGameMode()
	{
		if (!Z_Registration_Info_UClass_AUGGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUGGameMode.OuterSingleton, Z_Construct_UClass_AUGGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUGGameMode.OuterSingleton;
	}
	template<> UGHPROJECT_API UClass* StaticClass<AUGGameMode>()
	{
		return AUGGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUGGameMode);
	AUGGameMode::~AUGGameMode() {}
	struct Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUGGameMode, AUGGameMode::StaticClass, TEXT("AUGGameMode"), &Z_Registration_Info_UClass_AUGGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUGGameMode), 3328065354U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGGameMode_h_997150549(TEXT("/Script/UghProject"),
		Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
