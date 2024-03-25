// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealSerialization_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealSerialization;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealSerialization()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealSerialization.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UnrealSerialization",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xDBD6F204,
				0x0BD7FCE1,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealSerialization.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UnrealSerialization.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealSerialization(Z_Construct_UPackage__Script_UnrealSerialization, TEXT("/Script/UnrealSerialization"), Z_Registration_Info_UPackage__Script_UnrealSerialization, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xDBD6F204, 0x0BD7FCE1));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
