#include "DCV3CenterPanelMenuBar.h"
#include "DCV3Parameters.h"

DCV3CenterPanelMenuBar::DCV3CenterPanelMenuBar(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
    
    const int comboBoxWidth = 100;
    const int componentWidth = CENTER_PANEL_MENU_BAR_WIDTH;
    const int componentHeight = CENTER_PANEL_MENU_BAR_HEIGHT;
    
    int typeIndex = *inProcessor->parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_DelayType]);
    
    mFXTypeComboBox =
    std::make_unique<DCV3ParameterComboBox>(mProcessor->parameters, DCV3ParameterID[kDCV3Parameter_DelayType]);
    mFXTypeComboBox->setBounds(componentWidth - comboBoxWidth, 0, comboBoxWidth, componentHeight);
    mFXTypeComboBox->addItem("DELAY", 1);
    mFXTypeComboBox->addItem("CHORUS", 2);
    mFXTypeComboBox->setSelectedItemIndex(typeIndex, dontSendNotification);
    addAndMakeVisible(mFXTypeComboBox.get());
}

DCV3CenterPanelMenuBar::~DCV3CenterPanelMenuBar()
{
    
}

void DCV3CenterPanelMenuBar::addFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFXTypeComboBox->addListener(inListener);
}

void DCV3CenterPanelMenuBar::removeFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFXTypeComboBox->removeListener(inListener);
}
