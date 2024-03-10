// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/ABGameMode.h"

AABGameMode::AABGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));
	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ThirdPersonClassRef is not found"));
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/ArenaBattle.ABPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
}
