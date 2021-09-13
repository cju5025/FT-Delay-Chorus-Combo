#pragma once
#include "JuceHeader.h"

class DCV3PresetManager
{
    
public:
    
    DCV3PresetManager(AudioProcessor* inProcessor);
    ~DCV3PresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    void loadPresetForXml(XmlElement* inElement);
    
private:
    
    AudioProcessor* mProcessor;
    
};
