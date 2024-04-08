// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/UGProjectileBulletBase.h"

#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Physics/UGCollision.h"

// Sets default values
AUGProjectileBulletBase::AUGProjectileBulletBase()
{
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	RootComponent = Collision;
	Mesh->SetupAttachment(Collision);
	Movement->SetUpdatedComponent(Collision);

	Collision->SetCollisionProfileName(CPROFILE_UGCAPSULE);
	Collision->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AUGProjectileBulletBase::OnOverlapBegin);

	Mesh->SetCollisionProfileName(TEXT("NoCollision"));

	Movement->UpdatedComponent = Collision;
	Movement->InitialSpeed = 3000.0f;
	Movement->MaxSpeed = 3000.0f;
	Movement->bRotationFollowsVelocity = true;
	Movement->bShouldBounce = false;
	Movement->ProjectileGravityScale = 0.0f;
}

void AUGProjectileBulletBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
}


