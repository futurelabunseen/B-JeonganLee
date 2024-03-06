// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HELLOUNREAL_MyGameInstance_generated_h
#error "MyGameInstance.generated.h already included, missing '#pragma once' in MyGameInstance.h"
#endif
#define HELLOUNREAL_MyGameInstance_generated_h

#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_SPARSE_DATA
#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_ACCESSORS
#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyGameInstance(); \
	friend struct Z_Construct_UClass_UMyGameInstance_Statics; \
public: \
	DECLARE_CLASS(UMyGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/HelloUnreal"), NO_API) \
	DECLARE_SERIALIZER(UMyGameInstance)


#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyGameInstance(UMyGameInstance&&); \
	NO_API UMyGameInstance(const UMyGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyGameInstance) \
	NO_API virtual ~UMyGameInstance();


#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_12_PROLOG
#define FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_SPARSE_DATA \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_ACCESSORS \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HELLOUNREAL_API UClass* StaticClass<class UMyGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HelloUnreal_Source_HelloUnreal_MyGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
