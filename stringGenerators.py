import bitrevIdxs
import valueGenerators as gens


tables_header_start = f"""#ifndef _ARM_EXTRA_TABLES_H
#define _ARM_EXTRA_TABLES_H

#include "arm_math_types.h"

#ifdef   __cplusplus
extern "C"
{{
#endif
"""
tables_file_start = '#include "arm_math_types.h"\n\n#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_FFT_ALLOW_TABLES)\n'


def bitrev_table(stop_power):
    bitrev = gens.bit_reversers(stop_power)
    length_bitrev = len(bitrev)
    header_string = f"""
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_FFT_ALLOW_TABLES)
  /* Double Precision Float CFFT twiddles */
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREV_{length_bitrev})
    extern const uint16_t armBitRevTableExtra[{length_bitrev}];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
"""
    table_string = f'#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREV_{length_bitrev})\nconst uint16_t armBitRevTableExtra[{length_bitrev}] = {{\n    '
    table_string += (",\n    ".join(
                                [', '.join(
                                       f'0x{val:04x}' for val in bitrev[idx:idx+10]
                                      )
                                 for idx in range(0, length_bitrev, 10)]
                                ))
    table_string += ("};\n#endif\n\n")

    return header_string, table_string


def bitrevidx_table(lengths):
    table_string = ""
    header_string = ""
    for power, length in lengths:
        tps = bitrevIdxs.create_transpositions(length, 8)
        out = bitrevIdxs.transpositions_stringify(length, 8, tps)
        if len(tps)*2 > 2**16-1:
            print(f"warning: bitrevidx table for {length} is too long ({len(tps)*2}). Use a smaller value or figure out where to switch uint16_t to uint32_t")

        table_string += f"#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_{length})\n"
        table_string += out
        table_string += "\n#endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */\n\n\n"


        header_string += f"""  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_BITREVIDX_FLT_{length})
    #define ARMBITREVINDEXTABLE_{length}_TABLE_LENGTH_EXTRA ((uint16_t){len(tps)*2})
    extern const uint32_t armBitRevIndexTableExtra{length}[ARMBITREVINDEXTABLE_{length}_TABLE_LENGTH_EXTRA];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
"""
    return header_string, table_string


def twiddle_complex_table(lengths):
    table_string = ""
    header_string = ""
    for power, length in lengths:

        twiddles = gens.twiddle_coefs_complex(length)

        table_string += f"#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_{length*2})\n"
        table_string += f'const float32_t twiddleCoefExtra_{length}[{length*2}] = {{\n'
        table_string += "".join(f'    {val.real:.9f}f, {val.imag:.9f}f,\n' for val in twiddles)
        table_string += '};\n'
        table_string += "#endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */\n\n"


        header_string += f"""  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_F32_{length})
    extern const float32_t twiddleCoefExtra_{length}[{length*2}];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */
  
"""
    return header_string, table_string


def twiddle_real_table(lengths):
    table_string = ""
    header_string = ""
    for power, length in lengths:
        twiddles = gens.twiddle_coefs_real(length)

        table_string += f"#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_{length})\n"
        table_string += f'const float32_t twiddleCoefExtra_rfft_{length}[{length}] = {{\n'
        table_string += "".join(f'    {val.real:.9f}f, {val.imag:.9f}f,\n' for val in twiddles)
        table_string += '};\n'
        table_string += "#endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */\n\n"

        header_string += f"""  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_{length})
    extern const float32_t twiddleCoefExtra_rfft_{length}[{length}];
  #endif /* !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) */

"""
    return header_string, table_string


tables_header_end = """
#endif /* if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_FAST_TABLES) */
#ifdef   __cplusplus
}
#endif

#endif /*  ARM_EXTRA_TABLES_H */"""
tables_file_end = "\n#endif\n"


