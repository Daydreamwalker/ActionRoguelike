// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBuyStationItem.generated.h"

class USAction;


UENUM()
enum ItemType
{
	Attack     UMETA(DisplayName = "Attack"),
	Recover    UMETA(DisplayName = "Recover"),
};

/**
 * 
 */
UCLASS(Blueprintable)
class ACTIONROGUELIKE_API USBuyStationItem : public UObject
{
	GENERATED_BODY()
	
protected:

public:

	UPROPERTY(BlueprintReadOnly)
	FName ItemName;

	UPROPERTY(BlueprintReadOnly)
	TEnumAsByte<ItemType> BuyItemType;

	UPROPERTY(BlueprintReadOnly)
	FText BuyItemDescription;

	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<USAction> BuyItemActionClass;

	UPROPERTY(BlueprintReadOnly)
	int CreditsRequiredToPurchase;

	UPROPERTY(BlueprintReadOnly)
	bool bIsAlreadyPurchased;

	UPROPERTY(BlueprintReadOnly)
	float Duration;
};
