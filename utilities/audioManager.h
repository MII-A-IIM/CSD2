//All credits for AudioManger go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/xx_eindopdrachtExamples/07_choicesSynth

#pragma once
#include <iostream>
#include <thread>
#include "userInput.h"
#include "../../CSD2_pull/Marc/stereo_jack/jack_module_stereo.h"
#include "../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/utilities/writeToFile.h"
//we need the delay base class for its static function
#include "../2c/audio_effect/delay.h"
#include "../2c/audio_effect/modulation.h"
#include "../2c/audio_effect/modDelay.h"

class AudioManager
{
public:
  //The possible synthtypes are choosen from enum
  enum EffectType {
    TREMOLO = 0,
    SIMPLEDELAY,
    MODDELAY,
    CHORUS,
    SIZE,
    NONE
  };
  AudioManager(char **argv);
  ~AudioManager();
  static std::string effectEnumToString(EffectType type);
  std::string waveformEnumToString(Modulation::WaveformType waveform);
  std::string delayTimeEnumToString(Delay::BufferSizeType delayTime);
  Modulation::WaveformType waveformTypeSelection();
  Delay::BufferSizeType delayTimeSelection();
  float setModFreq();
  float setDelayTime(Delay::BufferSizeType delayTimeType);
  float setDelayFeedback();
  float setModDelayModDepth(Delay::BufferSizeType delayTimeType);
  float setChorusBufferSize();
  float setChorusLRRatio();
  void assignAudioCallback();
  void makeEffect(EffectType effect);
  void end();

protected:
  float amplitude = 0.5;
  unsigned long chunkSize = 2048;
  JackModuleStereo* jack;
  float* inbuf;
  float* outbuf;
  AudioEffect* audioEffectL;
  AudioEffect* audioEffectR;
  //var
  double samplerate;
  double masterAmp;
  int frameIndex;
  int frameInterval;

  EffectType effect;
};