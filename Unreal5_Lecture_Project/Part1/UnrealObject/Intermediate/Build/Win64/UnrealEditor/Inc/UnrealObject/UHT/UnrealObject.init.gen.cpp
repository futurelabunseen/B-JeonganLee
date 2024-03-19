// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealObject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealObject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealObject()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealObject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UnrealObject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x1A06F77C,
				0xDFE3737B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealObject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UnrealObject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealObject(Z_Construct_UPackage__Script_UnrealObject, TEXT("/Script/UnrealObject"), Z_Registration_Info_UPackage__Script_UnrealObject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1A06F77C, 0xDFE3737B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
