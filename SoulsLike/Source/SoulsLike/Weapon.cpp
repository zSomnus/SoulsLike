// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "MainCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"

AWeapon::AWeapon()
{

}

void AWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogTemp, Warning, TEXT("Weapon::OnOverlapBegin()"));

	if (OtherActor)
	{
		AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
		if (MainCharacter)
		{
			Equip(MainCharacter);
		}
	}
}

void AWeapon::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	UE_LOG(LogTemp, Warning, TEXT("Weapon::OnOverlapEnd()"));
}

void AWeapon::Equip(AMainCharacter* Character)
{
	if (Character)
	{
		Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		Mesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* RightHandSocket = Character->GetMesh()->GetSocketByName("RightHandSocket");
		if (RightHandSocket)
		{
			RightHandSocket->AttachActor(this, Character->GetMesh());
		}
	}
}