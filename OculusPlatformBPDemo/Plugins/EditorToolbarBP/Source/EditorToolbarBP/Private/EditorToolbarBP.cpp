// Copyright 2021 InnerLoop LLC. All Rights Reserved.

#include "EditorToolbarBP.h"
#include "EditorToolbarBPStyle.h"
#include "EditorToolbarBPCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "Engine/Selection.h"
#include "EngineUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsContainer.h"
#include "EditorToolbarBPSettings.h"

DEFINE_LOG_CATEGORY(LogEditorToolbarBP);

static const FName EditorToolbarBPTabName("EditorToolbarBP");

#define LOCTEXT_NAMESPACE "FEditorToolbarBPModule"

void FEditorToolbarBPModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEditorToolbarBPStyle::Initialize();
	FEditorToolbarBPStyle::ReloadTextures();

	// Make events visible in the actor by default, but disabled until used.
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction1));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction2));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction3));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction4));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction5));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction6));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction7));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction8));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction9));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction10));

	// Register settings
	RegisterSettings();

	//auto SettingsActor = GetSettingsActor(); //->GetDefaultObject()
	//FString WorldSettingsActor = "World Settings Actor = " + SettingsActor->GetName();
	//UE_LOG(LogEditorToolbarBP, Log, TEXT("%s"), *WorldSettingsActor);

	//SettingsActor.Get()

	// Get all uobjects, either in the level or if a blueprint editor is open.
	//for (TObjectIterator<TSubclassOf<AEditorToolbarBPActor>> ActorItr; ActorItr; ++ActorItr)
	//{
	//	FString ActorItrName = "World Settings Actor = " + ActorItr->;
	//	UE_LOG(LogEditorToolbarBP, Log, TEXT("%s"), *ActorItrName);
	//}

	// Register menu commands
	FEditorToolbarBPCommands::Register();

	// Create the command list
	CreateCommandList();

	// This could be used instead of CreateCommandList(), but it binds directly to events on specific actors.
	// There are obvious downsides to this, like needing to scan for actors frequently, instead of only when buttons are clicked.
	//BindCommandsToActorEvents(10);

	// Register Menus
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FEditorToolbarBPModule::RegisterMenus));
}

void FEditorToolbarBPModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Unregister the default blueprint events
	FKismetEditorUtilities::UnregisterAutoBlueprintNodeCreation(this);

	// Unregister settings
	UnregisterSettings();

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FEditorToolbarBPStyle::Shutdown();

	FEditorToolbarBPCommands::Unregister();
}

void FEditorToolbarBPModule::ToolbarAction(uint8 ActionNumber)
{
	// Junk function. At least for now.

	/*
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				switch (ActionNumber)
				{
				case 1:
					ActorItr->ToolbarAction1();
					UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 1."));
					break;
				case 2:
					ActorItr->ToolbarAction2();
					UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 1."));
					break;
				default:
					break;
				}
			}
		}
	}
	*/
}

void FEditorToolbarBPModule::ToolbarAction1()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		auto SettingsActor = GetSettingsActor();//->StaticClass();

		FActorSpawnParameters SpawnParams;
		FTransform SpawnTransform;
		
		//auto ActorRef = GEditor->GetWorld()->SpawnActor(SpawnParams->StaticClass())//SpawnActor<SettingsActor->GetClass()>(SettingsActor, SpawnTransform, SpawnParams);

		//ActorRef->ToolbarAction1();
		
		//FString ActorName = "We spawned this actor and executed the action: " + ActorRef->GetName();
		//UE_LOG(LogEditorToolbarBP, Log, TEXT("%s"), *ActorName);


		// Get all uobjects, either in the level or if a blueprint editor is open.
		//for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		//{
		//	FString ActorItrName = "Actor Itr " + ActorItr->GetName();
		//	UE_LOG(LogEditorToolbarBP, Log, TEXT("%s"), *ActorItrName);
			
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			//if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			//{
			//	ActorItr->ToolbarAction1();
			//	UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 1."));
			//}
		//}
	}
}

