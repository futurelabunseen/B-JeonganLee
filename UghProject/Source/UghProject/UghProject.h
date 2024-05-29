// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUGAbilityInputID : uint8
{
	// 0 None
	None		UMETA(DisplayName = "None"),
	// 1 Confirm
	Confirm		UMETA(DisplayName = "Confirm"),
	// 2 Cancel
	Cancel		UMETA(DisplayName = "Cancel"),
	// 3 LMB
	Ability1	UMETA(DisplayName = "Ability1"),
	// 4 RMB
	Ability2	UMETA(DisplayName = "Ability2"),
	// ? Jump
	Jump		UMETA(DisplayName = "Jump"),
};