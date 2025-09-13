// VehicleHelper/config.cpp
// Vollständige Config für das VehicleHelper-Mod (DayZ).
// Enthält CfgPatches und CfgMods mit korrekten Script-Pfaden (3_Game / 4_World / 5_Mission)
// sowie Angabe der inputs-XML für Community Framework (CF) und versionPath.

class CfgPatches
{
    class VehicleHelper
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class VehicleHelper
    {
        dir = "VehicleHelper";
        name = "VehicleHelper";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 0;
        author = "deinName";
        authorID = "0";
        version = "0.1";
        tooltip = "VehicleHelper - CF gebundenes Ingame Menü Demo";
        overview = "VehicleHelper - Demomod: CF Input + UIScriptedMenu (öffnen mit VH_OpenMenu oder Taste U)";
        versionPath = "VehicleHelper/version.txt";

        // Wichtig für CF: Pfad zu deiner inputs-XML
        inputs = "VehicleHelper/inputs/vehiclehelper_inputs.xml";

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] =
                {
                    "VehicleHelper/Scripts/3_Game"
                };
            };

            class worldScriptModule
            {
                value = "";
                files[] =
                {
                    "VehicleHelper/Scripts/4_World"
                };
            };

            class missionScriptModule
            {
                value = "";
                files[] =
                {
                    "VehicleHelper/Scripts/5_Mission"
                };
            };

            class uiScriptModule
            {
                value = "";
                files[] =
                {
                    "VehicleHelper/Scripts/5_Mission",
                    "VehicleHelper/Scripts/3_Game"
                };
            };
        };
    };
};