void FEditorToolbarBPModule::ToolbarAction2()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction2();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 2."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction3()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction3();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 3."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction4()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction4();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 4."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction5()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction5();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 5."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction6()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction6();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 6."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction7()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction7();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 7."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction8()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction8();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 8."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction9()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction9();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 9."));
			}
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction10()
{
	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		// Get all uobjects, either in the level or if a blueprint editor is open.
		for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				ActorItr->ToolbarAction10();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 10."));
			}
		}
	}
}

void FEditorToolbarBPModule::CreateCommandList()
{
	// Create the command list
	PluginCommands = MakeShareable(new FUICommandList);

	// Map actions to the command list
	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[0],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction1),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[1],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction2),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[2],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction3),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[3],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction4),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[4],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction5),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[5],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction6),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[6],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction7),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[7],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction8),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[8],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction9),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[9],
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction10),
		FCanExecuteAction());
}

void FEditorToolbarBPModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	/*
	// This section doesn't seem necessary at the moment. Will worry about it more in the next update, while focusing on appearance
	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FEditorToolbarBPCommands::Get().OpenActionList, PluginCommands);
		}
	}
	*/

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry1 = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEditorToolbarBPCommands::Get().ToolbarAction[0]));
				Entry1.SetCommandList(PluginCommands);
				FToolMenuEntry& Entry2 = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEditorToolbarBPCommands::Get().ToolbarAction[1]));
				Entry2.SetCommandList(PluginCommands);
			}
		}
	}
}

void FEditorToolbarBPModule::RegisterSettings()
{	
	// Registers settings.
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule)
	{
		TSharedPtr<ISettingsContainer> ProjectSettingsContainer = SettingsModule->GetContainer("Project");

		SettingsModule->RegisterSettings("Project", "Plugins", "EditorToolbarBP",
			FText::FromString("EditorToolbarBP"),
			FText::FromString("Configure EditorToolbarBP Settings"),
			GetMutableDefault<UEditorToolbarBPSettings>()
		);
	}
}

void FEditorToolbarBPModule::UnregisterSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule)
	{
		SettingsModule->UnregisterSettings("Project", "EditorToolbarBP", "EditorToolbarBP");
	}
}

TSubclassOf<AEditorToolbarBPActor> FEditorToolbarBPModule::GetSettingsActor()
{
	// Get the settings.
	const UEditorToolbarBPSettings* EditorToolbarBPSettings = GetDefault<UEditorToolbarBPSettings>();

	// Get the ToolbarEvents actor from the content folder.
	TArray<UObject*> ToolbarActors;
	EngineUtils::FindOrLoadAssetsByPath(TEXT("/EditorToolbarBP/"), ToolbarActors, EngineUtils::ATL_Regular);

	// If something exists in the content folder, great. That's where our ToolbarEvents actor is.
	if (ToolbarActors.IsValidIndex(0))
	{
		// We should probably loop through ToolbarActors to make sure there's a ToolbarEvents actor in the array.
		// For now we're just assuming there's only one file in the directory

		// If the actor is set in settings, great. Move on.
		if (EditorToolbarBPSettings->ToolbarActorClass)
		{
			// If the actor set in settings is a ToolbarEvents actor, great. We're done here.
			//if (EditorToolbarBPSettings->ToolbarActorClass->GetPackage() == ToolbarActors[0]->GetPackage() || 
			//	EditorToolbarBPSettings->ToolbarActorClass->GetSuperClass()->GetPackage() == ToolbarActors[0]->GetPackage())
			if (EditorToolbarBPSettings->ToolbarActorClass->IsChildOf(AEditorToolbarBPActor::StaticClass()))
			{
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Settings actor is a ToolbarEvents actor! Hooray!"));
				return EditorToolbarBPSettings->ToolbarActorClass;
			}
			// If the actor set in settings is not a ToolbarEvents actor, panic!
			else
			{
				UE_LOG(LogEditorToolbarBP, Log, TEXT("Settings actor is NOT a ToolbarEvents actor... Booo! Panic!"));

				FString WrongClass = "Wrong Class = " + EditorToolbarBPSettings->ToolbarActorClass->GetPackage()->GetName();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("%s"), *WrongClass);

				FString WrongSuperClass = "Wrong Super Class = " + EditorToolbarBPSettings->ToolbarActorClass->GetSuperClass()->GetPackage()->GetName();
				UE_LOG(LogEditorToolbarBP, Log, TEXT("%s"), *WrongSuperClass);
				// We need to set the settings actor here.
				//EditorToolbarBPSettings->ToolbarActorClass;
				return nullptr;
			}
		}
		// If the actor is not set in the settings, set it based on the actor in the content folder.
		else
		{
			UE_LOG(LogEditorToolbarBP, Log, TEXT("Panic! There's no ToolbarEvents actor selected in settings! No events will be fired!"));
			// We need to set the settings actor here.
			return nullptr;
		}
	}
	// If nothing is found in the content folder... show a warning.
	// Eventually we should just create a new blueprint actor if this happens.
	// That's a problem for future me.
	else
	{
		UE_LOG(LogEditorToolbarBP, Log, TEXT("ToolbarEvents Actor DID NOT LOAD! Should be in '/EditorToolbarBP/Content/'"));
		return nullptr;
	}
}

