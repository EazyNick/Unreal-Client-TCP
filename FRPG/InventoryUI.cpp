// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryUI.h"
#include "DragDropWidget.h"
#include <Components/TileView.h>
#include "InventoryListData.h"


//bool UInventoryUI::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
//{
//	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
//
//	UDragDropWidget* DragWidgetResult = Cast<UDragDropWidget>(InOperation);
//
//	if (!IsValid(DragWidgetResult))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Cast returned null."));
//		return false;
//	}
//
//	const FVector2D DragWindowOffset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
//	const FVector2D DragWindowOffsetResult = DragWindowOffset - DragWidgetResult->DragOffset;
//
//	ChangeItem(DragWidgetResult->WidgetReference);
//	//DragWidgetResult->WidgetReference->AddToViewport();
//	//DragWidgetResult->WidgetReference->SetVisibility(ESlateVisibility::Visible);
//	//DragWidgetResult->WidgetReference->SetPositionInViewport(DragWindowOffsetResult, false);
//
//	return true;
//}

void UInventoryUI::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//Item_List[0].
	//UItemSlot* MySlotF = NewObject<UItemSlot>(this, UItemSlot::StaticClass());
	UInventoryListData* ListData1 = NewObject<UInventoryListData>();
	UInventoryListData* ListData2 = NewObject<UInventoryListData>();
	UInventoryListData* ListData3 = NewObject<UInventoryListData>();

	ListData1->InventoryItemData = *(ItemDataTable->FindRow<FInventoryItemData>(FName("0"), FString("")));
	AddItem(ListData1);
	ListData2->InventoryItemData = *(ItemDataTable->FindRow<FInventoryItemData>(FName("1"), FString("")));
	AddItem(ListData2);
	ListData3->InventoryItemData = *(ItemDataTable->FindRow<FInventoryItemData>(FName("2"), FString("")));
	AddItem(ListData3);

	for (int i = 3; i < 100; i++)
	{
		//UItemSlot* MySlot = NewObject<UItemSlot>(this, UItemSlot::StaticClass());
		//AddItem(ItemData);
		UInventoryListData* ListData = NewObject<UInventoryListData>();
		ListData->InventoryItemData.Item_Index = i;
		ListData->InventoryItemData.Item_Count = 0;
		AddItem(ListData);
	}
}

void UInventoryUI::NativeConstruct()
{
	Super::NativeConstruct();


	//ItemData.Item_Texture = TestTexture;


	//ItemSlot->Item_Change(ItemData);

}

void UInventoryUI::AddItem(UObject* Item)
{
	Item_List->AddItem(Item);
}

void UInventoryUI::DeleteItem(UObject* Item)
{
}

void UInventoryUI::ChangeItem()
{
}

void UInventoryUI::TestItem()
{
	UInventoryListData* ItemData = Cast<UInventoryListData>(Item_List->GetItemAt(0));
	ItemData->InventoryItemData.Item_Count = 1;
	Item_List->RegenerateAllEntries();
	UInventoryListData* ItemData2 = Cast<UInventoryListData>(Item_List->GetItemAt(0));
	UE_LOG(LogTemp, Log, TEXT("%d"), ItemData2->InventoryItemData.Item_Count);
}
