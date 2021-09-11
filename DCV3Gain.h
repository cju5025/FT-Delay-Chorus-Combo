#pragma once

class DCV3Gain
{
public:
    
    DCV3Gain();
    ~DCV3Gain();
    
    void process(float* inAudio,
                  float inGain,
                  float* outAudio,
                  int inNumSamplesToRender);
    
private:
    float mGainSmoothed;
};
