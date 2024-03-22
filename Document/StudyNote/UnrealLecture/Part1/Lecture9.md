# 9강: 언리얼 C++ 설계 III - 델리게이트

- 강의 목표
  - 느슨한 결합의 장점과 이를 편리하게 구현하도록 도와주는 델리게이트의 이해
  - 발행 구독 디자인 패턴의 이해
  - 언리얼 델리게이트를 활용한 느슨한 결합의 설계와 구현의 학습
- 강의 과제
  - 언리얼 델리게이트를 활용한 예제를 고안하고 직접 구현해보세요.
    - 게임 데이터를 관리하는 클래스가 있다고 가정합시다.
    - 게임 데이터를 화면에 출력하는 UI 클래스가 있다고 가정해봅시다.
    - 게임 데이터가 변경될 때 자동으로 UI도 변경되도록 만들어보세요.
    - 실제 UI를 구현하지 않고 로그로 표현하세요

## 느슨한 결합(Loose Coupling)

- 강한 결합(Tight Coupling)
  - 클래스들이 서로 의존성을 가지는 경우를 의미한다.
  - 전 예제의 Card가 없는 경우는 Person객체가 만들어질 수 없다.
  - 따라서 이를 Person은 Card에 강하게 결합되어 있다고 할 수 있다.
  - 추가적으로 다른 인증 제도가 추가되면서 Card가 아닌 다른 인증 방법을 사용하게 된다면 Person 클래스를 수정해야 한다. (수정이 필요한 부분이 많아진다.)
- 느슨한 결합 (Loose Coupling)
  - 실물에 의존하지 말고 추상적 설계에 의존하라 (DIP)
  - 객체의 데이터가 아닌 행동에 초점을 맞추어 Person은 출입을 확인해야 하는 객첵로 바라본다면 이를 담당할 인터페이스가 필요하다.
  - `ICheck` 인터페이스를 상속받은 새로운 카드 인터페이스를 선언하여 해결한다.
  - 이러한 느슨한 결합 구조는 유지보수를 쉽게 만들어준다.

### 느슨한 결합의 간편한 구현 - 델리게이트(Delegate)

- [공식 문서](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/delegates-and-lamba-functions-in-unreal-engine?application_version=5.3)

하지만 위 방식은 매번 인터페이스를 만들어야 하기에 번거로울 수 있다. 따라서 함수를 오브젝트와 같이 관리한다면 더욱 편리하게 느슨한 결합을 구현할 수 있다.

`C#`의 유용한 델리게이트를 따라 언리얼 C++도 델리게이트를 지원한다.

## 발행 구독 디자인 패턴

델리게이트를 좀 더 깊게 이해하기 위해선 `발행 구독 디자인 패턴`을 이해하면 좋다.

발행 구독 디자인 패턴은 푸시형태의 알림을 구현하는데 적합한 디자인 패턴으로 발행자(Publisher)와 구독자(Subscriber)로 나뉜다.

- 콘텐츠 제작자는 콘텐츠를 생산한다.
- 발행자는 배포된 콘텐츠를 배포한다.
- 구독자는 배포된 콘텐츠를 받아 소비한다.
- 제작자와 구독자가 서로를 몰라도, 발행자를 통해 콘텐츠를 생산하고 전달할 수 있다. (느슨한 결합)

장점으로는 제작자와 구독자는 서로를 모르기 때문에 느슨한 결합으로 구성된다. 유지 보수가 쉽고, 유연하게 활용할 수 있으며 테스트가 쉬워진다. 시스템 스케일을 유연하게 조절할 수 있으며, 기능 확장에 용이하다.

*옵저버 패턴(Observer Pattern)*

### 예제를 위한 클래스 다이어그램과 시나리오

이번 예제는 학교에서 진행하는 온라인 수업을 예시로 학사 정보와 학생의 관계에 집중한다.

- 학교는 학사 정보를 관리한다.
- 학사 정보가 변경되면 자동으로 학생에게 알려준다.
- 학생은 학사 정보의 알림 구독을 해지할 수 있다.

### 언리얼 델리게이트

언리얼 엔진은 발행 구독 패턴 구현을 위해 델리게이트 기능을 제공한다. 델리게이트의 사전적 의미는 대리자로 학사정보의 구독과 알림을 대리해주는 객체를 의미한다.

