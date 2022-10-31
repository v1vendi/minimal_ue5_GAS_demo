// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MinimalGASDemo : ModuleRules
{
	public MinimalGASDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"GameplayAbilities"
		});
	}
}
