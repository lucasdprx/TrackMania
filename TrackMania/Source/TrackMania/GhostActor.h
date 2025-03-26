#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GhostActor.generated.h"

UCLASS()
class TRACKMANIA_API AGhostActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGhostActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMeshComponent* GhostMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool StartGhost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsStarted;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* Car;
	
	UFUNCTION(BlueprintCallable)
	void SetLocationAndRotation();
	
	UFUNCTION(BlueprintCallable)
	void ResetArrays();

	UFUNCTION(BlueprintCallable)
	void SetNewBestTime();

private:
	TArray<FVector> ArrayLocation;
	TArray<FVector> ArrayLocationTemp;
	TArray<FRotator> ArrayRotation;
	TArray<FRotator> ArrayRotationTemp;
	int IndexArray;
	bool HaveABestTime;
	
};
