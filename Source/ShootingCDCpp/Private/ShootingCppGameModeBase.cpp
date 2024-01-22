// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingCppGameModeBase.h"
#include "ScoreWidget.h"

void AShootingCppGameModeBase::BeginPlay()
{
	// 태어날 때 점수위젯을 생성하고싶다.
	scoreUI = CreateWidget<UScoreWidget>(GetWorld(), scoreUIFactory );
	// 그녀석을 화면에 보이게하고싶다.
	scoreUI->AddToViewport();
	scoreUI->SetScoreText( 0 );
}

void AShootingCppGameModeBase::AddScore( int value )
{
	score += value;

	scoreUI->SetScoreText( score );	// UI한테 값을 밀어넣기
}
