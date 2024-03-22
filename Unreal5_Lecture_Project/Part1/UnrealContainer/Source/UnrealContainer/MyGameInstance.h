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

/**
 * 
 */
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
