// Fill out your copyright notice in the Description page of Project Settings.

#include "PressurePlatform.h"
#include "Components/BoxComponent.h"
#include "EngineUtils.h"
#include "MovingPlatform.h"

// Sets default values
APressurePlatform::APressurePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Pressure Platform"));
	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APressurePlatform::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APressurePlatform::OnOverlapEnd);


}

// Called when the game starts or when spawned
void APressurePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APressurePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	UE_LOG(LogTemp, Warning, TEXT("On pressure plat."));

	
	for (auto MovingPlatform : MovingPlatforms) {
		MovingPlatform->AddActiveTrigger();
	}
}


void APressurePlatform::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	UE_LOG(LogTemp, Warning, TEXT("Off pressure plat."));
	
	for (auto MovingPlatform : MovingPlatforms) {
		MovingPlatform->RemoveActiveTrigger();
	}
	
}