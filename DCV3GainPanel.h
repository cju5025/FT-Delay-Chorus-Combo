#pragma once
#include "DCV3PanelBase.h"
#include "DCV3ParameterSlider.h"

class DCV3GainPanel
:   public DCV3PanelBase
{
public:
    
    DCV3GainPanel(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3GainPanel();
    
    void setParameterID(int inParameterID);

private:
    
    std::unique_ptr<DCV3ParameterSlider> mGainSlider;
    
}; 
