/*
 ==============================================================================
 
 This file was auto-generated by the Introjucer!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "LinkwitzRiley4thOrder.h"




//==============================================================================
Multiband_compressorAudioProcessor::Multiband_compressorAudioProcessor()
{
    // Set default values:
    pLowGain = pMidGain = pHighGain = 1.0;
    pLowThreshold = pMidThreshold = pHighThreshold = 0.0;
    pLowRatio = pMidRatio = pHighRatio = 1;
    pLowAttack = pMidAttack = pHighAttack = 5;
    pLowRelease = pMidRelease = pHighRelease = 5;
    pLowONOFF = pMidONOFF = pHighONOFF = 1;
    
    pOverallGain = 1.0;
    pKneeWidth = 0.0;
    
    pLowPassCutoff = 500;
    pHighPassCutoff = 2000;
    
    // instantiate compresors
    lowComp = new Compressor;
    midComp = new Compressor;
    highComp = new Compressor;
    
}

Multiband_compressorAudioProcessor::~Multiband_compressorAudioProcessor()
{
}

//==============================================================================
const String Multiband_compressorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Multiband_compressorAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool Multiband_compressorAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool Multiband_compressorAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double Multiband_compressorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Multiband_compressorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int Multiband_compressorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Multiband_compressorAudioProcessor::setCurrentProgram (int index)
{
}

const String Multiband_compressorAudioProcessor::getProgramName (int index)
{
    return String();
}

void Multiband_compressorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Multiband_compressorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    // Create as many filters as we have input channels
    numChannels = getTotalNumInputChannels();
    
    
    // for each channel add low and high filters, set coefficients and reset
    for (int i = 0; i < numChannels; i++) {
        lowpassFilters.add(new LinkwitzRiley4thOrder);
        lowpassFilters[i]->setCoefficients(filterTypeLowPass, pLowPassCutoff, sampleRate);
        lowpassFilters[i]->reset();
        
        bandpassAFilters.add(new LinkwitzRiley4thOrder);
        bandpassAFilters[i]->setCoefficients(filterTypeHighPass, pLowPassCutoff, sampleRate);
        bandpassAFilters[i]->reset();
        
        bandpassBFilters.add(new LinkwitzRiley4thOrder);
        bandpassBFilters[i]->setCoefficients(filterTypeLowPass, pHighPassCutoff, sampleRate);
        bandpassBFilters[i]->reset();
        
        highpassFilters.add(new LinkwitzRiley4thOrder);
        highpassFilters[i]->setCoefficients(filterTypeHighPass, pHighPassCutoff, sampleRate);
        highpassFilters[i]->reset();
    }
    
    // prepare compressors
    lowComp->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumInputChannels());
    midComp->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumInputChannels());
    highComp->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumInputChannels());
    
    lowComp->setParameters(pLowRatio, pLowThreshold, pLowAttack, pLowRelease, pLowGain, pKneeWidth);
    midComp->setParameters(pMidRatio, pMidThreshold, pMidAttack, pMidRelease, pMidGain, pKneeWidth);
    highComp->setParameters(pHighRatio, pHighThreshold, pHighAttack, pHighRelease, pHighGain, pKneeWidth);
    
    
}

void Multiband_compressorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void Multiband_compressorAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int numInputChannels = buffer.getNumChannels();
    const int numSamples = buffer.getNumSamples();
    
    // initialise buffers for each band
    AudioSampleBuffer lowOutput;
    AudioSampleBuffer midOutput;
    AudioSampleBuffer highOutput;
    
    // set each to the input
    lowOutput.makeCopyOf(buffer);
    midOutput.makeCopyOf(buffer);
    highOutput.makeCopyOf(buffer);
    
    float sampleRate = getSampleRate();
    
    for (int channel = 0; channel < numInputChannels; channel++) {
        
        // set parameters for filters

        lowpassFilters[channel]->setCoefficients(filterTypeLowPass, pLowPassCutoff, sampleRate);
        bandpassAFilters[channel]->setCoefficients(filterTypeHighPass, pLowPassCutoff, sampleRate);
        bandpassBFilters[channel]->setCoefficients(filterTypeLowPass, pHighPassCutoff, sampleRate);
        highpassFilters[channel]->setCoefficients(filterTypeHighPass, pHighPassCutoff, sampleRate);

        
        // apply filters
        lowpassFilters[channel]->processSamples(lowOutput.getWritePointer(channel), numSamples);
        
        bandpassAFilters[channel]->processSamples(midOutput.getWritePointer(channel), numSamples);
        bandpassBFilters[channel]->processSamples(midOutput.getWritePointer(channel), numSamples);
        
        highpassFilters[channel]->processSamples(highOutput.getWritePointer(channel), numSamples);
    }
    
    // set parameters for compressors
    lowComp->setParameters(pLowRatio, pLowThreshold, pLowAttack, pLowRelease, pLowGain, pKneeWidth);
    midComp->setParameters(pMidRatio, pMidThreshold, pMidAttack, pMidRelease, pMidGain, pKneeWidth);
    highComp->setParameters(pHighRatio, pHighThreshold, pHighAttack, pHighRelease, pHighGain, pKneeWidth);

    // compress each band
    if (pLowONOFF)  lowComp->processSamples(lowOutput);
    if (pMidONOFF)  midComp->processSamples(midOutput);
    if (pHighONOFF) highComp->processSamples(highOutput);
   
    
    // sum each band
    buffer.clear();
    for (int ch = 0; ch < numInputChannels; ch++) {
        buffer.addFrom(ch, 0, lowOutput, ch, 0, numSamples, 1.0/3.0);
        buffer.addFrom(ch, 0, midOutput, ch, 0, numSamples, 1.0/3.0);
        buffer.addFrom(ch, 0, highOutput, ch, 0, numSamples, 1.0/3.0);
    }
    
    // apply overall gain
    buffer.applyGain(pOverallGain);
    
}


//==============================================================================
bool Multiband_compressorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Multiband_compressorAudioProcessor::createEditor()
{
    return new Multiband_compressorAudioProcessorEditor (this);
}

//==============================================================================
void Multiband_compressorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Multiband_compressorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Multiband_compressorAudioProcessor();
}

//==============================================================================

