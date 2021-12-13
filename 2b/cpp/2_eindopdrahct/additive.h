//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "synth.h"
using namespace std;

class Additive : public Synth{
    public:
        Additive(float midiNumber, double samplerate);
        ~Additive();
    protected:
        void typeSynthCalc();
        void getTypeSynthSample();
};