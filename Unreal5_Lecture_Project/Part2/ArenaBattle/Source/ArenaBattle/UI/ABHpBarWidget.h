// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABUserWidget.h"
#include "GameData/ABCharacterStat.h"
#include "ABHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABHpBarWidget : public UABUserWidget
{
	GENERATED_BODY()

public:
	// UUserWidget의 생성자 (다른 형태임)
	UABHpBarWidget(const FObjectInitializer& ObjectInitializer);

protected:
	// UUserWidget에서 제공하는 함수로 아래 UMG 오브젝트 참조를 초기화하기 위해
	virtual void NativeConstruct() override;
	
public:
	void UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat);
	void UpdateHpBar(float NewCurrentHp);
	FString GetHpStatText();
	
protected:
	// 언리얼 오브젝트 포인터로 UProgressBar를 가리키는 포인터 변수 선언 (전방선언 의존성 x)
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgressBar;

	UPROPERTY()
	TObjectPtr<class UTextBlock> HpStat;

	UPROPERTY()
	float CurrentHp;

	UPROPERTY()
	float MaxHp;
};

// 기본적으로 UMG관련 모듈을 사용한다면 Bulid.cs에 추가해야 한다. "UMG"를 추가하면 된다.