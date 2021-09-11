#pragma once
#include "DCV3AudioHelpers.h"

class DCV3LFO
{
public:
    DCV3LFO();
    ~DCV3LFO();
    
    void reset();
    
    void setSampleRate(double inSampleRate);
    
    void process(float inRate, float inDepth, int inNumSamples);
    
    float* getBuffer();
    
private:
    
    double mSampleRate;
    
    float mPhase;
    
    float mBuffer[maxBufferSize];
};
