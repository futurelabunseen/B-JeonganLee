
#pragma once

#include "GameplayTagContainer.h"

#define UGTAG_ABILITY_JUMP FGameplayTag::RequestGameplayTag(FName("Ability.Jump"))
#define UGTAG_ABILITY1 FGameplayTag::RequestGameplayTag(FName("Ability.Skill.Ability1"))

#define UGTAG_EVENT_MONTAGE_ENDABILITY FGameplayTag::RequestGameplayTag(FName("Event.Montage.EndAbility"))
#define UGTAG_EVENT_MONTAGE_SPAWNPROJECTILE FGameplayTag::RequestGameplayTag(FName("Event.Montage.SpawnProjectile"))