#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "DCV3InterfaceDefines.h"

class DCV3PanelBase
:   public Component
{
public:
    
    DCV3PanelBase(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3PanelBase();
    
    void paint (Graphics& g) override;
    
protected:
    
    DelayChorusv3AudioProcessor* mProcessor;
    
};
