// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerTrack.generated.h"

UCLASS()
class TRACKMANIA_API ATimerTrack : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void StartTimer();

	UPROPERTY()
	float BestTime;

	UPROPERTY()
	float CurrentTime;

	UPROPERTY()
	float LastTime;

	UPROPERTY()
	bool IsStarted;
};
