// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Components/BoxComponent.h"
#include "EnemyActor.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ShootingCppGameModeBase.h"

// Sets default values
ABulletActor::ABulletActor()
{
	PrimaryActorTick.bCanEverTick = true;
	// 충돌체를 생성하고싶다.
	boxComp = CreateDefaultSubobject<UBoxComponent>( TEXT( "boxComp" ) );
	// 충돌체를 루트컴포넌트로하고싶다.
	SetRootComponent( boxComp );
	// 몸을 생성하고싶다.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "meshComp" ) );
	// 몸을 충돌체에 붙이고싶다.
	meshComp->SetupAttachment( RootComponent );

	// 충돌설정을 하고싶다.
	boxComp->SetGenerateOverlapEvents( true );
	boxComp->SetCollisionProfileName( TEXT( "Bullet" ) );

	// 몸의 충돌체는 NoCollision 시키고싶다.
	meshComp->SetCollisionEnabled( ECollisionEnabled::NoCollision );
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic( this , &ABulletActor::OnMyCompBeginOverlap );

}

// Called every frame
void ABulletActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// 앞방향으로 이동하고싶다.
	FVector dir = GetActorForwardVector();
	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * GetWorld()->GetDeltaSeconds();
	SetActorLocation( P0 + vt );
}

void ABulletActor::OnMyCompBeginOverlap( UPrimitiveComponent* OverlappedComponent , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult )
{
	// 만약 OtherActor가 적이라면
	if (OtherActor->IsA<AEnemyActor>())
	{
		// 점수를 1점 추가 하고싶다.
		auto gm = Cast<AShootingCppGameModeBase>(GetWorld()->GetAuthGameMode());
		if (gm)
		{
			gm->AddScore( 1 );
		}


		// 폭발 소리를 내고싶다.
		UGameplayStatics::PlaySound2D( GetWorld() , expSound );

		// 폭발 VFX를 생성해서 배치하고싶다.
		UGameplayStatics::SpawnEmitterAtLocation( GetWorld() , expVFX , GetActorLocation() );

		// 너(OtherActor)죽고
		OtherActor->Destroy();

		//  나(this)죽자
		this->Destroy();

	}
}

