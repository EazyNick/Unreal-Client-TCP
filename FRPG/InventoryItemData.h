// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/DataTable.h>
#include "InventoryItemData.generated.h"

/**
 * 
 */
class FRPG_API InventoryItemData
{
public:
	InventoryItemData();
	~InventoryItemData();
};

USTRUCT(Atomic, BlueprintType)
struct FInventoryItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Item_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Item_Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Index;
};
