// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_Object.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum FruitList
{
	Apple UMETA(DisplayName = "Apple"),
	Mango UMETA(DisplayName = "Mango"),
	Banana UMETA(DisplayName = "Banana"),
};

USTRUCT(BlueprintType)
struct FBook
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int NumberOfPages;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Rating;

	
};

UCLASS(Blueprintable)
class PROJECTNS_API UCPP_Object : public UObject
{
	GENERATED_BODY()
private:
	int OurPrivateIntegerVariable;
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int OurPublicIntegerVariable;
	UFUNCTION(BlueprintPure)
		int GetOurPrivateInteger();
	UFUNCTION(BlueprintCallable)
		void SetOurPrivateInteger(UPARAM(ref)int& NewValue);
	UFUNCTION(BlueprintCallable)
		static void Test(UPARAM(ref)FBook& Target, UObject* Context);
};