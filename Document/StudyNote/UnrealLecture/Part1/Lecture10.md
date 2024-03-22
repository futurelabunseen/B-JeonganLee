# 10강: 언리얼 컨테이너 라이브러리 I - Array와 Set

- 강의 목표
  - 언리얼 대표 컨테이너 라이브러리 TArray와 TSet을 이해한다.
  - 각 컨테이너 라이브러리의 장단점을 파악하고, 알맞게 활용하는 방법의 학습
- 강의 과제
  - 자료구조에서 해시테이블이 어떻게 동작하는지 설명하고, Bucket의 개념에 대해 설명하시오.
  - TSet의 자료는 TSparseArray자료구조를 기반으로 구축되어 있는데, TSparseArray의 Element는 다음으로 선언되어 있다. 이를 통해 TSet의 해시테이블은 어떻게 동작하는지 유추해보시오.  

## 언리얼 컨테이너 라이브러리

언리얼 엔진이 자체 제작해서 제공하는 라이브러리(UCL, Unreal Container Library)는 언리얼 오브젝트를 안정적으로 지원하며 다수의 오브젝트 처리에 유용하게 사용된다. 언리얼 C++은 다양한 자료구조 라이브러리를 직접 만들어 제공하고 있다. (`TArray`, `TSet`, `TMap`)

*접두사 `T`는 탬플릿 라이브러리를 의미한다.*

### C++ STL과 언리얼 컨테이너 라이브러리의 차이점

- C++ STL은 범용적으로 설계되어 있다.
- C++ STL은 표준이기 때문에 호환성이 높다.
- C++ STL에는 많은 기능이 엮여 있어 컴파일 시간이 오래 걸린다.
- 언리얼 컨테이너 라이브러리는 언리얼 엔진에 특화되어 있다.
- 언리얼 컨테이너 라이브러리는 언리얼 오브젝트 구조를 안정적으로 지원한다.
- 언리얼 컨테이너 라이브러리는 가볍고 게임 제작에 최적화되어 있다.

*쉽게 말해서 언리얼에서는 언리얼 컨테이너 라이브러리를 사용하는 것이 좋다.*

### 언리얼 C++ 주요 컨테이너 라이브러리

- 두 라이브러리의 이름과 용도는 유사하지만, 내부적으로는 다르게 구현되어 있다.
  - `TArray`: 오브젝트를 순서대로 담아 효율적으로 관리하는 용도
  - `TSet`: 중복되지 않는 요소로 구성된 집합을 만드는 용도
  - `TMap`: Key와 Value의 조합으로 레코드를 관리하는 용도

## TArray의 구조와 활용

### TArray 개요

