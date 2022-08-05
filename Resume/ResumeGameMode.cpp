// Copyright Epic Games, Inc. All Rights Reserved.

#include "ResumeGameMode.h"
#include "ResumeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AResumeGameMode::AResumeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
