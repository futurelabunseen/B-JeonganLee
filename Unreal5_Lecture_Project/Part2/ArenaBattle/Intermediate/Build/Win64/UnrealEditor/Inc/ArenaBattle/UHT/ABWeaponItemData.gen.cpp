// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Item/ABWeaponItemData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABWeaponItemData() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_UABItemData();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABWeaponItemData();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABWeaponItemData_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void UABWeaponItemData::StaticRegisterNativesUABWeaponItemData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UABWeaponItemData);
	UClass* Z_Construct_UClass_UABWeaponItemData_NoRegister()
	{
		return UABWeaponItemData::StaticClass();
	}
	struct Z_Construct_UClass_UABWeaponItemData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponMesh_MetaData[];
#endif
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WeaponMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABWeaponItemData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UABItemData,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABWeaponItemData_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABWeaponItemData_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/ABWeaponItemData.h" },
		{ "ModuleRelativePath", "Item/ABWeaponItemData.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABWeaponItemData_Statics::NewProp_WeaponMesh_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Item/ABWeaponItemData.h" },
	};
#endif
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UABWeaponItemData_Statics::NewProp_WeaponMesh = { "WeaponMesh", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABWeaponItemData, WeaponMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABWeaponItemData_Statics::NewProp_WeaponMesh_MetaData), Z_Construct_UClass_UABWeaponItemData_Statics::NewProp_WeaponMesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABWeaponItemData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABWeaponItemData_Statics::NewProp_WeaponMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABWeaponItemData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABWeaponItemData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UABWeaponItemData_Statics::ClassParams = {
		&UABWeaponItemData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABWeaponItemData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABWeaponItemData_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABWeaponItemData_Statics::Class_MetaDataParams), Z_Construct_UClass_UABWeaponItemData_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABWeaponItemData_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UABWeaponItemData()
	{
		if (!Z_Registration_Info_UClass_UABWeaponItemData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABWeaponItemData.OuterSingleton, Z_Construct_UClass_UABWeaponItemData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UABWeaponItemData.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<UABWeaponItemData>()
	{
		return UABWeaponItemData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABWeaponItemData);
	UABWeaponItemData::~UABWeaponItemData() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Item_ABWeaponItemData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Item_ABWeaponItemData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UABWeaponItemData, UABWeaponItemData::StaticClass, TEXT("UABWeaponItemData"), &Z_Registration_Info_UClass_UABWeaponItemData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABWeaponItemData), 291585396U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Item_ABWeaponItemData_h_3305487890(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Item_ABWeaponItemData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Item_ABWeaponItemData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
