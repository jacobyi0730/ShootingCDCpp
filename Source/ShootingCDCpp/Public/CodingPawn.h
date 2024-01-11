// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CodingPawn.generated.h"

UCLASS()
class SHOOTINGCDCPP_API ACodingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACodingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//(Edit / Visible) + (Anywhere / DefaultsOnly / InstanceOnly)
	UPROPERTY(EditAnywhere)
	int32 number = 0;

	UPROPERTY(EditAnywhere)
	float pi = 3.3f;

	UPROPERTY(EditAnywhere)
	bool isOK = true;

	UPROPERTY(EditAnywhere)
	FString myName = TEXT("이영훈");
};
