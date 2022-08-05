// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemiesActor.h"

// Sets default values
AEnemiesActor::AEnemiesActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EHealth = 100.0f;
}

float AEnemiesActor::TakeDamage(float DamageAmount, 
	FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	EHealth -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Demage taken: %f"), EHealth);
	return DamageAmount;
}

// Called when the game starts or when spawned
void AEnemiesActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemiesActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

