/*
 ==============================================================================
 
 This file was auto-generated by the Introjucer!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"




//==============================================================================
Multiband_compressorAudioProcessor::Multiband_compressorAudioProcessor()
{
    // Set default values:
    pLowGain = pMidGain = pHighGain = 1.0;
    pLowThreshold = pMidThreshold = pHighThreshold = 0.0;
    pLowRatio = pMidRatio = pHighRatio = 1;
    pLowAttack = pMidAttack = pHighAttack = 0.1;
    pLowRelease = pMidRelease = pHighRelease = 0.1;
    
    pOverallGain = 1.0;
    pKneeWidth = 0.0;
    
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
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // Create as many filters as we have input channels
    numChannels = getTotalNumInputChannels();
    
    IIRCoefficients low =IIRCoefficients::makeLowPass(sampleRate, loPassCutoff);
    IIRCoefficients high =IIRCoefficients::makeHighPass(sampleRate, hiPassCutoff);
    
    //    lpFilters = (IIRFilter**)malloc(numChannels * sizeof(IIRFilter*));
    //    hpFilters = (IIRFilter**)malloc(numChannels * sizeof(IIRFilter*));
    
    for (int i = 0; i < numChannels; i++) {
        lpFilters.add(new IIRFilter);
        lpFilters[i]->setCoefficients(low);
        hpFilters.add(new IIRFilter);
        hpFilters[i]->setCoefficients(high);
    }
    
    lowComp->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumInputChannels());
    midComp->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumInputChannels());
    highComp->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumInputChannels());

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
    
    float lowOutput[numInputChannels][numSamples];
    float midOutput[numInputChannels][numSamples];
    float highOutput[numInputChannels][numSamples];
    
    for (int channel = 0; channel < numInputChannels; channel++) {
        
        float* channelData = buffer.getWritePointer(channel);
        
        for (int n = 0; n < numSamples; n++)
        {
            float input = channelData[n];
            
            lowOutput[channel][n] = lpFilters[channel]->processSingleSampleRaw(input);
            highOutput[channel][n] = hpFilters[channel]->processSingleSampleRaw(input);
            midOutput[channel][n] = input - lowOutput[channel][n] - highOutput[channel][n];
            
        }
    }
    
    
    //            //float output = lowComp->processSample(lowOutput) + midComp->processSample(midOutput) + highComp->processSample(hiOutput);
    //            float output = lowOutput * pLowGain + midOutput * pMidGain + hiOutput * pHighGain;
    //
    //            channelData[n] = output;
    
    
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

