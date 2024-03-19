# 6강: 언리얼 오브젝트 리플렉션 시스템 II

- 강의 목표
  - 언리얼 오브젝트 리플렉션 시스템을 사용해 언리얼 오브젝트를 다루는 방법을 학습
- 강의 과제
  - 언리얼 오브젝트 리플렉션 시스템을 활용한 예제를 고안하고 이를 직접 구현해보세요.

## 실습

- 주의사항
  - `#include "Student.generated.h"`아래로는 include문을 작성하지 않는다.
  - 비슷하게 오브젝트에  선언된 헤더가 가장 위쪽에 위치해야 한다.

### 클래스 구조

```cpp
// Person.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UPerson : public UObject
{
 GENERATED_BODY()
public:
 UPerson(); // 생성자 -> CDO에 초기화할 값들을 설정한다.

 UFUNCTION() // 리플렉션 시스템을 사용해 호출할 수 있는 함수, 즉 이 매크로를 사용해야 코드에서 리플렉션으로 호출이 가능하다.
 virtual void DoLesson(); // 가상 함수로 작성하여 파생 클래스에서 재정의할 수 있도록 한다.

 const FString& GetName() const; // Getter
 void SetName(const FString& InName); // Setter
protected:
 UPROPERTY() // 리플렉션 시스템을 사용해 접근할 수 있는 변수
 FString Name;

 UPROPERTY()
 int32 Year;

private:
 
};
```

가장 베이스가 되는 UPerson클래스로 UObject를 상속받아 구현한다. 내부에는 동일한 행동 양식을 가상함수로 정의하여 다형성을 구현하고, 공통된 필드인 Name과 Year를 선언한다.

```cpp
// person.cpp
#include "Person.h"

UPerson::UPerson()
{
 Name = TEXT("이정안");
 Year = 1;
}

void UPerson::DoLesson()
{
 UE_LOG(LogTemp, Log, TEXT("%s 님이 수업에 참여합니다."), *Name);
}

const FString& UPerson::GetName() const
{
 return Name;
}

void UPerson::SetName(const FString& InName)
{
 Name = InName;
}
```

실제 Cpp파일에서는 생성자에서 초기화를 하고, 수업을 듣는 함수를 구현한다. 생성자로 초기화 된 값은 CDO에 저장된다. (Static Constructor)

```cpp
// Student.h
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"                 // 이 순서가 중요하다. (위의 주의사항)
#include "Student.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UStudent : public UPerson // 상속
{
 GENERATED_BODY()
public:
 UStudent();
 
 virtual void DoLesson() override; // 재정의

private:
 UPROPERTY()
 int32 Id; // Id는 private이지만 리플렉션 시스템을 사용해 접근할 수 있다.
};
```

`Student`클래스는 `Person`클래스를 상속받아 구현한다. `Id`는 private이지만 리플렉션 시스템을 사용해 접근할 수 있다.
주의 깊게 봐야하는 부분은 include문의 위치와 상속된 모습이다. (`:`을 통해 상속을 표현하는데 상속 구조에도 접근자를 붙인다..)

```cpp
// Student.cpp
#include "Student.h" // Student 참조

UStudent::UStudent()
{
 Name = TEXT("이학생");
 Year = 1;
 Id = 1;
}

void UStudent::DoLesson()
{
 Super::DoLesson();

 UE_LOG(LogTemp, Log, TEXT("%d학년 %d반 %s님이 수업을 듣습니다."), Year, Id, *Name);
}
```

```cpp
// Teacher.h
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h"
#include "Teacher.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UTeacher : public UPerson
{
 GENERATED_BODY()

public:
 UTeacher();

 virtual void DoLesson() override;

private:
 UPROPERTY()
 int32 Id;
 
}
```

```cpp
// Teacher.cpp

#include "Teacher.h"

UTeacher::UTeacher()
{
 Name = TEXT("이선생");
 Year = 3;
 Id = 1;
}

void UTeacher::DoLesson()
{
 Super::DoLesson();

 UE_LOG(LogTemp, Log, TEXT("%년차 선생님 %s님이 수업을 강의합니다.."), Year, *Name);
}
```

