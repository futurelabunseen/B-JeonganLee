// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/UGCharacterCyber.h"

AUGCharacterCyber::AUGCharacterCyber()
{
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef (TEXT("/Game/Ugh/Animations/Cyber/ABP_Cyber.ABP_Cyber_C"));
	if (AnimInstanceClassRef.Class)
	{
		GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Spawned AUGCharacterCyber!"));
}
