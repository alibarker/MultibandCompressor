/*
  ==============================================================================

    LinkwitzRiley4thOrder.h
    Created: 8 Mar 2016 10:40:20am
    Author:  Alistair Barker

  ==============================================================================
*/

#ifndef LINKWITZRILEY4THORDER_H_INCLUDED
#define LINKWITZRILEY4THORDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#define FILTER_ORDER 4

enum {
    filterTypeLowPass = 0,
    filterTypeHighPass
};

class LinkwitzRiley4thOrder {
public:
    LinkwitzRiley4thOrder() {}
    ~LinkwitzRiley4thOrder() {}
    
    void setCoefficients(int filterType, float cutoff, float sampleRate);
    void processSamples(float* samples, int numSamples);
    void reset();
    
private:
    //coefficients
    float a[FILTER_ORDER+1];
    float b[FILTER_ORDER+1];
    
    // last sample buffers
    float x[FILTER_ORDER];
    float y[FILTER_ORDER];
    int writePointer;
        
};


#endif  // LINKWITZRILEY4THORDER_H_INCLUDED
