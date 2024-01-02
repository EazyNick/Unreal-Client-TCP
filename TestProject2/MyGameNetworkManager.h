//Once activity
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Common/TcpSocketBuilder.h"
// Unreal의 자동 코드 생성 시스템에 의해 생성된 파일을 포함
// 액터에 대한 메타데이터를 처리하고, Unreal Engine의 블루프린트 시스템과의 통합을 가능
#include "MyGameNetworkManager.generated.h"


//UCLASS() 매크로는 이 클래스가 Unreal Engine의 객체 시스템에 의해 관리되는 클래스임을 나타냅니다. 
//GENERATED_BODY() 매크로는 Unreal Engine의 자동 코드 생성 기능에 필요한 코드를 추가
UCLASS()
class AMyGameNetworkManager : public AActor
{   // 생성자 필요 시 GENERATED_UCLASS_BODY 로 변경
    GENERATED_BODY()

public:
    // Constructor(생성자)
    AMyGameNetworkManager();

    //해당 변수를 Unreal에서 사용 가능하게 설정
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    FString ServerIP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network")
    int32 ServerPort;

    // Destructor(소멸자)
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
