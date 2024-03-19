// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("========================="));

	UClass* ClassRuntime = GetClass(); // 런타임에 클래스 정보를 가져온다.
	UClass* ClassCompile = UMyGameInstance::StaticClass(); // 컴파일 시점에 클래스 정보를 가져온다.
	check(ClassRuntime == ClassRuntime); // 어서션함수로 두 클래스가 같은지 확인한다.

	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName()); // Check가 통과한다면 클래스 이름을 출력한다.

	SchoolName = TEXT("세종대학교");

	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName); // 학교 이름을 출력한다.
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값: %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName); // 기본값을 출력한다.
	
	UE_LOG(LogTemp, Log, TEXT("========================="));
}
