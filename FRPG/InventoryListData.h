// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemData.h"
#include "InventoryListData.generated.h"

/**
 * 
 */
UCLASS()
class FRPG_API UInventoryListData : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	FInventoryItemData InventoryItemData;
};
