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
    XmlElement* presetName = new XmlElement("presetName");
    presetName->setAttribute("name", mCurrentPresetName);
    inElement->addChildElement(presetName);
    
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < parameters.size(); i++)
    {
        AudioProcessorParameterWithID* parameter =
        (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        inElement->setAttribute(parameter->paramID, parameter->getValue());
    }
    
}

void DCV3PresetManager::loadPresetForXml(XmlElement* inElement)
{
    mCurrentPresetXml = inElement;
    XmlElement* presetName = inElement->getChildByName("presetName");
    
    if (presetName == nullptr){ return; }
    
    mCurrentPresetName = presetName->getStringAttribute("name", "error");
    
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < mCurrentPresetXml->getNumAttributes(); i++)
    {
        const String paramID = mCurrentPresetXml->getAttributeName(i);
        const float value = mCurrentPresetXml->getDoubleAttribute(paramID);
        
        for (int j = 0; j < parameters.size(); j++)
        {
            AudioProcessorParameterWithID* parameter =
            (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
            
            if (paramID == parameter->paramID)
            {
                parameter->setValueNotifyingHost(value);
            }
        }
    }
    
}
