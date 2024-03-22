// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealMemory/Student.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStudent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALMEMORY_API UClass* Z_Construct_UClass_UStudent();
	UNREALMEMORY_API UClass* Z_Construct_UClass_UStudent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealMemory();
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStudent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealMemory,
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
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStudent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStudent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStudent_Statics::ClassParams = {
		&UStudent::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::Class_MetaDataParams), Z_Construct_UClass_UStudent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UStudent()
	{
		if (!Z_Registration_Info_UClass_UStudent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStudent.OuterSingleton, Z_Construct_UClass_UStudent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStudent.OuterSingleton;
	}
	template<> UNREALMEMORY_API UClass* StaticClass<UStudent>()
	{
		return UStudent::StaticClass();
	}
	UStudent::UStudent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStudent);
	UStudent::~UStudent() {}
	struct Z_CompiledInDeferFile_FID_UnrealMemory_Source_UnrealMemory_Student_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealMemory_Source_UnrealMemory_Student_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStudent, UStudent::StaticClass, TEXT("UStudent"), &Z_Registration_Info_UClass_UStudent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStudent), 1507358112U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealMemory_Source_UnrealMemory_Student_h_1727412405(TEXT("/Script/UnrealMemory"),
		Z_CompiledInDeferFile_FID_UnrealMemory_Source_UnrealMemory_Student_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealMemory_Source_UnrealMemory_Student_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
