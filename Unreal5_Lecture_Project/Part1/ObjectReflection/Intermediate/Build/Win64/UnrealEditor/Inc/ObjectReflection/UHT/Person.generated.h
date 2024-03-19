// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Person.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OBJECTREFLECTION_Person_generated_h
#error "Person.generated.h already included, missing '#pragma once' in Person.h"
#endif
#define OBJECTREFLECTION_Person_generated_h

#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_SPARSE_DATA
#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDoLesson);


#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_ACCESSORS
#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPerson(); \
	friend struct Z_Construct_UClass_UPerson_Statics; \
public: \
	DECLARE_CLASS(UPerson, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ObjectReflection"), NO_API) \
	DECLARE_SERIALIZER(UPerson)


#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPerson(UPerson&&); \
	NO_API UPerson(const UPerson&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPerson); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPerson); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPerson) \
	NO_API virtual ~UPerson();


#define FID_ObjectReflection_Source_ObjectReflection_Person_h_12_PROLOG
#define FID_ObjectReflection_Source_ObjectReflection_Person_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_SPARSE_DATA \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_ACCESSORS \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_INCLASS_NO_PURE_DECLS \
	FID_ObjectReflection_Source_ObjectReflection_Person_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OBJECTREFLECTION_API UClass* StaticClass<class UPerson>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ObjectReflection_Source_ObjectReflection_Person_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
