# 2강: 캐릭터와 입력 시스템

- 강의 목표
  - 액터와 컴포넌트 개념의 이해
  - 블루프린트로 확장 가능한 프로퍼티 설계
  - 언리얼 엔진의 폰과 캐릭터 시스템의 이해
  - 언리얼 엔진 5이 제공하는 향상된 입력 시스템의 활용
- 강의 과제
  - 자신의 게임 내에서 사용할 입력에 대해 정리하시오.
  - 이러한 입력 처리를 어디서 구현할지 정리하시오. ( PlayerController, Character )

## 액터와 컴포넌트

월드에 속한 콘텐츠의 기본 단위를 **액터**라고 한다. 액터는 **트랜스폼**을 가지며, 월드로부터 **틱과 시간 서비스**를 제공받는다. 이는 논리적개념일 뿐 컴포넌트를 감싸는 **포장 박스**에 불과하다. 실질적인 구현은 컴포넌트를 통해서 진행하고 **대부분 다수의 컴포넌트**를 가지고 있다. 다수의 컴포넌트를 대표하는 컴포넌트를 **루트 컴포넌트**라고 한다. 액터는 루트 컴포넌트를 기준으로 트랜스폼을 가지며 트랜스폼은 액터의 트랜스폼을 의미한다.

### 블루프린터로 액터 제작

- `Add` 버튼을 눌러서 블루프린트 액터 클래스를 선택
- 블루플린트 제작 에디터로 이동, 위에서 말한 루트 컴포넌트는 더미로 생성되어 있다.
- Static Mesh Component를 추가하고 루트 컴포넌트로 설정(드래그 드롭으로 변경)
- 계층 구조를 가지기에 아래로 추가된 컴포넌트는 상위 컴포넌트의 자식이 된다. (상대적 트랜스폼)

### C++액터에서 컴포넌트 제작

- 컴포넌트는 언리얼 오브젝트이므로 `UPROPERTY` 매크로를 설정해주고 `TObjectPtr`라고하는 탬플릿 클래스를 사용해 선언해야 한다.
  - 언리얼 5부터 적용된 기능으로 헤더에 언리얼 오브젝트를 선언할 때 일반 포인터에서 `TObjectPtr`로 변경되었다.
- 컴포넌트 등록
  - **CDO에서 생성한 컴포넌트는 자동으로 월드**에 등록된다.
  - 하지만 NewObject로 생성한 컴포넌트는 수동으로 월드에 등록해야 한다. (RegisterComponent를 이용)
  - **등록된 컴포넌트는 월드의 기능**을 사용할 수 있으며, 물리와 렌더링 처리에 합류한다.
- 컴포넌트의 확장 설계
  - 에디어 편집 및 블루프린트로의 승계를 위한 설정
  - `UPROPERTY`에 지정자 (Specifier)를 설정할 수 있다.
- 컴포넌트 지정자
  - `Visible`: 에디터에서 보이게 함(객체 타입)
  - `Edit`: 에디터에서 보이게 함 (값 타입)
  - `AnyWhere`, `DefaultsOnly`, `InstanceOnly`: 에디터에서 편집 가능 영역 (보통 `AnyWhere`를 사용)
  - `BlueprintReadOnly`, `BlueprintReadWrite`: 블루프린트에서 접근 가능 영역 (읽기 전용, 읽기 쓰기)
  - `Category`: 에디터에서 보여지는 카테고리 이름

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AB_Fountain.generated.h"

UCLASS()
class ARENABATTLE_API AAB_Fountain : public AActor
{
 GENERATED_BODY()
 
public: 
 // Sets default values for this actor's properties
 AAB_Fountain();

protected:
 // Called when the game starts or when spawned
 virtual void BeginPlay() override;

public: 
 // Called every frame
 virtual void Tick(float DeltaTime) override;

 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
 TObjectPtr<class UStaticMeshComponent> Body;

 UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
 TObjectPtr<class UStaticMeshComponent> Water;
};
```

아래 `Body`와 `Water`는 객체타입을 에디터에서 보이게하고, 편집 가능영역을 말해준다. 또한, 블루프린트에서 읽기 쓰기가 가능하다. 카테고리는 `Mesh`로 설정되어 있다.

`TObjectPtr`라는 탬플릿 클래스를 사용

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Prop/AB_Fountain.h"
#include "Components//StaticMeshComponent.h"

// Sets default values
AAB_Fountain::AAB_Fountain()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
 PrimaryActorTick.bCanEverTick = true;

 Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
 Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Water"));

 RootComponent = Body;
 Water->SetupAttachment(Body);
 Water->SetRelativeLocation(FVector(0.0f, 0.0f, 132.0f));

 static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01'"));
 if (BodyMeshRef.Object)
 {
  Body->SetStaticMesh(BodyMeshRef.Object);
 }

 static ConstructorHelpers::FObjectFinder<UStaticMesh> WaterMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Plains_Fountain_02.SM_Plains_Fountain_02'"));
 if (WaterMeshRef.Object)
 {
  Water->SetStaticMesh(WaterMeshRef.Object);
 }
}

// Called when the game starts or when spawned
void AAB_Fountain::BeginPlay()
{
 Super::BeginPlay();
 
}

// Called every frame
void AAB_Fountain::Tick(float DeltaTime)
{
 Super::Tick(DeltaTime);

}
```

`CreateDefaultSubobject`를 통해 컴포넌트를 생성하고 초기화한다. (탬플릿 함수로 예제에서는 `UStaticMeshComponent`를 생성하고 있다.)

`RootComponent`는 루트 컴포넌트를 설정하고 그 하위인 `Water`은 `SetupAttachment`를 통해 `Body`에 붙여준다. `SetRelativeLocation`를 통해 상대적인 위치를 설정해준다.

`ConstructorHelpers`를 통해 에디터에서 사용할 메쉬를 찾아서 설정해준다.

`ConstructorHelpers`는 `FObjectFinder`를 통해 찾아서 설정해주는데, `UStaticMesh`를 찾아서 설정해주고 있다. (Resource Load의 기능)

*코드에 참조 주소값이 리터럴 값으로 들어가 있어서 위험해 보인다.*

## 캐릭터의 제작

### 폰의 기능과 설계

폰이란, **액터를 상속받은 특별한 클래스**이며, 플레이어가 빙**의해 입출력을 처리**하도록 설계되어 있다. 기능으론 길찾기를 사용할 수 있으며, 일반적으로 세 가지 주요 컴포넌트로 구성된다.

- 기믹과 상호작용을 담당하는 충돌 컴포넌트 컴포넌트(루트컴포넌트)
- 시각적인 비주얼을 담당하는 메시 컴포넌트
- 움직일을 담당하는 컴포넌트

컴포넌트 중에서 트랜스폼이 없이 기능만 제공하는 컴포넌트를 액터컴포넌트라고 한다.

### 캐릭터의 기본 구조

캐릭터는 인간형 폰을 구성하도록 **언리얼이 제공하는 전문 폰 클래스**를 의미한다. 캐릭터는 세 가지 주요 컴포넌트로 구성되어 있다.

- 기믹과 상호작용을 담당하는 캡슐 컴포넌트 (루트 컴포넌트)
- 애니메이션 캐릭터를 표현하는 스켈레탈 메시 컴포넌트
- 캐릭터의 움직임을 담당하는 캐릭터 무브먼트 컴포넌트

```cpp
private:
 /** The main skeletal mesh associated with this Character (optional sub-object). */
 UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
 TObjectPtr<USkeletalMeshComponent> Mesh;
```

실제로 `Character` 클래스에서 위에서 C++로 커스텀한 컴포넌트와 같은 형태로 선언되어 있다.

### C++ 캐릭터 생성 실습

```cpp
UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter
{
 GENERATED_BODY()

public:
 // Sets default values for this character's properties
 AABCharacterBase();

};
```

생성자를 통해서만 초기화하기 위해 기본적인 코드는 삭제하고 진행한다. `ACharacter`를 상속받았기에 해당 클래스에 접근하여 데이터를 세팅한다.

```cpp
#include "Character/ABCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

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

 static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'"));
 if (CharacterMeshRef.Object)
 {
  GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
 }

 static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef(TEXT("/Game/Characters/Mannequins/Animations/ABP_Quinn.ABP_Quinn_C"));
 if (AnimInstanceClassRef.Class)
 {
  GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
 }
}
```

