// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "TimerManager.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region Fire functions

// Function that fires using HitScan system or projectile system
void ABaseWeapon::Fire()
{
	FireAnimation();
	FireSound();
	if (IsAutomatic)
	{

		GetWorldTimerManager().SetTimer(FireRateTimer, this, &ABaseWeapon::Fire, FireRate, true);
	}
	
}

// Function that stops automatic fire mode
void ABaseWeapon::StopFire()
{
	if (IsAutomatic || CurrentAmmo <= 0)
	{
		GetWorldTimerManager().ClearTimer(FireRateTimer);
	}
}

void ABaseWeapon::Reload()
{
	if (!IsReloading)
	{
		ReloadAnimation();
		ReloadSound();
		CurrentAmmo = MaxAmmo;
	}
}

#pragma endregion


void ABaseWeapon::DisableActor(bool toHide, bool SetTickEnable)
{
	// Hides visible components
	SetActorHiddenInGame(toHide);

	// Stops the Actor from ticking
	SetActorTickEnabled(SetTickEnable);

	IsHidden = toHide;
}


bool ABaseWeapon::GetIsReloading() 
{
	return IsReloading;
}

bool ABaseWeapon::GetIsHidden()
{
	return IsHidden;
}


void ABaseWeapon::ApplyDamage(FHitResult HitResult)
{
	
	auto HitResultActor = HitResult.GetActor();
	auto MyOwnerInstigator = GetOwner()->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();
	if (HitResultActor && HitResultActor != this && HitResultActor != GetOwner())
	{
		UGameplayStatics::ApplyDamage(HitResultActor, Damage, MyOwnerInstigator, this, DamageTypeClass);

		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitResult.GetActor()->GetActorNameOrLabel())
		UE_LOG(LogTemp, Warning, TEXT("Weapon damage is %f"), Damage)
	}
	
}