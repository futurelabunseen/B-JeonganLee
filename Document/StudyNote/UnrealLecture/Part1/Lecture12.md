# 12강: 언리얼 엔진의 메모리 관리

- 강의 목표
  - 언리얼 엔진의 메모리 관리 시스템의 이해
  - 안정적으로 언리얼 오브젝트 포인터를 관리하는 방법의 학습
- 강의 과제
  - C++ 언어에서 포인터 사용시 발생하는 문제점, 실수에 대해 정리하시오.
  - C++ STL에서 제공하는 스마트 포인터를 조사하고 이들의 장점에 대해 정리하시오

## 언리얼 엔진의 자동 메모리 관리

### C++ 언어 메모리 관리의 문제점

C++은 저수준으로 메모리 주소에 직접 접근하는 포인터를 사용해 오브젝트를 관리한다. 그러다보니 프로그래머가 직접 할당과 해지를 해야하는데, 이를 잘 지키지 못하는 경우 다양한 문제가 발생할 수 있다.

- 메모리 누수: 메모리를 할당했지만 해지하지 않아 메모리가 계속 쌓이는 현상(힙)
- 댕글링 포인터: 이미 해제해 무효화된 오브젝트의 주소를 가리키는 포인터
- 와일드 포인터: 값이 초기화되지 않아 엉뚱한 주소를 가리키는 포인터

위와 같이 잘못된 포인터 값은 다양한 문제를 일으키며, 한 번의 실수로 프로그램을 종료시키는 치명적인 문제로 이어진다. 이는 게임의 규모가 커질수록 더 복잡해지고 실수할 확률 또한 증가한다.

따라서 이후에 나온 객체지향 언어인 JAVA/C#은 가비지콜렉션을 도입하여 이러한 문제를 해결했다.

### 가비지 컬렉션 시스템

프로그램이 사용하지 않는 오브젝트를 자동으로 감지해 메모리를 회수하는 시스템이다. 동적으로 생성된 모든 오브젝트 정보를 모아둔 저장소를 사용해 사용되지 않는 메모리를 추적한다.

- 마크-스윕 방식의 가비지 컬렉션
  - 저장소에서 최초 검색을 시작하는 루트 오브젝트를 표기한다.
  - 루트 오브젝트가 참조하는 객체를 찾아 마크한다.
  - 마크된 객체로부터 다시 참조하는 객체를 찾아 마크하고 이를 계속 반복한다. (재귀)
  - 이제 저장소에는 마크된 객체와 마크되지 않은 갹체로 나뉜다.
  - GC가 저장소에서 마크되지 않은 객체들의 메모리를 회수한다.

### 언리얼 엔진의 가비지 컬렉션 시스템

언리얼 엔진은 마크-스윕 방식의 가비지컬렉션 시스템을 자체적으로 구축한다. 지정된 주기마다 몰아서 없애도록 설정되어 있는데, 기본 값은 60초로 설정되어 있다. 성능향상을 위해 병령 처리, 클러스터링과 같은 기능을 탑재했다.

*유니티는 C#기반으로 .NET 가비지 컬렉션을 사용한다. 내부 구현은 똑같은 마크-스윕 방식이다.*

### 가바지 컬렉션을 위한 객체 저장소

관리되는 모든 언리얼 오브젝트의 정보를 저장하는 전역 변수 `GUObjectArray`가 있다. 각 요소에는 `Flag`가 설정되어 있으며 이를 통해 가비지 컬렉션의 대상 여부를 판단한다.

- `Garbege`: 다른 언리얼 오브젝트로부터의 참조가 없어 회수 예정인 오브젝트
- `RootSet`: 다른 언리얼 오브젝트로부터 참조가 없어도 회수하지 않는 특별한 오브젝트

가비지 컬렉터는 `GUObjectArray`에 있는 플래그를 확인하여 빠르게 회수해야 할 오브젝트를 파악하고 메모리에서 제거함

### 가비지 컬렉터의 메모리 회수

가비지 컬렉터는 지정된 시간에 따라 주기적으로 메모리를 회수한다. `Garbege`플래그로 설정된 오브젝트를 파악하고 메모리를 안전하게 회수한다 이는 수동으로 설정하는 것이 아닌 시스템이 결정함

**한 번 생성된 언리얼 오브젝트는 바로 삭제가 불가능함.**

### 루트셋 플래그의 설정

만약에 런타임 내내 살아있어야 하는 중요한 언리얼 오브젝트가 있다면 `RootSet`플래그를 설정해야 한다. `AddToRoot()`함수를 사용하면 최초 탐색 목록으로 설정되며, 이는 메모리 회수로부터 보호받게 된다. `RemoveFromRoot()`함수를 사용하면 다시 일반 오브젝트로 돌아간다.

**콘텐츠와 관련된 오브젝트에는 권장하지 않음.**

