# 3강: 캐릭터 컨트롤 설정

- 강의 목표
  - 캐릭터 컨트롤을 위한 각종 설정 옵션의 이해
  - 데이터 에셋을 활용한 설정값의 체계적인 관리
  - 입력매핑컨텍스트 활용법의 이해
- 강의 과제
  - 자신의 게임에서 사용할 시점에 대해 정리하시오. ( 1인칭 또는 3인칭 )
  - 자신의 게임에서 조작할 캐릭터의 움직임에 대해 정리하시오.
  - 이를 구현하기 위해 어떤 값을 설정할지 정리하고 이 값들을 애셋으로 관리해보시오

## 캐릭터 컨트롤 요소

### 캐릭터 컨트롤

일반적으로 컨트롤러와 폰, 카메라, 스프링암, 캐릭터 무브먼트의 다섯 가지 요소를 사용해 설정한다.

- 컨트롤러: 사용자의 의지(목표 지점)을 지정할 때 사용. `ControlRotation`속성
- 폰: 폰의 트랜스폼을 지정
- 카메라: 화면 구도를 설정하기 위해 사용, 주로 1인칭 에서 사용
- 스프링 암: 화면 구도를 설정하기 위해 사용. 주로 3인칭 시점에서 사용
- 캐릭터 무브먼트: 캐릭터의 이동과 회전을 조정하는 용도로 사용

`DesiredRotation`은 캐릭터가 원하는 방향을 나타내고 `Rotation`은 현재 상태를 나타낸다. 부드러움 움직임을 위해 선형보간과 같이 각속도로 회전할 수 있도록 구현한다. (일반적으로)

### 폰 이동 함수

전 강의에서 사용한 `Move`함수와 `Look`함수를 통해 직접 캐릭터가 어떻게 이동하는지 알아보자.

- Look 함수: 마우스 입력으로부터 컨트롤러의 컨트롤 회전을 설정
- Move 함수: 컨트롤러의 컨트롤 회전으로부터 Yaw값을 참고해 이동 방향을 설정
- 콘솔 커맨드 창으로부터 Control Rotation 값을 확인할 수 있다. (`~`로 사용)
  - `DisplayAll PlayerController ControlRotation`

### 폰의 컨트롤 옵션

블루프린트로 접근하여 `Pawn`의 속성을 보면 `Use Controller Ratation`항목이 있는데 `Yaw`, `Pitch`, `Roll`의 값을 컨트롤러에 지정된 Control Rotation값에 폰의 Rotation을 맞출 것인지 설정하는 항목이다.

2강에서 보면 코드에서 각 설정들에 대해서 `false`를 한 것을 볼 수 있다. (마우스와 키보드의 입력으로 캐릭터를 제어하기 위해)

```cpp
bUseControllerRotationPitch = false;
bUseControllerRotationYaw = false;
bUseControllerRotationRoll = false;
```

*깨알이지만, Boolean이라 b접두사를 사용한 모습..*

해당 값을 `true`하고 실행해보면 캐릭터가 마우스 방향으로 이동은 하지만, 캐릭터 매쉬자체의 회전은 없어진다. 매우 어색한 느낌

### 스프링암의 컨트롤 옵션

마찬가지로 실제 값을 보고 싶다면 블루프린트로 접근하여 값을 확인할 수 있다. 마찬가지로 이 값을 블루프린트에서 볼 수 있다면 코드에서도 설정할 수 있다는 뜻이다.

- Use Pawn Control Rotation
  - `Control Rotation`값을 사용해서 `Spring Arm`의 회전을 동기화하도록 설정할 수 있다. 이 값이 체크가 되어 있어서 마우스를 움직을 때, 스프링 암 또한 같이 회전한 것을 알 수 있다.
- Do Collision Test
  - 부모 컴포넌트의 회전을 그대로 따를 것인가?
  - 중간에 장애물이 있으면 카메라를 앞으로 당길 것인가?
  
