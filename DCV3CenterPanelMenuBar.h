#pragma once
#include "DCV3PanelBase.h"
#include "DCV3ParameterComboBox.h"

class DCV3CenterPanelMenuBar
:   public DCV3PanelBase
{
public:
    
    DCV3CenterPanelMenuBar(DelayChorusv3AudioProcessor* inProcessor);
    ~DCV3CenterPanelMenuBar();
    
    void addFXTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFXTypeComboBoxListener(ComboBox::Listener* inListener);
    
private:
    
    std::unique_ptr<DCV3ParameterComboBox> mFXTypeComboBox;
    
};
