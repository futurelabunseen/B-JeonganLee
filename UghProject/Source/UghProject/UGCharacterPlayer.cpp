// Fill out your copyright notice in the Description page of Project Settings.


#include "UGCharacterPlayer.h"

// Sets default values
AUGCharacterPlayer::AUGCharacterPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUGCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUGCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUGCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

