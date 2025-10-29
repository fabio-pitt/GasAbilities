// GasAbilities © 2025 Fabio Pittaccio. All Rights Reserved. Personal, non-commercial use only. See LICENSE and README for details.

#include "Core/CharacterBase/GasCharacterBase.h"

// Sets default values
AGasCharacterBase::AGasCharacterBase() :
	CameraArmComponent{nullptr},
	CameraComponent{nullptr}
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGasCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGasCharacterBase::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGasCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
