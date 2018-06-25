// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellCharacter.h"


// Sets default values
ASpellCharacter::ASpellCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpellCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpellCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpellCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


/* 사용자 정의 함수 시작 구간 */


void ASpellCharacter::MoveRightOnGround(const float InputValue)
{
	if (Controller != nullptr && InputValue != 0.f)
	{
		AddMovementInput(GetActorRightVector(), InputValue);
	}
}

void ASpellCharacter::MoveForwardOnGround(const float InputValue)
{
	if (Controller != nullptr && InputValue != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), InputValue);
	}
}

void ASpellCharacter::MoveForwardOnSky(const float InputValue)
{
	
}