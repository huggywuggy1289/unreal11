//#include <windows.h>
//
//// D3D 사용에 필요한 헤더파일
//#include <d3d11.h>
//#include <d3dcompiler.h>
//#include <dxgi.h>
//
//// D3D 사용에 필요한 라이브러리
//#pragma comment(lib, "user32")
//#pragma comment(lib, "d3d11")
//#pragma comment(lib, "d3dcompiler")
//
//#include <d3d11.h>
//#include <d3dcompiler.h>
//
//#include "../ImGui/imgui.h"
//#include "../ImGui/imgui_internal.h"
//#include "../ImGui/imgui_impl_dx11.h"
//#include "../ImGui/imgui_impl_win32.h"
//
//struct FVertexSimple
//{
//    float x, y, z; // 위치
//    float r, g, b, a; // 색상
//};
//
//// Structure for a 3D vector
//struct FVector {
//    float x, y, z;
//    FVector(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
//};
//
//
//#include "Sphere.h"
//
//// ==========================================
//// Direct3D 11 렌더러 클래스
//// ==========================================
//class URenderer
//{
//public:
//    // I가 붙은 것: D3D11에서 제공하는 그래픽 카드 제어용 기능(인터페이스/객체) 포인터
//    ID3D11Device* Device = nullptr;  // GPU와 통신하기 위한 Direct3D 장치
//    ID3D11DeviceContext* DeviceContext = nullptr; // GPU 명령 하달(일꾼 역할)1
//    IDXGISwapChain* SwapChain = nullptr;           // 프레임 버퍼를 교체하는 데 사용되는 스왑 체인2
//
//    // 렌더링 리소스 및 파이프라인 상태
//    ID3D11Texture2D* FrameBuffer = nullptr;            // 대상이 될 진짜 텍스처
//    ID3D11RenderTargetView* FrameBufferRTV = nullptr;  // 렌더 타겟 뷰
//    ID3D11RasterizerState* RasterizerState = nullptr;   // 래스터라이저 상태
//    ID3D11Buffer* ConstantBuffer = nullptr;            // 쉐이더에 데이터를 전달하기 위한 상수 버퍼 (추후 사용)
//
//    // 셰이더 관련 리소스
//    ID3D11VertexShader* SimpleVertexShader = nullptr;
//    ID3D11PixelShader* SimplePixelShader = nullptr;
//    ID3D11InputLayout* SimpleInputLayout = nullptr;
//    unsigned int Stride = 0;
//
//    // 옵션 세팅
//    FLOAT ClearColor[4] = { 0.025f, 0.025f, 0.025f, 1.0f }; // 화면을 초기화(clear)할 때 사용할 색상 (RGBA)
//    D3D11_VIEWPORT ViewportInfo = {};                            // 렌더링 영역 정보
//
//public:
//    // 기본 프레임워크 초기화
//    void Create(HWND hWindow)
//    {
//        CreateDeviceAndSwapChain(hWindow); // GPU 연결 + 화면 출력 통로 만들기
//        CreateFrameBuffer(); // 그림 그릴 캔버스 준비
//        CreateRasterizerState(); // 그리기 방식 설정
//    }
//
//    // 장치 및 스왑 체인 생성
//    void CreateDeviceAndSwapChain(HWND hWindow)
//    {
//        // 지원하는 Direct3D 기능 레벨을 정의 = 그래픽 카드에게 요구할 스펙(버전) 결정
//        D3D_FEATURE_LEVEL featurelevels[] = { D3D_FEATURE_LEVEL_11_0 };
//
//        // 스왑 체인 설정 구조체 초기화
//        DXGI_SWAP_CHAIN_DESC swapchaindesc = {};
//        swapchaindesc.BufferDesc.Width = 0; // 창 크기에 맞게 자동으로 설정
//        swapchaindesc.BufferDesc.Height = 0; // 창 크기에 맞게 자동으로 설정
//        swapchaindesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // 색상 포맷
//        swapchaindesc.SampleDesc.Count = 1; // 멀티 샘플링 비활성화
//        swapchaindesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 렌더 타겟으로 사용
//        swapchaindesc.BufferCount = 2; // 더블 버퍼링
//        swapchaindesc.OutputWindow = hWindow; // 렌더링할 창 핸들
//        swapchaindesc.Windowed = TRUE; // 창 모드
//        swapchaindesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD; // 스왑 방식
//
//        // Direct3D 장치와 스왑 체인을 생성
//        D3D11CreateDeviceAndSwapChain(
//            nullptr,                      // 기본 그래픽 카드(0번 디바이스) 사용
//            D3D_DRIVER_TYPE_HARDWARE,     // CPU 에뮬레이션이 아닌 진짜 하드웨어 GPU 가속 사용
//            nullptr,                      // 소프트웨어 구동 드라이버 안 씀
//            D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_DEBUG, // 디버깅 기능 켜기
//            featurelevels,                // 아까 정의한 버전 정보 (DX11)
//            ARRAYSIZE(featurelevels),     // 버전 배열의 개수 (1개)
//            D3D11_SDK_VERSION,            // 현재 시스템의 DX SDK 기본 버전
//            &swapchaindesc,               // 스왑체인 초기화한 내용 담은 배열의주소
//            &SwapChain,                   // [결과물 1] 생성된 스왑체인 포인터 주소 받기
//            &Device,                      // [결과물 2] 생성된 디바이스(공장) 포인터 주소 받기
//            nullptr,                      // 지원되는 기능 레벨 결과물은 안 받음
//            &DeviceContext                // [결과물 3] 생성된 컨텍스트(일꾼) 포인터 주소 받기
//        );
//        // >> 이게 끝나야 DeviceContext 포인터에 진짜 GPU 메모리 주소가 할당
//
//        // 생성된 스왑 체인의 정보 가져오기 = 그래픽 카드가 실제로 세팅한 진짜 창 크기 정보 다시 받아오기
//        SwapChain->GetDesc(&swapchaindesc);
//
//        // 뷰포트(화면 어디에 그릴지 범위) 정보 설정
//        ViewportInfo = {
//            0.0f, 0.0f,
//            (float)swapchaindesc.BufferDesc.Width,
//            (float)swapchaindesc.BufferDesc.Height,
//            0.0f, 1.0f
//        };
//    }
//
//    // 백 버퍼 가져와서 FrameBuffer에 저장 및 RTV(허가증) 생성
//    void CreateFrameBuffer()
//    {
//        // 스왑 체인으로부터 백 버퍼(0) 텍스처 가져오기
//        HRESULT hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&FrameBuffer);
//
//        if (FAILED(hr) || FrameBuffer == nullptr) {
//            assert(SUCCEEDED(hr) && "스왑체인버퍼를 가져오는데 실패하였습니다.");
//            return;
//        }
//
//        D3D11_RENDER_TARGET_VIEW_DESC framebufferRTVdesc = {};
//        framebufferRTVdesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB; // 색상 포맷
//        framebufferRTVdesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D; // 이 텍스처가 1D인지 2D인지 3D인지, 배열인지 등을 지정
//
//        // 진짜 RTV 생성 - 순서대로 재료, 설명서의 주소, 결과물을 받아올 상자의 주소
//        Device->CreateRenderTargetView(FrameBuffer, &framebufferRTVdesc, &FrameBufferRTV);
//    }
//
//    // 래스터라이저 : 3D 좌표를 실제 화면의 픽셀들로 변환하는 GPU 단계의 규칙 지정함수
//    void CreateRasterizerState()
//    {
//        D3D11_RASTERIZER_DESC rasterizerdesc = {};
//        rasterizerdesc.FillMode = D3D11_FILL_SOLID; // D3D11_FILL_WIREFRAME :테두리만 선으로 그림 
//        rasterizerdesc.CullMode = D3D11_CULL_BACK; // D3D11_CULL_NONE : 앞뒤 다 그림 & D3D11_CULL_FRONT : 앞면을 버림
//
//        Device->CreateRasterizerState(&rasterizerdesc, &RasterizerState);
//    }
//
//    // HLSL 텍스트 → GPU가 실행 가능한 바이너리로 변환
//    // (Java로 치면 .java → .class로 컴파일하는 것과 비슷한 개념)
//    void CreateShader()
//    {
//        // ID3DBlob : 정체를 알 수 없는 바이너리 데이터 뭉치"를 담는 범용 상자
//        ID3DBlob* vertexshaderCSO = nullptr;
//        ID3DBlob* pixelshaderCSO = nullptr;
//
//        D3DCompileFromFile(L"ShaderW0.hlsl", nullptr, nullptr, "mainVS", "vs_5_0", 0, 0, &vertexshaderCSO, nullptr);
//        // 실제로 GPU에서 쓸 수 있는 Vertex Shader 객체를 만들어달라고 요청
//        Device->CreateVertexShader(vertexshaderCSO->GetBufferPointer(), vertexshaderCSO->GetBufferSize(), nullptr, &SimpleVertexShader);
//
//        D3DCompileFromFile(L"ShaderW0.hlsl", nullptr, nullptr, "mainPS", "ps_5_0", 0, 0, &pixelshaderCSO, nullptr);
//        // 실제로 GPU에서 쓸 수 있는 pixel Shader 객체를 만들어달라고 요청
//        Device->CreatePixelShader(pixelshaderCSO->GetBufferPointer(), pixelshaderCSO->GetBufferSize(), nullptr, &SimplePixelShader);
//
//        D3D11_INPUT_ELEMENT_DESC layout[] =
//        {
//            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//        };
//
//        Device->CreateInputLayout(layout, ARRAYSIZE(layout), vertexshaderCSO->GetBufferPointer(), vertexshaderCSO->GetBufferSize(), &SimpleInputLayout);
//        Stride = sizeof(FVertexSimple);
//
//        vertexshaderCSO->Release();
//        pixelshaderCSO->Release();
//    }
//
//    // 프레임 시작 전 도화지 세팅
//    void Prepare()
//    {
//        DeviceContext->ClearRenderTargetView(FrameBufferRTV, ClearColor);
//        DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
//        DeviceContext->RSSetViewports(1, &ViewportInfo);
//        DeviceContext->RSSetState(RasterizerState);
//        DeviceContext->OMSetRenderTargets(1, &FrameBufferRTV, nullptr);
//        DeviceContext->OMSetBlendState(nullptr, nullptr, 0xffffffff);
//    }
//
//    // 사용할 그리기도구(셰이더) 장착
//    void PrepareShader()
//    {
//        DeviceContext->VSSetShader(SimpleVertexShader, nullptr, 0);
//        DeviceContext->PSSetShader(SimplePixelShader, nullptr, 0);
//        DeviceContext->IASetInputLayout(SimpleInputLayout);
//
//        // 실습 3 : Shader 준비 과정에 상수 버퍼 사용을 버텍스 쉐이더에 알려주는 함수 호출을 추가
//        if (ConstantBuffer)
//        {
//            DeviceContext->VSSetConstantBuffers(0, 1, &ConstantBuffer);
//        }
//    }
//
//    // 버텍스 버퍼 바인딩 및 실질적인 드로우콜 명령
//    void RenderPrimitive(ID3D11Buffer* pBuffer, UINT numVertices)
//    {
//        UINT offset = 0;
//        DeviceContext->IASetVertexBuffers(0, 1, &pBuffer, &Stride, &offset);
//        DeviceContext->Draw(numVertices, 0);
//    }
//
//    // 전면/후면 버퍼 교체 (화면 출력)
//    void SwapBuffer()
//    {
//        SwapChain->Present(1, 0);
//    }
//
//    // 기본 장치 장부 해제
//    void ReleaseDeviceAndSwapChain()
//    {
//        if (DeviceContext) DeviceContext->Flush();
//        if (SwapChain) { SwapChain->Release(); SwapChain = nullptr; }
//        if (DeviceContext) { DeviceContext->Release(); DeviceContext = nullptr; }
//        if (Device) { Device->Release(); Device = nullptr; }
//    }
//
//    // 백 버퍼 해제
//    void ReleaseFrameBuffer()
//    {
//        if (FrameBuffer) { FrameBuffer->Release(); FrameBuffer = nullptr; }
//        if (FrameBufferRTV) { FrameBufferRTV->Release(); FrameBufferRTV = nullptr; }
//    }
//
//    // 셰이더 해제
//    void ReleaseShader()
//    {
//        if (SimpleInputLayout) { SimpleInputLayout->Release(); SimpleInputLayout = nullptr; }
//        if (SimplePixelShader) { SimplePixelShader->Release(); SimplePixelShader = nullptr; }
//        if (SimpleVertexShader) { SimpleVertexShader->Release(); SimpleVertexShader = nullptr; }
//    }
//
//    // 전체 해제 통제 함수
//    void Release()
//    {
//        ReleaseShader();
//        if (RasterizerState) { RasterizerState->Release(); RasterizerState = nullptr; }
//        DeviceContext->OMSetRenderTargets(0, nullptr, nullptr);
//        ReleaseFrameBuffer();
//        ReleaseDeviceAndSwapChain();
//    }
//
//    // 도형을 실시간 전환하게 되면 "정점 배열 → 버텍스 버퍼 생성" 이 작업을 도형 종류만큼 여러 번 반복해야 합니다.
//    // 매번 이 5~6줄을 복붙하는 대신, 한 번만 함수로 만들어두고 필요할 때마다 호출합니다.
//    ID3D11Buffer* CreateVertexBuffer(FVertexSimple* vertices, UINT byteWidth) {
//
//        D3D11_BUFFER_DESC vertexbufferdesc = {};
//        vertexbufferdesc.ByteWidth = byteWidth;
//        vertexbufferdesc.Usage = D3D11_USAGE_IMMUTABLE;
//        vertexbufferdesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//
//        D3D11_SUBRESOURCE_DATA vertexbufferSRD = { vertices };
//
//        ID3D11Buffer* vertexBuffer;
//
//        Device->CreateBuffer(&vertexbufferdesc, &vertexbufferSRD, &vertexBuffer);
//
//        return vertexBuffer;
//    }
//
//    void ReleaseVertexBuffer(ID3D11Buffer* vertexBuffer) {
//        vertexBuffer->Release();
//    }
//
//    struct FConstants
//    {
//        FVector Offset;
//        float Scale;
//    };
//
//    void CreateConstantBuffer()
//    {
//        D3D11_BUFFER_DESC constantbufferdesc = {};
//        constantbufferdesc.ByteWidth = sizeof(FConstants) + 0xf & 0xfffffff0; // ensure constant buffer size is multiple of 16 bytes
//        constantbufferdesc.Usage = D3D11_USAGE_DYNAMIC; // will be updated from CPU every frame
//        constantbufferdesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
//        constantbufferdesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//
//        Device->CreateBuffer(&constantbufferdesc, nullptr, &ConstantBuffer);
//    }
//
//    void ReleaseConstantBuffer()
//    {
//        if (ConstantBuffer)
//        {
//            ConstantBuffer->Release();
//            ConstantBuffer = nullptr;
//        }
//    }
//
//    void UpdateConstant(FVector Offset, float Scale)
//    {
//        if (ConstantBuffer)
//        {
//            D3D11_MAPPED_SUBRESOURCE constantbufferMSR;
//
//            DeviceContext->Map(ConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &constantbufferMSR); // update constant buffer every frame
//            FConstants* constants = (FConstants*)constantbufferMSR.pData;
//            {
//                constants->Offset = Offset;
//                constants->Scale = Scale;
//            }
//            DeviceContext->Unmap(ConstantBuffer, 0);
//        }
//    }
//};
//
//// ImGui_ImplWin32_WndProcHandler 함수를 선언해놨으니 링크 단계에서 찾아서 연결해라
//extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//
//// ==========================================
//// 도형 기반 클래스
//// ==========================================
//class UPrimitive
//{
//public:
//    virtual void Update(float dt, bool bGravityOn, bool bWindOn) = 0;
//    virtual void Draw(URenderer& renderer) = 0;
//    virtual bool IsColliding(UPrimitive* other) = 0;
//    virtual void ApplyImpulse(const FVector& v) = 0;
//};
//
//ID3D11Buffer* g_VertexBufferSphere = nullptr;
//UINT g_NumVerticesSphere = 0;
//
//const float g_LeftBorder = -1.0f;
//const float g_RightBorder = 1.0f;
//const float g_TopBorder = 1.0f;
//const float g_BottomBorder = -1.0f;
//
//class UBall : public UPrimitive {
//public:
//    FVector Location;
//    FVector Velocity;
//    float Radius;
//    float Mass;
//    static int TotalNumBalls;
//
//    UBall(FVector InLocation, FVector InVelocity, float InRadius) {
//        Location = InLocation;
//        Velocity = InVelocity;
//        Radius = InRadius;
//        Mass = InRadius;
//        TotalNumBalls++;
//    }
//    ~UBall()
//    {
//        TotalNumBalls--;
//    }
//
//    void Update(float dt, bool bGravityOn, bool bWindOn) override // 2번째 매개변수 : 중력추가 & 3번째 매개변수 : 바람추가
//    {
//        if (bGravityOn) {
//            Velocity.y -= 0.003f;
//        }
//
//        if (bWindOn) {
//            Velocity.x += 0.002f;
//        }
//
//        // 위치 갱신
//        Location.x += Velocity.x;
//        Location.y += Velocity.y;
//        Location.z += Velocity.z;
//
//        const float ballDamping = 0.9f;
//
//        // 충돌체크 후 튕기기
//        if (Location.x < g_LeftBorder + Radius)
//        {
//            Location.x = g_LeftBorder + Radius;
//            if (Velocity.x < 0.0f) Velocity.x *= -ballDamping;
//        }
//        if (Location.x > g_RightBorder - Radius)
//        {
//            Location.x = g_RightBorder - Radius;
//            if (Velocity.x > 0.0f) Velocity.x *= -ballDamping;
//        }
//        if (Location.y > g_TopBorder - Radius)
//        {
//            Location.y = g_TopBorder - Radius;
//            if (Velocity.y > 0.0f) Velocity.y *= -ballDamping;
//        }
//        if (Location.y < g_BottomBorder + Radius)
//        {
//            Location.y = g_BottomBorder + Radius;
//            if (Velocity.y < 0.0f) Velocity.y *= -ballDamping;
//        }
//    }
//
//    void Draw(URenderer& renderer) override
//    {
//        // 추가안하면 공이 생성안됨
//        renderer.UpdateConstant(Location, Radius);
//        renderer.RenderPrimitive(g_VertexBufferSphere, g_NumVerticesSphere);
//    }
//
//    bool IsColliding(UPrimitive* other) override
//    {
//        UBall* otherBall = (UBall*)other;
//
//        float dx = Location.x - otherBall->Location.x;
//        float dy = Location.y - otherBall->Location.y;
//        float distSq = dx * dx + dy * dy;
//
//        float radiusSum = Radius + otherBall->Radius;
//
//        return distSq < (radiusSum * radiusSum);
//    }
//
//    void ApplyImpulse(const FVector& v) override
//    {
//        Velocity.x += v.x;
//        Velocity.y += v.y;
//        Velocity.z += v.z;
//    }
//
//    void HandleCollision(UBall* other) {
//
//        float nx = Location.x - other->Location.x;
//        float ny = Location.y - other->Location.y;
//        float dist = sqrtf(nx * nx + ny * ny);
//
//        if (dist == 0.0f) return;
//
//        nx /= dist;
//        ny /= dist;
//
//        float overlap = (Radius + other->Radius) - dist;
//        if (overlap > 0.0f) {
//            float pushEach = overlap * 0.5f;
//            Location.x += nx * pushEach;
//            Location.y += ny * pushEach;
//            other->Location.x -= nx * pushEach;
//            other->Location.y -= ny * pushEach;
//        }
//
//        float v1n = Velocity.x * nx + Velocity.y * ny;
//        float v2n = other->Velocity.x * nx + other->Velocity.y * ny;
//
//        if (v1n - v2n > 0.0f) return;
//
//        /*
//        v1' = ((m1 - m2)*v1 + 2*m2*v2) / (m1 + m2)
//        v2' = ((m2 - m1)*v2 + 2*m1*v1) / (m1 + m2)
//        */
//        float m1 = Mass;
//        float m2 = other->Mass;
//
//        float newV1n = ((m1 - m2) * v1n + 2 * m2 * v2n) / (m1 + m2);
//        float newV2n = ((m2 - m1) * v2n + 2 * m1 * v1n) / (m1 + m2);
//
//        float dv1n = newV1n - v1n;
//        float dv2n = newV2n - v2n;
//
//        Velocity.x += dv1n * nx;
//        Velocity.y += dv1n * ny;
//        other->Velocity.x += dv2n * nx;
//        other->Velocity.y += dv2n * ny;
//    }
//};
//
//int UBall::TotalNumBalls = 0;
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam)) {
//        return true;
//    }
//
//    switch (message)
//    {
//    case WM_DESTROY:
//        // Signal that the app should quit
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//
//    return 0;
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
//
//    WCHAR WindowClass[] = L"JungleWindowClass";
//    WNDCLASSW wndclass = {};
//    wndclass.lpfnWndProc = WndProc;
//    wndclass.lpszClassName = WindowClass;
//
//    RegisterClassW(&wndclass);
//
//    HWND hWnd = CreateWindowExW(0, WindowClass, L"Game Tech Lab", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//        CW_USEDEFAULT, CW_USEDEFAULT, 1024, 1024, nullptr, nullptr, hInstance, nullptr);
//
//    URenderer renderer;
//    renderer.Create(hWnd);
//    renderer.CreateShader();
//
//    renderer.CreateConstantBuffer();
//
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO();
//    ImGui_ImplWin32_Init((void*)hWnd);
//    ImGui_ImplDX11_Init(renderer.Device, renderer.DeviceContext);
//
//
//    UINT numVerticesSphere = sizeof(sphere_vertices) / sizeof(FVertexSimple);
//
//    g_VertexBufferSphere = renderer.CreateVertexBuffer(sphere_vertices, sizeof(sphere_vertices));
//    g_NumVerticesSphere = numVerticesSphere;
//
//    bool bIsExit = false;
//    bool bGravity = false;
//    bool bWind = false;
//
//    UPrimitive** PrimitiveList = nullptr;
//    int NumBalls = 0;
//
//    NumBalls = 1;
//    PrimitiveList = new UPrimitive * [NumBalls];
//
//    float initRadius = 0.05f + ((float)(rand() % 100) / 100.0f) * 0.05f;
//    FVector initLocation(0.0f, 0.0f, 0.0f);
//    FVector initVelocity(
//        ((float)(rand() % 100 - 50)) * 0.005f,
//        ((float)(rand() % 100 - 50)) * 0.005f,
//        0.0f
//    );
//
//    PrimitiveList[0] = new UBall(initLocation, initVelocity, initRadius);
//
//    const int targetFPS = 30;
//    const double targetFrameTime = 1000.0 / targetFPS;
//
//    LARGE_INTEGER frequency;
//    QueryPerformanceFrequency(&frequency);
//
//    LARGE_INTEGER startTime, endTime;
//    double elapsedTime = 0.0;
//
//
//    while (bIsExit == false)
//    {
//        MSG msg;
//        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//
//            if (msg.message == WM_QUIT)
//            {
//                bIsExit = true;
//                break;
//            }
//
//            else if (msg.message == WM_KEYDOWN)
//            {
//
//            }
//        }
//
//        for (int i = 0; i < NumBalls; ++i)
//        {
//            PrimitiveList[i]->Update(0.0f, bGravity, bWind);
//        }
//
//        for (int i = 0; i < NumBalls; ++i)
//        {
//            for (int j = i + 1; j < NumBalls; ++j)
//            {
//                UBall* ballA = (UBall*)PrimitiveList[i];
//                UBall* ballB = (UBall*)PrimitiveList[j];
//
//                if (ballA->IsColliding(ballB))
//                {
//                    ballA->HandleCollision(ballB);
//                }
//            }
//        }
//
//        if (bIsExit == false) {
//
//            QueryPerformanceCounter(&startTime);
//            renderer.Prepare();
//            renderer.PrepareShader();
//
//            for (int i = 0; i < NumBalls; ++i)
//            {
//                PrimitiveList[i]->Draw(renderer);
//            }
//
//            ImGui_ImplDX11_NewFrame();
//            ImGui_ImplWin32_NewFrame();
//            ImGui::NewFrame();
//
//            ImGui::Begin("Jungle Property Window");
//            ImGui::Text("Hello Jungle World!");
//
//            ImGui::Text("Total Balls: %d", UBall::TotalNumBalls);
//
//            // DEBUG
//
//            /*
//            if (NumBalls >= 2)
//            {
//                UBall* debugBall = (UBall*)PrimitiveList[0];
//                ImGui::Text("Ball0 Vel: (%.4f, %.4f)", debugBall->Velocity.x, debugBall->Velocity.y);
//            }
//            */
//
//            ImGui::Checkbox("Gravity", &bGravity); // 중력추가
//            ImGui::Checkbox("Wind", &bWind);       // 바람추가
//
//            int desiredNumBalls = NumBalls;
//            ImGui::InputInt("Number of Balls", &desiredNumBalls);
//
//            if (desiredNumBalls < 1)
//            {
//                desiredNumBalls = 1;
//            }
//
//            if (desiredNumBalls != NumBalls)
//            {
//                if (desiredNumBalls > NumBalls)
//                {
//                    int oldNumBalls = NumBalls;
//                    NumBalls = desiredNumBalls;
//
//                    UPrimitive** NewList = new UPrimitive * [NumBalls];
//                    for (int i = 0; i < oldNumBalls; ++i)
//                    {
//                        NewList[i] = PrimitiveList[i];
//                    }
//
//                    for (int i = oldNumBalls; i < NumBalls; ++i)
//                    {
//                        float r = 0.05f + ((float)(rand() % 100) / 100.0f) * 0.05f;
//                        FVector loc(
//                            ((float)(rand() % 100 - 50)) / 50.0f * 0.8f,
//                            ((float)(rand() % 100 - 50)) / 50.0f * 0.8f,
//                            0.0f
//                        );
//                        FVector vel(
//                            ((float)(rand() % 100 - 50)) * 0.001f,
//                            ((float)(rand() % 100 - 50)) * 0.001f,
//                            0.0f
//                        );
//                        NewList[i] = new UBall(loc, vel, r);
//                    }
//
//                    delete[] PrimitiveList;
//                    PrimitiveList = NewList;
//                }
//                else
//                {
//                    int oldNumBalls = NumBalls;
//                    NumBalls = desiredNumBalls;
//
//                    int removeCount = oldNumBalls - NumBalls;
//                    for (int r = 0; r < removeCount; ++r)
//                    {
//                        int removeIndex = rand() % oldNumBalls;
//                        delete PrimitiveList[removeIndex];
//
//                        PrimitiveList[removeIndex] = PrimitiveList[oldNumBalls - 1];
//                        oldNumBalls--;
//                    }
//
//                    UPrimitive** NewList = new UPrimitive * [NumBalls];
//                    for (int i = 0; i < NumBalls; ++i)
//                    {
//                        NewList[i] = PrimitiveList[i];
//                    }
//
//                    delete[] PrimitiveList;
//                    PrimitiveList = NewList;
//                }
//            }
//
//            ImGui::End();
//
//            ImGui::Render();
//            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
//
//            renderer.SwapBuffer();
//
//            do {
//                Sleep(0);
//                QueryPerformanceCounter(&endTime);
//                elapsedTime = (endTime.QuadPart - startTime.QuadPart) * 1000.0 / frequency.QuadPart;
//            } while (elapsedTime < targetFrameTime);
//        }
//    }
//
//    ImGui_ImplDX11_Shutdown();
//    ImGui_ImplWin32_Shutdown();
//    ImGui::DestroyContext();
//
//    for (int i = 0; i < NumBalls; ++i)
//    {
//        delete PrimitiveList[i];
//    }
//    delete[] PrimitiveList;
//
//    renderer.ReleaseVertexBuffer(g_VertexBufferSphere);
//
//    renderer.ReleaseConstantBuffer();
//    renderer.ReleaseShader();
//
//    renderer.Release();
//
//    return 0;
//}