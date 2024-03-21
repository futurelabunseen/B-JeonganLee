# 7강: 언리얼 C++ 설계 I - 인터페이스

- 강의 목표
  - 언리얼 C++ 인터페이스 클래스를 사용해 보다 안정적으로 클래스를 설계하는 기법의 학습
- 강의 과제
  - C++ 언어가 제공하는 다중 상속 기능에서 문제가 될 수 있는 부분은 어떤 것인지 살펴보고, Java와 C#과 같은 후발언어들은 왜 다중 상속을 사용하지 않고 인터페이스를 사용한 제한적 상속을 구현했는지 정리해보세요.
  - Person 클래스의 GetName 함수를 다음과 같이 선언해보았다. 이들의 차이점을 정리해보시오.

## 언리얼 C++ 인터페이스

인터페이스란 객체가 **반드시 구현해야 할 행동을 지정**하는데 활용되는 타입으로 **다형성의 구현**과 **의존성이 분리**된 설계에 유용하게 활용된다.

*데이터가 아닌 행동으로 책임에 초점을 맞춘다.*

언리얼 엔진에서 게임 콘텐츠를 구성하는 오브젝트의 설계 예시로 월드에 배치되는 모든 오브젝트 중 움직이는 오브젝트에 대해 반드시 움직이게 하고 싶다면`INavAgentInterface`를 상속받아 구현한다. (Pawn)

### 예제를 위한 클래스 다이어그램

수업에 참여하는 사람과 참여하지 않는 사람을 구분하여 이를 인터페이스를 통해 구현해보자.

- 수업에 반드시 참여해야 하는 사람은 `Student`, `Teacher`이며, `Staff`은 참여하지 않는다. 이 행동에 대해서 `ILessonInterface`로 나타낸다.

### 언리얼 C++ 인터페이스 특징

언리얼 C++ 인터페이스는 생성하면 두 개의 클래스가 생성된다. `U`로 시작하는 타입 클래스로 타입의 정보를 제공하는 역할과 `I`로 시작하는 인터페이스 클래스로 실절적인 설계 및 구현을 담당한다.

`U`타입 클래스 정보는 런타임에서 인터페이스의 구현 여부를 파악하는 용도로 사용되고, 실제로 `U`타입에서 작업할 일은 없다. 인터페이스에 관련된 구성 및 구현은 `I`인터페이스 클래스에서 진행된다.

`언리얼 C++`은 다른 객체지향 언어와 달리 인터페이스에도 구현이 가능하다.

*`C#`만 써서 과연 인터페이스에도 구현을 하는 것이 좋은가? 라는 생각이 든다. 구현이 들어가는 순간 추상클래스로 전락하고 자율성이 떨어지는 것이 아닌가?*

```cpp
#include "MyGameInstance.h"

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
 for(const auto Person : Persons)
 {
  UE_LOG(LogTemp, Log, TEXT("구성원 이름: %s"), *Person->GetName());
 }
 UE_LOG(LogTemp, Log, TEXT("======================"));

 for(const auto Person : Persons)
 {
  ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
  if(LessonInterface)
  {
   LessonInterface->DoLessson();
  }
 }
 UE_LOG(LogTemp, Log, TEXT("======================"));
}
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LessonInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULessonInterface : public UInterface
{
 GENERATED_BODY()
};

/**
 * 
 */
class UNREALINTERFACE_API ILessonInterface
{
 GENERATED_BODY()

 // Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
 virtual  void DoLessson() = 0;
 // or
 //virtual void DoLessson() { UE_LOG(LogTemp, Warning, TEXT("수업에 입장합니다.")); }
};
```

```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "person.generated.h"

UCLASS()
class UNREALINTERFACE_API Uperson : public UObject
{
 GENERATED_BODY()

public:
 Uperson();

 FORCEINLINE FString& GetName () {return Name;}
 FORCEINLINE void SetName (const FString& NewName) {Name = NewName;}
protected:
 UPROPERTY()
 FString Name;
};
```

```cpp
#pragma once

#include "CoreMinimal.h"
#include "LessonInterface.h"
#include "person.h"
#include "Student.generated.h"

UCLASS()
class UNREALINTERFACE_API UStudent : public Uperson, public ILessonInterface
{
 GENERATED_BODY()

public:
 UStudent();

 virtual void DoLessson() override;
};
```

```cpp
#include "Student.h"

UStudent::UStudent()
{
 Name = TEXT("이학생");
}

void UStudent::DoLessson()
{
 UE_LOG(LogTemp, Log, TEXT("%s님은 공부합니다."), *Name);
}
```

- `class ULessonInterface : public UInterface`이 부분은 `U`타입 클래스 정보를 제공하는 역할을 한다. 자동으로 생성되는 코드이다. (건드리지 않는다.)
- `ILessonInterface`실제 정의할 행동은 `I`타입 클래스에서 정의한다.
  - `virtual void DoLessson() = 0;`을 통해 **순수 가상함수**로 만들어 인터페이스를 구현하는 클래스에서 반드시 구현해야 하는 함수임을 명시한다.
  - C++ 특성상 내부에 구현을 가질 수도 있으며, 이를 호출하기 위해서 `Super`가 아닌 해당 인터페이스에 직접 접근하여 호출한다. `ILessonInterface::DoLessson();`
- `ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);`캐스팅을 통해 안전하게 인터페이스를 사용할 수 있다. (캐스팅 실패시 `nullptr`를 반환한다.)

## 정리

- 클래스가 반드시 구현해야 하는 기능을 저장하는데 사용한다.
- C++은 기본적으로 다중상속을 지원하지만, 언리얼 C++의 인터페이스를 사용해 가급적 축소된 다중상속의 형태로 구현하는 것이 향후 유지보수에 도움이 된다. (다형성이 필요한 부분에 대해)
- 언리얼 C++ 인터페이스는 두 개의 클래스를 생성한다.
- 언리얼 C++ 인터페이스는 추상 타입으로 강제되지 않고, 내부에 기본 함수를 구현할 수 있다.

### Tips

- 에디터나 IDE가 아닌 직접적으로 파일을 옮기면 언리얼 엔진에서 파일이 인식되지 않기에 해결하기 위해 `Refresh`를 사용하자.
- `FORCEINLINE` 매크로는 인라인 함수를 강제로 만들어주는 매크로이다. 인라인 함수는 함수 호출을 줄여 성능을 향상시키는데, 이 매크로는 인라인 함수로 만들어주는 역할을 한다.
- `#include "person.generated.h"`파일은 항상 가장 밑에 위치해야 한다. 그렇지 않으면 컴파일 에러가 발생한다.
- 한글은 코드에 사용하지 않는 것이 좋다. (경로도 마찬가지)
