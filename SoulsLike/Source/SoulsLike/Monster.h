// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Monster.generated.h"

/**
 * 
 */
UCLASS()
class SOULSLIKE_API AMonster : public AAIController
{
	GENERATED_BODY()


		UPROPERTY(transient)
		class UBlackboardComponent* BlackBoardComp;
	UPROPERTY(transient)
		class UBehaviorTreeComponent* BehaviorComp;


	UPROPERTY(EditAnywhere)
		float Damage;

	UPROPERTY(EditAnywhere)
		float Distance;

	UPROPERTY(EditAnywhere)
		UParticleSystem* Particle;

	UPROPERTY(EditAnywhere)
		class USoundCue* Sound;

public :
	AMonster();

	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
		void Attack();

	uint8 MonsterKeyID;
};
