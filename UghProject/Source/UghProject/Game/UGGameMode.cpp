// Fill out your copyright notice in the Description page of Project Settings.


#include "UGGameMode.h"

void AUGGameMode::StartPlay()
{
	Super::StartPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Hello World, this is UGGameMode!"));
}

AUGGameMode::AUGGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Ugh/Blueprints/Character/BP_CharacterCyber.BP_CharacterCyber_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/UghProject.UGPlayerController"));
    if (PlayerControllerClassRef.Class)
    {
    	PlayerControllerClass = PlayerControllerClassRef.Class;
    }
}
