#pragma once
#include "JuceHeader.h"

class DCV3ParameterSlider
:   public Slider
{
public:
    
    DCV3ParameterSlider(AudioProcessorValueTreeState& stateToControl,
                        const String& parameterID);
    
    ~DCV3ParameterSlider();
    
    void paint(Graphics& g);
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DCV3ParameterSlider);
};
