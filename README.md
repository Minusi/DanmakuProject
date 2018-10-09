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



### Event Dispatcher

+ 블루프린트 내에서 이벤트 디스패처를 생성하고 이 이름을 해당 블루프린트 내 이벤트그래프에 존재하는 함수/이벤트 이름으로 리네임(rename)할 경우, '겹쳐진이름_0'으로 자동으로 변경되지만 이름만 변경되고 이 순간부터 이벤트 디스패처로써의 기능을 상실하게 됩니다. '내 블루프린트/이벤트 디스패처'에서도 삭제가 불가능하며 이벤트 디스패처의 기능도 하지 않으므로 이 디스패처와 연관된 모든 곳에서 컴파일 에러가 발생합니다. 또한 제거가 불가능해지며 유일한 해결책은 Ctrl+Z로 겹쳐진 이름 이전의 행동으로 돌아가는 것입니다. 이름 겹침 현상에서 벗어나게 된다면 다시 이벤트 디스패처로써의 기능을 시작합니다. 이러한 현상의 원인을 추측하건데 겹쳐지는 이름으로 디스패처명을 설정할 때 이벤트 그래프 및 이벤트 디스패처 카테고리 내의 이름을 변경하지만, 그 이전에 겹쳐진 이름을 가진 대상의 함수성(또는 기능)을 따라가는 것 때문이 아닐까 싶습니다. 






# Tips Found
이 카테고리는 언리얼 엔진에 대한 이해 도중에 알아낸 팁들을 나열한 리스트입니다.

### Profiling

+ GPU 프로파일링의 단축키는 Ctrl + Shift + , 이다. 또는 콘솔에 GPU Profiling(아니면 Profile)을 타이핑하면 된다.

+ 더블 모니터 이상으로 작업하면 GPU에 많은 과부하가 걸리며 이는 프로파일링에서 GPU 병목현상을 야기한다. 하지만 이 점을 UE4 프로파일러에서는 말해주지 않기 때문에 (콘솔창에서 이용할 수 있는 각종 프로파일 기능들은 STAT UNIT에서 보여주는 높은 병목현상만큼의 값을 제출하지 않는다.) 제대로된 퍼포먼스를 확인하고 싶다면 싱글 모니터에서 수행하도록 하는 것이 좋다.

### Input

+ UInputComponent를 가지고 있는 클래스는 Enable Input으로 입력을 가져오는 효과를 볼 수 없으며, Possess를 사용해야 합니다. 즉, Enable Input은 그것이 없는 Actor 클래스 등에 사용되어야 합니다. ~~~ 18.07.23 추가하자면, 입력을 가져오는 효과를 볼 수 없는지는 잘 모르겠다. Possess 상태의 객체에게 Enable Input / Disable Input은 컨트롤러의 입력을 허용 또는 차단하는 효과가 있음을 확인하였다. 추후에 연구하여 더 자세한 결과를 가져오도록 하겠다.



### CharacterMovementComponent

+ Character가 Controller에 의해 이동 로직을 수행할 때, CharacterMovementComponent 내 Rotation Setting에서 Orientation...을 체크하면 별도의 메시 회전 로직을 구현하지 않고도 스켈레탈 메시를 회전시킬 수 있다.

+ CharaterMovementComponent의 점프 부분에서 핵심 로직은 CheckJumpInput이다. 만약 점프 관련된 버그 사항이 존재한다면 이곳을 시작점으로 확대 추적하는 것이 좋다.

+ 같은 프레임 내에서 Jump와 JumpStopping을 호출하는 것은 버그를 야기한다. 경험적으로 Jump에 의해 Z속력 및 JumpCurrentCount의 값은 올바르게 적용되지만 JumpStopping 이후 CanJump는 true 값을 반환해야하지만 false를 반환한다. 요약하자면 Jump를 한 후 공중에서 점프를 멈춘 동작을 행하지만 논리적으로는 전혀 점프를 멈춘 동작으로 인식하지 않는 다는 점이다. 이를 해결하기 위해서는 Delay 함수 또는 SetTimer 함수를 통해 약간의 지연을 주어야 한다.

+ Jump 실행 경과 후 StopJumpping을 호출하지 않으면 JumpCurrentCount가 올라가지 않으므로 MaxJumpCount보다 값이 작다면 계속 점프할 수 있음.

### Camera

+ 항상 Player Controller가 보는 방향으로 Pawn을 회전시키고 싶다면 빙의 가능한 클래스 내 Pawn 카테고리에서 UseControll[Roll/Pitch/Yaw]를 체크하면 된다. (기본적으로 Yaw는 체크되어 있음, 이 기능을 사용하지 않으려면 체크를 푸는 것이 좋다.)

+ 입력 받았을 때 Player Controller가 보는 방향으로 회전시키고 싶다면 위 기능을 전부 끄고 로직으로 구현해야 한다. (Get Controller Rotator-> Break Rot -> Make Rot -> Get Rotate [Forward/Right/Up] Vector -> AddMovementInput 순으로 구현)

+ 카메라가 입력을 받았을 때 부착된 상위 컴포넌트를 중심으로 공전할 지, 또는 자기 자신을 중심으로 회전할 지는 SpringArm에서 UsePawnRotation을 사용할 지 Camera에서 사용할 지에 따라서 결정된다.



### State Machine

+ 스테이트 노드의 디테일 패널에 있는 3가지 이벤트들은 (Entered, Left, Blended) 단순 커스텀 이벤트로써 취급하는 것이 아니라 애님 노티파이 이벤트로 취급하므로 커스텀 이벤트로 생성해놓고 작동이 안되는 어리석은 실수를 하지 말자.

+ 스테이트 머신 내 상태 노드의 Left State Event 또는 컨듀잇 노드에서 나가는 트랜지션 룰의 Start Event는 한 번 콜백하는 것이 아니라 무적권 3번 반응한다. 이유를 찾기 위해 수많은 테스트를 수행했지만 꿋꿋이 3번 이벤트를 발생시킨다. 따라서 단 한 번 이벤트를 발생시키고자 한다면 컨듀잇 노드에서는 End Event를 사용하도록 하자. (상태 노드 내에서는 아직 실험하지 않아서 결과를 모른다.)



### Animation Sequence

+ 애니메이션 시퀀스는 기본적으로 Looping을 수행하며, 현재까지는 이 루핑을 강제로 중단하는 방법을 찾지 못했다(코드로 제어할 수 있을 수도 있을 것 같지만 현재 경험적으로 스크립팅은 불가능).

+ 시퀀스가 기본적으로 Looping하므로 스테이트 머신을 통해 애니메이션 전환을 꾀하는 경우 애니메이션이 끝나기 전에(2번째 루프를 시작하기 전에) 블렌드를 완료하는 것이 좋다. 이유는 애님 노티파이와 연관되어 있는데 애님 노티파이가 프레임의 앞부분에 존재한다면 두 번 호출되며 이것이 게임 로직에 영향을 끼치는 노티파이라면 버그를 유발할 수 있다. 마찬가지로 블렌드 타임이 너무 빨라서 프레임의 뒷부분에 존재하는 애님 노티파이를 실행하지 않을 수도 있으니 게임 로직에 영향을 주는 애님 노티파이는 무시되지 않도록 '상태 전이를 잘 고려해야한다.'

