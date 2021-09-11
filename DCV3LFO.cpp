#include "DCV3LFO.h"
#include "JuceHeader.h"

DCV3LFO::DCV3LFO()
{
    reset();
}

DCV3LFO::~DCV3LFO()
{
    
}

void DCV3LFO::reset()
{
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float) * maxBufferSize);
}

void DCV3LFO::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void DCV3LFO::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for (int i = 0; i < inNumSamples; i++)
    {
        mPhase += (rate / mSampleRate);
        
        if (mPhase > 1)
        {
            mPhase -= 1.0f;
        }
        
        const float LFOPosition = sinf(mPhase * TWO_PI) * inDepth;
        
        mBuffer[i] = LFOPosition;
    }
}

float* DCV3LFO::getBuffer()
{
    return mBuffer;
}
