// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Student.generated.h"

/**
 * 
 */
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
