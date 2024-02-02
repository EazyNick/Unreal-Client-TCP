// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawner.generated.h"

UCLASS()
class FRPG_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACharacterSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame	
	virtual void Tick(float DeltaTime) override;

	FVector ParseVelocityFromString(const FString& Input);

	void SpawnCharacter();
	void SendData();

	FVector Velocity;

	int32 VelocityIndexStart;

	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	TSubclassOf<ACharacter> TargetCharacter; //블루프린트에서 캐릭터 설정, 해당 캐릭터 AI빙의 spawn관련으로 설정
	class APlayerCharacter* DollCharacter;



};
