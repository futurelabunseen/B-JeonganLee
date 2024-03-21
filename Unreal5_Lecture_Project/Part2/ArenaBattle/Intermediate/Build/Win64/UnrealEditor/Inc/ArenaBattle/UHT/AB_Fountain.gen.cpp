// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Prop/AB_Fountain.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAB_Fountain() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AAB_Fountain();
	ARENABATTLE_API UClass* Z_Construct_UClass_AAB_Fountain_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AAB_Fountain::StaticRegisterNativesAAB_Fountain()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAB_Fountain);
	UClass* Z_Construct_UClass_AAB_Fountain_NoRegister()
	{
		return AAB_Fountain::StaticClass();
	}
	struct Z_Construct_UClass_AAB_Fountain_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Body;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Water_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Water;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAB_Fountain_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAB_Fountain_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAB_Fountain_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Prop/AB_Fountain.h" },
		{ "ModuleRelativePath", "Prop/AB_Fountain.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Body_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Prop/AB_Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x00140000000a000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAB_Fountain, Body), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Body_MetaData), Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Body_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Water_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Prop/AB_Fountain.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Water = { "Water", nullptr, (EPropertyFlags)0x00140000000a000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAB_Fountain, Water), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Water_MetaData), Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Water_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAB_Fountain_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Body,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAB_Fountain_Statics::NewProp_Water,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAB_Fountain_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAB_Fountain>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAB_Fountain_Statics::ClassParams = {
		&AAB_Fountain::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAB_Fountain_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAB_Fountain_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAB_Fountain_Statics::Class_MetaDataParams), Z_Construct_UClass_AAB_Fountain_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAB_Fountain_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AAB_Fountain()
	{
		if (!Z_Registration_Info_UClass_AAB_Fountain.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAB_Fountain.OuterSingleton, Z_Construct_UClass_AAB_Fountain_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAB_Fountain.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AAB_Fountain>()
	{
		return AAB_Fountain::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAB_Fountain);
	AAB_Fountain::~AAB_Fountain() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Prop_AB_Fountain_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Prop_AB_Fountain_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAB_Fountain, AAB_Fountain::StaticClass, TEXT("AAB_Fountain"), &Z_Registration_Info_UClass_AAB_Fountain, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAB_Fountain), 1442751601U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Prop_AB_Fountain_h_2554041653(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Prop_AB_Fountain_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Prop_AB_Fountain_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
