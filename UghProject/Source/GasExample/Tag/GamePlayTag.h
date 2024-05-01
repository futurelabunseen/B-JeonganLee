
#pragma once

#include "GameplayTagContainer.h"

#define ACTOR_ROTATE FGameplayTag::RequestGameplayTag(FName("Actor.Action.Rotate"))
#define ACTOR_ISROTATING FGameplayTag::RequestGameplayTag(FName("Actor.State.IsRotating"))