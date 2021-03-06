#pragma once
#include "JuceHeader.h"
#include "DCV3Dial.h"

class DCV3ParameterSlider
:   public Slider
{
public:
    
    DCV3ParameterSlider(AudioProcessorValueTreeState& stateToControl,
                        const String& parameterID);
    
    ~DCV3ParameterSlider();
        
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    DCV3Dial mDialLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DCV3ParameterSlider);
};
