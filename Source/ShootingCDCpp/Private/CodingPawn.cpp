// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingPawn.h"

// Sets default values
ACodingPawn::ACodingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ACodingPawn::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello World!!"));

	UE_LOG(LogTemp, Warning, TEXT("number : %d, pi : %f"), number, pi);

	UE_LOG(LogTemp, Warning, TEXT("isOK : %d"), isOK);

	UE_LOG(LogTemp, Warning, TEXT("myName : %s"), *myName);


	// 배열
	TArray<int> ta;
	ta.Add(0);
	ta.Add(10);

	ta[0] = 20;

	if (false == ta.Contains(10))
	{
		ta.Add(10);
	}
	//ta.Remove(10);
	ta.RemoveAt(0);

	for (int i = 0; i < ta.Num(); i++)
	{
		ta[i] = i;
	}


	TMap<FString, int> userLevelInfo;
	userLevelInfo.Add(TEXT("홍길동"), 10);
	userLevelInfo.Add(TEXT("장길산"), 50);

	userLevelInfo[TEXT("홍길동")] = 20;

	for (auto item : userLevelInfo)
	{
		auto _Key = item.Key;
		auto _Value = item.Value;
	}

	
	TSet<int> sss;
	sss.Add(10);
	sss.Add(10);

	UE_LOG(LogTemp, Warning, TEXT("sss.Num() : %d"), sss.Num());
	


}

// Called every frame
void ACodingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACodingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// 정의/구현
int32 ACodingPawn::MyAdd( int32 a , int32 b )
{
	return a + b;
}

int32 ACodingPawn::MyAddPure( int32 a , int32 b )
{
	return a + b;
}

int32 ACodingPawn::MyAddNative_Implementation( int32 a , int32 b )
{
	return a + b;
}

