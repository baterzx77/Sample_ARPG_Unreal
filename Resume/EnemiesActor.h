// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemiesActor.generated.h"

UCLASS()
class RESUME_API AEnemiesActor : public AActor
{
	GENERATED_BODY()

		
public:	
	// Sets default values for this actor's properties
	AEnemiesActor();
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Stats")
		float EHealth;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
