// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/ABItemData.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABItemData_generated_h
#error "ABItemData.generated.h already included, missing '#pragma once' in ABItemData.h"
#endif
#define ARENABATTLE_ABItemData_generated_h

#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_SPARSE_DATA
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_ACCESSORS
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABItemData(); \
	friend struct Z_Construct_UClass_UABItemData_Statics; \
public: \
	DECLARE_CLASS(UABItemData, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABItemData)


#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABItemData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABItemData(UABItemData&&); \
	NO_API UABItemData(const UABItemData&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABItemData); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABItemData); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABItemData) \
	NO_API virtual ~UABItemData();


#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_20_PROLOG
#define FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_SPARSE_DATA \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_ACCESSORS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_INCLASS_NO_PURE_DECLS \
	FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class UABItemData>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaBattle_Source_ArenaBattle_Item_ABItemData_h


#define FOREACH_ENUM_EITEMTYPE(op) \
	op(EItemType::Weapon) \
	op(EItemType::Potion) \
	op(EItemType::Scroll) 

enum class EItemType : uint8;
template<> struct TIsUEnumClass<EItemType> { enum { Value = true }; };
template<> ARENABATTLE_API UEnum* StaticEnum<EItemType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
