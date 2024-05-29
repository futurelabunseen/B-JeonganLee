// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UghProject.h"
#include "Abilities/GameplayAbility.h"
#include "UGGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class UGHPROJECT_API UUGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UUGGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EUGAbilityInputID AbilityInputID = EUGAbilityInputID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EUGAbilityInputID AbilityID = EUGAbilityInputID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	bool ActivateAbilityOnGranted = false;

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
