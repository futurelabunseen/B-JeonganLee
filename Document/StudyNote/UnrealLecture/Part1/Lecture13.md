# 13강: 언리얼 오브젝트 관리 I - 직렬화

- 강의 목표
  - 언리얼 엔진이 제공하는 직렬화 기능의 이해
  - 언리얼 오브젝트를 직렬화하고 이를 저장하고 불러들이는 방법의 이해
- 강의 과제
  - 복잡한 Json 문자를 설계하고 이에 대응하는 UObject와 동기화시키는 예시를 구현하시오

## 언리얼 엔진의 직렬화

### 직렬화(Serialization)란?

직렬화란, 오브젝트나 연결된 오브젝트의 묶음(오브젝트 그래프)을 **바이트 스트림**으로 변환하는 과정이다. (복잡한 데이터를 일렬로 세우기 때문에 직렬화)

거꾸로 복구하는 과정도 포함해서 이를 **역직렬화(Deserialization)**라고 한다.

- **시리얼라이제이션(Serialization)**: 오브젝트 그래프에서 바이트 스트림으로 변환
- **디시리얼라이제이션(Deserialization)**: 바이트 스트림에서 오브젝트 그래프로 변환

이런 직렬화는 다음과 같은 장점을 지닌다.

- 현재 프로그램 **상태를 저장**하고 필요할 때 **데이터를 복원**할 수 있다. (게임의 저장시스템)
- 현재 **객체의 정보**를 클립보드에 복사하여 다른 프로그램에 전송이 가능하다.
- **네트워크를 통해** 현재 프로그램의 상태를 다른 컴퓨터에 복원할 수 있다. (게임의 멀티플레이)
- **데이터 압축**, **암호화**를 통해 데이터를 효율적이고 안전하게 보관할 수도 있다.

*이런 직렬화는 실제로 유니티에서 리플렉션과 함께 많이 사용되는 기술이다.*

### 직렬화 구현시 고려할 점

이러한 직렬화를 직접 구현할 경우 다양한 상황을 고려해야 함

- **데이터 레이아웃**: 오브젝트가 소유한 다양한 데이터를 변환할 것인가?
- **이식성**: 서로 다른 시스템에 전송해도 이식될 수 있는가?
- **버전 관리**: 새로운 기능이 추가될 때 이를 어떻게 확장하고 처리할 것인가?
- **성능**: 네트웍 비용을 줄이기 위해 어떤 데이터 형식을 사용할 것인가?
- **보안**: 데이터를 어떻게 안전하게 보호할 것인가?
- **에러 처리**: 전송 과정에서 문제가 발생할 경우 이를 어떻게 인식하고 처리할 것인가?

**이러한 상황을 모두 감안해 직렬화 모델을 만드는 것은 매우 어렵다.**

### 언리얼 엔진의 직렬화 시스템

언리얼 엔진은 이러한 상황을 모두 고려한 직렬화 시스템을 자체적으로 제공하고 있다.

- 직렬화 시스템을 위해 제공하는 클래스 `FArchive`와 연산자
  - 아카이브 클래스 `FArchive`: 직렬화를 위한 기본 클래스
  - 직렬화 연산자: `<<` 연산자를 오버로딩하여 직렬화를 수행 (Shift)
- 다양한 아카이브 클래스의 제공
  - 메모리 아카이브 (`FMemoryReader`, `FMemoryWriter`)
  - 파일 아카이브 (`FArchiveFileReaderGeneric`, `FArchiveFileWriterGeneric`)
  - 기타 언리얼 오브젝트와 관련된 아카이브 클래스 (`FArchiveUObject`)
- Json 직렬화 기능: 별도의 라이브러리를 통해 제공하고 있다.

### Json 직렬화

Json은 **JavaScript Object Notation**의 약자로, 데이터를 표현하기 위한 경량의 데이터 교환 형식이다. (보통 웹 환경에서 서버와 클라이언트 사이에 사용)

