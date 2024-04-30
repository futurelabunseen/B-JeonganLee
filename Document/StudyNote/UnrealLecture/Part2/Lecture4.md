# 4강: 캐릭터 애니메이션 설정

- 강의 목표
  - 캐릭터의 애니메이션 시스템을 생성하는 방법의 학습
  - 캐릭터의 애니메이션 시스템을 효과적으로 설계하는 방법의 학습
- 강의 과제
  - 자신의 게임에 등장하는 캐릭터의 행동을 기획하고 이를 구현한 애니메이션 블루프린트를 정리하시오

## 새로운 캐릭터 제작

### 캐릭터 애니메이션 시스템의 생성

- 스켈레탈 메시 컴포넌트의 애니메이션 블루프린트 클래스를 지정한다
- 캐릭터가 초기화될 때 `AnimInstance` 클래스의 인스턴스를 생성한다
- 캐릭터는 `GetAnimInstance()` 함수를 사용해 애니메이션을 얻을 수 있다
- 애니메이션 인스턴스는 `GetOwningActor()` 함수를 사용해 자신이 소유한 액터 정보를 얻을 수 있다

### AnimInstance

애니메이션 블루프린트는 이벤트 그래프와 Anim 그래프의 두 영역으로 분리되어 있다. 이벤트 그래프는 이벤트로부터 상태를 파악할 수 있는 주요 변수를 지정하는데 사용한다. Anim 그래프는 저장된 변수로부터 지정된 상태의 애니메이션을 재생한다. 애님 그래프의 복잡한 상태는 `State Alias`로 분리해 효과적으로 설계할 수 있다.

- 이벤트 그래프에서 `NativeInitalizeAnimation`라는 함수가 발생하면 `GetOwningActor()` 함수를 사용해 액터 정보를 가져와 현재 캐릭터(액터)를 살펴보고 지정한 변수를 저장한다. 이 애니메이션에 저장된 변수를 애니메이션 그래프에서 할용하게 된다. (FSM에 맞게 사용하지만 복잡해진다. 따라서 언리얼에서는 `State Alias`를 사용하여 벗어나고자 함.)

### 실습

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
 GENERATED_BODY()

public:
 UABAnimInstance();

protected:
 virtual void NativeInitializeAnimation() override;

 virtual void NativeUpdateAnimation(float DeltaSeconds) override;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
 TObjectPtr<class ACharacter> Owner;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
 TObjectPtr<class UCharacterMovementComponent> Movement;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 FVector Velocity;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 float GroundSpeed;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 uint8 bIsIdle : 1;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 float MovingThreshould;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 uint8 bIsFalling : 1;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 uint8 bIsJumping : 1;

 UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
 float JumpingThreshould;
};
```

```cpp
#include "Animation/ABAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UABAnimInstance::UABAnimInstance()
{
 MovingThreshould = 3.0f;
 JumpingThreshould = 100.0f;
}

void UABAnimInstance::NativeInitializeAnimation()
{
 Super::NativeInitializeAnimation();

 Owner = Cast<ACharacter>(GetOwningActor());
 if (Owner)
 {
  Movement = Owner->GetCharacterMovement();
 }
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
 Super::NativeUpdateAnimation(DeltaSeconds);

 if (Movement)
 {
  Velocity = Movement->Velocity;
  GroundSpeed = Velocity.Size2D();
  bIsIdle = GroundSpeed < MovingThreshould;
  bIsFalling = Movement->IsFalling();
  bIsJumping = bIsFalling & (Velocity.Z > JumpingThreshould);
 }
}
```

- `UABAnimInstance` 클래스는 `UAnimInstance` 클래스를 상속받아 구현된다
  - 즉, 사용자 설정 애니메이션 인스턴스
- `NativeInitializeAnimation` 함수는 애니메이션 인스턴스가 초기화될 때 호출되는 함수로, 액터 정보를 가져와 변수를 저장한다
  - `Owner` 변수는 애니메이션 인스턴스가 소유한 액터 정보를 저장한다
  - `Movement` 변수는 캐릭터의 움직임 정보를 저장한다
  - `Cast<ACharacter>(GetOwningActor())` 함수는 애니메이션 인스턴스가 소유한 액터 정보를 캐릭터로 변환한다 (형변환)
- `NativeUpdateAnimation` 함수는 애니메이션 인스턴스가 업데이트될 때 호출되는 함수로, 애니메이션을 업데이트한다
  - 실제 캐릭터 애니메이션 로직을 설계한다. 지금은 움직을 때 설정
  - 이 데이터를 기반으로 블루프린트를 동작시킨다
- 생성자는 기본적인 변수를 초기화한다
- `UPROPERTY`를 통해서 블루프린트에서 사용할 수 있는 변수를 지정한다

## 정리

- `C++`클래스를 상속받은 애니메이션 블루프린트의 생성 방법의 이해
- 이벤트 그래프와 애님 그래프로 구성된 애니메이션 블루프린트의 구조 파악
- 애님 그래프를 사용한 애니메이션 시스템의 설계 방법의 학습
