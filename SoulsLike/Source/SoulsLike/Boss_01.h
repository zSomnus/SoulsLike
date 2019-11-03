// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Boss_01.generated.h"

UCLASS()
class SOULSLIKE_API ABoss_01 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoss_01();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float MaxHealth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
