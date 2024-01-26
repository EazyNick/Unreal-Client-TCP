// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include <Blueprint/UserWidget.h>
#include "InventoryUI.h"

AMyPlayerController::AMyPlayerController()
{
	bShowMouseCursor = true;
	bReplicates = true;
}

void AMyPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (bClickRightMouse)
	{
		MoveToMouseCursor();
	}
}

void AMyPlayerController::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;
}

void AMyPlayerController::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("RightClick", EInputEvent::IE_Pressed, this, &AMyPlayerController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", EInputEvent::IE_Released, this, &AMyPlayerController::InputRightMouseButtonReleased);
	InputComponent->BindAction("Inventory", EInputEvent::IE_Pressed, this, &AMyPlayerController::OpenInventory);
	InputComponent->BindAction("Test1", EInputEvent::IE_Pressed, this, &AMyPlayerController::TestInventory);
}

void AMyPlayerController::SetNewDestination(const FVector Destination)
{
	APawn* const PlayerPawn = GetPawn();
	if (PlayerPawn)
	{
		float const Distance = FVector::Dist(PlayerPawn->GetActorLocation(), Destination);
		if(Distance > 10.f)
		{ 
			Server_MovePlayer(this, Destination);
		}
	}
}

void AMyPlayerController::Server_MovePlayer_Implementation(APlayerController* PlayerCtr, FVector Destination)
{
	Multicast_MovePlayer(PlayerCtr, Destination);
}

void AMyPlayerController::Multicast_MovePlayer_Implementation(APlayerController* PlayerCtr, FVector Destination)
{
	MovePlayer(PlayerCtr, Destination);
}

void AMyPlayerController::MovePlayer(APlayerController* PlayerCtr, FVector Destination)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(PlayerCtr, Destination);
}


void AMyPlayerController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit)
	{
		SetNewDestination(Hit.ImpactPoint);
	}
}

void AMyPlayerController::OpenInventory()
{
	UE_LOG(LogTemp, Log, TEXT("Open"));
	if (!UI_Iventory) // 인벤토리 UI 생성 확인, 없으면 생성
	{
		UE_LOG(LogTemp, Log, TEXT("Open2"));
		if (UI_Inventory_Class)
		{
			UI_Iventory = CreateWidget(GetWorld(), UI_Inventory_Class);
			if (UI_Iventory)
			{
				UI_Iventory->AddToViewport();
				UE_LOG(LogTemp, Log, TEXT("Open4"));
			}
		}
	}
	else
	{
		// 생성 이후 껐다 켰다
		UE_LOG(LogTemp, Log, TEXT("Open3"));
		if (UI_Iventory->GetVisibility() != ESlateVisibility::Hidden)
		{
			UI_Iventory->SetVisibility(ESlateVisibility::Hidden);
		}
		else
		{
			UI_Iventory->SetVisibility(ESlateVisibility::Visible);
		}

	}
}

void AMyPlayerController::TestInventory()
{
	if (UI_Iventory)
	{
		UInventoryUI* InvenUI = Cast<UInventoryUI>(UI_Iventory);
		InvenUI->TestItem();
	}
}