def rfft_init(lengths):
    init_string = """
/* ----------------------------------------------------------------------
 * Project:      CMSIS DSP Library
 * Title:        arm_rfft_fast_init_f32_extra.c
 * Description:  Split Radix Decimation in Frequency CFFT Floating point processing function
 *
 * $Date:        23 April 2021
 * $Revision:    V1.9.0
 *
 * Target Processor: Cortex-M and Cortex-A cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2021 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "extra_ffts.h"
#include "arm_common_tables_extra.h"

/**
  @ingroup groupTransforms
 */

/**
  @addtogroup RealFFT
  @{
 */
"""
    # we can't do a rfft for the lowest power, since a rfft always includes a cfft of length/2
    for power, length in lengths:
        init_string += f"""
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_{length//2}) && (defined(ARM_TABLE_BITREVIDX_FLT_{length//2}) || defined(ARM_TABLE_BITREVIDX_FXT_{length//2})) && defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_{length}))

/**
  @private
  @brief         Initialization function for the {length}pt floating-point real FFT.
  @param[in,out] S  points to an arm_rfft_fast_instance_f32_extra structure
  @return        execution status
                   - \\ref ARM_MATH_SUCCESS        : Operation successful
                   - \\ref ARM_MATH_ARGUMENT_ERROR : an error is detected
 */

static arm_status arm_rfft_{length}_fast_init_f32( arm_rfft_fast_instance_f32_extra * S ) {{

  arm_status status;

  if( !S ) return ARM_MATH_ARGUMENT_ERROR;

  status=arm_cfft_init_f32_extra(&(S->Sint),{length//2});
  if (status != ARM_MATH_SUCCESS)
  {{
    return(status);
  }}

  S->fftLenRFFT = {length}U;
  S->pTwiddleRFFT    = (float32_t *) twiddleCoefExtra_rfft_{length};

  return ARM_MATH_SUCCESS;
}}
#endif 
"""
    init_string += f"""

/**
  @brief         Initialization function for the floating-point real FFT.
  @param[in,out] S       points to an arm_rfft_fast_instance_f32_extra structure
  @param[in]     fftLen  length of the Real Sequence
  @return        execution status
                   - \\ref ARM_MATH_SUCCESS        : Operation successful
                   - \\ref ARM_MATH_ARGUMENT_ERROR : <code>fftLen</code> is not a supported length

  @par           Description
                   The parameter <code>fftLen</code> specifies the length of RFFT/CIFFT process.
                   Supported FFT Lengths are {", ".join(str(2**power) for power, _ in lengths)}.
  @par
                   This Function also initializes Twiddle factor table pointer and Bit reversal table pointer.
 */

arm_status arm_rfft_fast_init_f32_extra(
  arm_rfft_fast_instance_f32_extra * S,
  uint16_t fftLen)
{{
  typedef arm_status(*fft_init_ptr)( arm_rfft_fast_instance_f32_extra *);
  fft_init_ptr fptr = 0x0;

  switch (fftLen)
  {{
"""
    for power, length in lengths[::-1]:
        init_string += f"""
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_{length//2}) && (defined(ARM_TABLE_BITREVIDX_FLT_{length//2}) || defined(ARM_TABLE_BITREVIDX_FXT_{length//2})) && defined(ARM_TABLE_TWIDDLECOEF_RFFT_F32_{length}))
  case {length}U:
    fptr = arm_rfft_{length}_fast_init_f32;
    break;
#endif
"""
    init_string += """
  default:
    break;
  }

  if( ! fptr ) return ARM_MATH_ARGUMENT_ERROR;
  return fptr( S );

}

/**
  @} end of RealFFT group
 */

"""
    return init_string


