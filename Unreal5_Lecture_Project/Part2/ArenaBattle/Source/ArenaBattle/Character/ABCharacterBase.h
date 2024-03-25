// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quater
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacterBase();

protected:
	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);

	UPROPERTY(EditAnywhere, Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterControlType, class UABCharacterControlData*> CharacterControlManager;

	// Combo Action Section
protected:

	// 둘다 블루프린트에서 설정할 수 있도록 열어둔 변수
	// 위는 몽타주, 아래는 데이터 에셋이다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UABComboActionData> ComboActionData;

	// 키에 바인딩 될 메서드
	void ProcessComboCommand();

	// 시작 그리고 종료에 각각 호출되는 메서드
	void ComboActionBegin();
	void ComboActionEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);

	// 타이머 발동 메소드와 입력이 들어왔는지 체크하는 함수
	void SetComboCheckTimer();
	void ComboCheck();
	
	// 콤보 Flag 변수
	int32 CurrentCombo = 0;
	// 언리얼 엔진 월드에서 제공하는 특정 타이머 기능을 사용할 수 있는 구조체
	FTimerHandle ComboTimerHandle; 
	bool HasNextComboCommand = false;
};
