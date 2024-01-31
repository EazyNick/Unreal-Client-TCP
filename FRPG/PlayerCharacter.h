// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FRPG_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// 위치 정보를 블루프린트에서 접근 가능하게 만듭니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector CurrentLocation;

	// 회전 정보를 블루프린트에서 접근 가능하게 만듭니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FRotator CurrentRotation;

	// 속도 정보를 블루프린트에서 접근 가능하게 만듭니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector CurrentVelocity;

	// Sets default values for this character's properties
	APlayerCharacter();

	UFUNCTION(BlueprintCallable, Category = "GetPlayerState")
	void UpdateCharacterState();

protected:

	bool bIsConnected = false;

	bool bHasRetrievedInstance = false;

	//AMyGameNetworkManager* MyCharacterNetworkManager = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 클라이언트의 현재 상태(위치, 회전, 속도)를 얻는 함수
	UFUNCTION(BlueprintCallable, Category = "GetPlayerState")
	FString GetPlayerMove() const;

	UFUNCTION(BlueprintCallable, Category = "GetPlayerState")
	FString GetPlayerID() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cam")
	class UCameraComponent* PlayerCam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cam")
	class USpringArmComponent* PlayerCamSpringArm;
};