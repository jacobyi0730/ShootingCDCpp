// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TailActor.generated.h"

UCLASS()
class SHOOTINGCDCPP_API ATailActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATailActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// 목적지를 향해 이동하고싶다.
	// 몸(staticmeshcomp)을 가지고싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 450.f;
	
	// meshComp를 생성하시오!
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;
};
