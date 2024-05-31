# 캐릭터 무브먼트 컴포넌트

[무브먼트 컴포넌트 공식문서](https://docs.unrealengine.com/5.1/ko/movement-components-in-unreal-engine/)

언리얼 엔진에서 제공하는 캐릭터 무브먼트 컴포넌트에 대해 정리합니다.

캐릭터 무브먼트 컴포넌트는 기본적으로 Pawn 클래스의 서브클래스인 Character 클래스에 포함되어 있는 컴포넌트로, 캐릭터의 이동을 담당합니다.

## 사용 관련

```cpp
FORCEINLINE UCharacterMovementComponent* GetCharacterMovement() const { return CharacterMovement; }
```

Character 클래스에서 `GetCharacterMovement` 함수를 통해 무브먼트 컴포넌트를 가져올 수 있다.

해당 컴포넌트에 접근하여 값을 직접적으로 수정할 수 있다. (Const이기 때문에 컴포넌트 자체는 변경 x)

## 무브먼트 컴포넌트 설정 관련

```cpp
GetCharacterMovement()->bUseControllerDesiredRotation = true;
GetCharacterMovement()->bOrientRotationToMovement = false;
```

- `bUseControllerDesiredRotation`
  - 컨트롤러의 회전값을 사용하여 캐릭터를 회전시킵니다.
- `bOrientRotationToMovement`
  - 이동 방향에 따라 캐릭터를 회전시킵니다.

*현재 제작중인 프로젝트에서는 위와 같은 설정 값을 사용해야 한다. 오버워치와 비슷한 방식*