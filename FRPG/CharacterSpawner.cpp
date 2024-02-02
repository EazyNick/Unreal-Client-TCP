// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSpawner.h"
#include "MyGameNetworkManager.h"
#include "PlayerCharacter.h"

// Sets default values
ACharacterSpawner::ACharacterSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnCharacter();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACharacterSpawner::SendData, 1.0f, true, 5.0f);
}

// Called every frame
void ACharacterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterSpawner::SpawnCharacter() //스포너 좌표로 캐릭터 스폰
{
	if (TargetCharacter)
	{
		FVector Pos = GetActorLocation();
		DollCharacter = Cast<APlayerCharacter>(GetWorld()->SpawnActor(TargetCharacter, &Pos));
		DollCharacter->IsDoll = true;
	}
}

void ACharacterSpawner::SendData() //데이터 보내기
{
	AMyGameNetworkManager* MyCharacterNetworkManager = AMyGameNetworkManager::GetInstance(this);

	if (DollCharacter)
	{
		UE_LOG(LogTemp, Log, TEXT("Send"));
		FVector Pos = FVector::ZeroVector;

		FRotator Rot = FRotator::ZeroRotator;
		FString imsi = MyCharacterNetworkManager->ReceiveData();
		FVector Vlc = ParseVelocityFromString(imsi);
		//FVector Vlc = FVector(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1), 0);
		FString CharacterData = (Pos.ToString() + "," + Rot.ToString() + "," + Vlc.ToString());
		DollCharacter->ReceiveCharacterData(CharacterData);
	}
}

FVector ACharacterSpawner::ParseVelocityFromString(const FString& Input) {
    //FVector Velocity(0, 0, 0); // 기본값으로 초기화

    // "Velocity:" 문자열을 찾습니다.
	int32 LastVelocityIndex = Input.Find(TEXT("Velocity:"), ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	if (LastVelocityIndex != INDEX_NONE) {
		FString VelocityString = Input.Mid(LastVelocityIndex);

		// 공백으로 문자열을 분리하여 각 축의 값을 파싱합니다.
		TArray<FString> ParsedValues;
		VelocityString.ParseIntoArray(ParsedValues, TEXT(" "), true);

		// X, Y, Z 축의 값을 파싱합니다.
		for (int32 i = 1; i < ParsedValues.Num(); ++i) {
			FString AxisValue = ParsedValues[i];
			if (AxisValue.StartsWith(TEXT("X="))) {
				Velocity.X = FCString::Atof(*AxisValue.Mid(2));
			}
			else if (AxisValue.StartsWith(TEXT("Y="))) {
				Velocity.Y = FCString::Atof(*AxisValue.Mid(2));
			}
			else if (AxisValue.StartsWith(TEXT("Z="))) {
				Velocity.Z = FCString::Atof(*AxisValue.Mid(2));
			}
		}
	}

	return Velocity;
}