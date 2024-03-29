# 레퍼런스 프로젝트 분석

제작하려는 프로젝트와 비슷한 성격의 오픈소스 프로젝트를 분석한다.

- 해당 링크에 있는 강의를 듣는게 좋겠지만, 필요한 부분만 공부해보려고 한다.
- 가능하다면 클론 코딩, 당장 스프린트에 필요한 세팅과 움직임 슈팅등을 학습.
- 학습 내용은 상세하게 기록

## [ActionRoguelike](https://github.com/tomlooman/ActionRoguelike/tree/UE5.3?tab=readme-ov-file)

- 진행 순서
  - 프로젝트 분석
  - 첫 프로젝트 분석이기 때문에 일단 눈으로 리딩을 먼저 진행
  - 캐릭터 무브먼트나 요소들에 대해서 먼저 파악
  - 스크립트를 읽어보면서 어떤식으로 구현되어 있는지 파악

### 프로젝트 분석

#### 사용된 모듈

```csharp
// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ActionRoguelike : ModuleRules
{
 public ActionRoguelike(ReadOnlyTargetRules Target) : base(Target)
 {
  PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
  
  // Simplify the include paths in our source files
  PublicIncludePaths.AddRange(
   new string[] {
    "ActionRoguelike"
   }
  );
 
  PublicDependencyModuleNames.AddRange(new string[]
  {
   "Core", 
   "CoreUObject", 
   "Engine", 
   "InputCore", 
   "AIModule", 
   "GameplayTasks", 
   "UMG", 
   "GameplayTags", 
   "OnlineSubsystem", 
   "DeveloperSettings",
   "SignificanceManager",
   "EnhancedInput",
   "Niagara"
  });

  PrivateDependencyModuleNames.AddRange(new string[]
  {
   "MoviePlayer", // loading screen
   "RenderCore" // for PSO caching code access
  });
 }
}
```

- `Core`, `CoreUObject`, `Engine`, `InputCore` 등 기본적인 모듈들이 사용되었다.
  - 기본 프로젝트 생성 시 자동으로 추가되는 모듈들
  - `Core`는 게임 엔진의 핵심으로 기본 데이터 타입을 제공
  - `CoreUObject`는 게임 엔진의 객체 시스템을 제공(GC, 언리얼 오브젝트의 클래스 구조 등)
  - `Engine`은 게임 엔진의 핵심 기능을 제공(렌더링, 입력 등)
  - `InputCore`는 입력 처리를 담당
- `AIModule`은 대충 AI관련 모듈인 듯
- `GameplayTasks`는 게임 플레이에 관련된 태스크를 제공
  - 찾아보니 비동기 관련인듯 하다. (너무 정보가 적어서 힘듬)
- `UMG`는 유저 인터페이스를 제공 UI
- `GameplayTags`는 게임 플레이에 관련된 태그를 제공
  - GAS에서도 사용되는 쉽게 접근할 수 있도록 해주는 기능
- `OnlineSubsystem`은 온라인 플랫폼에 대한 인터페이스 제공
- `DeveloperSettings`는 개발자 설정을 제공 아마 설정창을 만들거나 하는 용도로 사용되는 듯
- `SignificanceManager`는 게임 오브젝트의 중요도를 관리..? 성능 최적화와 연관
- `EnhancedInput`은 입력 처리를 개선하는 모듈
- `Niagara`는 파티클 시스템

코드에서 `PrivateDependencyModuleNames`으로 나뉜 이유는 의존성을 나누어서 관리하기 위함인 듯 하다. 아마 지역적으로만 사용되는 모듈의 경우나 내부적으로만 사용하는 경우에 해당될 듯 하다.

#### 게임플레이 태그

```csharp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace SharedGameplayTags
{
 UE_DECLARE_GAMEPLAY_TAG_EXTERN(Action_Sprint);
 UE_DECLARE_GAMEPLAY_TAG_EXTERN(Action_PrimaryAttack);
 UE_DECLARE_GAMEPLAY_TAG_EXTERN(Action_Blackhole);
 UE_DECLARE_GAMEPLAY_TAG_EXTERN(Action_Dash);
 UE_DECLARE_GAMEPLAY_TAG_EXTERN(Action_Stunned);
}
```

```csharp
// Fill out your copyright notice in the Description page of Project Settings.


#include "SharedGameplayTags.h"

namespace SharedGameplayTags
{
 UE_DEFINE_GAMEPLAY_TAG(Action_Sprint, "Action.Sprint");
 UE_DEFINE_GAMEPLAY_TAG(Action_PrimaryAttack, "Action.PrimaryAttack");
 UE_DEFINE_GAMEPLAY_TAG(Action_Blackhole, "Action.Blackhole");
 UE_DEFINE_GAMEPLAY_TAG(Action_Dash, "Action.Dash");
 UE_DEFINE_GAMEPLAY_TAG(Action_Stunned, "Status.Stunned");

 // UE_DEFINE_GAMEPLAY_TAG_COMMENT()
}
```

