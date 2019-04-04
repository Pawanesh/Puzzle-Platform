// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformGameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void UPuzzlePlatformGameInstance::Host() {
	auto Engine = GetEngine();
	if (!ensure(Engine)) return;

	Engine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("Hosing ...."));
	
	auto World = GetWorld();
	if (!ensure(World)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformGameInstance::Join(const FString& address) {
	auto Engine = GetEngine();
	if (!ensure(Engine)) return;
	Engine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("Joining ...."));

	APlayerController* playerController = GetFirstLocalPlayerController(GetWorld());
	if (!ensure(playerController)) return;

	Engine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("Joining 192.168.0.9:7777...."));

	playerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
}