- Json 장점
  - 텍스트임에도 데이터 크기가 가볍다.
  - 읽기 편해서 데이터를 보고 이해할 수 있다.
  - 사실 상 웹 통신의 표준으로 널리 사용된다.
- Json 단점
  - 지원하는 타입이 몇 가지 안됨. (문자, 숫자, 불리언, 널, 배열, 오브젝트만 가능)
  - 텍스트 형식으로만 사용할 수 있다.

언리얼은 `Json`, `JosnUtilities` 라이브러리 활용

### Json 데이터 예씨

Json은 `{}`로 오브젝트 내 데이터를 키와 밸류 조합으로 표현한다. 배열은 `[]`로 표현하고 이외에는 문자열, 숫자, 불리언, 널을 표현한다.

```json
{
  "Name": "이정안",
  "Age": 42,
}
```

### 언리얼 스마트 포인터 라이브러리 개요

일반 `C++`오브젝트의 포인터 문제를 해결해주는 언리얼 엔진의 라이브러리이다.

- `TUniquePtr`: 유일한 포인터로 지정한 곳에서만 메모리를 관리하는 포인터
  - 특정 오브젝트에게 명확하게 해지 권한을 주고 싶은 경우
  - delete 구문 없이 함수 실행 후 자동으로 소멸시키고 싶을 때
- `TSharedPtr`: 더 이상 사용되지 않으면 자동으로 메모리를 해지하는 포인터
  - 여러 로직에서 할당된 오브젝트가 공유해서 사용되는 경우
  - 다른 함수로부터 할당된 오브젝트를 `Out`으로 받는 경우
- `TShardRef`: 공유 포인터와 동일하지만, 유효한 객체를 항상 보장받는 레퍼런스
  - 여러 로직에서 할당된 오브젝트가 공유해서 사용되는 경우
  - `Not Null`을 보장받으며 오브젝트를 편리하게 사용하고 싶은 경우

### 실습

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

struct FStudentData
{
 FStudentData () {}
 FStudentData(int32 InOrder, const FString& InName) : Order(InOrder), Name(InName) {}

 friend FArchive& operator<<(FArchive& Ar, FStudentData& InStudentData)
 {
  Ar << InStudentData.Order;
  Ar << InStudentData.Name;
  return Ar;
 }
 
 int32 Order = -1;
 FString Name = TEXT("홍길동");
};

/**
 * 
 */
UCLASS()
class UNREALSERIALIZATION_API UMyGameInstance : public UGameInstance
{
 GENERATED_BODY()

public:
 UMyGameInstance();

 virtual void Init() override;

private:

 TObjectPtr<class UStudent> StudentSrc;
};

