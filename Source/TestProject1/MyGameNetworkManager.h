#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Common/TcpSocketBuilder.h"
#include "MyGameNetworkManager.generated.h"

UCLASS()
class AMyGameNetworkManager : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AMyGameNetworkManager();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    FString ServerIP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    int32 ServerPort;

    // Destructor
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
    // Client socket
    FSocket* ClientSocket;
};