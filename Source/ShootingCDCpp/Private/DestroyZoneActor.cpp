// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyZoneActor.h"
#include "Components/BoxComponent.h"
#include "BulletActor.h"

// Sets default values
ADestroyZoneActor::ADestroyZoneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 박스컴포넌트를 생성해서 루트로 하고싶다.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent( boxComp );
	// 박스의 크기를 1미터로 하고싶다.
	boxComp->SetBoxExtent(FVector(50));
	boxComp->SetGenerateOverlapEvents( true );
	boxComp->SetCollisionProfileName(TEXT("DestroyZone"));
}

// Called when the game starts or when spawned
void ADestroyZoneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyZoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestroyZoneActor::NotifyActorBeginOverlap( AActor* OtherActor )
{
	// 만약 총알이라면 탄창에 다시 돌려주고싶다.
	ABulletActor* bullet = Cast<ABulletActor>( OtherActor );
	if (bullet)
	{
		bullet->GoMagazine();
	}
	// 그렇지 않다면
	else{
		// 너만 파괴하고싶다.
		OtherActor->Destroy();
	}
}

