// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss_01.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ABoss_01::ABoss_01()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Health = 100.0f;
	MaxHealth = 100.0f;

}

// Called when the game starts or when spawned
void ABoss_01::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABoss_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoss_01::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

