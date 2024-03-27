// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"

#include "Components/ProgressBar.h"
#include "Interface/ABCharacterWidgetInterface.h"

// Super를 객체로 초기화하고 MaxHp를 -1로 초기화
UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxHp = -1.0f;
}

void UABHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// GetWidgetFromName: UMG에서 이름으로 찾아서 반환 (Find와 비슷)
	HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PbHpBar")));
	ensure(HpProgressBar);

	IABCharacterWidgetInterface* CharacterWidget = Cast<IABCharacterWidgetInterface>(OwningActor);
	if (CharacterWidget)
	{
		CharacterWidget->SetupCharacterWidget(this);
	}
}

void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{
	// 어서션 함수로 체크
	ensure(MaxHp > 0.0f);
	if (HpProgressBar)
	{
		HpProgressBar->SetPercent(NewCurrentHp / MaxHp);
	}
}
