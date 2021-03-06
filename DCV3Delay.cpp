#include "DCV3Delay.h"
#include "JuceHeader.h"

DCV3Delay::DCV3Delay()
:   mSampleRate(-1),
    mFeedbackSample(0.0f),
    mTimeSmoothed(0.0f),
    mDelayIndex(0)
{
    
}

DCV3Delay::~DCV3Delay()
{
    
}

void DCV3Delay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void DCV3Delay::reset()
{
    mTimeSmoothed = 0.0f;
    
    zeromem(mBuffer, (sizeof(double) * maxBufferSize));
}

void DCV3Delay::process(float* inAudio,
                        float inTime,
                        float inFeedback,
                        float inWetDry,
                        float inType,
                        float* inModulationBuffer,
                        float* outAudio,
                        int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.98f);
    
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        
        if ((int)inType == kDCV3Type_Delay)
        {
            mTimeSmoothed -= smoothingCoefficient_Fine * (mTimeSmoothed - inTime);

        } else {
            const double delayTimeModulation = (0.003 + (0.002f * inModulationBuffer[i]));
            mTimeSmoothed -= smoothingCoefficient_Fine * (mTimeSmoothed - delayTimeModulation);
        }
        
        
        const double delayTimeInSamples = (mTimeSmoothed * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        
        mFeedbackSample = sample;
        
        outAudio[i] = (inAudio[i] * dry + sample * wet);
        
        mDelayIndex++;
        
        if (mDelayIndex > maxBufferSize)
        {
            mDelayIndex -= maxBufferSize;
        }
    }
}

double DCV3Delay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if(readPosition < 0.0f)
    {
        readPosition += maxBufferSize;
    }
    
    int index_y0 = (int)readPosition - 1;
    if (index_y0 < 0)
    {
        index_y0 += maxBufferSize;
    }
    
    int index_y1 = readPosition;
    if (index_y1 > maxBufferSize)
    {
        index_y1 -= maxBufferSize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - (int)readPosition;
    
    double outSample = linearInterpolation(sample_y0, sample_y1, t);
    
    return outSample;
}

