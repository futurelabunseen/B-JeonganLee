// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealContainer/Student.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStudent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALCONTAINER_API UClass* Z_Construct_UClass_UStudent();
	UNREALCONTAINER_API UClass* Z_Construct_UClass_UStudent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealContainer();
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
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Students_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Students_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Students;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStudent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealContainer,
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
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UStudent_Statics::NewProp_Students_Inner = { "Students", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStudent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStudent_Statics::NewProp_Students_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x97\xa4\xeb\x8d\x94\xec\x97\x90\xec\x84\x9c \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa5\xbc \xec\x84\xa0\xec\x96\xb8\xed\x95\xa0 \xeb\x95\x8c\xeb\x8a\x94 \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c TObjectPtr\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4.\n// \xec\xa0\x84\xeb\xb0\xa9\xec\x84\xa0\xec\x96\xb8\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xec\x97\xac UStudent \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\xa5\xbc \xea\xb0\x80\xeb\xb3\x80 \xeb\xb0\xb0\xec\x97\xb4\xeb\xa1\x9c \xea\xb0\x80\xec\xa7\x84\xeb\x8b\xa4.\n// \xec\x9d\xb4\xeb\xa0\x87\xea\xb2\x8c TArray\xec\x97\x90\xec\x84\x9c \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa5\xbc \xea\xb4\x80\xeb\xa6\xac\xed\x95\x98\xea\xb2\x8c \xeb\x90\x9c\xeb\x8b\xa4\xeb\xa9\xb4 \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc\xec\x97\x90\xec\x84\x9c \xec\x9e\x90\xeb\x8f\x99\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa9\x94\xeb\xaa\xa8\xeb\xa6\xac\xeb\xa5\xbc \xea\xb4\x80\xeb\xa6\xac\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d\n// UPROPERTY()\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4. (\xed\x95\x84\xec\x88\x98\xec\xa0\x81\xec\x9d\xb8)\n" },
#endif
		{ "ModuleRelativePath", "Student.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x97\xa4\xeb\x8d\x94\xec\x97\x90\xec\x84\x9c \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa5\xbc \xec\x84\xa0\xec\x96\xb8\xed\x95\xa0 \xeb\x95\x8c\xeb\x8a\x94 \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c TObjectPtr\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4.\n\xec\xa0\x84\xeb\xb0\xa9\xec\x84\xa0\xec\x96\xb8\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xec\x97\xac UStudent \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\xa5\xbc \xea\xb0\x80\xeb\xb3\x80 \xeb\xb0\xb0\xec\x97\xb4\xeb\xa1\x9c \xea\xb0\x80\xec\xa7\x84\xeb\x8b\xa4.\n\xec\x9d\xb4\xeb\xa0\x87\xea\xb2\x8c TArray\xec\x97\x90\xec\x84\x9c \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa5\xbc \xea\xb4\x80\xeb\xa6\xac\xed\x95\x98\xea\xb2\x8c \xeb\x90\x9c\xeb\x8b\xa4\xeb\xa9\xb4 \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc\xec\x97\x90\xec\x84\x9c \xec\x9e\x90\xeb\x8f\x99\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa9\x94\xeb\xaa\xa8\xeb\xa6\xac\xeb\xa5\xbc \xea\xb4\x80\xeb\xa6\xac\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d\nUPROPERTY()\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4. (\xed\x95\x84\xec\x88\x98\xec\xa0\x81\xec\x9d\xb8)" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UStudent_Statics::NewProp_Students = { "Students", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStudent, Students), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStudent_Statics::NewProp_Students_MetaData), Z_Construct_UClass_UStudent_Statics::NewProp_Students_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStudent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStudent_Statics::NewProp_Students_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStudent_Statics::NewProp_Students,
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
	template<> UNREALCONTAINER_API UClass* StaticClass<UStudent>()
	{
		return UStudent::StaticClass();
	}
	UStudent::UStudent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStudent);
	UStudent::~UStudent() {}
	struct Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_Student_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_Student_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStudent, UStudent::StaticClass, TEXT("UStudent"), &Z_Registration_Info_UClass_UStudent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStudent), 1351410709U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_Student_h_1503698010(TEXT("/Script/UnrealContainer"),
		Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_Student_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_Student_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
