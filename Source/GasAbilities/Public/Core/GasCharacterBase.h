// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GasCharacterBase.generated.h"

/**
 * AGasCharacterBase is an **abstract** base class for all playable Characters in the project.
 * It establishes the core functionality and component structure inherited by all derived characters, 
 * primarily serving as the owner for essential **GAS components** and attributes. 
 * This class provides the foundational architecture and replication setup for Characters, 
 * ensuring derived classes can seamlessly integrate the Gameplay Ability System.
 */
UCLASS(Abstract, NotBlueprintable)
class GASABILITIES_API AGasCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGasCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
