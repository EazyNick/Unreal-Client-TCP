// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameNetworkManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Common/TcpSocketBuilder.h"
#include "Sockets.h"
#include "Kismet/GameplayStatics.h"

AMyGameNetworkManager::AMyGameNetworkManager()
{
    ClientSocket = nullptr;
    // Set the timer to call SendData_Movement every 0.1 seconds (or any other suitable interval)
    //if (GetWorld())
    //{
    //    GetWorldTimerManager().SetTimer(PlayerMoveUpdateHandle, this, &AMyGameNetworkManager::SendData_Movement, 0.1f, true);
    //}
}

AMyGameNetworkManager::~AMyGameNetworkManager()
{
    CloseConnection();
    //if (GetWorld())
    //{
    //    GetWorldTimerManager().ClearTimer(PlayerMoveUpdateHandle);
    //}
}

bool AMyGameNetworkManager::ConnectToServer()
{
    FIPv4Address ServerIpv4;
    FIPv4Address::Parse(this->ServerIP, ServerIpv4);
    FIPv4Endpoint Endpoint(ServerIpv4, this->ServerPort);

    ClientSocket = FTcpSocketBuilder(TEXT("UE5TCPClient"))
        .AsBlocking()
        .AsReusable()
        .Build();

    if (ClientSocket && ClientSocket->Connect(*Endpoint.ToInternetAddr()))
    {
        // ���� ����
        UE_LOG(LogTemp, Warning, TEXT("SSSSSSSSSSSSSSSSSS."));
        return true;
    }
    else
    {
        // ���� ����
        UE_LOG(LogTemp, Error, TEXT("FFFFFFFFFFFFFFFFF."));
        UE_LOG(LogTemp, Error, TEXT("FFFFFFFFFFFFFFFFF."));
        UE_LOG(LogTemp, Error, TEXT("FFFFFFFFFFFFFFFFF."));
        return false;
    }

    return ClientSocket && ClientSocket->Connect(*Endpoint.ToInternetAddr());
}

void AMyGameNetworkManager::SendData_Movement(FVector CurrentLocation1, FRotator CurrentRotation1, FVector CurrentVelocity1)
{
    if (!ClientSocket) return;

    UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s, Velocity: %s"),
        *CurrentLocation1.ToString(),
        *CurrentRotation1.ToString(),
        *CurrentVelocity1.ToString());

    FString PlayerStateString = FString::Printf(TEXT("Location: %s, Rotation: %s, Velocity: %s"),
        *CurrentLocation1.ToString(),
        *CurrentRotation1.ToString(),
        *CurrentVelocity1.ToString());

    // ���ڿ��� UTF-8�� ���ڵ�
    FTCHARToUTF8 Convert(PlayerStateString);
    int32 BytesSent = 0;
    ClientSocket->Send((uint8*)Convert.Get(), Convert.Length(), BytesSent);
}

//void AMyGameNetworkManager::SendData_Movement()
//{
//    if (!ClientSocket) return;
//
//    // APlayerCharacter�� ���� Ŭ���� ���ο��� ȣ��
//    FString PlayerMoveInfo = GetPlayerMove();
//    UE_LOG(LogTemp, Warning, TEXT("Sending movement data: %s"), *PlayerMoveInfo);
//    // ���ڿ��� UTF-8�� ���ڵ�
//    FTCHARToUTF8 Convert(PlayerMoveInfo);
//    int32 BytesSent = 0;
//    ClientSocket->Send((uint8*)Convert.Get(), Convert.Length(), BytesSent);
//}

//void AMyGameNetworkManager::SendData(const FString& DataToSend)
//{
//    if (!ClientSocket) return;
//
//    // APlayerCharacter�� ���� Ŭ���� ���ο��� ȣ��
//    FString PlayerMoveInfo = GetPlayerMove();
//
//    // ���ڿ��� UTF-8�� ���ڵ�
//    FTCHARToUTF8 Convert(DataToSend);
//    int32 BytesSent = 0;
//    ClientSocket->Send((uint8*)Convert.Get(), Convert.Length(), BytesSent);
//}

void AMyGameNetworkManager::CloseConnection()
{
    if (ClientSocket)
    {
        ClientSocket->Close();
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
        ClientSocket = nullptr;
    }
}

void AMyGameNetworkManager::UpdateCharacterState()
{

    APlayerCharacter* MyCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

    if (MyCharacter) // MyCharacter�� ĳ���Ϳ� ���� �����Դϴ�.
    {
        FVector Location = MyCharacter->GetActorLocation();
        FRotator Rotation = MyCharacter->GetActorRotation();
        FVector Velocity = MyCharacter->GetCharacterMovement()->Velocity;

        // ���� ��ġ, ȸ��, �ӵ� ���� �����ϴ� ������ �����ϼ���.
        SendData_Movement(Location, Rotation, Velocity);
    }
}

bool AMyGameNetworkManager::ReceiveData(FString& OutReceivedData)
{
    if (!ClientSocket) return false;

    // ���� ���� �غ�
    TArray<uint8> ReceivedData;
    uint32 Size;
    while (ClientSocket->HasPendingData(Size))
    {
        ReceivedData.Init(0, FMath::Min(Size, 65507u));

        int32 Read = 0;
        ClientSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);

        if (Read > 0) {
            // ���ŵ� �����͸� FString���� ��ȯ
            FString ReceivedString = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(ReceivedData.GetData())));
            OutReceivedData += ReceivedString;
            UE_LOG(LogTemp, Warning, TEXT("Received data: %s"), *ReceivedString);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Read < 0"));
        }
    }

    return true;
}

//// Called every frame
//void APlayerCharacter::Tick(float DeltaTime)
//{
//    Super::Tick(DeltaTime);
//    CurrentLocation = GetActorLocation();
//    CurrentRotation = GetActorRotation();
//    CurrentVelocity = GetVelocity();
//    // ���� ��ġ, ȸ��, �ӵ��� ������Ʈ�մϴ�.
//    //GetPlayerMove();
//}

void AMyGameNetworkManager::BeginPlay()
{
    Super::BeginPlay();

    FTimerHandle CharacterUpdateTimer;
    GetWorld()->GetTimerManager().SetTimer(CharacterUpdateTimer, this, &AMyGameNetworkManager::UpdateCharacterState, 0.1f, true);

    APlayerCharacter* MyCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
    if (MyCharacter)
    {
        // ĳ���� ������ ���������� ��������ϴ�.
    }
}