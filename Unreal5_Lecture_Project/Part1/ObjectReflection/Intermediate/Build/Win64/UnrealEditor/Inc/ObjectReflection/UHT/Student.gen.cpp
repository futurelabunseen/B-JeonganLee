// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ObjectReflection/Student.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStudent() {}
// Cross Module References
	OBJECTREFLECTION_API UClass* Z_Construct_UClass_UPerson();
	OBJECTREFLECTION_API UClass* Z_Construct_UClass_UStudent();
	OBJECTREFLECTION_API UClass* Z_Construct_UClass_UStudent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ObjectReflection();
// End Cross Module References
	void UStudent::StaticRegisterNativesUStudent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStudent);
	UClass* Z_Construct_UClass_UStudent_NoRegister()
	{
		return UStudent::StaticClass();
	}
	struct Z_Construct_UClass_UStudent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStudent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPerson,
		(UObject* (*)())Z_Construct_UPackage__Script_ObjectReflection,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStudent_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Student.h" },
		{ "ModuleRelativePath", "Student.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStudent_Statics::NewProp_Id_MetaData[] = {
		{ "ModuleRelativePath", "Student.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UStudent_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStudent, Id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::NewProp_Id_MetaData), Z_Construct_UClass_UStudent_Statics::NewProp_Id_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStudent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStudent_Statics::NewProp_Id,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStudent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStudent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStudent_Statics::ClassParams = {
		&UStudent::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UStudent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::Class_MetaDataParams), Z_Construct_UClass_UStudent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UStudent()
	{
		if (!Z_Registration_Info_UClass_UStudent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStudent.OuterSingleton, Z_Construct_UClass_UStudent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStudent.OuterSingleton;
	}
	template<> OBJECTREFLECTION_API UClass* StaticClass<UStudent>()
	{
		return UStudent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStudent);
	UStudent::~UStudent() {}
	struct Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Student_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Student_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStudent, UStudent::StaticClass, TEXT("UStudent"), &Z_Registration_Info_UClass_UStudent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStudent), 3536157732U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Student_h_3909868712(TEXT("/Script/ObjectReflection"),
		Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Student_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ObjectReflection_Source_ObjectReflection_Student_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
