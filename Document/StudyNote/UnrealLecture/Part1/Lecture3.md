# 3강: 언리얼 C++ 기본타입과 문자열

- 강의 목표
  - 언리얼 C++의 기본 타입과 문자열 다루는 방법 이해 ( int32, FString )
  - 언리얼 환경에서 알아두어야 할 기본 타입과 고려할 점
  - 캐릭터 인코딩 시스템에 대한 이해
  - 언리얼 C++이 제공하는 다양한 문자열 처리 방법과 내부 구성의 이해
- 강의 과제
  - ANSI, ASCII, EUC-KR, CP949, UTF-8 BOM, UTF-8, UTF-16에 대해 정리하시오
  - Little Endian, Big Endian에 대해서도 정리하시오.  언제 어떤 경우에 리틀 엔디안과 빅 엔디안이 사용되는지 조사해보시오.
  - TCHAR 배열, FString, FCString의 관계와 각각의 쓰임새에 대해 자신의 생각을 정리해보세오. 그림으로 설명하면 더 좋습니다.
  - FName은 어떤 경우에 유용하게 쓰일지 자신의 생각을 정리해보세오.
  - 실수를 문자열로 변환할 때 왜 FromFloat이 아닌 SanitizeFloat이라는 함수 명을 지었는지 F12키를 눌러 소스코드를 보면서 간략하게 설명하시오. ( 선택 )

