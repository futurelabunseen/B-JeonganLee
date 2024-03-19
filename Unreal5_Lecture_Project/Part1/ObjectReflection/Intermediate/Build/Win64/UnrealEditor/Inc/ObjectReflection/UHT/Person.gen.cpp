// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ObjectReflection/Person.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePerson() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	OBJECTREFLECTION_API UClass* Z_Construct_UClass_UPerson();
	OBJECTREFLECTION_API UClass* Z_Construct_UClass_UPerson_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ObjectReflection();
// End Cross Module References
	DEFINE_FUNCTION(UPerson::execDoLesson)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DoLesson();
		P_NATIVE_END;
	}
	void UPerson::StaticRegisterNativesUPerson()
	{
		UClass* Class = UPerson::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DoLesson", &UPerson::execDoLesson },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPerson_DoLesson_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPerson_DoLesson_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Person.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPerson_DoLesson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPerson, nullptr, "DoLesson", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPerson_DoLesson_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPerson_DoLesson_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPerson_DoLesson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPerson_DoLesson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPerson);
	UClass* Z_Construct_UClass_UPerson_NoRegister()
	{
		return UPerson::StaticClass();
	}
	struct Z_Construct_UClass_UPerson_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Year_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Year;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPerson_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ObjectReflection,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPerson_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPerson_DoLesson, "DoLesson" }, // 1672420239
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPerson_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Person.h" },
		{ "ModuleRelativePath", "Person.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPerson_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Person.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPerson_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPerson, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::NewProp_Name_MetaData), Z_Construct_UClass_UPerson_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPerson_Statics::NewProp_Year_MetaData[] = {
		{ "ModuleRelativePath", "Person.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPerson_Statics::NewProp_Year = { "Year", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPerson, Year), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::NewProp_Year_MetaData), Z_Construct_UClass_UPerson_Statics::NewProp_Year_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPerson_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPerson_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPerson_Statics::NewProp_Year,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPerson_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPerson>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPerson_Statics::ClassParams = {
		&UPerson::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPerson_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::Class_MetaDataParams), Z_Construct_UClass_UPerson_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPerson_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPerson()
	{
		if (!Z_Registration_Info_UClass_UPerson.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPerson.OuterSingleton, Z_Construct_UClass_UPerson_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPerson.OuterSingleton;
	}
	template<> OBJECTREFLECTION_API UClass* StaticClass<UPerson>()
	{
		return UPerson::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPerson);
	UPerson::~UPerson() {}
	struct Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Person_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Person_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPerson, UPerson::StaticClass, TEXT("UPerson"), &Z_Registration_Info_UClass_UPerson, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPerson), 1112902084U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Person_h_2038562921(TEXT("/Script/ObjectReflection"),
		Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Person_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Person_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
