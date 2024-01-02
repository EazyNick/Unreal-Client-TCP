#include "MyGameNetworkManager.h"


AMyGameNetworkManager::AMyGameNetworkManager()
{
    //Ŭ���̾�Ʈ ������ nullptr�� �ʱ�ȭ
    ClientSocket = nullptr;
}


AMyGameNetworkManager::~AMyGameNetworkManager()
{
    //��ü�� �ı��� �� CloseConnection �Լ��� ȣ���Ͽ� ���� �ִ� ��� ��Ʈ��ũ ������ �ݰ�, ���� ���ҽ��� ����
    CloseConnection();
}


bool AMyGameNetworkManager::ConnectToServer()
{
    FIPv4Address ServerIpv4;
    FIPv4Address::Parse(this->ServerIP, ServerIpv4); // ServerIP ���� FIPv4Address�� �Ľ�, ServerIpv4�� IP �� �����
    FIPv4Endpoint Endpoint(ServerIpv4, this->ServerPort); // IP, ��Ʈ��ȣ�� ������ ��������Ʈ ����


    ClientSocket = FTcpSocketBuilder(TEXT("UE5TCPClient")) // ������ ���� �̸�
        .AsBlocking() // ���ŷ ���, ���� �۾�(��: ������ ����)�� �Ϸ�� ������ �ش� �۾��� ȣ���� �����尡 ���, ��Ʈ��ũ ���� �� �ڵ� ���
        .AsReusable() // ������ ���� �����ϰ� ����
        .Build(); // �ռ� ������ �ɼǿ� ���� ���� ������ ����

    // ������ �õ��ϰ� ����� 'bIsConnected' ������ �����մϴ�.
    bool bIsConnected = ClientSocket && ClientSocket->Connect(*Endpoint.ToInternetAddr());

    if (bIsConnected)
    {
        // ���� ����
        UE_LOG(LogTemp, Warning, TEXT("SSSSSSSSSSSSSSSSSS."));

    }
    else
    {
        // ���� ����
        UE_LOG(LogTemp, Error, TEXT("FFFFFFFFFFFFFFFFF."));

    }
    // ���� ���� ���θ� ��ȯ�մϴ�.
    return bIsConnected;
}


void AMyGameNetworkManager::SendData(const FString& DataToSend)
{
    if (!ClientSocket) return;


    // ���ڿ��� UTF-8�� ���ڵ�
    FTCHARToUTF8 Convert(*DataToSend);
    int32 BytesSent = 0; // ���۵� ����Ʈ ���� BytesSent�� ����
    ClientSocket->Send((uint8*)Convert.Get(), Convert.Length(), BytesSent);
    //Get() �޼���� ���ڵ��� ���ڿ��� ������ ����Ű�� �����͸� ��ȯ
    //Convert.Length() ���ڵ��� �������� ����(����Ʈ ��)�� ��ȯ�մϴ�. �̴� �����Ϸ��� �������� ũ��
    //���۵� ����Ʈ ���� ������ ����. Send �Լ��� ������ ��Ʈ��ũ�� ���� ���۵� ����Ʈ ���� �� ������ ���
}


void AMyGameNetworkManager::CloseConnection()
{
    if (ClientSocket)
    {
        ClientSocket->Close(); // ���� �ݱ�
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket); // ���� �ı�(����)
        ClientSocket = nullptr; // �ʱ�ȭ
    }
}