```cpp
// UMyGameInstance.cpp

void UMyGameInstance::Init()
{
 Super::Init();

 UStudent* Student = NewObject<UStudent>(); // UStudent 클래스의 객체를 생성한다.
 UTeacher* Teacher = NewObject<UTeacher>();
 Student->SetName(TEXT("학생1")); // Setter 함수를 통해 이름을 설정한다.
 UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 %s"), *Student->GetName()); // Getter 함수를 통해 이름을 출력한다.

 FString CurrentTeacherName;
 FString NewTeacherName = TEXT("이득우");
 FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name")); // 컴파일 타임에 선생님 클래스의 이름 프로퍼티를 찾는다.
 if (NameProp)
 {
  NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName); // NUll 아니라면 해당 프로퍼티를 해당 객체에서 찾아서 값을 전달해준다. (out)
  UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 %s"), *CurrentTeacherName); // Getter 함수를 통해 이름을 출력한다.

  NameProp->SetValue_InContainer(Teacher, &NewTeacherName); // 위와 같은 방식으로 리플렉션을 통해 접근한다.
  UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 %s"), *Teacher->GetName()); // 실제 값이 변경되었는지 확인
 }

 UE_LOG(LogTemp, Log, TEXT("========================="));

 Student->DoLesson(); // 기본 함수 호출

 UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson")); // 런타임에 선생님 클래스의 수업 함수를 찾는다.
 if (DoLessonFunc)
 {
  Teacher->ProcessEvent(DoLessonFunc, nullptr); // 해당 함수를 호출한다.
 }

 UE_LOG(LogTemp, Log, TEXT("========================="));
}
```

- `NewObject`함수를 통해 객체를 생성한다.
  - 언리얼의 객체를 생성하기 위한 `New`라고 보면 된다.
- `FindPropertyByName`를 통해 해당 클래스의 프로퍼티를 찾는다.
- `GetValue_InContainer`를 통해 해당 객체의 프로퍼티 값을 가져온다.
- `SetValue_InContainer`를 통해 해당 객체의 프로퍼티 값을 변경한다.
- `FindFunctionByName`을 통해 해당 클래스의 함수를 찾는다.
- `ProcessEvent`를 통해 해당 함수를 호출한다.

*그렇다면 게터, 세터 대신에 리플렉션을 쓰는 것이 더 좋은 것인가?*

새롭게 알게 된 사실은 상속에도 접근자를 붙여서 제한할 수 있다는 점이다. 기본적으로 public인 `is-a`관계보다 더 제한적으로 파생 클래스의 서브클래스까지 제한할 수 있는 점이 신기하다.

언리얼 엔진의 내부에 이런 리플렉션을 사용하여 구현된 기능이 많다고 하는데, 리플렉션은 본질적인 객체지향의 캡슐화를 위반할 수 있는 부분이 존재한다. 하지만 리플렉션은 런타임때 동적으로 타입을 확인하고 호출하는 등의 더 유연한 기능이 가능하니, 이런 트레이드 오프를 잘 생각해야 할 것 같다.

## 정리

- 리플렉션 시스템을 사용해 **언리얼 오브젝트의 특정 속성과 함수를 이름으로 검색할 수 있다.**
- 리플렉션 시스템을 사용해 **접근 지시자와 무관하게 값을 설정할 수 있다.**
  - 접근 지시자를 무시한다는 것은 캡슐화를 위반하는 것인데.. 과연 올바르게 사용하는 방법이 있을까?
- 리플렉션 시스템을 사용해 **언리얼 오브젝트의 함수를 호출할 수 있다.**

언리얼 엔진의 기본적인 프레임웤이 리플렉션을 활용해 구축되어 있으므로, 이를 이해하기 위해서는 리플렉션 시스템을 이해하는 것이 필요하다.
