#include <iostream>
using namespace std;
#include "instrument.h"

Instrument::Instrument(string name, string soundDes, float note){
    this-> name = name;
    this-> soundDes = soundDes;
    this-> note = note;
}

Instrument::~Instrument(){
    
}

void Instrument::play(){
        cout<< name << " is playing \n" 
        << soundDes
        << note <<endl;

}