// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "MonsterCharacter.h"
#include "Monster.h"
#include "MainCharacter.h"


AMonster::AMonster()
{
	BlackBoardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void AMonster::OnPossess(APawn* InPawn) 
{
	Super::Possess(InPawn);

	AMonsterCharacter* Char = Cast<AMonsterCharacter>(InPawn);

	if (Char && Char->BotBehavior)
	{
		BlackBoardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		MonsterKeyID = BlackBoardComp->GetKeyID("target");

		BehaviorComp->StartTree(*Char->BotBehavior); 
	}
	
}

void AMonster::Attack()
{
	auto player = Cast<AMainCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if (player != nullptr)
	{
		player->Health -= 1.f;
	}
}

