// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/ABCharacterNonPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterNonPlayer() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterBase();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterNonPlayer();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterNonPlayer_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AABCharacterNonPlayer::StaticRegisterNativesAABCharacterNonPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABCharacterNonPlayer);
	UClass* Z_Construct_UClass_AABCharacterNonPlayer_NoRegister()
	{
		return AABCharacterNonPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AABCharacterNonPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABCharacterNonPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AABCharacterBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterNonPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterNonPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/ABCharacterNonPlayer.h" },
		{ "ModuleRelativePath", "Character/ABCharacterNonPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABCharacterNonPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABCharacterNonPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABCharacterNonPlayer_Statics::ClassParams = {
		&AABCharacterNonPlayer::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterNonPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AABCharacterNonPlayer_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AABCharacterNonPlayer()
	{
		if (!Z_Registration_Info_UClass_AABCharacterNonPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABCharacterNonPlayer.OuterSingleton, Z_Construct_UClass_AABCharacterNonPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABCharacterNonPlayer.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AABCharacterNonPlayer>()
	{
		return AABCharacterNonPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABCharacterNonPlayer);
	AABCharacterNonPlayer::~AABCharacterNonPlayer() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterNonPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterNonPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABCharacterNonPlayer, AABCharacterNonPlayer::StaticClass, TEXT("AABCharacterNonPlayer"), &Z_Registration_Info_UClass_AABCharacterNonPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABCharacterNonPlayer), 36547777U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterNonPlayer_h_3441660743(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterNonPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterNonPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
