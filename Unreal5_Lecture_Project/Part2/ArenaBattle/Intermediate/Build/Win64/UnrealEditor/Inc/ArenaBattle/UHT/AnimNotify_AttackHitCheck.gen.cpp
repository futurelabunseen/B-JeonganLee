// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Animation/AnimNotify_AttackHitCheck.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNotify_AttackHitCheck() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_UAnimNotify_AttackHitCheck();
	ARENABATTLE_API UClass* Z_Construct_UClass_UAnimNotify_AttackHitCheck_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void UAnimNotify_AttackHitCheck::StaticRegisterNativesUAnimNotify_AttackHitCheck()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimNotify_AttackHitCheck);
	UClass* Z_Construct_UClass_UAnimNotify_AttackHitCheck_NoRegister()
	{
		return UAnimNotify_AttackHitCheck::StaticClass();
	}
	struct Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "Animation/AnimNotify_AttackHitCheck.h" },
		{ "ModuleRelativePath", "Animation/AnimNotify_AttackHitCheck.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimNotify_AttackHitCheck>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::ClassParams = {
		&UAnimNotify_AttackHitCheck::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UAnimNotify_AttackHitCheck()
	{
		if (!Z_Registration_Info_UClass_UAnimNotify_AttackHitCheck.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimNotify_AttackHitCheck.OuterSingleton, Z_Construct_UClass_UAnimNotify_AttackHitCheck_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimNotify_AttackHitCheck.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<UAnimNotify_AttackHitCheck>()
	{
		return UAnimNotify_AttackHitCheck::StaticClass();
	}
	UAnimNotify_AttackHitCheck::UAnimNotify_AttackHitCheck(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimNotify_AttackHitCheck);
	UAnimNotify_AttackHitCheck::~UAnimNotify_AttackHitCheck() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Animation_AnimNotify_AttackHitCheck_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Animation_AnimNotify_AttackHitCheck_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimNotify_AttackHitCheck, UAnimNotify_AttackHitCheck::StaticClass, TEXT("UAnimNotify_AttackHitCheck"), &Z_Registration_Info_UClass_UAnimNotify_AttackHitCheck, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimNotify_AttackHitCheck), 287161434U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Animation_AnimNotify_AttackHitCheck_h_709562033(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Animation_AnimNotify_AttackHitCheck_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Animation_AnimNotify_AttackHitCheck_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
