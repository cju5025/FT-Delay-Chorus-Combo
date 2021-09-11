#include "DCV3CenterPanel.h"

DCV3CenterPanel::DCV3CenterPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mCenterPanelMenuBar = std::make_unique<DCV3CenterPanelMenuBar>(inProcessor);
    mCenterPanelMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(mCenterPanelMenuBar.get());
    
    mFXPanel = std::make_unique<DCV3FXPanel>(inProcessor);
    mFXPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mFXPanel.get());
}

DCV3CenterPanel::~DCV3CenterPanel()
{
    
}