## 언리얼 델리게이트의 선언

### 언리얼 델리게이트 선언시 고려사항

델리게이트를 설계하기 위해선 많은 사항을 고려해야 한다.

- 어떤 데이터를 전달하고 받을 것인가? 인자의 수와 각각의 타입을 설계
  - 몇 개의 인자를 전달할 것인가?
  - 어떤 방식으로 전달할 것인가?
  - 일대일로 전달
  - 일대다로 전달
- 프로그래밍 환경 설정
  - `C++` 프로그래밍에서만 사용할 것인가?
  - `UFUNCTION`으로 지정된 블루프린트 함수와 사용할 것인가?
- 어떤 함수와 연결할 것인가?
  - 클래스 외부에 설계된 `C++` 함수와 연결
  - 전역에 설계된 정적 함수와 연결
  - 언리얼 오브젝트의 멤버 함수와 연결 (대부분의 경우 이 방식)

### 언리얼 델리게이트 선언 매크로

> DECLARE_{델리게이트 유형}DELEGATE{함수정보}

- 델리게이트 유형: 어떤 유형의 델리게이트인지 구상한다
  - 일대일 형태로 C++만 지원한다면 유형은 공란으로 둔다. `DECLARE_DELEGATE`
  - 일대다 형태로 C++만 지원한다면 유형은 `MULTICAST`로 지정한다. `DECLARE_MULTICAST_DELEGATE`
  - 일대일 형태로 블루프린트를 지원한다면 `DYNAMIC`으로 지정한다. `DECLARE_DYNAMIC_DELEGATE`
  - 일대다 형태로 블루프린트를 지원한다면 `DYNAMIC_MULTICAST`로 지정한다. `DECLARE_DYNAMIC_MULTICAST_DELEGATE`
- 함수정보: 연동 될 함수 형태를 지정한다
  - 인자가 없고 반환값도 없으면 공란으로 둔다. `DECLARE_DELEGATE`
  - 인자가 하나고 반환값이 없으면 `OneParam`으로 지정한다. `DECLARE_DELEGATE_OneParam`
  - 인자가 세 개고 반환값이 있으면 `RetVal_ThreeParams`로 지정한다. `DECLARE_DELEGATE_RetVal_ThreeParams` (`Multicast`는 반환값을 지원하지 않음)
  - 최대 9개까지 지원함

*C#, Unity의 Action, Event, Func과 유사하다. 미리 구현해 놓은 델리게이트 유형이 있어서 편리하게 사용할 수 있다.*

### 언리얼 델리게이트 선정 예시

- 학사 정보가 변경되면 알림 주체와 내용을 학생에게 전달한다.
  - 두 개의 인자를 가짐
- 변경된 학사 정보는 다수 인원을 대상으로 발송한다.
  - `MULTICAST`로 지정
- 오직 C++ 프로그래밍에서만 사용된다.
  - `DYNAMIC`은 사용하지 않음

```cpp
DECLARE_MULTICAST_DELEGATE_TwoParams
```

### 언리얼 델리게이트의 설계

학사 정보 클래스와 학생 클래스의 상호 의존성을 최대한 없앤다. 즉, **하나의 클래스는 하나의 작업에만 집중하도록 설계**한다. (자동적으로 SRP를 준수하게 되면서 리스코프를 제외한 나머지 원칙들도 준수하게 된다.)

학사 정보 클래스는 델리게이트를 선언하고 알림에만 집중하며 학생 클래스는 알림을 수신하는데만 집중한다. 직원도 알림을 받을 수 있도록 유연하게 설계하며, **학사 정보와 학생은 서로 헤더를 참조하지 않도록 신경쓴다.**

이를 위해 발행과 구독을 컨트롤하는 주체를 설정한다. 학사 정보에서 선언한 델리게이트를 중심으로 구독과 알림을 컨트롤하는 주체 설정

## 실습

```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CourseInfo.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangedSignature, const FString&, const FString&);

UCLASS()
class UNREALDELEGATE_API UCourseInfo : public UObject
{
 GENERATED_BODY()

public:
 UCourseInfo();

 FCourseInfoOnChangedSignature OnChanged;

 void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents);

private:
 FString Contents;
};
```

