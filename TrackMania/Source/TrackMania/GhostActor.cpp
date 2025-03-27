// Fill out your copyright notice in the Description page of Project Settings.


#include "GhostActor.h"

// Sets default values
AGhostActor::AGhostActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGhostActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGhostActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsStarted)
	{
		if (HaveABestTime && StartGhost)
		{
			SetLocationAndRotation();
		}
		ArrayLocationTemp.Add(Car->GetActorLocation());
		ArrayRotationTemp.Add(Car->GetActorRotation());
	}
}

void AGhostActor::SetLocationAndRotation()
{
	GhostMesh->SetVisibility(true);
	GhostMesh->SetWorldLocation(ArrayLocation[IndexArray]);
	GhostMesh->SetWorldRotation(ArrayRotation[IndexArray]);
	IndexArray++;
	if (IndexArray >= ArrayLocation.Num())
	{
		IndexArray = 0;
		StartGhost = false;
		GhostMesh->SetVisibility(false);
	}
}

void AGhostActor::ResetArrays()
{
	ArrayLocationTemp.Empty();
	ArrayRotationTemp.Empty();
	IndexArray = 0;
	GhostMesh->SetVisibility(false);
}

void AGhostActor::SetNewBestTime()
{
	HaveABestTime = true;
	StartGhost = false;
	ArrayLocation = ArrayLocationTemp;
	ArrayRotation = ArrayRotationTemp;
	ResetArrays();
}

