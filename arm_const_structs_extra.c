
#include "arm_math_types.h"
#include "arm_const_structs_extra.h"

/* Floating-point structs */
#if !defined(ARM_MATH_MVEF) || defined(ARM_MATH_AUTOVECTORIZE)


#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_16) && defined(ARM_TABLE_BITREVIDX_FLT_16))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len16_extra = {
  16, twiddleCoefExtra_16, armBitRevIndexTableExtra16, ARMBITREVINDEXTABLE_16_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_32) && defined(ARM_TABLE_BITREVIDX_FLT_32))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len32_extra = {
  32, twiddleCoefExtra_32, armBitRevIndexTableExtra32, ARMBITREVINDEXTABLE_32_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_64) && defined(ARM_TABLE_BITREVIDX_FLT_64))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len64_extra = {
  64, twiddleCoefExtra_64, armBitRevIndexTableExtra64, ARMBITREVINDEXTABLE_64_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_128) && defined(ARM_TABLE_BITREVIDX_FLT_128))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len128_extra = {
  128, twiddleCoefExtra_128, armBitRevIndexTableExtra128, ARMBITREVINDEXTABLE_128_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_256) && defined(ARM_TABLE_BITREVIDX_FLT_256))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len256_extra = {
  256, twiddleCoefExtra_256, armBitRevIndexTableExtra256, ARMBITREVINDEXTABLE_256_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_512) && defined(ARM_TABLE_BITREVIDX_FLT_512))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len512_extra = {
  512, twiddleCoefExtra_512, armBitRevIndexTableExtra512, ARMBITREVINDEXTABLE_512_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_1024) && defined(ARM_TABLE_BITREVIDX_FLT_1024))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len1024_extra = {
  1024, twiddleCoefExtra_1024, armBitRevIndexTableExtra1024, ARMBITREVINDEXTABLE_1024_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_2048) && defined(ARM_TABLE_BITREVIDX_FLT_2048))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len2048_extra = {
  2048, twiddleCoefExtra_2048, armBitRevIndexTableExtra2048, ARMBITREVINDEXTABLE_2048_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_4096) && defined(ARM_TABLE_BITREVIDX_FLT_4096))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len4096_extra = {
  4096, twiddleCoefExtra_4096, armBitRevIndexTableExtra4096, ARMBITREVINDEXTABLE_4096_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_8192) && defined(ARM_TABLE_BITREVIDX_FLT_8192))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len8192_extra = {
  8192, twiddleCoefExtra_8192, armBitRevIndexTableExtra8192, ARMBITREVINDEXTABLE_8192_TABLE_LENGTH_EXTRA
};
#endif



#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_16384) && defined(ARM_TABLE_BITREVIDX_FLT_16384))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len16384_extra = {
  16384, twiddleCoefExtra_16384, armBitRevIndexTableExtra16384, ARMBITREVINDEXTABLE_16384_TABLE_LENGTH_EXTRA
};
#endif


#endif /* !defined(ARM_MATH_MVEF) || defined(ARM_MATH_AUTOVECTORIZE) */
