// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Character/ABCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacterBase() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterBase();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacterBase_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABAnimationAttackInterface_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABCharacterControlData_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABCharacterItemInterface_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABCharacterStatComponent_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABCharacterWidgetInterface_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABComboActionData_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABMyWidgetComponent_NoRegister();
	ARENABATTLE_API UEnum* Z_Construct_UEnum_ArenaBattle_ECharacterControlType();
	ARENABATTLE_API UScriptStruct* Z_Construct_UScriptStruct_FTakeItemDelegateWrapper();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECharacterControlType;
	static UEnum* ECharacterControlType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECharacterControlType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECharacterControlType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ArenaBattle_ECharacterControlType, (UObject*)Z_Construct_UPackage__Script_ArenaBattle(), TEXT("ECharacterControlType"));
		}
		return Z_Registration_Info_UEnum_ECharacterControlType.OuterSingleton;
	}
	template<> ARENABATTLE_API UEnum* StaticEnum<ECharacterControlType>()
	{
		return ECharacterControlType_StaticEnum();
	}
	struct Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::Enumerators[] = {
		{ "ECharacterControlType::Shoulder", (int64)ECharacterControlType::Shoulder },
		{ "ECharacterControlType::Quater", (int64)ECharacterControlType::Quater },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
		{ "Quater.Name", "ECharacterControlType::Quater" },
		{ "Shoulder.Name", "ECharacterControlType::Shoulder" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ArenaBattle,
		nullptr,
		"ECharacterControlType",
		"ECharacterControlType",
		Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_ArenaBattle_ECharacterControlType()
	{
		if (!Z_Registration_Info_UEnum_ECharacterControlType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECharacterControlType.InnerSingleton, Z_Construct_UEnum_ArenaBattle_ECharacterControlType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECharacterControlType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper;
class UScriptStruct* FTakeItemDelegateWrapper::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTakeItemDelegateWrapper, (UObject*)Z_Construct_UPackage__Script_ArenaBattle(), TEXT("TakeItemDelegateWrapper"));
	}
	return Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper.OuterSingleton;
}
template<> ARENABATTLE_API UScriptStruct* StaticStruct<FTakeItemDelegateWrapper>()
{
	return FTakeItemDelegateWrapper::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xeb\xa1\x9c \xeb\xb3\x80\xec\x88\x98\xeb\xa5\xbc \xeb\xa7\x8c\xeb\x93\xa4 \xec\x88\x98 \xec\x97\x86\xea\xb8\xb0 \xeb\x95\x8c\xeb\xac\xb8\xec\x97\x90, \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xeb\xa5\xbc \xeb\x9e\x98\xed\x95\x91\xed\x95\x98\xeb\x8a\x94 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\xeb\xa5\xbc \xeb\xa7\x8c\xeb\x93\xa4\xec\x96\xb4\xec\x84\x9c \xeb\xb3\x80\xec\x88\x98\xeb\xa1\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4.\n" },
#endif
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xeb\xa1\x9c \xeb\xb3\x80\xec\x88\x98\xeb\xa5\xbc \xeb\xa7\x8c\xeb\x93\xa4 \xec\x88\x98 \xec\x97\x86\xea\xb8\xb0 \xeb\x95\x8c\xeb\xac\xb8\xec\x97\x90, \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xeb\xa5\xbc \xeb\x9e\x98\xed\x95\x91\xed\x95\x98\xeb\x8a\x94 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\xeb\xa5\xbc \xeb\xa7\x8c\xeb\x93\xa4\xec\x96\xb4\xec\x84\x9c \xeb\xb3\x80\xec\x88\x98\xeb\xa1\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTakeItemDelegateWrapper>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
		nullptr,
		&NewStructOps,
		"TakeItemDelegateWrapper",
		nullptr,
		0,
		sizeof(FTakeItemDelegateWrapper),
		alignof(FTakeItemDelegateWrapper),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTakeItemDelegateWrapper()
	{
		if (!Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper.InnerSingleton, Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper.InnerSingleton;
	}
	void AABCharacterBase::StaticRegisterNativesAABCharacterBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABCharacterBase);
	UClass* Z_Construct_UClass_AABCharacterBase_NoRegister()
	{
		return AABCharacterBase::StaticClass();
	}
	struct Z_Construct_UClass_AABCharacterBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterControlManager_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CharacterControlManager_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CharacterControlManager_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterControlManager_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_CharacterControlManager;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComboActionMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ComboActionMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComboActionData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ComboActionData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeadMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_DeadMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Stat_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Stat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HpBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_HpBar;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Weapon;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TakeItemActions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TakeItemActions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TakeItemActions;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABCharacterBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/ABCharacterBase.h" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_ValueProp = { "CharacterControlManager", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UABCharacterControlData_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_Key_KeyProp = { "CharacterControlManager_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ArenaBattle_ECharacterControlType, METADATA_PARAMS(0, nullptr) }; // 1044877428
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CharacterControl" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager = { "CharacterControlManager", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, CharacterControlManager), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_MetaData) }; // 1044877428
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionMontage_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x91\x98\xeb\x8b\xa4 \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xec\x84\xa4\xec\xa0\x95\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d \xec\x97\xb4\xec\x96\xb4\xeb\x91\x94 \xeb\xb3\x80\xec\x88\x98\n// \xec\x9c\x84\xeb\x8a\x94 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc, \xec\x95\x84\xeb\x9e\x98\xeb\x8a\x94 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\x97\x90\xec\x85\x8b\xec\x9d\xb4\xeb\x8b\xa4.\n" },
#endif
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x91\x98\xeb\x8b\xa4 \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xec\x84\xa4\xec\xa0\x95\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d \xec\x97\xb4\xec\x96\xb4\xeb\x91\x94 \xeb\xb3\x80\xec\x88\x98\n\xec\x9c\x84\xeb\x8a\x94 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc, \xec\x95\x84\xeb\x9e\x98\xeb\x8a\x94 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\x97\x90\xec\x85\x8b\xec\x9d\xb4\xeb\x8b\xa4." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionMontage = { "ComboActionMontage", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, ComboActionMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionMontage_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionData_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionData = { "ComboActionData", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, ComboActionData), Z_Construct_UClass_UABComboActionData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionData_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionData_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_DeadMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_DeadMontage = { "DeadMontage", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, DeadMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_DeadMontage_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_DeadMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Stat_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Stat = { "Stat", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, Stat), Z_Construct_UClass_UABCharacterStatComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Stat_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Stat_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_HpBar_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Widget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_HpBar = { "HpBar", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, HpBar), Z_Construct_UClass_UABMyWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_HpBar_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_HpBar_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Weapon_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Equipment" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, Weapon), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Weapon_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Weapon_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions_Inner = { "TakeItemActions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTakeItemDelegateWrapper, METADATA_PARAMS(0, nullptr) }; // 3262415432
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions_MetaData[] = {
		{ "ModuleRelativePath", "Character/ABCharacterBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions = { "TakeItemActions", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABCharacterBase, TakeItemActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions_MetaData), Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions_MetaData) }; // 3262415432
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABCharacterBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_CharacterControlManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_ComboActionData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_DeadMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Stat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_HpBar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_Weapon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABCharacterBase_Statics::NewProp_TakeItemActions,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AABCharacterBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UABAnimationAttackInterface_NoRegister, (int32)VTABLE_OFFSET(AABCharacterBase, IABAnimationAttackInterface), false },  // 1861011270
			{ Z_Construct_UClass_UABCharacterWidgetInterface_NoRegister, (int32)VTABLE_OFFSET(AABCharacterBase, IABCharacterWidgetInterface), false },  // 3978123899
			{ Z_Construct_UClass_UABCharacterItemInterface_NoRegister, (int32)VTABLE_OFFSET(AABCharacterBase, IABCharacterItemInterface), false },  // 122915905
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABCharacterBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABCharacterBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AABCharacterBase_Statics::ClassParams = {
		&AABCharacterBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABCharacterBase_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AABCharacterBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABCharacterBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AABCharacterBase()
	{
		if (!Z_Registration_Info_UClass_AABCharacterBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABCharacterBase.OuterSingleton, Z_Construct_UClass_AABCharacterBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AABCharacterBase.OuterSingleton;
	}
	template<> ARENABATTLE_API UClass* StaticClass<AABCharacterBase>()
	{
		return AABCharacterBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABCharacterBase);
	AABCharacterBase::~AABCharacterBase() {}
	struct Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::EnumInfo[] = {
		{ ECharacterControlType_StaticEnum, TEXT("ECharacterControlType"), &Z_Registration_Info_UEnum_ECharacterControlType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1044877428U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::ScriptStructInfo[] = {
		{ FTakeItemDelegateWrapper::StaticStruct, Z_Construct_UScriptStruct_FTakeItemDelegateWrapper_Statics::NewStructOps, TEXT("TakeItemDelegateWrapper"), &Z_Registration_Info_UScriptStruct_TakeItemDelegateWrapper, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTakeItemDelegateWrapper), 3262415432U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AABCharacterBase, AABCharacterBase::StaticClass, TEXT("AABCharacterBase"), &Z_Registration_Info_UClass_AABCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABCharacterBase), 1585305379U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_3897325380(TEXT("/Script/ArenaBattle"),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaBattle_Source_ArenaBattle_Character_ABCharacterBase_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
