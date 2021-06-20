// Copyright 2021 InnerLoop LLC. All Rights Reserved.

#pragma once

#include "EditorToolbarBPActor.generated.h"

UCLASS(Blueprintable)
class EDITORTOOLBARBP_API AEditorToolbarBPActor : public AActor
{

	GENERATED_UCLASS_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 1"))
		void ToolbarAction1();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 2"))
		void ToolbarAction2();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 3"))
		void ToolbarAction3();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 4"))
		void ToolbarAction4();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 5"))
		void ToolbarAction5();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 6"))
		void ToolbarAction6();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 7"))
		void ToolbarAction7();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 8"))
		void ToolbarAction8();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 9"))
		void ToolbarAction9();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 10"))
		void ToolbarAction10();

	UFUNCTION(CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 10"))
		static void ToolbarAction(AEditorToolbarBPActor *ToolbarActor, uint8 ActionID);

	static AEditorToolbarBPActor* SpawnEditorToolbarActor(UObject* WorldContextObject);
};