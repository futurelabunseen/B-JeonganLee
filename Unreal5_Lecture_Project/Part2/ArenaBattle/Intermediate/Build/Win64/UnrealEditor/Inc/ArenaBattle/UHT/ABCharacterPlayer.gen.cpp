// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/ABCharacterPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterPlayer() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterBase();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterPlayer();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterPlayer_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AABCharacterPlayer::StaticRegisterNativesAABCharacterPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABCharacterPlayer);
	UClass* Z_Construct_UClass_AABCharacterPlayer_NoRegister()
	{
		return AABCharacterPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AABCharacterPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABCharacterPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AABCharacterBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/ABCharacterPlayer.h" },
		{ "ModuleRelativePath", "Character/ABCharacterPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABCharacterPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABCharacterPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABCharacterPlayer_Statics::ClassParams = {
		&AABCharacterPlayer::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AABCharacterPlayer_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AABCharacterPlayer()
	{
		if (!Z_Registration_Info_UClass_AABCharacterPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABCharacterPlayer.OuterSingleton, Z_Construct_UClass_AABCharacterPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABCharacterPlayer.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AABCharacterPlayer>()
	{
		return AABCharacterPlayer::StaticClass();
	}
	AABCharacterPlayer::AABCharacterPlayer() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABCharacterPlayer);
	AABCharacterPlayer::~AABCharacterPlayer() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABCharacterPlayer, AABCharacterPlayer::StaticClass, TEXT("AABCharacterPlayer"), &Z_Registration_Info_UClass_AABCharacterPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABCharacterPlayer), 922035951U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_3589163000(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