```cpp
#include "CourseInfo.h"

UCourseInfo::UCourseInfo()
{
 Contents = TEXT("기존 학사 정보");
}

void UCourseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents)
{
 Contents = InNewContents;

 UE_LOG(LogTemp, Log, TEXT("[CourseInfo] 학사 정보가 변경되어 알림을 발송합니다."));
 OnChanged.Broadcast(InSchoolName, Contents);
}
```

```cpp
#pragma once

#include "CoreMinimal.h"
#include "LessonInterface.h"
#include "person.h"
#include "Student.generated.h"

UCLASS()
class UNREALDELEGATE_API UStudent : public Uperson, public ILessonInterface
{
 GENERATED_BODY()

public:
 UStudent();

 virtual void DoLessson() override;

 void GetNotification(const FString& School, const FString& NewCourseInfo);
};
```

```cpp
#include "Student.h"
#include "Card.h"

UStudent::UStudent()
{
 Name = TEXT("이학생");
 Card->SetCardType(ECardType::Student);
}

void UStudent::DoLessson()
{
 UE_LOG(LogTemp, Log, TEXT("%s님은 공부합니다."), *Name);
}

void UStudent::GetNotification(const FString& School, const FString& NewCourseInfo)
{
 UE_LOG(LogTemp, Log, TEXT("[Student] %s님이 %s로부터 받은 메시지: %s"), *Name, *School, *NewCourseInfo);
}
```

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class UNREALDELEGATE_API UMyGameInstance : public UGameInstance
{
 GENERATED_BODY()
public:
 UMyGameInstance();
 
 virtual void Init() override;

private:
 UPROPERTY()
 TObjectPtr<class UCourseInfo> CourseInfo;
 
 UPROPERTY()
 FString SchoolName;
};
```

```cpp
#include "MyGameInstance.h"

#include "Card.h"
#include "CourseInfo.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
 SchoolName = TEXT("학교");
}