void FEditorToolbarBPModule::BindCommandsToActorEvents(uint8 NumberOfActions)
{
	// Create the command list
	PluginCommands = MakeShareable(new FUICommandList);

	// Disable action if PIE or SIE
	if (!GEditor->IsPlaySessionInProgress())
	{
		//for (size_t i = 0; i < NumberOfActions; i++)
		//{
			// Action numbers will be one greater than then array index.
			//uint8 ActionID = i + 1;

			// Map actions to the command list
		//	PluginCommands->MapAction(
		//		FEditorToolbarBPCommands::Get().ToolbarAction[0],
		//		FExecuteAction::CreateUFunction(GetSettingsActor().Get(), "ToolbarAction1"),
		//		FCanExecuteAction());
		//}
		/*// Get all uobjects, either in the level or if a blueprint editor is open.
		TObjectIterator<AEditorToolbarBPActor> ActorItr;
		for (ActorItr; ActorItr; ++ActorItr)
		{
			// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
			// Objects open in a blueprint editor will be ignored.
			if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
			{
				for (size_t i = 0; i < NumberOfActions; i++)
				{
					// Action numbers will be one greater than then array index.
					uint8 ActionID = i + 1;

					// Map actions to the command list
					PluginCommands->MapAction(
						FEditorToolbarBPCommands::Get().ToolbarAction[i],
						FExecuteAction::CreateUFunction(*ActorItr, "ToolbarAction", ActionID),
						FCanExecuteAction());
				}
			}
		}*/
	}
}

void FEditorToolbarBPModule::BindCommandToActorInstance(uint8 ActionID)
{
	// Create the command list
	PluginCommands = MakeShareable(new FUICommandList);

	FTransform DefaultTransform;

	auto ToolbarBPActor = AEditorToolbarBPActor::SpawnEditorToolbarActor(GEditor->GetEditorWorldContext().World());

	// Basically, what we're gonna try is spawning an actor and binding events to that actor specifically.
	// Of course, if we spawn the base EditorToolbarBPActor, there will be no actions associated with it.
	// So, we'll have to pre-define a subclass in the settings, then spawn an actor of that subclass

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction[ActionID - 1],
		FExecuteAction::CreateUFunction(ToolbarBPActor, "ToolbarAction", ActionID),
		FCanExecuteAction());
}

void FEditorToolbarBPModule::ExecEventOnActorInstance(uint8 ActionID)
{


}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorToolbarBPModule, EditorToolbarBP)

/*
	// Gets the world. Compare it to the actor.
	GEditor->GetEditorWorldContext();
	GEditor->GetPIEWorldContext();

	// Returns true if blueprint graph is currently open for this class
	FKismetEditorUtilities::GetIBlueprintEditorForObject(ActorItr->GetClass(), false)
*/