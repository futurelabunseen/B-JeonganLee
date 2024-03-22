// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Algo/Accumulate.h"

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
}
