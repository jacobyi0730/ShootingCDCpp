// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/WidgetAnimation.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 버튼을 누르면 동작하게 함수를 연결하고싶다.
	ButtonRestart->OnClicked.AddDynamic( this , &UGameOverWidget::OnMyRestart );

	ButtonQuit->OnClicked.AddDynamic( this , &UGameOverWidget::OnMyQuit );

	PlayAnimation( StartAnim );
}

void UGameOverWidget::OnMyRestart()
{
	// 현재 맵의 이름을 알고싶다.
	FString mapName = UGameplayStatics::GetCurrentLevelName( GetWorld() );
	// 그 맵으로 다시 레벨을 재시작 싶다.
	UGameplayStatics::OpenLevel( GetWorld() , FName(*mapName));
	
	//this->RemoveFromParent();
	//auto controller = GetWorld()->GetFirstPlayerController();
	//controller->SetShowMouseCursor( false );
	//controller->SetInputMode( FInputModeGameOnly() );
}

void UGameOverWidget::OnMyQuit()
{
	auto controller = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame( GetWorld() , controller , EQuitPreference::Quit , false );
}
