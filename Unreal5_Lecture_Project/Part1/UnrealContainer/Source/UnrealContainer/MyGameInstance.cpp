// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
	TCHAR FirstChar[] = TEXT("김이박최");
	TCHAR MiddleChar[] = TEXT("상혜지성");
	TCHAR LastChar[] = TEXT("수은원연");

	TArray<TCHAR> RandArray;
	RandArray.SetNum(3);
	RandArray[0] = FirstChar[FMath::RandRange(0, 2)];
	RandArray[1] = MiddleChar[FMath::RandRange(0, 3)];
	RandArray[2] = LastChar[FMath::RandRange(0, 3)];
	
	// TArray는 TCHAR을 담고있는 배열이기에 해당 포인터를 반환하면 자동으로
	// FString으로 변환된다.
	return RandArray.GetData(); 
}

void UMyGameInstance::Init()
{
	Super::Init();

	const int32 ArrayNum = 10;
	TArray<int32> Int32Array; // 현재 참조 변수만 선언되어 있고, 메모리는 할당되어 있지 않다.

	for (int32 i = 0; i < ArrayNum; ++i)
	{
		Int32Array.Add(i); // 메모리가 할당된다.
	}

	Int32Array.RemoveAll([](int32 Value) { return Value % 2 == 0; }); // 짝수를 제거한다. 람다

	Int32Array += {2, 4, 6, 8, 10}; // Operator+=를 사용하여 배열에 추가한다.

	TArray<int32> Int32ArrayCompare;
	int32 CArray[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	Int32ArrayCompare.AddUninitialized(ArrayNum);
	FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, sizeof(int32) * ArrayNum); // 메모리 복사

	ensure(Int32Array == Int32ArrayCompare);

	// Algo
	int32 Sum = 0;
	for (const int32& Int32Elem : Int32Array)
	{
		Sum += Int32Elem;
	}

	ensure(Sum == 55);

	int32 SumByAlgo = Algo::Accumulate(Int32Array, 0); // Algo::Accumulate를 사용하여 배열의 합을 구한다.
	ensure(SumByAlgo == Sum);

	// TSet

	TSet<int32> Int32Set;
	for (int32 i = 0; i < ArrayNum; ++i)
	{
		Int32Set.Add(i);
	}

	Int32Set.Remove(2);
	Int32Set.Remove(4);
	Int32Set.Remove(6);
	Int32Set.Remove(8);
	Int32Set.Remove(10);
	Int32Set.Add(2);
	Int32Set.Add(4);
	Int32Set.Add(6);
	Int32Set.Add(8);
	Int32Set.Add(10);

	// Struct
	const int32 StudentNum = 300;
	for (int32 i = 1; i <= StudentNum; ++i)
	{
		StudentsData.Emplace(FStudentData(MakeRandomName(), i));
	}

	TArray<FString> AllStudentsNames;
	Algo::Transform(StudentsData, AllStudentsNames, [](const FStudentData& StudentData) { return StudentData.Name; });

	UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수: %d"), AllStudentsNames.Num());

	TSet<FString> AllUniqueNames;
	Algo::Transform(StudentsData, AllUniqueNames, [](const FStudentData& StudentData) { return StudentData.Name; });
	
	UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수: %d"), AllUniqueNames.Num());

	// TMap

	Algo::Transform(StudentsData, StudentMap, [](const FStudentData& StudentData) { return TPair<int32, FString>(StudentData.Order, StudentData.Name);});
	UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 레코드 수: %d"), StudentMap.Num());

	TMap<FString, int32> StudentsMapByUniqueName;
	Algo::Transform(StudentsData, StudentsMapByUniqueName, [](const FStudentData& StudentData) { return TPair<FString, int32>(StudentData.Name, StudentData.Order); });
	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 레코드 수: %d"), StudentsMapByUniqueName.Num());

	TMultiMap<FString, int32> StudentMapByName;
	Algo::Transform(StudentsData, StudentMapByName, [](const FStudentData& StudentData) { return TPair<FString, int32>(StudentData.Name, StudentData.Order); });
	UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 레코드 수: %d"), StudentMapByName.Num());

	const FString TargetName(TEXT("이혜은"));
	TArray<int32> AllOrders;
	StudentMapByName.MultiFind(TargetName, AllOrders);

	UE_LOG(LogTemp, Log, TEXT("이름이 %s인 학생 수: %d"), *TargetName, AllOrders.Num());

	TSet<FStudentData> StudentSet;
	for (int32 i = 1; i <= StudentNum; ++i)
	{
		StudentSet.Emplace(FStudentData(MakeRandomName(), i));
	}
}
