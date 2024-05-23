// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/UGCharacterBase.h"

#include "Characters/Abilities/UGAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

// Sets default values
AUGCharacterBase::AUGCharacterBase()
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);
}

UAbilitySystemComponent* AUGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

int32 AUGCharacterBase::GetAbilityLevel(EUGAbilityID AbilityID) const
{
	return 1;
}

void AUGCharacterBase::AddCharacterAbilities()
{
	for (const auto& StartAbility : CharacterAbilities)
	{
		//AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartAbility.GetDefaultObject()->AbilityID, GetDefaultObject(StartAbility.GetDefaultObject()->)));
	}
}






