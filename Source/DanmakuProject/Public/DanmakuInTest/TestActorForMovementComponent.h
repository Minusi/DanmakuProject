// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "TestActorForMovementComponent.generated.h"

UCLASS()
class DANMAKUPROJECT_API ATestActorForMovementComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActorForMovementComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* RootCollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* SubStaticMeshComponent1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* SubStaticMeshComponent2;

	/* 큐브메시를 포함해야하는 메시 컴포넌트입니다 */ 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* SubStaticMeshComponent3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProjectileMovementComponent* SMComponentProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class URotatingMovementComponent* SMComponentRotationMovementComponent;
	
};