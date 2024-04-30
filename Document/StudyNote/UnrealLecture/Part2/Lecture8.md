# 8강: 아이템 시스템

- 강의 목표
  - 트리거 박스를 활용한 아이템 상자의 구현
  - 다양한 종류의 아이템에 대한 개별적인 습득 처리의 구현
  - 소프트오브젝트 레퍼런스와 하드 오브젝트 레퍼런스의 차이 이해
- 강의 과제
  - 현재 프로젝트의 클래스를 데이터, 미들웨어, 게임의 세 가지 레이어로 한번 정리하고 이들의 의존 관계를 줄이기 위한 규칙을 만들어보시오.
  - 현재 프로젝트에 소프트 오브젝트 레퍼런스를 도입하고, 최초 맵 로딩시 메모리 사용량을 이전과 이후로 비교해보시오

## 프로젝트 준비

- 무료 무기 에셋 다운로드

## 트리거 박스의 설정

### 트리거 박스의 구현

- 루트에 트리거를 설정하고 자식에 메시 컴포넌트를 부착
- 이펙트는 기본 값으로 비활성화 상태로 두고 오버랩 이벤트 발생시 발동되도록 설정
- 이펙트 종료시 액터가 제거되도록 설정

### 실습

```c++
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABItemBox.generated.h"

UCLASS()
class ARENABATTLE_API AABItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABItemBox();

protected:
	// 해당 엑터에 구성될 컴포넌트들
	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UBoxComponent> Trigger;

	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, Category = Effect)
	TObjectPtr<class UParticleSystemComponent> Effect;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult);

	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* ParticleSystem);
};
```

```c++
// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ABItemBox.h"

#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Physics/ABCollision.h"

// Sets default values
AABItemBox::AABItemBox()
{
	// 서브오브젝트로 실제 객체 할당
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Effect"));

	// 계층구조 설정 (Root를 Trigger로)
	RootComponent = Trigger;
	Mesh->SetupAttachment(Trigger);
	Effect->SetupAttachment(Trigger);

	// 충돌 프로필 설정 (어떤 채널과 충돌할지, 엔진에 Collision에 정의되어 있음)
	// OnComponentBeginOverlap라는 콜리전에 이미 정의된 이벤트(델리게이트)에 사용할 함수를 바인딩
	// 이런 델리게이트는 블루프린트에도 사용할 수 있도록 다이나믹으로 선언되어 있다. 따라서 UFUNCTION()을 사용해야 한다.
	Trigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABItemBox::OnOverlapBegin);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BoxMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1'"));
	if (BoxMeshRef.Object)
	{
		Mesh->SetStaticMesh(BoxMeshRef.Object);
	}
	Mesh->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));
	Mesh->SetCollisionProfileName(TEXT("NoCollision"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> EffectRef(TEXT("/Script/Engine.ParticleSystem'/Game/ArenaBattle/Effect/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh'"));
	if (EffectRef.Object)
	{
		Effect->SetTemplate(EffectRef.Object);
		Effect->bAutoActivate = false;
	}
	Effect->OnSystemFinished.AddDynamic(this, &AABItemBox::OnEffectFinished); // 이벤트 바인딩은 위쪽으로 빼는게 더 바람직해 보임..
}

void AABItemBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	Effect->Activate(true);
	Effect->Activate(true);
	Mesh->SetHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AABItemBox::OnEffectFinished(UParticleSystemComponent* ParticleSystem)
{
	Destroy();
}
```

```c++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABItemData.generated.h"

// 블루프린트와 호환되도록 BlueprintType으로 선언
UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon = 0,
	Potion,
	Scroll,
};
/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Type)
	EItemType Type;
};
```

```c++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ABItemData.h"
#include "ABWeaponItemData.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABWeaponItemData : public UABItemData
{
	GENERATED_BODY()

public:
	UABWeaponItemData();
	
	UPROPERTY(EditAnywhere, Category = Weapon)
	TSoftObjectPtr<USkeletalMesh> WeaponMesh;
};
```

## 아이템 애셋의 설계

### 프로젝트에서 사용할 아이템 에셋

- 총 3가지 종류의 아이템 타입을 지정
  - 무기 타입: 캐릭터에 무기를 부착 (무기에 의한 부가 스탯 강화)
  - 포션 타입: 캐릭터의 HP를 회복
  - 스크롤 타입: 캐릭터의 기본 스탯을 상승
  - *실제 스탯 구현은 차후 강좌에서 진행*

### 아이템 애셋의 관리

현재 `ItemData`를 부모 클래스로 상속 받은 세 가지 종류의 아이템 클래스를 선언하였다. `UItemWeaponData`과 같이 자식 클래스로 상속 구조로 가져감

## 의존성 분리를 위한 설계 규칙

새로운 아이템이 추가될 때 마다 새로운 작업을 해야하는 것은 번거로울 수 있다. (사실 번거러운 것은 다른 문제고 새로운 아이템이 추가될 때 마다 기존 로직에 최대한 영향을 주지 않도록 하는 것이 중요하다. 이것이 의존성 분리의 핵심)

