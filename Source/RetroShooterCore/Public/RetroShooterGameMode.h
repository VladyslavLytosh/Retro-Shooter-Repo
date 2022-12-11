// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RetroShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RETROSHOOTERCORE_API ARetroShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

};
