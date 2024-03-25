// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interface/ABAnimationAttackInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABAnimationAttackInterface_generated_h
#error "ABAnimationAttackInterface.generated.h already included, missing '#pragma once' in ABAnimationAttackInterface.h"
#endif
#define ARENABATTLE_ABAnimationAttackInterface_generated_h

#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_SPARSE_DATA
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ARENABATTLE_API UABAnimationAttackInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARENABATTLE_API UABAnimationAttackInterface(UABAnimationAttackInterface&&); \
	ARENABATTLE_API UABAnimationAttackInterface(const UABAnimationAttackInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ARENABATTLE_API, UABAnimationAttackInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABAnimationAttackInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABAnimationAttackInterface) \
	ARENABATTLE_API virtual ~UABAnimationAttackInterface();


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUABAnimationAttackInterface(); \
	friend struct Z_Construct_UClass_UABAnimationAttackInterface_Statics; \
public: \
	DECLARE_CLASS(UABAnimationAttackInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/ArenaBattle"), ARENABATTLE_API) \
	DECLARE_SERIALIZER(UABAnimationAttackInterface)


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IABAnimationAttackInterface() {} \
public: \
	typedef UABAnimationAttackInterface UClassType; \
	typedef IABAnimationAttackInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_10_PROLOG
#define FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_SPARSE_DATA \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class UABAnimationAttackInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Source_ArenaBattle_Interface_ABAnimationAttackInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
