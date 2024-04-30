// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "person.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API Uperson : public UObject
{
	GENERATED_BODY()

public:
	Uperson();

	FORCEINLINE const FString& GetName () const {return Name;} // const 지시자
	FORCEINLINE void SetName (const FString& NewName) {Name = NewName;}

	FORCEINLINE class UCard* GetCard() const {return Card;}
	FORCEINLINE void SetCard(class UCard* InCard) {Card = InCard;}
	
protected:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	TObjectPtr<class UCard> Card; // 전방선언 (언리얼 5기준)
	//class UCard* Card; // 전방선언 (언리얼 4기준)
};
