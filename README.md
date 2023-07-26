# Long_FFTs_for_CMSIS_DSP
This repository provides python scripts to generate all necessary tables and C Code to calculate up to 32768 point float32_t ffts with ARM CMSIS. Both real and complex ffts are supported.

This extension is semi standalone, in that it doesn't depend on any of the original CMSIS FFT functionality, but duplicates everything needed. The only #include from the original CMSIS DSP is "arm_math_types.h". I assume, however, that if someone needs an fft, they also need a function to calculate the magnitude afterwards and will therefore use the original CMSIS Code anyway. Therefore I haven't actually checked if it really works on its own. 

The reason to duplicate so much original code is that the armBitRevIndexTables need to switch to uint32_t for lengths above 8192. Therefore, all functions passing these tables on to the next function need changing too which cascades into quite a few files. Currently, this extension uses uint32_t armBitRevIndexTables for all FFT lengths. If you are concerned about program size, you might need to place a couple of ifs to pick the right data type depending on FFT length. 

## Usage
- include https://github.com/ARM-software/CMSIS-DSP in your project
- put all files from generatedFiles and nonGeneratedFiles into one folder (or organize them to your liking) and add it as Include and Source Directory
- add `#include "extra_ffts.h"` to your code
- replace any calls to CMSIS DSP FFT functions or structures in your code by calls with _extra in the end (see extra_ffts.h for available options)
- use any fft size in the range you generated for (16 - 16384 cfft and 32 - 16384 rfft if you used the pregenerated files)

## Generation
- install python (tested with python version 3.10, probably works with anything >3.6)
- install sympy (tested with version 1.11.1, probably works with anything)
- set your desired powers of 2 to be generated in main.py
- run main.py

## Neon/Helium/Vector Extensions...
...are not supported\
You might notice that some of the device specific code for these is still included and generated. Most of it is, however, not adapted to the longer ffts and none of the technology specific tables are generated.  



This repository contains and generates code originally published as part of https://github.com/ARM-software/CMSIS-DSP. All respective licensing terms apply.
