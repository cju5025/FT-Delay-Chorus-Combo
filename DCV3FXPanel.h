#pragma once
#include "DCV3PanelBase.h"
#include "DCV3ParameterSlider.h"

enum DCV3FXPanelStyle
{
    kDCV3FXPanelStyle_Delay,
    kDCV3FXPanelStyle_Chorus,
    kDCV3FXPanelStyle_TotalNumStyles,
};

class DCV3FXPanel
:   public DCV3PanelBase
{
public:
    
    DCV3FXPanel(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3FXPanel();
    
    void paint(Graphics& g) override;
    void setFXPanelStyle(DCV3FXPanelStyle inStyle);
    
private:
    DCV3FXPanelStyle mStyle;
    
    String mLabel;
    
    OwnedArray<DCV3ParameterSlider> mFXSliders;
    
};