- [작업 Issue](https://github.com/futurelabunseen/B-JeonganLee/issues/12)
- [실습 프로젝트]()

## 왜 언리얼은 기본 타입을 따로 지정하는가?

기본적으로 언리얼은 `C++`의 기본 타입을 사용하지 않는다. 그 이유는 `C++`가 굉장히 오래전에 개발된 언어라 플랫폼의 파편화가 발생하였다. (당시엔 크로스 플랫폼을 지원하지 않았다.)

`C++`최신 규약에서 int는 최소 32비트를 보장하도록 규정되어 있지만 특정 플랫폼에서는 64비트로 해석될 수 있다. 따라서 게임과 같이 퍼포먼스를 최대로 끌어내야 하는 소프트웨어의 입장에선 명확하지 않은 데이터 타입이 문제가 될 수 있다.

`int`라는 데이터 타입이 아닌 `int32`라는 데이터 타입을 사용함으로써 플랫폼에 상관없이 32비트로 해석되도록 보장할 수 있다.

[포팅 가능한 C++코드 관련](https://github.com/futurelabunseen/B-JeonganLee/blob/main/Document/StudyNote/UnrealLecture/Part1/Lecture2.md#%ED%8F%AC%ED%84%B0%EB%B8%94-c-%EC%BD%94%EB%93%9C)

### bool 타입의 선언

bool타입 자체가 크기가 명시되어 있지 않기에 사용할 때는 `uint8`을 사용하여 데이터를 저장하는데, 참/거짓의 정보만 저장하기에 비효율적이다. 따라서 `Bit Field`를 사용하여 제한을 둔다. 또한 사용할 때 접두사로 `b`를 붙여 사용한다.

```cpp
uint8 bIsDead : 1;
```

## 캐릭터 인코딩

### 왜 언리얼은 문자열을 따로 지정하는가?

영어의 경우 1byte로 충분히 표현이 가능하지만 동아시아의 언어들은 1byte로 표현이 불가능하다. 현재는 유니코드를 지원하지만, 그 전에 윈도우 운영체제가 보급됨에 따라 멀티바이트 문자열, 유니코드 문자열이 혼재되어 사용되었다. (싱글 바이트 문자열까지)

따라서 이러한 문제를 해결하기 위해 언리얼에선 TCHAR라는 타입을 사용한다.

- [언리얼 캐릭터 인코딩 공식문서](https://docs.unrealengine.com/5.3/ko/character-encoding-in-unreal-engine/)

#### UTF-8 의 경우

UTF-8은 가변 길이 문자 인코딩 방식으로, 영문권의 경우 1byte로 표현이 가능하다. 하지만 동아시아의 경우 3byte로 표현이 가능하다. 이 과정이 각 지역별로 처리된다.

- 장점이자 단점인 언어마다 다른 바이트를 사용한다는 것

#### UTF-16 의 경우

통일된 길이의 문자 인코딩 방식으로, 모든 문자를 2byte로 표현이 가능하다. 정렬된 데이터를 처리하지만, 메모리르 더 사용한다.

#### UE 내부 스트링 표현

언리얼 엔진의 모든 스트링은 FStrings 혹은 TCHAR 정렬 상태로 **UTF-16** 포맷 메모리에 저장됩니다. 대부분의 코드에서 2 바이트가 하나의 코드포인트라 가정하므로, 언리얼의 내부 인코딩이 UCS-2 로 보다 정확히 설명될 수 있도록 Basic Multilingual Plane(BMP) 만 지원됩니다. 스트링은 현 플랫폼에 적합한 엔디안에 저장됩니다.

즉, UTF-16

#### UE에 로드되는 텍스트 파일

이 함수는 UTF-16 파일에서 유니코드 바이트-오더-마크(byte-order-mark, BOM)를 인식하고, 있으면 어느 엔디안으로든 UTF-16 으로 파일을 로드합니다. (기본적으로 UTF-16으로 로드함)

#### 동아시아 인코딩 고유의 C++ 소스 코드에 대해서

UTF-8 와 디폴트 Windows 인코딩 모두 C++ 컴파일러와 관련해서 다음과 같은 문제를 야기할 수 있습니다:

- 이 동아시아 캐릭터 인코딩 시스템에서는 첫째 바이트에 0x81-0xFE 를, 그리고 둘째 바이트에 0x40-0xFE 를 사용합니다. 둘째 바이트에서 0x5C 의 값은 ASCII/latin-1 에서 백슬래시로 해석되는데, 이게 C++ 에 있어 특별한 의미를 지닙니다 (스트링을 그대로 쓰는 것에서의 이스케이프 시퀀스이고, 줄 끝에 사용되면 줄 연속입니다). 그러한 소스 코드를 1 바이트 코드 페이지 Windows에서 컴파일 할 때, 컴파일러는 동아시아 2 바이트 캐릭터 인코딩에 대해선 신경을 쓰지 않는 바, 이것은 컴파일 오류, 혹은 EXE 에 버그가 생기는 등 더 심각한 문제를 야기할 수 있습니다.
- BOM 없는 UTF-8 (BOM 을 시그니쳐로 서술하는 텍스트 에디터도 있습니다.)

#### 결론

언리얼은 자체적으로 스트링을 관리하는데, UTF-16을 사용한다. 소스코드에 한글이 들어간다면 UTF-8로 저장하라 (이 부분은 문제가 발생할 수 있다.)

## TCHAR 와 FString 실습

```cpp
#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	const TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, LogCharArray);
}
```

- 1강에서 실습한 내용과 같지만 조금은 다른 점은 `UE_LOG`의 메서드가 전에는 `%s`로 VA_ARGS를 받았지만, TCHAR자체의 배열로 넘겨주기 위해선 해당 배열 자체가 const로 선언되어야 한다는 부분이 강의와 조금은 달랐다.
- 또한 언리얼 버전이 달라지면서 이를 지원하는 방식이 달라져 오류가 난다.
- [오류 링크](https://www.inflearn.com/questions/938125/ue-log%EC%97%90-%EB%B9%A8%EA%B0%84-%EB%B0%91%EC%A4%84%EC%9D%B4-%EC%83%9D%EA%B2%A8%EC%9A%94)

```cpp
void UMyGameInstance::Init()
{
	Super::Init();

	TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, TEXT("LogCharArray: %s"), LogCharArray);

	const FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("LogCharString: %s"), *LogCharString);
}
```

- TCHAR 배열을 FString으로 변환하는 방법은 `FString`의 생성자를 이용하면 된다. (값복사가 이뤄짐)
- 사용하기 위해선 해당 배열을 `*`로 포인터로 변환해야 한다.

### 복잡한 문자열 처리를 하나로

유니코드를 사용해 문자열 처리를 통일한데 이 중에서 2Byte로 사이즈가 균일한 UTF-16을 사용하고 있다. (TCHAR) 또한 문자열은 언제나 **TEXT매크로**를 사용해 지정한다. 이 매크로는 문자열을 TCHAR배열로 변환해주는 역할을 한다. 추가로 문자열을 다루는 클래스로 FString이 있다. (TCHAR배열을 포함하는 헬퍼클래스의 개념)

### FString

- [FString 공식문서](https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/StringHandling/FString/)

FName 이나 FText 와는 달리, FString 은 조작이 가능한 유일한 스트링 클래스입니다. 대소문자 변환, 부분문자열 발췌, 역순 등 사용가능한 메서드는 많습니다. FString 은 검색, 변경에 다른 스트링과의 비교도 가능합니다. 그러나 바로 그것이 FString 이 다른 불변의 스트링 클래스보다 비싸지는 이유입니다.

- `Tostring`도 지원
- 다른 타입에서 FString으로의 변환
  - `FString::Printf`
  - `FString::SanitizeFloat`
  - `FString::FromInt`

TCHAR 배열을 FString으로 변환하는 과정은 언이렁 내부의 `TArray`라고 하는 동적 배열로 변환되어 문자열을 보관한다. 포인터로 접근하여 문자열을 변경할 수 있다.

실질적으로 문자열을 자르거나 합치는 등의 작업을 할 때는 `FCString`을 사용한다.

- `FCString::Atoi`
- `FCString::Atof`

### FString 추가 실습

```cpp
	const TCHAR* LongCharPtr = *LogCharString;
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData();
```

- `GetCharArray`를 사용하여 `TArray`로 변환하여 `GetData`를 사용하여 포인터로 변환한다.
  - TCHAR 포인터로 접근하여 문자열을 변경할 수 있다.
- `*`를 사용하여 TCHAR 포인터로 변환한다.
  - `const`로 받아야 한다.

```cpp
	// 다시 배열로 복사
	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);
```

- FString의 값을 다시 TCHAR 배열로 복사하는 과정이다. `FCString::Strcpy`를 사용하여 복사한다. (저수준)

```cpp
	if(LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString EndString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("Find Test: %s"), *EndString);
	}
```

- `Contains`를 사용하여 문자열이 포함되어 있는지 확인한다. (FString 클래스의 메서드)
- `Find`를 사용하여 문자열의 위치를 찾는다. (FString 클래스의 메서드)
- `Mid`를 사용하여 문자열을 자른다. (FString 클래스의 메서드)

```cpp
	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Split Test: %s 와 %s"), *Left, *Right);
	}
```

- `Split`을 사용하여 문자열을 나눈다. (FString 클래스의 메서드)
  - `&`를 사용하여 참조로 받아야 한다. (오버로딩에 맞게 사용 가능)

```cpp
	int32 IntValue = 32;
	float FloatValue = 3.141592;

	FString FloatIntString = FString::Printf(TEXT("Int:%d Float:%f"), IntValue, FloatValue);
	FString FloatString = FString::SanitizeFloat(FloatValue);
	FString IntString = FString::FromInt(IntValue);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int: %s Float: %s"), *IntString, *FloatString);
```

- `FString::Printf`를 사용하여 문자열을 생성한다. (포맷팅 가능)
- `FString::SanitizeFloat`를 사용하여 실수를 문자열로 변환한다.
- `FString::FromInt`를 사용하여 정수를 문자열로 변환한다.

```cpp
	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	FloatIntString = FString::Printf(TEXT("Int: %d Float: %f"), IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
```

- `FCString::Atoi`를 사용하여 문자열을 정수로 변환한다.
- `FCString::Atof`를 사용하여 문자열을 실수로 변환한다.

## FName

- [FName 공식문서](https://docs.unrealengine.com/5.3/ko/fname-in-unreal-engine/)

- `FName`은 에셋 관리를 위해 사용되는 문자열 체계
  - 대수문자 구분 없음
  - 한번 선언되면 바꿀 수 없음 (Read-Only)
  - 가볍고 빠름
  - 문자를 표현하는 용도가 아닌 에셋 키를 저장하기 위해 사용 (해시값으로 변환되어 빠름)
- `FText`은 다국어 지원을 위한 문자열 관리 체계
  - 일종의 키로 작용함
  - 별도의 문자열 테이블 정보가 추가로 요구됨
  - 게임 빌드 시 자동으로 다양한 국가별 언어로 변환됨
  - Localization기능을 쉽게 사용하게 해준다?

### FName의 구조와 활용

FName과 관련된 글로벌 Pool 자료구조를 가지고 있다. 문자열이 들어오면 해시 값을 추출해서 키를 생성하고 FName에서 보관 (Pool)한다. 이후 FName값에 저장된 값을 사용해 전역 Pool에서 원하는 값을 찾아서 사용한다.

즉, 에셋의 빠른 조회를 위해 싱글톤으로 Pooling하여 사용한다. 실제 Key는 해시값이 저장되고 실제 문자열은 value에 저장된다.

FindOrAdd만 수행하기에 자료의 불변성을 보장하며, 빠른 조회를 위해 사용한다. (실제 조회할 때 FName은 해당 문자열만 들고 들어가 해시값읕 통해 조회한 후 없으면 추가하고 있다면 문자열을 반환한다.)

```cpp
	FName Key1(TEXT("PELVIS"));
	FName key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), Key1 == key2 ? TEXT("같음") : TEXT("다름"));
```

- 대소문자 구분이 없다.

```cpp
  FName Key3(TEXT("PELVIS"));
  FName Key4(TEXT("PELVIS"));
  UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), Key3 == Key4 ? TEXT("같음") : TEXT("다름"));

  // 같음이라는 결과 출력
```

- 대소문자 구분이 없음을 알 수 있다.

```cpp
	for (int i = 0; i < 10000; i++)
	{
		FName SearchInNamePool = FName(TEXT("pelvis"));
		const static FName StaticOnlyOnce(TEXT("pelvis"));
	}
```

- 반목문안에서`FName(TEXT("pelvis"));`의 사용은 불필요하다. (해시값을 찾아서 사용하기에) 오버헤드가 발생한다.
- `const static`으로 선언하여 한번만 사용하도록 한다.

## 정리

- 언리얼이 `C++`타입의 `int`를 사용하지 않는 이유
  - 플랫폼에 따라 다르게 해석될 수 있기 때문에
- 다양한 캐릭터 인코딩 시스템의 이해
  - UTF-8, UTF-16 등 실제 적용 사례
- 언리얼의 문자열 처리의 이해
  - TCHAR, FString, FCString, FName의 관계와 각각의 쓰임새
