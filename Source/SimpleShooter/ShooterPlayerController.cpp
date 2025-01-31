// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    StartScreen = CreateWidget(this, StartScreenClass);
    if (StartScreen)
    {
        StartScreen->AddToViewport();
        SetShowMouseCursor(true);
        SetInputMode(FInputModeUIOnly());
    }
}

void AShooterPlayerController::StartGame()
{
    StartScreen->RemoveFromParent();
    SetShowMouseCursor(false);
    SetInputMode(FInputModeGameOnly());

    HUD = CreateWidget(this, HUDClass);
    if (HUD)
    {
        HUD->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromParent();
    if (bIsWinner)
    {
        UUserWidget *WinScreen = CreateWidget(this, WinScreenClass);
        if (WinScreen)
        {
            WinScreen->AddToViewport();
        }
    }
    else
    {
        // Criamos a UI, mas ainda não está na tela
        UUserWidget *LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen)
        {
            // Adicionamos a UI na tela
            LoseScreen->AddToViewport();
        }
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
