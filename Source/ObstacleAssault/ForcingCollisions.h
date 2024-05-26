// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ForcingCollisions.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBSTACLEASSAULT_API UForcingCollisions : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UForcingCollisions();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	ACharacter* Owner;
	
	// Capsule component to handle the overlaping
	class UCapsuleComponent* OverlapCapsule;

	void ShakeCharacter() const;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, Category="Forcing Collisions", meta=(AllowPrivateAccess="true"))
	int32 NumOverlapping = 0;
};
