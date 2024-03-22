// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealComposition_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealComposition;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealComposition()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealComposition.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UnrealComposition",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0513E199,
				0xA44B596E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealComposition.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UnrealComposition.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealComposition(Z_Construct_UPackage__Script_UnrealComposition, TEXT("/Script/UnrealComposition"), Z_Registration_Info_UPackage__Script_UnrealComposition, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0513E199, 0xA44B596E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
