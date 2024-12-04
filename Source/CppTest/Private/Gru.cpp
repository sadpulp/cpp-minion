// Fill out your copyright notice in the Description page of Project Settings.


#include "Gru.h"

// Sets default values
AGru::AGru(): DoStuffInterval(1.f), TimeSinceLastDoStuff(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGru::BeginPlay()
{
	Super::BeginPlay();
	InactiveMinions = Minions;
	for (AMinion* InactiveMinion : InactiveMinions)
    {
		InactiveMinion->OnDeactivate.AddDynamic(this, &AGru::HandleMinionDeactivation);
    }
	GetWorld()->GetTimerManager().SetTimer(GruTimerHandle, this, ActivateMinion, ActivateMinionInterval, true);
}

void AGru::ActivateMinion()
{
	if (!InactiveMinions.Num()) return;
	AMinion* SelectedMinion = InactiveMinions[FMath::RandRange(0, InactiveMinions.Num() - 1)];
	if (SelectedMinion && !SelectedMinion->IsInUse)
	{
		*SelectedMinion->Activate();
		*SelectedMinion->OnDeactivate.AddDynamic(this, &AGru::HandleMinionDeactivation);
		InactiveMinions.Remove(*SelectedMinion);
		UE_LOG(LogTemp, Display, TEXT("Activating Minion: %s"), *SelectedMinion->Name);
	}
}

void AGru::HandleMinionDeactivation(AMinion* DeactivatedMinion)
{
    if (DeactivatedMinion && !InactiveMinions.Contains(DeactivatedMinion))
    {
        InactiveMinions.Add(DeactivatedMinion);
    }
}

// Called every frame
void AGru::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
