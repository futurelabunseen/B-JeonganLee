// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/UGGameplayAbility.h"

#include "AbilitySystemComponent.h"

UUGGameplayAbility::UUGGameplayAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerExecution;
}

void UUGGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);

	if (ActivateAbilityOnGranted)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, true);
	}
}
