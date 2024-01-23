// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingCppGameModeBase.h"
#include "ScoreWidget.h"
#include "Kismet/GameplayStatics.h"
#include "HighScoreSaveGame.h"


void AShootingCppGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	LoadHighScore();

	// 태어날 때 점수위젯을 생성하고싶다.
	scoreUI = CreateWidget<UScoreWidget>( GetWorld() , scoreUIFactory );
	// 그녀석을 화면에 보이게하고싶다.
	scoreUI->AddToViewport( 1 );
	scoreUI->SetScoreText( 0 , highScore );

}

void AShootingCppGameModeBase::AddScore( int32 value )
{
	score += value;

	if (score > highScore)
	{
		highScore = score;
		// 저장하기
		SaveHighScore();
	}

	scoreUI->SetScoreText( score , highScore );	// UI한테 값을 밀어넣기
}

void AShootingCppGameModeBase::SaveHighScore()
{
	// 1. SavaGame객체 생성
	auto inst = Cast<UHighScoreSaveGame>( UGameplayStatics::CreateSaveGameObject( saveGameFactory ) );

	// 2. 저장할 값을 SavaGame객체에 대입하고싶다
	inst->save_highScore = highScore;

	// 3. 슬롯( 파일 )로 저장
	UGameplayStatics::SaveGameToSlot( inst , saveFileName , saveUserIndex );
}

void AShootingCppGameModeBase::LoadHighScore()
{
	// 1. 파일이 존재한다면
	if (UGameplayStatics::DoesSaveGameExist(saveFileName , saveUserIndex))
	{
		// 2. 파일을 로드하고
		auto inst = Cast<UHighScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(saveFileName , saveUserIndex));
		// 3. 로드한 savegame의 내용을 가져다 사용한다.
		highScore = inst->save_highScore;
	}
	
}