### 프로젝트의 주요 레이어

- 데이터 레이어: 게임을 구성하는 기본 데이터 (스탯 정보, 캐릭터 레벨 테이블 등등)
- 미들웨어 레이어: 게임에 사용되는 미들웨어 모듈 (UI, 아이템, 애니메이션, AI 등등)
- 게임 레이어: 게임 로직을 구체적으로 구현하는데 사용 (캐릭터, 게임 모드 등등)
- 위에서 아래로는 직접 참조하되, 아래에서 위로는 인터페이스를 통해 접근하도록 한다.

![image](https://github.com/futurelabunseen/B-JeonganLee/assets/84510455/6ebabe05-514f-4975-b48f-6c164faa59cd)

*이 부분 되게 중요한 듯, 미들웨어 레이어에서는 게임 레이어의 헤더를 참조하지 않도록 해야 한다.*

### 실습

```c++
//////h/////////
// 아이템을 획득했을 때 호출되는 델리게이트 이름은 FOnTakeItemDelegate이며 인자를 하나 가지며 인자는 UABItemData* 타입이다.
DECLARE_DELEGATE_OneParam(FOnTakeItemDelegate, class UABItemData* /*InItemData*/);
// 델리게이트로 변수를 만들 수 없기 때문에, 델리게이트를 래핑하는 구조체를 만들어서 변수로 사용한다.
USTRUCT(BlueprintType)
struct FTakeItemDelegateWrapper
{
	GENERATED_BODY()
	FTakeItemDelegateWrapper() {}
	FTakeItemDelegateWrapper(const FOnTakeItemDelegate& InItemDelegate) : ItemDelegate(InItemDelegate) {}	
	FOnTakeItemDelegate ItemDelegate;
};

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Equipment, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TArray<FTakeItemDelegateWrapper> TakeItemActions;
	
	virtual void TakeItem(class UABItemData* InItemData) override;
	virtual void DrinkPotion(class UABItemData* InItemData);
	virtual void EquipWeapon(class UABItemData* InItemData);
	virtual void ReadScroll(class UABItemData* InItemData);

//////cpp/////////
	// Item Actions
	TakeItemActions.Add(FTakeItemDelegateWrapper(FOnTakeItemDelegate::CreateUObject(this, &AABCharacterBase::EquipWeapon)));
	TakeItemActions.Add(FTakeItemDelegateWrapper(FOnTakeItemDelegate::CreateUObject(this, &AABCharacterBase::DrinkPotion)));
	TakeItemActions.Add(FTakeItemDelegateWrapper(FOnTakeItemDelegate::CreateUObject(this, &AABCharacterBase::ReadScroll)));

	// Weapon Component
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("hand_rSocket"));

void AABCharacterBase::TakeItem(UABItemData* InItemData)
{
	if (InItemData)
	{
		TakeItemActions[(uint8)InItemData->Type].ItemDelegate.ExecuteIfBound(InItemData);
	}
}

void AABCharacterBase::DrinkPotion(UABItemData* InItemData)
{
	UE_LOG(LogABCharacter, Log, TEXT("Drink Potion"));
}

void AABCharacterBase::EquipWeapon(UABItemData* InItemData)
{
	UABWeaponItemData* WeaponItemData = Cast<UABWeaponItemData>(InItemData);
	if (WeaponItemData)
	{
		if (WeaponItemData->WeaponMesh.IsPending())
		{
			WeaponItemData->WeaponMesh.LoadSynchronous();
		}
		Weapon->SetSkeletalMesh(WeaponItemData->WeaponMesh.Get());
	}
}

void AABCharacterBase::ReadScroll(UABItemData* InItemData)
{
	UE_LOG(LogABCharacter, Log, TEXT("Read Scroll"));
}
```

### 소프트 레퍼런싱 vs 하드 레퍼런싱

액터 로딩 시 TObjectPtr로 선언한 언리얼 오브젝트도 따라서 메모리에 로딩된다. 이를 하드 레퍼런싱이라고 하는데 만약 게임 진행에 필수적인 언리얼 오브젝트는 이렇게 선언해도 되지만 아이템의 경우 데이터 라이브러리에 1000종의 아이템 목록이 있을 때 이를 모두 다 로딩할 것은 매우 비효율적이다.

따라서 필요한 데이터만 로딩하도록 TSoftObjectPtr로 선언하고 대신 애셋 주소 문자열을 지정한다. 필요시에 에셋을 로딩하도록 구현을 변경할 수 있으나 에셋 로딩 시간이 소요된다. 현재 게임에서 로딩되어 있는 스켈레탈 메시의 목록을 살펴보면 실제 로딩이 되는 것을 알 수 있다. 따라서 SoftObjectPtr로 선언하여 확인 할 수 있다.

## 정리

- 기믹 구현을 위한 트리거 액터의 설계
- 데이터 에셋을 활용한 아이템 데이터 관리
- 의존성 분리를 위한 설계 구현
- 메모리 최적화를 위한 소프트 레퍼런싱의 구현
