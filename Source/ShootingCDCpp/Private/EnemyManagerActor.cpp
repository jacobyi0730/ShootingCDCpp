// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"
#include "Components/ArrowComponent.h"
#include "EnemyActor.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// ArrowComp를 생성하고싶다.
	arrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("arrowComp"));
	arrowComp->SetupAttachment( RootComponent );
	arrowComp->SetWorldRotation( FRotator(-90, 0, 180) );
}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle tHandle;
	GetWorldTimerManager().SetTimer( tHandle , this , &AEnemyManagerActor::MakeEnemy , makeTime , true );
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyManagerActor::MakeEnemy()
{
	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, arrowComp->GetComponentTransform());
}

