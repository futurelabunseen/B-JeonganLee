// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ABCharacterStatComponent.generated.h"

// 델리게이트 발행 위쪽은 매개변수 x, 아래쪽은 매개변수 하나
// 컨벤션에 집중
DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;
	
	// 간단한 getter, setter라 inline으로 처리
	FORCEINLINE float GetMaxHp() { return MaxHp; }
	FORCEINLINE float GetCurrentHp() { return CurrentHp; }

	float ApplyDamage(float InDamage);
	
protected:
	// HP변경할 때 사용하는 함수(필수로 입구와 출구를 하나로 만들고 내부에서 훅킹함)
	void SetHp(float NewHp);
	
	// VisibleInstanceOnly 인스턴스마다 다르게 설정할 수 있다.
	UPROPERTY(VisibleInstanceOnly, Category = Stat)
	float MaxHp;

	// Transient: 디스크에 저장하지 않는다. (공간 낭비 x)
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentHp;
};
