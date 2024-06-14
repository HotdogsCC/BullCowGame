// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver == true)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);  
    }    
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("urinating");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Hi there, and welcome to Bull Cows."));
    PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Enter your guess:"));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to continue"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("Good stuff, that was the hidden word!"));
        EndGame(); 
    }
    else
    {
        if(!IsIsogram(Guess))
        {
            PrintLine(TEXT("No repeating letters. Try again."));
            return;
        }


        if (HiddenWord.Len() != Guess.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long.."), HiddenWord.Len());
        }
        else
        {
            PrintLine(TEXT("Yikes, nah, not quite"));
            PrintLine(TEXT("You have lost a life."));
            PrintLine(TEXT("You are now on %i lives"), --Lives); 
        }

        if(Lives <= 0)
        {
            PrintLine(TEXT("You lose!"));
            EndGame();
        }
        else
        {
            PrintLine(TEXT("Try again:"));
        }
    }
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{

    return true;
}