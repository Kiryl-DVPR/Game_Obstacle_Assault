// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnyWhere, Category = "Moving Platform")
	FVector VelocityPlatform = FVector(1, 0, 0);

	FVector StartLocation;

	UPROPERTY(VisibleAnyWhere, Category = "Moving Platform")
	float PlatformDistance = 10;

	UPROPERTY(EditAnyWhere, Category = "Moving Platform")
	float MovedDistance = 100;
	
	UPROPERTY(EditAnyWhere, Category = "Moving Platform")
	FRotator RotateVelocityPlatform;

	void MovePlatform (float DeltaTime);

  	void RotatePlatform (float DeltaTime);

  	bool ShouldPlatformReturn();

  	float GetDistanceMoved();

};
