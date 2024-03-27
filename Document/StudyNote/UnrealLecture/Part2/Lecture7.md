# 7강: 캐릭터 스탯과 위젯

- 강의 목표
  - 액터 컴포넌트를 활용한 객터 기능의 확장 방법의 이해
  - 언리얼 델리게이트를 활용한 발행 구독 모델의 학습
  - 액터의 초기화 단계와 위젯 초기화 과정의 이해
- 강의 과제
  - 현재 프로젝트에서 느슨한 결합 구현을 위해 델리게이트를 활용하는(아니면 앞으로 활용할) 사례를 정리해보시오.
  - 충돌 채널 설정에서 오브젝트 타입에 ABPawn이라는 타입을 새롭게 추가해 다른 폰의 반응은 무시하고 오로지 ABCharacter의 캡슐에만 반응하도록 설정하고자 한다.  이를 위해 추가해야 할 충돌 프로필을 생각해보시오.

## 캐릭터 스탯의 설정

### 액터 컴포넌트를 활용한 스탯의 설계

액터 컴포넌트란, 액터에 부착할 수 있는 컴포넌트 중 트랜스폼이 없는 컴포넌트이다. 액터의 기능을 확장할 때 컴포넌트로 분리해 모듈화할 수 있기 때문에 액터 컴포넌트를 사용한다. (응집성, 결합도)

이번 강의에선 스탯 데이터를 담당하는 컴포넌트와 UI 위젯을 담당하는 컴포넌트로 분리하는데, 본 액터는 두 컴포넌트가 서로 통신하도록 중개하는 역할로 지정한다. (Manager의 역할)

ex) 외부로부터 피해를 받는다면 액터는 이벤트를 받고 스탯 컴포넌트에 피해량을 전달하고, 스탯 컴포넌트는 피해량을 계산하여 UI 업데이트를 위해 UI 컴포넌트에 전달한다.

### 언리얼 델리게이트를 활용한 발행 구독 모델의 구현

푸시형태의 알림을 구현하는데 적합한 디자인 패턴으로 느슨한 결합을 위해 사용한다.

### 실습

```cpp
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });
```

- 모듈 추가 부분

```cpp
// ABCharacterBase.h

 // Stat Section
protected:
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UABCharacterStatComponent> Stat;

 // UI Widget Section
protected:
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget, Meta = (AllowPrivateAccess = "true"))
 TObjectPtr<class UWidgetComponent> HpBar;

 //virtual void SetupCharacterWidget(class UABUserWidget* InUserWidget) override;
```

```cpp
// ABCharacterBase.cpp
#include "CharacterStat/ABCharacterStatComponent.h"
#include "Components/WidgetComponent.h"

// Stat Component 
 Stat = CreateDefaultSubobject<UABCharacterStatComponent>(TEXT("Stat"));

 // Widget Component 
 HpBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
 HpBar->SetupAttachment(GetMesh());
 HpBar->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));
 static ConstructorHelpers::FClassFinder<UUserWidget> HpBarWidgetRef(TEXT("/Game/ArenaBattle/UI/WBP_HpBar.WBP_HpBar_C"));
 if (HpBarWidgetRef.Class)
 {
  HpBar->SetWidgetClass(HpBarWidgetRef.Class);
  HpBar->SetWidgetSpace(EWidgetSpace::Screen); // 2차원 UI
  HpBar->SetDrawSize(FVector2D(150.0f, 15.0f));
  HpBar->SetCollisionEnabled(ECollisionEnabled::NoCollision); // 충돌 x
 }
```

- 모든 캐릭터에 적용되도록 설정.. 마찬가지로 서브 오브젝트로 할당(액터 컴포넌트)로 메모리 할당하고 리소스는 FClassFinder로 찾아서 할당한다.

```cpp
// UI\ABHpBarWidget.h
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ABHpBarWidget.generated.h"

UCLASS()
class ARENABATTLE_API UABHpBarWidget : public UUserWidget
{
 GENERATED_BODY()

public:
 // UUserWidget의 생성자 (다른 형태임)
 UABHpBarWidget(const FObjectInitializer& ObjectInitializer);

protected:
 // UUserWidget에서 제공하는 함수로 아래 UMG 오브젝트 참조를 초기화하기 위해
 virtual void NativeConstruct() override;
 
public:
 FORCEINLINE void SetMaxHp(float NewMaxHp) { MaxHp = NewMaxHp; }
 void UpdateHpBar(float NewCurrentHp);
 
protected:
 // 언리얼 오브젝트 포인터로 UProgressBar를 가리키는 포인터 변수 선언 (전방선언 의존성 x)
 UPROPERTY()
 TObjectPtr<class UProgressBar> HpProgressBar;

 UPROPERTY()
 float MaxHp;
};
```

