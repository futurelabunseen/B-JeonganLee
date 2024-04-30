# 8강: 언리얼 C++ 설계 II - 컴포지션

- 강의 목표
  - 언리얼 C++의 컴포지션 기법을 사용해 오브젝트의 포함 관계를 설계하는 방법의 학습
  - 언리얼 C++이 제공하는 확장 열거형 타입의 선언과 활용 방법의 학습
- 강의 과제
  - 언리얼 오브젝트의 컴포지션을 활용한 예제를 고안해보고 직접 구현해보세요.
  - 두 개의 언리얼 오브젝트 A와 B(가칭)를 선언합니다.
  - B는 A의 서브 오브젝트입니다.
  - A의 CDO에서 B를 생성합니다.
  - NewObject로 A를 생성하면 서브오브젝트인 B도 생성되어 있는지 확인해봅니다.
  - B 오브젝트의 포인터를 가져온 후 B의 GetOuter() 함수를 호출해 Outer가 A를 가리키는지 확인해봅니다.

## 언리얼 오브젝트의 컴포지션

### 컴포지션(Composition)

컴포지션은 객체지향 프로그래밍에서 객체의 포함 관계를 나타내는 방법으로 **합성** 또는 **구성**이라고도 한다. 상속의 `is-a`관계만으로는 설계와 유지보수가 어렵기에 **has-a**관계를 나타내는 것이다.

### 모던 객체 설계 기법과 컴포지션

좋은 객체지향 설계 패턴을 제작하기 위한 모던 객체 설계 기법 (SOLID)라고 한다.

- **S**ingle Responsibility Principle (단일 책임 원칙)
  - 클래스는 단 하나의 책임을 가져야 한다.
- **O**pen/Closed Principle (개방/폐쇄 원칙)
  - 확장에 대해서는 열려 있어야 하지만 수정에 대해서는 닫혀 있어야 한다.
- **L**iskov Substitution Principle (리스코프 치환 원칙)
  - 파생 클래스는 기반 클래스로 대체 가능해야 한다.
- **I**nterface Segregation Principle (인터페이스 분리 원칙)
  - 클라이언트는 사용하지 않는 인터페이스에 의존하지 않아야 한다. (인터페이스를 분리해야 한다.)
- **D**ependency Inversion Principle (의존성 역전 원칙)
  - 고수준 모듈은 저수준 모듈에 의존해서는 안된다. 둘 다 추상화에 의존해야 한다.

*사실 이런 SOLID를 제대로 이해하기 위해선 객체지향에 대한 공부가 먼저 선행되어야 한다고 생각한다. 그냥 법칙을 외우고 사용하는 것에서 대부분 끝난다.*

### 컴포지션 설계 예시

전 강의에서 활용한 학교 구성원 시스템을 그대로 사용하되, 출입증으로 만들어 `Person`에게 구현하여 상속할 것인지, 합성인 컴포지션으로 가져갈 것인지를 고민해보자. 정답은 컴포지션으로 상속의 고질적인 문제점을 조금만 생각해보면 답이 나온다.

### 언러얼 엔진에서의 컴포지션 구현 방법

- 하나의 언리얼 오브젝트에는 항상 클래스 기본 오브젝트 **CDO**가 있다.
- 언리얼 오브젝트간의 컴포지션은 어떻게 구현할 것인가?
  - 언리얼 오브젝트에 다른 언리얼 오브젝트를 조합할 때 다음의 선택지가 존재
    - 방법1: **CDO에 미리 언리얼 오브젝트를 생성해 조합한다. (필수적 포함)**
    - 방법2: **CDO에 빈 포인터를 넣고 런타임에서 언리얼 오브젝트를 생성해 조합한다. (선택적 포함)**
  - 언리얼 오브젝트를 생성할 때 컴포지션 정보를 구축할 수 있다
    - 내가 소유한 언리얼 오브젝트를 SubObject라고 한다.
    - 나를 소유한 언리얼 오브젝트를 Outer라고 한다.

두 가지 방법을 유니티의 관점에서 바라본다면, Awake에서 실질적으로 정적인 할당이 이뤄지는 것과 참조 변수만 두고 런타임 도중에 할당하는 것과 같다고 볼 수 있다. 이 메서드를 `CreateDefaultSubobject`라는 API로 생성자에서 구현하거나 런타임에 `NewObject`로 생성할 수 있다.

### 실습

