#include "DCV3ParameterSlider.h"

DCV3ParameterSlider::DCV3ParameterSlider(AudioProcessorValueTreeState& stateToControl,
                    const String& parameterID)
:   Slider(parameterID)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment =
    std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}

DCV3ParameterSlider::~DCV3ParameterSlider()
{
    
}

void DCV3ParameterSlider::paint(Graphics& g)
{
    g.setColour(Colours::ghostwhite);
    g.fillEllipse(10.0f, 0.0f, this->getWidth() - 20.0f, this->getHeight() - 20.0f);
    
    g.setColour (juce::Colours::orange);
    juce::Line<float> line (juce::Point<float> (10, 10),
                            juce::Point<float> (this->getHeight() / 2, 0));
    g.drawLine (line, 2.0f);
    
}
