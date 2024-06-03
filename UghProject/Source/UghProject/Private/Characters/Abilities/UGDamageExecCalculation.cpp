// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/UGDamageExecCalculation.h"

#include "Characters/Abilities/UGAbilitySystemComponent.h"
#include "Characters/Abilities/AttributeSets/UGAttributeSetBase.h"

struct UGDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	UGDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UUGAttributeSetBase, Armor, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UUGAttributeSetBase, Damage, Target, true);
	}
};

static const UGDamageStatics& DamageStatics()
{
	static UGDamageStatics DStatics;
	return DStatics;
}

UUGDamageExecCalculation::UUGDamageExecCalculation()
{
	RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
}

void UUGDamageExecCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UAbilitySystemComponent *TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent *SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor *SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->GetAvatarActor() : nullptr;
	AActor *TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec &Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer *SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer *TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Armor = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef, EvaluationParameters, Armor);
	Armor = FMath::Max<float>(Armor, 0.0f);

	float Damage = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, EvaluationParameters, Damage);
	Damage += FMath::Max<float>(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Damage")), false, -1.0f), 0.0f);

	float UnmitigatedDamage = Damage;
	float MitigatedDamage = UnmitigatedDamage * (100 / (100 + Armor));

	if (MitigatedDamage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Additive, MitigatedDamage));
	}

	UUGAbilitySystemComponent *TargetASC = Cast<UUGAbilitySystemComponent>(TargetAbilitySystemComponent);
	if (TargetASC)
	{
		UUGAbilitySystemComponent *SourceASC = Cast<UUGAbilitySystemComponent>(SourceAbilitySystemComponent);
		TargetASC->ReceiveDamage(SourceASC, UnmitigatedDamage, MitigatedDamage);
	}
}
