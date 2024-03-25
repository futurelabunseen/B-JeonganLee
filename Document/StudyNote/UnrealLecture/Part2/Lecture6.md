# 6강: 캐릭터 공격 판정

- 강의 목표
  - 애니메이션 이벤트 발생을 위한 노티파이 설정 방법의 학습
  - 공격 판정을 이한 트레이스 채널 설정과 판정을 시각적으로 디버깅하는 방법의 학습
  - 데미지 프레임웍을 활용한 데미지 전달과 Dead 상태의 구현
- 강의 과제
  - 자신의 게임에서 활용할 채널과 프로필 설정 및 사용할 트레이스 기능에 대해 정리하시오
  - 자신의 게임에서 물리 오브젝트 타입을 추가할 계획이 있는지, 없다면 왜 그런지 이유를 설명하시오

## 충돌 채널의 설정

### 캐릭터 액션의 충돌 판정

- 월드가 제공하는 충돌 판정 서비스를 사용한다. 월드는 크게 3가지의 충돌 판정 서비스를 제공한다. 월드 내에 배치된 충돌체와 충돌하는지 파악하고, 충돌한 액터 정보를 얻을 수 있음
  - LineTrace
  - Sweep
  - Overlap

*Unity의 Collider, Raycast와 유사한 기능을 제공한다.*

### 트레이스 채널과 충돌 프로필 생성

- 액션 판정을 위한 트레이스 채널의 생성 `ABAction`(기본 반응은 무시)
- 캐릭터 캡슐용 프로필: `ABAction`트레이스 채널에 반응. 오브젝트 타입은 `Pawn`
- 스켈레탈 메시용 프로필: 랙돌 구현을 위해 주로 사용
- 기믹 트리거용 프로필: 폰 캡슐에만 반응하도록 설정. 오브젝트 타입은 `WorldStatic`

### 실습

- `ProjectSetting -> Collision`에서 `ABAction`을 트레이스 채널로 설정한다.
- 이어서 `Preset` 항목에서 새로운 프리셋을 생성한다.
  - `ABCapsule` 프로필을 생성한다. `ABAction` 트레이스 채널에 반응하도록 설정한다. (대상 캡슐)
  - `ABTrigger` 프로필을 생성한다. `ABAction` 트레이스 채널에 반응하도록 설정한다. (맵에 존재하는 오브젝트)
- 이후에 몽타주에서 애니메이션 도중에 호출할 `Notify`를 생성한다.
  - `Notify`도 마찬가지로 사용자 지정으로 생성이 가능하다.

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_AttackHitCheck.generated.h"

UCLASS()
class ARENABATTLE_API UAnimNotify_AttackHitCheck : public UAnimNotify
{
 GENERATED_BODY()

protected:
 virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
```

```cpp
#include "Animation/AnimNotify_AttackHitCheck.h"
#include "Interface/ABAnimationAttackInterface.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
 Super::Notify(MeshComp, Animation, EventReference);

 if (MeshComp)
 {
  // 언리얼의 특징? 얽힌 상속 구조를 사용하여 Notify될 때 MeshComp의 Owner를 찾아서 IABAnimationAttackInterface를 구현한 객체를 찾아서 AttackHitCheck를 호출한다.
  IABAnimationAttackInterface* AttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());

  if (AttackPawn)
  {
   AttackPawn->AttackHitCheck();
  }
 }
}
```

```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ABAnimationAttackInterface.generated.h"

UINTERFACE(MinimalAPI)
class UABAnimationAttackInterface : public UInterface
{
 GENERATED_BODY()
};

