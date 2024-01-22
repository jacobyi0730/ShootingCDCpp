// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/TextBlock.h"
#include "ShootingCppGameModeBase.h"

void UScoreWidget::NativeConstruct()
{
	// 게임모드를 가져와서 기억하고싶다.
	auto gmb = GetWorld()->GetAuthGameMode();
	gm = Cast<AShootingCppGameModeBase>( gmb );
}

void UScoreWidget::SetScoreText( int score )
{
	TextScore->SetText(FText::AsNumber( score ));
}
