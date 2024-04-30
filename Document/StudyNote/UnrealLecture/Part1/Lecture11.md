# 11강: 언리얼 컨테이너 라이브러리 II - 구조체와 Map

- 강의 목표
  - 언리얼 구조체의 선언과 특징 이해
  - 언리얼 대표 컨테이너 라이브러리 TMap의 내부 구조 이해
  - 세 컨테이너 라이브러리의 장단점을 파악하고, 알맞게 활용하는 방법의 학습
- 강의 과제
  - 현재 진행 중인 프로젝트에서 구조체, Array, Set, Map, MultiMap이 유용하게 활용될 수 있는 사례를 생각해보시오.  ( 전부 다 사용하지 않아도 좋음 )

## 언리얼 구조체

- [공식 문서](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/structs-in-unreal-engine?application_version=5.3)

> 구조체 는 멤버 프로퍼티를 체계화 및 조작할 수 있는 데이터 구조체입니다. 언리얼 엔진의 리플렉션 시스템은 구조체를 UStruct 로 인식하지만, 구조체는 UObject 생태계의 일부가 아니며, UClass 내부에서 사용됩니다.

데이터에 특화된 자료 형태로 데이터를 한 곳으로 모을 수 있다.

- UStruct 는 가비지 컬렉션이 UObject 를 제거하지 않도록 하기 위해 언리얼 엔진의 스마트 포인터 및 가비지 컬렉션 시스템을 사용할 수 있습니다.
- **구조체는 간단한 데이터 타입에 가장 적합합니다**. 프로젝트 내부에서 보다 복잡한 인터랙션을 하기 위해서는, 대신 UObject 또는 AActor 서브클래스를 만드는 것이 좋습니다.
- **UStructs 는 리플리케이션용으로 간주되지 않습니다**. 그러나 UProperty 변수는 리플리케이션용으로 간주 됩니다.
- 언리얼 엔진에는 구조체를 위한 생성　및 소멸 함수 자동 생성 기능이 있습니다.

*리플리케이션용으로 간주되지 않는 이유는 접두사 자체가 `F`로 지정되어 있기 때문에 엔진에서 일반 C++객체로 취급한다는 것이다.*

### 언리얼 구조체 UStruct

- 데이터 저장/전송에 특화된 가벼운 객체
- 대부분 `GENERATED_BODY()` 매크로로 선언
  - 따라서 리플렉션, 직렬화와 같은 유용한 기능을 사용할 수 있음
  - `GENERATED_BODY`를 선언한 구조체는 `UScriptStruct`클래스로 구현됨
  - 이 경우 제한적으로 리플렉션을 지원한다.
    - 속성 `UPROPERTY`만 선언할 수 있고, 함수 `UFUNCTION`은 사용할 수 없다. (언리얼 오브젝트와 차이점)
- 언리얼 엔진의 구조체 이름은 `F`로 시작함 (따라서 엔진에서 메모리 관리를 해주지 않는다.)
  - 대부분 힙 메모리 할당 없이 스택 내 데이터로 사용된다.
  - `NewObject`를 사용할 수 없음

### 언리얼 리플렉션 관련 계층 구조

