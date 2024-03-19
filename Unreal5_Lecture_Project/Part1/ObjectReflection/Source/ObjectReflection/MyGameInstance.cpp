// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

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

	UStudent* Student = NewObject<UStudent>(); // UStudent 클래스의 객체를 생성한다.
	UTeacher* Teacher = NewObject<UTeacher>();
	Student->SetName(TEXT("학생1")); // Setter 함수를 통해 이름을 설정한다.
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 %s"), *Student->GetName()); // Getter 함수를 통해 이름을 출력한다.

	FString CurrentTeacherName;
	FString NewTeacherName = TEXT("이득우");
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name")); // 컴파일 타임에 선생님 클래스의 이름 프로퍼티를 찾는다.
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName); // NUll 아니라면 해당 프로퍼티를 해당 객체에서 찾아서 값을 전달해준다. (out)
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 %s"), *CurrentTeacherName); // Getter 함수를 통해 이름을 출력한다.

		NameProp->SetValue_InContainer(Teacher, &NewTeacherName); // 위와 같은 방식으로 리플렉션을 통해 접근한다.
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 %s"), *Teacher->GetName()); // 실제 값이 변경되었는지 확인
	}

	UE_LOG(LogTemp, Log, TEXT("========================="));

	Student->DoLesson(); // 기본 함수 호출

	UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson")); // 런타임에 선생님 클래스의 수업 함수를 찾는다.
	if (DoLessonFunc)
	{
		Teacher->ProcessEvent(DoLessonFunc, nullptr); // 해당 함수를 호출한다.
	}

	UE_LOG(LogTemp, Log, TEXT("========================="));
}
