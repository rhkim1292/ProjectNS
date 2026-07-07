// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_Weapon_Base.generated.h"

// Define delegate signature
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAmmoChanged);

UCLASS()
class PROJECTNS_API ACPP_Weapon_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Weapon_Base();
	float BaseDamage = 15.0f;
	float FireRate = 0.25f;
	int MaxMagazine = 12;
	int CurrentMagazine = 12;
	int MaxRange = 5000;
	bool bIsEquipped = false;
	bool bIsReloading = false;
	bool bCanFire = true;
	float LastFireTime = 0.0f;
	int AmmoNeeded = 0;
	AActor* CurrentOwner;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
		FOnAmmoChanged OnAmmoChanged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void FireWeapon();
};
