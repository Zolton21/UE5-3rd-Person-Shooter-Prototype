// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameModeBase.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"

void AKillThemAllGameModeBase::PawnKilled(APawn* Pawn) {
	Super::PawnKilled(Pawn);

	UE_LOG(LogTemp, Warning, TEXT("Pawn was killed"));

	APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController());
	if (PlayerController != nullptr) {
		EndGame(false);
	}

	for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld())) {
		if (!AIController->IsDead()) {
			return;
		}
	}
	EndGame(true);
}

void AKillThemAllGameModeBase::EndGame(bool bIsPlayerWinner) {
	for (AController* Controller : TActorRange<AController>(GetWorld())) {
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}