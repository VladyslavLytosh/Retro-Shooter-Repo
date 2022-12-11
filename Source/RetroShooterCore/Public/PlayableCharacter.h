// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RETROSHOOTERCORE_API APlayableCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
#pragma region Blueprint events
	

#pragma endregion


#pragma region Protected functions

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Protected variables


#pragma endregion


private:
#pragma region Private variables
	
		// Sensitivity property
	UPROPERTY(EditDefaultsOnly, Category="Mouse settings")
		float Sensitivity;

		// Player weapon inventory array
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class ABaseWeapon>> WeaponInventory;

	TArray<class ABaseWeapon*> CurrentWeaponInventory;

		// Iteration variable for weapon switch system
	int32 CurrentWeaponNumber = 0;

		// Current equipped weapon
	class ABaseWeapon* CurrentWeapon;

#pragma endregion

private:
#pragma region Private functions

	/* Performs character movement*/
		// Forward/Bacwards movement
	void MoveForward(float AxisValue);
		//Side movement
	void SideMove(float AxisValue);

	/* Player mouse input */
		// Up and down input
	void MouseInputUpAndDown(float AxisValue);
		// Left and right input
	void MouseInputLeftAndRight(float AxisValue);

	/* Action input functions */
		// Weapon switch system
	void WeaponSwitch();
		// Fire weapon
	void FireCurrentWeapon();
		// Stop firing
	void StopFireCurrentWeapon();
		// Reload current weapon
	void ReloadCurrentWeapon();

	/* Another functions */

	void SetupWeapons();

#pragma endregion
};