*3인칭 카메라의 카메라 앞으로 당기기 기능이 언리얼에서는 주어진다니.. 유니티에선 매우 힘들게 구현해봤던 기억이..*

### 카메라의 컨트롤 옵션

카메라의 컨트롤 옵션으로 동일하게 폰의 컨트롤 회전을 사용할 것인가를 설정할 수 있다. (1인칭에 주로 사용)

- Use Pawn Control Roation

### 캐릭터 무브먼트의 이동 옵션

다양한 무브먼트 모드들을 제공해준다. (Walking, Falling, Swimming, Flying, Custom..)

각 모드에 관한 속성은 코드에서 다룬 `MaxWalkSpeed`등으로 조절할 수 있다.

### 캐릭터 무브먼트의 회전 옵션

- `Rotation Rate`를 통해 회전 속도를 조절할 수 있다. (Yaw, Pitch, Roll)
- `Use Controller Desired Rotation` 컨트롤 회전을 목표 회전(의지)로 삼고 지정한 속도로 돌리기
- `Orient Rotation to Movement` 이동 방향으로 회전 일치시키기
- 폰의 회전 옵션과 충돌이 나지 않도록 주의

## 데이터 에셋

위에서 다룬 데이터들은 매우 분산되어 있고, 이를 관리하기 위해 데이터 에셋을 사용한다.

데이터 에셋이란, `UdataAsset`클래스를 상속받은 언리얼 오브젝트 클래스이다. 에디터에서 쉽게 에셋 형태로 데이터를 관리할 수 있으며, 캐릭터 컨트롤에 관련된 주요 옵션을 모아 에셋으로 관리한다.

*Unity의 ScriptableObject와 비슷한 개념인 것 같다.*

