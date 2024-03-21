// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Staff.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("======================"));
	TArray<Uperson*> Persons = {NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>()};
	for(const auto Person : Persons)
	{
		UE_LOG(LogTemp, Log, TEXT("구성원 이름: %s"), *Person->GetName());
	}
	UE_LOG(LogTemp, Log, TEXT("======================"));

	for(const auto Person : Persons)
	{
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if(LessonInterface)
		{
			LessonInterface->DoLessson();
		}
	}
	UE_LOG(LogTemp, Log, TEXT("======================"));
}
