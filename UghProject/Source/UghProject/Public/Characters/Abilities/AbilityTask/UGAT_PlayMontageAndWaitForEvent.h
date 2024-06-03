// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "UGAT_PlayMontageAndWaitForEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGDPlayMontageAndWaitForEventDelegate, FGameplayTag, EventTag, FGameplayEventData, EventData);

UCLASS()
class UGHPROJECT_API UUGAT_PlayMontageAndWaitForEvent : public UAbilityTask
{
	GENERATED_BODY()

public:
	UUGAT_PlayMontageAndWaitForEvent(const FObjectInitializer& ObjectInitializer);

	virtual void Activate() override;
	virtual void ExternalCancel() override;
	virtual FString GetDebugString() const override;
	virtual void OnDestroy(bool AbilityEnded) override;

	UPROPERTY(BlueprintAssignable)
	FGDPlayMontageAndWaitForEventDelegate OnCompleted;
	
	UPROPERTY(BlueprintAssignable)
	FGDPlayMontageAndWaitForEventDelegate OnBlendOut;
	
	UPROPERTY(BlueprintAssignable)
	FGDPlayMontageAndWaitForEventDelegate OnInterrupted;
	
	UPROPERTY(BlueprintAssignable)
	FGDPlayMontageAndWaitForEventDelegate OnCancelled;
	
	UPROPERTY(BlueprintAssignable)
	FGDPlayMontageAndWaitForEventDelegate EventReceived;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UUGAT_PlayMontageAndWaitForEvent* PlayMontageAndWaitForEvent(
			UGameplayAbility* OwningAbility,
			FName TaskInstanceName,
			UAnimMontage* MontageToPlay,
			FGameplayTagContainer EventTags,
			float Rate = 1.f,
			FName StartSection = NAME_None,
			bool bStopWhenAbilityEnds = true,
			float AnimRootMotionTranslationScale = 1.f);

private:
	UPROPERTY()
	UAnimMontage* MontageToPlay;
	
	UPROPERTY()
	FGameplayTagContainer EventTags;
	
	UPROPERTY()
	float Rate;
	
	UPROPERTY()
	FName StartSection;
	
	UPROPERTY()
	float AnimRootMotionTranslationScale;
	
	UPROPERTY()
	bool bStopWhenAbilityEnds;
	
	bool StopPlayingMontage();

	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	void OnAbilityCancelled();
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload);

	FOnMontageBlendingOutStarted BlendingOutDelegate;
	FOnMontageEnded MontageEndedDelegate;
	FDelegateHandle CancelledHandle;
	FDelegateHandle EventHandle;
};
