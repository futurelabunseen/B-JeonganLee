# 5강: 캐릭터 콤보 액션

- 강의 목표
  - 애니메이션 몽타주 시스템의 활용 방법
  - 데이터 에셋과 델리게이트를 활용한 콤보 공격의 구현
- 강의 과제
  - 게임에서 애니메이션 블루프린트의 상태와 구별되는 애니메이션 몽타주를 어떻게 활용하면 좋을지 정리해보시오

## 애니메이션 몽타주

몽타주(Montage)란 이미지 일부를 잘라내 한 화면에서 합성하는 회화 기법이다. 언리얼 엔진에선 애니메이션 클립을 잘라내고 합성한 후 이를 재생하는 애니메이션 기술이다. 애니메이션 클립을 모아둔 다수의 섹션으로 구성되어 있으며 섹션끼리의 연동도 가능하다. (스크립트를 통해 원하는 섹션으로 건너뛸 수 있다.)

### 실습

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "InputActionValue.h"
#include "ABCharacterPlayer.generated.h"

UCLASS()
class ARENABATTLE_API AABCharacterPlayer : public AABCharacterBase
{
 GENERATED_BODY()
public:
 AABCharacterPlayer();
 
protected:
 virtual void BeginPlay() override;

public:
 virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Character Control Setion
protected:
 void ChangeCharacterControl();
 void SetCharacterControl(ECharacterControlType NewCharacterControlType);
 virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData) override;
 
// Camera
protected:
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class USpringArmComponent> CameraBoom;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UCameraComponent> FollowCamera;
 
// Input
protected:
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> JumpAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> ChangeControlAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> ShoulderMoveAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> ShoulderLookAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> QuaterMoveAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> AttackAction;
 
 void ShoulderMove(const FInputActionValue& Value);
 void ShoulderLook(const FInputActionValue& Value);

 void QuaterMove(const FInputActionValue& Value);

 ECharacterControlType CurrentCharacterControlType;

 void Attack();
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/ABCharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ABCharacterControlData.h"

