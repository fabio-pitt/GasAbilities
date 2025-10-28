// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "GasAbilities/Public/Core/GasGameMode.h"

// Sets default values
AGasGameMode::AGasGameMode()
{
	// Set the default pawn class to our Blueprinted character
	// Note: Update the path to match the Blueprint location
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/BP_GasCharacter"));

	// If the Blueprint class is found, set it as the default pawn class
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
