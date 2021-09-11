#pragma once
#include "DCV3PanelBase.h"

class DCV3TopPanel
:   public DCV3PanelBase
{
public:
    
    DCV3TopPanel(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3TopPanel();
    
    void paint(Graphics& g) override;
    
private:
    
};
