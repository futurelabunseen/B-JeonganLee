// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

UENUM() // 언리얼이 확인할 수 있게 만들어줌
enum class ECardType : uint8
{
	Student = 1 UMETA(DisplayName = "For Student"), // 각 항목에 대한 메타정보도 사용 가능
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
};

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UCard();

	ECardType GetCardType() const { return CardType; }
	void SetCardType(ECardType NewCardType) { CardType = NewCardType; }

private:
	UPROPERTY()
	ECardType CardType;

	UPROPERTY()
	uint32 Id;	
};
