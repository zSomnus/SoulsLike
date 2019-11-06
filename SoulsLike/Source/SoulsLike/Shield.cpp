// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"
#include "MainCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/SkinnedMeshComponent.h"

AShield::AShield()
{

}

void AShield::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("Shield::OnOverlapBegin()"));

	if (OtherActor)
	{
		AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
		if (MainCharacter)
		{
			Equip(MainCharacter);
		}
	}
}

void AShield::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	UE_LOG(LogTemp, Warning, TEXT("Shield::OnOverlapEnd()"));

}

void AShield::Equip(AMainCharacter* Character)
{
	if (Character)
	{
		Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		Mesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* LeftHandSocket = Character->GetMesh()->GetSocketByName("LeftHandSocket");
		if (LeftHandSocket)
		{
			LeftHandSocket->AttachActor(this, Character->GetMesh());
		}
	}
}