// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "MyActor.generated.h"

UCLASS()
class GASEXAMPLE_API AMyActor : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	AMyActor();
	
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;


protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void TimerAction();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<class UStaticMeshComponent> MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	TObjectPtr<class URotatingMovementComponent> RotatingMovementComponent;

	UPROPERTY(EditAnywhere, Category = "Timer")
	float ActionPeriod;

	UPROPERTY(EditAnywhere, Category=GAS)
	TObjectPtr<class UAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere, Category=GAS)
	TArray<TSubclassOf<class UGameplayAbility>> StartAbilities;
	
	FTimerHandle ActionTimer;
};
