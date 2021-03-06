#pragma once
#include <iostream>
#include "circularBuffer.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/square.h"

class Wavetable{
  public:
    Wavetable();
    enum WaveformType {
      SINE = 0, // ensure enum starts at 0
      SAW,
      SQUARE,
      SIZE // 3
    };
    Wavetable(unsigned int samplerate, int size, 
      WaveformType waveformType, int freq);
    ~Wavetable();
    void selectWaveform(WaveformType waveformType);
    void oscToWavetable();
    float getSampWavetable();
  private:
    Oscillator* osc;
    CircBuf* circBuf;
    unsigned int samplerate;
    int size;
    float freq;
    unsigned int calcWavetableSamplerate(unsigned int samplerate, int freq);
    unsigned int wavetableSamplerate;
    int writeCount = 0;
    int samplerateWriteCount = 0;
    int readCount = 0;
    int samplerateReadCount = 0;
    float sample = 0;

};
