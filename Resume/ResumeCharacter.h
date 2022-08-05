// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Structs.h"
#include "GameFramework/Character.h"
#include "ResumeCharacter.generated.h"

class AItem;
//struct FTest;

UCLASS(config=Game)
class AResumeCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	
public:
	AResumeCharacter();
	//class AActor* Gen;
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, FVector NormalImpulse,
			const FHitResult& Hit);
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Stat)
		float Damage;

	UPROPERTY()
		class AController* DamageInstigator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		TSubclassOf<UDamageType> DamageType;


protected:
	

	void LigthAttack();

	void HeavyAttack();

	UFUNCTION(BlueprintCallable, Category = "tut")
		void UseItem(TSubclassOf<AItem> ItemSubclass);

	UFUNCTION(BlueprintImplementableEvent, Category = "tut")
		void UpdateStats(float hunger, float health);

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void interract();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
		float Health;

	UPROPERTY(BlueprintReadWrite, Category = Stat)
		float Hunger;

	void OnImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		const FHitResult& Hit);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintImplementableEvent, Category = "Test")
	void AddItemToInventoryWidget(FTest ItemData);

	void AddHealth(float value);
	void RemoveHunger(float value);

	void DMG(AActor* Other)
	{
		UE_LOG(LogTemp, Warning, TEXT("Deal"));
		TSubclassOf<UDamageType> DmgTypeClass = DamageType ? *DamageType : UDamageType::StaticClass();
		Other->TakeDamage(Damage * 0.8, FDamageEvent(DmgTypeClass), DamageInstigator, this);
		//UE_LOG(LogTemp, Warning, TEXT("Name: %s"), Other->GetName());
	}

	void DealDamageTo(class AActor* OtherActor);
};

