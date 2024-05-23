# 시스템 구조 문서

- GAS로 시스템 변경중

## PlayerState

플레이어 State에 `AbilitySystemComponent`, `AttributeSet`을 넣어두고 이를 통해 플레이어의 상태를 관리한다.

즉, 프레젠테이션 or Controller의 역할을 가지며 값이 변경되면 실행할 로직을 정의한다.