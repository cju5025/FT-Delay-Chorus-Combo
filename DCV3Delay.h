#pragma once
#include "DCV3AudioHelpers.h"

enum DCV3Type
{
    kDCV3Type_Delay = 0,
    kDCV3Type_Chorus
};

class DCV3Delay
{
public:
    DCV3Delay();
    ~DCV3Delay();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModulationBuffer,
                 float* outAudio,
                 int inNumSamplesToRender);
    
private:
    
    double getInterpolatedSample(float inDelayTimeInSamples);
    
    double mSampleRate;
    double mBuffer[maxBufferSize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    
    int mDelayIndex;
};
