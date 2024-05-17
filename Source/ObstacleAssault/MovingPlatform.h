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

	UPROPERTY(EditAnywhere, Category="Moving Platform Variables")
	FVector MoveSpeedVector = FVector(0, 0, 10);

	UPROPERTY(VisibleAnywhere, Category="Moving Platform Variables")
	float DistanceFromPlayer = 0.0f;

	// UPROPERTY(EditAnywhere, Category="Moving Platform Variables")  // Directly setting the player actor in the editor
	AActor* PlayerActor;
};
