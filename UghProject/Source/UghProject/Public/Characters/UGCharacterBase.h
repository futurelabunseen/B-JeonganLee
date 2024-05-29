// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "UghProject.h"
#include "GameFramework/Character.h"
#include "UGCharacterBase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

// 추상클래스의 역할로 사용
UCLASS()
class UGHPROJECT_API AUGCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AUGCharacterBase();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "Ugh|Abilities")
	virtual int32 GetAbilityLevel(EUGAbilityInputID AbilityID) const;
	
protected:
	TWeakObjectPtr<class UUGAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<class UUGAttributeSetBase> AttributeSetBase;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ugh|Abilities")
	TArray<TSubclassOf<class UUGGameplayAbility>> CharacterAbilities;

	virtual void AddCharacterAbilities();
	
};
