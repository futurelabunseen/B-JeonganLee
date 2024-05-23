// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/UGPlayerState.h"

#include "Characters/Abilities/AttributeSets/UGAttributeSetBase.h"
#include "Characters/Abilities/UGAbilitySystemComponent.h"

AUGPlayerState::AUGPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UUGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(false);

	AttributeSetBase = CreateDefaultSubobject<UUGAttributeSetBase>(TEXT("AttributeSetBase"));
}

UAbilitySystemComponent* AUGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


UUGAttributeSetBase* AUGPlayerState::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

float AUGPlayerState::GetHealth() const
{
	return AttributeSetBase->GetHealth();
}

void AUGPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		HealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetHealthAttribute()).AddUObject(this, &AUGPlayerState::OnHealthChanged);
	}
}

void AUGPlayerState::OnHealthChanged(const FOnAttributeChangeData& Data)
{
	float Health = Data.NewValue;

	// 체력 변경이 되면 실행할 다른 로직을 여기에 추가
	// ex) 체력이 0이 되면 죽음 처리, UI 갱신 등	
	
}
 