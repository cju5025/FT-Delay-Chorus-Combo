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
    const float width = this->getWidth();
    const float height = this->getHeight();
    
    float diameter = jmin(width, height);
    float radius = diameter / 2;
    float centreX = width / 2;
    float centreY = height / 2;
    float rx = centreX - radius;
    float ry = centreY - radius;
    
    g.setColour(Colours::ghostwhite);
    g.fillEllipse(10.0f, 0.0f, width - 20.0f, height - 20.0f);
    
    
    g.setColour(Colours::black);
    Path dialTick;
    dialTick.addRectangle(0, 0, 7.5f, radius);
    
    g.fillPath(dialTick);
    
    
};
