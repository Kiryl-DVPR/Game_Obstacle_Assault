// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform.h"

// Sets default values
AMovePlatform::AMovePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

  	RotatePlatform(DeltaTime);

	PlatformDistance = GetDistanceMoved() ; /*FVector::Dist(StartLocation, LocalVector)*/

	RotatePlatform(DeltaTime);
		
}

void AMovePlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("%s rotating!!!"),*GetName());
	AddActorLocalRotation(RotateVelocityPlatform*DeltaTime);
}

void AMovePlatform::MovePlatform (float DeltaTime)
{
	if (ShouldPlatformReturn())
		{
			FVector NormalVelocity = VelocityPlatform.GetSafeNormal();

			StartLocation = StartLocation + NormalVelocity * MovedDistance;

			SetActorLocation(StartLocation); 

			VelocityPlatform = -VelocityPlatform ;
		} 
	else
 	 	{

   		FVector CurrentLocation = GetActorLocation();
    	CurrentLocation = CurrentLocation + VelocityPlatform * DeltaTime;
    	SetActorLocation(CurrentLocation);

  		}
}

bool AMovePlatform::ShouldPlatformReturn()
{
   
  return GetDistanceMoved() > MovedDistance;

}

float AMovePlatform::GetDistanceMoved()
{
  return FVector::Dist(GetActorLocation(),StartLocation);
}