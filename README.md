## Delay / Chorus Combo Plugin
<p>This is the code for an audio effect plugin written in C++ with the JUCE framework. As a delay, incoming audio is stored in a circular buffer
and played back after a certain amount of time, which the user decides by changing the time parameter. As a chorus, the circular buffer stays implemented, 
but time is constantly changing based on the depth and rate of an LFO. Both modes have a feedback parameter.</p>
<br>

### Quick Overview
* The files from this repository can be added to the Source folder of a newly created JUCE plugin to create a delay/chorus combo plugin
with full functionality. You will of course need to namespace accordingly.

* GUI is broken down into modular sections labeled as panels. JUCE's Graphics class is used to customize the look of these panels.

* Panels are then included in the pluginEditor class to ensure they are called when the plugin GUI is constructed.

* Signal processing is also broken down into specific classes to be included into the main processor. This is nice because these classes
can be easily imported to other plugin projects.
    
* The pluginProcessor class is the heart of the plugin, with all of the DSP classes being included and constructed within.
