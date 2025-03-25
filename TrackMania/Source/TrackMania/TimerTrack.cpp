#include "TimerTrack.h"

void ATimerTrack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimerTrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsStarted)
		CurrentTime += DeltaTime;
}
void ATimerTrack::StartTimer()
{
	IsStarted = true;
	LastTime = CurrentTime;
	if (LastTime > BestTime)
	{
		BestTime = LastTime;
	}
	CurrentTime = 0;
}