def cfft_init(lengths):
    init_string = """
/* ----------------------------------------------------------------------
 * Project:      CMSIS DSP Library
 * Title:        arm_cfft_init_f32_extra.c
 * Description:  Initialization function for cfft f32 instance
 *
 * $Date:        23 April 2021
 * $Revision:    V1.9.0
 *
 * Target Processor: Cortex-M and Cortex-A cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2021 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define FFTINIT(EXT,SIZE)                                           \\
  S->bitRevLength = arm_cfft_sR_##EXT##_len##SIZE##_extra.bitRevLength;        \\
  S->pBitRevTable = arm_cfft_sR_##EXT##_len##SIZE##_extra.pBitRevTable;         \\
  S->pTwiddle = arm_cfft_sR_##EXT##_len##SIZE##_extra.pTwiddle;

/**
  @addtogroup ComplexFFT
  @{
 */

/**
  @brief         Initialization function for the cfft f32 function
  @param[in,out] S              points to an instance of the floating-point CFFT structure
  @param[in]     fftLen         fft length (number of complex samples)
  @return        execution status
                   - \\ref ARM_MATH_SUCCESS        : Operation successful
                   - \\ref ARM_MATH_ARGUMENT_ERROR : an error is detected

  @par          Use of this function is mandatory only for the MVE version of the FFT.
                Other versions can still initialize directly the data structure using 
                variables declared in arm_const_structs_extra.h
 */

#include "extra_ffts.h"
#include "arm_common_tables_extra.h"
#include "arm_const_structs_extra.h"

#if defined(ARM_MATH_MVEF) && !defined(ARM_MATH_AUTOVECTORIZE)

#include "arm_vec_fft.h"
#include "arm_mve_tables.h"

arm_status arm_cfft_radix4by2_rearrange_twiddles_f32(arm_cfft_instance_f32_extra *S, int twidCoefModifier)
{
                                                                  
        switch (S->fftLen >> (twidCoefModifier - 1)) {  
"""
    for power, length in lengths[::-1]:
        if power % 2 != 0:
            continue
        init_string += f"""
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) \\
            || defined(ARM_TABLE_TWIDDLECOEF_F32_{length})                                                                                                
        case {length}U:                                                                                
            S->rearranged_twiddle_tab_stride1_arr = rearranged_twiddle_tab_stride1_arr_{length}_f32;
            S->rearranged_twiddle_stride1  =  rearranged_twiddle_stride1_{length}_f32;     

            S->rearranged_twiddle_tab_stride2_arr = rearranged_twiddle_tab_stride2_arr_{length}_f32;
            S->rearranged_twiddle_stride2  =  rearranged_twiddle_stride2_{length}_f32;    

            S->rearranged_twiddle_tab_stride3_arr = rearranged_twiddle_tab_stride3_arr_{length}_f32;
            S->rearranged_twiddle_stride3  =  rearranged_twiddle_stride3_{length}_f32;                                                     
            break; 
#endif
"""
    init_string += """                                                                         
                                                                                                   
        default:  
            return(ARM_MATH_ARGUMENT_ERROR);                                                                                 
            break;                                                                                 
            /* invalid sizes already filtered */                                                   
        }                                                                                          

        return(ARM_MATH_SUCCESS);

}

arm_status arm_cfft_init_f32_extra(
  arm_cfft_instance_f32_extra * S,
  uint16_t fftLen)
{

        /*  Initialise the default arm status */                                
        arm_status status = ARM_MATH_SUCCESS;                                   
                                                                                
        /*  Initialise the FFT length */                                        
        S->fftLen = fftLen;                                                     
                                                                                
        /*  Initialise the Twiddle coefficient pointer */                       
        S->pTwiddle = NULL;                         
                                                                                
                                                                                
        /*  Initializations of Instance structure depending on the FFT length */
        switch (S->fftLen) {   
"""

    for power, length in lengths[::-1]:
        init_string += f"""                                                 
            /*  Initializations of structure parameters for {length} point FFT */   
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_BITREVIDX_FXT_{length}) && defined(ARM_TABLE_TWIDDLECOEF_F32_{length}))                     
        case {length}U:  
            /*  Initialise the bit reversal table modifier */                   
            S->bitRevLength = ARMBITREVINDEXTABLE_FIXED_{length}_TABLE_LENGTH_EXTRA;      
            S->pBitRevTable = (uint16_t *)armBitRevIndexTable_fixed_{length};   
            S->pTwiddle = (float32_t *)twiddleCoefExtra_{length};       
            status=arm_cfft_radix4by2_rearrange_twiddles_f32(S, {(power % 2) + 1});               
            break;                                                              
#endif 
"""
    init_string += """                                                   
        default:                                                                
            /*  Reporting argument error if fftSize is not valid value */       
            status = ARM_MATH_ARGUMENT_ERROR;                                   
            break;                                                              
        }                                                                       
                                                                                
                                                                                
        return (status);     
}
#else
arm_status arm_cfft_init_f32_extra(
  arm_cfft_instance_f32_extra * S,
  uint16_t fftLen)
{
        /*  Initialise the default arm status */
        arm_status status = ARM_MATH_SUCCESS;

        /*  Initialise the FFT length */
        S->fftLen = fftLen;

        /*  Initialise the Twiddle coefficient pointer */
        S->pTwiddle = NULL;


        /*  Initializations of Instance structure depending on the FFT length */
        switch (S->fftLen) {
"""
    for power, length in lengths[::-1]:
        init_string += f"""
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_{length}) && defined(ARM_TABLE_BITREVIDX_FLT_{length}))
            /*  Initializations of structure parameters for {length} point FFT */
        case {length}U:
            /*  Initialise the bit reversal table modifier */
            FFTINIT(f32,{length});
            break;
#endif
"""
    init_string += """

        default:
            /*  Reporting argument error if fftSize is not valid value */
            status = ARM_MATH_ARGUMENT_ERROR;
            break;
        }


        return (status);
}
#endif /* defined(ARM_MATH_MVEF) && !defined(ARM_MATH_AUTOVECTORIZE) */

/**
  @} end of ComplexFFT group
 */

"""
    return init_string


def const_structs(lengths):
    struct_string = """
#include "arm_math_types.h"
#include "arm_const_structs_extra.h"

/* Floating-point structs */
#if !defined(ARM_MATH_MVEF) || defined(ARM_MATH_AUTOVECTORIZE)
"""
    header_string = """
#ifndef _ARM_CONST_STRUCTS_EXTRA_H
#define _ARM_CONST_STRUCTS_EXTRA_H

#include "arm_math_types.h"
#include "arm_common_tables_extra.h"
#include "extra_ffts.h"

#ifdef   __cplusplus
extern "C"
{
#endif
"""
    for power, length in lengths:
        struct_string += f"""

#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_F32_{length}) && defined(ARM_TABLE_BITREVIDX_FLT_{length}))
const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len{length}_extra = {{
  {length}, twiddleCoefExtra_{length}, armBitRevIndexTableExtra{length}, ARMBITREVINDEXTABLE_{length}_TABLE_LENGTH_EXTRA
}};
#endif

"""
        header_string += f"   extern const arm_cfft_instance_f32_extra arm_cfft_sR_f32_len{length}_extra;\n"
    struct_string += """
#endif /* !defined(ARM_MATH_MVEF) || defined(ARM_MATH_AUTOVECTORIZE) */
"""

    header_string += """

#ifdef   __cplusplus
}
#endif

#endif


"""
    return header_string, struct_string
