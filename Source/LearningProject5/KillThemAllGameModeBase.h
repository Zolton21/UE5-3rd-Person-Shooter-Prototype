// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameModeBase.h"
#include "KillThemAllGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGPROJECT5_API AKillThemAllGameModeBase : public AShooterGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* Pawn) override;

	void EndGame(bool bIsPlayerWinner);
};