void UMyGameInstance::Init()
{
 Super::Init();

 // CDO가 아닌 런타임에 합성으록 가져감
 // CourseInfo가 서브 오브젝트로 등록되기 위해 Outer로 this를 전달 즉, GameInstance의 서브 오브젝트로 등록
 // 이렇게 코드로 컴포지션 관계를 만들 수 있는데, 이는 CDO가 아닌 런타임에 할당 하는 것이다.
 // 좀 더 나가아서 this가 아닌 다른 오브젝트의 서브 오브젝트로 등록할 수도 있다.
 CourseInfo = NewObject<UCourseInfo>(this); 

 UE_LOG(LogTemp, Log, TEXT("======================"));

 // but 이 오브젝트는 지역 변수로 선언되어 함수가 끝나면 메모리에서 해제되기에 outer를 등록할 필요가 없다.
 UStudent* Student1 = NewObject<UStudent>();
 Student1->SetName(TEXT("학생1"));
 UStudent* Student2 = NewObject<UStudent>();
 Student2->SetName(TEXT("학생2"));
 UStudent* Student3 = NewObject<UStudent>();
 Student3->SetName(TEXT("학생3"));

 // 가지고 있는 학사 정보 시스템의 델리게이트에 학생과 델리게이트와 같은 형식을 가진 함수를 바인딩
 CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
 CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
 CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);

 CourseInfo->OnChanged.AddLambda([](const FString& School, const FString& NewCourseInfo)
 {
  UE_LOG(LogTemp, Log, TEXT("[Lambda] 학사 정보가 변경되었습니다. 학교: %s, 정보: %s"), *School, *NewCourseInfo);
 });

 // 학사 정보를 변경 내부에서 Invoke
 CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));
 
 UE_LOG(LogTemp, Log, TEXT("======================"));
}
```

- `DECLARE_MULTICAST_DELEGATE_TwoParams`를 통해 두 개의 인자를 가지는 멀티캐스트 델리게이트를 선언
  - `DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangedSignature, const FString&, const FString&);`
  - `FCourseInfoOnChangedSignature`는 델리게이트의 이름이다.
  - 첫 번째 인자인 델리게이트 이름은 `F`로 접두사를 가지며 뒤로는 클래스 이름과 액션을 붙여서 사용한다. `OnChanged`, 마지막으로 `Signature`를 붙여서 사용한다.
  - 뒤로는 전달할 인자의 타입을 나열한다. `const FString&, const FString&`
  - 정리하면 `DECLARE_MULTICAST_DELEGATE_TwoParams`이기에 두 개의 인자를 가지는 멀티캐스트 델리게이트를 선언한다.
- `FCourseInfoOnChangedSignature OnChanged;` 학사 정보 클래스에 델리게이트 멤버 변수를 선언한다. 이를 통해 구독하므로 이는 발행자가 된다. (unity의 event와 유사)
- `void UCourseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents)`
  - 마찬가지로 대리자와 동일한 인자를 가지는 함수를 선언한다. *OnChanged를 직접가지기에 이를 외부에서 Invoke도 가능하지만, 위험하기에 자신이 직접 호출하는 것이 더 적합하다. 자신이 가진 함수로*
  - `OnChanged.Broadcast(InSchoolName, Contents);` 브로드 캐스트 방식으로 등록된 구독자에게 알림을 전달한다.
- `void GetNotification(const FString& School, const FString& NewCourseInfo);`
  - `UStudent`클래스도 마찬가지로 대리자와 같은 형식의 함수를 선언하여 알림을 받을 수 있도록 한다.
- `TObjectPtr<class UCourseInfo> CourseInfo;`
  - `UCourseInfo`를 가지는 포인터를 선언한다. (`UObject`를 상속받은 클래스는 포인터로 선언하는 것이 좋다. 탬플릿)
- `CourseInfo = NewObject<UCourseInfo>(this);`
  - 실제로는 CDO, 생성자에서 생성하는 것이 좋지만, `NewObject`의 학습을 위해 런타임에 생성한다.
  - 실제는 학교는 반드시 학사정보를 가져야 하는 has-a의 관계이기에 생성자에서 생성하는 것이 좋다.
  - `this`를 Outer로 전달하여 GameInstance의 서브 오브젝트로 등록한다.
  - `CourseInfo`는 `UMyGameInstance`의 서브 오브젝트로 등록된다.
  - 더 나아가 `this`가 아닌 다른 오브젝트의 서브 오브젝트로 등록할 수도 있다. (이건 관리자의 역항인듯)
- `UStudent* Student1 = NewObject<UStudent>();`
  - 동적으로 `UObject`객체를 생성한다. 하지만 지역 변수이기에 함수가 끝나면 메모리에서 해제된다. (가비지 컬렉터, 직접 해제해도 된다.) 따라서 `Outer`를 등록할 필요가 없다.
- `CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);`
  - 해당 발행자에 구독할 대상과 메서드를 바인딩하는 코드이다.
  - 아래와 같이 람다 함수로도 바인딩이 가능하다.
  - 실제 클래스의 주소로 접근하여 바인딩 하기에 public메서드로 강제되는 것 같다.
- `CourseInfo->OnChanged.AddLambda`
  - 람다로도 사용이 가능하다.
  - 이외에도 많은 듯
- `CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));`
  - 실제 Invoke하는 함수를 통해 호출한다.

**제일 중요한 점은 실제로 `Student`와 `CourseInfo`는 서로 헤더를 참조하지 않는다. 이는 느슨한 결합을 구현한 것이다.**

## 정리

- 느슨한 결합이 가지는 장점에 대해서 알아봄 향후 시스템 변경 사항에 대해 유연하게 대처 가능
- 느슨한 결합으로 구현된 발행 구독 모델의 장점
  - 클래스는 자신이 해야 할 작업에만 집중할 수 있다
  - 외부에서 발생한 변경 사항에 대해 영향을 받지 않음
  - 자신의 기능을 확장하더라도 다른 모듈에 영향을 주지 않음
- 언리얼 C++의 델리게이트 선언과 활용
  - 몇 개의 인자를 가지는가?
  - 어떤 방식으로 동작하는가?
  - 에디터와 연동할 것인가?
  - 위 사항들을 적절하게 조합하여 매크로를 선택

**데이터 기반의 디자인 패턴을 설계할 때 유용하게 사용된다.**
