/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_3A339D09AD8FC8FB__
#define __JUCE_HEADER_3A339D09AD8FC8FB__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Multiband_compressorAudioProcessorEditor  : public AudioProcessorEditor,
                                                  public Timer,
                                                  public SliderListener
{
public:
    //==============================================================================
    Multiband_compressorAudioProcessorEditor (Multiband_compressorAudioProcessor* ownerFilter);
    ~Multiband_compressorAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Multiband_compressorAudioProcessor* getProcessor() const
    {
        return static_cast <Multiband_compressorAudioProcessor*> (getAudioProcessor());
    }
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> sliderLowThreshold;
    ScopedPointer<Slider> sliderLowRatio;
    ScopedPointer<Slider> sliderLowAttack;
    ScopedPointer<Slider> sliderLowRelease;
    ScopedPointer<Slider> sliderLowGain;
    ScopedPointer<Slider> sliderMidThreshold;
    ScopedPointer<Slider> sliderMidRatio;
    ScopedPointer<Slider> sliderMidAttack;
    ScopedPointer<Slider> sliderMidRelease;
    ScopedPointer<Slider> sliderMidGain;
    ScopedPointer<Slider> sliderHighThreshold;
    ScopedPointer<Slider> sliderHighRatio;
    ScopedPointer<Slider> sliderHighAttack;
    ScopedPointer<Slider> sliderHighRelease;
    ScopedPointer<Slider> sliderHighGain;
    ScopedPointer<Label> ratioLabel;
    ScopedPointer<Label> attackLabel;
    ScopedPointer<Label> releaseLabel;
    ScopedPointer<Label> gainLabel;
    ScopedPointer<Label> lowLabel;
    ScopedPointer<Label> midLabel;
    ScopedPointer<Label> highLabel;
    ScopedPointer<Slider> sliderKneeWidth;
    ScopedPointer<Slider> sliderOverallGain;
    ScopedPointer<Label> kneeWidthLabel;
    ScopedPointer<Label> overallGainLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Multiband_compressorAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3A339D09AD8FC8FB__
