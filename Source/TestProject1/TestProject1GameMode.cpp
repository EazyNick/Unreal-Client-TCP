// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestProject1GameMode.h"
#include "TestProject1PlayerController.h"
#include "TestProject1Character.h"
#include "UObject/ConstructorHelpers.h"

ATestProject1GameMode::ATestProject1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATestProject1PlayerController::StaticClass();

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