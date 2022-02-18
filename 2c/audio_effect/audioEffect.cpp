#include <iostream>
#include "audioEffect.h"

AudioEffect::AudioEffect(){

}

AudioEffect::AudioEffect(unsigned int samplerate, float dryWet, 
  bool bypass) : samplerate(samplerate), dryWet(dryWet),
  bypass(bypass){
  #if DEBUG > 0
    std::cout<< "contructor AudioEffect" <<std::endl;
  #endif

}

AudioEffect::~AudioEffect(){
  std::cout<< "~destructor AudioEffect" <<std::endl;
}

unsigned int AudioEffect::getSamplerate(){
  return samplerate;
}
