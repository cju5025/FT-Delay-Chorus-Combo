#include "DCV3GainPanel.h"
#include "DCV3Parameters.h"

DCV3GainPanel::DCV3GainPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

DCV3GainPanel::~DCV3GainPanel()
{
    
}


void DCV3GainPanel::setParameterID(int inParameterID)
{
    mGainSlider = std::make_unique<DCV3ParameterSlider>(mProcessor->parameters,
                                                    DCV3ParameterID[inParameterID]);

    const int sliderSize = 75;
    mGainSlider->setBounds((getWidth() * 0.5) - (sliderSize * 0.5),
                       (getHeight() * 0.5) - (sliderSize * 0.5),
                       sliderSize,
                       sliderSize);

    addAndMakeVisible(mGainSlider.get());
}
