#include "DCV3ParameterComboBox.h"

DCV3ParameterComboBox::DCV3ParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                      const String& parameterID)
:   ComboBox(parameterID)
{
    mAttachment =
    std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
}

DCV3ParameterComboBox::~DCV3ParameterComboBox()
{
    
}
