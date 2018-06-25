# DanmakuProject
이 레포지토리는 탄막 슈팅 기반 게임을 개발하는데 필요한 기초조사 및 언리얼 엔진에 대한 높은 이해도를 성취하기 위해 만들어졌습니다.



# Bugs Found
이 카테고리는 언리얼 엔진에 대한 이해 도중에 발견된 버그들을 나열한 리스트이며, 다양한 이유가 있을 수 있지만 개발자가 UE4에 리포트를 제출하지는 않습니다.

### UPROPERTY

+ UPROPERTY 지정자인 VisibleAnywhere에 대해 VisibleAnywhere로 선언된 일부 프로퍼티는 따르는 Category="CategoryName"의 영향을 받지 않고 독자적으로 편집된 슬레이트 UI를 보여줍니다(Example : UStaticMeshComponent). 

+ UPROPERTY 지정자인 EditAnywhere에 대해 EditAnywhere로 선언된 일부 프로퍼티는 일부 하위 카테고리 영역에서 VisibleAnywhere보다 제공하는 프로퍼티가 더 작게 노출됩니다.(Example : UStaticMeshComponent, Physics 하위 탭에는 "Simulate Physics"를 비롯한 4종의 프로퍼티 노출이 제한적입니다.


### MovmentComponent

+ 순수하게 블루프린트로 구성된 액터에 대해 MovementComponent를 컴포넌트로써 추가한 후 컨스트럭션 스크립트에서 SetUpdatedComponent()를 통해 RootComponent를 제외한 어떤 하위 컴포넌트로 지정하였을 때, 블루프린트 에디터 내 시뮬레이트 및 독립형 세션에서는 올바르게 동작하나 PIE 세션 및 패키징 버전에서는 SetUpdatedComponent(SomeComponent)의 기능을 무시하고 RootCopmonent에 적용되어 나타납니다. 게다가 단순히 RootComponent에만 적용되는 것이 아닌, 액터 전체에 대한 MovementComponent의 영향이 가해집니다:

Example : RootComponent인 Box Collision이 버그로 ProjectileMovementComponent의 영향을 받고 X축으로 전진하는 영향을 받고 있으면 액터 전체가 영향을 받는 것으로 간주하여, 하위 컴포넌트로 스태틱 메시가 존재할 때 이 스태틱 메시 또한 X축으로 전진하는 영향을 받게 됩니다.

이러한 버그는 C++에서 미리 컴포넌트들을 셋업하고 SetUpdatedComponent를 사용한후 블루프린트 클래스로 파생시킨 경우에 대해서 버그가 아닌 올바른 시뮬레이션을 제공합니다. 즉, C++로 미리 액터 전반에 대한 컴포넌트들의 프로퍼티 셋업을 코딩하십시오.

