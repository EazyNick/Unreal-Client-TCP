// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestProject2 : ModuleRules
{
	public TestProject2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Networking", "Sockets", "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
