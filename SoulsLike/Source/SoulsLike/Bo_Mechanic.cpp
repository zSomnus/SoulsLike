// Fill out your copyright notice in the Description page of Project Settings.


#include "Bo_Mechanic.h"

// Sets default values
ABo_Mechanic::ABo_Mechanic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABo_Mechanic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABo_Mechanic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABo_Mechanic::Spawn()
{
}

