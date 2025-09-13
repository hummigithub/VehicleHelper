class VehicleHelperMenu extends UIScriptedMenu
{
    protected Widget      m_Root;
    protected Widget      m_Panel;
    protected TextWidget  m_Title;
    protected ButtonWidget m_CloseBtn;
    protected ButtonWidget m_Action1;
    protected ButtonWidget m_Action2;

    void VehicleHelperMenu()
    {
    }

    override Widget Init()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("VehicleHelper/GUI/layouts/vehiclehelper_menu.layout");

        m_Panel    = Widget.Cast(m_Root.FindAnyWidget("panel_root"));
        m_Title    = TextWidget.Cast(m_Root.FindAnyWidget("title_text"));
        m_CloseBtn = ButtonWidget.Cast(m_Root.FindAnyWidget("btn_close"));
        m_Action1  = ButtonWidget.Cast(m_Root.FindAnyWidget("btn_action1"));
        m_Action2  = ButtonWidget.Cast(m_Root.FindAnyWidget("btn_action2"));

        if (m_Title)
            m_Title.SetText("VehicleHelper - Interaktionsmenü");

        if (m_CloseBtn) m_CloseBtn.SetHandler(this);
        if (m_Action1)  m_Action1.SetHandler(this);
        if (m_Action2)  m_Action2.SetHandler(this);

        return m_Root;
    }

    override void OnShow()
    {
        super.OnShow();
        GetGame().GetUIManager().ShowCursor(true);
    }

    override void OnHide()
    {
        super.OnHide();
        GetGame().GetUIManager().ShowCursor(false);
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_CloseBtn)
        {
            Close();
            return true;
        }

        if (w == m_Action1)
        {
            DoAction1();
            return true;
        }

        if (w == m_Action2)
        {
            DoAction2();
            return true;
        }

        return false;
    }

    void DoAction1()
    {
        GetGame().GetMission().DisplayNotification("Action 1 ausgeführt");
    }

    void DoAction2()
    {
        GetGame().GetMission().DisplayNotification("Action 2 ausgeführt");
    }

    void Close()
    {
        GetGame().GetUIManager().Back();
    }
}