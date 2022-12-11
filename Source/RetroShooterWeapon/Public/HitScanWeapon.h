// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "HitScanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class RETROSHOOTERWEAPON_API AHitScanWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	

public:
#pragma region Public functions

	virtual void Fire() override;


#pragma endregion

};
