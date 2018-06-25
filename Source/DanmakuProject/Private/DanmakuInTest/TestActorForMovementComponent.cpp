// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActorForMovementComponent.h"
#include "Engine/Engine.h"

// Sets default values
ATestActorForMovementComponent::ATestActorForMovementComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootCollision"));
	RootComponent = RootCollisionComponent;

	SubStaticMeshComponent1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpehreMesh"));
	SubStaticMeshComponent2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConeMesh"));
	SubStaticMeshComponent3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	SubStaticMeshComponent1->SetupAttachment(RootComponent);
	SubStaticMeshComponent2->SetupAttachment(RootComponent);
	SubStaticMeshComponent3->SetupAttachment(RootComponent);
	
	SMComponentProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	SMComponentProjectileMovementComponent->SetUpdatedComponent(SubStaticMeshComponent1);

	SMComponentRotationMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	SMComponentRotationMovementComponent->SetUpdatedComponent(SubStaticMeshComponent2);
}

// Called when the game starts or when spawned
void ATestActorForMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATestActorForMovementComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
