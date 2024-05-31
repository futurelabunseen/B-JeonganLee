// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UGProjectile.generated.h"

UCLASS()
class UGHPROJECT_API AUGProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AUGProjectile();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true))
	float Range;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<class UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<class UShapeComponent> Collision;

protected:
	virtual void BeginPlay() override;
};
