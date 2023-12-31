#include "MyGameNetworkManager.h"

AMyGameNetworkManager::AMyGameNetworkManager()
{
    ClientSocket = nullptr;
}

AMyGameNetworkManager::~AMyGameNetworkManager()
{
    CloseConnection();
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
        UE_LOG(LogTemp, Error, TEXT("FFFFFFFFFFFFFFFFF."));
        return false;
    }

    return ClientSocket && ClientSocket->Connect(*Endpoint.ToInternetAddr());
}

void AMyGameNetworkManager::SendData(const FString& DataToSend)
{
    if (!ClientSocket) return;

    // ���ڿ��� UTF-8�� ���ڵ�
    FTCHARToUTF8 Convert(*DataToSend);
    int32 BytesSent = 0;
    ClientSocket->Send((uint8*)Convert.Get(), Convert.Length(), BytesSent);
}

void AMyGameNetworkManager::CloseConnection()
{
    if (ClientSocket)
    {
        ClientSocket->Close();
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
        ClientSocket = nullptr;
    }
}