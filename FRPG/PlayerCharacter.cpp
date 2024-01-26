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

	//Ŭ���̾�Ʈ ���� �ĺ���ȣ ��������
	APlayerState* MyPlayerState = GetPlayerState();
	if (MyPlayerState)
	{
		FString PlayerId = MyPlayerState->GetUniqueId().ToString();
		UE_LOG(LogTemp, Log, TEXT("Clinet ID : %s"), *PlayerId);
		return PlayerId;
	}
	else
	{
		// MyPlayerState�� null�� ��� �ٽ� ȣ��
		UE_LOG(LogTemp, Warning, TEXT("MyPlayerState is null"));
		return "G000";
	}

}

//// ĳ���� ������ �޾ƿ���
//FString APlayerCharacter::GetPlayerMove() const
//{
//
//	FVector OutLocation = GetActorLocation();  // ���� ��ġ ��������
//	FRotator OutRotation = GetActorRotation(); // ���� ȸ�� ��������	
//	FVector OutVelocity = GetVelocity();       // ���� �ӵ� ��������
//
//	FString PlayerStateString = FString::Printf(TEXT("Location: %s, Rotation: %s, Velocity: %s"),
//		*OutLocation.ToString(),
//		*OutRotation.ToString(),
//		*OutVelocity.ToString());
//	UE_LOG(LogTemp, Log, TEXT("%s"), *PlayerStateString);
//
//	return PlayerStateString;
//}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetPlayerID();
}

//// Called every frame
//void APlayerCharacter::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	//CurrentLocation = GetActorLocation();
//	//CurrentRotation = GetActorRotation();
//	//CurrentVelocity = GetVelocity();
//	// ���� ��ġ, ȸ��, �ӵ��� ������Ʈ�մϴ�.
//	//GetPlayerMove();
//}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

