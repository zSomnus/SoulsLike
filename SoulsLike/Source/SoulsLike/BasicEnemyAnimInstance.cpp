// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemyAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.h"

void UBasicEnemyAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			MainCharacter = Cast<AMainCharacter>(Pawn);
		}
	}
}

void UBasicEnemyAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();

		if (MainCharacter == nullptr)
		{
			MainCharacter = Cast<AMainCharacter>(Pawn);
		}
	}
}
