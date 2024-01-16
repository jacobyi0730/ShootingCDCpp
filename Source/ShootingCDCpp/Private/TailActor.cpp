// Fill out your copyright notice in the Description page of Project Settings.


#include "TailActor.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

// Sets default values
ATailActor::ATailActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// meshComp를 생성하시오!
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("meshComp"));
	meshComp->SetupAttachment( RootComponent );
}

// Called when the game starts or when spawned
void ATailActor::BeginPlay()
{
	Super::BeginPlay();

	// 태어날 때 주인공을 찾아서 target에 담고싶다.
	target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

}

// Called every frame
void ATailActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	// 타겟 방향을 향해서
	FVector dir = target->GetActorLocation() - this->GetActorLocation();
	//dir.Normalize(); // dir의 길이를 1로 만들고싶다.

	// 이동하고싶다.
	FVector P0 = GetActorLocation();
	FVector vt = dir.GetSafeNormal() * speed * DeltaTime;
	SetActorLocation( P0 + vt );

	/*if (dir.Length() > 100000)
	{

	}*/
}

