// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingCppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCDCPP_API AShootingCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// 점수를 관리하고 싶다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int score;

	UFUNCTION(BlueprintCallable)
	void AddScore(int value);
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> scoreUIFactory;

	UPROPERTY()
	class UScoreWidget* scoreUI;

};
