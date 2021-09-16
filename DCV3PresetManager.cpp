#include "DCV3PresetManager.h"

DCV3PresetManager::DCV3PresetManager(AudioProcessor* inProcessor)
:   mProcessor(inProcessor),
    mCurrentPresetName("Untitled")
{
    
}

DCV3PresetManager::~DCV3PresetManager()
{
    
}

void DCV3PresetManager::getXmlForPreset(XmlElement* inElement)
{
    XmlElement* presetName = new XmlElement("preset_name");
    presetName->setAttribute("name", mCurrentPresetName);
    inElement->addChildElement(presetName);
    
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < parameters.size(); i++)
    {
        AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        inElement->setAttribute(parameter->paramID, parameter->getValue());
    }
    
}

void DCV3PresetManager::loadPresetForXml(XmlElement* inElement)
{
    
}
