// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameNetworkManager.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayerCam = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCam"));
	PlayerCamSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring"));

	PlayerCamSpringArm->SetupAttachment(RootComponent);
	PlayerCamSpringArm->SetUsingAbsoluteRotation(true);
	PlayerCamSpringArm->bDoCollisionTest = false;

	PlayerCam->SetupAttachment(PlayerCamSpringArm);
	PlayerCam->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);

	
}

FString APlayerCharacter::GetPlayerID() const
{

	//클라이언트 고유 식별번호 가져오기
	APlayerState* MyPlayerState = GetPlayerState();
	if (MyPlayerState)
	{
		FString PlayerId = MyPlayerState->GetUniqueId().ToString();
		UE_LOG(LogTemp, Log, TEXT("Clinet ID : %s"), *PlayerId);
		return PlayerId;
	}
	else
	{
		// MyPlayerState가 null인 경우 다시 호출
		UE_LOG(LogTemp, Warning, TEXT("MyPlayerState is null"));
		return "G000";
	}

}

// 캐릭터 움직임 받아오기
FString APlayerCharacter::GetPlayerMove() const
{

	FVector OutLocation = GetActorLocation();  // 현재 위치 가져오기
	FRotator OutRotation = GetActorRotation(); // 현재 회전 가져오기	
	FVector OutVelocity = GetVelocity();       // 현재 속도 가져오기

	FString PlayerStateString = FString::Printf(TEXT("Location: %s, Rotation: %s, Velocity: %s"),
		*OutLocation.ToString(),
		*OutRotation.ToString(),
		*OutVelocity.ToString());
	//UE_LOG(LogTemp, Log, TEXT("%s"), *PlayerStateString);

	return PlayerStateString;
}

void APlayerCharacter::UpdateCharacterState()
{
	APlayerCharacter* MyCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	AMyGameNetworkManager* MyCharacterNetworkManager = AMyGameNetworkManager::GetInstance(this);

	if (MyCharacter) // MyCharacter는 캐릭터에 대한 참조입니다.
	{
		FVector Location = MyCharacter->GetActorLocation();
		FRotator Rotation = MyCharacter->GetActorRotation();
		FVector Velocity = MyCharacter->GetCharacterMovement()->Velocity;

		// 이제 위치, 회전, 속도 값을 전송하는 로직을 구현하세요.
		MyCharacterNetworkManager->SendData_Movement(Location, Rotation, Velocity);

		// Return the values as a tuple
		//return std::make_tuple(Location, Rotation, Velocity);
	}
	
	
	//FVector InvalidVector(-1.f, -1.f, -1.f);
	//FRotator InvalidRotator(-1.f, -1.f, -1.f);

	// Return the values as a tuple
	//return std::make_tuple(InvalidVector, InvalidRotator, InvalidVector);
}

 //Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	CameraValue = FVector(PlayerCamSpringArm->TargetArmLength, PlayerCamSpringArm->GetDesiredRotation().Pitch, PlayerCamSpringArm->GetDesiredRotation().Yaw);
	CameraZoomValue = CameraValue - FVector(350, -45, 0);
	UE_LOG(LogTemp, Log, TEXT("Value = %s"), *CameraValue.ToString());

	AMyGameNetworkManager* MyCharacterNetworkManager = AMyGameNetworkManager::GetInstance(this);

	if (MyCharacterNetworkManager)
	{
		// 서버 IP와 포트를 설정합니다.
		MyCharacterNetworkManager->SetServerIP(TEXT("127.0.0.1")); // 예시 IP
		MyCharacterNetworkManager->SetServerPort(12332); // 예시 포트

		// 서버에 연결을 시도합니다.
		if (MyCharacterNetworkManager->ConnectToServer())
		{
			// 연결 성공
			bIsConnected = true;
			//UpdateCharacterState();
			//FString Result = MyCharacterNetworkManager->ReceiveData();
			//UE_LOG(LogTemp, Warning, TEXT("Received data: %s"), *Result);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle_Update, this, &APlayerCharacter::UpdateCharacterState, 1.5f, true);
			//GetPlayerMove();
			//UpdateCharacterState();
			//CharacterNetworkManager->Shutdown();
		}
	}
	GetPlayerID();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//int Tickcut = 0;

	if (bCameraZoom) {
		CameraSmoothMove();
	}
	if (IsDoll)
	{
		RC_Move();
	}

	//Tickcut += 1;
	//AMyGameNetworkManager* MyCharacterNetworkManager = AMyGameNetworkManager::GetInstance(this);

	//UpdateCharacterState();

	//MyCharacterNetworkManager->ReceiveData();

	if (!bHasRetrievedInstance)
	{
		bHasRetrievedInstance = true;
	}

	if (bIsConnected)
	{
		//AMyGameNetworkManager* MyCharacterNetworkManager = AMyGameNetworkManager::GetInstance(this);
		//UpdateCharacterState();
		//MyCharacterNetworkManager->ReceiveData();
	}

	//CurrentLocation = GetActorLocation();
	//CurrentRotation = GetActorRotation();
	//CurrentVelocity = GetVelocity();
	// 현재 위치, 회전, 속도를 업데이트합니다.
	//GetPlayerMove();
	//CurrentLocation = GetActorLocation();
	//CurrentRotation = GetActorRotation();
	//CurrentVelocity = GetVelocity();
	// 현재 위치, 회전, 속도를 업데이트합니다.
	//GetPlayerMove();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("CameraZoomIn", IE_Pressed, this, &APlayerCharacter::CameraZoomIn);
	InputComponent->BindAction("CameraZoomOut", IE_Pressed, this, &APlayerCharacter::CameraZoomOut);

}

