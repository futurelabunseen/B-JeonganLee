// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"
#include "Card.h"

UTeacher::UTeacher()
{
	Name = TEXT("이선생");
	Card->SetCardType(ECardType::Teacher);
}

void UTeacher::DoLessson()
{
	//ILessonInterface::DoLessson(); // 인터페이스에 구현된 베이스 함수 호출
	UE_LOG(LogTemp, Log, TEXT("%s님은 가르칩니다."), *Name);
}
