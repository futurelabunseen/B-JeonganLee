// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealObject/MyObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyObject() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UNREALOBJECT_API UClass* Z_Construct_UClass_UMyObject();
	UNREALOBJECT_API UClass* Z_Construct_UClass_UMyObject_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealObject();
// End Cross Module References
	void UMyObject::StaticRegisterNativesUMyObject()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyObject);
	UClass* Z_Construct_UClass_UMyObject_NoRegister()
	{
		return UMyObject::StaticClass();
	}
	struct Z_Construct_UClass_UMyObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealObject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyObject_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyObject_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyObject.h" },
		{ "ModuleRelativePath", "MyObject.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyObject_Statics::ClassParams = {
		&UMyObject::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyObject_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMyObject()
	{
		if (!Z_Registration_Info_UClass_UMyObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyObject.OuterSingleton, Z_Construct_UClass_UMyObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyObject.OuterSingleton;
	}
	template<> UNREALOBJECT_API UClass* StaticClass<UMyObject>()
	{
		return UMyObject::StaticClass();
	}
	UMyObject::UMyObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyObject);
	UMyObject::~UMyObject() {}
	struct Z_CompiledInDeferFile_FID_UnrealObject_Source_UnrealObject_MyObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealObject_Source_UnrealObject_MyObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyObject, UMyObject::StaticClass, TEXT("UMyObject"), &Z_Registration_Info_UClass_UMyObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyObject), 4174185575U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealObject_Source_UnrealObject_MyObject_h_3025323459(TEXT("/Script/UnrealObject"),
		Z_CompiledInDeferFile_FID_UnrealObject_Source_UnrealObject_MyObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealObject_Source_UnrealObject_MyObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
