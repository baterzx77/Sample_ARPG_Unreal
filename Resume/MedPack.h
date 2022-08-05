// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ResumeCharacter.h"
#include "MedPack.generated.h"

/**
 * 
 */
class AResumeCharacter;

UCLASS()
class RESUME_API AMedPack : public AItem
{
	GENERATED_BODY()

public:
	AMedPack();

protected:

	UPROPERTY(EditAnywhere)
		float HealthValue;

public:
	virtual void Use(AResumeCharacter* character) override;
};
