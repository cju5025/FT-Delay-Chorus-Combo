#pragma once

#include "JuceHeader.h"
#include "DCV3InterfaceDefines.h"

class DCV3LookAndFeel
:   public LookAndFeel_V4
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
    
    virtual ~DCV3LookAndFeel() {};
    
//===================    buttons
    
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
        const juce::Rectangle<float> bounds =
        button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);
                
        g.setColour (fillColour);
        g.fillRoundedRectangle (bounds.reduced(1), cornerSize);
    }
    
    //===================    combo box
    
    Font getLabelFont(Label& label) override
    {
        return font_1;
    }
    
    void drawPopupMenuBackground(juce::Graphics &g, int width, int height) override
        {
            g.setColour(DCV3Colour_3);
            g.fillRect(0,0,width,height);
        }
        
        void drawPopupMenuItem (Graphics& g, const juce::Rectangle<int>& area,
                                const bool isSeparator, const bool isActive,
                                const bool isHighlighted, const bool isTicked,
                                const bool hasSubMenu, const String& text,
                                const String& shortcutKeyText,
                                const Drawable* icon, const Colour* const textColourToUse) override
    {
        juce::Rectangle<int> r (area);
        
        Colour fillColour = isHighlighted ? DCV3Colour_1 : DCV3Colour_3;
        g.setColour(fillColour);
        g.fillRect(r.getX(), r.getY(), r.getWidth(), r.getHeight() -1);
        
        Colour textColour = isTicked ? DCV3Colour_6 : DCV3Colour_5;
        g.setColour(textColour);
        g.setFont(font_1);
        
        r.setLeft(10);
        r.setY(1);
        g.drawFittedText(text, r, Justification::left, 1);
        
    }
    
    void drawComboBox (Graphics& g, int width, int height, bool,
                           int, int, int, int, ComboBox& box) override
    {
        const float cornerSize = 3.0f;
        const juce::Rectangle<int> boxBounds (0, 0, width, height);
        
        g.setColour(DCV3Colour_2);
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);
        
        juce::Rectangle<int> arrowZone (width - 30, 0, 20, height);
        
        Path path;
        
        path.startNewSubPath(arrowZone.getX() + 3.0f, arrowZone.getCentreY() - 2.0f);
        path.lineTo(static_cast<float> (arrowZone.getCentreX()), arrowZone.toFloat().getCentreY() + 3.0f);
        path.lineTo(arrowZone.getRight() - 3.0f, arrowZone.getCentreY() - 2.0f);
        
        g.setColour (box.findColour(ComboBox::arrowColourId).withAlpha(box.isEnabled() ? 0.9f : 0.2f));
        g.strokePath(path, PathStrokeType(2.0f));
    }
    
private:
    
};
