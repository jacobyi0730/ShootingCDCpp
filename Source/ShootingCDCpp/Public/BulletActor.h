// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class SHOOTINGCDCPP_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 총알과 부딪히면 너죽고 나죽고 하고싶다.
	UFUNCTION()
	void OnMyCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// 충돌체와 몸(StaticMeshComp)을 갖고싶다.
	// 앞방향으로 계속 이동하고싶다.

	// 충돌체
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;
	// 몸
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;
	// speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 1000;

	UPROPERTY(EditAnywhere)
	class USoundBase* expSound;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* expVFX;

};
