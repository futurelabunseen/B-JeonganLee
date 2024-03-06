# 1강: 헬로 언리얼!

- 강의 목표
  - "Hello Unreal!" 문자열을 뷰포트와 출력로그에 찍는 예시를 따라해보기 (요구)
  - 언리얼 `C++` 프로그래밍을 위한 개발 환경 설정
  - 앞으로 강의에 사용할 프로그래밍 환경 구성 학습
- 강의 과제
  - 에디터를 실행해 헬로 언리얼이 Output Log에 출력될 때까지 실행 과정을 움짤로 캡쳐해보세요.
  - 처음 작업한 언리얼 코드에서 자신이 모르는 내용이 어떤 것들이 있는지 모두 정리해보세요.

- [작업한 프로젝트 링크](/Unreal5_Lecture_Project/Part1/HelloUnreal/)

## 언리얼 엔진 설치 및 개발 환경 설정

에디터 허브에서 사용할 엔진을 설치하고, 개발 환경을 설정하기 위해 `디버깅을 위한 편집기 기호`를 추가 설치한다. *엔진에서 언리얼엔진이 어떻게 동작하는지 알고 싶다면 설치해야 한다.*

IDE의 경우 `Visual Studio`를 사용한다. *나는 학생 버전 Rider를 사용하고 있기 때문에 Rider로 사용할 예정이다. 설치 해보니 Visual Studio을 통해서 컴파일러를 설치해야 한다.*

- 학습을 유용하게 하려면 영문을 사용하는 것이 좋다. (언리얼 엔진의 공식 문서나 자료들이 대부분 영문이기 때문에)

### 프로젝트 생성

- 탬플릿은 `Games` 카테고리에서 `Blank`를 선택한다.
- 프로젝트 설정은 `C++`을 선택한다.

### 오류 발생

프로젝트를 세팅하던 중 프로젝트 컴파일 에러가 떴다. 멘토님의 조언대로 5.3의 최신버전으로 진행했지만, 조금 찾아보니 문제는 Visual Studio의 버전 문제였다.

- [해당 글 링크](https://forums.unrealengine.com/t/failure-to-create-a-new-project-cannot-access-private-member-declared-in-class-fhazardpointercollection-fhazardrecord/1548295/16)

나는 `Visual Studio`의 버전을 미리보기 버전으로 변경하여서 해결했다.

### 언리얼 엔진

언리얼 엔진은 뼈대(프레임)을 제공해주기 때문에 개발자는 그 위에 레이어를 쌓아서 게임을 만들면 된다.

`Hellow Unreal`을 출력하기 위해선 언리얼 엔진에 객체를 생성해야한다.

- `Tools` -> `New C++ Class`을 통해서 클래스를 작성할 수 있다.
  - `Common Classes`는 대부분 게임 제작에 관련된 클래스들
  - `All Classes`는 모든 클래스들을 볼 수 있다. (여기서 `GameInstance`클래스를 선택한다.)

#### 엔진 디렉토리 구성

- [참고할 공식문서](https://docs.unrealengine.com/4.27/ko/Basics/DirectoryStructure/)
- Egine: 엔진의 소스코드
- Games: 게임의 소스코드

#### 에디터 확장

Rider를 사용하고 있어서 확장은 따로 설치하지 않았다.

#### 언리얼 코드 컴파일 방법

- 헤더파일에 변경이 발생하면 - 에디터를 끄고 비주얼 스튜디오에서 컴파일한다.
- 소스 파일에만 변경이 발생하면 - 라이브 코딩으로 컴파일한다.

**에디터에서 수동으로 클래스를 추가하지 말 것!**

즉 헤더파일인 설계측면에서 변경은 에디터를 끄고 컴파일하는 것이 가장 깔끔하고, 소스코드인 구현에 대해서만 변경이 발생하면 라이브 코딩으로 컴파일하는 것이 좋다.

> 오류 발생  
> SDK문제가 발생하는데 이는 Visual Studio installer에서 SDK를 설치하면 해결된다.  

#### 코드 작성

```cpp
UCLASS()
class HELLOUNREAL_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
};
```

```cpp
void UMyGameInstance::Init()
{
  Super::Init();
  UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello, Unreal!"));
}
```

- `UCLASS`는 언리얼 엔진에서 사용하는 매크로
- `UMyGameInstance`는 클래스 이름
  - `UGameInstance`를 상속받는다.
- `Init`는 초기화 함수 (오버라이딩)
  - `Super::Init()`는 부모 클래스의 `Init`함수를 호출한다. (부모 클래스의 `Init`함수를 호출하지 않으면 오류가 발생한다.)
  - `UE_LOG`는 언리얼 엔진에서 사용하는 로그 매크로
    - `LogTemp`는 로그의 종류
    - `Warning`은 로그의 레벨
    - `TEXT`는 문자열을 출력하는 매크로

#### 로그 확인

- `Output Log`에서 로그를 확인할 수 있다.
- 검색이나 필터링을 통해서 로그를 확인할 수 있다.