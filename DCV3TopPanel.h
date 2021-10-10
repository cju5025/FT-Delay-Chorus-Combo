#pragma once
#include "DCV3PanelBase.h"


class DCV3TopPanel
:   public DCV3PanelBase
{
public:
    
    DCV3TopPanel(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3TopPanel();
    
    void paint(Graphics& g) override;
    
private:
    
    void displaySaveAsPopup();
    void updatePresetComboBox();
    
    std::unique_ptr<ComboBox> mPresetDisplay;
    
    std::unique_ptr<TextButton> mNewPresetButton;
    std::unique_ptr<TextButton> mSavePresetButton;
    std::unique_ptr<TextButton> mSaveAsPresetButton;
    
};
