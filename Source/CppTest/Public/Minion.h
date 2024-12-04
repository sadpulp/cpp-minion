// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Minion.generated.h"

UCLASS()
class CPPTEST_API AMinion : public AActor
{
	GENERATED_BODY()
	
public:	
	AMinion();
	UPROPERTY(EditAnywhere, Category = "Minion")
	bool IsInUse;

	UPROPERTY(EditAnywhere, Category = "Minion")
	FString Name;

	
protected:
	virtual void BeginPlay() override;
	virtual void Activate();
	virtual void Deactivate();

	UPROPERTY(EditAnywhere, Category = "Minion")
	float Health;
	
	UPROPERTY(EditAnywhere, Category = "Minion")
	float ActiveTime;

	UPROPERTY(VisibleAnywhere, Category = "Minion")
	FTimerHandle MinionTimerHandle;
	
public:	
	virtual void Tick(float DeltaTime) override;

};