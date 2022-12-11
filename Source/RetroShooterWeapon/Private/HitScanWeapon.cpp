// Fill out your copyright notice in the Description page of Project Settings.


#include "HitScanWeapon.h"
#include "Kismet/GameplayStatics.h"



void AHitScanWeapon::Fire()
{
	if (CurrentAmmo <= 0 || IsReloading)
	{
		return;
	}
	Super::Fire();
	FHitResult HitResult;
	FVector LineStart = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetCameraLocation();
	FVector EndLine = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetCameraRotation().Vector();
	GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, EndLine * WeaponRange + LineStart, ECollisionChannel::ECC_Visibility);
	if (HitResult.GetActor())
	{
		ApplyDamage(HitResult);
	}
	CurrentAmmo--;
}





