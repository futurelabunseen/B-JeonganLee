# GameplayAbilitySystem

*이득우의 언리얼 프로그래밍 Part4 - 게임플레이 어빌리티 시스템을 포함한 추가 정리..*

- [공식문서](https://docs.unrealengine.com/5.3/ko/gameplay-ability-system-for-unreal-engine/)
- [강의 정리](https://github.com/futurelabunseen/B-JeonganLee/blob/main/Document/StudyNote/UnrealLecture/Part4/README.md)

## 액션 RPG로 알아보는 게임플레이 어빌리티 시스템(GAS) | Unreal Fest 2022

[유튜브 링크](https://www.youtube.com/watch?v=vknzNVYJjr4)

- GAS는 기본적으로 엔진용 플러그인이다.
- 캐릭터에 ASC(Ability System Component)를 추가하면 GAS를 사용할 수 있다. 즉, 캐릭터의 모든 어트리뷰트에 접근할 수 있다.
- 확장하여 파괴 가능한 오브젝트가 같은 체력을 공유하고, 데미지를 받으면 체력이 감소하는 등의 기능을 구현할 수 있다.
- 어트리뷰트 세트는 float숫자의 집합으로 현재값과 베이스값을 따로 가진다.
  - 베이스 값이 100이더라도 현재값이 120을 가질 수 있다. (잠깐 1.2배로 스케일 조절하는 모디파이러를 사용하여)
- 게임플레이 어빌리티는 `GA`라고 부르며 블루프린트로 구현하는 것이 유리하다. (C++로 가능하지만, 팀원도 사용할 수 있게 하려면 블루프린트로 구현하는 것이 좋다.)
- 게임플레이 이펙트는 꼭 GA에서 나올 필요는 없지만 일반적으론 GA에서 나온다.
  - 캐릭터나 액터의 어트리뷰트를 수정하거나 태그를 적용해준다. (무적모드로 만든다?)
  - 즉각적인 효과나 지속적인 효과로 나뉜다.
  - 또한 `GE`는 데이터 오브젝트이다.
- 게임플레이 태그는 액터 태그와 비슷한 기능이다.
  - 한 번 만들어서 프로젝트 세팅에 추가하면 디폴트 gameplaytags.ini에 남는다는 것이다.
  - 이후에는 드롭다운 박스로 간편하게 사용할 수 있다.
  - 태그에는 계층구조가 있다.
  - 엔진과는 별개이므로 GAS없이도 사용가능하다. (강력한 기능)

## Unreal GAS(GameplayAbilitySystem) Documentation 번역글 1부

[블로그 링크](https://kkadalg.tistory.com/29)



