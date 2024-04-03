// Fill out your copyright notice in the Description page of Project Settings.


#include "UGGameMode.h"

AUGGameMode::AUGGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Ugh/Blueprints/BP_CharacterPlayer'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find PlayerPawnBPClass"));
	}
}