- [게임플레이 태그 공식문서](https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/Tags/)
- [게임플레이 관련 영상](https://www.youtube.com/watch?v=1T4S2lFf19s)
  - 이 영상을 보고 많이 이해한 듯 하다. 더이상 깊게 들어가지말고 사용하면서 익히자.
  - 놀란 점은 블루프린트 인터페이스가 있다는 점..?

#### EnhancedInput

![image](https://github.com/futurelabunseen/B-JeonganLee/assets/84510455/2b4df2df-546e-43d3-8c93-48c197ef449d)

`Content/ActionRoguelike/Input`폴더에 잘 정리가 되어 있었다. 특이한 점은 시점까지 인풋으로 구현하였다는 점?

```csharp
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputMappingContext> DefaultInputMapping;

 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_Move;

 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_LookMouse;

 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_LookStick;
 
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_Jump;
 
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_Interact;
 
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_Sprint;
 
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_Dash;
 
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_PrimaryAttack;
 
 UPROPERTY(EditDefaultsOnly, Category="Input")
 TObjectPtr<UInputAction> Input_SecondaryAttack;
```

인풋도 마찬가지로 사용할 수 있도록 `TObjectPtr`로 선언되어 있었다.

간단하게 조금만 알아보면 `UInputAction`은 `UDataAsset`을 상속 받고 `UDataAsset`은 `UObject`를 상속 받는다.

#### 플레이어

비슷한 코드가 많아서 강의를 토대로 생각해도 될 듯 하다. 액션적인 부분들은 따로 블루프린트를 사용한듯.

## ThirdPerson

개발하려는 게임이 3인칭 슈터이기 때문에 먼저 움직임 구현을 위해 3인칭 Person 예제 프로젝트를 분석한다.

```cpp
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "PracticeThirdPersonCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class APracticeThirdPersonCharacter : public ACharacter
{
 GENERATED_BODY()

 /** Camera boom positioning the camera behind the character */
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
 USpringArmComponent* CameraBoom;

 /** Follow camera */
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
 UCameraComponent* FollowCamera;
 
 /** MappingContext */
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
 UInputMappingContext* DefaultMappingContext;

 /** Jump Input Action */
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
 UInputAction* JumpAction;

 /** Move Input Action */
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
 UInputAction* MoveAction;

 /** Look Input Action */
 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
 UInputAction* LookAction;

public:
 APracticeThirdPersonCharacter();
 

protected:

 /** Called for movement input */
 void Move(const FInputActionValue& Value);

 /** Called for looking input */
 void Look(const FInputActionValue& Value);

 void JumpPressed();
   

protected:
 // APawn interface
 virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
 
 // To add mapping context
 virtual void BeginPlay();

public:
 /** Returns CameraBoom subobject **/
 FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
 /** Returns FollowCamera subobject **/
 FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
```

```cpp
// Copyright Epic Games, Inc. All Rights Reserved.

#include "PracticeThirdPersonCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// APracticeThirdPersonCharacter

APracticeThirdPersonCharacter::APracticeThirdPersonCharacter()
{
 // Set size for collision capsule
 GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
  
 // Don't rotate when the controller rotates. Let that just affect the camera.
 bUseControllerRotationPitch = false;
 bUseControllerRotationYaw = false;
 bUseControllerRotationRoll = false;

 // Configure character movement
 GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input... 
 GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

 // Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
 // instead of recompiling to adjust them
 GetCharacterMovement()->JumpZVelocity = 700.f;
 GetCharacterMovement()->AirControl = 0.35f;
 GetCharacterMovement()->MaxWalkSpeed = 500.f;
 GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
 GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
 GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

 // Create a camera boom (pulls in towards the player if there is a collision)
 CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
 CameraBoom->SetupAttachment(RootComponent);
 CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character 
 CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

 // Create a follow camera
 FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
 FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
 FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

 // Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
 // are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void APracticeThirdPersonCharacter::BeginPlay()
{
 // Call the base class  
 Super::BeginPlay();

 //Add Input Mapping Context
 if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
 {
  if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
  {
   Subsystem->AddMappingContext(DefaultMappingContext, 0);
  }
 }
}

//////////////////////////////////////////////////////////////////////////
// Input

void APracticeThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
 // Set up action bindings
 if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
  
  // Jumping
  EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
  EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APracticeThirdPersonCharacter::JumpPressed);
  EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

  // Moving
  EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APracticeThirdPersonCharacter::Move);

  // Looking
  EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APracticeThirdPersonCharacter::Look);
 }
 else
 {
  UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
 }
}

void APracticeThirdPersonCharacter::Move(const FInputActionValue& Value)
{
 // input is a Vector2D
 FVector2D MovementVector = Value.Get<FVector2D>();

 if (Controller != nullptr)
 {
  // find out which way is forward
  const FRotator Rotation = Controller->GetControlRotation();
  const FRotator YawRotation(0, Rotation.Yaw, 0);

  // get forward vector
  const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
 
  // get right vector 
  const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

  // add movement 
  AddMovementInput(ForwardDirection, MovementVector.Y);
  AddMovementInput(RightDirection, MovementVector.X);
 }
}

void APracticeThirdPersonCharacter::Look(const FInputActionValue& Value)
{
 // input is a Vector2D
 FVector2D LookAxisVector = Value.Get<FVector2D>();

 if (Controller != nullptr)
 {
  // add yaw and pitch input to controller
  AddControllerYawInput(LookAxisVector.X);
  AddControllerPitchInput(LookAxisVector.Y);
 }
}

void APracticeThirdPersonCharacter::JumpPressed()
{
 // GetCharacterMovement()->JumpZVelocity += 100.0f;
 // GetCharacterMovement()->MaxWalkSpeed += 100.0f;
}
```

움직임과 `UPROPERTY`로 선언된 부분, 바인딩되는 부분들은 이제는 익숙하다. 애니메이션 부분으로 넘어가자.

### 애니메이션

현재 만들어진 애니메이션 블루프린트와 연결

## 예정

일단 지금 알게된 내용으로 다음 Task인 움직임등을 구현하고 필요할 때 다시 분석 예정