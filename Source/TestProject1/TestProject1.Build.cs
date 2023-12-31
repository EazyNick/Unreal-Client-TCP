// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestProject1 : ModuleRules
{
	public TestProject1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Networking", "Sockets", "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
