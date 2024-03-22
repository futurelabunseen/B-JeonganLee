// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealMemory_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealMemory;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealMemory()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealMemory.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UnrealMemory",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x4E598CA0,
				0xE6EE7D66,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealMemory.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UnrealMemory.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealMemory(Z_Construct_UPackage__Script_UnrealMemory, TEXT("/Script/UnrealMemory"), Z_Registration_Info_UPackage__Script_UnrealMemory, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4E598CA0, 0xE6EE7D66));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
