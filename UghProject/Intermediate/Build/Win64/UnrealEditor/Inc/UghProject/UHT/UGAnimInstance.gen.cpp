// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UghProject/Animation/UGAnimInstance.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUGAnimInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UGHPROJECT_API UClass* Z_Construct_UClass_UUGAnimInstance();
	UGHPROJECT_API UClass* Z_Construct_UClass_UUGAnimInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UghProject();
// End Cross Module References
	void UUGAnimInstance::StaticRegisterNativesUUGAnimInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUGAnimInstance);
	UClass* Z_Construct_UClass_UUGAnimInstance_NoRegister()
	{
		return UUGAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UUGAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUGAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_UghProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGAnimInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUGAnimInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Animation/UGAnimInstance.h" },
		{ "ModuleRelativePath", "Animation/UGAnimInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUGAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGAnimInstance_Statics::ClassParams = {
		&UUGAnimInstance::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGAnimInstance_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UUGAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UUGAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGAnimInstance.OuterSingleton, Z_Construct_UClass_UUGAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUGAnimInstance.OuterSingleton;
	}
	template<> UGHPROJECT_API UClass* StaticClass<UUGAnimInstance>()
	{
		return UUGAnimInstance::StaticClass();
	}
	UUGAnimInstance::UUGAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUGAnimInstance);
	UUGAnimInstance::~UUGAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_Animation_UGAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_Animation_UGAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUGAnimInstance, UUGAnimInstance::StaticClass, TEXT("UUGAnimInstance"), &Z_Registration_Info_UClass_UUGAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGAnimInstance), 2532365941U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_Animation_UGAnimInstance_h_2303344696(TEXT("/Script/UghProject"),
		Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_Animation_UGAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UghProject_Source_UghProject_Animation_UGAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
