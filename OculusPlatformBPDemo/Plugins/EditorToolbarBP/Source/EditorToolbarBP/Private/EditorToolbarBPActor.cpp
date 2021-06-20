// Copyright 2021 InnerLoop LLC. All Rights Reserved.

#include "EditorToolbarBPActor.h"

AEditorToolbarBPActor::AEditorToolbarBPActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
	bIsEditorOnlyActor = 1;
	
}

void AEditorToolbarBPActor::ToolbarAction(AEditorToolbarBPActor *ToolbarActor, uint8 ActionID)
{
	switch (ActionID)
	{
	case 1:
		ToolbarActor->ToolbarAction1();
		break;
	case 2:
		ToolbarActor->ToolbarAction1();
		break;
	}
}

AEditorToolbarBPActor* AEditorToolbarBPActor::SpawnEditorToolbarActor(UObject* WorldContextObject)
{
	return NewObject<AEditorToolbarBPActor>();
}
