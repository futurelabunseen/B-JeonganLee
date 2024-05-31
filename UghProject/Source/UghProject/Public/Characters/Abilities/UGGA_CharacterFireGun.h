// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/UGProjectile.h"
#include "Characters/Abilities/UGGameplayAbility.h"
#include "UGGA_CharacterFireGun.generated.h"

/**
 * 
 */
UCLASS()
class UGHPROJECT_API UUGGA_CharacterFireGun : public UUGGameplayAbility
{
	GENERATED_BODY()

public:
	UUGGA_CharacterFireGun();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<AUGProjectile> ProjectileClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<UAnimMontage> FireMontage;

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UFUNCTION()
	void OnCancelled();
};
