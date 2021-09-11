#include "DCV3TopPanel.h"

DCV3TopPanel::DCV3TopPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

DCV3TopPanel::~DCV3TopPanel()
{
    
}

void DCV3TopPanel::paint(Graphics& g)
{
    DCV3PanelBase::paint(g);
    
    g.drawFittedText("Family Time Delay / Chorus", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}
