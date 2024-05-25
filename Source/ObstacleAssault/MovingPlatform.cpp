// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = StartLocation + EndLocationOffset;	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calculate new location
	CurrentLocation = GetActorLocation();
	FVector TargetLocation = MovingForward ? EndLocation : StartLocation;
	FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	FVector NewLocation = CurrentLocation + Direction * MoveSpeedVector * DeltaTime;
	
	// Move the platform
	SetActorLocation(NewLocation);

	// If the platform has reached the target location, switch direction
	if (FVector::DistSquared(NewLocation, TargetLocation) < 1.0f)
	{
		MovingForward = !MovingForward;
	}
}