![image](https://github.com/futurelabunseen/B-JeonganLee/assets/84510455/0c93c9f9-c2bb-438d-aefd-952944833199)

가장 한 눈에 들어오는 구조로 `UObject`아래로 `UField`가 있고 (`UObject`를 상속 받은), 그 아래로 `UStruct`와 `UEnum`이 있다. `UStruct`는 내부 컴포지션으로 `UFild`를 가지고 있는 구조로 활용되며 이를 상속받은 `UClass`가 있다. 이 외에도 `UScriptStruct`와 `UFuntion`이 있다. (둘다 `UStruct`를 상속받은 구조체)

`UClass`는 특이하게 내부 컴포지션으로 `UFunction`을 가지고 있어서 위에서 `UStruct`에서 사용할 수 없는 `UFunction`을 사용할 수 있다.

### 언리얼 구조체 실습

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

// 원래는 따로 헤더 파일을 만들어서 사용해야 하지만, 편의상 여기에 작성
USTRUCT()
struct FStudentData
{
 GENERATED_BODY()

 FStudentData()
 {
  Name = TEXT("홍길동");
  Order = -1;
 }

 FStudentData (FString InName, int32 InOrder) : Name(InName), Order(InOrder) {}

 // UPROPERTY()를 사용한다는 것은 리플렉션 기능이나
 // 블루프린트와 호환한다는 것으로 명확한 사용 목적이 있어야 함
 // But 언리얼 오브젝트 포인터를 멤버 변수로 가진다면 반드시 사용해야 함
 UPROPERTY() 
 FString Name;

 UPROPERTY()
 int32 Order;
};

UCLASS()
class UNREALCONTAINER_API UMyGameInstance : public UGameInstance
{
 GENERATED_BODY()

public:
 virtual void Init() override;

private:
 // 값 타입이기 때문에 UPROPERTY()를 사용하지 않아도 된다.
 TArray<FStudentData> StudentsData;
};
```

```cpp
#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
 TCHAR FirstChar[] = TEXT("김이박최");
 TCHAR MiddleChar[] = TEXT("상혜지성");
 TCHAR LastChar[] = TEXT("수은원연");

 TArray<TCHAR> RandArray;
 RandArray.SetNum(3);
 RandArray[0] = FirstChar[FMath::RandRange(0, 2)];
 RandArray[1] = MiddleChar[FMath::RandRange(0, 3)];
 RandArray[2] = LastChar[FMath::RandRange(0, 3)];
 
 // TArray는 TCHAR을 담고있는 배열이기에 해당 포인터를 반환하면 자동으로
 // FString으로 변환된다.
 return RandArray.GetData(); 
}

void UMyGameInstance::Init()
{
 // Struct
 const int32 StudentNum = 300;
 for (int32 i = 1; i <= StudentNum; ++i)
 {
  StudentsData.Emplace(FStudentData(MakeRandomName(), i));
 }

 TArray<FString> AllStudentsNames;
 Algo::Transform(StudentsData, AllStudentsNames, [](const FStudentData& StudentData) { return StudentData.Name; });

 UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수: %d"), AllStudentsNames.Num());

 TSet<FString> AllUniqueNames;
 Algo::Transform(StudentsData, AllUniqueNames, [](const FStudentData& StudentData) { return StudentData.Name; });
 
 UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수: %d"), AllUniqueNames.Num());
}
```

- `USTRUCT`를 붙여야 언리얼에서 사용 가능한 구조체로 인식한다.
  - `GENERATED_BODY()` 매크로를 사용하면 리플렉션 기능을 사용할 수 있다.
  - `UPROPERTY()`를 사용하면 리플렉션 기능을 사용할 수 있다. (구조체가 아닌 멤버 변수들이)
  - `UFUNCTION()`은 사용할 수 없다.
  - `F`로 시작하는 이름을 사용한다.
- `TArray<FStudentData> StudentsData;`
  - 값 타입으로 구조체를 배열에 넣어서 사용한다. UPROPERTY()를 사용하지 않아도 된다.
- `MakeRandomName` 함수는 랜덤한 이름을 생성하는 함수이다.
  - 마지막의 `GetData()`는 해당 포인터를 반환하기에 return과정에서 자동으로 `FString`으로 변환된다. (주소를 주기 때문에 실질적으로 동일하다.)
- `StudentsData.Emplace(FStudentData(MakeRandomName(), i));`
  - 구조체이기에 값 복사가 많이 일어나기에 `Emplace`를 사용한다.
  - `Algo::Transform(StudentsData, AllStudentsNames, [](const FStudentData& StudentData) { return StudentData.Name; });` 람다식을 사용하여 복사하는 과정을 줄인다.
  - `AllUniqueNames` 는 `TSet`을 사용하여 중복을 제거한다.

### 객체의 동적 배열 관리를 위한 예제

```cpp
UCLASS()
class UNREALCONTAINER_API UStudent : public UObject
{
 GENERATED_BODY()

