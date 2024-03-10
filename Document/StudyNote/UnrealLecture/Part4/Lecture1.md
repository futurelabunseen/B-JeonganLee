# 1강: 언리얼 게임플레이 어빌리티 시스템 개요

- 강의 목표
  - 게임플레이 어빌리티 시스템을 구성하는 주요 개념과 핵심 구성요소의 학습
  - 실습 프로젝트 구성의 이해
  - 향후 실습 구현 과정의 이해
  - C++언어로 게임 플레이 어빌리티 시스템 학습해야 하는 이유
- 강의 과제

## 게임플레이 어빌리티 시스템의 개요

- [GAS시스템 공식 문서](https://docs.unrealengine.com/5.3/ko/gameplay-ability-system-for-unreal-engine/)
- [과거에 정리한 어빌리티 시스템에 대한 내용](https://github.com/fkdl0048/CodeReview/blob/main/GameAlgorithm/UtilitySystem/README.md)

*쉽게 이해할 수 있게 만든 강의를 따라가고 이후에 라일라 프로젝트를 뜯어보며 공부하면 좋다.*

### GAS 프레임웍?

- 액터가 소유하고 발동할 수 있는 어빌리티 및 액터 간의 인터랙션 기능을 제공하는 프레임웍
- RPG, 액션 어드벤처, MOBA 장르의 제작을 쉽게하기 위한 도구. 대부분의 게임 제작에 활용 가능
- 장점
  - **유연성과 확장성**: 다양하고 복잡한 게임 제작에 대응할 수 있도록 범용적으로 설계
  - **모듈러 시스템**: 각 기능에 대한 의존성이 최소화되도록 설계
  - **네트워크 지원**: 네트웍 멀티플레이어 게임에서도 활용 가능하도록 설계
  - **데이터 기반 설계**: 데이터를 기반으로 동작하도록 설계
    - *과연 객체지향 설계에서 데이터 기반 설계가 유리한가? 책임주도 개발에 대한 고민이 필요하다.*
  - **완성도**: 포트나이트 게임 서비스를 통해 실효성 검증
- 단점
  - **배우는 학습 비용**: 러닝 커브가 높음
  - **오버헤드**: 작은 규모의 프로젝트에는 복잡한 구조가 오히려 부담이 될 수 있다.

**큰 규모의 RPG 및 네트웍 멀티플레이 게임을 효율적으로 만드는데 적합함**

모든 패턴이나 프레임웍이 그러하듯 디커플링이 핵심이고 MVP패턴과 비슷한 성격을 가짐(동작, 데이터 처리, 표현을 분리)

### GAS 프레임웍의 핵심 구성요소

#### 어빌리티 시스템 컴포넌트(Ability System Component: ASC)

- GAS 프레임웍을 관리하고 처리하는 중앙 처리 장치(Brain)

#### 게임플레이 태그(Tag System: Tag)

- 현재 프로젝트 레벨에서 액터들의 상태나 행동을 관리하는 데 사용되는 게임 플레이 태그

#### 게임플레이 어빌리티(Gameplay Ability: GA)

- 게임 플레이 어빌리티로 부터 모든 스킬, 액션이 발동해서 시작한다고 할 수 있다.

#### 게임플레이 이펙트(Gameplay Effect: GE)

- 게임 특수효과가 아닌 게임에 주는 영향을 나타내는 효과
- 어빌리티로 인한 행동에 대한 결과로 어떤 효과가 나타나는지

#### 어트리뷰트(Attribute)

- 게임에서 영향을 받는 데이터/수치

### GAS 프레임웍 시스템 흐름

- ASC는 모든 상태를 다 제어할 수 있다.
- Tag는 프로젝트 단위에서 모든 시스템을 감싸고 있기 때문에 이를 통해 쉽게 접근하고 제어할 수 있다.
  - 그 만큼 트레이드 오프가 발생하니 생각없이 사용 X(필요한 것에만 의존성을 두는 것이 좋다.)
- **대표적인 제어 흐름**
  - 가장 중요한 `ASC`를 액터에 생성한다.
  - 이후에 액터가 취할 액션인 `GA`를 부여해준다.
  - 만약 부여된 `GA`가 조건에 맞으면 발동이 된다. (캐릭터가 액션을 수행한다.)
  - 발동이 되면 액션의 종류에 따라서 영향을 끼치게 되는데 이를 `GE`로 표현한다.
  - 이펙트가 발동되면 결과적으로 어트리뷰트에 영향을 끼치게 된다.
- 어빌리티 태스크(Ability Task)
  - `GA`를 발동할 때 애니메이션과 같은 일정 시간이 걸리는 작업들이 있을텐데 이러한 작업들을 단위화 시켜서 원하는 액션을 취할 수 있도록 제작할 수 있다. (마치 private함수로 조합하여 하나의 public함수로 만드는 것과 같다.)
- 어빌리티 큐(Ability cue)
  - 이펙트가 발동되면 강조하기 위해 시각적인 효과가 필요한데 이를 어빌리티 큐라고 한다.

### 예제로 실습

- [실습 프로젝트 링크](https://github.com/ideugu/UnrealGAS1)

### C++ 프로그래밍 VS 블루프린트

- GAS의 기본 설정은 `C++`에서 진행하도록 구성되어 있음
- 세밀한 제어는 오직 `C++`에서만 가능
- 세임플레이 어빌리티, 게임플레이 이펙트 및 장식 이펙트는 블루프린트 작업이 용이함
- 전체적인 GAS 시스템 설정을 `C++`로 작업하고, 블루프린트를 활용해 게임 콘텐츠를 제작

**게임플레이 어빌리티 시스템을 효과적으로 학습하기 위해 `C++`프로그래밍으로 전 과정을 직접 만들어 본 후 블루프린트와 조합해 의존성을 최소화하는 것을 권장**

## 정리

- 게임플레이 어빌리티 시스템의 주요 구성 요소 학습
- 앞으로 실습할 프로젝트 소개
- 향후 실습 프로젝트의 구현 방향
- `C++` 프로그래밍의 필요성