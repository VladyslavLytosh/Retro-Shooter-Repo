// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharacter.h"
#include "RetroShooterWeapon/Public/BaseWeapon.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"





void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetupWeapons();
}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
#pragma region Main movement inputs

	PlayerInputComponent->BindAxis(TEXT("MoveForward/MoveBackwards"), this, &APlayableCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveLeft/MoveRight"), this, &APlayableCharacter::SideMove);

	PlayerInputComponent->BindAxis(TEXT("LookUp/LookDown"), this, &APlayableCharacter::MouseInputUpAndDown);
	PlayerInputComponent->BindAxis(TEXT("LookRight/LookLeft"), this, &APlayableCharacter::MouseInputLeftAndRight);

	/* Jump mechanic, very simple using character movement component */
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlayableCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &APlayableCharacter::StopJumping);

	/* Weapon switch input */
	PlayerInputComponent->BindAction(TEXT("WeaponSwitch"), IE_Pressed, this, &APlayableCharacter::WeaponSwitch);

	/* Fire inputs */
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayableCharacter::FireCurrentWeapon);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &APlayableCharacter::StopFireCurrentWeapon);

	/* Reload input */
	PlayerInputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &APlayableCharacter::ReloadCurrentWeapon);
#pragma endregion
}


#pragma region Input Functions

void APlayableCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);

}

void APlayableCharacter::SideMove(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}


void APlayableCharacter::MouseInputUpAndDown(float AxisValue)
{
	AddControllerPitchInput(AxisValue * Sensitivity);
	
}

void APlayableCharacter::MouseInputLeftAndRight(float AxisValue)
{
	AddControllerYawInput(AxisValue * Sensitivity);
}
	
	// When we press weapon switch button our current weapon destroy and spawn next one
void APlayableCharacter::WeaponSwitch()
{
	if (CurrentWeapon && CurrentWeapon->GetIsReloading())
	{
		return;
	}
	if (CurrentWeapon)
	{
		CurrentWeapon->DisableActor(true, false);
	}
	if (CurrentWeaponNumber == CurrentWeaponInventory.Num())
	{
		CurrentWeaponNumber = 0;
	}
	CurrentWeapon = CurrentWeaponInventory[CurrentWeaponNumber];
	CurrentWeapon->DisableActor(false, true);
	CurrentWeaponNumber++;
	
}

/* Fire input functions */
void APlayableCharacter::FireCurrentWeapon()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Fire();
	}
}

void APlayableCharacter::StopFireCurrentWeapon()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFire();
	}
}

/* Reload input function */
void APlayableCharacter::ReloadCurrentWeapon()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Reload();
	}
}  

#pragma endregion

void APlayableCharacter::SetupWeapons()
{
	for (auto Weapon : WeaponInventory)
	{
		ABaseWeapon* AttachedWeapon = GetWorld()->SpawnActor<ABaseWeapon>(Weapon, GetActorLocation(), GetActorRotation());
		AttachedWeapon->SetOwner(this);
		USceneComponent* Camera = Cast<USceneComponent>(GetComponentByClass(UCameraComponent::StaticClass()));
		AttachedWeapon->AttachToComponent(Camera, FAttachmentTransformRules::SnapToTargetIncludingScale);
		AttachedWeapon->DisableActor(true, false);
		CurrentWeaponInventory.Add(AttachedWeapon);
	}
}