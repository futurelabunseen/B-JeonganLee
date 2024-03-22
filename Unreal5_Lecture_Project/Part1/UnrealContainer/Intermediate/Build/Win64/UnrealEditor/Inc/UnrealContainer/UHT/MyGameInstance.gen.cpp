// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealContainer/MyGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGameInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UNREALCONTAINER_API UClass* Z_Construct_UClass_UMyGameInstance();
	UNREALCONTAINER_API UClass* Z_Construct_UClass_UMyGameInstance_NoRegister();
	UNREALCONTAINER_API UScriptStruct* Z_Construct_UScriptStruct_FStudentData();
	UPackage* Z_Construct_UPackage__Script_UnrealContainer();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_StudentData;
class UScriptStruct* FStudentData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_StudentData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_StudentData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStudentData, (UObject*)Z_Construct_UPackage__Script_UnrealContainer(), TEXT("StudentData"));
	}
	return Z_Registration_Info_UScriptStruct_StudentData.OuterSingleton;
}
template<> UNREALCONTAINER_API UScriptStruct* StaticStruct<FStudentData>()
{
	return FStudentData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FStudentData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Order_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Order;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStudentData_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9b\x90\xeb\x9e\x98\xeb\x8a\x94 \xeb\x94\xb0\xeb\xa1\x9c \xed\x97\xa4\xeb\x8d\x94 \xed\x8c\x8c\xec\x9d\xbc\xec\x9d\x84 \xeb\xa7\x8c\xeb\x93\xa4\xec\x96\xb4\xec\x84\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\x98\xec\xa7\x80\xeb\xa7\x8c, \xed\x8e\xb8\xec\x9d\x98\xec\x83\x81 \xec\x97\xac\xea\xb8\xb0\xec\x97\x90 \xec\x9e\x91\xec\x84\xb1\n" },
#endif
		{ "ModuleRelativePath", "MyGameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\x90\xeb\x9e\x98\xeb\x8a\x94 \xeb\x94\xb0\xeb\xa1\x9c \xed\x97\xa4\xeb\x8d\x94 \xed\x8c\x8c\xec\x9d\xbc\xec\x9d\x84 \xeb\xa7\x8c\xeb\x93\xa4\xec\x96\xb4\xec\x84\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\x98\xec\xa7\x80\xeb\xa7\x8c, \xed\x8e\xb8\xec\x9d\x98\xec\x83\x81 \xec\x97\xac\xea\xb8\xb0\xec\x97\x90 \xec\x9e\x91\xec\x84\xb1" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FStudentData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStudentData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Name_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY()\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4\xeb\x8a\x94 \xea\xb2\x83\xec\x9d\x80 \xeb\xa6\xac\xed\x94\x8c\xeb\xa0\x89\xec\x85\x98 \xea\xb8\xb0\xeb\x8a\xa5\xec\x9d\xb4\xeb\x82\x98\n// \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x99\x80 \xed\x98\xb8\xed\x99\x98\xed\x95\x9c\xeb\x8b\xa4\xeb\x8a\x94 \xea\xb2\x83\xec\x9c\xbc\xeb\xa1\x9c \xeb\xaa\x85\xed\x99\x95\xed\x95\x9c \xec\x82\xac\xec\x9a\xa9 \xeb\xaa\xa9\xec\xa0\x81\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\xa8\n// But \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa5\xbc \xeb\xa9\xa4\xeb\xb2\x84 \xeb\xb3\x80\xec\x88\x98\xeb\xa1\x9c \xea\xb0\x80\xec\xa7\x84\xeb\x8b\xa4\xeb\xa9\xb4 \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\xa8\n" },
#endif
		{ "ModuleRelativePath", "MyGameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY()\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4\xeb\x8a\x94 \xea\xb2\x83\xec\x9d\x80 \xeb\xa6\xac\xed\x94\x8c\xeb\xa0\x89\xec\x85\x98 \xea\xb8\xb0\xeb\x8a\xa5\xec\x9d\xb4\xeb\x82\x98\n\xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x99\x80 \xed\x98\xb8\xed\x99\x98\xed\x95\x9c\xeb\x8b\xa4\xeb\x8a\x94 \xea\xb2\x83\xec\x9c\xbc\xeb\xa1\x9c \xeb\xaa\x85\xed\x99\x95\xed\x95\x9c \xec\x82\xac\xec\x9a\xa9 \xeb\xaa\xa9\xec\xa0\x81\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\xa8\nBut \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0\xeb\xa5\xbc \xeb\xa9\xa4\xeb\xb2\x84 \xeb\xb3\x80\xec\x88\x98\xeb\xa1\x9c \xea\xb0\x80\xec\xa7\x84\xeb\x8b\xa4\xeb\xa9\xb4 \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x95\xbc \xed\x95\xa8" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStudentData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Order_MetaData[] = {
		{ "ModuleRelativePath", "MyGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Order = { "Order", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStudentData, Order), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Order_MetaData), Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Order_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStudentData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStudentData_Statics::NewProp_Order,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStudentData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealContainer,
		nullptr,
		&NewStructOps,
		"StudentData",
		Z_Construct_UScriptStruct_FStudentData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStudentData_Statics::PropPointers),
		sizeof(FStudentData),
		alignof(FStudentData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStudentData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStudentData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStudentData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FStudentData()
	{
		if (!Z_Registration_Info_UScriptStruct_StudentData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_StudentData.InnerSingleton, Z_Construct_UScriptStruct_FStudentData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_StudentData.InnerSingleton;
	}
	void UMyGameInstance::StaticRegisterNativesUMyGameInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyGameInstance);
	UClass* Z_Construct_UClass_UMyGameInstance_NoRegister()
	{
		return UMyGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMyGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealContainer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyGameInstance.h" },
		{ "ModuleRelativePath", "MyGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyGameInstance_Statics::ClassParams = {
		&UMyGameInstance::StaticClass,
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
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMyGameInstance()
	{
		if (!Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton, Z_Construct_UClass_UMyGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton;
	}
	template<> UNREALCONTAINER_API UClass* StaticClass<UMyGameInstance>()
	{
		return UMyGameInstance::StaticClass();
	}
	UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyGameInstance);
	UMyGameInstance::~UMyGameInstance() {}
	struct Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics::ScriptStructInfo[] = {
		{ FStudentData::StaticStruct, Z_Construct_UScriptStruct_FStudentData_Statics::NewStructOps, TEXT("StudentData"), &Z_Registration_Info_UScriptStruct_StudentData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStudentData), 3513422564U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyGameInstance, UMyGameInstance::StaticClass, TEXT("UMyGameInstance"), &Z_Registration_Info_UClass_UMyGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyGameInstance), 2975481133U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_1753679884(TEXT("/Script/UnrealContainer"),
		Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealContainer_Source_UnrealContainer_MyGameInstance_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
