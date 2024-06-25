// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Abilities/UGGA_CharacterFireGun.h"
#include "Characters/Abilities/AbilityTask/UGAT_PlayMontageAndWaitForEvent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/Class/UGCharacterPlayer.h"
#include "ETC/GamePlayTag.h"
#include "Kismet/KismetMathLibrary.h"

UUGGA_CharacterFireGun::UUGGA_CharacterFireGun()
{
	AbilityInputID = EUGAbilityInputID::Ability1;
	AbilityID = EUGAbilityInputID::Ability1;

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	AbilityTags.AddTag(UGTAG_ABILITY1);

	Range = 10000.0f;
	Damage = 10.0f;
}

void UUGGA_CharacterFireGun::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
	}

	UUGAT_PlayMontageAndWaitForEvent* Task = UUGAT_PlayMontageAndWaitForEvent::PlayMontageAndWaitForEvent(this, NAME_None, FireMontage, FGameplayTagContainer(), 1.0f, NAME_None, false, 1.0f);
	Task->OnBlendOut.AddDynamic(this, &UUGGA_CharacterFireGun::OnCompleted);
	Task->OnCompleted.AddDynamic(this, &UUGGA_CharacterFireGun::OnCompleted);
	Task->OnInterrupted.AddDynamic(this, &UUGGA_CharacterFireGun::OnCancelled);
	Task->OnCancelled.AddDynamic(this, &UUGGA_CharacterFireGun::OnCancelled);
	Task->EventReceived.AddDynamic(this, &UUGGA_CharacterFireGun::EventReceived);
	Task->ReadyForActivation();
}

void UUGGA_CharacterFireGun::InputPressed(const FGameplayAbilitySpecHandle Handle,const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputPressed(Handle, ActorInfo, ActivationInfo);

	// 키 입력이 눌렸을 때의 처리 (총 발사)
}

void UUGGA_CharacterFireGun::CancelAbility(const FGameplayAbilitySpecHandle Handle,const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);

	// 총 발사 취소
}

void UUGGA_CharacterFireGun::EndAbility(const FGameplayAbilitySpecHandle Handle,const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UUGGA_CharacterFireGun::OnCancelled(FGameplayTag EventTag, FGameplayEventData EventData)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}

void UUGGA_CharacterFireGun::OnCompleted(FGameplayTag EventTag, FGameplayEventData EventData)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UUGGA_CharacterFireGun::EventReceived(FGameplayTag EventTag, FGameplayEventData EventData)
{
	
	if (EventTag == UGTAG_EVENT_MONTAGE_ENDABILITY)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
		return;
	}

	if (EventTag == UGTAG_EVENT_MONTAGE_SPAWNPROJECTILE)
	{
		AUGCharacterPlayer* Character = Cast<AUGCharacterPlayer>(GetAvatarActorFromActorInfo());
		if (!Character)
		{
			EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		}
		
		FVector Start = Character->GetMesh()->GetSocketLocation(FName("Muzzle_02"));
		FVector End = Character->GetCameraBoom()->GetComponentLocation() + Character->GetFollowCamera()->GetForwardVector() * Range;
		FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		if (GEngine)
		{
			UWorld* World = GetWorld();
			if (World)
			{
				DrawDebugLine(World, Start, End, FColor::Red, false, 5.0f, 0, 1.0f);
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("Ability Level: %d"), GetAbilityLevel());
		FGameplayEffectSpecHandle DamageEffectSpecHandle = MakeOutgoingGameplayEffectSpec(DamageGameplayEffect, GetAbilityLevel());

		DamageEffectSpecHandle.Data.Get()->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Damage")), Damage); // Todo

		FTransform MuzzleTransform = Character->GetMesh()->GetSocketTransform(FName("Muzzle_02"));
		MuzzleTransform.SetRotation(Rotation.Quaternion());
		MuzzleTransform.SetScale3D(FVector(1.0f));

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; // TOdo

		AUGProjectile* Projectile = GetWorld()->SpawnActorDeferred<AUGProjectile>(ProjectileClass, MuzzleTransform,
			GetOwningActorFromActorInfo(), Character, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		Projectile->DamageEffectSpecHandle = DamageEffectSpecHandle;
		Projectile->Range = Range;
		Projectile->FinishSpawning(MuzzleTransform);
	}
}


