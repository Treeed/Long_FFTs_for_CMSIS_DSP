#ifndef _ARM_EXTRA_TABLES_H
#define _ARM_EXTRA_TABLES_H

#include "arm_math_types.h"

#ifdef   __cplusplus
extern "C"
{
#endif

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_FFT_ALLOW_TABLES)
  /* Double Precision Float CFFT twiddles */
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREV_4096)
    extern const uint16_t armBitRevTableExtra[4096];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_16)
    extern const float32_t twiddleCoefExtra_16[32];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_16)
    #define ARMBITREVINDEXTABLE_16_TABLE_LENGTH_EXTRA ((uint16_t)20)
    extern const uint32_t armBitRevIndexTableExtra16[ARMBITREVINDEXTABLE_16_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_32)
    extern const float32_t twiddleCoefExtra_32[64];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_32)
    #define ARMBITREVINDEXTABLE_32_TABLE_LENGTH_EXTRA ((uint16_t)48)
    extern const uint32_t armBitRevIndexTableExtra32[ARMBITREVINDEXTABLE_32_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_64)
    extern const float32_t twiddleCoefExtra_64[128];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_64)
    #define ARMBITREVINDEXTABLE_64_TABLE_LENGTH_EXTRA ((uint16_t)56)
    extern const uint32_t armBitRevIndexTableExtra64[ARMBITREVINDEXTABLE_64_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_128)
    extern const float32_t twiddleCoefExtra_128[256];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_128)
    #define ARMBITREVINDEXTABLE_128_TABLE_LENGTH_EXTRA ((uint16_t)208)
    extern const uint32_t armBitRevIndexTableExtra128[ARMBITREVINDEXTABLE_128_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_256)
    extern const float32_t twiddleCoefExtra_256[512];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_256)
    #define ARMBITREVINDEXTABLE_256_TABLE_LENGTH_EXTRA ((uint16_t)440)
    extern const uint32_t armBitRevIndexTableExtra256[ARMBITREVINDEXTABLE_256_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_512)
    extern const float32_t twiddleCoefExtra_512[1024];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_512)
    #define ARMBITREVINDEXTABLE_512_TABLE_LENGTH_EXTRA ((uint16_t)448)
    extern const uint32_t armBitRevIndexTableExtra512[ARMBITREVINDEXTABLE_512_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_1024)
    extern const float32_t twiddleCoefExtra_1024[2048];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_1024)
    #define ARMBITREVINDEXTABLE_1024_TABLE_LENGTH_EXTRA ((uint16_t)1800)
    extern const uint32_t armBitRevIndexTableExtra1024[ARMBITREVINDEXTABLE_1024_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_2048)
    extern const float32_t twiddleCoefExtra_2048[4096];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_2048)
    #define ARMBITREVINDEXTABLE_2048_TABLE_LENGTH_EXTRA ((uint16_t)3808)
    extern const uint32_t armBitRevIndexTableExtra2048[ARMBITREVINDEXTABLE_2048_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_4096)
    extern const float32_t twiddleCoefExtra_4096[8192];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_4096)
    #define ARMBITREVINDEXTABLE_4096_TABLE_LENGTH_EXTRA ((uint16_t)4032)
    extern const uint32_t armBitRevIndexTableExtra4096[ARMBITREVINDEXTABLE_4096_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_8192)
    extern const float32_t twiddleCoefExtra_8192[16384];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_8192)
    #define ARMBITREVINDEXTABLE_8192_TABLE_LENGTH_EXTRA ((uint16_t)14576)
    extern const uint32_t armBitRevIndexTableExtra8192[ARMBITREVINDEXTABLE_8192_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_16384)
    extern const float32_t twiddleCoefExtra_16384[32768];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_16384)
    #define ARMBITREVINDEXTABLE_16384_TABLE_LENGTH_EXTRA ((uint16_t)31080)
    extern const uint32_t armBitRevIndexTableExtra16384[ARMBITREVINDEXTABLE_16384_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_32)
            extern const float32_t twiddleCoefExtra_rfft_32[32];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_64)
            extern const float32_t twiddleCoefExtra_rfft_64[64];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_128)
            extern const float32_t twiddleCoefExtra_rfft_128[128];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_256)
            extern const float32_t twiddleCoefExtra_rfft_256[256];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_512)
            extern const float32_t twiddleCoefExtra_rfft_512[512];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_1024)
            extern const float32_t twiddleCoefExtra_rfft_1024[1024];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_2048)
            extern const float32_t twiddleCoefExtra_rfft_2048[2048];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_4096)
            extern const float32_t twiddleCoefExtra_rfft_4096[4096];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_8192)
            extern const float32_t twiddleCoefExtra_rfft_8192[8192];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

          #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_16384)
            extern const float32_t twiddleCoefExtra_rfft_16384[16384];
          #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

        
  #define twiddleCoefExtra twiddleCoef_16384

#endif /* if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_FAST_TABLES) */
#ifdef   __cplusplus
}
#endif

#endif /*  ARM_EXTRA_TABLES_H */