 // 헤더에서 언리얼 오브젝트 포인터를 선언할 때는 반드시 TObjectPtr를 사용해야 한다.
 // 전방선언을 사용하여 UStudent 클래스를 가변 배열로 가진다.
 // 이렇게 TArray에서 포인터를 관리하게 된다면 언리얼에서 자동으로 메모리를 관리할 수 있도록
 // UPROPERTY()를 사용해야 한다. (필수적인)
 UPROPERTY()
 TArray<TObjectPtr<class UStudent>> Students;
};
```

구조체를 `TArray`로 관리하게 되는 경우에는 별도로 `UPROPERTY()`를 붙이거나 붙이지 않거나 이것은 자유롭게 선택할 수 있는 반면에 `TArray`에서 `UStudent` 언리얼 오브젝트를 관리할 때는 반드시 `UPROPERTY()`를 붙여야 한다.

## TMap의 구조와 활용

STL map과 TMap의 비교

- `STL map`의 특징
  - `STL map`은 `STL Set`과 동일하게 이진 트리로 구성되어 있다.
  - 정렬은 지원하지만, 메모리 구성이 효율적이지 않으며, 데이터 삭제시 재구축이 일어날 수 있다
  - 모든 자료를 순회하는데 적합하진 않다.
- 언리얼 `TMap`의 특징
  - 키, 밸류 구성의 튜플데이터의 **TSet 구조로 구현**되어 있음 (TSet과 동일하나 튜플의 형태의 차이만 있다.)
  - **해시 테이블 형태로 구축되어 있어 빠른 검색**이 가능하다.
  - **동적 배열의 형태로 데이터**가 모여있음
  - 데이터는 **빠르게 순회**할 수 있음
  - 데이터는 **삭제해도 재구축이 일어나지 않음**
  - **비어있는 데이터가 있을 수 있음**
  - `TMultiMap`을 사용하면 중복 데이터를 관리할 수 있음

동작원리 자체는 `STL unordered_map`과 유사하다. 키, 밸류 쌍이 필요한 자료구조에 광범위하게 사용된다.

### TMap의 내부 구조

- 공식 문서

> 언리얼 엔진 에서 TArray (배열) 다음으로 가장 자주 사용되는 컨테이너는 TMap (맵)입니다. TMap 이 TSet (세트)와 비슷한 점은 그 구조하 키 해시 기반이라는 점입니다. 그러나 TSet 와 달리 이 컨테이너는 데이터를 키-값 짝으로 (TPair<KeyType, ValueType>) 저장하며, 저장 및 불러올 때는 키만 사용합니다.

`TSet`과 동일하나 `TPair`라는 구조체로 키, 밸류를 관리한다.

### TMap의 활용

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

// 원래는 따로 헤더 파일을 만들어서 사용해야 하지만, 편의상 여기에 작성
USTRUCT()
struct FStudentData
{
 GENERATED_BODY()

 FStudentData()
 {
  Name = TEXT("홍길동");
  Order = -1;
 }

 FStudentData (FString InName, int32 InOrder) : Name(InName), Order(InOrder) {}

 bool operator==(const FStudentData& Other) const
 {
  return Order == Other.Order;
 }

 friend FORCEINLINE uint32 GetTypeHash(const FStudentData& StudentData)
 {
  return GetTypeHash(StudentData.Order);
 }

 // UPROPERTY()를 사용한다는 것은 리플렉션 기능이나
 // 블루프린트와 호환한다는 것으로 명확한 사용 목적이 있어야 함
 // But 언리얼 오브젝트 포인터를 멤버 변수로 가진다면 반드시 사용해야 함
 UPROPERTY() 
 FString Name;

 UPROPERTY()
 int32 Order;
};


UCLASS()
class UNREALCONTAINER_API UMyGameInstance : public UGameInstance
{
 GENERATED_BODY()

public:
 virtual void Init() override;

private:
 // 값 타입이기 때문에 UPROPERTY()를 사용하지 않아도 된다.
 TArray<FStudentData> StudentsData;

 // 키 타입이 int32이고 값 타입이 FString인 TMap
 // 내부에 값 타입만 있기 때문에 UPROPERTY()를 사용하지 않아도 된다.
 // 만약 언리얼 오브젝트 포인터를 값으로 가진다면 UPROPERTY()를 사용해야 한다.
 TMap<int32, FString> StudentMap;
};

```

