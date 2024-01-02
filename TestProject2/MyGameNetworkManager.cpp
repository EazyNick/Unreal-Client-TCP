#include "MyGameNetworkManager.h"


AMyGameNetworkManager::AMyGameNetworkManager()
{
    //클라이언트 소켓을 nullptr로 초기화
    ClientSocket = nullptr;
}


AMyGameNetworkManager::~AMyGameNetworkManager()
{
    //객체가 파괴될 때 CloseConnection 함수를 호출하여 열려 있는 모든 네트워크 연결을 닫고, 관련 리소스를 정리
    CloseConnection();
}


bool AMyGameNetworkManager::ConnectToServer()
{
    FIPv4Address ServerIpv4;
    FIPv4Address::Parse(this->ServerIP, ServerIpv4); // ServerIP 값을 FIPv4Address에 파싱, ServerIpv4에 IP 값 저장됨
    FIPv4Endpoint Endpoint(ServerIpv4, this->ServerPort); // IP, 포트번호를 가지고 엔드포인트 설정


    ClientSocket = FTcpSocketBuilder(TEXT("UE5TCPClient")) // 생성할 소켓 이름
        .AsBlocking() // 블로킹 모드, 소켓 작업(예: 데이터 수신)이 완료될 때까지 해당 작업을 호출한 스레드가 대기, 네트워크 지연 시 코드 블록
        .AsReusable() // 소켓을 재사용 가능하게 설정
        .Build(); // 앞서 설정한 옵션에 따라 실제 소켓을 생성

    // 연결을 시도하고 결과를 'bIsConnected' 변수에 저장합니다.
    bool bIsConnected = ClientSocket && ClientSocket->Connect(*Endpoint.ToInternetAddr());

    if (bIsConnected)
    {
        // 연결 성공
        UE_LOG(LogTemp, Warning, TEXT("SSSSSSSSSSSSSSSSSS."));

    }
    else
    {
        // 연결 실패
        UE_LOG(LogTemp, Error, TEXT("FFFFFFFFFFFFFFFFF."));

    }
    // 연결 성공 여부를 반환합니다.
    return bIsConnected;
}


void AMyGameNetworkManager::SendData(const FString& DataToSend)
{
    if (!ClientSocket) return;


    // 문자열을 UTF-8로 인코딩
    FTCHARToUTF8 Convert(*DataToSend);
    int32 BytesSent = 0; // 전송된 바이트 수는 BytesSent에 저장
    ClientSocket->Send((uint8*)Convert.Get(), Convert.Length(), BytesSent);
    //Get() 메서드는 인코딩된 문자열의 시작을 가리키는 포인터를 반환
    //Convert.Length() 인코딩된 데이터의 길이(바이트 수)를 반환합니다. 이는 전송하려는 데이터의 크기
    //전송된 바이트 수를 저장할 변수. Send 함수는 실제로 네트워크를 통해 전송된 바이트 수를 이 변수에 기록
}


void AMyGameNetworkManager::CloseConnection()
{
    if (ClientSocket)
    {
        ClientSocket->Close(); // 소켓 닫기
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket); // 소켓 파괴(제거)
        ClientSocket = nullptr; // 초기화
    }
}
