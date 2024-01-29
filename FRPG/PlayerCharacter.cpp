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

//void SomeFunction()
//{
//	AMyGameNetworkManager* MyNetworkManager = nullptr;
//
//	for (TActorIterator<AMyGameNetworkManager> It(GetWorld()); It; ++It)
//	{
//		MyNetworkManager = *It;
//		break; // 첫 번째 인스턴스를 찾으면 반복을 종료합니다.
//	}
//
//	if (MyNetworkManager)
//	{
//		// 이제 UpdateCharacterState() 함수를 호출할 수 있습니다.
//		MyNetworkManager->UpdateCharacterState();
//	}
//}

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
	UE_LOG(LogTemp, Log, TEXT("%s"), *PlayerStateString);

	return PlayerStateString;
}

void APlayerCharacter::UpdateCharacterState(AMyGameNetworkManager* MyCharacterNetworkManager)
{

	APlayerCharacter* MyCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter) // MyCharacter는 캐릭터에 대한 참조입니다.
	{
		FVector Location = MyCharacter->GetActorLocation();
		FRotator Rotation = MyCharacter->GetActorRotation();
		FVector Velocity = MyCharacter->GetCharacterMovement()->Velocity;

		// 이제 위치, 회전, 속도 값을 전송하는 로직을 구현하세요.
		MyCharacterNetworkManager->SendData_Movement(Location, Rotation, Velocity);
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	// AMyGameNetworkManager 인스턴스를 생성합니다.
	AMyGameNetworkManager* MyCharacterNetworkManager = NewObject<AMyGameNetworkManager>(this, AMyGameNetworkManager::StaticClass());

	if (MyCharacterNetworkManager)
	{
		// 서버 IP와 포트를 설정합니다.
		MyCharacterNetworkManager->SetServerIP(TEXT("127.0.0.1")); // 예시 IP
		MyCharacterNetworkManager->SetServerPort(12332); // 예시 포트

		// 서버에 연결을 시도합니다.
		if (MyCharacterNetworkManager->ConnectToServer())
		{
			// 연결 성공
			//GetPlayerMove();
			UpdateCharacterState(MyCharacterNetworkManager);
		}
	}
	GetPlayerID();
}

//// Called every frame
//void APlayerCharacter::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	//CurrentLocation = GetActorLocation();
//	//CurrentRotation = GetActorRotation();
//	//CurrentVelocity = GetVelocity();
//	// 현재 위치, 회전, 속도를 업데이트합니다.
//	//GetPlayerMove();
//}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

