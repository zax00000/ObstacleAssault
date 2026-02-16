// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	int MyValue = -5;
	int MyOtherValue = -8;

	int Result = MyValue * MyOtherValue;

	UE_LOG(LogTemp, Display, TEXT("Result is %d"), Result);

	float MyCalculation = 12.0f / 5.0f;
	UE_LOG(LogTemp, Display, TEXT("My calculation is %f"), MyCalculation);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

