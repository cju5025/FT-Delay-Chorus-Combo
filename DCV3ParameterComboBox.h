#pragma once
#include "JuceHeader.h"

class DCV3ParameterComboBox
:   public ComboBox
{
public:
    
    DCV3ParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                          const String& parameterID);
    ~DCV3ParameterComboBox();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DCV3ParameterComboBox);
};
