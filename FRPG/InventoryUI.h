// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryUI.generated.h"

/**
 * 
 */
UCLASS()
class FRPG_API UInventoryUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	//virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UTileView* Item_List;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Image")
	UTexture2D* TestTexture1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Image")
	UTexture2D* TestTexture2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	class UDataTable* ItemDataTable;
public:
	void AddItem(UObject* Item);
	void DeleteItem(UObject* Item);
	void ChangeItem();
	void TestItem();
	
};
