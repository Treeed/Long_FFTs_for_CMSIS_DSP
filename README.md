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
- enable -Ofast (and -funroll-loops if you want) if you are concerned about speed. These options are needed to match the performance of the precompiled CMSIS library. In Eclipse (STM32CubeIDE) -Ofast is in "Project Settings -> C/C++Build -> Settings -> Tool Settings -> MCU GCC Compiler -> Optimization -> Optimization level" and -funroll-loops needs to be added under "MCU GCC Compiler -> Miscellaneous"

## Generation
- install python (tested with python version 3.10, probably works with anything >3.6)
- install sympy (tested with version 1.11.1, probably works with anything)
- set your desired powers of 2 to be generated in main.py
- run main.py

## Neon/Helium/Vector Extensions...
...are not supported\
You might notice that some of the device specific code for these is still included and generated. Most of it is, however, not adapted to the longer ffts and none of the technology specific tables are generated.  

## Performance
Some rough performance tests done using the Systick set to 10kHz and the following code:
```c
  unsigned long start = HAL_GetTick();
  arm_rfft_fast_f32_extra(&fft_tables_main, fft_buffer1, fft_buffer2, false);
  arm_cmplx_mag_f32(fft_buffer2, fft_buffer1, FFT_LEN);
  volatile unsigned long result = HAL_GetTick() - start;
```
I used GNU Tools for STM32 (10.3-2021.10) which contains some GCC 10.3 on an STM32F479NG running at 180MHz.\
I didn't test the very short FFTs as they run too fast to measure this way and I didn't test the very long FFTs since their twiddle tables didn't fit on flash together with the other FFTs.
### Options for the different scenarios:
#### Precompiled CMSIS
Just the library that STM32CubeIDE provides. 

#### Extra FFT Opt
-Ofast -funroll-loops
-mfpu=fpv4-sp-d16 -mfloat-abi=hard

#### Extra FFT No Opt
-O0
-mfpu=fpv4-sp-d16 -mfloat-abi=hard

#### Extra FFT No FPU
-Ofast -funroll-loops
-mfloat-abi=soft

| FFT Length | Precompiled CMSIS time (ms) | Extra FFT Opt time (ms) | Extra FFT No Opt time (ms) | Extra FFT No FPU time (ms) |
|------------|-----------------------------|-------------------------|----------------------------|----------------------------|
| 128        | 0.1                         | 0.1                     | 0.3                        | 0.6                        |
| 256        | 0.1                         | 0.1                     | 0.6                        | 1.2                        |
| 512        | 0.3                         | 0.3                     | 1.3                        | 2.6                        |
| 1024       | 0.6                         | 0.6                     | 2.5                        | 5.6                        |
| 2048       | 1.2                         | 1.2                     | 5.7                        | 12.2                       |
| 4096       | 2.6                         | 2.6                     | 12.0                       | 27.9                       |
| 8192       | -                           | 4.8                     | 23.5                       | 59.8                       |
| 16384      | -                           | 11.1                    | 52.9                       | 129.1                      | 



&nbsp;
&nbsp;
&nbsp;

Thanks to https://gist.github.com/rosek86 for the code to generate the bitreversal index tables: https://gist.github.com/rosek86/d0d709852fddf36193071d7f61987bae 

&nbsp;
&nbsp;
&nbsp;

This repository contains and generates code originally published as part of https://github.com/ARM-software/CMSIS-DSP. All respective licensing terms apply.
