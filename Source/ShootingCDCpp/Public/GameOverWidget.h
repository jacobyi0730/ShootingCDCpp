// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCDCPP_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ButtonRestart;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ButtonQuit;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* StartAnim;

	UFUNCTION()
	void OnMyRestart();
	
	UFUNCTION()
	void OnMyQuit();
};