```cpp
//ABHpBarWidget.cpp

#include "UI/ABHpBarWidget.h"

#include "Components/ProgressBar.h"

// Super를 객체로 초기화하고 MaxHp를 -1로 초기화
UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 MaxHp = -1.0f;
}

void UABHpBarWidget::NativeConstruct()
{
 Super::NativeConstruct();

 // GetWidgetFromName: UMG에서 이름으로 찾아서 반환 (Find와 비슷)
 HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PbHpBar")));
 ensure(HpProgressBar);
}

void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{
 // 어서션 함수로 체크
 ensure(MaxHp > 0.0f);
 if (HpProgressBar)
 {
  HpProgressBar->SetPercent(NewCurrentHp / MaxHp);
 }
}
```

```cpp
// ABCharacterStatComponent.h
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ABCharacterStatComponent.generated.h"

// 델리게이트 발행 위쪽은 매개변수 x, 아래쪽은 매개변수 하나
// 컨벤션에 집중
DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
 GENERATED_BODY()

public: 
 // Sets default values for this component's properties
 UABCharacterStatComponent();

protected:
 // Called when the game starts
 virtual void BeginPlay() override;

public:
 FOnHpZeroDelegate OnHpZero;
 FOnHpChangedDelegate OnHpChanged;
 
 // 간단한 getter, setter라 inline으로 처리
 FORCEINLINE float GetMaxHp() { return MaxHp; }
 FORCEINLINE float GetCurrentHp() { return CurrentHp; }

 float ApplyDamage(float InDamage);
 
protected:
 // HP변경할 때 사용하는 함수(필수로 입구와 출구를 하나로 만들고 내부에서 훅킹함)
 void SetHp(float NewHp);
 
 // VisibleInstanceOnly 인스턴스마다 다르게 설정할 수 있다.
 UPROPERTY(VisibleInstanceOnly, Category = Stat)
 float MaxHp;

 // Transient: 디스크에 저장하지 않는다. (공간 낭비 x)
 UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
 float CurrentHp;
};
```

```cpp
// ABCharacterStatComponent.cpp
#include "CharacterStat/ABCharacterStatComponent.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
 // 생성자 초기화
 MaxHp = 200.0f;
 CurrentHp = MaxHp;
}


// Called when the game starts
void UABCharacterStatComponent::BeginPlay()
{
 Super::BeginPlay();

 // 시작시 초기화 *(Start)
 SetHp(MaxHp);
}

float UABCharacterStatComponent::ApplyDamage(float InDamage)
{
 const float PrevHp = CurrentHp;
 // Clamp: 최소값과 최대값을 설정하여 그 사이의 값만을 반환
 const float ActualDamage = FMath::Clamp<float>(InDamage, 0, InDamage);

 SetHp(PrevHp - ActualDamage);
 if (CurrentHp <= KINDA_SMALL_NUMBER)
 {
  OnHpZero.Broadcast();
 }
 
 return ActualDamage;
}

void UABCharacterStatComponent::SetHp(float NewHp)
{
 CurrentHp = FMath::Clamp<float>(NewHp, 0.0f, MaxHp);
 
 OnHpChanged.Broadcast(CurrentHp); // Invoke
}
```

- Action동작과 동일.

## 액터의 초기화 과정

### 액터의 라이프 싸이클

- [공식 문서](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/unreal-engine-actor-lifecycle?application_version=5.3)

정리하자면 액터를 최종적으로 마무리하고자 할 때는 `PostInitializeComponents`라는 함수를 통해 초기화를 마무리한다. (에디터 실행 전 마무리 작업) 이후 `BeginPlay` 함수를 통해 게임 실행 전 초기화 작업을 마무리한다. (게임 실행 전 마무리 작업) 이후에는 `Tick` 함수를 통해 게임 실행 중 작업을 진행한다. (게임 실행 중 작업)

