#include "DCV3MainPanel.h"
#include "DCV3Parameters.h"

DCV3MainPanel::DCV3MainPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<DCV3TopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel.get());
    
    mInputGainPanel = std::make_unique<DCV3GainPanel>(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(kDCV3Parameter_InputGain);
    addAndMakeVisible(mInputGainPanel.get());
    
    mCenterPanel = std::make_unique<DCV3CenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel.get());
    
    mOutputGainPanel = std::make_unique<DCV3GainPanel>(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(kDCV3Parameter_OutputGain);
    addAndMakeVisible(mOutputGainPanel.get());
}

DCV3MainPanel::~DCV3MainPanel()
{
    
}
