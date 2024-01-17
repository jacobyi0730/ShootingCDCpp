// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	// boxComp를 생성해서
	boxComp = CreateDefaultSubobject<UBoxComponent>( TEXT( "boxComp" ) );
	// boxComp를 루트컴포넌트로 하고싶다.
	this->SetRootComponent( boxComp );

	// meshComp를 생성해서
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "meshComp" ) );
	// 루트에 붙이고싶다.
	meshComp->SetupAttachment( RootComponent );

	// 충돌설정을 하고싶다.
	boxComp->SetGenerateOverlapEvents( true );
	boxComp->SetCollisionProfileName(TEXT("Enemy"));

	// 몸의 충돌체는 NoCollision 시키고싶다.
	meshComp->SetCollisionEnabled( ECollisionEnabled::NoCollision );
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();

	// 30%확률로 목적지를 향하는 방향, 나머지 확률로 앞방향
	// 임의의 값을 하나 추출하고
	int32 randValue = FMath::RandRange( 0 , 9 );
	// 만약 그 값이 randomRate보다 작다면
	if (randValue < randomRate)
	{
		// 플레이어 방향
		AActor* target = UGameplayStatics::GetPlayerPawn( GetWorld() , 0 );
		direction = target->GetActorLocation() - this->GetActorLocation();
		direction.Normalize();
	}
	// 그렇지 않다면
	else
	{
		// 앞방향
		direction = GetActorForwardVector();
	}
}

// Called every frame
void AEnemyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// direction 으로 이동하고싶다.  
	FVector P0 = this->GetActorLocation();
	FVector vt = direction * speed * DeltaTime;
	SetActorLocation( P0 + vt );
}

void AEnemyActor::NotifyActorBeginOverlap( AActor* OtherActor )
{
	// 너(OtherActor)죽고
	OtherActor->Destroy();
	//  나(this)죽자
	this->Destroy();
}

