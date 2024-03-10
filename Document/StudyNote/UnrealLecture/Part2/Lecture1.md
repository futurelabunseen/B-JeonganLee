# 1강: 언리얼 엔진 게임 제작 기초

- 강의 목표
  - 예제 게임을 활용한 언리얼 엔진의 게임 프레임웍의 이해
  - 기본 C++ 클래스 생성
  - C++ 프로젝트 운영 규칙 이해
- 강의 과제
  - 현재 만들고자 하는 게임의 게임 프레임웍 요소를 정리해보시오.
  - Build.cs에 PublicIncludePaths.AddRange( new string[] { "모듈이름" } ); 설정을 추가하고, 소스코드를 최대한 폴더 단위로 묶어 보시오.
  - cpp 파일이 다른 폴더에 위치한 헤더 파일을 참조하고 있는지 확인해보고, 이를 없앨 수 있는 방법은 어떤 것이 있는지 생각해보시오.

## 언리얼 게임 프레임웍

기본적으로 게임을 만들기 위해서는 게임이라는 시스템이 어떻게 구성되어 있는지를 이해해야 한다. 이를 쉽게 게임 프레임웍이라고 부르는데, 언리얼은 이것을 기본적으로 제공한다.

이를 **게임플레이 프레임웍(Gameplay Framework)**이라고 부르는데, 이는 게임의 기본적인 구조를 제공한다. 이를 통해 게임의 기본적인 구조를 파악하고, 이를 커스터마이징하여 게임을 만들 수 있다. (각 구성요소를 파악하고 이를 확장하면서 제작)

*유니티는 이러한 프레임웍이 없기 때문에 모든 베이스를 다시 만들거나 계속해서 생기는 라이브러리에 대해서 학습해야 함.*

- [실습할 프로젝트](/Unreal5_Lecture_Project/Part2/ArenaBattleSample/)

### 월드(World)

- 게임 콘텐츠를 담기 위해 제공되는 가상의 공간
- 월드는 **시간**, **트랜스폼**, **틱**을 서비스로 제공한다.
- 월드 세팅이라는 콘텐츠 제작을 위한 기본 환경 설정을 제공한다.
- **월드의 기본 단위는 액터(Actor)로 정의**되며, 액터 클래스는 언제나 접두사 A를 활용한다.
  - 자세한 에셋, 스크립트 규정은 다음 문서를 참고 [언리얼 엔진 컨벤션](/Document/StudyNote/UnrealConvention/Unreal5StyleGuide.md)

### 게임 모드(GameMode)

- 게임의 규칙을 지정하고 게임을 판정하는 **최고 관리자 액터**. 형태가 없다.
  - 게임모드도 하나의 액터 단위로 존재한다.
- 언리얼 엔진에서 하나의 게임에는 **반드시 하나의 게임 모드만 존재한다.**
- 게임 모드에서 입장할 사용자의 규격을 지정할 수 있음
- 멀티플레이어 게임에서 판정을 처리하는 절대적 권위의 심판

*유니티로 따지면 GameObject로 보면 될 것 같다.*

### 기믹(Gimmick)

- 게임 진행을 위한 **이벤트를 발생시키는 사물 액터**
- 주로 이벤트 발생을 위한 충돌 영역을 설정하는데, 이를 **트리거**라고 한다.
- 트리거를 통해 캐릭터와 상호작용하고, 월드에 액터를 **스폰**해 콘텐츠를 전개한다.

*유니티로 보면 콜라이더 컴포넌트 정도로 생각된다.*

### 플레이어(Player)

- 게임에 입장한 **사용자 액터**로 게임모드와 마찬가지로 **형태가 없다.**
- 게임모드의 로그인을 통해 사용자가 게임월드에 입장하면 **플레이어가 생성된다.**
  - 로그인은 게임모드가 플레이어를 생성하기 위한 절차정도
- 사용자와 1:1로 매칭
- **싱글 플레이 게임에는 0번의 플레이어**가 설정된다.
- 사용자와의 최종 커뮤니케이션을 담당한다. (입력 장치의 해석, 화면 장치로의 출력)
  - 화면에 나타나는 UI나 HUD를 관리한다.

*처음부터 멀티플레이의 가능성을 열어놔서 설계 자체가 로그인, 0번 플레이어와 같은 형태가 생긴 것 같다.*

### 폰(Pawn)

- 무형의 액터인 플레이어가 빙의해 조종하는 액터
  - 즉 플레이어가 조종하는 캐릭터를 의미 (플레이어는 한 단계 더 높은 수준을 가지는 것 같다.)
- 길찾기를 사용할 수 있으며, 기믹 및 다른 폰과 상호작용한다.
- 폰 중에서 인간형 폰을 별도로 캐릭터라고 한다.

## 게임의 제작 과정

- 1단계: 월드 설정과 게임 모드 설정
- 2단계: 플레이어 폰의 입출력 및 모션 설정
- 3단계: 캐릭터에 반응하는 기믹 설계
- 4단계: 게임 데이터와 NPC 인공 지능
- 5단계: UI연동 및 게임 제작 마무리

*주어진 ArenaBattle은 3단계까지 진행되어 있다.*

제작과정은 가급적 블루프린트를 사용하지않고, `C++`로만 제작한다.

## ArenaBattle

- 맵 생성
- 플레이어 Start 생성
  - 여기서 플레이어가 1:1로 매칭되는 폰을 생성한다.
  - Z축 좌표로 움직이다 `End`를 누르면 현재 가장 아래 있는 메쉬에 딱 맞게 떨어진다.
- `		PublicIncludePaths.AddRange(new string[] { "ArenaBattle" });`
  - 언리얼은 빌드도 포함할 영역을 지정해줘야 한다. (Custom가능)
- `CharacterBase`로 기본 캐릭터를 생성(Pawn으로 부터 상속 받은, 뒤로 Player와 NPC로 상속할 예정)
- `AABGameMode`의 생성자에서 해당 게임모드에 사용될 클래스들을 지정해야 함
  - 드래그앤 드롭이 아닌 생성자를 통해서 사용할 클래스를 넣어줌(`ABPlayerController`)
    - `PlayerControllerClass = AABPlayerController::StaticClass();`
    - 플레이어 모델은 해당 에셋에 접근하여 클래스 정보를 얻어와 적용해야 한다.
      - `ConstructorHelpers`클래스를 통해 에셋을 로드하여 사용할 수 있다.
      - 마찬가지로 `ABPlayerController`로 클래스 레퍼런스 주소로 접근하여 사용할 수 있다.

```cpp
#include "Game/ABGameMode.h"

AABGameMode::AABGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));
	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/ArenaBattle.ABPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
}
```

- 쉽게 말하면 `ABGameMode`에서 초기화에 따른 의존성을 줄이기 위해 `ABPlayerController`를 생성자에서 지정해준다. 전 방법인 헤더파일의 include를 통해 사용할 수 있지만, 이는 의존성을 높이는 것이기 때문에 지양해야 한다.

## 정리

- 게임 콘텐츠 구조의 이해
- 게임 프레임웍의 구성 요소 살펴보기
  - 여러 가지 구성요소로 이루어진 프레임웍에서 단순한 게임 구조에서 확장되어 가는 과정을 설명해줌
- C++ 프로젝트 구성을 위한 기본 설정
- 게임 구성 요소를 폴더별로 분류하고, 헤더 참조를 최소화하는 규칙 수립