### 언리얼 오브젝트를 통한 포인터 문제의 해결

- 메모리 누수 문제
  - 언리얼 오브젝트는 가비지 컬렉터를 통해 자동으로 해결
  - C++ 오브젝트는 직접 신경써야 함 (스마트 포인터 사용)
- 댕글링 포인터 문제
  - 언리얼 오브젝트는 이를 탐지하기 위한 함수를 제공함 `IsValid()`
  - C++ 오브젝트는 직접 신경써야 함 (스마트 포인터 사용)
- 와일드 포인터 문제
  - 언리얼 오브젝트에 UPROPERTY 속성을 지정하면 자동으로 nullptr로 초기화 해 줌
  - C++ 오브젝트의 포인터는 직접 nullptr로 초기화 할 것 (또는 스마트 포인터 사용)

### 회수되지 않는 언리얼 오브젝트

회수되지 않는 언리얼 오브젝트들은 언리얼 엔진 방식으로 참조를 설정한 언리얼 오브젝트이다. 먼저 `UPROPERTY`로 참조된 언리얼 오브젝트, `AddReferencedObject`람수를 통해 참조를 설정한 언리얼 오브젝트, `AddToRoot`함수로 루트셋에 추가된 언리얼 오브젝트 등이 있다.

정리하자면 언리얼 오브젝트 선언의 기본 원칙은 오브젝트 포인터는 가급적 UPROPERTY로 선언하고, 메모리는 가비지컬렉터가 자동으로 관리하도록 위임한다.

*그렇다면 C++의 장점이자 단점인 메모리 접근을 통해 게임의 성능을 올려야 하는 부분에선 어떨까?*

### 언리얼 오브젝트의 관리 원칙

- 생성된 언리얼 오브젝트를 유지하기 위해 레퍼런스 참조 방법을 설계할 것
  - 언리얼 오브젝트 내의 언리얼 오브젝트: **UPROPERTY 사용**
  - 일반 C++ 오브젝트 내의 언리얼 오브젝트: FGCObject 상속 후 `AddReferencedObject`함수 구현
- 생성된 언리얼 오브젝트는 강제로 지우려 하지 말 것
  - **참조를 끊는다는 생각**으로 설계할 것 (유니티와 동일하다.)
  - 가비지 컬렉터에게 회수를 재촉할 수는 있음
  - 콘텐츠 제작에서 Destroy()함수를 사용할 수 있으나 내부 동작은 동일함 (의미없음)

### 가비지 컬렉션 테스트 환경 제작

- 프로젝트 설정에서 가비지 컬렉션 GCCycle 시간을 3초로 단축 설정한다.
- 새로운 GameInstance의 두 함수를 오버라이드
  - Init: 애플리케이션 초기화 시 호출
  - Shutdown: 애플리케이션 종료 시 호출
- 테스트 시나리오
  - 플레이 버튼을 누를 때 Init함수에서 오브젝트를 생성하고
  - 3초 이상 대기해 가비지 컬렉션을 발동
  - 플레이 중지를 눌러 `Shutdown`함수에서 생성한 오브젝트의 유효성을 확인

### 실습

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class UNREALMEMORY_API UMyGameInstance : public UGameInstance
{
 GENERATED_BODY()

public:
 virtual void Init() override;
 virtual void Shutdown() override;

private:
 TObjectPtr<class UStudent> NonPropStudent;

 UPROPERTY()
 TObjectPtr<class UStudent> PropStudent;

 TArray<TObjectPtr<class UStudent>> NonPropStudents;

 UPROPERTY()
 TArray<TObjectPtr<class UStudent>> PropStudents;

 // 일반 객체이기에 UPROPERTY()를 사용할 수 없다.
 // 따라서 값을 보장할 수 없기에 nullptr로 초기화한다.
 class FStudentManager* StudentManager = nullptr; 
};
```

```cpp
#include "MyGameInstance.h"

#include "Student.h"
#include "StudentManager.h"

void CheckUObjectIsValid(const UObject* Object, const FString& InTag)
{
 if (Object->IsValidLowLevel())
 {
  UE_LOG(LogTemp, Log, TEXT("[%s] 유효한 언리얼 오브젝트"), *InTag);
 }
 else
 {
  UE_LOG(LogTemp, Log, TEXT("[%s] 유효하지 않은 언리얼 오브젝트"), *InTag);
 }
}

void CheckUObjectIsNull(const UObject* Object, const FString& InTag)
{
 if (nullptr == Object)
 {
  UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터 언리얼 오브젝트"), *InTag);
 }
 else
 {
  UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터가 아닌 언리얼 오브젝트"), *InTag);
 }
}

