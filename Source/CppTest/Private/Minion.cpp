// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion.h"



// Sets default values
AMinion::AMinion():
	IsInUse(false),
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void AMinion::Activate()
{
    IsInUse = true;
    SetActorHiddenInGame(false);

    GetWorld()->GetTimerManager().SetTimer(MinionTimerHandle, this, &AMinion::Deactivate, ActiveTime, false);
}

void AMinion::Deactivate()
{
    IsInUse = false;
    SetActorHiddenInGame(true);

	OnDeactivate.Broadcast(this);
    GetWorld()->GetTimerManager().ClearTimer(MinionTimerHandle);
}

// Called when the game starts or when spawned
void AMinion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