```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "JsonObjectConverter.h"
#include "Student.h"

void PrintStudentInfo(const UStudent* InStudent, const FString& InTag)
{
 UE_LOG(LogTemp, Log, TEXT("[%s] 이름 %s 순번 %d"), *InTag, *InStudent->GetName(), InStudent->GetOrder());
}

UMyGameInstance::UMyGameInstance()
{
}

void UMyGameInstance::Init()
{
 Super::Init();

 FStudentData RawDataSrc(16, TEXT("이정안"));

 const FString SaveDir = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));
 UE_LOG(LogTemp, Log, TEXT("저장할 파일 폴더: %s"), *SaveDir);

 {
  const FString RawDataFileName("RawData.bin");
  FString RawDataAbsolutePath = FPaths::Combine(*SaveDir, *RawDataFileName);
  UE_LOG(LogTemp, Log, TEXT("저장할 파일 전체 경로: %s"), *RawDataAbsolutePath);
  FPaths::MakeStandardFilename(RawDataAbsolutePath);
  UE_LOG(LogTemp, Log, TEXT("변경할 파일 전체 경로: %s"), *RawDataAbsolutePath);

  FArchive* RawFileWriterAr = IFileManager::Get().CreateFileWriter(*RawDataAbsolutePath);
  if (RawFileWriterAr)
  {
   *RawFileWriterAr << RawDataSrc;
   RawFileWriterAr->Close();
   delete RawFileWriterAr;
   RawFileWriterAr = nullptr;
  }

  FStudentData RawDataDest;
  FArchive* RawFileReaderAr = IFileManager::Get().CreateFileReader(*RawDataAbsolutePath);
  if (RawFileReaderAr)
  {
   *RawFileReaderAr << RawDataDest;
   RawFileReaderAr->Close();
   delete RawFileReaderAr;
   RawFileReaderAr = nullptr;

   UE_LOG(LogTemp, Log, TEXT("[RawData]: 이름 %s 순번 %d"), *RawDataDest.Name, RawDataDest.Order);
  }
 }

 // Unreal Obj Serilization
 
 StudentSrc = NewObject<UStudent>();
 StudentSrc->SetOrder(42);
 StudentSrc->SetName("이정안");

 {
  const FString ObjectDataFileName(TEXT("ObjectData.bin"));
  FString ObjectDataAbsolutePath = FPaths::Combine(*SaveDir, *ObjectDataFileName);
  FPaths::MakeStandardFilename(ObjectDataAbsolutePath);

  // 직렬화를 위한 버퍼 (언리얼 형식)
  TArray<uint8> BufferArray;
  FMemoryWriter MemoryWriterAr(BufferArray);
  // 간단하게 Serialize 함수를 호출하여 직렬화를 수행한다.
  StudentSrc->Serialize(MemoryWriterAr);

  // 스마트 포인터 라이브러리를 사용하여 위에서 한 nullptr이나 delete를 대체한다.
  if (TUniquePtr<FArchive> FileWriterAr = TUniquePtr<FArchive>(IFileManager::Get().CreateFileWriter(*ObjectDataAbsolutePath)))
  {
   *FileWriterAr << BufferArray;
   FileWriterAr->Close();
  }

  TArray<uint8> BufferArrayFromFile;
  if (TUniquePtr<FArchive> FileReaderAr = TUniquePtr<FArchive>(IFileManager::Get().CreateFileReader(*ObjectDataAbsolutePath)))
  {
   // 컨텍스트로 읽기, 쓰기를 구분 / 오퍼레이터는 동일
   *FileReaderAr << BufferArrayFromFile;
   FileReaderAr->Close();
  }

  FMemoryReader MemoryReaderAr(BufferArrayFromFile);
  UStudent* StudentDest = NewObject<UStudent>();
  StudentDest->Serialize(MemoryReaderAr);
  PrintStudentInfo(StudentDest, TEXT("ObjectData"));
 }

 // Json
 {
  const FString JsonDataFileName(TEXT("StudentJsonData.txt"));
  FString JsonDataAbsolutePath = FPaths::Combine(*SaveDir, *JsonDataFileName);
  FPaths::MakeStandardFilename(JsonDataAbsolutePath);

  TSharedRef<FJsonObject> JsonObjectSrc = MakeShared<FJsonObject>();
  FJsonObjectConverter::UStructToJsonObject(StudentSrc->GetClass(), StudentSrc, JsonObjectSrc);
  
  FString JsonOutString;
  // null이 아님을 보장 (만들기 때문에, 있다면 접근)
  TSharedRef<TJsonWriter<TCHAR>> JsonWriterAr = TJsonWriterFactory<TCHAR>::Create(&JsonOutString);
  if (FJsonSerializer::Serialize(JsonObjectSrc, JsonWriterAr))
  {
   FFileHelper::SaveStringToFile(JsonOutString, *JsonDataAbsolutePath);
  }

  FString JsonInString;
  FFileHelper::LoadFileToString(JsonInString, *JsonDataAbsolutePath);

  TSharedRef<TJsonReader<TCHAR>> JsonReaderAr = TJsonReaderFactory<TCHAR>::Create(JsonInString);

  TSharedPtr<FJsonObject> JsonObjectDest;
  // but 읽어들어야 하기에 null이 될 수 있음 따라서 TSharedPtr로 받아야 함
  if (FJsonSerializer::Deserialize(JsonReaderAr, JsonObjectDest))
  {
   UStudent* JsonStudentDest = NewObject<UStudent>();
   if (FJsonObjectConverter::JsonObjectToUStruct(JsonObjectDest.ToSharedRef(), JsonStudentDest->GetClass(), JsonStudentDest))
   {
    PrintStudentInfo(JsonStudentDest, TEXT("JsonData"));
   }
  }
 }
}

```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Student.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSERIALIZATION_API UStudent : public UObject
{
 GENERATED_BODY()

public:
 UStudent();

 int32 GetOrder() const {return Order;}
 void SetOrder(int32 InOrder) {Order = InOrder;}

 const FString& GetName() const {return Name;}
 void SetName(const FString& InName) {Name = InName;}

 // 이미 구현이 되어 있는 Serialize 함수를 재정의한다.
 virtual void Serialize(FArchive& Ar) override;

private:

 UPROPERTY()
 int32 Order;

 UPROPERTY()
 FString Name;
};
```

```cpp
// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
 Order = -1;
 Name = TEXT("홍길동");
}

