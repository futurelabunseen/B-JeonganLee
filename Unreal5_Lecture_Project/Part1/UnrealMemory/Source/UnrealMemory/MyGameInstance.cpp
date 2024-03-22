// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "Student.h"
#include "StudentManager.h"

void CheckUObjectIsValid(const UObject* Object, const FString& InTag)
{
	if (Object->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효한 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효하지 않은 언리얼 오브젝트"), *InTag);
	}
}

void CheckUObjectIsNull(const UObject* Object, const FString& InTag)
{
	if (nullptr == Object)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터가 아닌 언리얼 오브젝트"), *InTag);
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	NonPropStudent = NewObject<UStudent>();
	PropStudent = NewObject<UStudent>();

	NonPropStudents.Add(NewObject<UStudent>());
	PropStudents.Add(NewObject<UStudent>());

	StudentManager = new FStudentManager(NewObject<UStudent>());
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();

	// 널 포인터가 아니지만 유효하지 않은 상태이다. 댕글링 발생
	CheckUObjectIsNull(NonPropStudent, TEXT("NonPropStudent"));
	CheckUObjectIsValid(NonPropStudent, TEXT("NonPropStudent"));

	// 널 포인터가 아니지만 유효한 상태이다. 문제없음
	CheckUObjectIsNull(PropStudent, TEXT("PropStudent"));
	CheckUObjectIsValid(PropStudent, TEXT("PropStudent"));

	// ----------------------------------------------
	// TArray (컨테이너 안의 언리얼 오브젝트)
	// ----------------------------------------------

	// 널 포인터가 아니지만 유효하지 않은 상태이다. 댕글링 발생
	CheckUObjectIsNull(NonPropStudents[0], TEXT("NonPropStudents"));
	CheckUObjectIsValid(NonPropStudents[0], TEXT("NonPropStudents"));

	// 널 포인터가 아니지만 유효한 상태이다. 문제없음
	CheckUObjectIsNull(PropStudents[0], TEXT("PropStudents"));
	CheckUObjectIsValid(PropStudents[0], TEXT("PropStudents"));

	// ----------------------------------------------
	// 일반 객체 (일반 객체 안의 언리얼 오브젝트)
	// ----------------------------------------------
	
	const UStudent* StudentInManager = StudentManager->GetStudent();
	
	delete StudentManager;
	StudentManager = nullptr;

	// 마찬가지로 댕글링 포인터 문제 발생
	// but FGCObject를 상속받은 클래스에서 AddReferencedObjects를 구현하면 문제가 해결된다.
	CheckUObjectIsNull(StudentInManager, TEXT("StudentInManager"));
	CheckUObjectIsValid(StudentInManager, TEXT("StudentInManager"));
}
