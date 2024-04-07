// Fill out your copyright notice in the Description page of Project Settings.

#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn *PawnKilled)
{
    UE_LOG(LogTemp, Warning, TEXT("Pawn %s killed"), *PawnKilled->GetActorNameOrLabel());

    APlayerController *PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController)
    {
        PlayerController->GameHasEnded(nullptr, false);
    }
}
