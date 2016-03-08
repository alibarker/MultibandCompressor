/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "LinkwitzRiley4thOrder.h"
#include "Compressor.h"


//==============================================================================
/**
*/
class Multiband_compressorAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Multiband_compressorAudioProcessor();
    ~Multiband_compressorAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    
    //==============================================================================
    enum Parameters
    {
        overallGain,
        kneeWidth,
        
        lowGain,
        lowThreshold,
        lowRatio,
        lowAttack,
        lowRelease,
        
        midGain,
        midThreshold,
        midRatio,
        midAttack,
        midRelease,
        
        highGain,
        highThreshold,
        highRatio,
        highAttack,
        highRelease,
        
        lowONOFF,
        midONOFF,
        highONOFF,
        
        kNumParameters
    };
    
    void setOverallGain(float value){ pOverallGain = Decibels::decibelsToGain(value); }
    void setKneeWidth(float value){ pKneeWidth = value; }

    void setLowGain(float value){ pLowGain = Decibels::decibelsToGain(value);; }
    void setLowThreshold(float value){ pLowThreshold = value; }
    void setLowRatio(float value){ pLowRatio = value; }
    void setLowAttack(float value){ pLowAttack = value; }
    void setLowRelease(float value){ pLowRelease = value; }
    
    void setMidGain(float value){ pMidGain = Decibels::decibelsToGain(value);; }
    void setMidThreshold(float value){ pMidThreshold = value; }
    void setMidRatio(float value){ pMidRatio = value; }
    void setMidAttack(float value){ pMidAttack = value; }
    void setMidRelease(float value){ pMidRelease = value; }
    
    void setHighGain(float value){ pHighGain = Decibels::decibelsToGain(value);; }
    void setHighThreshold(float value) { pHighThreshold = value; }
    void setHighRatio(float value) { pHighRatio = value; }
    void setHighAttack(float value){ pHighAttack = value; }
    void setHighRelease(float value) { pHighRelease = value; }
    
    void setLowONOFF(int value) {pLowONOFF = value;}
    void setMidONOFF(int value) {pMidONOFF = value;}
    void setHighONOFF(int value) {pHighONOFF = value;}
    
    //==============================================================================

    float getOverallGain() {return Decibels::gainToDecibels(pOverallGain);}
    float getKneeWidth() {return pKneeWidth;}
    
    float getLowGain(){return Decibels::gainToDecibels(pLowGain);}
    float getLowThreshold() {return pLowThreshold;}
    float getLowRatio() {return pLowRatio;}
    float getLowAttack() {return pLowAttack;}
    float getLowRelease() {return pLowRelease;}
    
    float getMidGain(){return Decibels::gainToDecibels(pMidGain);}
    float getMidThreshold() {return pMidThreshold;}
    float getMidRatio() {return pMidRatio;}
    float getMidAttack() {return pMidAttack;}
    float getMidRelease() {return pMidRelease;}
    
    float getHighGain(){ return Decibels::gainToDecibels(pHighGain);}
    float getHighThreshold() {return pHighThreshold;}
    float getHighRatio() {return pHighRatio;}
    float getHighAttack() {return pHighAttack;}
    float getHighRelease() {return pHighRelease;}
    
    int getLowONOFF(){ return pLowONOFF; }
    int getMidONOFF(){ return pMidONOFF; }
    int getHighONOFF(){ return pHighONOFF; }

    
private:
       
    OwnedArray<LinkwitzRiley4thOrder> lpFilters;
    OwnedArray<LinkwitzRiley4thOrder> hpFilters;
    
    ScopedPointer<Compressor> lowComp;
    ScopedPointer<Compressor> midComp;
    ScopedPointer<Compressor> highComp;


    int numChannels;
    
    float   pLowGain, pLowThreshold, pLowRatio, pLowAttack, pLowRelease,
            pMidGain, pMidThreshold, pMidRatio, pMidAttack, pMidRelease,
            pHighGain, pHighThreshold, pHighRatio, pHighAttack, pHighRelease,
            pOverallGain, pKneeWidth;
    int pLowONOFF, pMidONOFF, pHighONOFF;
    float loPassCutoff = 500;
    float hiPassCutoff = 2000;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Multiband_compressorAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
