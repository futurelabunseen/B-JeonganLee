// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealContainer_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealContainer;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealContainer()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealContainer.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UnrealContainer",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xBF94297B,
				0x18CEF22E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealContainer.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UnrealContainer.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealContainer(Z_Construct_UPackage__Script_UnrealContainer, TEXT("/Script/UnrealContainer"), Z_Registration_Info_UPackage__Script_UnrealContainer, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBF94297B, 0x18CEF22E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
