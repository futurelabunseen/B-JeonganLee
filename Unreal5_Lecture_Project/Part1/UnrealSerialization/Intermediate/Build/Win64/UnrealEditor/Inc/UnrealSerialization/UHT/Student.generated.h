// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Student.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALSERIALIZATION_Student_generated_h
#error "Student.generated.h already included, missing '#pragma once' in Student.h"
#endif
#define UNREALSERIALIZATION_Student_generated_h

#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_SPARSE_DATA
#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_ACCESSORS
#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UStudent, NO_API)


#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUStudent(); \
	friend struct Z_Construct_UClass_UStudent_Statics; \
public: \
	DECLARE_CLASS(UStudent, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealSerialization"), NO_API) \
	DECLARE_SERIALIZER(UStudent) \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_ARCHIVESERIALIZER


#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UStudent(UStudent&&); \
	NO_API UStudent(const UStudent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UStudent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStudent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UStudent) \
	NO_API virtual ~UStudent();


#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_12_PROLOG
#define FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_SPARSE_DATA \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_ACCESSORS \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealSerialization_Source_UnrealSerialization_Student_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALSERIALIZATION_API UClass* StaticClass<class UStudent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealSerialization_Source_UnrealSerialization_Student_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
