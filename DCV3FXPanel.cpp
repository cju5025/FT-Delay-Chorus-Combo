#include "DCV3FXPanel.h"

DCV3FXPanel::DCV3FXPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor),
    mStyle(kDCV3FXPanelStyle_Delay)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

DCV3FXPanel::~DCV3FXPanel()
{
    
}

void DCV3FXPanel::paint(Graphics& g)
{
    DCV3PanelBase::paint(g);
    
    switch (mStyle)
    {
        case (kDCV3FXPanelStyle_Delay):
        {
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
            
        case (kDCV3FXPanelStyle_Chorus):
        {
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
            
        case (kDCV3FXPanelStyle_TotalNumStyles):
        {
            jassertfalse;
        } break;
    };
}

void DCV3FXPanel::setFXPanelStyle(DCV3FXPanelStyle inStyle)
{
    mStyle = inStyle;
}