void UStudent::Serialize(FArchive& Ar)
{
 Super::Serialize(Ar);

 Ar << Order;
 Ar << Name;
}
```

- `FStudentData` 구조체를 정의하고 `FArchive` 연산자를 오버로딩하여 직렬화를 수행한다.
  - 내부 오퍼레이터를 통해 직렬화를 수행한다. (사용자 정의 구현)
- `FPaths::Combine` 함수를 사용하여 파일 경로를 결합한다.
  - 구조는 내부 폴더의 `Saved` 폴더에 저장한다.
  - 뒤에서도 해당 경로와 실제 파일의 이름을 결합하여 주소로 사용
- `FPaths::MakeStandardFilename` 함수를 사용하여 파일 경로를 정규화한다.
- `FArchive` 클래스를 사용하여 파일을 읽고 쓴다.
  - `IFileManager::Get().CreateFileWriter` 함수를 사용하여 파일을 쓰기 위한 아카이브를 생성한다.
  - `IFileManager::Get().CreateFileReader` 함수를 사용하여 파일을 읽기 위한 아카이브를 생성한다.
  - `<<` 연산자를 사용하여 직렬화를 수행한다.
  - 같은 과정처럼 보이지만 앞의 컨텍스트로 해석한다.
- `TArray<uint8>` 배열을 사용하여 메모리 버퍼를 생성한다.
  - `FMemoryWriter` 클래스를 사용하여 메모리 버퍼에 직렬화를 수행한다.
  - `FMemoryReader` 클래스를 사용하여 메모리 버퍼에서 역직렬화를 수행한다.
- `TUniquePtr` 스마트 포인터 라이브러리를 사용하여 위에서 한 nullptr이나 delete를 대체한다.
- `TSharedRef<FJsonObject>` 클래스를 사용하여 Json 오브젝트를 생성한다.
- `TSharedRef` 스마트 포인터로 null이 아님을 보장 (만들기 때문에, 있다면 접근)
- `TSharedPtr` 스마트 포인터로 null이 될 수 있음 따라서 TSharedPtr로 받아야 함
  - but 읽어들어야 하기에 null이 될 수 있음 따라서 TSharedPtr로 받아야 함

## 정리

- 언리얼 엔진이 제공하는 직렬화 시스템에 대한 이해
- `FArchive` 클래스를 활용한 메모리 아카이브와 파일 아카이브의 활용
- `JsonSerializer`를 사용한 `JSON`형식의 직렬화 기능의 활용
- 일반 `C++` 객체 관리를 위한 언리얼 스마트 포인터 라이브러리의 활용