void APlayerCharacter::CameraZoomIn()
{
	//PlayerCamSpringArm->SetWorldRotation(FRotator(CameraZoomValue.Y, CameraZoomValue.Z, 0));
	//PlayerCamSpringArm->TargetArmLength = CameraZoomValue.X;
	if (!bCameraZoom)
	{
		TargetCameraIndex = 1;
		if (TargetCameraIndex != CurrentCameraIndex) //�̵���ų ī�޶� �ε����� ���� ī�޶� �ε����� �ٸ� ��쿡�� ī�޶� �̵�
		{
			bCameraZoom = true;
			CameraTimerWeightedValue = 0.0f;
		}

	}
}

void APlayerCharacter::CameraZoomOut()
{
	//PlayerCamSpringArm->SetWorldRotation(FRotator(CameraValue.Y, CameraValue.Z, 0));
	//PlayerCamSpringArm->TargetArmLength = CameraValue.X;
	if (!bCameraZoom)
	{
		TargetCameraIndex = 0;
		if (TargetCameraIndex != CurrentCameraIndex)
		{
			bCameraZoom = true;
			CameraTimerWeightedValue = 0.0f;
		}
	}
}

void APlayerCharacter::CameraSmoothMove()
{
	if (CameraTimerWeightedValue < 5.0f)
	{
		CameraTimerWeightedValue += 0.1f;
	}
	if (TargetCameraIndex) //
	{
		CameraTimer += (0.02f / CameraTimerWeightedValue);
	}
	else
	{
		CameraTimer -= (0.02f / CameraTimerWeightedValue);
	}

	float SpringArmLength = UKismetMathLibrary::Lerp(CameraValue.X, CameraZoomValue.X, CameraTimer);
	float RotatorX = UKismetMathLibrary::Lerp(CameraValue.Y, CameraZoomValue.Y, CameraTimer);
	float RotatorY = UKismetMathLibrary::Lerp(CameraValue.Z, CameraZoomValue.Z, CameraTimer);

	PlayerCamSpringArm->SetWorldRotation(FRotator(RotatorX, RotatorY, 0));
	PlayerCamSpringArm->TargetArmLength = SpringArmLength;

	if (CameraTimer < 0) //
	{
		bCameraZoom = false;
		CameraTimer = 0.0f;
		CurrentCameraIndex = 0;
	}
	else if (CameraTimer > 1) //
	{
		bCameraZoom = false;
		CameraTimer = 1.0f;
		CurrentCameraIndex = 1;
	}

}

void APlayerCharacter::ReceiveCharacterData(FString StringData) //
{
	UE_LOG(LogTemp, Log, TEXT("Receive"));
	UE_LOG(LogTemp, Log, TEXT("Data: %s"), *StringData);
	TArray<FString> DataArray;
	StringData.ParseIntoArray(DataArray, TEXT(","));
	UE_LOG(LogTemp, Log, TEXT("VlcData: %s"), *DataArray[2]);
	Rc_Position.InitFromString(DataArray[0]);
	Rc_Rotation.InitFromString(DataArray[1]);
	Rc_Velocity.InitFromString(DataArray[2]);
}

void APlayerCharacter::RC_Move()
{
	this->AddMovementInput(Rc_Velocity);
}

void APlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (bIsConnected)
	{
		AMyGameNetworkManager* MyCharacterNetworkManager = AMyGameNetworkManager::GetInstance(this);

	// Ensure network manager is not null

		// Close the network connection
		MyCharacterNetworkManager->Shutdown();

		// Optional: Clear the reference to the network manager
		//MyCharacterNetworkManager = nullptr;
		bIsConnected = false;
		bHasRetrievedInstance = false;
		
	}
}
