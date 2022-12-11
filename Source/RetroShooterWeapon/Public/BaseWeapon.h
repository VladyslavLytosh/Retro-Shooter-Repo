// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"


UCLASS()
class RETROSHOOTERWEAPON_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();
	UFUNCTION(BlueprintImplementableEvent)
		void FireAnimation();
	UFUNCTION(BlueprintImplementableEvent)
		void ReloadAnimation();

	UFUNCTION(BlueprintImplementableEvent)
		void ReloadSound();
	UFUNCTION(BlueprintImplementableEvent)
		void FireSound();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma region Protected functions

	

#pragma endregion

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
#pragma region Public functions

	virtual void Fire();
	virtual void StopFire();
	virtual void Reload();
	virtual bool GetIsReloading();
	bool GetIsHidden();
	void DisableActor(bool toHide,bool SetTickEnable);
	void ApplyDamage(FHitResult HitResult);
#pragma endregion

protected:
#pragma region Protected variables

	/* Protected weapon */
		//Damage weapon value
	UPROPERTY(EditDefaultsOnly, Category = "Weapon mechanic")
		float Damage;
		// Weapon fire rate value
	UPROPERTY(EditDefaultsOnly, Category = "Weapon mechanic")
		float FireRate;
		// Range, which determines how far the weapon can fire.
	UPROPERTY(EditDefaultsOnly, Category = "Weapon mechanic")
		float WeaponRange;
		// Determines wheres weapon is automatic 
	UPROPERTY(EditDefaultsOnly, Category = "Weapon mechanic")
		bool IsAutomatic = false;
		//Max weapon ammo
	UPROPERTY(EditDefaultsOnly, Category = "Weapon mechanic")
		int32 MaxAmmo;
		// Current ammo in magazine
	int32 CurrentAmmo;
		// Timer handle for Fire Rate
	FTimerHandle FireRateTimer;

	UPROPERTY(BlueprintReadWrite)
		bool IsReloading = false;

	bool IsHidden;

#pragma endregion


	

};
