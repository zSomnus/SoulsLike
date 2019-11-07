// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathVectorCommon.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create spring arm "Camera Boom"
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 270.f;	// Length of spring are
	CameraBoom->bUsePawnControlRotation = true;	//We use the Pawn rotation here
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->CameraLagSpeed = 2.f;
	CameraBoom->CameraLagMaxDistance = 100.f;
	
	// Create camera "Follow Camera"
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);	// Attached camera on the end of the spring arm (that end point called "SocketName" by default)
	FollowCamera->bUsePawnControlRotation = true;	// Just rotate with the spring arm

	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;

	// Do not rotate Player facing direction with the camera rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	bIsSpringArmRotate = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;	// Main character moves in the direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.f, 450.f, 0.f);
	GetCharacterMovement()->AirControl = 0.2f;

	
	MaxHealth = 100.f;
	Health = 70.f;
	MaxStamina = 350.f;
	Stamina = 120.f;
	Souls = 100;

	RunningSpeed = 500.f;
	DashingSpeed = 700.f;

	bIsDashing = false;
	bIsRolling = false;
	bIsDodging = false;
	bIsAttacking = false;

	MovementStatus = EMovementStatus::EMS_Normal;
	StaminaDrainRate = 25.f;

	// Set default value of movement, make them available
	bCanRoll = true;
	bCanDodge = true;
	bCanAttack = true;
	bCanDash = true;
	bCanParry = false;

	//Timeline curves
	static ConstructorHelpers::FObjectFinder<UCurveFloat> RollCurve(TEXT("/Game/Curves/C_RollCurve"));
	static ConstructorHelpers::FObjectFinder<UCurveFloat> DodgeCurve(TEXT("/Game/Curves/C_DodgeCurve"));
	static ConstructorHelpers::FObjectFinder<UCurveFloat> AttackStepCurve(TEXT("/Game/Curves/C_AttackStepCurve"));

	check(RollCurve.Succeeded());
	check(DodgeCurve.Succeeded());
	check(AttackStepCurve.Succeeded());

	FVector ActorVelocity = GetActorForwardVector();

	AttackCount = 0;

	// lodad the sound cue object
	/*static ConstructorHelpers::FObjectFinder<USoundCue> WhooshSOundCueObject(TEXT("SoundWave'/Engine/VREditor/Sounds/UI/Teleport_Committed.Teleport_Committed'"));
	if (WhooshSOundCueObject.Succeeded())
	{
		WhooshSoundCue = WhooshSOundCueObject.Object;
	}*/
	//const FVector Destination = GetActorForwardVector() * 5 + GetActorLocation();
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	FOnTimelineFloat onRollTimelineCallback;
	FOnTimelineEventStatic onRollTimelineFinishedCallback;

	FOnTimelineFloat onDodgeTimelineCallback;
	FOnTimelineEventStatic onDodgeTimelineFinishedCallback;

	FOnTimelineFloat onAttackStepTimelineCallback;
	FOnTimelineEventStatic onAttackStepTimelineFinishedCallback;

	Super::BeginPlay();
	
	//Roll timeline
	if (RollFloatCurve)
	{
		//RollTimeLine
		RollTimeline = NewObject<UTimelineComponent>(this, FName("RollTimelineAnimation"));
		RollTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript; // Indicate it comes from a blueprint so it gets cleared when we rerun construction scripts
		this->BlueprintCreatedComponents.Add(RollTimeline);
		RollTimeline->SetNetAddressable();

		RollTimeline->SetPropertySetObject(this);
		RollTimeline->SetTimelineLength(.5f);
		RollTimeline->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);

		onRollTimelineCallback.BindUFunction(this, FName{ TEXT("RollTimelineCallback") });
		onRollTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("RollTimelineFinishedCallback") });
		RollTimeline->AddInterpFloat(RollFloatCurve, onRollTimelineCallback);
		RollTimeline->SetTimelineFinishedFunc(onRollTimelineFinishedCallback);

		RollTimeline->RegisterComponent();
	}

	if(DodgeFloatCurve)
	{
		// DodgeTimeline
		DodgeTimeline = NewObject<UTimelineComponent>(this, FName("DodgeTimelineAnimation"));
		DodgeTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript; // Indicate it comes from a blueprint so it gets cleared when we rerun construction scripts
		this->BlueprintCreatedComponents.Add(DodgeTimeline);
		DodgeTimeline->SetNetAddressable();

		DodgeTimeline->SetPropertySetObject(this);
		DodgeTimeline->SetTimelineLength(.5f);
		DodgeTimeline->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);

		onDodgeTimelineCallback.BindUFunction(this, FName{ TEXT("DodgeTimelineCallback") });
		onDodgeTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("DodgeTimelineFinishedCallback") });
		DodgeTimeline->AddInterpFloat(DodgeFloatCurve, onDodgeTimelineCallback);
		DodgeTimeline->SetTimelineFinishedFunc(onDodgeTimelineFinishedCallback);

		DodgeTimeline->RegisterComponent();
	}
	if (AttackStepFloatCurve)
	{
		//RollTimeLine
		AttackStepTimeline = NewObject<UTimelineComponent>(this, FName("AttackStepTimelineAnimation"));
		AttackStepTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript; // Indicate it comes from a blueprint so it gets cleared when we rerun construction scripts
		this->BlueprintCreatedComponents.Add(AttackStepTimeline);
		AttackStepTimeline->SetNetAddressable();

		AttackStepTimeline->SetPropertySetObject(this);
		AttackStepTimeline->SetTimelineLength(.2f);
		AttackStepTimeline->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);

		onAttackStepTimelineCallback.BindUFunction(this, FName{ TEXT("AttackStepTimelineCallback") });
		onAttackStepTimelineFinishedCallback.BindUFunction(this, FName{ TEXT("AttackStepTimelineFinishedCallback") });
		AttackStepTimeline->AddInterpFloat(AttackStepFloatCurve, onAttackStepTimelineCallback);
		AttackStepTimeline->SetTimelineFinishedFunc(onAttackStepTimelineFinishedCallback);

		AttackStepTimeline->RegisterComponent();
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer = DeltaTime;

	if (Timer == 0.4)
	{
		AttackCount = 0;
		Timer = 0.0f;
	}

	//SetActorLocation(FMath::Lerp(GetActorLocation(), Destination, 1));
	//

	//Roll timeline
	if (RollTimeline)
	{
		RollTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
	// AttackStepTimeline
	if (AttackStepTimeline)
	{
		AttackStepTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}

	float DeltaStamina = StaminaDrainRate * DeltaTime;
	FVector CurrentVelocity = GetVelocity();

	if (bIsDashing)
	{
		if (Stamina > 0.f)
		{
			if (CurrentVelocity != FVector(0.f))
			{
				Stamina -= DeltaStamina;
				SetMovementStatus(EMovementStatus::EMS_Dashing);
			}
			else
			{
				Stamina += DeltaStamina;
				SetMovementStatus(EMovementStatus::EMS_Normal);
			}
		}
		else
		{
			Stamina = 0.f;
			SetMovementStatus(EMovementStatus::EMS_Normal);
		}
	}
	else
	{
		if (Stamina + DeltaStamina >= MaxStamina)
		{
			Stamina = MaxStamina;
		}
		else
		{
			Stamina += DeltaStamina;
		}

		SetMovementStatus(EMovementStatus::EMS_Normal);
	}
}


