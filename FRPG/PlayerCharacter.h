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

	// ��ġ ������ �������Ʈ���� ���� �����ϰ� ����ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector CurrentLocation;

	// ȸ�� ������ �������Ʈ���� ���� �����ϰ� ����ϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FRotator CurrentRotation;

	// �ӵ� ������ �������Ʈ���� ���� �����ϰ� ����ϴ�.
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

	// Ŭ���̾�Ʈ�� ���� ����(��ġ, ȸ��, �ӵ�)�� ��� �Լ�
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