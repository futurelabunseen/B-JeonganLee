// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface/ABCharacterWidgetInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterWidgetInterface() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_UABCharacterWidgetInterface();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABCharacterWidgetInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void UABCharacterWidgetInterface::StaticRegisterNativesUABCharacterWidgetInterface()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABCharacterWidgetInterface);
	UClass* Z_Construct_UClass_UABCharacterWidgetInterface_NoRegister()
	{
		return UABCharacterWidgetInterface::StaticClass();
	}
	struct Z_Construct_UClass_UABCharacterWidgetInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABCharacterWidgetInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterWidgetInterface_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABCharacterWidgetInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Interface/ABCharacterWidgetInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABCharacterWidgetInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IABCharacterWidgetInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABCharacterWidgetInterface_Statics::ClassParams = {
		&UABCharacterWidgetInterface::StaticClass,
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
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABCharacterWidgetInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UABCharacterWidgetInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UABCharacterWidgetInterface()
	{
		if (!Z_Registration_Info_UClass_UABCharacterWidgetInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABCharacterWidgetInterface.OuterSingleton, Z_Construct_UClass_UABCharacterWidgetInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABCharacterWidgetInterface.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<UABCharacterWidgetInterface>()
	{
		return UABCharacterWidgetInterface::StaticClass();
	}
	UABCharacterWidgetInterface::UABCharacterWidgetInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABCharacterWidgetInterface);
	UABCharacterWidgetInterface::~UABCharacterWidgetInterface() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterWidgetInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterWidgetInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABCharacterWidgetInterface, UABCharacterWidgetInterface::StaticClass, TEXT("UABCharacterWidgetInterface"), &Z_Registration_Info_UClass_UABCharacterWidgetInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABCharacterWidgetInterface), 3978123899U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterWidgetInterface_h_3792111057(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterWidgetInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Interface_ABCharacterWidgetInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
