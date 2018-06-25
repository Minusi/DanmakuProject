// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "SpellCharacter.generated.h"

UCLASS()
class DANMAKUPROJECT_API ASpellCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpellCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


/* 클래스 멤버 변수 시작 */
private:
	// 추가 예정 : 스펠 관리자


/* 클래스 멤버 함수 시작 */
private:

	// 캐릭터를 입력값에 따라 지상에서 좌우로 움직입니다.
	void MoveRightOnGround(const float InputValue);
	
	// 캐릭터를 입력값에 따라 지상에서 앞뒤로 움직입니다.
	void MoveForwardOnGround(const float InputValue);

	// 캐릭터를 입력값에 따라 공중에서 좌우로 움직입니다.
	void MoveRightOnSky(const float InputValue);

	// 캐릭터를 입력값에 따라 공중에서 앞뒤로 움직입니다.
	// 이 때, MoveForwardOnGround 함수와 달리 X,Z축이 변경대상이 될 수 있습니다.
	void MoveForwardOnSky(const float InputValue);

};
