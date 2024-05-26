// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector CurrentLocation;
	FVector StartLocation;
	FVector EndLocation;
	UPROPERTY(VisibleAnywhere, Category="Moving Platform Variables")
	bool MovingForward = true;

	UPROPERTY(EditAnywhere, Category="Moving Platform Variables")
	float MoveSpeedVector = 50;

	UPROPERTY(EditAnywhere, Category="Moving Platform Variables")
	FRotator RotationSpeed = FRotator(0, 90, 0);

	UPROPERTY(EditAnywhere, Category="Moving Platform Variables")
	FVector EndLocationOffset = FVector(500, 0, 0);
	
};
