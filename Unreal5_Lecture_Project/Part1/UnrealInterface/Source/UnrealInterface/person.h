// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "person.generated.h"

/**
 * 
 */
UCLASS()
class UNREALINTERFACE_API Uperson : public UObject
{
	GENERATED_BODY()

public:
	Uperson();

	FORCEINLINE FString& GetName () {return Name;}
	FORCEINLINE void SetName (const FString& NewName) {Name = NewName;}
protected:
	UPROPERTY()
	FString Name;
};
