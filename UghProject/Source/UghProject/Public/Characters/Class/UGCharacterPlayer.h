// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
<<<<<<< HEAD:UghProject/Source/UghProject/Public/Characters/Class/UGCharacterPlayer.h
#include "InputActionValue.h"
#include "Characters/UGCharacterBase.h"
=======
#include "Character/UGCharacterBase.h"
>>>>>>> main:UghProject/Source/UghProject/Character/UGCharacterPlayer.h
#include "UGCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
<<<<<<< HEAD:UghProject/Source/UghProject/Public/Characters/Class/UGCharacterPlayer.h
class UGHPROJECT_API AUGCharacterPlayer : public AUGCharacterBase
=======
class UGHPROJECT_API AUGCharacterPlayer : public AUGCharacterBase, public IAbilitySystemInterface
>>>>>>> main:UghProject/Source/UghProject/Character/UGCharacterPlayer.h
{
	GENERATED_BODY()

public:
	AUGCharacterPlayer();
<<<<<<< HEAD:UghProject/Source/UghProject/Public/Characters/Class/UGCharacterPlayer.h
	
	virtual void PossessedBy(AController* NewController) override; // 빙의가 될 때 호출
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	FORCEINLINE class UAnimMontage* GetAttackMontage() const { return AttackMontage; }

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	
=======

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override; // 빙의가 될 때 호출
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class UAnimMontage* GetAttackMontage() const { return AttackMontage; }

protected:
>>>>>>> main:UghProject/Source/UghProject/Character/UGCharacterPlayer.h
	void SetupGASInputComponent();
	void GASInputPressed(int32 InputId);
	void GASInputReleased(int32 InputId);
	
protected:
<<<<<<< HEAD:UghProject/Source/UghProject/Public/Characters/Class/UGCharacterPlayer.h
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

<<<<<<<< HEAD:UghProject/Source/UghProject/Public/Characters/Class/UGCharacterPlayer.h
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> AttackMontage;

========
protected:
>>>>>>>> main:UghProject/Source/UghProject/Character/UGCharacterBase.h
	// Input
	protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;
<<<<<<<< HEAD:UghProject/Source/UghProject/Public/Characters/Class/UGCharacterPlayer.h
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;
========

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;

public:
	AUGCharacterBase();
>>>>>>>> main:UghProject/Source/UghProject/Character/UGCharacterBase.h

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:
	
=======
	UPROPERTY(EditAnywhere, Category = GAS)
	TObjectPtr<class UAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere, Category = GAS)
	TArray<TSubclassOf<class UGameplayAbility>> StartAbilities;

	UPROPERTY(EditAnywhere, Category = GAS)
	TMap<int32, TSubclassOf<class UGameplayAbility>> StartInputAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> AttackMontage;
>>>>>>> main:UghProject/Source/UghProject/Character/UGCharacterPlayer.h
};
