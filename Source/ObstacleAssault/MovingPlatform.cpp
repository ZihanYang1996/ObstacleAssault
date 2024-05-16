// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

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

	MyX = MyVector.X;

	UE_LOG(LogTemp, Warning, TEXT("X: %i"), MyX)

	SetActorLocation(MyVector);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyVector.Z = MyVector.Z + MoveSpeed * DeltaTime;
	SetActorLocation(MyVector);
}