```cpp
#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
 TCHAR FirstChar[] = TEXT("김이박최");
 TCHAR MiddleChar[] = TEXT("상혜지성");
 TCHAR LastChar[] = TEXT("수은원연");

 TArray<TCHAR> RandArray;
 RandArray.SetNum(3);
 RandArray[0] = FirstChar[FMath::RandRange(0, 2)];
 RandArray[1] = MiddleChar[FMath::RandRange(0, 3)];
 RandArray[2] = LastChar[FMath::RandRange(0, 3)];
 
 // TArray는 TCHAR을 담고있는 배열이기에 해당 포인터를 반환하면 자동으로
 // FString으로 변환된다.
 return RandArray.GetData(); 
}

void UMyGameInstance::Init()
{
 Super::Init();

 Algo::Transform(StudentsData, StudentMap, [](const FStudentData& StudentData) { return TPair<int32, FString>(StudentData.Order, StudentData.Name);});
 UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 레코드 수: %d"), StudentMap.Num());

 TMap<FString, int32> StudentsMapByUniqueName;
 Algo::Transform(StudentsData, StudentsMapByUniqueName, [](const FStudentData& StudentData) { return TPair<FString, int32>(StudentData.Name, StudentData.Order); });
 UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 레코드 수: %d"), StudentsMapByUniqueName.Num());

 TMultiMap<FString, int32> StudentMapByName;
 Algo::Transform(StudentsData, StudentMapByName, [](const FStudentData& StudentData) { return TPair<FString, int32>(StudentData.Name, StudentData.Order); });
 UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 레코드 수: %d"), StudentMapByName.Num());

 const FString TargetName(TEXT("이혜은"));
 TArray<int32> AllOrders;
 StudentMapByName.MultiFind(TargetName, AllOrders);

 UE_LOG(LogTemp, Log, TEXT("이름이 %s인 학생 수: %d"), *TargetName, AllOrders.Num());

 TSet<FStudentData> StudentSet;
 for (int32 i = 1; i <= StudentNum; ++i)
 {
  StudentSet.Emplace(FStudentData(MakeRandomName(), i));
 }
}
```

- `bool operator==(const FStudentData& Other) const` `TSet`과 `TMap`에서 사용하기 위한 연산자 오버로딩
  - 쉽게 유니티의 `IEquatable` 인터페이스와 같은 역할을 한다.
  - 사용자가 해당 구조체에서 비교할 함수 자체를 줘서 자율적으로 비교할 수 있도록 한다.
- `friend FORCEINLINE uint32 GetTypeHash(const FStudentData& StudentData)` `TSet`과 `TMap`에서 사용하기 위한 해시 함수
  - `GetTypeHash` 함수를 사용하여 해시값을 반환한다.
  - `FORCEINLINE`은 인라인 함수로 만들어주는 매크로이다.
  - 위와 같은 맥락이다.
- `TMap<int32, FString> StudentMap;`
  - Pair형태로 키, 밸류를 관리한다. `TMap<Pair<int32, FString>>`와 같다.

## 정리

- `TArray`, `TSet`, `TMap` 컨테이너 라이브러리 내부 구조와 활용 방법을 이해
- 언리얼 구조체의 선언 방법
- `TSet`과 `TMap`에서 언리얼 구조체를 사용하기 위해 필요한 함수의 선언과 구현 방법
