// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "GasCharacterController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Core/CharacterBase/GasCharacterBase.h"

// Setup input component
void AGasCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast the InputComponent to UEnhancedInputComponent for enhanced input handling
	const TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent
		= Cast<UEnhancedInputComponent>(this->InputComponent);

	// Bind input actions to their respective handlers
	if (EnhancedInputComponent)
	{
		// Look
		EnhancedInputComponent->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AGasCharacterController::Look);

		// Move
		EnhancedInputComponent->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &AGasCharacterController::Move);

		// The Jump action has two events: Started and Completed
		EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Started, this, &AGasCharacterController::JumpStart);
		EnhancedInputComponent->BindAction(JumpAction.Get(), ETriggerEvent::Completed, this, &AGasCharacterController::JumpStop);
	}
}

// Called when possessing a pawn
void AGasCharacterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Cast the possessed pawn to AGasCharacterBase and store the reference
	this->CurrentCharacter = Cast<AGasCharacterBase>(InPawn);

	// Get the enhanced input local player subsystem
	const TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputLocalPlayerSubsystem
		= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());

	// Add the current input mapping context to the input subsystem
	if (InputLocalPlayerSubsystem && CurrentMappingContext)
	{
		InputLocalPlayerSubsystem->AddMappingContext(this->CurrentMappingContext.Get(), 0);
	}
}

/// Input action handlers implementation

// Handle look input
void AGasCharacterController::Look(const FInputActionValue& Value)
{
	// Get the look axis vector from the input value
	const FVector2d LookAxisVector = Value.Get<FVector2d>();

	// Add yaw and pitch input to the current character's controller
	this->CurrentCharacter->AddControllerYawInput(LookAxisVector.X);
	this->CurrentCharacter->AddControllerPitchInput(LookAxisVector.Y);
}

// Handle move input
void AGasCharacterController::Move(const FInputActionValue& Value)
{
	// Get the movement vector from the input value
	const FVector2d MovementVector = Value.Get<FVector2d>();

	// Get the control rotation and isolate the yaw component
	const FRotator Rotation = this->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get the forward and right vectors based on the yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Add movement input in the forward and right directions
	this->CurrentCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);
	this->CurrentCharacter->AddMovementInput(RightDirection, MovementVector.X);
}

// Handle jump input start
void AGasCharacterController::JumpStart()
{
	this->CurrentCharacter->Jump();
}

// Handle jump input stop
void AGasCharacterController::JumpStop()
{
	this->CurrentCharacter->StopJumping();
}