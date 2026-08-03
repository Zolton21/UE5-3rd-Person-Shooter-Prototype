// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckIfPlayerIsClose.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_CheckIfPlayerIsClose::UBTService_CheckIfPlayerIsClose() {
	NodeName = TEXT("Check if player is close enough");
}

void UBTService_CheckIfPlayerIsClose::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
		return;

	if (OwnerComp.GetAIOwner() == nullptr)
		return;

	float Distance = FVector::Dist(OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(), PlayerPawn->GetActorLocation());
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), Distance <= 500);
}