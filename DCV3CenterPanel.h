#pragma once
#include "DCV3PanelBase.h"
#include "DCV3CenterPanelMenuBar.h"
#include "DCV3FXPanel.h"

class DCV3CenterPanel
:   public DCV3PanelBase
{
public:
    
    DCV3CenterPanel(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3CenterPanel();
    
private:
    
    std::unique_ptr<DCV3CenterPanelMenuBar> mCenterPanelMenuBar;
    std::unique_ptr<DCV3FXPanel> mFXPanel;
};
