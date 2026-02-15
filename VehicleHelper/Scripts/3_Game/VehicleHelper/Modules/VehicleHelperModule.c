class VehicleHelperModule : CF_ModuleGame
{
    void VehicleHelperModule()
    {
    }

    override void OnInit()
    {
        super.OnInit();

        // CF Binding: ruft OnToggleMenu(UAInput) auf, wenn VH_OpenMenu ausgelöst wird
        Bind("OnToggleMenu", "VH_OpenMenu", false);
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);

        // Fallback: Öffnen mit der Taste U (schnelles Testen, unabhängig von Keybinding)
        if (GetGame() && GetGame().GetPlayer())
        {
            if (GetGame().GetInput().LocalPress(KeyCode.KC_U))
            {
                PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
                if (player)
                    ToggleForPlayer(player);
            }
        }
    }

    // Wird vom CF-Input-System aufgerufen (UAInput enthält LocalPress/LocalValue etc.)
    void OnToggleMenu(UAInput input)
    {
        // Reagiere nur auf Press-Events
        if (!input.LocalPress()) return;

        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player) return;

        ToggleForPlayer(player);
    }

    void ToggleForPlayer(PlayerBase player)
    {
        if (!player) return;

        EntityAI itemInHands = player.GetHumanInventory().GetEntityInHands();
        if (!itemInHands) return;

        // Prüfe, ob das Objekt in der Hand eine Flashlight (Testobjekt) ist
        if (!itemInHands.IsKindOf("Flashlight")) return;

        // Menü erstellen und anzeigen
        VehicleHelperMenu menu = new VehicleHelperMenu();
        GetGame().GetUIManager().ShowScriptedMenu(menu);
    }
}