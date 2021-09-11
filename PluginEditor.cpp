#include "PluginProcessor.h"
#include "PluginEditor.h"

DelayChorusv3AudioProcessorEditor::DelayChorusv3AudioProcessorEditor (DelayChorusv3AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mMainPanel = std::make_unique<DCV3MainPanel>(&audioProcessor);
    addAndMakeVisible(mMainPanel.get());
}

DelayChorusv3AudioProcessorEditor::~DelayChorusv3AudioProcessorEditor()
{
    
}

void DelayChorusv3AudioProcessorEditor::paint (juce::Graphics& g)
{
       g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
       g.setColour (juce::Colours::white);
       g.setFont (15.0f);
       g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DelayChorusv3AudioProcessorEditor::resized()
{

}
