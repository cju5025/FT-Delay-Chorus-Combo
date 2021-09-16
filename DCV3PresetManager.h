#pragma once
#include "JuceHeader.h"

#define PRESET_FILE_EXTENSION ".ftp"

class DCV3PresetManager
{
    
public:
    
    DCV3PresetManager(AudioProcessor* inProcessor);
    ~DCV3PresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    void loadPresetForXml(XmlElement* inElement);
    void createNewPreset();
    void savePreset();
    void saveAsPreset(String inPresetName = "Preset");
    void loadPreset(int inPresetIndex);
    
    int getNumberOfPresets();
    
    String getPresetName(int inPresetIndex);
    String getCurrentPresetName();
    
    bool isCurrentPresetSaved();
    
    
    
    
private:
    
    AudioProcessor* mProcessor;
    
    void storeLocalPresets();
    
    bool mCurrentPresetIsSaved;
    
    File mCurrentlyLoadedPreset;
    Array<File> mLocalPresets;
    
    XmlElement* mCurrentPresetXml;
    
    String mCurrentPresetName;
    String mPresetDirectory;
};