너무 깊게 들어가지말고, 쉽게 `ACharacter`에 있는 멤버변수에 접근하여 세팅해주는 코드이다. 순서대로 앞서 말한 구조를 따라간다.

- 캐릭터는 폰의 전문 클래스로 (인간형) Pawn의 아마 회전 방향을 설정하는 부분을 flase로 설정한 것 같다.
- 충돌 컴포넌트인 캡슐은 기믹과 상호작용을 담당하며 여기선 크기와 충돌 프로필을 설정해주었다.
- 움직임을 담당하는 컴포넌트는 캐릭터 무브먼트 컴포넌트로 여기선 회전속도, 점프속도, 공중제어, 최대 이동속도, 최소 이동속도, 브레이킹 디셀레레이션을 설정해주었다. 실제로 참조에 접근해보면 이외에도 다양한 커스텀이 가능하다.
- 시각적인 비주얼을 담당하는 메시 컴포넌트로 여기선 상대적인 위치와 회전을 설정해주었다. 그리고 애니메이션 모드와 충돌 프로필을 설정해주었다. 위치와 회전은 전 분수대의 메시 설정과 동일하다.
- 이후 실제로 리소스를 찾아서 설정해주었다. `ConstructorHelpers`
- 애니메이션은 클래스로 넣어줘야 하기에 `FClassFinder`를 통해 찾아서 설정해주었다.

### 입력 시스템 개요

- [Enhanced Input System](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/enhanced-input-in-unreal-engine?application_version=5.1)
  - 언리얼 엔진 5에서 새롭게 제공되는 입력 시스템
  - 플랫폼에 상관없이 일관된 입력 처리를 제공
  - 플랫폼별 입력 처리를 추상화하여 제공
  - 블루프린트와 C++에서 동일한 방식으로 사용 가능
  - 플러그인으로 제공되어 기존 입력 시스템과 호환 가능

플레이어의 입력은 컨트롤러를 통해 폰으로 전달됨 (우선순위를 컨트롤러가 가진다.) 여기서 입력을 컨트롤러가 처리할 수도, 폰이 처리할 수도 있는데, 일반적으로는 폰이 처리하도록 설정

*다양한 입력에 대해서 컨트롤러가 개개인의 폰에 대해서 처리하다보면 결합도가 높아지고 의존성이 방대해짐.*

이번 강의에선 향상된 입력 시스템을 사용한다. 이는 사용자의 입력 설정 변경에 유연하게 대처할 수 있도록 구조를 재수립한다. 사용자의 입력 처리를 네 단계로 세분화하고 각 설정을 독립적인 에셋으로 대체한다. (원래는 유연한 입력을 대체하기 힘듬)

#### 향상된 입력시스템 동작 구성

사용자가 기본적으로 입력을 진행하면 **입력 매핑 컨텍스트**라고 하는 것을 통해서 입력과 연결이 되고, 입력에 따라 액션이 수행된다. 이 액션에서 입력에 대해서 재가공할 것인지 결정하고 트리거를 활성화한다. 이후 게임로직에 맞게 수행된다.

- 사용자의 입력 데이터를 최종 함수에 매핑하는 과정을 체계적으로 구성
- 플랫폼에 따른 다양한 입력 장치의 설정
  - 게임 패드용, 키보드 용
- 입력 값의 변경
  - AD/WS 입력값을 Y축과 X축으로 변경 등
- 이벤트 발생 조건의 상세 설정
  - 일반 버튼인가? 축 이동인가? 등등

게임로직의 부담을 줄여주고 (비즈니스 로직과 입력 로직을 분리) 유연한 입력 처리를 가능하게 한다.

*유니티의 New Input System과 비슷한 구조로 보인다.*

### 입력 시스템 실습

