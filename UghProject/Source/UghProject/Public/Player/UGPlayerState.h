// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Characters/Abilities/AttributeSets/UGAttributeSetBase.h"
#include "GameFramework/PlayerState.h"
#include "UGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UGHPROJECT_API AUGPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AUGPlayerState();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class UUGAttributeSetBase* GetAttributeSetBase() const;

	// Attribute Setters
	UFUNCTION(BlueprintCallable, Category = "Ugh|PlayerState|Attributes")
	float GetHealth() const;

protected:
	UPROPERTY(EditAnywhere, Category = GAS)
	TObjectPtr<class UUGAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = GAS)
	TObjectPtr<class UUGAttributeSetBase> AttributeSetBase;

	FDelegateHandle HealthChangedDelegateHandle;
	
	virtual void BeginPlay() override;

	// 어트리뷰트 변경 콜백 함수
	virtual void OnHealthChanged(const FOnAttributeChangeData& Data);
};
