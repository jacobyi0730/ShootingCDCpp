// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Components/BoxComponent.h"

// Sets default values
ABulletActor::ABulletActor()
{
	PrimaryActorTick.bCanEverTick = true;
	// 충돌체를 생성하고싶다.
	boxComp = CreateDefaultSubobject<UBoxComponent>( TEXT("boxComp"));
	// 충돌체를 루트컴포넌트로하고싶다.
	SetRootComponent( boxComp );
	// 몸을 생성하고싶다.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "meshComp" ) );
	// 몸을 충돌체에 붙이고싶다.
	meshComp->SetupAttachment( RootComponent );
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 앞방향으로 이동하고싶다.
	FVector dir = GetActorForwardVector();
	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * GetWorld()->GetDeltaSeconds();
	SetActorLocation( P0 + vt );
}

