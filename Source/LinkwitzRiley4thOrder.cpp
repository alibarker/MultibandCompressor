/*
  ==============================================================================

    LinkwitzRiley4thOrder.cpp
    Created: 8 Mar 2016 10:40:20am
    Author:  Alistair Barker

  ==============================================================================
*/

#include "LinkwitzRiley4thOrder.h"

void LinkwitzRiley4thOrder::reset()
{
    for (int i; i < FILTER_ORDER; i++)
    {
        x[i] = 0.0;
        y[i] = 0.0;
    }
    
    writePointer = 0;
}

void LinkwitzRiley4thOrder::setCoefficients(int filterType, float cutoff, float sampleRate)
{
    
    float wc = 2 * M_PI * cutoff;
    float Q = sqrt(2) / 2;
    
    float wca = tanf(wc/(2*sampleRate));
    
    float a0 = pow(1 + wca/Q + pow(wca,2), 2); // denominator for all coefficeints for the linkwitz filters


    if(filterType == filterTypeLowPass) {
        
        b[0] = pow(wca, 4) / a0;
        b[1] = 4 * pow(wca, 4) / a0;
        b[2] = 2 * pow(wca, 4) + 4 * pow(wca, 4) / a0;
        b[3] = 4 * pow(wca, 4) / a0;
        b[4] = pow(wca, 4) / a0;
        
        a[1] = 2 * (1 + wca/Q + pow(wca,2))*( -2 + 2 * pow(wca,2)) / a0;
        a[2] =( 2 * (1 + wca/Q + pow(wca,2)) * (1 - wca/Q + pow(wca,2)) + pow(-2 + 2 * pow(wca,2), 2)) / a0;
        a[3] = 2 * (-2 + 2 * pow(wca,2)) * (1 - wca/Q + pow(wca,2)) / a0;
        a[4] = pow(1 - wca/Q + pow(wca,2), 2) / a0;
        
        
    } else if(filterType ==  filterTypeHighPass) {
        
        b[0] = 1 / a0;
        b[1] = -4 / a0;
        b[2] = 6 / a0;
        b[3] = -4 / a0;
        b[4] = 1 / a0;
        
    
        a[1] = 2 * (1 + wca/Q + pow(wca,2))*( -2 + 2 * pow(wca,2)) / a0;
        a[2] = (2 * (1 + wca/Q + pow(wca,2)) * (1 - wca/Q + pow(wca,2)) + pow(-2 + 2 * pow(wca,2), 2)) / a0;
        a[3] = 2 * (-2 + 2 * pow(wca,2)) * (1 - wca/Q + pow(wca,2)) / a0;
        a[4] = pow(1 - wca/Q + pow(wca,2), 2) / a0;
        
        
    }


    
//    
//    
//    rt_printf("Filter Coefficients:\n");
//    
//    for (int i = 0; i <= FILTER_ORDER; i++)
//    {
//        rt_printf("A(%d) = %f", i, coeffs.a[i]);
//        rt_printf("\t B(%d) = %f \n", i, coeffs.b[i]);
//        
//    }
//    
//    
    return;
    
}

void LinkwitzRiley4thOrder::processSamples(float *samples, int numSamples)
{
    
    for (int n = 0; n < numSamples; ++n) {
        
        float input = samples[n];
        float output = b[0] * input;
    
        for (int i = 1; i <= FILTER_ORDER; i++)
        {
            output += b[i] * x[ (writePointer - i + FILTER_ORDER) % FILTER_ORDER];
            output -= a[i] * y[ (writePointer - i + FILTER_ORDER) % FILTER_ORDER];
            
        }
        
        // write inputs and outputs to buffers
        x[writePointer] = input;
        y[writePointer] = output;
        
        // advance pointer and loop in pointer if necessary
        writePointer++;
        if (writePointer == FILTER_ORDER) {
            writePointer = 0;
        }
        
        samples[n] = output;

    }

}