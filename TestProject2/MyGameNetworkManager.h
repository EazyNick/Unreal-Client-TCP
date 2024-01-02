//Once activity
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Common/TcpSocketBuilder.h"
// Unreal�� �ڵ� �ڵ� ���� �ý��ۿ� ���� ������ ������ ����
// ���Ϳ� ���� ��Ÿ�����͸� ó���ϰ�, Unreal Engine�� �������Ʈ �ý��۰��� ������ ����
#include "MyGameNetworkManager.generated.h"


//UCLASS() ��ũ�δ� �� Ŭ������ Unreal Engine�� ��ü �ý��ۿ� ���� �����Ǵ� Ŭ�������� ��Ÿ���ϴ�. 
//GENERATED_BODY() ��ũ�δ� Unreal Engine�� �ڵ� �ڵ� ���� ��ɿ� �ʿ��� �ڵ带 �߰�
UCLASS()
class AMyGameNetworkManager : public AActor
{   // ������ �ʿ� �� GENERATED_UCLASS_BODY �� ����
    GENERATED_BODY()

public:
    // Constructor(������)
    AMyGameNetworkManager();

    //�ش� ������ Unreal���� ��� �����ϰ� ����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    FString ServerIP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    int32 ServerPort;

    // Destructor(�Ҹ���)
    // virtual - ���� �Ļ� Ŭ������ AMyGameNetworkManager�� ��ӹް�, �Ҹ��ڸ� �ߺ���Ű�� �ʱ� ���� ��
    // �����ڴ� ���� �� �������� ���̿��� �ϹǷ� virtual�� ���� �ȵ�.
    virtual ~AMyGameNetworkManager();

    // Function to connect to the server
    UFUNCTION(BlueprintCallable, Category = "Network")
    bool ConnectToServer();

    // Function to send data
    UFUNCTION(BlueprintCallable, Category = "Network")
    void SendData(const FString& DataToSend);

    // Function to close the connection
    UFUNCTION(BlueprintCallable, Category = "Network")
    void CloseConnection();

private:
    // Client socket(Pointer)
    FSocket* ClientSocket;
};
