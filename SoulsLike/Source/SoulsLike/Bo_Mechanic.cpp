// Fill out your copyright notice in the Description page of Project Settings.


#include "Bo_Mechanic.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"
#include "TimerManager.h"
#include "Engine.h"


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

	LightIntensity = 8000.f;
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = true;
	RootComponent = PointLight;


}


// Called when the game starts or when spawned
void ABo_Mechanic::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ABo_Mechanic::GetRadomDelay, Delay1, true, 1);
}

// Called every frame
void ABo_Mechanic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ABo_Mechanic::GetRadomDelay()
{
	FMath random;
	Delay2 = random.RandRange(2, 6);
	PointLight->ToggleVisibility();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("number:%d"), Delay2));
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ABo_Mechanic::BallAttack, Delay2,false);





}

void ABo_Mechanic::BallAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Yo!!!")));

	if (Delay2 == 2) {
		Spawn(MySceneThird);
	}
	else if (Delay2 == 3) {
		Spawn(MySceneSecond);
		Spawn(MySceneForth);
	}
	else if (Delay2 == 4) {
		Spawn(MySceneFirst);
		Spawn(MySceneThird);
		Spawn(MySceneFifth);
	}
	else if (Delay2 == 5) {
		Spawn(MySceneFirst);
		Spawn(MySceneSecond);
		Spawn(MySceneForth);
		Spawn(MySceneFifth);
	}
	else if (Delay2 == 6) {
		Spawn(MySceneFirst);
		Spawn(MySceneSecond);
		Spawn(MySceneThird);
		Spawn(MySceneForth);
		Spawn(MySceneFifth);
	}

	GetRadomDelay();
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


