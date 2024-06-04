// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/UGProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AUGProjectile::AUGProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = Collision;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AUGProjectile::OnMeshBeginOverlap);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AUGProjectile::OnCollisionBeginOverlap);
}


void AUGProjectile::BeginPlay()
{
	Super::BeginPlay();

	float InLifeTime = Range / ProjectileMovement->InitialSpeed;

	SetLifeSpan(InLifeTime);
}

void AUGProjectile::OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AUGProjectile::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("AUGProjectile::OnSheredBeginOverlap"));
}


