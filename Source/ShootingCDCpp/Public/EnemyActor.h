// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class SHOOTINGCDCPP_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void OnMyCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// 충돌체와 몸을 갖고싶다.
	// 태어날 때 방향을 만들고
	// 30%확률로 목적지를 향하는 방향, 나머지 확률로 앞방향
	// 살아가면서 그 방향으로 이동하고싶다.
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int randomRate = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector direction;

	// 플레이어와 부딪히면 폭발 소리를 내고싶다. 폭발 이펙트도 생성해서 배치하고 싶다.

	UPROPERTY(EditAnywhere)
	class USoundBase* expSound;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* expVFX;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameOverWidget> gameOverUIFactory;
};
