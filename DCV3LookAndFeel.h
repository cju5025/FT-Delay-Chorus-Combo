#pragma once

#include "JuceHeader.h"
#include "DCV3InterfaceDefines.h"

class DCV3LookAndFeel
:   public LookAndFeel_v4
{
public:
    
    DCV3LookAndFeel()
    {
        setColour(ComboBox::backgroundColourId, DCV3Colour_2);
        setColour(ComboBox::outlineColourId, DCV3Colour_1);
        setColour(ComboBox::arrowColourId, DCV3Colour_5);
        setColour(ComboBox::textColourId, DCV3Colour_5);
        
        setColour(TextButton::buttonColourId, DCV3Colour_5);
        setColour(TextButton::textColourOnId, DCV3Colour_5);
        setColour(TextButton::textColourOffId, DCV3Colour_5);
    }
    
    ~DCV3LookAndFeel();
    
    Font getTextButtonFont(TextButton&, int buttonHeight) override
    {
        return font_1;
    }
    
    void drawButtonBackground (Graphics& g,
                               Button& button,
                               const Colour& backgroungColour,
                               bool isMouseOverButton,
                               bool isButtonDown) override
    {
        Colour fillColour;
        
        if (isButtonDown)
        {
            fillColour = DCV3Colour_1;
        } else if (isMouseOverButton)
        {
            fillColour = DCV3Colour_3;
        } else
        {
            fillColour = DCV3Colour_2;
        }
        
        const float cornerSize = 6.0f;
        const Rectangle<float> bounds =
        button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);
                
        g.setColour (fillColour);
        g.fillRoundedRectangle (bounds.reduced(1), cornerSize);
    }
        
    
private:
    
};
