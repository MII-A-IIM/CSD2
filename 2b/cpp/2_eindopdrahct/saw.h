//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"
using namespace std;

class Saw : public Oscillator{
    public:
        Saw(float frequency, double samplerate);
        ~Saw();        
        float getSample();
        void calculate();
    private:
        float amplitude = 1.0;
        float phase = 0;
        float sample = 0;
};

#endif