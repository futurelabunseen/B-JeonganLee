// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealDelegate/CourseInfo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCourseInfo() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALDELEGATE_API UClass* Z_Construct_UClass_UCourseInfo();
	UNREALDELEGATE_API UClass* Z_Construct_UClass_UCourseInfo_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealDelegate();
// End Cross Module References
	void UCourseInfo::StaticRegisterNativesUCourseInfo()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCourseInfo);
	UClass* Z_Construct_UClass_UCourseInfo_NoRegister()
	{
		return UCourseInfo::StaticClass();
	}
	struct Z_Construct_UClass_UCourseInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCourseInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealDelegate,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCourseInfo_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCourseInfo_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "CourseInfo.h" },
		{ "ModuleRelativePath", "CourseInfo.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCourseInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCourseInfo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCourseInfo_Statics::ClassParams = {
		&UCourseInfo::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCourseInfo_Statics::Class_MetaDataParams), Z_Construct_UClass_UCourseInfo_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UCourseInfo()
	{
		if (!Z_Registration_Info_UClass_UCourseInfo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCourseInfo.OuterSingleton, Z_Construct_UClass_UCourseInfo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCourseInfo.OuterSingleton;
	}
	template<> UNREALDELEGATE_API UClass* StaticClass<UCourseInfo>()
	{
		return UCourseInfo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCourseInfo);
	UCourseInfo::~UCourseInfo() {}
	struct Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_CourseInfo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_CourseInfo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCourseInfo, UCourseInfo::StaticClass, TEXT("UCourseInfo"), &Z_Registration_Info_UClass_UCourseInfo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCourseInfo), 1657215195U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_CourseInfo_h_3618745072(TEXT("/Script/UnrealDelegate"),
		Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_CourseInfo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealDelegate_Source_UnrealDelegate_CourseInfo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
