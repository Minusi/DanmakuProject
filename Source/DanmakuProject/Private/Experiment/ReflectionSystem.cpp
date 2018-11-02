// Fill out your copyright notice in the Description page of Project Settings.

#include "ReflectionSystem.h"
#include "Engine/Engine.h"


// Sets default values
AReflectionSystem::AReflectionSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReflectionSystem::BeginPlay()
{
	Super::BeginPlay();
	
	UClass* StaticClassPtr = AReflectionSystem::StaticClass();
	UClass* GetClassPtr = this->GetClass();
	UClass* GetClassFromStaticClassPtr = AReflectionSystem::StaticClass()->GetClass();
	UClass* GetClassToGetClassFromStaticClassPtr = AReflectionSystem::StaticClass()->GetClass()->GetClass();
	UClass* GCTGCTGetClassFormStaticClassPtr = AReflectionSystem::StaticClass()->GetClass()->GetClass()->GetClass();

	FString SCPString = StaticClassPtr->GetName();
	FString GCPString = GetClassPtr->GetName();
	FString GCFSCPString = GetClassFromStaticClassPtr->GetName();
	FString GCTGCFSCP = GetClassToGetClassFromStaticClassPtr->GetName();
	FString GCTGCTGCFSCP = GCTGCTGetClassFormStaticClassPtr->GetName();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, SCPString);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, GCPString);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, GCFSCPString);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, GCTGCFSCP);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, GCTGCTGCFSCP);
	}
}

// Called every frame
void AReflectionSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

