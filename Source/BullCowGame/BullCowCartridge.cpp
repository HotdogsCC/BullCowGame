// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    PrintLine(TEXT("Hi there, and welcome to Bull Cows."));
    PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
    PrintLine(TEXT("Enter your guess:"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("yesss"));
    }
    else
    {
        if (HiddenWord.Len() != Input.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
        }

        PrintLine(TEXT("no."));
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("urinating");
    Lives = 5;
}