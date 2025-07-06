// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleSteamSessionGameMode.h"
#include "SimpleSteamSessionCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleSteamSessionGameMode::ASimpleSteamSessionGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/PNetworking/Custom/Blueprints/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
