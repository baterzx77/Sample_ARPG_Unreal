// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structs.h"
#include "interractableInterface.h"
#include "ResumeCharacter.h"
#include "Containers/UnrealString.h"
#include "Item.generated.h"



UCLASS()
class RESUME_API AItem : public AActor, public IinterractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Tut")
	class UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Tut")
		FTest ItemData;
	
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	virtual void Interract(class AResumeCharacter* character) override;
	
	FTest GetItemData() const { return ItemData; }

	
	virtual void Use(AResumeCharacter* character) override;
};
