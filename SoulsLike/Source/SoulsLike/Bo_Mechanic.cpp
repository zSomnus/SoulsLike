// Fill out your copyright notice in the Description page of Project Settings.


#include "Bo_Mechanic.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"

// Sets default values
ABo_Mechanic::ABo_Mechanic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyCollisionShere = CreateDefaultSubobject<USphereComponent>(TEXT("My Shere Component"));
	MyCollisionShere->InitSphereRadius(50.f);
	MyCollisionShere->SetCollisionProfileName("Trigger");
	RootComponent = MyCollisionShere;

	MySceneFirst = CreateDefaultSubobject<USceneComponent>(TEXT("My Mesh1"));
	MySceneFirst->SetupAttachment(RootComponent);

	MySceneSecond= CreateDefaultSubobject<USceneComponent>(TEXT("My Mesh2"));
	MySceneSecond->SetupAttachment(RootComponent);

	MySceneThird=CreateDefaultSubobject<USceneComponent>(TEXT("My Mesh3"));
	MySceneThird->SetupAttachment(RootComponent);

	MySceneForth= CreateDefaultSubobject<USceneComponent>(TEXT("My Mesh4"));
	MySceneForth->SetupAttachment(RootComponent);

	MySceneFifth= CreateDefaultSubobject<USceneComponent>(TEXT("My Mesh5"));
	MySceneFifth->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void ABo_Mechanic::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ABo_Mechanic::BallAttack, Delay1, true, Delay2);
}

// Called every frame
void ABo_Mechanic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ABo_Mechanic::BallAttack()
{
	FMath random;
	float temp = random.RandRange(0, 4);

	if (temp == 0) {
		Spawn(MySceneThird);
	}
	else if (temp == 1) {
		Spawn(MySceneSecond);
		Spawn(MySceneForth);
	}
	else if (temp == 2) {
		Spawn(MySceneFirst);
		Spawn(MySceneThird);
		Spawn(MySceneFifth);
	}
	else if (temp == 3) {
		Spawn(MySceneFirst);
		Spawn(MySceneSecond);
		Spawn(MySceneForth);
		Spawn(MySceneFifth);
	}
	else if (temp == 4) {
		Spawn(MySceneFirst);
		Spawn(MySceneSecond);
		Spawn(MySceneThird);
		Spawn(MySceneForth);
		Spawn(MySceneFifth);
	}

}



void ABo_Mechanic::Spawn(class USceneComponent* scene)
{
	if (ToSpawn) {

		UWorld* world = GetWorld();
		if (world) {
			
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			FRotator rotator;
		//	FVector spawnLocation = scene->GetActorLocation();
		//	world->SpawnActor<AActor>(ToSpawn,spawnLocation,rotator,spawnParams);
			world->SpawnActor<AActor>(ToSpawn, scene->GetComponentLocation(), rotator, spawnParams);

		}
	}
}


