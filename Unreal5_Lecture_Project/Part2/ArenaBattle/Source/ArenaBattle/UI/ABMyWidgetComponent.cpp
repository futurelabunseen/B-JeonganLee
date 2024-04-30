// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABMyWidgetComponent.h"

#include "ABUserWidget.h"

void UABMyWidgetComponent::InitWidget()
{
	Super::InitWidget();

	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());
	if (ABUserWidget)
	{
		ABUserWidget->SetOwningActor(GetOwner());
	}
}
