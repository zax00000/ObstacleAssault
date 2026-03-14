// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void MyTestFunction(float MyFloatParam, FString MyStringParam)
{
	UE_LOG(LogTemp, Display, TEXT("MyFloatParam is %f"), MyFloatParam);

	UE_LOG(LogTemp, Display, TEXT("MyStringParam is %s"), *MyStringParam);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	FString MyName = GetName();
	MyTestFunction(3.5f, MyName);

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// Increase X position by 1 every frame
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved >= MoveDistance)
	{
		float Overshoot = DistanceMoved - MoveDistance;
		FString PlatformName = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s overshoot by %f"), *PlatformName, Overshoot);

		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotate the platform
}