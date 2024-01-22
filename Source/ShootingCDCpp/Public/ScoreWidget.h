// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCDCPP_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// UI에 존재하는 텍스트의 문자열을 입력받은 score로 하고싶다.
	void SetScoreText( int score );

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TextScore;

	UPROPERTY()
	class AShootingCppGameModeBase* gm;


};
