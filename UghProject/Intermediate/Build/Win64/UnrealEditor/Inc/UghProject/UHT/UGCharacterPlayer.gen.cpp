// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UghProject/UGCharacterPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGCharacterPlayer() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UGHPROJECT_API UClass* Z_Construct_UClass_AUGCharacterPlayer();
	UGHPROJECT_API UClass* Z_Construct_UClass_AUGCharacterPlayer_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UghProject();
// End Cross Module References
	void AUGCharacterPlayer::StaticRegisterNativesAUGCharacterPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUGCharacterPlayer);
	UClass* Z_Construct_UClass_AUGCharacterPlayer_NoRegister()
	{
		return AUGCharacterPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AUGCharacterPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUGCharacterPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UghProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUGCharacterPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUGCharacterPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "UGCharacterPlayer.h" },
		{ "ModuleRelativePath", "UGCharacterPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUGCharacterPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUGCharacterPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUGCharacterPlayer_Statics::ClassParams = {
		&AUGCharacterPlayer::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUGCharacterPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AUGCharacterPlayer_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AUGCharacterPlayer()
	{
		if (!Z_Registration_Info_UClass_AUGCharacterPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUGCharacterPlayer.OuterSingleton, Z_Construct_UClass_AUGCharacterPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUGCharacterPlayer.OuterSingleton;
	}
	template<> UGHPROJECT_API UClass* StaticClass<AUGCharacterPlayer>()
	{
		return AUGCharacterPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUGCharacterPlayer);
	AUGCharacterPlayer::~AUGCharacterPlayer() {}
	struct Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGCharacterPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGCharacterPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUGCharacterPlayer, AUGCharacterPlayer::StaticClass, TEXT("AUGCharacterPlayer"), &Z_Registration_Info_UClass_AUGCharacterPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUGCharacterPlayer), 3828846461U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGCharacterPlayer_h_3415101682(TEXT("/Script/UghProject"),
		Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGCharacterPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_UGCharacterPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
