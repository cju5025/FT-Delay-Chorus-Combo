#include "DCV3Gain.h"
#include "JuceHeader.h"

DCV3Gain::DCV3Gain()
:   mGainSmoothed(0.0f)
{
    
}

DCV3Gain::~DCV3Gain()
{
    
}

void DCV3Gain::process(float* inAudio,
                       float inGain,
                       float* outAudio,
                       int inNumSamplesToRender)
{
    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
        
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        mGainSmoothed -= 0.0004 * (mGainSmoothed - gainMapped);
        outAudio[i] = inAudio[i] * mGainSmoothed;
    };
}