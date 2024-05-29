// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/AbilityTask/UGAT_JumpAndWaitForLanding.h"

#include "GameFramework/Character.h"

UUGAT_JumpAndWaitForLanding::UUGAT_JumpAndWaitForLanding()
{
}

UUGAT_JumpAndWaitForLanding* UUGAT_JumpAndWaitForLanding::CreateTask(UGameplayAbility* OwningAbility)
{
	UUGAT_JumpAndWaitForLanding* NewTask = NewAbilityTask<UUGAT_JumpAndWaitForLanding>(OwningAbility);
	return NewTask;
}

void UUGAT_JumpAndWaitForLanding::Activate()
{
	Super::Activate();

	ACharacter* Character = CastChecked<ACharacter>(GetAvatarActor());
	Character->LandedDelegate.AddDynamic(this, &UUGAT_JumpAndWaitForLanding::OnLandedCallback);
	Character->Jump();

	SetWaitingOnAvatar();
}

void UUGAT_JumpAndWaitForLanding::OnDestroy(bool AbilityEnded)
{
	ACharacter* Character = CastChecked<ACharacter>(GetAvatarActor());
	Character->LandedDelegate.RemoveDynamic(this, &UUGAT_JumpAndWaitForLanding::OnLandedCallback);
	
	Super::OnDestroy(AbilityEnded);
}

void UUGAT_JumpAndWaitForLanding::OnLandedCallback(const FHitResult& Hit)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnComplete.Broadcast();
	}

	EndTask();
}
