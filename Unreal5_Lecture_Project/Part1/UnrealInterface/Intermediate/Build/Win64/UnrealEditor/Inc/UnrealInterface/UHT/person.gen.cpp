// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealInterface/person.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeperson() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALINTERFACE_API UClass* Z_Construct_UClass_Uperson();
	UNREALINTERFACE_API UClass* Z_Construct_UClass_Uperson_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealInterface();
// End Cross Module References
	void Uperson::StaticRegisterNativesUperson()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(Uperson);
	UClass* Z_Construct_UClass_Uperson_NoRegister()
	{
		return Uperson::StaticClass();
	}
	struct Z_Construct_UClass_Uperson_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Uperson_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealInterface,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Uperson_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Uperson_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "person.h" },
		{ "ModuleRelativePath", "person.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Uperson_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "person.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_Uperson_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Uperson, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Uperson_Statics::NewProp_Name_MetaData), Z_Construct_UClass_Uperson_Statics::NewProp_Name_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_Uperson_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Uperson_Statics::NewProp_Name,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_Uperson_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Uperson>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_Uperson_Statics::ClassParams = {
		&Uperson::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_Uperson_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_Uperson_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Uperson_Statics::Class_MetaDataParams), Z_Construct_UClass_Uperson_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Uperson_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_Uperson()
	{
		if (!Z_Registration_Info_UClass_Uperson.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Uperson.OuterSingleton, Z_Construct_UClass_Uperson_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_Uperson.OuterSingleton;
	}
	template<> UNREALINTERFACE_API UClass* StaticClass<Uperson>()
	{
		return Uperson::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(Uperson);
	Uperson::~Uperson() {}
	struct Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_person_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_person_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_Uperson, Uperson::StaticClass, TEXT("Uperson"), &Z_Registration_Info_UClass_Uperson, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Uperson), 2033156988U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_person_h_807905650(TEXT("/Script/UnrealInterface"),
		Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_person_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealInterface_Source_UnrealInterface_person_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