// Roll Timeline
void AMainCharacter::RollTimelineCallback(float interpolatedVal)
{
	// This function is called for every tick in the timeline.
	const FVector ForwardDir = GetRootComponent()->GetForwardVector() * interpolatedVal;

	//AMainCharacter* Character = Cast<AMainCharacter>();
	LaunchCharacter(ForwardDir, false, true);
}

void AMainCharacter::RollTimelineFinishedCallback()
{
	// This function is called when the timeline finishes playing.
}

// Dodge Timeline
void AMainCharacter::DodgeTimelineCallback(float interpolatedVal)
{
	// This function is called for every tick in the timeline.
	const FVector ForwardDir = GetRootComponent()->GetForwardVector() * -interpolatedVal;

	//AMainCharacter* Character = Cast<AMainCharacter>();
	LaunchCharacter(ForwardDir, false, true);

}

void AMainCharacter::DodgeTimelineFinishedCallback()
{
	// This function is called when the timeline finishes playing.
}

// Attack step Timeline
void AMainCharacter::AttackStepTimelineCallback(float interpolatedVal)
{
	// This function is called for every tick in the timeline.
	//GEngine->AddOnScreenDebugMessage(0, 3, FColor::Red, TEXT("Attack timeline"));
	//
	//const FRotator Rotation = Controller->GetControlRotation();
	//const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	//const FVector Destination = (RootComponent->GetForwardVector() * 2.0f) + RootComponent->GetComponentLocation();
	////const FRotator NewRotation = FRotator(0, FollowCamera->GetComponentRotation().Yaw, 0);
	//FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//const FVector ForwardDir = Direction * interpolatedVal;

	//FVector ForwardDir = FMath::Lerp(GetActorLocation(), Direction, 0.2f);
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDir = GetRootComponent()->GetForwardVector() * 100;
	SetActorRotation(YawRotation);
	LaunchCharacter(ForwardDir, false, true);
	//const FVector Destination = GetActorForwardVector() * 5 + GetActorLocation();
	//SetActorLocation(NewLocation);
	//SetActorLocationAndRotation(NewLocation, YawRotation, true, false);
	//AMainCharacter* Character = Cast<AMainCharacter>();
	//LaunchCharacter(ForwardDir, false, true);
}