class ARENABATTLE_API IABAnimationAttackInterface
{
 GENERATED_BODY()

public:
 virtual void AttackHitCheck() = 0;
};
```

- `virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;`
  - 엔진 5이후로 사용해야 하는 `Notify`가상 함수를 오버로딩하여 추가 구현을 진행한다.
  - 내부에서 `USkeletalMeshComponent`에 접근하여 `Owner`를 찾아서 `IABAnimationAttackInterface`를 구현한 객체를 찾아서 `AttackHitCheck`를 호출한다.
  - 다른 객체에서도 사용할 수 있도록 `IABAnimationAttackInterface`를 생성한다. (의존성 분리)

## 공격 판정의 구현

### 월드 트레이싱 함수의 선택

크게 세 가지 카테고리로 원하는 함수 이름을 얻을 수 있다.

- 카테고리 1: 처리 방법
- 카테고리 2: 대상
  - Test: 무언가 감지되었는지를 테스트
  - Single 또는 AnyTest: 감지된 단일 물체 정보를 반환
  - Multi: 감지된 모든 물체 정보를 반환
  - *아마 속도의 차이가 있지 않을까?*
- 카테고리 3: 처리 설정
  - ByChannel: 채널 정보를 사용해 감지
  - ByObjectType: 물체에 지정된 물리 타입 정보를 사용해 감지
  - ByProfile: 프로필 정보를 사용해 감지

`{처리방법}{대상}{처리설정}`

### 캐릭터 공격 판정의 구현

- 캐릭터 위치에서 시선 방향으로 물체가 있는지 감지
- 작은 구체를 제작하고 시선 방향으로 특정 거리까지만 투사
- 하나의 물체만 감지
- 트레이스 채널을 사용한다

`{Sweep}{Single}{ByChannel}`

### 물리 충돌 테스트

디버그 드로잉을 이용한 물리 충돌을 시각적으로 테스트한다.

- 캡슐
  - Origin
  - HalfHeight
  - Radius

### 실습

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/ABAnimationAttackInterface.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
 Shoulder,
 Quater
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter, public IABAnimationAttackInterface
{
 GENERATED_BODY()

public:
 // Sets default values for this character's properties
 AABCharacterBase();

protected:
 virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);

 UPROPERTY(EditAnywhere, Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
 TMap<ECharacterControlType, class UABCharacterControlData*> CharacterControlManager;

 // Combo Action Section
protected:

 // 둘다 블루프린트에서 설정할 수 있도록 열어둔 변수
 // 위는 몽타주, 아래는 데이터 에셋이다.
 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
 TObjectPtr<class UAnimMontage> ComboActionMontage;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UABComboActionData> ComboActionData;

 // 키에 바인딩 될 메서드
 void ProcessComboCommand();

 // 시작 그리고 종료에 각각 호출되는 메서드
 void ComboActionBegin();
 void ComboActionEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);

 // 타이머 발동 메소드와 입력이 들어왔는지 체크하는 함수
 void SetComboCheckTimer();
 void ComboCheck();
 
 // 콤보 Flag 변수
 int32 CurrentCombo = 0;
 // 언리얼 엔진 월드에서 제공하는 특정 타이머 기능을 사용할 수 있는 구조체
 FTimerHandle ComboTimerHandle; 
 bool HasNextComboCommand = false;

 // AttackHit Section
protected:
 virtual void AttackHitCheck() override;
 virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

 // Dead Section
protected:
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UAnimMontage> DeadMontage;

 virtual void SetDead();
 void PlayDeadAnimation();

 float DeadEventDelayTime = 5.0f;
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterControlData.h"
#include "ABComboActionData.h"
#include "Engine/DamageEvents.h"
#include "Physics/ABCollision.h"

// Sets default values
AABCharacterBase::AABCharacterBase()
{
 // Pawn
 bUseControllerRotationPitch = false;
 bUseControllerRotationYaw = false;
 bUseControllerRotationRoll = false;

 // Capsule
 GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
 GetCapsuleComponent()->SetCollisionProfileName(CPROFILE_ABCAPSULE);

 // Movement
 GetCharacterMovement()->bOrientRotationToMovement = true;
 GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
 GetCharacterMovement()->JumpZVelocity = 700.f;
 GetCharacterMovement()->AirControl = 0.35f;
 GetCharacterMovement()->MaxWalkSpeed = 500.f;
 GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
 GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

 // Mesh
 GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
 GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
 GetMesh()->SetCollisionProfileName(TEXT("NoCollision"));

 static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
 if (CharacterMeshRef.Object)
 {
  GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
 }

 static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef(TEXT("/Game/ArenaBattle/Animation/ABP_ABCharacter.ABP_ABCharacter_C"));
 if (AnimInstanceClassRef.Class)
 {
  GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
 }

 static ConstructorHelpers::FObjectFinder<UABCharacterControlData> ShoulderDataRef(TEXT("/Script/ArenaBattle.ABCharacterControlData'/Game/ArenaBattle/CharacterControl/ABC_Shoulder.ABC_Shoulder'"));
 if (ShoulderDataRef.Object)
 {
  CharacterControlManager.Add(ECharacterControlType::Shoulder, ShoulderDataRef.Object);
 }

 static ConstructorHelpers::FObjectFinder<UABCharacterControlData> QuaterDataRef(TEXT("/Script/ArenaBattle.ABCharacterControlData'/Game/ArenaBattle/CharacterControl/ABC_Quater.ABC_Quater'"));
 if (QuaterDataRef.Object)
 {
  CharacterControlManager.Add(ECharacterControlType::Quater, QuaterDataRef.Object);
 }

 static ConstructorHelpers::FObjectFinder<UAnimMontage> ComboActionMontageRef(TEXT("/Script/Engine.AnimMontage'/Game/ArenaBattle/Animation/AM_ComboAttack.AM_ComboAttack'"));
 if (ComboActionMontageRef.Object)
 {
  ComboActionMontage = ComboActionMontageRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UABComboActionData> ComboActionDataRef(TEXT("/Script/ArenaBattle.ABComboActionData'/Game/ArenaBattle/CharacterAction/ABA_ComboAttack.ABA_ComboAttack'"));
 if (ComboActionDataRef.Object)
 {
  ComboActionData = ComboActionDataRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UAnimMontage> DeadMontageRef(TEXT("/Script/Engine.AnimMontage'/Game/ArenaBattle/Animation/AM_Dead.AM_Dead'"));
 if (DeadMontageRef.Object)
 {
  DeadMontage = DeadMontageRef.Object;
 }
}

void AABCharacterBase::SetCharacterControlData(const UABCharacterControlData* CharacterControlData)
{
 // Pawn
 bUseControllerRotationYaw = CharacterControlData->bUseControllerRotationYaw;

 // CharacterMovement
 GetCharacterMovement()->bOrientRotationToMovement = CharacterControlData->bOrientRotationToMovement;
 GetCharacterMovement()->bUseControllerDesiredRotation = CharacterControlData->bUseControllerDesiredRotation;
 GetCharacterMovement()->RotationRate = CharacterControlData->RotationRate;
}

void AABCharacterBase::ProcessComboCommand()
{
 if (CurrentCombo == 0)
 {
  ComboActionBegin();
  return;
 }
 
 if (!ComboTimerHandle.IsValid())
 {
  HasNextComboCommand = false;
 }
 else
 {
  HasNextComboCommand = true;
 }
}

void AABCharacterBase::ComboActionBegin()
{
 // Combo Start
 CurrentCombo = 1;

 // Movement Setting
 // 캐릭터의 움직임을 제한한다.
 GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);

 // Animation Setting
 const float AttackSpeedRate = 1.0f;
 UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
 AnimInstance->Montage_Play(ComboActionMontage, AttackSpeedRate);

 FOnMontageEnded EndDelegate;
 EndDelegate.BindUObject(this, &AABCharacterBase::ComboActionEnd);
 AnimInstance->Montage_SetEndDelegate(EndDelegate, ComboActionMontage);

 ComboTimerHandle.Invalidate();
 SetComboCheckTimer();
}

void AABCharacterBase::ComboActionEnd(UAnimMontage* TargetMontage, bool IsProperlyEnded)
{
 ensure(CurrentCombo != 0);
 CurrentCombo = 0;
 // 콤보가 끝났으므로 움직임을 다시 허용한다.
 GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}

void AABCharacterBase::SetComboCheckTimer()
{
 int32 ComboIndex = CurrentCombo - 1;
 ensure(ComboActionData->EffectiveFrameCount.IsValidIndex(ComboIndex));

 const float AttackSpeedRate = 1.0f;
 float ComboEffectiveTime = (ComboActionData->EffectiveFrameCount[ComboIndex] / ComboActionData->FrameRate) / AttackSpeedRate;
 if (ComboEffectiveTime > 0.0f)
 {
  GetWorld()->GetTimerManager().SetTimer(ComboTimerHandle, this, &AABCharacterBase::ComboCheck, ComboEffectiveTime, false);
 }
}

void AABCharacterBase::ComboCheck()
{
 ComboTimerHandle.Invalidate();
 if (HasNextComboCommand)
 {
  UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

  CurrentCombo = FMath::Clamp(CurrentCombo + 1, 1, ComboActionData->MaxComboCount);
  FName NextSection = *FString::Printf(TEXT("%s%d"), *ComboActionData->MontageSectionNamePrefix, CurrentCombo);
  AnimInstance->Montage_JumpToSection(NextSection, ComboActionMontage);
  SetComboCheckTimer();
  HasNextComboCommand = false;
 }
}

void AABCharacterBase::AttackHitCheck()
{
 FHitResult OutHitResult;
 FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), false, this);

 const float AttackRange = 40.0f;
 const float AttackRadius = 50.0f;
 const float AttackDamage = 30.0f;
 const FVector Start = GetActorLocation() + GetActorForwardVector() * GetCapsuleComponent()->GetScaledCapsuleRadius();
 const FVector End = Start + GetActorForwardVector() * AttackRange;

 bool HitDetected = GetWorld()->SweepSingleByChannel(OutHitResult, Start, End, FQuat::Identity, CCHANNEL_ABACTION, FCollisionShape::MakeSphere(AttackRadius), Params);
 if (HitDetected)
 {
  FDamageEvent DamageEvent;
  OutHitResult.GetActor()->TakeDamage(AttackDamage, DamageEvent, GetController(), this);
 }

#if ENABLE_DRAW_DEBUG

 FVector CapsuleOrigin = Start + (End - Start) * 0.5f;
 float CapsuleHalfHeight = AttackRange * 0.5f;
 FColor DrawColor = HitDetected ? FColor::Green : FColor::Red;

 DrawDebugCapsule(GetWorld(), CapsuleOrigin, CapsuleHalfHeight, AttackRadius, FRotationMatrix::MakeFromZ(GetActorForwardVector()).ToQuat(), DrawColor, false, 5.0f);
#endif
}

float AABCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
 Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

 SetDead();

 return DamageAmount;
}

void AABCharacterBase::SetDead()
{
 GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
 PlayDeadAnimation();
 SetActorEnableCollision(false);
}

void AABCharacterBase::PlayDeadAnimation()
{
 UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
 AnimInstance->StopAllMontages(0.0f);
 AnimInstance->Montage_Play(DeadMontage, 1.0f);
}
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "ABCharacterNonPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABCharacterNonPlayer : public AABCharacterBase
{
 GENERATED_BODY()
 
public:
 AABCharacterNonPlayer();

protected:
 void SetDead() override;
};
```

