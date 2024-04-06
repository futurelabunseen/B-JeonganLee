// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UGProjectileBulletBase.generated.h"

UCLASS()
class UGHPROJECT_API AUGProjectileBulletBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUGProjectileBulletBase();


protected:

	UPROPERTY(VisibleAnywhere, Category = "Bullet")
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Bullet")
	TObjectPtr<class UProjectileMovementComponent> Movement;

	UPROPERTY(VisibleAnywhere, Category = "Bullet")
	TObjectPtr<class UBoxComponent> Collision;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
