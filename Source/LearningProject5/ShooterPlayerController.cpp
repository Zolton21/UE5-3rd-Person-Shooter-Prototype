// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) {
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UUserWidget* Screen;

	if (HUD != nullptr) {
		HUD->RemoveFromViewport();
	}
	
	if (bIsWinner) {
		Screen = CreateWidget(this, WinScreenClass);
		if (Screen != nullptr) {
			Screen->AddToViewport();
		}
	}
	else {
		Screen = CreateWidget(this, LoseScreenClass);
		if (Screen != nullptr) {
			Screen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::BeginPlay() {
	Super::BeginPlay();
	if (HUDClass != nullptr) {
		HUD = CreateWidget(this, HUDClass);
		HUD->AddToViewport();
	}
}