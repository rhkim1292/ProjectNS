// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectNSEditorTarget : TargetRules
{
	public ProjectNSEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		BuildEnvironment = TargetBuildEnvironment.Unique;

		ExtraModuleNames.AddRange( new string[] { "ProjectNS" } );
	}
}
