# 게임플레이 어빌리티 시스템 Advanced

전체적인 구조

ASC를 중심으로 어빌리티를 실행함으로 이펙트를 발생시켜 애트리뷰트를 조작하는 방식이다. 어빌리티는 어빌리티 Task를 통해 구성할 수 있으며, C++을 통해 로직을 구현하고 블루프린트를 통해 연결한다.

## GamePlayAbilitySystem

## GameplayAbility

### The important functions

*기본적으로 상속받아서 구현하는 Func에 해당된다.*

- `CanActivateAbility`
  - 어빌리티를 활성화할 수 있는지 확인하는 함수
  - 주로 UI에서 사용 / 그외에도 사용
- `TryActivateAbility`
  - 어빌리티를 활성화하려고 시도하는 함수
- `CallActivateAbility`
  - 내부적으로 `ActivateAbility`를 호출하기 전에 필요한 작업을 수행한다.
  - 외부에서 호출하지 않고 내부에서 호출한다.
- `ActivateAbility`
  - 능력이 실제로 수행하는 작업을 정의한다.
- `CommitAbility`
  - `ActivateAbility`에서 반드시 호출해야 하는 함수
- `CancelAbility`
  - 외부에 의해서 능력을 취소할 때 호출하는 함수
- `EndAbility`
  - 어빌리티가 끝날 때 호출하는 함수

가장 간단한 순서는 ActivateAbility -> CommitAbility -> EndAbility이다.

### ETC

`virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec);`

GAS에서 능력의 아바타가 설정될 때 호출되는 함수

## AbilityTask

하나의 어빌리티를 구성하기 위해서 사용하는 Task라고 생각하면 된다. 이를 활용하여 블루프린트에서 어빌리티를 구성할 수 있다.

능력의 실행을 단순화하기 위해서 사용하며 비동기 작업 (애니메이션 재생, 이동, 시간지연 등)

- `Activate()`
  - 능력이 활성화 될 때 호출된다. 비동기 작업을 실행하거나 이벤트를 바인딩하는 초기화 작업을 수행
- `OnDestroy()`
  - 작업이 종료될 때 호출된다. 이벤트 바인딩을 해제하거나 리소스를 해제하는 작업을 수행

마찬가지로 EndTask를 꼭 호출해야 한다.

## AttributeSet

애트리뷰트 셋은 다른 어빌리티에 의해서 관리되는 값의 집합이다. 이를 통해 능력이 애트리뷰트를 조작하고, 애트리뷰트가 변경될 때 이벤트를 발생시킬 수 있다.

값은 Current, Base값으로 나뉘며, 

## GAS Documentation 구조

자체적으로 `UGameplayAbility`을 상속하여 사용함

구조의 특징은 `AbilityInputID`나 `AbilityID`와 같이 Enum과 같은 값을 가지게 하기 위함과 생성자 CDO에서 모두 동일하게 가져야 하는 게임플레이 태그를 생성하거나 기본 정책들을 먹인다.

마찬가지로 `UAbilitySystemComponent`도 상속하여 사용함

내부에서 브로드 캐스트와 같이 ASC를 가진 객체들에게 동일하게 수행할 메서드를 여기에 넣어둠

