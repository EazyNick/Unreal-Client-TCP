// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FRPG_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMyPlayerController();
protected:
	virtual void PlayerTick(float DeltaTime) override;

	bool bClickRightMouse;

	void InputRightMouseButtonPressed();

	void InputRightMouseButtonReleased();

	virtual void SetupInputComponent() override;

	void MoveToMouseCursor();

	void OpenInventory();

	void TestInventory();

public:
	//UFUNCTION(reliable, server)
	void SetNewDestination(const FVector Destination);
	UFUNCTION(Server, Unreliable)
	void Server_MovePlayer(APlayerController* PlayerCtr, FVector Destination);
	void Server_MovePlayer_Implementation(APlayerController* PlayerCtr, FVector Destination);
	UFUNCTION(NetMulticast, Unreliable)
	void Multicast_MovePlayer(APlayerController* PlayerCtr,FVector Destination);
	void Multicast_MovePlayer_Implementation(APlayerController* PlayerCtr, FVector Destination);
	void MovePlayer(APlayerController* PlayerCtr, FVector Destination);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> UI_Inventory_Class;
	UUserWidget* UI_Iventory;
};
