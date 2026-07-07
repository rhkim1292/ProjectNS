// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Weapon_Base.h"

// Sets default values
ACPP_Weapon_Base::ACPP_Weapon_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Weapon_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Weapon_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Weapon_Base::FireWeapon()
{
	bCanFire = false;
	CurrentMagazine--;
	if (OnAmmoChanged.IsBound())
	{
		OnAmmoChanged.Broadcast();
	}
	auto temp = UGameplayStatics::GetPlayerCameraManager(this, 0);
	TArray<AActor*> ActorsToIgnore;
	FHitResult Hit;
	UKismetSystemLibrary::LineTraceSingle(this, temp->GetCameraLocation(),
		temp->GetCameraLocation() + temp->GetActorForwardVector() * MaxRange,
		ETraceTypeQuery::TraceTypeQuery1,
		0,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		Hit,
		true);
	
	if (Hit.GetActor())
	{
		//if (UKismetSystemLibrary::DoesImplementInterface(Hit.GetActor(), UCPP_Damage_Interface::StaticClass())){}
	}
}