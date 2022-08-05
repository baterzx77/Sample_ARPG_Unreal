// Fill out your copyright notice in the Description page of Project Settings.


#include "testEnemyCharacter.h"

// Sets default values
AtestEnemyCharacter::AtestEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AtestEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtestEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AtestEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AtestEnemyCharacter::TakeDamage(float DamageAmount,
	FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	Health -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Demage taken Treeman: %f"), Health);
	return DamageAmount;
}