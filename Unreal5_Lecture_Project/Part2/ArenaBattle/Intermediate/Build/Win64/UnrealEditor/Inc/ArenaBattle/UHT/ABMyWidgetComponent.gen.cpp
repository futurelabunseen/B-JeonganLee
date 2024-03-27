// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/ABMyWidgetComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABMyWidgetComponent() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_UABMyWidgetComponent();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABMyWidgetComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void UABMyWidgetComponent::StaticRegisterNativesUABMyWidgetComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABMyWidgetComponent);
	UClass* Z_Construct_UClass_UABMyWidgetComponent_NoRegister()
	{
		return UABMyWidgetComponent::StaticClass();
	}
	struct Z_Construct_UClass_UABMyWidgetComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABMyWidgetComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWidgetComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABMyWidgetComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABMyWidgetComponent_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object Activation Components|Activation Sockets Base Lighting LOD Mesh Mobility Trigger" },
		{ "IncludePath", "UI/ABMyWidgetComponent.h" },
		{ "ModuleRelativePath", "UI/ABMyWidgetComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABMyWidgetComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABMyWidgetComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABMyWidgetComponent_Statics::ClassParams = {
		&UABMyWidgetComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B010A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABMyWidgetComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UABMyWidgetComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UABMyWidgetComponent()
	{
		if (!Z_Registration_Info_UClass_UABMyWidgetComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABMyWidgetComponent.OuterSingleton, Z_Construct_UClass_UABMyWidgetComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABMyWidgetComponent.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<UABMyWidgetComponent>()
	{
		return UABMyWidgetComponent::StaticClass();
	}
	UABMyWidgetComponent::UABMyWidgetComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABMyWidgetComponent);
	UABMyWidgetComponent::~UABMyWidgetComponent() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABMyWidgetComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABMyWidgetComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABMyWidgetComponent, UABMyWidgetComponent::StaticClass, TEXT("UABMyWidgetComponent"), &Z_Registration_Info_UClass_UABMyWidgetComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABMyWidgetComponent), 4084638219U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABMyWidgetComponent_h_1743714639(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABMyWidgetComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_UI_ABMyWidgetComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
