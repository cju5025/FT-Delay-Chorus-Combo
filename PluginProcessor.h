#pragma once

#include "JuceHeader.h"
#include "DCV3Gain.h"
#include "DCV3Delay.h"
#include "DCV3LFO.h"
#include "DCV3PresetManager.h"


class DelayChorusv3AudioProcessor  : public juce::AudioProcessor
{
public:
    DelayChorusv3AudioProcessor();
    ~DelayChorusv3AudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    AudioProcessorValueTreeState parameters;

private:
    
    void initializeDSP();
    
    std::unique_ptr<DCV3Delay> mDelay[8];
    std::unique_ptr<DCV3LFO> mLFO[8];
    std::unique_ptr<DCV3Gain> mInputGain[8];
    std::unique_ptr<DCV3Gain> mOutputGain[8];
    
    std::unique_ptr<DCV3PresetManager> mPresetManager;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayChorusv3AudioProcessor)
};
