//
// Created by jona on 21.07.2023.
//

#ifndef BLINKITEMB1_EXTRA_FFTS_H
#define BLINKITEMB1_EXTRA_FFTS_H

#include "arm_math_types.h"



/**
 * @brief Instance structure for the floating-point CFFT/CIFFT function.
 */
typedef struct
{
    uint16_t fftLen;                   /**< length of the FFT. */
    const float32_t *pTwiddle;         /**< points to the Twiddle factor table. */
    const uint32_t *pBitRevTable;      /**< points to the bit reversal table. */
    uint16_t bitRevLength;             /**< bit reversal table length. */
#if defined(ARM_MATH_MVEF) && !defined(ARM_MATH_AUTOVECTORIZE)
    const uint32_t *rearranged_twiddle_tab_stride1_arr;        /**< Per stage reordered twiddle pointer (offset 1) */                                                       \
   const uint32_t *rearranged_twiddle_tab_stride2_arr;        /**< Per stage reordered twiddle pointer (offset 2) */                                                       \
   const uint32_t *rearranged_twiddle_tab_stride3_arr;        /**< Per stage reordered twiddle pointer (offset 3) */                                                       \
   const float32_t *rearranged_twiddle_stride1; /**< reordered twiddle offset 1 storage */                                                                   \
   const float32_t *rearranged_twiddle_stride2; /**< reordered twiddle offset 2 storage */                                                                   \
   const float32_t *rearranged_twiddle_stride3;
#endif
} arm_cfft_instance_f32_extra;

/**
 * @brief Instance structure for the floating-point RFFT/RIFFT function.
 */
typedef struct
{
    arm_cfft_instance_f32_extra Sint;      /**< Internal CFFT structure. */
    uint16_t fftLenRFFT;             /**< length of the real sequence */
    const float32_t * pTwiddleRFFT;        /**< Twiddle factors real stage  */
} arm_rfft_fast_instance_f32_extra ;


arm_status arm_rfft_fast_init_f32_extra (
        arm_rfft_fast_instance_f32_extra * S,
        uint16_t fftLen);

void arm_rfft_fast_f32_extra(
        const arm_rfft_fast_instance_f32_extra * S,
        float32_t * p, float32_t * pOut,
        uint8_t ifftFlag);


arm_status arm_cfft_init_f32_extra(
        arm_cfft_instance_f32_extra * S,
        uint16_t fftLen);


void arm_cfft_f32_extra(
        const arm_cfft_instance_f32_extra * S,
        float32_t * p1,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);



#endif //BLINKITEMB1_EXTRA_FFTS_H
