#include "DCV3FXPanel.h"
#include "DCV3Parameters.h"
#include "DCV3GuiHelpers.h"

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
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight() * 0.75, Justification::centred, 1);
        } break;
            
        case (kDCV3FXPanelStyle_Chorus):
        {
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight() * 0.75, Justification::centred, 1);
        } break;
            
        case (kDCV3FXPanelStyle_TotalNumStyles):
        {
            jassertfalse;
        } break;
    };
    
    for (int i = 0; i < mFXSliders.size(); i++)
    {
        paintComponentLabel(g, mFXSliders[i]);
    }
}

void DCV3FXPanel::setFXPanelStyle(DCV3FXPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mFXSliders.clear();
    
    const int sliderSize = 75;
    int x = 130;
    int y = (getHeight() * 0.5) - (sliderSize * 0.5);
    
    switch (mStyle)
    {
        case (kDCV3FXPanelStyle_Delay):
        {
            DCV3ParameterSlider* time =
            new DCV3ParameterSlider(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_DelayTime]);
            time->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(time);
            mFXSliders.add(time);
            x += sliderSize * 2;
            
            DCV3ParameterSlider* feedback =
            new DCV3ParameterSlider(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_DelayFeedback]);
            feedback->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(feedback);
            mFXSliders.add(feedback);
            x += sliderSize * 2;
            
            DCV3ParameterSlider* wetdry =
            new DCV3ParameterSlider(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_DelayWetDry]);
            wetdry->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(wetdry);
            mFXSliders.add(wetdry);
            
        } break;
            
        case (kDCV3FXPanelStyle_Chorus):
        {
            DCV3ParameterSlider* rate =
            new DCV3ParameterSlider(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_ModulationRate]);
            rate->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(rate);
            mFXSliders.add(rate);
            x += sliderSize * 2;
            
            DCV3ParameterSlider* depth =
            new DCV3ParameterSlider(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_ModulationDepth]);
            depth->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(depth);
            mFXSliders.add(depth);
            x += sliderSize * 2;
            
            DCV3ParameterSlider* wetdry =
            new DCV3ParameterSlider(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_DelayWetDry]);
            wetdry->setBounds(x, y, sliderSize, sliderSize);
            addAndMakeVisible(wetdry);
            mFXSliders.add(wetdry);
            
            
        } break;
            
        case (kDCV3FXPanelStyle_TotalNumStyles):
        {
            jassertfalse;
        } break;
    };
}