void UMyGameInstance::Init()
{
 Super::Init();

 NonPropStudent = NewObject<UStudent>();
 PropStudent = NewObject<UStudent>();

 NonPropStudents.Add(NewObject<UStudent>());
 PropStudents.Add(NewObject<UStudent>());

 StudentManager = new FStudentManager(NewObject<UStudent>());
}

void UMyGameInstance::Shutdown()
{
 Super::Shutdown();

 // 널 포인터가 아니지만 유효하지 않은 상태이다. 댕글링 발생
 CheckUObjectIsNull(NonPropStudent, TEXT("NonPropStudent"));
 CheckUObjectIsValid(NonPropStudent, TEXT("NonPropStudent"));

 // 널 포인터가 아니지만 유효한 상태이다. 문제없음
 CheckUObjectIsNull(PropStudent, TEXT("PropStudent"));
 CheckUObjectIsValid(PropStudent, TEXT("PropStudent"));

 // ----------------------------------------------
 // TArray (컨테이너 안의 언리얼 오브젝트)
 // ----------------------------------------------

 // 널 포인터가 아니지만 유효하지 않은 상태이다. 댕글링 발생
 CheckUObjectIsNull(NonPropStudents[0], TEXT("NonPropStudents"));
 CheckUObjectIsValid(NonPropStudents[0], TEXT("NonPropStudents"));

 // 널 포인터가 아니지만 유효한 상태이다. 문제없음
 CheckUObjectIsNull(PropStudents[0], TEXT("PropStudents"));
 CheckUObjectIsValid(PropStudents[0], TEXT("PropStudents"));

 // ----------------------------------------------
 // 일반 객체 (일반 객체 안의 언리얼 오브젝트)
 // ----------------------------------------------
 
 const UStudent* StudentInManager = StudentManager->GetStudent();
 
 delete StudentManager;
 StudentManager = nullptr;

 // 마찬가지로 댕글링 포인터 문제 발생
 // but FGCObject를 상속받은 클래스에서 AddReferencedObjects를 구현하면 문제가 해결된다.
 CheckUObjectIsNull(StudentInManager, TEXT("StudentInManager"));
 CheckUObjectIsValid(StudentInManager, TEXT("StudentInManager"));
}
```

```cpp
#pragma once

#include "CoreMinimal.h"

class UNREALMEMORY_API FStudentManager : public FGCObject
{
public:
 FStudentManager(class UStudent* InStudent) : SafeStudent(InStudent) {}
 
 virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
 virtual FString GetReferencerName() const override
 {
  return TEXT("FStudentManager");
 }

 const class UStudent* GetStudent() const { return SafeStudent; }
private:
 class UStudent* SafeStudent = nullptr;
};
```

```cpp
#include "StudentManager.h"

#include "Student.h"

void FStudentManager::AddReferencedObjects(FReferenceCollector& Collector)
{
 if (SafeStudent->IsValidLowLevel())
 {
  Collector.AddReferencedObject(SafeStudent);
 }
}
```

- `Init`, `Shutdown`함수를 오버라이드하여 언리얼 오브젝트를 생성하고 해제하는 코드를 작성한다.
  - 자동으로 `UGameInstance`에 의해 호출된다. (생성과 소멸)
- `TObjectPtr<class UStudent> NonPropStudent;`
  - 언리얼 오브젝트를 담기 위해 `TObjectPtr`를 사용한다.
  - 하지만 `UPROPERTY`로 선언하지 않았기에 가비지 컬렉터에 의해 회수된다.
- `TObjectPtr<class UStudent> PropStudent;`
  - `UPROPERTY`로 선언했기에 가비지 컬렉터에 의해 회수되지 않는다.
- `TArray<TObjectPtr<class UStudent>> NonPropStudents;`
  - `TArray`를 사용해 여러 개의 언리얼 오브젝트를 담는다.
  - `UPROPERTY`로 선언하지 않았기에 가비지 컬렉터에 의해 회수된다. (똑같음)
- `TArray<TObjectPtr<class UStudent>> PropStudents;`
  - `UPROPERTY`로 선언했기에 가비지 컬렉터에 의해 회수되지 않는다.
- `class FStudentManager* StudentManager = nullptr;`
  - 일반 C++ 오브젝트이기에 `UPROPERTY`를 사용할 수 없다.
  - 따라서 `nullptr`로 초기화한다.
  - 가비지 콜렉터에 의해 내부의 언리얼 오브젝트가 회수된다.
  - `FGCObject`를 상속받아 `AddReferencedObjects`함수를 구현하면 문제가 해결된다.

## 정리

- C++언어의 고질적인 문제인 포인터 문제의 이해
- 이를 해결하기 위한 가비지 콜렉션의 동작 원리의 이해와 설정 방법
- 다양한 상황에서 언리얼 오브젝트를 생성하고 메모리에 유지하는 방법의 이해
- 언리얼 오브젝트 포인터를 선언하는 코딩 규칙의 이해
