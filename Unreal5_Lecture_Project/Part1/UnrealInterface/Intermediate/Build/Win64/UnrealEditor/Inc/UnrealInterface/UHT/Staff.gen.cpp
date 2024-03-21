// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealInterface/Staff.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStaff() {}
// Cross Module References
	UNREALINTERFACE_API UClass* Z_Construct_UClass_Uperson();
	UNREALINTERFACE_API UClass* Z_Construct_UClass_UStaff();
	UNREALINTERFACE_API UClass* Z_Construct_UClass_UStaff_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealInterface();
// End Cross Module References
	void UStaff::StaticRegisterNativesUStaff()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStaff);
	UClass* Z_Construct_UClass_UStaff_NoRegister()
	{
		return UStaff::StaticClass();
	}
	struct Z_Construct_UClass_UStaff_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStaff_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_Uperson,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealInterface,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStaff_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStaff_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Staff.h" },
		{ "ModuleRelativePath", "Staff.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStaff_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStaff>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStaff_Statics::ClassParams = {
		&UStaff::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStaff_Statics::Class_MetaDataParams), Z_Construct_UClass_UStaff_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UStaff()
	{
		if (!Z_Registration_Info_UClass_UStaff.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStaff.OuterSingleton, Z_Construct_UClass_UStaff_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStaff.OuterSingleton;
	}
	template<> UNREALINTERFACE_API UClass* StaticClass<UStaff>()
	{
		return UStaff::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStaff);
	UStaff::~UStaff() {}
	struct Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_Staff_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_Staff_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStaff, UStaff::StaticClass, TEXT("UStaff"), &Z_Registration_Info_UClass_UStaff, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStaff), 3956652947U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_Staff_h_1543250057(TEXT("/Script/UnrealInterface"),
		Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_Staff_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_Staff_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
