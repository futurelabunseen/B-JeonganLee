// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Card.h"
#include "CourseInfo.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	// CDO가 아닌 런타임에 합성으록 가져감
	// CourseInfo가 서브 오브젝트로 등록되기 위해 Outer로 this를 전달 즉, GameInstance의 서브 오브젝트로 등록
	// 이렇게 코드로 컴포지션 관계를 만들 수 있는데, 이는 CDO가 아닌 런타임에 할당 하는 것이다.
	// 좀 더 나가아서 this가 아닌 다른 오브젝트의 서브 오브젝트로 등록할 수도 있다.
	CourseInfo = NewObject<UCourseInfo>(this); 

	UE_LOG(LogTemp, Log, TEXT("======================"));

	// but 이 오브젝트는 지역 변수로 선언되어 함수가 끝나면 메모리에서 해제되기에 outer를 등록할 필요가 없다.
	UStudent* Student1 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));
	UStudent* Student2 = NewObject<UStudent>();
	Student2->SetName(TEXT("학생2"));
	UStudent* Student3 = NewObject<UStudent>();
	Student3->SetName(TEXT("학생3"));

	// 가지고 있는 학사 정보 시스템의 델리게이트에 학생과 델리게이트와 같은 형식을 가진 함수를 바인딩
	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);

	CourseInfo->OnChanged.AddLambda([](const FString& School, const FString& NewCourseInfo)
	{
		UE_LOG(LogTemp, Log, TEXT("[Lambda] 학사 정보가 변경되었습니다. 학교: %s, 정보: %s"), *School, *NewCourseInfo);
	});

	// 학사 정보를 변경 내부에서 Invoke
	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));

	UE_LOG(LogTemp, Log, TEXT("======================"));
}
