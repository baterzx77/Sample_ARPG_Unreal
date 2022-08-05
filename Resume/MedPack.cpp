// Fill out your copyright notice in the Description page of Project Settings.


#include "MedPack.h"
#include "ResumeCharacter.h"

AMedPack::AMedPack()
{
	HealthValue = 10.0f;
	ItemData.ItemClass = StaticClass();
}

void AMedPack::Use(AResumeCharacter* character)
{
	if (character)
	{
		character->AddHealth(HealthValue);
	}
}
