#pragma once
#include "DCV3PanelBase.h"
#include "DCV3TopPanel.h"
#include "DCV3GainPanel.h"
#include "DCV3CenterPanel.h"

class DCV3MainPanel
:   public DCV3PanelBase
{
public:
    
    DCV3MainPanel(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3MainPanel();
    
private:
    
    std::unique_ptr<DCV3TopPanel> mTopPanel;
    std::unique_ptr<DCV3GainPanel> mInputGainPanel;
    std::unique_ptr<DCV3GainPanel> mOutputGainPanel;
    std::unique_ptr<DCV3CenterPanel> mCenterPanel;
};
