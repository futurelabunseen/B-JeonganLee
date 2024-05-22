// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/UGPlayerState.h"

#include "AbilitySystemComponent.h"

AUGPlayerState::AUGPlayerState()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
}

UAbilitySystemComponent* AUGPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}
