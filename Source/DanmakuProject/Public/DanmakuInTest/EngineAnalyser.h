// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "EngineAnalyser.generated.h"

UCLASS()
class DANMAKUPROJECT_API AEngineAnalyser : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEngineAnalyser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;




public:
	/**********************
	*** Anaysis Method ***
	**********************/

	// InObject의 OuterChain을 거슬러 올라가면서 Outer들을 게임 내 화면에 디스플레이합니다.
	// 반환값은 InObject의 Outer를 반환합니다.
	UFUNCTION(BlueprintCallable)
		static UObject* DisplayOuterChain(UObject* InObject, float DisplayTime = 10.0f);

	// InClass의 OuterChain을 거슬러 올라가면서 Outer의 UClass를 게임 내 화면에 디스플레이합니다.
	// 반환값은 InClass의 Outer의 UClass입니다.
	// 인자가 UObject인 이유는 UObject를 상속한 모든 객체는 리플렉션을 위해 ClassPrivate를 보유하고 있기 때문입니다.
	UFUNCTION(BlueprintCallable)
		static UClass* DisplayClassChain(UObject* InClass, float DisplayTime = 10.0f);

	// GetFullName의 래퍼 함수입니다. GetFullName을 게임 내 화면에 디스플레이합니다.
	UFUNCTION(BlueprintCallable)
		static FString DisplayGetFullGroupName(UObject* InObject, bool bStartWithOuter = false, float DisplayTime = 10.0f);

public:
	/**********************
	*** Accessor Method ***
	***********************/

	// InObject의 World를 반환합니다.
	// InObject가 nullptr이 아닐 때 내부적으로 GetWorld 함수를 호출하고 그렇지 않으면 nullptr을 반환합니다.
	UFUNCTION(BlueprintCallable)
	static UWorld* GetCurrentWorldFrom(UObject* InObject);
};