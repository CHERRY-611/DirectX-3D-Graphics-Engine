# DirectX 11 기반 3D 렌더링 엔진

**Direct3D 11과 C++20을 기반으로 구현한 실시간 3D 렌더링 엔진** 프로젝트입니다.  

> 목표: 렌더링 파이프라인 이해, 셰이더 추상화, 스켈레탈 애니메이션, GPU 자원 관리

<p align="center">
  <img src="https://github.com/user-attachments/assets/d519ce1b-dab3-4765-a450-aaa31eddf144" />
</p>

</br>

## 주요 기능

### 1. 셰이더 시스템
- Vertex / Pixel 셰이더 래퍼 클래스 구현
- 스키닝 전용 Vertex 셰이더 구현
- 컴파일된 셰이더 블롭 기반 Input Layout 생성
- 모듈화된 셰이더 초기화 구조 (재사용성 고려)

</br>

### 2. 정적 렌더링 시스템 (Renderable)
- 정적 메시 (Vertex / Index Buffer) 렌더링
- 객체 단위 월드 변환 적용
- 머티리얼 기반 텍스처 및 샘플러 바인딩

</br>

### 3. 스켈레탈 애니메이션 (Skinning)
- 본(Bone) 트랜스폼 별도 버퍼 관리
- 스키닝 상수버퍼(CBSkinning) GPU 전달
- 멀티 스트림 버텍스 입력 (정점 + 애니메이션 데이터)

</br>

### 4. 라이팅 시스템
- 다수의 포인트 라이트 지원 (NUM_LIGHTS)
- 상수버퍼(CBLights)를 통한 GPU 전달
- 프레임 단위 라이트 위치 및 색상 업데이트

</br>

### 5. 카메라 시스템
- View / Projection 행렬 계산
- 입력 기반 카메라 이동 및 회전
- 이벤트(리사이즈 등)에 따른 상수버퍼 갱신

</br>

## 🛠️ 사용 기술

| 영역 | 기술 스택 |
|------|----------|
| **Language** | C++20 (MSVC) |
| **Graphics API** | Direct3D 11 (D3D11), DXGI |
| **Shader** | HLSL (Shader Model 5.0) |
| **Model / Asset** | Assimp |
| **Development** | Visual Studio 2022, D3D11 Debug Layer |