`TArray`는 동적 배열의 자료구조로 STL의 `std::vector`와 유사하다. (C#은 `List<T>`와 유사) `TArray`는 동적 배열을 구현하며, 배열의 크기가 동적으로 변할 수 있다.

게임에서는 특히 가변 배열 자료구조를 효과적으로 활용하는 것이 좋으며 데이터가 순차적으로 모여있기 때문에 메모리를 효과적으로 사용할 수 있고 **캐시 효율이 높다**. 컴퓨터 사양이 좋아짐에 따라 캐시 지역성으로 인한 성능 향상은 굉장히 중요해짐, 임의 데이터의 접근이 빠르고, 고속으로 요소를 순회하는 것이 가능해진다.

가변 배열은 데이터를 추가하는 것은 가볍지만, **중간에 요소를 추가하거나 삭제하는 작업의 비용**이 크다. 데이터가 많아질 수록 검색, 삭제, 수정 작업이 느려지기 때문에, 많은 수의 데이터 검색 작업이 일어난다면, `TArray`대신에 `TSet`을 사용하는 것이 좋다.

### TArray의 내부 구조

- [공식문서](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/array-containers-in-unreal-engine?application_version=5.3)

같은 자료가 빈틈없이 메모리에 정렬되어 있다. 순차적으로 정렬되어 있기 때문에 한번에 인덱스를 참조하여 데이터를 가져올 수 있다.

- `TArray`는 값 유형이기에 동적할당을 하지 않는다. 따라서 소멸 자체는 멤버 변수나 스택에서 일어난다.
- 새로운 `TArray`을 통해 복사하게 되면 기본적으로 값이 복사되어 새로운 배열이 생성된다.
- 값을 채워 넣을 때는 `Add`와 `Emplace`를 사용한다. `Add`는 복사 생성자를 호출하고, `Emplace`는 생성자를 호출하지 않는다.
  - 따라서 `Emplace`가 더 빠르다.
- 다양한 내용이 공식문서에 있으니 필요할 때 찾아보기

### TArray 실습

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

void UMyGameInstance::Init()
{
 Super::Init();

 const int32 ArrayNum = 10;
 TArray<int32> Int32Array; // 현재 참조 변수만 선언되어 있고, 메모리는 할당되어 있지 않다.

 for (int32 i = 0; i < ArrayNum; ++i)
 {
  Int32Array.Add(i); // 메모리가 할당된다.
 }

 Int32Array.RemoveAll([](int32 Value) { return Value % 2 == 0; }); // 짝수를 제거한다. 람다

 Int32Array += {2, 4, 6, 8, 10}; // Operator+=를 사용하여 배열에 추가한다.

 TArray<int32> Int32ArrayCompare;
 int32 CArray[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
 Int32ArrayCompare.AddUninitialized(ArrayNum);
 FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, sizeof(int32) * ArrayNum); // 메모리 복사

 ensure(Int32Array == Int32ArrayCompare);

 // Algo
 int32 Sum = 0;
 for (const int32& Int32Elem : Int32Array)
 {
  Sum += Int32Elem;
 }

 ensure(Sum == 55);

 int32 SumByAlgo = Algo::Accumulate(Int32Array, 0); // Algo::Accumulate를 사용하여 배열의 합을 구한다.
 ensure(SumByAlgo == Sum);
}
```

## TSet의 구조와 활용

### TSet의 특징

STL의 Set과 언리얼 TSet의 비교

- STL Set의 특징
  - STL Set은 이진 트리로 구성되어 있어 정렬을 지원함
  - STL Set은 메모리 구성이 효율적이지 않음
  - STL Set은 모든 자료를 순회하는데 적합하지 않음
  - STL Set은 요소가 삭제될 때 균형을 위한 재구축이 일어날 수 있음
- 언리얼 TSet의 특징
  - TSet은 **해시 테이블 형태**로 키 데이터가 구축되어 있어 **빠른 검색이 가능**함
  - TSet은 **동적 배열의 행태**로 데이터가 모여있음
  - TSet의 데이터는 **빠르게 순회**할 수 있다.
  - TSet의 데이터는 **삭제해도 재구축이 일어나지 않음**
  - TSet의 자료에는 **비어있는 데이터가 있을 수 있음**

따라서 STL set과 언리얼 TSet의 활용 방법은 서로 다르기 때문에 주의할 것. TSet은 **중복 없는 데이터 집합**을 구축하는데 유용하게 사용할 수 있다.

### TSet의 내부 구조

- [공식문서](https://dev.epicgames.com/documentation/ko-kr/unreal-engine/set-containers-in-unreal-engine)

동적 가변 배열의 형태를 가지지만, 중간 중간 데이터가 빠져 있을 수 있다. 내부는 해쉬테이블 형태이기에 접근이 빠르고 비어있는 데이터부터 채워넣을 수 있다.

> TSet (세트)는 TMap (맵) 및 TMultiMap (멀티 맵)과 비슷하지만, 중요한 차이점이 있습니다: 독립된 키로 데이터 값을 연결하기 보다, TSet 는 데이터 값 자체를 키로 사용하며, 이 때 엘리먼트를 값을 평가하는 오버라이드 가능 함수를 사용합니다. TSet 는 엘리먼트 추가, 검색, 제거가 매우 빠릅니다 (고정비). 기본적으로 TSet 는 중복 키를 지원하지 않지만, 템플릿 파라미터로 사용할 수는 있습니다.

내부적으로 해시테이블 형태록 구성되어 있고 데이터 자체가 키를 가지기에 빠르다는 것을 의미힌다.

> TSet 는 순서가 중요치 않은 상황에서 고유 엘리먼트를 저장하는 데 사용되는 고속 컨테이너 클래스입니다

> TArray 와는 달리 TSet 엘리먼트의 메모리 내 상대 순서는 신뢰성이 있거나 안정적이지 않으며, 반복처리 결과도 처음 추가된 순서와 다르게 반환될 수 있습니다. 메모리에도 인접해서 놓이지 않을 수 있습니다. 세트의 데이터 구조는 희소 배열로, 엘리먼트 사이 간극을 효율적으로 지원하는 배열입니다. 세트에서 엘리먼트가 제거되면, 희소 배열에 간극이 나타납니다. 이 간극은 앞으로 추가되는 엘리먼트가 메꿉니다.

### 자료구조의 시간 복잡도 비교

| | TArray | TSet |
|---|---|---|
| 접근 | O(1) | O(1) |
| 검색 | O(n) | O(1) |
| 삽입 | O(n) | O(1) |
| 삭제 | O(n) | O(1) |

- `TArray`는 순차적이고, 빈틈이 없는 메모리, `TSet`은 빠른 중복을 감지할 수 있다.

## 정리

- TArray, TSet 컨테이너 라이브러리 내부 구조와 활용 방법
- 디버그 빌드를 사용해 메모리 정보를 확인하는 방법
  - 디버깅에서 좀 더 세부적으로 보고 싶다면 디버거 모드를 Game Editor로 변경하면 된다.
- 두 컨테이너 라이브러리가 가진 특징의 이해
