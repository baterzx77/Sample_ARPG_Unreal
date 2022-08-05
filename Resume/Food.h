// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ResumeCharacter.h"
#include "Food.generated.h"

/**
 * 
 */
UCLASS()
class RESUME_API AFood : public AItem
{
	GENERATED_BODY()
public:
	AFood();
protected:

	UPROPERTY(EditAnywhere)
		float RemoveFoodValue;
public:
		virtual void Use(AResumeCharacter* character) override;
};
