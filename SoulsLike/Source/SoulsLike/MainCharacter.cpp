// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"

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
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* 
	1. Clamp the value of the length of the input vector between 0 to 1 and then multiply it with world delta time
	2. Calculate the defference between "Control Rotation" and "The vector of movement in world coordinates" then take the value of Yaw
	Do multiplication of result of #1 and result of #2 and gives the result to AddControllerYawInput()
	*/
	// Still working on the parts below and function float AMainCharacter::AlignSpringArmRotation(), doesn't make any changes right now....

	//float InputLength = UKismetMathLibrary::Clamp(UKismetMathLibrary::Abs((GetInputAxisValue(TEXT("MoveForward")))) + UKismetMathLibrary::Abs((GetInputAxisValue(TEXT("MoveRight")))), 0.f, 1.f);

	//AddControllerYawInput((UKismetMathLibrary::Clamp(GetWorld()->GetDeltaSeconds() * InputLength, 0.f, 1.f)) * AlignSpringArmRotation());

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

	float Temp = (MovementRotator - ControlRotation).Roll;

	AddControllerYawInput(GetWorld()->GetDeltaSeconds() * Temp);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &AMainCharacter::Roll);
	PlayerInputComponent->BindAction("Roll", IE_Released, this, &AMainCharacter::Roll);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

// Set Player Actions
void AMainCharacter::Roll()
{
	bIsRolling = true;
}

bool AMainCharacter::IsRolling()
{
	return bIsRolling;
}

void AMainCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		//AddMovementInput(UKismetMathLibrary::GetRightVector(Rotation), Value);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
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
		AddMovementInput(Direction, Value);

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