### 위젯 컴포넌트와 위젯

위젯 컴포넌트는 Actor 이외의 UI 위젯을 띄워주는 컴포넌트에 불과하다. 내부적으로 2D와 3D모두 지원하며 위젯 컴포넌트는 컨테이너의 역할만 할 뿐, 둘은 서로 독립적으로 동작한다. (위젯과 위젯 컴포넌트)

### 위젯 컴포넌트의 초기화 과정

(현재 위젯과 실제 스탯의 통신을 위해 초기화 과정을 알아야 한다.) 발행 구독 모델의 구현을 위해 위젯 컴포넌트의 초기화 단계를 파악할 필요가 있다. UI 관련 컴포넌트는 액터의 `BeginPlay` 이후에 호출되고 있다. 생성시 `InitWidget`함수와 `NativeConstruct`함수가 호출되며, 이를 ㅌ오해 차우에 변경될 가능성을 염두해야 한다.

하지만 지금은 소유한 액터의 정보를 알아올 수 없도록 설계가 되어 있다. 따라서 이를 확장하여 설계해야 한다.

### 실습

```cpp
// ABCharacterBase.cpp
#include "UI/ABHpBarWidget.h"
#include "UI/ABMyWidgetComponent.h"

// .. 생략
// 서브 오브젝트 할당을 확장 클래스로 변경 (소유 액터를 알 수 있는 wIdget)
HpBar = CreateDefaultSubobject<UABMyWidgetComponent>(TEXT("Widget"));

// .. 생략

void AABCharacterBase::PostInitializeComponents()
{
 Super::PostInitializeComponents();

// 라이프서클중 PostInitializeComponents에서 위젯 초기화 죽음 메서드와 STAT 이벤트와 연결
 Stat->OnHpZero.AddUObject(this, &AABCharacterBase::SetDead);
}

// 실제 데미지 주는 동작을 Stat에 일임
 Stat->ApplyDamage(DamageAmount);
  
// .. 생략
// 죽으면 위젯을 숨기는 동작
HpBar->SetHiddenInGame(true);

// .. 생략
// 사용자 정의 인터페이스 구현체 (캐릭터간 의존성 x)
void AABCharacterBase::SetupCharacterWidget(UABUserWidget* InUserWidget)
{
  //확장된 위젯 클래스로 캐스팅하고, 이를 통해 Stat 이벤트와 UI 바인딩
 UABHpBarWidget* HpBarWidget = Cast<UABHpBarWidget>(InUserWidget);
 if (HpBarWidget)
 {
  HpBarWidget->SetMaxHp(Stat->GetMaxHp());
  HpBarWidget->UpdateHpBar(Stat->GetCurrentHp());
  Stat->OnHpChanged.AddUObject(HpBarWidget, &UABHpBarWidget::UpdateHpBar);
 }
}
```

```cpp
// ABHpBarWidget.cpp

// 위 코드에서 사용하게 되는 인터페이스..
#include "Interface/ABCharacterWidgetInterface.h"

// 인터페이스로 캐스팅하여 실제 인터페이스의 인스턴스를 가져온다. (해당 함수를 포인팅하여 가져옴)
// 확장으로 상위 액터의 정보를 가져올 수 있게 된다. (OwningActor)
 IABCharacterWidgetInterface* CharacterWidget = Cast<IABCharacterWidgetInterface>(OwningActor);
 if (CharacterWidget)
 {
  // 해당 인터페이스 함수를 호출하도록 함 (CharacterBase <-> HPBarWidget)
  CharacterWidget->SetupCharacterWidget(this);
 }
```

```cpp
#include "UI/ABMyWidgetComponent.h"

#include "ABUserWidget.h"

// UWidgetComponent을 상속받아 확장
void UABMyWidgetComponent::InitWidget()
{
 Super::InitWidget();

 UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());
 if (ABUserWidget)
 {
  ABUserWidget->SetOwningActor(GetOwner());
 }
}
```

## 정리

- 액터 컴포넌트를 사용해 캐릭터가 가진 기능을 분산
- 언리얼 델리게이트를 활용한 발행 구독 모델의 구현
- 위젯 컴포넌트 초기화 시점을 파악하기 위한 기존 클래스 구조의 확장 설계
