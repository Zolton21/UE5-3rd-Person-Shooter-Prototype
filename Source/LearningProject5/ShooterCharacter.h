// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class AGun;

UCLASS()
class LEARNINGPROJECT5_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* PlayerCharacterMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookGamepadAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveRightAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ShootAction;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment")
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float Health;

	APlayerController* CharacterPlayerController;

	void Look(const FInputActionValue& Value);
	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);
	void LookGamepad(const FInputActionValue& Value);
	void ShootInput(const FInputActionValue& Value);

public:
	void Shoot();

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
