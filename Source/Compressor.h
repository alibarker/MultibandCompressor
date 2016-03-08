/*
  ==============================================================================

    Compressor.h
    Created: 8 Mar 2016 11:55:52am
    Author:  Alistair Barker

  ==============================================================================
*/

#ifndef COMPRESSOR_H_INCLUDED
#define COMPRESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"



class Compressor
{
public:
    Compressor(){}
    ~Compressor(){}
    
    void prepareToPlay (double sr, int samplesPerBlock, int numInputChannels);
    void processSamples(AudioSampleBuffer &buffer);
    void setParameters(float ra, float t, float a, float re, float m, float kw);
    
private:
    
    float ratio;
    float threshold;
    float tauAttack;
    float tauRelease;
    float makeUpGain;
    float kneeWidth;
    
    float yL_prev;
    
    int compressorONOFF = 1;
    AudioSampleBuffer inputBuffer;
    int M;
    
    float samplerate;
    
    float alphaAttack, alphaRelease;
    
    float x_g, y_g, x_l, y_l, c;
};



#endif  // COMPRESSOR_H_INCLUDED