void AMainCharacter::AttackStepTimelineFinishedCallback()
{
	// This function is called when the timeline finishes playing.
}


void AMainCharacter::PlayRollTimeline()
{
	if (RollTimeline)
	{
		RollTimeline->PlayFromStart();
	}
}
void AMainCharacter::PlayDodgeTimeline()
{
	if (DodgeTimeline)
	{
		DodgeTimeline->PlayFromStart();
	}
}
void AMainCharacter::PlayAttackStepTimeline()
{
	if (AttackStepTimeline != NULL)
	{
		AttackStepTimeline->PlayFromStart();
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Roll", IE_Released, this, &AMainCharacter::Roll);
	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &AMainCharacter::Dodge);
	//PlayerInputComponent->BindAction("Roll", IE_Released, this, &AMainCharacter::RollEnd);

	PlayerInputComponent->BindAction("Parry", IE_Pressed, this, &AMainCharacter::Parry);

	PlayerInputComponent->BindAction("Block", IE_Pressed, this, &AMainCharacter::BlockBegin);
	PlayerInputComponent->BindAction("Block", IE_Released, this, &AMainCharacter::BlockEnd);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMainCharacter::Attack);

	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &AMainCharacter::DashBegin);
	PlayerInputComponent->BindAction("Dash", IE_Released, this, &AMainCharacter::DashEnd);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

// Roll and Dodge
void AMainCharacter::Roll()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	FVector CurrentVector = GetVelocity();
	float MoveForwardValue = FMath::Abs(GetInputAxisValue(FName("MoveForward")));
	float MoveRightValue = FMath::Abs(GetInputAxisValue(FName("MoveRight")));

	float InputLength = MoveForwardValue + MoveRightValue;

	if ((CurrentVector != FVector(0.f)) && (InputLength != 0.f))
	{
		if (AnimInstance && RollMontage && !bIsRolling)
		{
			if (!bIsDodging && !bIsAttacking && !bIsParrying)
			{
				bIsRolling = true;
				AnimInstance->Montage_Play(RollMontage, 1.f);
				AnimInstance->Montage_JumpToSection(FName("Roll"), RollMontage);
				UE_LOG(LogTemp, Warning, TEXT("Roll"));

				PlayRollTimeline();
			}
			else
			{
				bIsRolling = false;
			}
			
		}
	}
}

void AMainCharacter::Dodge()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	FVector CurrentVector = GetVelocity();
	float MoveForwardValue = FMath::Abs(GetInputAxisValue(FName("MoveForward")));
	float MoveRightValue = FMath::Abs(GetInputAxisValue(FName("MoveRight")));

	float InputLength = MoveForwardValue + MoveRightValue;

	if(CurrentVector == FVector(0.f) && InputLength == 0.f)
	{
		if (AnimInstance && DodgeMontage && !bIsDodging)
		{
			if (!bIsRolling && !bIsAttacking && !bIsParrying)
			{
				bIsDodging = true;
				AnimInstance->Montage_Play(DodgeMontage, 1.f);
				AnimInstance->Montage_JumpToSection(FName("Dodge"), DodgeMontage);
				UE_LOG(LogTemp, Warning, TEXT("Dodge"));

				PlayDodgeTimeline();
			}
			else
			{
				bIsDodging = false;
			}
		}
	}
}

