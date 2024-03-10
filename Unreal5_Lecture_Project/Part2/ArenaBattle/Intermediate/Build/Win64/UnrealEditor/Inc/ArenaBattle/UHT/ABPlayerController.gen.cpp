// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Player/ABPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABPlayerController() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABPlayerController();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABPlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AABPlayerController::StaticRegisterNativesAABPlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABPlayerController);
	UClass* Z_Construct_UClass_AABPlayerController_NoRegister()
	{
		return AABPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AABPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABPlayerController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Player/ABPlayerController.h" },
		{ "ModuleRelativePath", "Player/ABPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABPlayerController_Statics::ClassParams = {
		&AABPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AABPlayerController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AABPlayerController()
	{
		if (!Z_Registration_Info_UClass_AABPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABPlayerController.OuterSingleton, Z_Construct_UClass_AABPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABPlayerController.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AABPlayerController>()
	{
		return AABPlayerController::StaticClass();
	}
	AABPlayerController::AABPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABPlayerController);
	AABPlayerController::~AABPlayerController() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Player_ABPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Player_ABPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABPlayerController, AABPlayerController::StaticClass, TEXT("AABPlayerController"), &Z_Registration_Info_UClass_AABPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABPlayerController), 820151059U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Player_ABPlayerController_h_3696703060(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Player_ABPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Player_ABPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
