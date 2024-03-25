// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
#include "Interface/ABAnimationAttackInterface.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		// 언리얼의 특징? 얽힌 상속 구조를 사용하여 Notify될 때 MeshComp의 Owner를 찾아서 IABAnimationAttackInterface를 구현한 객체를 찾아서 AttackHitCheck를 호출한다.
		IABAnimationAttackInterface* AttackPawn = Cast<IABAnimationAttackInterface>(MeshComp->GetOwner());

		if (AttackPawn)
		{
			AttackPawn->AttackHitCheck();
		}
	}
}
