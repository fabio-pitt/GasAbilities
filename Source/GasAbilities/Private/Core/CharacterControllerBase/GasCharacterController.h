// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GasCharacterController.generated.h"

/**
 * AGasCharacterController is the Player Controller used for the main playable character in the project.
 * It is responsible for handling player input and **binding Ability inputs** to the 
 * Character's Gameplay Ability System (GAS). 
 * This controller manages the flow of commands and replication necessary for the player to utilize Abilities,
 * while also setting up the initial Player State and HUD for the GAS environment.
 */
UCLASS()
class GASABILITIES_API AGasCharacterController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGasCharacterController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
