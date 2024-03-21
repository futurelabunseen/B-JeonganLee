// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LessonInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALINTERFACE_LessonInterface_generated_h
#error "LessonInterface.generated.h already included, missing '#pragma once' in LessonInterface.h"
#endif
#define UNREALINTERFACE_LessonInterface_generated_h

#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_SPARSE_DATA
#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_ACCESSORS
#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UNREALINTERFACE_API ULessonInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UNREALINTERFACE_API ULessonInterface(ULessonInterface&&); \
	UNREALINTERFACE_API ULessonInterface(const ULessonInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UNREALINTERFACE_API, ULessonInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULessonInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULessonInterface) \
	UNREALINTERFACE_API virtual ~ULessonInterface();


#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesULessonInterface(); \
	friend struct Z_Construct_UClass_ULessonInterface_Statics; \
public: \
	DECLARE_CLASS(ULessonInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/UnrealInterface"), UNREALINTERFACE_API) \
	DECLARE_SERIALIZER(ULessonInterface)


#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ILessonInterface() {} \
public: \
	typedef ULessonInterface UClassType; \
	typedef ILessonInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_10_PROLOG
#define FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_SPARSE_DATA \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_ACCESSORS \
	FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALINTERFACE_API UClass* StaticClass<class ULessonInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealInterface_Source_UnrealInterface_LessonInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
