// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CanSeePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

UBTService_CanSeePlayer::UBTService_CanSeePlayer() {
	NodeName = TEXT("Can see player?");
}

void UBTService_CanSeePlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
		return;

	if (OwnerComp.GetAIOwner() == nullptr)
		return;

	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) {
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	}
	else {
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), false);
	}
}