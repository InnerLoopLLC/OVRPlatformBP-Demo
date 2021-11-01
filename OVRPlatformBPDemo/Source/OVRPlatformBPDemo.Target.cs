// Copyright 2021 InnerLoop LLC

using UnrealBuildTool;
using System.Collections.Generic;

public class OVRPlatformBPDemoTarget : TargetRules
{
	public OVRPlatformBPDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		//Use these config options in shipping to enable logs, and to enable debugger.
		if (Configuration == UnrealTargetConfiguration.Shipping)
		{
			BuildEnvironment = TargetBuildEnvironment.Unique;
			bUseLoggingInShipping = true;
		}

		ExtraModuleNames.AddRange( new string[] { "OVRPlatformBPDemo" } );
	}
}
