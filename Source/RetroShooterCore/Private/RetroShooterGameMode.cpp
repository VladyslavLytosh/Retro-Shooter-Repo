// Fill out your copyright notice in the Description page of Project Settings.


#include "RetroShooterGameMode.h"
#include "BaseCharacter.h"

void ARetroShooterGameMode::ActorDied(AActor* DeadActor)
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(DeadActor);
	if (Character)
	{
		Character->HandleDestruction();
	}
	
}