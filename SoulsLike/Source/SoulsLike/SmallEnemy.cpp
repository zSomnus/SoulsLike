// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallEnemy.h"
#include "Components/WidgetComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MainCharacter.h"
#include "Engine.h"

// Sets default values
ASmallEnemy::ASmallEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;

	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Damage = 1.f;
}

// Called when the game starts or when spawned
void ASmallEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASmallEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	TArray<TEnumAsByte<EObjectTypeQuery>> query;
	TArray<AActor*> ignore;
	TArray<AActor*> out;
	UKismetSystemLibrary::SphereOverlapActors(this, this->GetActorLocation(), Distance, query, AMainCharacter::StaticClass(), ignore, out);

	NumOfCharacter = out.Num();

	//for (auto actor : out)
	//{
	//	auto player = Cast<AMainCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());

	//	if (player != nullptr)
	//	{
	//		//Player->HP -= 0.1f;
	//		GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Black, "Player");
	//		Material->SetScalarParameterValue(TEXT("AlphaValue"), 1.0f);

	//		FTimerHandle timer;
	//		GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Black, "hhhhhhhhhhh");
	//		GetWorldTimerManager().SetTimer(timer, this, &AProximityMine::Explode, Delay, false);
	//		//GetWorldTimerManager().SetTimer(TimerHandle, this, &AProximityMine::Explode, Delay, false);
	//	}
	//	else
	//	{
	//		bInRange = false;
	//	}
	//}
}

// Called to bind functionality to input
void ASmallEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASmallEnemy::Attack()
{
	auto player = Cast<AMainCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (player != nullptr)
	{
		player->Health -= 1.f;
	}
}

void ASmallEnemy::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto player = Cast<AMainCharacter>(Other);
	if (player != nullptr)
	{
		player->Health -= (1 + NumOfCharacter * Damage);
		if (Particle != nullptr)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, GetTransform());
		}
		if (Sound != nullptr)
		{
			UGameplayStatics::PlaySound2D(this, Sound);
		}
	}
	Destroy();
}

