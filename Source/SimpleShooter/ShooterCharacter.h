// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ShooterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Jump() override;

	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Input")
	UInputMappingContext* ShooterMappingContext;

	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ShootAction;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	float RotationRate = 25;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere, Category = "Combat")
	float Health;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	void SetupEnhancedInputComponent();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Shoot();

};