```cpp
UCLASS()
class ARENABATTLE_API AABCharacterPlayer : public AABCharacterBase
{
 GENERATED_BODY()
public:
 AABCharacterPlayer();
 
protected:
 virtual void BeginPlay() override; // 입력 시스템 초기화를 위해 (캐스팅)

public:
 virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
  // 각 키에 대한 액션 바인딩 함수

// Input
protected:
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputMappingContext> DefaultMappingContext;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> JumpAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> MoveAction;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UInputAction> LookAction;

 void Move(const FInputActionValue& Value);
 void Look(const FInputActionValue& Value);

  // 각 액션에 대해서 UPROPERTY로 선언하여 CPP에서 접근할 수 있도록 설정 (액션과 키 바인딩을 위해)
  // 각 액션에 할당할 함수도 선언 (Enhaned Input System에서는 매개변수를 통해 입력값을 받아올 수 있다.)

// Camera
protected:
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class USpringArmComponent> CameraBoom;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UCameraComponent> FollowCamera;
};
```

```cpp
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
 static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextRef(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/ArenaBattle/Input/IMC_Default.IMC_Default'"));
 if (nullptr != InputMappingContextRef.Object)
 {
  DefaultMappingContext = InputMappingContextRef.Object;
 }
 else
 {
  UE_LOG(LogTemp, Error, TEXT("Failed to find IMC_Default"));
 
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Move.IA_Move'"));
 if (nullptr != InputActionMoveRef.Object)
 {
  MoveAction = InputActionMoveRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Jump.IA_Jump'"));
 if (nullptr != InputActionJumpRef.Object)
 {
  JumpAction = InputActionJumpRef.Object;
 }

 static ConstructorHelpers::FObjectFinder<UInputAction> InputActionLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Look.IA_Look'"));
 if (nullptr != InputActionLookRef.Object)
 {
  LookAction = InputActionLookRef.Object;
 }
}

void AABCharacterPlayer::BeginPlay()
{
 Super::BeginPlay();

 // 컨트롤러가 플레이어 컨트롤러 대상으로 설계된 전용 캐릭터 클래스이기에 castChecked를 사용하여 캐스팅합니다.
 APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
 if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
 {
  Subsystem->AddMappingContext(DefaultMappingContext, 0);
  //Subsystem->RemoveMappingContext(DefaultMappingContext); // 런타임에 매핑 컨텍스트를 제거할 수도 있습니다.
 }

}

void AABCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
 Super::SetupPlayerInputComponent(PlayerInputComponent);

 UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);// 반드시 EnhancedInputComponent로 캐스팅해야 합니다.

 EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
 EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
 EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Move);
 EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Look);
 // 각 키 입력에 대한 액션을 바인딩합니다.
 // ex 점프 액션의 Triggered 이벤트에 Jump 함수를 바인딩합니다. Completed 이벤트에 StopJumping 함수를 바인딩합니다.
 // (점프는 `ACharacter` 클래스에 정의된 함수를 매핑하지만, Move와 Look는 `AABCharacterPlayer` 클래스로 연결되기에 직접 구현
}

void AABCharacterPlayer::Move(const FInputActionValue& Value)
{
 FVector2D MovementVector = Value.Get<FVector2D>();

 const FRotator Rotation = Controller->GetControlRotation();
 const FRotator YawRotation(0, Rotation.Yaw, 0);

 const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
 const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

 AddMovementInput(ForwardDirection, MovementVector.X);
 AddMovementInput(RightDirection, MovementVector.Y);
}

void AABCharacterPlayer::Look(const FInputActionValue& Value)
{
 FVector2D LookAxisVector = Value.Get<FVector2D>();

 AddControllerYawInput(LookAxisVector.X);
 AddControllerPitchInput(LookAxisVector.Y);
}
```

마찬가지로 `ConstructorHelpers`을 통해 사용할 Input 매핑 컨텍스트, 각 액션을 가져온다.

추가적으로 Action에선 Extension처럼 각 액션에 대한 처리를 확장할 수 있다.

## 정리

- 액터와 컴포넌트 개념의 이해
- 컴포넌트 속성에 지정자를 추가해 블루프린트로 확장하는 방법의 이해
  - `Visible`, `Edit`, `AnyWhere`, `DefaultsOnly`, `InstanceOnly`, `BlueprintReadOnly`, `BlueprintReadWrite`, `Category`
- 폰과 캐릭터를 구성하는 3대 구성 요소
  - 충돌 컴포넌트, 시각적 비주얼을 담당하는 메시 컴포넌트, 움직임을 담당하는 컴포넌트
- 언리얼 엔진 5에서 제공하는 향상된 입력 시스템의 활용