void AMainCharacter::Parry()
{
	UE_LOG(LogTemp, Warning, TEXT("Parry"));
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && ParryMontage && !bIsParrying)
	{
		if (!bIsRolling && !bIsAttacking && !bIsDodging)
		{
			bIsParrying = true;
			AnimInstance->Montage_Play(ParryMontage, 1.f);
			AnimInstance->Montage_JumpToSection(FName("ShieldParry"), ParryMontage);

		}
		else
		{
			bIsParrying = false;
		}
	}
}

// Dash
void AMainCharacter::DashBegin()
{
	bIsDashing = true;
}

void AMainCharacter::DashEnd()
{
	bIsDashing = false;
}

// Movement
void AMainCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		//AddMovementInput(UKismetMathLibrary::GetRightVector(Rotation), Value);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		if (!bIsRolling && !bIsDodging && !bIsAttacking && !bIsParrying)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void AMainCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		//AddMovementInput(UKismetMathLibrary::GetForwardVector(Rotation), Value);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		if (!bIsRolling && !bIsDodging && !bIsAttacking && !bIsParrying)
		{
			AddMovementInput(Direction, Value);
		}

	}
}

float AMainCharacter::AlignSpringArmRotation()
{
	//AddControllerPitchInput(GetWorld()->GetDeltaSeconds());
	FVector MovementVector;
	FVector ForwardVector;
	FVector RightVector;

	FRotator Rotation = FRotator(0.f, 0.f, GetControlRotation().Roll);

	FRotator MovementRotator;
	FRotator ControlRotation;

	ForwardVector = UKismetMathLibrary::GetForwardVector(Rotation) * GetInputAxisValue(TEXT("MoveForward"));
	RightVector = UKismetMathLibrary::GetRightVector(Rotation) * GetInputAxisValue(TEXT("MoveRight"));

	MovementVector = ForwardVector + RightVector;

	MovementRotator = UKismetMathLibrary::MakeRotFromX(ForwardVector);
	ControlRotation = GetControlRotation();

	return (MovementRotator - ControlRotation).Roll;
	
}

void AMainCharacter::TurnAtRate(float Rate)
{

}

void AMainCharacter::LookUpAtRate(float Rate)
{

}

void AMainCharacter::IncrementSouls(int32 Amount)
{
	Souls += Amount;
}

void AMainCharacter::DecrementHealth(float Amount)
{
	if (Health - Amount == 0.f)
	{
		Health -= Amount;
		Die();
	}
	else
	{
		Health -= Amount;
	}
}

void AMainCharacter::Die()
{

}

void AMainCharacter::SetMovementStatus(EMovementStatus Status)
{
	MovementStatus = Status;
	if (MovementStatus == EMovementStatus::EMS_Dashing)
	{
		GetCharacterMovement()->MaxWalkSpeed = DashingSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;
	}
}

void AMainCharacter::Attack()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && AttackMontage && !bIsAttacking)
	{
		if (!bIsAttacking && !bIsDodging && !bIsRolling)
		{
			bIsAttacking = true;
			if (AttackCount < 1)
			{
				AttackCount = 1;
				AnimInstance->Montage_Play(AttackMontage, 1.f);
				AnimInstance->Montage_JumpToSection(FName("Attack1"), AttackMontage);
				//PlayAttackStepTimeline();
				AttackStep();
			}
			else
			{
				AttackCount = 0;
				AnimInstance->Montage_Play(AttackMontage, 1.f);
				AnimInstance->Montage_JumpToSection(FName("Attack2"), AttackMontage);
				//PlayAttackStepTimeline();
				AttackStep();
			}
		}
	}
}

void AMainCharacter::BlockBegin()
{
	bIsBlocking = true;
}
void AMainCharacter::BlockEnd()
{
	bIsBlocking = false;
}

void AMainCharacter::AttackStep()
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDir = GetRootComponent()->GetForwardVector() * 400;
	SetActorRotation(YawRotation);
	LaunchCharacter(ForwardDir, false, true);
}

