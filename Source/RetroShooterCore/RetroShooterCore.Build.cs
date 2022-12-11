using UnrealBuildTool;

public class RetroShooterCore : ModuleRules
{
    public RetroShooterCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "RetroShooterWeapon"}); 
        
    }
}