// Copyright Luca Farci 2020

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "PawnTank.generated.h"


class USpringArmComponent;
class UCameraComponent;


UCLASS()
class TOONTANKS_API APawnTank : public ABasePawn
{
	GENERATED_BODY()
	
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	FVector MoveDirection;
	FQuat RotationDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowprivateAccess ="true")) 
	float MoveSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowprivateAccess ="true")) 
	float RotateSpeed = 100.f;

	APlayerController* PlayerControllerRef;

	UPROPERTY()
	bool bIsPlayerAlive = true;

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();

public:

	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void HandleDestruction() override;

	bool GetIsPlayerAlive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




};
