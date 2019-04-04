// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include <utility>

AMovingPlatform::AMovingPlatform() {
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay() {
	Super::BeginPlay();
	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	ActorStartLocation = GetActorLocation();
	AbsoluteTargetLocation = GetTransform().TransformPosition(TargetLocation);
	JourneyLenght = (AbsoluteTargetLocation - ActorStartLocation).Size();
}

void AMovingPlatform::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (HasAuthority()) {
		if (ActivateTriggers >= 1) {
			auto ActorLocation = GetActorLocation();
			auto Direction = (AbsoluteTargetLocation - ActorStartLocation).GetSafeNormal();
			auto NewLocation = ActorLocation + Direction * Speed * DeltaSeconds;
			SetActorLocation(NewLocation);

			float TravelledLength = (NewLocation - ActorStartLocation).Size();
			if (TravelledLength > JourneyLenght) {
				std::swap(ActorStartLocation, AbsoluteTargetLocation);
			}
		}
	}

}

void AMovingPlatform::AddActiveTrigger() {
	++ActivateTriggers;
}

void AMovingPlatform::RemoveActiveTrigger() {
	if(ActivateTriggers >= 1)
		--ActivateTriggers;
}