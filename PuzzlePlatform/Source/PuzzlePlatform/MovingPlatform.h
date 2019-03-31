// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	UPROPERTY(EditAnyWhere)
	float Speed = 100.f;

	UPROPERTY(EditAnyWhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	UPROPERTY(EditAnyWhere)
	int ActivateTriggers = 1;

	FVector ActorStartLocation;
	FVector AbsoluteTargetLocation;
	float JourneyLenght = 0.f;
};
