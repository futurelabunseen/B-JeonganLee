// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
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
