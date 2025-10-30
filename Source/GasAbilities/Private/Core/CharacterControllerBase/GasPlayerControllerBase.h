// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GasPlayerControllerBase.generated.h"

class AGasCharacterBase;
struct FInputActionValue;

/**
 * AGasPlayerControllerBase is an **abstract** base class for Controllers used in the GAS project.
 * It provides the fundamental architecture for handling input, establishing necessary replication, 
 * and defining methods for future interaction with the Ability System Component (ASC). 
 * This class ensures a standardized starting point for all derived Player Controllers 
 * within the Gameplay Ability System framework.
 */
UCLASS()
class GASABILITIES_API AGasPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	// The Input Mapping Context that defines the input scheme for the character.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputMappingContext> CurrentMappingContext;

	// Reference to the current Gas Character Base controlled by this controller.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<AGasCharacterBase> CurrentCharacter;

	/// Declare input actions for movement and looking around

	// Input action for looking around
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> LookAction;

	// Input action for moving
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> MoveAction;

	// Input action for jumping
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GAS_Input, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> JumpAction;

public:
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	// Called when the controlled is possessing a pawn
	virtual void OnPossess(APawn* InPawn) override;

	/// Input actions handlers

	// Handler for Look action
	void Look(const FInputActionValue& Value);

	// Handler for Move action
	void Move(const FInputActionValue& Value);

	// Handler for Jump action start
	void JumpStart();

	// Handler for Jump action stop
	void JumpStop();
};
