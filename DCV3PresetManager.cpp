#include "DCV3PresetManager.h"

DCV3PresetManager::DCV3PresetManager(AudioProcessor* inProcessor)
:   mProcessor(inProcessor),
    mCurrentPresetIsSaved(false),
    mCurrentPresetName("Untitled")
{
    const String pluginName = (String) mProcessor->getName();
    
    mPresetDirectory =
    (File::getSpecialLocation(File::userDocumentsDirectory)).getFullPathName()+"/Family Time/"+pluginName;
    
    if(!File(mPresetDirectory).exists())
    {
        File(mPresetDirectory).createDirectory();
    }
    
    storeLocalPresets();
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

void DCV3PresetManager::createNewPreset()
{
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < parameters.size(); i++)
    {
        AudioProcessorParameterWithID* parameter =
        (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        const float defaultValue = parameter->getDefaultValue();
        parameter->setValueNotifyingHost(defaultValue);
    }
    
    mCurrentPresetIsSaved = false;
    mCurrentPresetName = "Untitled";
}

void DCV3PresetManager::savePreset(){
    
}

void DCV3PresetManager::saveAsPreset(String inPresetName)
{
    
}

void DCV3PresetManager::loadPreset(int inPresetIndex)
{
    
}

int DCV3PresetManager::getNumberOfPresets()
{
    return mLocalPresets.size();
}

String DCV3PresetManager::getPresetName(int inPresetIndex)
{
    return mLocalPresets[inPresetIndex].getFileNameWithoutExtension();
}

String DCV3PresetManager::getCurrentPresetName()
{
    
}

bool DCV3PresetManager::isCurrentPresetSaved()
{
    
}

void DCV3PresetManager::storeLocalPresets()
{
    
}