AABCharacterPlayer::AABCharacterPlayer()
{
 // Camera
 CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
 CameraBoom->SetupAttachment(RootComponent);
 CameraBoom->TargetArmLength = 400.0f;
 CameraBoom->bUsePawnControlRotation = true;

 FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
 FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
 FollowCamera->bUsePawnControlRotation = false;

 // Input
 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Jump.IA_Jump'"));
 if (nullptr != InputActionJumpRef.Object)
 {
  JumpAction = InputActionJumpRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputChangeActionControlRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ChangeControl.IA_ChangeControl'"));
 if (nullptr != InputChangeActionControlRef.Object)
 {
  ChangeControlAction = InputChangeActionControlRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ShoulderMove.IA_ShoulderMove'"));
 if (nullptr != InputActionShoulderMoveRef.Object)
 {
  ShoulderMoveAction = InputActionShoulderMoveRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_ShoulderLook.IA_ShoulderLook'"));
 if (nullptr != InputActionShoulderLookRef.Object)
 {
  ShoulderLookAction = InputActionShoulderLookRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionQuaterMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_QuaterMove.IA_QuaterMove'"));
 if (nullptr != InputActionQuaterMoveRef.Object)
 {
  QuaterMoveAction = InputActionQuaterMoveRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionAttackRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Attack.IA_Attack'"));
 if (nullptr != InputActionAttackRef.Object)
 {
  AttackAction = InputActionAttackRef.Object;
 }

 // 현재 상태 기본값으로 초기화 (Quater로 시작)
 CurrentCharacterControlType = ECharacterControlType::Quater;
}

void AABCharacterPlayer::BeginPlay()
{
 Super::BeginPlay();

 SetCharacterControl(CurrentCharacterControlType);
}

void AABCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
 Super::SetupPlayerInputComponent(PlayerInputComponent);

 UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);// 반드시 EnhancedInputComponent로 캐스팅해야 합니다.

 EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
 EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
 EnhancedInputComponent->BindAction(ShoulderMoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ShoulderMove);
 EnhancedInputComponent->BindAction(ShoulderLookAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ShoulderLook);
 EnhancedInputComponent->BindAction(QuaterMoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::QuaterMove);
 EnhancedInputComponent->BindAction(ChangeControlAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::ChangeCharacterControl);
 EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Attack);
 // 각 키 입력에 대한 액션을 바인딩합니다.
 // ex 점프 액션의 Triggered 이벤트에 Jump 함수를 바인딩합니다. Completed 이벤트에 StopJumping 함수를 바인딩합니다.
 // (점프는 `ACharacter` 클래스에 정의된 함수를 매핑하지만, Move와 Look는 `AABCharacterPlayer` 클래스로 연결되기에 직접 구현
}

void AABCharacterPlayer::ChangeCharacterControl()
{
 if (CurrentCharacterControlType == ECharacterControlType::Quater)
 {
  SetCharacterControl(ECharacterControlType::Shoulder);
 }
 else if (CurrentCharacterControlType == ECharacterControlType::Shoulder)
 {
  SetCharacterControl(ECharacterControlType::Quater);
 }
}

void AABCharacterPlayer::SetCharacterControl(ECharacterControlType NewCharacterControlType)
{
 // 상위 클래스에 정의된 딕셔너리에서 key값을 넣어서 컨텍스트를 가져온다.
 UABCharacterControlData* NewCharacterControl = CharacterControlManager[NewCharacterControlType];
 check(NewCharacterControl); // nullptr이 아닌지 체크 (어서션)

 SetCharacterControlData(NewCharacterControl); // 상위 클래스에 정의된 함수를 호출하여 캐릭터 컨트롤 데이터를 설정한다.
 // super을 통해 base에 pawn과 character movement를 설정하고
 // 현재 이 클래스에선 플레이어 입력과 스프링암 데이터를 설정한다.

 APlayerController* PlayerController = CastChecked<APlayerController>(GetController()); // 플레이어 컨트롤러를 가져온다. 반드시 가져와야 하는 경우 CastChecked를 사용한다.
 if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
 {
  // EnhancedInput 시스템에서 실제로 Input Mapping 컨텍스트를 운영하는 Subsystem을 가져온다.
  // 그리고 이전에 설정된 모든 매핑을 지우고 새로운 컨텍스트를 추가한다.
  Subsystem->ClearAllMappings();
  UInputMappingContext* NewMappingContext = NewCharacterControl->InputMappingContext;
  if (NewMappingContext)
  {
   Subsystem->AddMappingContext(NewMappingContext, 0);
   // 우선순위가 있는 것 같은데, 그렇다면 초기화에 이 작업을 컨택스트 만큼 수행하고 변경을 우선순위만 바꾸면 되지 않을까?
  }
 }

 CurrentCharacterControlType = NewCharacterControlType;
}

void AABCharacterPlayer::SetCharacterControlData(const UABCharacterControlData* CharacterControlData)
{
 Super::SetCharacterControlData(CharacterControlData); // 전에 구현한 Base의 클래스 함수를 호출 (필수)
 
 CameraBoom->TargetArmLength = CharacterControlData->TargetArmLength;
 CameraBoom->SetRelativeRotation(CharacterControlData->RelativeRotation);
 CameraBoom->bUsePawnControlRotation = CharacterControlData->bUsePawnControlRotation;
 CameraBoom->bInheritPitch = CharacterControlData->bInheritPitch;
 CameraBoom->bInheritYaw = CharacterControlData->bInheritYaw;
 CameraBoom->bInheritRoll = CharacterControlData->bInheritRoll;
 CameraBoom->bDoCollisionTest = CharacterControlData->bDoCollisionTest;
}

void AABCharacterPlayer::ShoulderMove(const FInputActionValue& Value)
{
 FVector2D MovementVector = Value.Get<FVector2D>();

 const FRotator Rotation = Controller->GetControlRotation();
 const FRotator YawRotation(0, Rotation.Yaw, 0);

 const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
 const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

 AddMovementInput(ForwardDirection, MovementVector.X);
 AddMovementInput(RightDirection, MovementVector.Y);
}

void AABCharacterPlayer::ShoulderLook(const FInputActionValue& Value)
{
 FVector2D LookAxisVector = Value.Get<FVector2D>();

 AddControllerYawInput(LookAxisVector.X);
 AddControllerPitchInput(LookAxisVector.Y);
}

void AABCharacterPlayer::QuaterMove(const FInputActionValue& Value)
{
 FVector2D MovementVector = Value.Get<FVector2D>();

 float InputSizeSquared = MovementVector.SquaredLength();
 float MovementVectorSize = 1.0f;
 float MovementVectorSizeSquared = MovementVector.SquaredLength();
 if (MovementVectorSizeSquared > 1.0f)
 {
  MovementVector.Normalize();
  MovementVectorSizeSquared = 1.0f;
 }
 else
 {
  MovementVectorSize = FMath::Sqrt(MovementVectorSizeSquared);
 }

 FVector MoveDirection = FVector(MovementVector.X, MovementVector.Y, 0.0f);
 GetController()->SetControlRotation(FRotationMatrix::MakeFromX(MoveDirection).Rotator());
 AddMovementInput(MoveDirection, MovementVectorSize);
}

void AABCharacterPlayer::Attack()
{
 ProcessComboCommand();
}
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
 Shoulder,
 Quater
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter
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

 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
 TObjectPtr<class UAnimMontage> ComboActionMontage;

 void ProcessComboCommand();
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterControlData.h"

// Sets default values
AABCharacterBase::AABCharacterBase()
{
 // Pawn
 bUseControllerRotationPitch = false;
 bUseControllerRotationYaw = false;
 bUseControllerRotationRoll = false;

 // Capsule
 GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
 GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

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
 GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

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
 UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
 AnimInstance->Montage_Play(ComboActionMontage);
}
```

- 이동 액션을 `EnhancedInputComponent`에 바인딩한 것과 같이 `Attack` 액션을 바인딩한다
- 다른 캐릭터도 사용할 것이라면 `ABCharacterBase`에 `ProcessComboCommand` 함수를 정의한다
- `ComboActionMontage`를 코드에서 직접 참조하여 바인딩이 아닌 블루프린트에서 설정할 수 있도록 한다 (UPROPERTY로 선언, WriteAnywhere로 설정)
- `GetMesh()->GetAnimInstance()->Montage_Play(ComboActionMontage)`를 통해 몽타주를 실행한다. 캐싱도 가능

### 콤보 공격의 기획

몽타주에 있는 섹션을 활용하여 콤보공격을 구현한다.

- 콤보 정보를 저장한 데이터 에셋을 생성
- 각 콤보마다 입력을 테스트하는 프레임을 지정
- 테스트 프레임 전에 입력이 들어오면 다음 몽타주 섹션으로 이어서 재생
- 테스트 프레임 입력이 늦으면 해당 섹션을 종료하고 마저 플레이하고 종료

### 실습

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABComboActionData.generated.h"

UCLASS()
class ARENABATTLE_API UABComboActionData : public UPrimaryDataAsset
{
 GENERATED_BODY()

public:
 UABComboActionData();

 UPROPERTY(EditAnywhere, Category = Name)
 FString MontageSectionNamePrefix;

 UPROPERTY(EditAnywhere, Category = Name)
 uint8 MaxComboCount;

 UPROPERTY(EditAnywhere, Category = Name)
 float FrameRate;

 UPROPERTY(EditAnywhere, Category = ComboData)
 TArray<float> EffectiveFrameCount;
};
```

```cpp
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
 Shoulder,
 Quater
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter
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
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterControlData.h"
#include "ABComboActionData.h"

// Sets default values
AABCharacterBase::AABCharacterBase()
{
 // Pawn
 bUseControllerRotationPitch = false;
 bUseControllerRotationYaw = false;
 bUseControllerRotationRoll = false;

 // Capsule
 GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
 GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

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
 GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

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
```

- `UABComboActionData`라는 데이터 에셋을 활용하여 각 콤보의 전이 조건과 콤보에 사용할 변수들을 설정한다
- `ComboTimerHandle` 각 콤보에서 전환될 타이머를 직접 월드 타이머에 델리게이트로 등록한다
- 콤보의 전이 로직이나 각 스테이터를 다루는 내용에 집중하기 보다 언리얼에서 데이터 에셋이나 몽타주를 어떻게 활용하는가에 집중할 것

## 정리

- 애니메이션 몽타주 활용 방법의 이해
- 데이터 에셋을 활용한 콤보 로직의 구현
- 언리얼 델리게이트를 사용한 이벤트 콜백의 구현
