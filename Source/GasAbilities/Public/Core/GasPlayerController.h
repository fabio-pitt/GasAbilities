// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "Core/CharacterControllerBase/GasPlayerControllerBase.h"
#include "GasPlayerController.generated.h"

/**
 * AGasPlayerController is the concrete Player Controller implementation derived from AGasPlayerControllerBase.
 * It handles the full setup of player input and is specifically responsible for **binding input actions** * to the
 * Character's Gameplay Ability System (GAS). 
 * This class is the definitive link between player commands and the execution of Gameplay Abilities, 
 * managing the runtime input configuration required by GAS.
 */
UCLASS()
class GASABILITIES_API AGasPlayerController : public AGasPlayerControllerBase
{
	GENERATED_BODY()
};
