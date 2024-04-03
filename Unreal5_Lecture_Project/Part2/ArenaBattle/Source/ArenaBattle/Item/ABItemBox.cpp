// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ABItemBox.h"

#include "Components/BoxComponent.h"
#include "Interface/ABCharacterItemInterface.h"
#include "Particles/ParticleSystemComponent.h"
#include "Physics/ABCollision.h"

// Sets default values
AABItemBox::AABItemBox()
{
	// 서브오브젝트로 실제 객체 할당
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Effect"));

	// 계층구조 설정 (Root를 Trigger로)
	RootComponent = Trigger;
	Mesh->SetupAttachment(Trigger);
	Effect->SetupAttachment(Trigger);

	// 충돌 프로필 설정 (어떤 채널과 충돌할지, 엔진에 Collision에 정의되어 있음)
	// OnComponentBeginOverlap라는 콜리전에 이미 정의된 이벤트(델리게이트)에 사용할 함수를 바인딩
	// 이런 델리게이트는 블루프린트에도 사용할 수 있도록 다이나믹으로 선언되어 있다. 따라서 UFUNCTION()을 사용해야 한다.
	Trigger->SetCollisionProfileName(CPROFILE_ABTRIGGER);
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABItemBox::OnOverlapBegin);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BoxMeshRef(TEXT("/Script/Engine.StaticMesh'/Game/ArenaBattle/Environment/Props/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1'"));
	if (BoxMeshRef.Object)
	{
		Mesh->SetStaticMesh(BoxMeshRef.Object);
	}
	Mesh->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));
	Mesh->SetCollisionProfileName(TEXT("NoCollision"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> EffectRef(TEXT("/Script/Engine.ParticleSystem'/Game/ArenaBattle/Effect/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh'"));
	if (EffectRef.Object)
	{
		Effect->SetTemplate(EffectRef.Object);
		Effect->bAutoActivate = false;
	}
	Effect->OnSystemFinished.AddDynamic(this, &AABItemBox::OnEffectFinished); // 이벤트 바인딩은 위쪽으로 빼는게 더 바람직해 보임..
}

void AABItemBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	// 상자를 열었는데 현재 상자에 아이템이 없으면 꽝, 상자를 없앤다.
	if (nullptr == Item)
	{
		Destroy();
		return;
	}

	// 현재 상호작용한 액터가 IABCharacterItemInterface를 상속받았다면 아이템을 준다. 즉, 플레이어
	// 수정해야 하는 부분은 플레이어가 아니더라도 상자는 열리는 부분?
	IABCharacterItemInterface* OverlappingPawn = Cast<IABCharacterItemInterface>(OtherActor);
	if (OverlappingPawn)
	{
		OverlappingPawn->TakeItem(Item);
	}
	
	Effect->Activate(true);
	Mesh->SetHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AABItemBox::OnEffectFinished(UParticleSystemComponent* ParticleSystem)
{
	Destroy();
}


