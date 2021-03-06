#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "DCV3MainPanel.h"
#include "DCV3LookAndFeel.h"

class DelayChorusv3AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DelayChorusv3AudioProcessorEditor (DelayChorusv3AudioProcessor&);
    ~DelayChorusv3AudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    DelayChorusv3AudioProcessor& audioProcessor;
    
    std::unique_ptr<DCV3MainPanel> mMainPanel;
    std::unique_ptr<DCV3LookAndFeel> mLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayChorusv3AudioProcessorEditor)
};
