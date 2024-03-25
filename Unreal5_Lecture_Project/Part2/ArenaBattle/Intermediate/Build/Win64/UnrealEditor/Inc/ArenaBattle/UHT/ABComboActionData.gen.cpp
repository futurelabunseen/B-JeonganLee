// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/ABComboActionData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABComboActionData() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_UABComboActionData();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABComboActionData_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void UABComboActionData::StaticRegisterNativesUABComboActionData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABComboActionData);
	UClass* Z_Construct_UClass_UABComboActionData_NoRegister()
	{
		return UABComboActionData::StaticClass();
	}
	struct Z_Construct_UClass_UABComboActionData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MontageSectionNamePrefix_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_MontageSectionNamePrefix;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxComboCount_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_MaxComboCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrameRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrameRate;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_EffectiveFrameCount_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectiveFrameCount_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_EffectiveFrameCount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABComboActionData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABComboActionData_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Character/ABComboActionData.h" },
		{ "ModuleRelativePath", "Character/ABComboActionData.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABComboActionData_Statics::NewProp_MontageSectionNamePrefix_MetaData[] = {
		{ "Category", "Name" },
		{ "ModuleRelativePath", "Character/ABComboActionData.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UABComboActionData_Statics::NewProp_MontageSectionNamePrefix = { "MontageSectionNamePrefix", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABComboActionData, MontageSectionNamePrefix), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::NewProp_MontageSectionNamePrefix_MetaData), Z_Construct_UClass_UABComboActionData_Statics::NewProp_MontageSectionNamePrefix_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABComboActionData_Statics::NewProp_MaxComboCount_MetaData[] = {
		{ "Category", "Name" },
		{ "ModuleRelativePath", "Character/ABComboActionData.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABComboActionData_Statics::NewProp_MaxComboCount = { "MaxComboCount", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABComboActionData, MaxComboCount), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::NewProp_MaxComboCount_MetaData), Z_Construct_UClass_UABComboActionData_Statics::NewProp_MaxComboCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABComboActionData_Statics::NewProp_FrameRate_MetaData[] = {
		{ "Category", "Name" },
		{ "ModuleRelativePath", "Character/ABComboActionData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UABComboActionData_Statics::NewProp_FrameRate = { "FrameRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABComboActionData, FrameRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::NewProp_FrameRate_MetaData), Z_Construct_UClass_UABComboActionData_Statics::NewProp_FrameRate_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount_Inner = { "EffectiveFrameCount", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount_MetaData[] = {
		{ "Category", "ComboData" },
		{ "ModuleRelativePath", "Character/ABComboActionData.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount = { "EffectiveFrameCount", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABComboActionData, EffectiveFrameCount), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount_MetaData), Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABComboActionData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABComboActionData_Statics::NewProp_MontageSectionNamePrefix,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABComboActionData_Statics::NewProp_MaxComboCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABComboActionData_Statics::NewProp_FrameRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABComboActionData_Statics::NewProp_EffectiveFrameCount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABComboActionData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABComboActionData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABComboActionData_Statics::ClassParams = {
		&UABComboActionData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABComboActionData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::Class_MetaDataParams), Z_Construct_UClass_UABComboActionData_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABComboActionData_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UABComboActionData()
	{
		if (!Z_Registration_Info_UClass_UABComboActionData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABComboActionData.OuterSingleton, Z_Construct_UClass_UABComboActionData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABComboActionData.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<UABComboActionData>()
	{
		return UABComboActionData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABComboActionData);
	UABComboActionData::~UABComboActionData() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABComboActionData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABComboActionData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABComboActionData, UABComboActionData::StaticClass, TEXT("UABComboActionData"), &Z_Registration_Info_UClass_UABComboActionData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABComboActionData), 518415565U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABComboActionData_h_1353122828(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABComboActionData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABComboActionData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
