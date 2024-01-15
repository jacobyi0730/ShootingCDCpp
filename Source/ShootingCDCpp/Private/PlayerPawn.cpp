// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector P0 = GetActorLocation();
	// 사용자의 입력방향을 기억하고싶다.
	FVector dir = FVector(0, h, v);
	dir.Normalize();

	FVector _v = dir * speed;
	FVector vt = _v * DeltaTime;
	FVector newLoc = P0 + vt;
	// 그 방향으로 이동하고싶다.
	SetActorLocation( newLoc );

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerPawn::OnMyAxisHorizontal);
	
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayerPawn::OnMyAxisVertical );

}

void APlayerPawn::OnMyAxisHorizontal( float value )
{
	h = value;
}

void APlayerPawn::OnMyAxisVertical( float value )
{
	v = value;
}