### 실습

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABCharacterControlData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterControlData : public UPrimaryDataAsset
{
 GENERATED_BODY()

public:
 UABCharacterControlData();

 // 캐릭터 컨트롤러에서 사용하는 회전 Yaw값
 UPROPERTY(EditAnywhere, Category = Pawn)
 uint32 bUseControllerRotationYaw : 1;

 // Movement에서 사용되는 변수들
 UPROPERTY(EditAnywhere, Category = CharacterMovement)
 uint32 bOrientRotationToMovement : 1;

 UPROPERTY(EditAnywhere, Category = CharacterMovement)
 uint32 bUseControllerDesiredRotation : 1;

 UPROPERTY(EditAnywhere, Category = CharacterMovement)
 FRotator RotationRate;

 // 입력 매핑 컨텍스트를 담을 변수
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
 TObjectPtr<class UInputMappingContext> InputMappingContext;

 // 스프링암에 들어갈 변수들
 UPROPERTY(EditAnywhere, Category = SpringArm)
 float TargetArmLength;

 UPROPERTY(EditAnywhere, Category = SpringArm)
 FRotator RelativeRotation;

 UPROPERTY(EditAnywhere, Category = SpringArm)
 uint32 bUsePawnControlRotation : 1;

 UPROPERTY(EditAnywhere, Category = SpringArm)
 uint32 bInheritPitch : 1;

 UPROPERTY(EditAnywhere, Category = SpringArm)
 uint32 bInheritYaw : 1;

 UPROPERTY(EditAnywhere, Category = SpringArm)
 uint32 bInheritRoll : 1;

 UPROPERTY(EditAnywhere, Category = SpringArm)
 uint32 bDoCollisionTest : 1;
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterControlData.h"

UABCharacterControlData::UABCharacterControlData()
{
 TargetArmLength = 400.0f;
}
```

- `UPrimaryDataAsset`을 상속받은 클래스를 생성함으로써 데이터 에셋을 만들 수 있다.
- 생성자를 통해 기본값을 설정할 수 있다. 현재 CPP파일에서 설정한 값은 `TargetArmLength`을 400.0f로 설정한 것이다.
- `UPROPERTY`매크로를 통해 에디터에서 변수를 수정할 수 있도록 한다.
- 즉, 데이터와 로직을 분리하여 관리할 수 있다.

### 데이터 에셋의 관리

현재 두 가지 데이터 에셋을 만들고 이를 통해 컨트롤 모드를 자율적으로 만들 수 있다. (3인칭 숄더뷰, 3인칭 쿼터뷰)
런타임에 데이터 에셋을 변경이 가능하다. (ENUM을 통해 상태를 관리.)

### 데이터 에셋의 구성과 적용

- 각 섹션별로 데이터를 저장한다.
  - `Pawn` 카테고리
  - 캐릭터 무브먼트 카테고리
  - 입력 매핑 컨텍스트 카테고리
  - 스프링암 카테고리
- `Pawn`과 캐릭터 무브먼트 데이터는 `CharacterBase`에서 설정
- 입력과 스프링암 데이터는 `CharacterPlayer`에서 설정

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
    ... // 생략

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
```

- `AABCharacterBase` 플레이어 캐릭터가 상속받을 클래스에선 Pawn과 CharacterMovement의 데이터를 설정한다.
- `SetCharacterControlData`라는 함수를 통해 데이터를 받아와서 각 컴포넌트에 접근하여 속성값을 설정한다.
- 생성자를 통해 `TMap`이라는 딕셔너리에 ENUM값을 키로 하여 각 데이터 에셋을 저장한다.
  - 마찬가지로 접근해야 하기에 `UPROPERTY`매크로를 사용
  - ENUM은 uint8로 설정하였다.
- `ConstructorHelpers::FObjectFinder`를 통해 실제 데이터 에셋에 접근한다. (오브젝트이기에 FObjectFinder를 사용)

### 뷰의 전환

컨트롤을 변경할 때 서로 다른 입력 매핑 콘텍스트가 지정되어야 한다. 예를 들어 숄더뷰의 경우엔 마우스를 통해 회전하고 이동하지만, 쿼터뷰의 경우 마우스를 사용하지 않기에 다른 입력 매핑 콘텍스트를 사용해야 한다. (입력 액션을 통해 변경 `V`)

가장 먼저 추가로 사용할 액션과 입력 매핑 콘텍스트를 만들어야 한다. 입력 매핑 콘텍스트는 `Quater`와 `Shoulder`로 나누어서 만들고 각 입력 매핑 콘텍스트에 액션을 추가한다. (에디터로 진행) 추가적으로 뷰를 전환하기 위한 액션을 추가한다.

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "InputActionValue.h"
#include "ABCharacterPlayer.generated.h"

/**
 * 
 */
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
 
 void ShoulderMove(const FInputActionValue& Value);
 void ShoulderLook(const FInputActionValue& Value);

 void QuaterMove(const FInputActionValue& Value);

 ECharacterControlType CurrentCharacterControlType;
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
```

- `ChangeCharacterControl` 뷰를 전환하는 액션에 매핑될 함수
- `SetCharacterControl` 뷰를 전환하는 함수
  - `CharacterControlManager`에서 해당하는 데이터를 가져와서 설정한다.
  - EnhancedInput 시스템에서 실제로 Input Mapping 컨텍스트를 운영하는 Subsystem을 가져온다.
  - 이전에 설정된 모든 매핑을 지우고 새로운 컨텍스트를 추가한다.
  - `UInputMappingContext`를 통해 새로운 컨텍스트를 추가한다.
- `ECharacterControlType`를 통해 현재 상태를 저장한다.
- `Subsystem->AddMappingContext(NewMappingContext, 0);`
  - 우선순위가 있는 것 같은데, 그렇다면 초기화에 이 작업을 컨택스트 만큼 수행하고 변경을 우선순위만 바꾸면 되지 않을까?

## 정리

- 컨트롤러에 설정된 `ControlRoatation`속성의 이해
- 캐릭터의 움직임과 회전을 설정하는 다양한 구성 요소와 설정 값의 이해
- 입력 매핑 콘텍스트를 활용한 뷰의 전환 구현
