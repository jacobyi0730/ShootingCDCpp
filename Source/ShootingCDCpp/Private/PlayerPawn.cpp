// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "BulletActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	// boxComp를 생성해서
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	// boxComp를 루트컴포넌트로 하고싶다.
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50.f));

	// meshComp를 생성해서
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	// 루트에 붙이고싶다.
	meshComp->SetupAttachment(RootComponent);

	// mesh의 StaticMesh 파일을 로드하고싶다.
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/Models/SpaceShip/Spaceship_ARA.Spaceship_ARA'"));

	// 로드를 성공했다면
	if (tempMesh.Succeeded())
	{
		// meshComp의 staticmesh를 로드한 것으로 지정하고싶다.
		meshComp->SetStaticMesh( tempMesh.Object );
		// Mesh의 Transform을 설정하고싶다.
		meshComp->SetRelativeRotation(FRotator(0, 90, 90));
		meshComp->SetRelativeScale3D(FVector(4.15f));
	}


	// Bullet과 Enemy에도 충돌설정을 반영해주세요!
	// 충돌설정을 하고싶다.
	boxComp->SetGenerateOverlapEvents( true );
	boxComp->SetCollisionProfileName(TEXT("Player"));

	// 몸의 충돌체는 NoCollision 시키고싶다.
	meshComp->SetCollisionEnabled( ECollisionEnabled::NoCollision );



	// Arrow 컴포넌트를 만들고
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	// 루트에 붙이고싶다.
	firePosition->SetupAttachment( RootComponent );
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	auto controller = UGameplayStatics::GetPlayerController(GetWorld() , 0);
	// 마우스 커서를 보이지 않게 하고싶다.
	controller->SetShowMouseCursor( false );
	// 입력모드를 게임으로 하고싶다.
	controller->SetInputMode( FInputModeGameOnly() );
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 이동 코드====
	{
		// pseudo code (의사코드)
		// 사용자의 입력을 받고 : SetupPlayerInputComponent
		// 그 입력값으로 방향을 만들고
		FVector dir = FVector( 0 , h , v );
		dir.Normalize();
		// 그 방향으로 이동하고싶다.(P = P0 + vt)
		FVector P0 = GetActorLocation();
		FVector vt = dir * speed * DeltaTime;
		SetActorLocation( P0 + vt );
	}
	// 이동 코드====

	//만약 bAutoFire가 true라면
	if (bAutoFire)
	{
		//	시간이 흐르다가 
		currentTime += DeltaTime;
		//	만약 발사시간이되면
		if (currentTime >= fireTime)
		{
			// MakeBullet함수를 호출하고싶다.
			MakeBullet();
			currentTime = 0;
		}
	}
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerPawn::OnMyAxisHorizontal);
	
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayerPawn::OnMyAxisVertical );

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerPawn::OnMyActionFirePressed);
	
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &APlayerPawn::OnMyActionFireReleased);
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
	bAutoFire = true;
	MakeBullet();
}

void APlayerPawn::OnMyActionFireReleased()
{
	bAutoFire = false;
	currentTime = 0;
}

void APlayerPawn::MakeBullet()
{
	// 총소리를 내고싶다.
	UGameplayStatics::PlaySound2D( GetWorld() , fireSound );

	FTransform t = firePosition->GetComponentTransform();
	// 총알을 만들어서 총구위치에 배치하고싶다. 
	GetWorld()->SpawnActor<ABulletActor>( bulletFactory , t );
}

