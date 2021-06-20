#pragma once

#include "EditorToolbarBPActor.h"
#include "EditorToolbarBPSettings.generated.h"

UCLASS(Config = EditorUserSettings, DefaultConfig)
class UEditorToolbarBPSettings : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Config, Category = EditorToolbarBP)
		TSubclassOf<AEditorToolbarBPActor> ToolbarActorClass;

	UPROPERTY(EditAnywhere, Config, Category = EditorToolbarBP)
		TArray<FEditorToolbarBPActionStruct> ActionInfo;
};