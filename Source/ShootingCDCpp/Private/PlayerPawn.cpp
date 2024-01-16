// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "../../../../../../../Source/Runtime/Engine/Classes/Components/BoxComponent.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "BulletActor.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	// boxComp를 생성해서
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	// boxComp를 루트컴포넌트로 하고싶다.
	this->SetRootComponent(boxComp);

	// meshComp를 생성해서
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	// 루트에 붙이고싶다.
	meshComp->SetupAttachment(RootComponent);

	// Arrow 컴포넌트를 만들고
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	// 루트에 붙이고싶다.
	firePosition->SetupAttachment( RootComponent );
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

	// pseudo code (의사코드)
	// 사용자의 입력을 받고 : SetupPlayerInputComponent
	// 그 입력값으로 방향을 만들고
	FVector dir = FVector(0, h, v);
	dir.Normalize();
	// 그 방향으로 이동하고싶다.(P = P0 + vt)
	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * DeltaTime;
	SetActorLocation( P0 + vt );
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerPawn::OnMyAxisHorizontal);
	
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayerPawn::OnMyAxisVertical );

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerPawn::OnMyActionFirePressed);
}

void APlayerPawn::OnMyAxisHorizontal( float value )
{
	h = value;
}

void APlayerPawn::OnMyAxisVertical( float value )
{
	v = value;
}

void APlayerPawn::OnMyActionFirePressed()
{
	FTransform t = firePosition->GetComponentTransform();
	// 총알을 만들어서 총구위치에 배치하고싶다. 
	GetWorld()->SpawnActor<ABulletActor>( bulletFactory , t );
}

void APlayerPawn::OnMyActionFireReleased()
{

}

