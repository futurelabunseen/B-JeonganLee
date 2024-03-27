// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/ABHpBarWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABHpBarWidget() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_UABHpBarWidget();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABHpBarWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void UABHpBarWidget::StaticRegisterNativesUABHpBarWidget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABHpBarWidget);
	UClass* Z_Construct_UClass_UABHpBarWidget_NoRegister()
	{
		return UABHpBarWidget::StaticClass();
	}
	struct Z_Construct_UClass_UABHpBarWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HpProgressBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_HpProgressBar;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHp_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABHpBarWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABHpBarWidget_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHpBarWidget_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UI/ABHpBarWidget.h" },
		{ "ModuleRelativePath", "UI/ABHpBarWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_HpProgressBar_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa1\x9c UProgressBar\xeb\xa5\xbc \xea\xb0\x80\xeb\xa6\xac\xed\x82\xa4\xeb\x8a\x94 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0 \xeb\xb3\x80\xec\x88\x98 \xec\x84\xa0\xec\x96\xb8 (\xec\xa0\x84\xeb\xb0\xa9\xec\x84\xa0\xec\x96\xb8 \xec\x9d\x98\xec\xa1\xb4\xec\x84\xb1 x)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/ABHpBarWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa1\x9c UProgressBar\xeb\xa5\xbc \xea\xb0\x80\xeb\xa6\xac\xed\x82\xa4\xeb\x8a\x94 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0 \xeb\xb3\x80\xec\x88\x98 \xec\x84\xa0\xec\x96\xb8 (\xec\xa0\x84\xeb\xb0\xa9\xec\x84\xa0\xec\x96\xb8 \xec\x9d\x98\xec\xa1\xb4\xec\x84\xb1 x)" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_HpProgressBar = { "HpProgressBar", nullptr, (EPropertyFlags)0x0024080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABHpBarWidget, HpProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_HpProgressBar_MetaData), Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_HpProgressBar_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_MaxHp_MetaData[] = {
		{ "ModuleRelativePath", "UI/ABHpBarWidget.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_MaxHp = { "MaxHp", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABHpBarWidget, MaxHp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_MaxHp_MetaData), Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_MaxHp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABHpBarWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_HpProgressBar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABHpBarWidget_Statics::NewProp_MaxHp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABHpBarWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABHpBarWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABHpBarWidget_Statics::ClassParams = {
		&UABHpBarWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABHpBarWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABHpBarWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABHpBarWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UABHpBarWidget_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABHpBarWidget_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UABHpBarWidget()
	{
		if (!Z_Registration_Info_UClass_UABHpBarWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABHpBarWidget.OuterSingleton, Z_Construct_UClass_UABHpBarWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABHpBarWidget.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<UABHpBarWidget>()
	{
		return UABHpBarWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABHpBarWidget);
	UABHpBarWidget::~UABHpBarWidget() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABHpBarWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABHpBarWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABHpBarWidget, UABHpBarWidget::StaticClass, TEXT("UABHpBarWidget"), &Z_Registration_Info_UClass_UABHpBarWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABHpBarWidget), 3122853848U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABHpBarWidget_h_2211080161(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABHpBarWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABHpBarWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
