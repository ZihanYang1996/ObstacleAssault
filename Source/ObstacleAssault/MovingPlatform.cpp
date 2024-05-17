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

	CurrentLocation = GetActorLocation();

	// Get the player actor using tag
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player"), FoundActors);
	if (FoundActors.Num() > 0)
	{
		PlayerActor = FoundActors[0];
	}
	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the platform
	CurrentLocation += MoveSpeedVector * DeltaTime;
	SetActorLocation(CurrentLocation);

	DistanceFromPlayer = FVector::Dist(PlayerActor->GetActorLocation(), CurrentLocation);
	// UE_LOG(LogTemp, Warning, TEXT("Distance from player: %s"), *PlayerActor->GetActorLocation().ToString());
	// UE_LOG(LogTemp, Warning, TEXT("Distance from player: %f"), DistanceFromPlayer);

}

