// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "InventoryItemData.h"
#include "ItemSlot.generated.h"

/**
 * 
 */
UCLASS()
class FRPG_API UItemSlot : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	FReply CustomDetectDrag(const FPointerEvent& InMouseEvent, UWidget* WidgetDetectingDrag, FKey DragKey);
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	void Item_Change_Set();

	UPROPERTY(meta = (BindWidget))
	class UImage* Background;
	UPROPERTY(meta = (BindWidget))
	class UImage* Item_Image;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Item_Count_Text;
	
	FInventoryItemData Item_Data;
	//UPROPERTY(meta = (BindWidget))
	//class UButton* Button;


public:
	//UFUNCTION()
	//void Item_Change(FInventoryItemData ItemData);
	UFUNCTION()
	void Item_Interaction();
	UFUNCTION()
	void Item_Drag();
	UFUNCTION()
	void Item_Drop();
	UFUNCTION()
	void Item_Change(UItemSlot* DragSlot);

};
