using UnrealBuildTool;

public class RetroShooterWeapon : ModuleRules
{
    public RetroShooterWeapon(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"}); 
    }
}