// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/ABItemBox.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UParticleSystemComponent;
class UPrimitiveComponent;
struct FHitResult;
#ifdef ARENABATTLE_ABItemBox_generated_h
#error "ABItemBox.generated.h already included, missing '#pragma once' in ABItemBox.h"
#endif
#define ARENABATTLE_ABItemBox_generated_h

#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_SPARSE_DATA
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEffectFinished); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABItemBox(); \
	friend struct Z_Construct_UClass_AABItemBox_Statics; \
public: \
	DECLARE_CLASS(AABItemBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABItemBox)


#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABItemBox(AABItemBox&&); \
	NO_API AABItemBox(const AABItemBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABItemBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABItemBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABItemBox) \
	NO_API virtual ~AABItemBox();


#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_9_PROLOG
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_SPARSE_DATA \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_INCLASS_NO_PURE_DECLS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class AABItemBox>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Source_ArenaBattle_Item_ABItemBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
