// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Minion.h"
#include "GameFramework/Actor.h"
#include "Gru.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinionDeactivate, AMinion*, Minion);

UCLASS()
class CPPTEST_API AGru : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGru();

protected:

	virtual void BeginPlay() override;
	virtual void HandleMinionDeactivation();
	virtual void ActivateMinion();

	UPROPERTY(EditAnywhere, Category = "Minions")
    FOnMinionDeactivate OnDeactivate;

	UPROPERTY(EditAnywhere,Category="Minions")
	TArray<class AMinion*> Minions;


	UPROPERTY(EditAnywhere, Category = "Minions")
	float ActivateMinionInterval;

	UPROPERTY(VisibleAnywhere, Category = "Minions")
	FTimerHandle GruTimerHandle;

	UPROPERTY(VisibleAnywhere, Category = "Minions")
	TArray<class AMinion*> InactiveMinions;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};