// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "ItemSlot.h"
#include "DragDropWidget.generated.h"

/**
 * 
 */
UCLASS()
class FRPG_API UDragDropWidget : public UDragDropOperation
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* WidgetReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D DragOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UItemSlot* DragSlot;
};
