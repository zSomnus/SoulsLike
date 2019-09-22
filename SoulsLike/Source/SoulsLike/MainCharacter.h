// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TimelineComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UENUM(BlueprintType)
enum class EMovementStatus : uint8
{
	EMS_Normal UMETA(DisplayName = "Normal"),
	EMS_Dashing UMETA(DisplayName = "Dashing"),
	EMS_MAX UMETA(DisplayName = "DefaultMax")
};

UCLASS()
class SOULSLIKE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timeline")
	UTimelineComponent* RollTimeline;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timeline")
	UTimelineComponent* DodgeTimeline;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timeline")
	UCurveFloat* RollFloatCurve;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timeline")
	UCurveFloat* DodgeFloatCurve;
	
	//RollTimelineCall
	UFUNCTION()
	void RollTimelineCallback(float value);

	UFUNCTION()
	void RollTimelineFinishedCallback();
	
	void PlayRollTimeline();

	//DodgeTimelineCall
	UFUNCTION()
	void DodgeTimelineCallback(float value);

	UFUNCTION()
	void DodgeTimelineFinishedCallback();

	void PlayDodgeTimeline();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timeline")
	TEnumAsByte<ETimelineDirection::Type> TimelineDirection;

public:
	// Sets default values for this character's properties
	AMainCharacter();


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	class AWeapon* EquippedWeapon;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enums")
	EMovementStatus MovementStatus;

	/** Set movement status and running speed */
	void SetMovementStatus(EMovementStatus Status);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enums")
	float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
	float RunningSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
	float DashingSpeed;

	/** Create camera spring are */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	/** Checking the movement state */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bIsRolling;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bIsAttacking;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bIsDodging;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bIsDashing;

	/** Checking if the movement is available */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bCanRoll;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bCanAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bCanDodge;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	bool bCanDash;



	/** Spring Arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringArmRotation")
	bool bIsSpringArmRotate;

	/** 
	/*
	/* Player stats
	/*
	*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 Souls;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable)
	void Roll();

	UFUNCTION(BlueprintCallable)
	void Dodge();

	UFUNCTION(BlueprintCallable)
	void Attack();

	void DashBegin();
	void DashEnd();

	/** Set the player base movements */
	void MoveForward(float Value);
	void MoveRight(float Value);

	/** Set the range that camera can look at */
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	/** Third Person Camera that aligns to movement direction */
	float AlignSpringArmRotation();

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	void IncrementSouls(int32 Amount);

	void DecrementHealth(float Amount);
	void Die();

	FORCEINLINE void SetEquippedWeapon(AWeapon* WeaponToSet) { EquippedWeapon = WeaponToSet; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	class UAnimMontage* RollMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	class UAnimMontage* DodgeMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	class UAnimMontage* AttackMontage;
};
