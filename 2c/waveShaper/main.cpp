#include <iostream>
#include <thread>
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/utilities/jack_module.h"
#include "math.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/utilities/writeToFile.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/square.h"
#include "waveTable.h"

#define WRITE_TO_FILE 0
#define WRITE_NUM_SAMPLES 440

int main(int argc,char **argv)
{
 
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  unsigned int samplerate = jack.getSamplerate();
  float amplitude = 0.5;
  float freq = 440;
  Sine sine(freq, samplerate);
  Wavetable wavetableObj(samplerate, 8, freq);

  for(int i = 0; i < 200; i++){
    float sineSample = sine.genNextSample();
    // std::cout<< "sineSample: " << sineSample <<std::endl;
    wavetableObj.fillWavetable(sineSample);  }
  for(int i = 0; i < 200; i++){
    std::cout<< "wavetableObj [i]: " << wavetableObj.getWavetableAtIndex() <<std::endl;
  }


// #if WRITE_TO_FILE
//   WriteToFile fileWriter("output.csv", true);
//   // assign a function to the JackModule::onProces
//   jack.onProcess = [&amplitude, &sine, &wavetable, &fileWriter](jack_default_audio_sample_t* inBuf,
//     jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
// #else
//   // assign a function to the JackModule::onProces
//   jack.onProcess = [&amplitude, &sine, &wavetable](jack_default_audio_sample_t* inBuf,
//     jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
// #endif
//     for(unsigned int i = 0; i < nframes; i++) {
//       wavetable.fillWavetable(sine.genNextSample());
//       outBuf[i] = wavetable.getWavetableAtIndex();
//       // ----- write result to file -----
// #if WRITE_TO_FILE
//       static int count = 0;
//       if(count < WRITE_NUM_SAMPLES) {
//         fileWriter.write(std::to_string(outBuf[i]) + "\n");
//       } else {
//         // log 'Done' message to console, only once
//         static bool loggedDone = false;
//         if(!loggedDone) {
//           std::cout << "\n**** DONE **** \n"
//             << "Output is written to file.\n"
//             << "Please enter 'q' to quit the program." << std::endl;
//           loggedDone = true;
//         }
//       }
//       count++;
//       // set output to 0 to prevent issues with output
//       outBuf[i] = 0;
// #endif
//     }

//     return 0;
//   };

//   jack.autoConnect();

//   //keep the program running and listen for user input, q = quit
//   std::cout << "\n\nPress 'q' when you want to quit the program.\n";
//   // boolean is used to keep program running / turn it off
//   bool running = true;
//   while (running)
//   {
//     switch (std::cin.get())
//     {
//       case 'q':
//         running = false;
//         jack.end();
//         break;
//       }
//   }

//   //end the program
//   return 0;

} // main()
