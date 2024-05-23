// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UGAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UUGAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class UGHPROJECT_API UUGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	bool bCharacterAbilitiesGiven = false; // 어빌리티를 캐릭터에게 주었는지 여부
	bool bStartupEffectsApplied = false;

	// 데미지를 받았을 때 브로드캐스트되는 델리게이트
	FReceivedDamageDelegate ReceivedDamage;

	virtual void ReceiveDamage(UUGAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
};
