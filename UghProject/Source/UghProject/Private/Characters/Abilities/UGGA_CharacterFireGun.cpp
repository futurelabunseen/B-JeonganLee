// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/UGGA_CharacterFireGun.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "ETC/GamePlayTag.h"

UUGGA_CharacterFireGun::UUGGA_CharacterFireGun()
{
	AbilityInputID = EUGAbilityInputID::Ability1;
	AbilityID = EUGAbilityInputID::Ability1;

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	AbilityTags.AddTag(UGTAG_ABILITY1);
}

void UUGGA_CharacterFireGun::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
	}

	UAbilityTask_PlayMontageAndWait* Task = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, TEXT("PlayAttack"), FireMontage, 1.0f, NAME_None, false, 1.0f);
	Task->ReadyForActivation();
	// UE_LOG(LogTemp, Warning, TEXT("Fire Gun"));

	Task->OnBlendOut.AddDynamic(this, &UUGGA_CharacterFireGun::OnCancelled);
}

void UUGGA_CharacterFireGun::OnCancelled()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
