// Fill out your copyright notice in the Description page of Project Settings.


#include "Prop/MyActor.h"

#include "GasExample.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GasExample.h"
#include "AbilitySystemComponent.h"
#include "Tag/GamePlayTag.h"

// Sets default values
AMyActor::AMyActor()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC")); // Ability System Component을 생성하고
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));

	RootComponent = MeshComponent;

	ActionPeriod = 3.0f;
}

UAbilitySystemComponent* AMyActor::GetAbilitySystemComponent() const // Ability System Component를 반환하는 함수 (IAbilitySystemInterface를 상속받아서 구현)
{
	return ASC;
}

void AMyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	RotatingMovementComponent->bAutoActivate = false;
	RotatingMovementComponent->Deactivate();

	ASC->InitAbilityActorInfo(this, this);  // Ability System Component를 초기화하고 자신을 Actor로 설정
	
	for (const auto& StartAbility : StartAbilities)
	{
		FGameplayAbilitySpec StartSpec(StartAbility);
		ASC->GiveAbility(StartSpec);
	}
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// 3초마다 TimerAction 함수를 호출하는 타이머를 생성 (이건 코루틴과 비슷한 기능을 하는 듯)
	GetWorld()->GetTimerManager().SetTimer(ActionTimer, this, &AMyActor::TimerAction, ActionPeriod, true, 0.0f);
}

void AMyActor::TimerAction()
{
	GAS_LOG(LogABGAS, Log, TEXT("TimerAction"));

	FGameplayTagContainer TargetTag(ACTOR_ROTATE);

	if (!ASC->HasMatchingGameplayTag(ACTOR_ROTATE))
	{
		ASC->TryActivateAbilitiesByTag(TargetTag);
	}
	else
	{
		ASC->CancelAbilities(&TargetTag);
	}

	// const FGameplayAbilitySpec* RotateGASpec = ASC->FindAbilitySpecFromClass(UMyGameplayAbility_Rotate::StaticClass()); // RotateGASpec을 찾아서
	// if (!RotateGASpec)
	// {
	// 	ABGAS_LOG(LogABGAS, Error, TEXT("RotateGASSpec is null"));
	// 	return;
	// }
	//
	// // 실행
	// if (!RotateGASpec->IsActive())
	// {
	// 	ASC->TryActivateAbility(RotateGASpec->Handle);
	// }
	// else
	// {
	// 	ASC->CancelAbilityHandle(RotateGASpec->Handle);
	// }

	// if (!RotatingMovementComponent->IsActive())
	// {
	// 	RotatingMovementComponent->Activate(true);
	// }
	// else
	// {
	// 	RotatingMovementComponent->Deactivate();
	// }
}