```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

UENUM() // 언리얼이 확인할 수 있게 만들어줌
enum class ECardType : uint8
{
 Student = 1 UMETA(DisplayName = "For Student"), // 각 항목에 대한 메타정보도 사용 가능
 Teacher UMETA(DisplayName = "For Teacher"),
 Staff UMETA(DisplayName = "For Staff"),
 Invalid
};

UCLASS()
class UNREALCOMPOSITION_API UCard : public UObject
{
 GENERATED_BODY()

public:
 UCard();

 ECardType GetCardType() const { return CardType; }
 void SetCardType(ECardType NewCardType) { CardType = NewCardType; }

private:
 UPROPERTY()
 ECardType CardType;

 UPROPERTY()
 uint32 Id;
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

UCard::UCard()
{
 CardType = ECardType::Invalid;
 Id = 0;
}
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "person.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API Uperson : public UObject
{
 GENERATED_BODY()

public:
 Uperson();

 FORCEINLINE const FString& GetName () const {return Name;} // const 지시자
 FORCEINLINE void SetName (const FString& NewName) {Name = NewName;}

 FORCEINLINE class UCard* GetCard() const {return Card;}
 FORCEINLINE void SetCard(class UCard* InCard) {Card = InCard;}
 
protected:
 UPROPERTY()
 FString Name;

 UPROPERTY()
 TObjectPtr<class UCard> Card; // 전방선언 (언리얼 5기준)
 //class UCard* Card; // 전방선언 (언리얼 4기준)
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "person.h"
#include "Card.h"

Uperson::Uperson()
{
 Name = TEXT("이정안");
 Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card"));
}
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"
#include "Card.h"

UTeacher::UTeacher()
{
 Name = TEXT("이선생");
 Card->SetCardType(ECardType::Teacher);
}

void UTeacher::DoLessson()
{
 //ILessonInterface::DoLessson(); // 인터페이스에 구현된 베이스 함수 호출
 UE_LOG(LogTemp, Log, TEXT("%s님은 가르칩니다."), *Name);
}
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Card.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
 SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
 Super::Init();

 UE_LOG(LogTemp, Log, TEXT("======================"));
 TArray<Uperson*> Persons = {NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>()};
 for (const auto Person : Persons)
 {
  const UCard* OwnCard = Person->GetCard();
  check(OwnCard);
  ECardType CardType = OwnCard->GetCardType();
  //UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %d"), *Person->GetName(), CardType);

  const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
  if (CardEnumType)
  {
   FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
   UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 %s"), *Person->GetName(), *CardMetaData);
  }
 }
 UE_LOG(LogTemp, Log, TEXT("======================"));
}
```

- `ECardType`은 열거형으로 접두사 `E`를 붙였다.
  - `uint8`로 선언하여 0부터 255까지의 값을 가질 수 있다.
  - 형식은 `enum class`로 선언하였다.
  - 매크로 `UENUM`을 사용하여 언리얼이 제공하는 확장 열거형으로 선언하였다.
  - 내부에 `UMETA` 매크로를 사용하여 메타 정보를 추가하였다. (이를 통해 코드에서 사용할 수 있다.)
- 해당 클래스 생성자를 통해서 값을 초기화한다. `CardType = ECardType::Invalid;` 카드도 카드만의 CDO를 가지고 있다.
- `TObjectPtr<class UCard> Card;`전방선언을 통해서 헤더파일과 `UCard`의 의존성을 없앴다.
  - 해당 포인터는 같은 크기를 가지기에 실제 클래스를 참조할 필요가 없어서 전방선언을 사용한다. 헤더에선 알 필요가 없고 실제 구현인 cpp에서만 알면 되기 때문이다.
  - 4에선 `class UCard* Card;`로 선언하였지만, 5에선 `TObjectPtr<class UCard> Card;`로 선언하였다. 가비지 콜렉션이나 더 나은 기능을 제공하기에 언리얼 오브젝트 포인터인 `TObjectPtr`를 사용하는 것이 좋다.
- `FORCEINLINE const FString& GetName () const {return Name;}`에서 `const` 지시자를 사용하여 함수 내에서 멤버 변수를 변경하지 못하도록 하였다.
  - 반환을 `FString&`주소로 하기 때문에 반환값 또한 변경 가능성을 막기 위해 `const`를 사용하였다.
- `Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card"));`를 통해 CDO에 `UCard`를 생성하였다.
  - 앞서 말한 생성자를 통해 모든 `Uperson`에 `UCard`가 포함되어 있다. (필수적 포함)
  - 여기에 포인터만 생성하고 이를 만지지 않고 런타임에 `NewObject`로 생성하는 방법도 있다. (선택적 포함)
  - `FName`을 통해 이름을 지정하는 것이 강제되는데 이는 `CreateDefaultSubobject`를 통해 생성된 오브젝트의 이름을 지정하는 것이다. `FName`이라는 것을 알려주기 위해 `NAME_Card`과 같이 접두사 `NAME_`을 붙여준다.
- `Card->SetCardType(ECardType::Teacher);`기본적으로 부모 클래스인 `Uperson`에서 `UCard`를 가지고 있기에 `Card`를 통해 `SetCardType`을 호출할 수 있다. (생성자의 호출 순서를 생각)
- `const UCard* OwnCard = Person->GetCard();` 구현된 다형성을 통하여 각 객체가 가지고 있는 카드에 접근이 가능하다.
  - 앞서 필수적 컴포지션 형태로 구현하였기에 문제 없이 동작하겠지만, `check(OwnCard);` 항상 널 포인터를 체크하는 습관을 들이자. but if를 사용하여 뎁스를 내리는 것보다 check를 사용하는 것이 좋을 수 있다.
  - `const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));`를 통해 메타 정보를 가져온다. (리플렉션)
  - 즉, 해당 Enum의 형태를 가져와서 아래의 `CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();`을 통해 해당 Enum의 메타 정보를 가져온다.

## 정리

- 언리얼 C++은 컴포지션을 구현하는 독특한 패턴이 있다.
- 클래스 기본 객체를 생성하는 생성자 코드를 사용해 복잡한 언리얼 오브젝트를 생성할 수 있음.
- 언리얼 C++ 컴포지션의 Has-A 관계에서 사용되는 용어
  - 내가 소유한 하위 오브젝트: SubObject
  - 나를 소유한 상위 오브젝트: Outer
- 언리얼 C++이 제공하는 확장 열거형을 사용해 다양한 메타 정보를 넣고 활용할 수 있다.
