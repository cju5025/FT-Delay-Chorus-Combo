#include "DCV3CenterPanel.h"
#include "DCV3Parameters.h"

DCV3CenterPanel::DCV3CenterPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mCenterPanelMenuBar = std::make_unique<DCV3CenterPanelMenuBar>(inProcessor);
    mCenterPanelMenuBar->setTopLeftPosition(0, 0);
    mCenterPanelMenuBar->addFXTypeComboBoxListener(this);
    addAndMakeVisible(mCenterPanelMenuBar.get());
    
    mDelayPanel = std::make_unique<DCV3FXPanel>(inProcessor);
    mDelayPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    mDelayPanel->setFXPanelStyle(kDCV3FXPanelStyle_Delay);
    addChildComponent(mDelayPanel.get());
    
    mChorusPanel = std::make_unique<DCV3FXPanel>(inProcessor);
    mChorusPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    mChorusPanel->setFXPanelStyle(kDCV3FXPanelStyle_Chorus);
    addChildComponent(mChorusPanel.get());
    
    AudioProcessorValueTreeState& tree = mProcessor->parameters;
    
    const float panelToShow =
    *tree.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_DelayType]);
    showPanel((int)panelToShow);
    
}

DCV3CenterPanel::~DCV3CenterPanel()
{
    mCenterPanelMenuBar->removeFXTypeComboBoxListener(this);
}

void DCV3CenterPanel::showPanel(int inPanelID)
{
    switch(inPanelID)
    {
        case(kDCV3FXPanelStyle_Delay):
        {
            mDelayPanel->setVisible(true);
            mChorusPanel->setVisible(false);
        } break;
            
        case(kDCV3FXPanelStyle_Chorus):
        {
            mDelayPanel->setVisible(false);
            mChorusPanel->setVisible(true);
        } break;
    }
}

void DCV3CenterPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    showPanel(comboBoxThatHasChanged->getSelectedItemIndex());
}
