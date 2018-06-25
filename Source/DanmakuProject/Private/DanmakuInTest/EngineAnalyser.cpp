// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineAnalyser.h"
#include "Engine/Engine.h"
#include "UObjectMarks.h"


// Sets default values
AEngineAnalyser::AEngineAnalyser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEngineAnalyser::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEngineAnalyser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UObject* AEngineAnalyser::DisplayOuterChain(UObject* InObject, float DisplayTime)
{
	if (InObject != nullptr)
	{
		UObject* currentOuter = InObject;

		for (currentOuter; currentOuter != nullptr; currentOuter = currentOuter->GetOuter())
		{
			if (GEngine != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, DisplayTime, FColor::Blue, FString::Printf(TEXT("%s"), *(currentOuter->GetName())));
			}
		}
		GEngine->AddOnScreenDebugMessage(-1, DisplayTime, FColor::Blue, TEXT("nullptr"));

		return InObject->GetOuter();
	}
	else
	{
		return nullptr;
	}
}

UClass* AEngineAnalyser::DisplayClassChain(UObject* InObject, float DisplayTime)
{
	UObject* OuterChainTraveler = InObject;

	if (InObject != nullptr)
	{
		for (OuterChainTraveler; OuterChainTraveler != nullptr; OuterChainTraveler = OuterChainTraveler->GetOuter())
		{
			if (GEngine != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, DisplayTime, FColor::Red, FString::Printf(TEXT("%s"), *(OuterChainTraveler->GetClass()->GetName())));
			}
		}
		GEngine->AddOnScreenDebugMessage(-1, DisplayTime, FColor::Red, TEXT("nullptr"));

		return InObject->GetClass();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, DisplayTime, FColor::Red, TEXT("DisplayClassChain : Input UObject param is nullptr"));
		return nullptr;
	}
}

FString AEngineAnalyser::DisplayGetFullGroupName(UObject* InObject, bool bStartWithOuter, float DisplayTime)
{
	FString Result = InObject->GetFullGroupName(bStartWithOuter);
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, DisplayTime, FColor::Yellow, Result);
	}

	return Result;
}

UWorld* AEngineAnalyser::GetCurrentWorldFrom(UObject* InObject)
{
	UWorld* ResultWorld;
	if (InObject != nullptr)
	{
		ResultWorld = InObject->GetWorld();
	}
	else
	{
		ResultWorld = nullptr;
	}

	return ResultWorld;
}