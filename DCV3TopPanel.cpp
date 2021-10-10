#include "DCV3TopPanel.h"

DCV3TopPanel::DCV3TopPanel(DelayChorusv3AudioProcessor* inProcessor)
:   DCV3PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;
    
    mNewPresetButton = std::make_unique<TextButton>("NEW");
    mNewPresetButton->setBounds(button_x, button_y, button_w, button_h);
    mNewPresetButton->onClick = [this]
        {
            mProcessor->getPresetManager()->createNewPreset();
            updatePresetComboBox();
        };
    addAndMakeVisible(mNewPresetButton.get());
    button_x = button_x + button_w;
    
    mSavePresetButton = std::make_unique<TextButton>("SAVE");
    mSavePresetButton->setBounds(button_x, button_y, button_w, button_h);
    mSavePresetButton->onClick = [this]
        {
            if(mProcessor->getPresetManager()->isCurrentPresetSaved())
            {
                mProcessor->getPresetManager()->savePreset();
            } else
            {
                displaySaveAsPopup();
            }
            updatePresetComboBox();
        };
    addAndMakeVisible(mSavePresetButton.get());
    button_x = button_x + button_w;
    
    mSaveAsPresetButton = std::make_unique<TextButton>("SAVE AS");
    mSaveAsPresetButton->setBounds(button_x, button_y, button_w, button_h);
    mSaveAsPresetButton->onClick = [this]
    {
        displaySaveAsPopup();
        updatePresetComboBox();
    };
    addAndMakeVisible(mSaveAsPresetButton.get());
    
    const int comboBox_w = 200;
    const int comboBox_x = TOP_PANEL_WIDTH * 0.5 - comboBox_w * 0.5;
    
    mPresetDisplay = std::make_unique<ComboBox>();
    mPresetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
    mPresetDisplay->onChange = [this]
    {
        mProcessor->getPresetManager()->loadPreset(mPresetDisplay->getSelectedItemIndex());
    };
    addAndMakeVisible(mPresetDisplay.get());
    
    updatePresetComboBox();
}

DCV3TopPanel::~DCV3TopPanel()
{
    
}

void DCV3TopPanel::paint(Graphics& g)
{
    DCV3PanelBase::paint(g);
    
    g.drawFittedText("Family Time Delay / Chorus", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}

void DCV3TopPanel::displaySaveAsPopup()
{
    
    DCV3PresetManager* presetManager = mProcessor->getPresetManager();

    String currentPresetName = presetManager->getCurrentPresetName();
    
    if (presetManager->isCurrentPresetSaved())
    {
        currentPresetName = currentPresetName + "_1";
    }
#if JUCE_MODAL_LOOPS_PERMITTED
    AlertWindow window ("Save As", "Enter Preset Name", AlertWindow::NoIcon);
    window.centreAroundComponent(this, getWidth(), getHeight());
    window.addTextEditor("presetName", currentPresetName, "preset name: ");
    window.addButton("Confirm", 1);
    window.addButton("Cancel", 0);

    if (window.runModalLoop() != 0)
    {
        DBG("deeper hit");
        String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);

        updatePresetComboBox();
    }
#endif
    
}

void DCV3TopPanel::updatePresetComboBox()
{
    DCV3PresetManager* presetManager = mProcessor->getPresetManager();
    String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(dontSendNotification);
    
    const int numberOfPresets = presetManager->getNumberOfPresets();
    
    for (int i = 0; i < numberOfPresets; i++)
    {
        mPresetDisplay->addItem(presetManager->getPresetName(i), (i + 1));
    }
    mPresetDisplay->setText(presetManager->getCurrentPresetName());
}
