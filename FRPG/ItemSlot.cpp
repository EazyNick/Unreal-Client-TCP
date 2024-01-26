// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSlot.h"
#include <Components/Image.h>
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include "DragDropWidget.h"
#include "InventoryListData.h"

void UItemSlot::NativeConstruct()
{
	//Super::NativeConstruct();
	//Button->OnClicked.AddDynamic(this, &UItemSlot::Item_Interaction);
	////Button->
}

void UItemSlot::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UInventoryListData* ListData = Cast<UInventoryListData>(ListItemObject);
	Item_Data = ListData->InventoryItemData;
	Item_Change_Set();
	UE_LOG(LogTemp, Log, TEXT("NativeOn"));
}

void UItemSlot::NativeOnItemSelectionChanged(bool bIsSelected)
{
	UE_LOG(LogTemp, Log, TEXT("NativeOnSelection"));
}

FReply UItemSlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	if (Item_Data.Item_Count > 0)
	{
		if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
		{
			return CustomDetectDrag(InMouseEvent, this, EKeys::LeftMouseButton);
		}
		else if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
		{
			Item_Interaction();
			return FReply::Handled();
		}
		else
		{
			return FReply::Handled();
		}
	}
	else
	{
		return FReply::Handled();
	}

}

void UItemSlot::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);


	UDragDropWidget* DragDropOperation = NewObject<UDragDropWidget>();
	this->SetVisibility(ESlateVisibility::HitTestInvisible); //HitTestInvisible - 사용자에게 그림으로만 보입니다. 상호작용되지는 않습니다.

	DragDropOperation->WidgetReference = this;
	DragDropOperation->DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	DragDropOperation->DragSlot = this;

	DragDropOperation->DefaultDragVisual = this;
	DragDropOperation->Pivot = EDragPivot::MouseDown;

	OutOperation = DragDropOperation;
	

}

void UItemSlot::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);
	UDragDropWidget* DragWidgetResult = Cast<UDragDropWidget>(InOperation);
	DragWidgetResult->WidgetReference->SetVisibility(ESlateVisibility::Visible);

}

FReply UItemSlot::CustomDetectDrag(const FPointerEvent& InMouseEvent, UWidget* WidgetDetectingDrag, FKey DragKey)
{

	FEventReply Reply;
	Reply.NativeReply = FReply::Handled();

	if (WidgetDetectingDrag)
	{
		TSharedPtr<SWidget> SlateWidgetDetectingDrag = WidgetDetectingDrag->GetCachedWidget();
		if (SlateWidgetDetectingDrag.IsValid())
		{
			Reply.NativeReply = Reply.NativeReply.DetectDrag(SlateWidgetDetectingDrag.ToSharedRef(), DragKey);
			return Reply.NativeReply;
		}
	}
	return FReply::Unhandled();
}

bool UItemSlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	UDragDropWidget* DragWidgetResult = Cast<UDragDropWidget>(InOperation);

	if (!IsValid(DragWidgetResult))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast returned null."));
		return false;
	}
	DragWidgetResult->WidgetReference->SetVisibility(ESlateVisibility::Visible);
	Item_Change(DragWidgetResult->DragSlot);
	

	//const FVector2D DragWindowOffset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition()); 위젯 이동만 할 경우
	//const FVector2D DragWindowOffsetResult = DragWindowOffset - DragWidgetResult->DragOffset;

	//DragWidgetResult->WidgetReference->AddToViewport(); 
	//DragWidgetResult->WidgetReference->SetPositionInViewport(DragWindowOffsetResult, false);

	return true;
}

void UItemSlot::Item_Change_Set()
{
	UInventoryListData* ListData = Cast<UInventoryListData>(GetListItem());
	ListData->InventoryItemData = Item_Data;
	if (Item_Data.Item_Count <= 0)
	{
		Item_Count_Text->SetText(FText());
	}
	else
	{
		Item_Count_Text->SetText(FText::FromString(FString::FromInt(Item_Data.Item_Count)));
	}

	Item_Image->SetBrushFromTexture(Item_Data.Item_Texture);
}

//void UItemSlot::Item_Change(FInventoryItemData ItemData)
//{
//	Item_Data = ItemData;
//	Item_Image->SetBrushFromTexture(Item_Data.Item_Texture);
//}

void UItemSlot::Item_Interaction()
{
	UE_LOG(LogTemp, Log, TEXT("Use Item"));
	Item_Data.Item_Count -= 1;
	if (Item_Data.Item_Count <= 0)
	{
		Item_Data.Item_Count = 0;
		Item_Data.Item_Name = "";
		Item_Data.Item_Texture = nullptr;
		Item_Change_Set();
	}
	else
	{
		Item_Change_Set();
	}
}

void UItemSlot::Item_Drag()
{
}

void UItemSlot::Item_Drop()
{
}

void UItemSlot::Item_Change(UItemSlot* DragSlot)
{
	if (DragSlot != this)
	{
		FInventoryItemData DragData = DragSlot->Item_Data;
		DragSlot->Item_Data = Item_Data;
		DragSlot->Item_Change_Set();
		Item_Data = DragData;
		Item_Change_Set();
	}

}
