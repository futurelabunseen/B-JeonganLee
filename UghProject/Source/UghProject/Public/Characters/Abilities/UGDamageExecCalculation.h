// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "UGDamageExecCalculation.generated.h"

/**
 * 
 */
UCLASS()
class UGHPROJECT_API UUGDamageExecCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UUGDamageExecCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
