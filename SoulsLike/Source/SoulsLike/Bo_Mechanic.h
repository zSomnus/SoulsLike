// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bo_Mechanic.generated.h"

class UPointLightComponent;
class USphereComponent;
UCLASS()
class SOULSLIKE_API ABo_Mechanic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABo_Mechanic();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> ToSpawn;
	UPROPERTY(VisibleAnywhere)
		class USphereComponent* MyCollisionShere;
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* MySceneFirst;
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* MySceneSecond;
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* MySceneThird;
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* MySceneForth;
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* MySceneFifth;
	UPROPERTY(VisibleAnywhere)
		FTimerHandle MemberTimerHandle;
	UPROPERTY(EditAnywhere, Category = "Delay")
		int Delay1=8;
	UPROPERTY(EditAnywhere, Category = "Delay")
		int Delay2=1;


	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		UPointLightComponent* PointLight1;
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		UPointLightComponent* PointLight2;
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		UPointLightComponent* PointLight3;
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		UPointLightComponent* PointLight4;
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		UPointLightComponent* PointLight5;

	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		USphereComponent* LightSphere;
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		float LightIntensity;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Spawn(class USceneComponent* scene);
	UFUNCTION(BlueprintCallable)
		void BallAttack();
	UFUNCTION(BlueprintCallable)
		void GetRadomDelay();
};
