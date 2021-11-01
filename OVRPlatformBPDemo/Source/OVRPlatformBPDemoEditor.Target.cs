// Copyright 2021 InnerLoop LLC

using UnrealBuildTool;
using System.Collections.Generic;

public class OVRPlatformBPDemoEditorTarget : TargetRules
{
	public OVRPlatformBPDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "OVRPlatformBPDemo" } );
	}
}
