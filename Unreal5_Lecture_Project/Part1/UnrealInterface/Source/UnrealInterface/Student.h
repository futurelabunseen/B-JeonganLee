// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LessonInterface.h"
#include "person.h"
#include "Student.generated.h"

/**
 * 
 */
UCLASS()
class UNREALINTERFACE_API UStudent : public Uperson, public ILessonInterface
{
	GENERATED_BODY()

public:
	UStudent();

	virtual void DoLessson() override;
};