```cpp
#include "ABCharacterNonPlayer.h"

AABCharacterNonPlayer::AABCharacterNonPlayer()
{
}

void AABCharacterNonPlayer::SetDead()
{
 Super::SetDead();

 FTimerHandle DeadTimerHandle;
 GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
  [&]()
  {
   Destroy();
  }
 ), DeadEventDelayTime, false);
}
```

- `DrawDebugCapsule`은 디버그 드로잉을 사용하여 캡슐을 그린다.
  - 유니티의 `Debug.DrawRay`와 유사한 기능을 제공한다.
- 죽음 몽타주는 전 방식과 동일하게 `TObjectPtr`로 선언하고, `ConstructorHelpers`를 사용하여 초기화한다. (초기값 설정 방식이 코드에 들어갈 것 인지, 블루프린터로 할 것인지는 선택)
- `TakeDamage`는 기본적으로 제공되는 액터의 데미지를 받는 함수이다. 이를 오버라이딩하여 데미지를 받았을 때의 처리를 구현한다. (추가적)
- `SetDead`는 캐릭터의 움직임을 제한하고, 콜라이더를 비활성화하고, 죽음 몽타주를 재생한다.
  - 마찬가지로 몽타주 재생도 재생중이던 애니메이션을 멈추고 재생한다.
- `GetWorld()->GetTimerManager().SetTimer`
  - 시간과 관련된 액션/이벤트를 걸고 싶다면 사용하라

## 정리

- 공격 판정 구현을 위한 물리 트레이스 채널 및 프로필 설정
- 디버그 드로잉 기능을 활용한 충돌 디버깅
- 대미지 프레임웍을 사용한 대미지 전달
- 델리게이트와 람다함수의 간편한 활용
