#include "DCV3PanelBase.h"

DCV3PanelBase::DCV3PanelBase(DelayChorusv3AudioProcessor* inProcessor)
:   mProcessor(inProcessor)
{
    
}

DCV3PanelBase::~DCV3PanelBase()
{
    
}

void DCV3PanelBase::paint (Graphics& g)
{
    g.setColour(Colours::black);
    g.fillAll();
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}
