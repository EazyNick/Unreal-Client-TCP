// Copyright Epic Games, Inc. All Rights Reserved.

#include "FRPGGameMode.h"
#include "MyGameNetworkManager.h"
#include "FRPGPlayerController.h"
#include "FRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFRPGGameMode::AFRPGGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AFRPGPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}