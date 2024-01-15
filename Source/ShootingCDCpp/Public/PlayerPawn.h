// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SHOOTINGCDCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	float h;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	float v;

public:
	// 입력에 대한 함수를 선언하고싶다.
	void OnMyAxisHorizontal( float value );
	void OnMyAxisVertical( float value );
};
