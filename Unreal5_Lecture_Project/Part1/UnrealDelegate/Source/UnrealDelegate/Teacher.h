// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LessonInterface.h"
#include "person.h"
#include "Teacher.generated.h"

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UTeacher : public Uperson, public ILessonInterface
{
	GENERATED_BODY()

public:
	UTeacher();

	virtual void DoLessson() override;
};
