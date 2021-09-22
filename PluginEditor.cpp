#include "PluginProcessor.h"
#include "PluginEditor.h"

DelayChorusv3AudioProcessorEditor::DelayChorusv3AudioProcessorEditor (DelayChorusv3AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mMainPanel = std::make_unique<DCV3MainPanel>(&audioProcessor);
    addAndMakeVisible(mMainPanel.get());
    
    mLookAndFeel = std::make_unique<DCV3LookAndFeel>();
    setLookAndFeel(mLookAndFeel.get());
    juce::LookAndFeel::setDefaultLookAndFeel(mLookAndFeel.get());

}

DelayChorusv3AudioProcessorEditor::~DelayChorusv3AudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

void DelayChorusv3AudioProcessorEditor::paint (juce::Graphics& g)
{

}

void DelayChorusv3AudioProcessorEditor::resized()
{

}
