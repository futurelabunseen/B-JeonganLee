
// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Abilities/UGAbilitySystemComponent.h"

void UUGAbilitySystemComponent::ReceiveDamage(UUGAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage)
{
	ReceivedDamage.Broadcast(SourceASC, UnmitigatedDamage, MitigatedDamage);
}
