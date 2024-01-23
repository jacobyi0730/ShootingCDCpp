// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

//class UStaticMeshComponent; // 전방선언 (정식)

UCLASS()
class SHOOTINGCDCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	float h;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVar)
	float v;

public:
	// 입력에 대한 함수를 선언하고싶다.
	void OnMyAxisHorizontal( float value );
	void OnMyAxisVertical( float value );

public:
	// 전방선언 (약식)
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// 마우스 왼쪽 버튼을 누르면
	// firePosition(Arrow)의 위치에 BulletActor를 생성해서 배치하고싶다.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePosition;

	void OnMyActionFirePressed();
	void OnMyActionFireReleased();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> bulletFactory;

	UPROPERTY(EditAnywhere)
	class USoundBase* fireSound;

	// 자동총쏘기 기능을 만들고싶다.
	// 누를때, 뗄때, Tick
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAutoFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fireTime = 0.2f;

	UFUNCTION(BlueprintCallable)
	void MakeBullet();

	void AddDamage( int32 damage );
	int32 GetHP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 maxHP = 2;

};
