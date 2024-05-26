// Fill out your copyright notice in the Description page of Project Settings.


#include "ForcingCollisions.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values for this component's properties
UForcingCollisions::UForcingCollisions()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UForcingCollisions::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACharacter>(GetOwner()); // GetOwner() returns an AActor*, so we need to cast it to ACharacter
	// Find the OverlapCapsule component
	if (Owner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Owner%s"), *Owner->GetActorLabel());
		UE_LOG(LogTemp, Warning, TEXT("Found Owner%s"), *Owner->GetFName().ToString());
		UE_LOG(LogTemp, Warning, TEXT("Found Owner%s"), *Owner->GetName());
		// Create the capsule component
		TArray<UCapsuleComponent*> CapsuleComponents;
		Owner->GetComponents<UCapsuleComponent>(CapsuleComponents);

		// Iterate over the capsule components to find OverlapCapsule
		for (UCapsuleComponent* Component : CapsuleComponents)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found Capsule"));
			if (Component->ComponentHasTag(FName("OverlapCapsule")))
			{
				UE_LOG(LogTemp, Warning, TEXT("Found OverlapCapsule"));
				OverlapCapsule = Component;
			}
		}
	}

	OverlapCapsule->OnComponentBeginOverlap.AddDynamic(this, &UForcingCollisions::OnOverlapBegin);
	OverlapCapsule->OnComponentEndOverlap.AddDynamic(this, &UForcingCollisions::OnOverlapEnd);
}


// Called every frame
void UForcingCollisions::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ShakeCharacter();
}

void UForcingCollisions::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	if (OtherActor == Owner)
	{
		return;
	}
	NumOverlapping++;
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin with: %s, NumOverlappingL %d"), *OtherActor->GetActorLabel(),
	       NumOverlapping);
}

void UForcingCollisions::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == Owner)
	{
		return;
	}
	NumOverlapping -= NumOverlapping > 0 ? 1 : 0;
	UE_LOG(LogTemp, Warning, TEXT("Overlap End with: %s, NumOverlappingL %d"), *OtherActor->GetActorLabel(),
	       NumOverlapping);
}

void UForcingCollisions::ShakeCharacter() const
{
	if (NumOverlapping == 0)
	{
		return;
	}

	FHitResult HitResult;
	bool bMoved = Owner->GetMovementComponent()->MoveUpdatedComponent(FVector(2.0f, 0.0f, 0.0f),
	                                                                  Owner->GetActorRotation(), true, &HitResult,
	                                                                  ETeleportType::None);
	bMoved = Owner->GetMovementComponent()->MoveUpdatedComponent(FVector(-2.0f, 0.0f, 0.0f),
	                                                             Owner->GetActorRotation(), true, &HitResult,
	                                                             ETeleportType::None);
	// if (bMoved)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Moved Character"));
	// }
}
