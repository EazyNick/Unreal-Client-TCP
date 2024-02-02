#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter.h"
//#include "MyStructureFactory.h"
#include "MyGameNetworkManager.generated.h"
    
UCLASS()
class AMyGameNetworkManager : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AMyGameNetworkManager();

    static FCriticalSection InstanceCriticalSection;

    static AMyGameNetworkManager* GetInstance(UObject* WorldContextObject);
    void Shutdown();

    void SetServerIP(const FString& NewServerIP) { ServerIP = NewServerIP; }
    void SetServerPort(int32 NewServerPort) { ServerPort = NewServerPort; }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    FString ServerIP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    int32 ServerPort;

    // Function to connect to the server
    UFUNCTION(BlueprintCallable, Category = "Network")
    bool ConnectToServer();


    UFUNCTION(BlueprintCallable, Category = "Network")
    void SendData_Movement(FVector CurrentLocation1, FRotator CurrentRotation1, FVector CurrentVelocity1);

    //UFUNCTION(BlueprintCallable, Category = "Network")
    //void SendData_Movement();

    //// Function to send data
    //UFUNCTION(BlueprintCallable, Category = "Network")
    //void SendData(const FString& DataToSend);

    // Function to close the connection
    UFUNCTION(BlueprintCallable, Category = "Network")
    void CloseConnection();

    UFUNCTION(Category = "Network")
    void UpdateCharacterState();

    //UFUNCTION(Category = "Network")
    //void SendData_Movement(FCharacterState State);

    UFUNCTION(BlueprintCallable, Category = "Network")
    FString ReceiveData();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // Destructor
    virtual ~AMyGameNetworkManager();

    //// Timer handle for movement updates
    //FTimerHandle PlayerMoveUpdateHandle;

private:
    static AMyGameNetworkManager* Instance;
    // Client socket
    FSocket* ClientSocket;
};

AMyGameNetworkManager* AMyGameNetworkManager::Instance = nullptr;
