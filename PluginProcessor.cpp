#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "DCV3Parameters.h"

AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for (int i = 0; i < kDCV3Parameter_TotalNumParameters; i++)
    {
        params.push_back(std::make_unique<AudioParameterFloat>(DCV3ParameterID[i],
                                                               DCV3ParameterLabel[i],
                                                               NormalisableRange<float> (0.0f, 1.0f, 0.001f),
                                                               DCV3ParameterDefaultValue[i]));
    }
    return { params.begin(), params.end() };
}

DelayChorusv3AudioProcessor::DelayChorusv3AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
                    parameters(*this,
                               nullptr,
                               Identifier("DCV3"),
                               createParameterLayout())

#endif
{
    initializeDSP();
}

DelayChorusv3AudioProcessor::~DelayChorusv3AudioProcessor()
{
}

//==============================================================================
const juce::String DelayChorusv3AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DelayChorusv3AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DelayChorusv3AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DelayChorusv3AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DelayChorusv3AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DelayChorusv3AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DelayChorusv3AudioProcessor::getCurrentProgram()
{
    return 0;
}

void DelayChorusv3AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DelayChorusv3AudioProcessor::getProgramName (int index)
{
    return {};
}

void DelayChorusv3AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DelayChorusv3AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (int i = 0; i < getTotalNumInputChannels(); i++)
    {
        mDelay[i]->setSampleRate(sampleRate);
        mLFO[i]->setSampleRate(sampleRate);
    }
}

void DelayChorusv3AudioProcessor::releaseResources()
{
    for (int i = 0; i < getTotalNumInputChannels(); i++)
    {
        mDelay[i]->reset();
        mLFO[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DelayChorusv3AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DelayChorusv3AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        mInputGain[channel]->process(channelData,
                                     *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_InputGain]),
                                     channelData,
                                     buffer.getNumSamples());
        
        float rate = 0;
        
        if (channel == 1)
        {
            rate = *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_ModulationRate]);
        }
        
        mLFO[channel]->process(rate,
                               *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_ModulationDepth]),
                               buffer.getNumSamples());
        
        mDelay[channel]->process(channelData,
                                 *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_DelayTime]),
                                 *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_DelayFeedback]),
                                 *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_DelayWetDry]),
                                 *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_DelayType]),
                                 mLFO[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
        
        mOutputGain[channel]->process(channelData,
                                      *parameters.getRawParameterValue(DCV3ParameterID[kDCV3Parameter_OutputGain]),
                                      channelData,
                                      buffer.getNumSamples());

    }
}

//==============================================================================
bool DelayChorusv3AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DelayChorusv3AudioProcessor::createEditor()
{
    return new DelayChorusv3AudioProcessorEditor (*this);
}

//==============================================================================
void DelayChorusv3AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DelayChorusv3AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void DelayChorusv3AudioProcessor::initializeDSP()
{
    for (int i = 0; i < getTotalNumInputChannels(); i++)
    {
        mDelay[i] = std::make_unique<DCV3Delay>();
        mLFO[i] = std::make_unique<DCV3LFO>();
        mInputGain[i] = std::make_unique<DCV3Gain>();
        mOutputGain[i] = std::make_unique<DCV3Gain>();
    }
}


juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DelayChorusv3AudioProcessor();
}
