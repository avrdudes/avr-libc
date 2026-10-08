/*
 * Header file for AVR32SD20
 *
 * Copyright (c) 2026 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioavr32sd20.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#ifndef _AVR_AVR32SD20_H_INCLUDED
#define _AVR_AVR32SD20_H_INCLUDED

/* Ungrouped common registers */
#define CCP  _SFR_MEM8(0x0034)  /* Configuration Change Protection */
#define SP  _SFR_MEM16(0x003D)  /* Stack Pointer */
#define SPL  _SFR_MEM8(0x003D)  /* Stack Pointer Low */
#define SPH  _SFR_MEM8(0x003E)  /* Stack Pointer High */
#define SREG  _SFR_MEM8(0x003F)  /* Status Register */

/* C Language Only */
#if !defined (__ASSEMBLER__)

#include <stdint.h>

typedef volatile uint8_t register8_t;
typedef volatile uint16_t register16_t;
typedef volatile uint32_t register32_t;

#ifdef _WORDREGISTER
#undef _WORDREGISTER
#endif
#define _WORDREGISTER(regname)        \
    __extension__ union               \
    {                                 \
        register16_t regname;         \
        struct                        \
        {                             \
            register8_t regname ## L; \
            register8_t regname ## H; \
        };                            \
    }

#ifdef _DWORDREGISTER
#undef _DWORDREGISTER
#endif
#define _DWORDREGISTER(regname)       \
    __extension__ union               \
    {                                 \
        register32_t regname;         \
        struct                        \
        {                             \
            register8_t regname ## 0; \
            register8_t regname ## 1; \
            register8_t regname ## 2; \
            register8_t regname ## 3; \
        };                            \
    }




#endif /* !defined (__ASSEMBLER__) */


/*================== Bitfield Definitions ================== */

/* AC - Analog Comparator */
/* AC.CTRLA  bit masks and bit positions */
#define AC_ENABLE_bm  0x01  /* Enable bit mask. */
#define AC_ENABLE_bp  0  /* Enable bit position. */
#define AC_HYSMODE_gm  0x06  /* Hysteresis Mode group mask. */
#define AC_HYSMODE_gp  1  /* Hysteresis Mode group position. */
#define AC_HYSMODE_0_bm  (1<<1)  /* Hysteresis Mode bit 0 mask. */
#define AC_HYSMODE_0_bp  1  /* Hysteresis Mode bit 0 position. */
#define AC_HYSMODE_1_bm  (1<<2)  /* Hysteresis Mode bit 1 mask. */
#define AC_HYSMODE_1_bp  2  /* Hysteresis Mode bit 1 position. */
#define AC_POWER_gm  0x18  /* Power profile group mask. */
#define AC_POWER_gp  3  /* Power profile group position. */
#define AC_POWER_0_bm  (1<<3)  /* Power profile bit 0 mask. */
#define AC_POWER_0_bp  3  /* Power profile bit 0 position. */
#define AC_POWER_1_bm  (1<<4)  /* Power profile bit 1 mask. */
#define AC_POWER_1_bp  4  /* Power profile bit 1 position. */
#define AC_OUTEN_bm  0x40  /* Output Pad Enable bit mask. */
#define AC_OUTEN_bp  6  /* Output Pad Enable bit position. */
#define AC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define AC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* AC.CTRLB  bit masks and bit positions */
#define AC_WINSEL_gm  0x03  /* Window selection mode group mask. */
#define AC_WINSEL_gp  0  /* Window selection mode group position. */
#define AC_WINSEL_0_bm  (1<<0)  /* Window selection mode bit 0 mask. */
#define AC_WINSEL_0_bp  0  /* Window selection mode bit 0 position. */
#define AC_WINSEL_1_bm  (1<<1)  /* Window selection mode bit 1 mask. */
#define AC_WINSEL_1_bp  1  /* Window selection mode bit 1 position. */

/* AC.MUXCTRL  bit masks and bit positions */
#define AC_MUXNEG_gm  0x07  /* Negative Input MUX Selection group mask. */
#define AC_MUXNEG_gp  0  /* Negative Input MUX Selection group position. */
#define AC_MUXNEG_0_bm  (1<<0)  /* Negative Input MUX Selection bit 0 mask. */
#define AC_MUXNEG_0_bp  0  /* Negative Input MUX Selection bit 0 position. */
#define AC_MUXNEG_1_bm  (1<<1)  /* Negative Input MUX Selection bit 1 mask. */
#define AC_MUXNEG_1_bp  1  /* Negative Input MUX Selection bit 1 position. */
#define AC_MUXNEG_2_bm  (1<<2)  /* Negative Input MUX Selection bit 2 mask. */
#define AC_MUXNEG_2_bp  2  /* Negative Input MUX Selection bit 2 position. */
#define AC_MUXPOS_gm  0x38  /* Positive Input MUX Selection group mask. */
#define AC_MUXPOS_gp  3  /* Positive Input MUX Selection group position. */
#define AC_MUXPOS_0_bm  (1<<3)  /* Positive Input MUX Selection bit 0 mask. */
#define AC_MUXPOS_0_bp  3  /* Positive Input MUX Selection bit 0 position. */
#define AC_MUXPOS_1_bm  (1<<4)  /* Positive Input MUX Selection bit 1 mask. */
#define AC_MUXPOS_1_bp  4  /* Positive Input MUX Selection bit 1 position. */
#define AC_MUXPOS_2_bm  (1<<5)  /* Positive Input MUX Selection bit 2 mask. */
#define AC_MUXPOS_2_bp  5  /* Positive Input MUX Selection bit 2 position. */
#define AC_INITVAL_bm  0x40  /* AC Output Initial Value bit mask. */
#define AC_INITVAL_bp  6  /* AC Output Initial Value bit position. */
#define AC_INVERT_bm  0x80  /* Invert AC Output bit mask. */
#define AC_INVERT_bp  7  /* Invert AC Output bit position. */

/* AC.DACREF  bit masks and bit positions */
#define AC_DACREF_gm  0xFF  /* DACREF group mask. */
#define AC_DACREF_gp  0  /* DACREF group position. */
#define AC_DACREF_0_bm  (1<<0)  /* DACREF bit 0 mask. */
#define AC_DACREF_0_bp  0  /* DACREF bit 0 position. */
#define AC_DACREF_1_bm  (1<<1)  /* DACREF bit 1 mask. */
#define AC_DACREF_1_bp  1  /* DACREF bit 1 position. */
#define AC_DACREF_2_bm  (1<<2)  /* DACREF bit 2 mask. */
#define AC_DACREF_2_bp  2  /* DACREF bit 2 position. */
#define AC_DACREF_3_bm  (1<<3)  /* DACREF bit 3 mask. */
#define AC_DACREF_3_bp  3  /* DACREF bit 3 position. */
#define AC_DACREF_4_bm  (1<<4)  /* DACREF bit 4 mask. */
#define AC_DACREF_4_bp  4  /* DACREF bit 4 position. */
#define AC_DACREF_5_bm  (1<<5)  /* DACREF bit 5 mask. */
#define AC_DACREF_5_bp  5  /* DACREF bit 5 position. */
#define AC_DACREF_6_bm  (1<<6)  /* DACREF bit 6 mask. */
#define AC_DACREF_6_bp  6  /* DACREF bit 6 position. */
#define AC_DACREF_7_bm  (1<<7)  /* DACREF bit 7 mask. */
#define AC_DACREF_7_bp  7  /* DACREF bit 7 position. */

/* AC.INTCTRL  bit masks and bit positions */
#define AC_CMP_bm  0x01  /* Interrupt Enable bit mask. */
#define AC_CMP_bp  0  /* Interrupt Enable bit position. */
#define AC_INTMODE_NORMAL_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_NORMAL_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE_NORMAL_0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE_NORMAL_0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE_NORMAL_1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE_NORMAL_1_bp  5  /* Interrupt Mode bit 1 position. */
#define AC_INTMODE_WINDOW_gm  0x30  /* Interrupt Mode group mask. */
#define AC_INTMODE_WINDOW_gp  4  /* Interrupt Mode group position. */
#define AC_INTMODE_WINDOW_0_bm  (1<<4)  /* Interrupt Mode bit 0 mask. */
#define AC_INTMODE_WINDOW_0_bp  4  /* Interrupt Mode bit 0 position. */
#define AC_INTMODE_WINDOW_1_bm  (1<<5)  /* Interrupt Mode bit 1 mask. */
#define AC_INTMODE_WINDOW_1_bp  5  /* Interrupt Mode bit 1 position. */

/* AC.STATUS  bit masks and bit positions */
#define AC_CMPIF_bm  0x01  /* Analog Comparator Interrupt Flag bit mask. */
#define AC_CMPIF_bp  0  /* Analog Comparator Interrupt Flag bit position. */
#define AC_CMPSTATE_bm  0x10  /* Analog Comparator State bit mask. */
#define AC_CMPSTATE_bp  4  /* Analog Comparator State bit position. */
#define AC_WINSTATE_gm  0xC0  /* Analog Comparator Window State group mask. */
#define AC_WINSTATE_gp  6  /* Analog Comparator Window State group position. */
#define AC_WINSTATE_0_bm  (1<<6)  /* Analog Comparator Window State bit 0 mask. */
#define AC_WINSTATE_0_bp  6  /* Analog Comparator Window State bit 0 position. */
#define AC_WINSTATE_1_bm  (1<<7)  /* Analog Comparator Window State bit 1 mask. */
#define AC_WINSTATE_1_bp  7  /* Analog Comparator Window State bit 1 position. */


/* ADC - Analog to Digital Converter */
/* ADC.CTRLA  bit masks and bit positions */
#define ADC_ENABLE_bm  0x01  /* ADC Enable bit mask. */
#define ADC_ENABLE_bp  0  /* ADC Enable bit position. */
#define ADC_LOWLAT_bm  0x20  /* Conversion mode bit mask. */
#define ADC_LOWLAT_bp  5  /* Conversion mode bit position. */
#define ADC_RUNSTBY_bm  0x80  /* Run standby mode bit mask. */
#define ADC_RUNSTBY_bp  7  /* Run standby mode bit position. */

/* ADC.CTRLB  bit masks and bit positions */
#define ADC_PRESC_gm  0x0F  /* Clock Pre-scaler group mask. */
#define ADC_PRESC_gp  0  /* Clock Pre-scaler group position. */
#define ADC_PRESC_0_bm  (1<<0)  /* Clock Pre-scaler bit 0 mask. */
#define ADC_PRESC_0_bp  0  /* Clock Pre-scaler bit 0 position. */
#define ADC_PRESC_1_bm  (1<<1)  /* Clock Pre-scaler bit 1 mask. */
#define ADC_PRESC_1_bp  1  /* Clock Pre-scaler bit 1 position. */
#define ADC_PRESC_2_bm  (1<<2)  /* Clock Pre-scaler bit 2 mask. */
#define ADC_PRESC_2_bp  2  /* Clock Pre-scaler bit 2 position. */
#define ADC_PRESC_3_bm  (1<<3)  /* Clock Pre-scaler bit 3 mask. */
#define ADC_PRESC_3_bp  3  /* Clock Pre-scaler bit 3 position. */

/* ADC.CTRLC  bit masks and bit positions */
#define ADC_REFSEL_gm  0x07  /* Reference Selection group mask. */
#define ADC_REFSEL_gp  0  /* Reference Selection group position. */
#define ADC_REFSEL_0_bm  (1<<0)  /* Reference Selection bit 0 mask. */
#define ADC_REFSEL_0_bp  0  /* Reference Selection bit 0 position. */
#define ADC_REFSEL_1_bm  (1<<1)  /* Reference Selection bit 1 mask. */
#define ADC_REFSEL_1_bp  1  /* Reference Selection bit 1 position. */
#define ADC_REFSEL_2_bm  (1<<2)  /* Reference Selection bit 2 mask. */
#define ADC_REFSEL_2_bp  2  /* Reference Selection bit 2 position. */

/* ADC.CTRLD  bit masks and bit positions */
#define ADC_WINCM_gm  0x07  /* Window Comparator Mode group mask. */
#define ADC_WINCM_gp  0  /* Window Comparator Mode group position. */
#define ADC_WINCM_0_bm  (1<<0)  /* Window Comparator Mode bit 0 mask. */
#define ADC_WINCM_0_bp  0  /* Window Comparator Mode bit 0 position. */
#define ADC_WINCM_1_bm  (1<<1)  /* Window Comparator Mode bit 1 mask. */
#define ADC_WINCM_1_bp  1  /* Window Comparator Mode bit 1 position. */
#define ADC_WINCM_2_bm  (1<<2)  /* Window Comparator Mode bit 2 mask. */
#define ADC_WINCM_2_bp  2  /* Window Comparator Mode bit 2 position. */
#define ADC_WINSRC_bm  0x08  /* Window Mode Source bit mask. */
#define ADC_WINSRC_bp  3  /* Window Mode Source bit position. */

/* ADC.CTRLE  bit masks and bit positions */
#define ADC_SAMPDUR_gm  0xFF  /* Sample Duration group mask. */
#define ADC_SAMPDUR_gp  0  /* Sample Duration group position. */
#define ADC_SAMPDUR_0_bm  (1<<0)  /* Sample Duration bit 0 mask. */
#define ADC_SAMPDUR_0_bp  0  /* Sample Duration bit 0 position. */
#define ADC_SAMPDUR_1_bm  (1<<1)  /* Sample Duration bit 1 mask. */
#define ADC_SAMPDUR_1_bp  1  /* Sample Duration bit 1 position. */
#define ADC_SAMPDUR_2_bm  (1<<2)  /* Sample Duration bit 2 mask. */
#define ADC_SAMPDUR_2_bp  2  /* Sample Duration bit 2 position. */
#define ADC_SAMPDUR_3_bm  (1<<3)  /* Sample Duration bit 3 mask. */
#define ADC_SAMPDUR_3_bp  3  /* Sample Duration bit 3 position. */
#define ADC_SAMPDUR_4_bm  (1<<4)  /* Sample Duration bit 4 mask. */
#define ADC_SAMPDUR_4_bp  4  /* Sample Duration bit 4 position. */
#define ADC_SAMPDUR_5_bm  (1<<5)  /* Sample Duration bit 5 mask. */
#define ADC_SAMPDUR_5_bp  5  /* Sample Duration bit 5 position. */
#define ADC_SAMPDUR_6_bm  (1<<6)  /* Sample Duration bit 6 mask. */
#define ADC_SAMPDUR_6_bp  6  /* Sample Duration bit 6 position. */
#define ADC_SAMPDUR_7_bm  (1<<7)  /* Sample Duration bit 7 mask. */
#define ADC_SAMPDUR_7_bp  7  /* Sample Duration bit 7 position. */

/* ADC.CTRLF  bit masks and bit positions */
#define ADC_SAMPNUM_gm  0x07  /* Sampling Number group mask. */
#define ADC_SAMPNUM_gp  0  /* Sampling Number group position. */
#define ADC_SAMPNUM_0_bm  (1<<0)  /* Sampling Number bit 0 mask. */
#define ADC_SAMPNUM_0_bp  0  /* Sampling Number bit 0 position. */
#define ADC_SAMPNUM_1_bm  (1<<1)  /* Sampling Number bit 1 mask. */
#define ADC_SAMPNUM_1_bp  1  /* Sampling Number bit 1 position. */
#define ADC_SAMPNUM_2_bm  (1<<2)  /* Sampling Number bit 2 mask. */
#define ADC_SAMPNUM_2_bp  2  /* Sampling Number bit 2 position. */
#define ADC_LEFTADJ_bm  0x10  /* Left Adjust bit mask. */
#define ADC_LEFTADJ_bp  4  /* Left Adjust bit position. */
#define ADC_FREERUN_bm  0x20  /* Free Running bit mask. */
#define ADC_FREERUN_bp  5  /* Free Running bit position. */

/* ADC.INTCTRL  bit masks and bit positions */
#define ADC_RESRDY_bm  0x01  /* Result Ready Interrupt Enable bit mask. */
#define ADC_RESRDY_bp  0  /* Result Ready Interrupt Enable bit position. */
#define ADC_SAMPRDY_bm  0x02  /* Sample Ready Interrupt Enable bit mask. */
#define ADC_SAMPRDY_bp  1  /* Sample Ready Interrupt Enable bit position. */
#define ADC_WCMP_bm  0x04  /* Window Comparator Interrupt Enable bit mask. */
#define ADC_WCMP_bp  2  /* Window Comparator Interrupt Enable bit position. */
#define ADC_RESOVR_bm  0x08  /* Result Overwrite Interrupt Enable bit mask. */
#define ADC_RESOVR_bp  3  /* Result Overwrite Interrupt Enable bit position. */
#define ADC_SAMPOVR_bm  0x10  /* Sample Overwrite Interrupt Enable bit mask. */
#define ADC_SAMPOVR_bp  4  /* Sample Overwrite Interrupt Enable bit position. */
#define ADC_TRIGOVR_bm  0x20  /* Trigger Overrun Interrupt Enable bit mask. */
#define ADC_TRIGOVR_bp  5  /* Trigger Overrun Interrupt Enable bit position. */

/* ADC.INTFLAGS  bit masks and bit positions */
/* ADC_RESRDY  is already defined. */
/* ADC_SAMPRDY  is already defined. */
/* ADC_WCMP  is already defined. */
/* ADC_RESOVR  is already defined. */
/* ADC_SAMPOVR  is already defined. */
/* ADC_TRIGOVR  is already defined. */

/* ADC.STATUS  bit masks and bit positions */
#define ADC_ADCBUSY_bm  0x01  /* ADC Busy bit mask. */
#define ADC_ADCBUSY_bp  0  /* ADC Busy bit position. */

/* ADC.DBGCTRL  bit masks and bit positions */
#define ADC_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define ADC_DBGRUN_bp  0  /* Debug run bit position. */

/* ADC.COMMAND  bit masks and bit positions */
#define ADC_START_gm  0x07  /* Start Conversion group mask. */
#define ADC_START_gp  0  /* Start Conversion group position. */
#define ADC_START_0_bm  (1<<0)  /* Start Conversion bit 0 mask. */
#define ADC_START_0_bp  0  /* Start Conversion bit 0 position. */
#define ADC_START_1_bm  (1<<1)  /* Start Conversion bit 1 mask. */
#define ADC_START_1_bp  1  /* Start Conversion bit 1 position. */
#define ADC_START_2_bm  (1<<2)  /* Start Conversion bit 2 mask. */
#define ADC_START_2_bp  2  /* Start Conversion bit 2 position. */
#define ADC_MODE_gm  0x70  /* Mode group mask. */
#define ADC_MODE_gp  4  /* Mode group position. */
#define ADC_MODE_0_bm  (1<<4)  /* Mode bit 0 mask. */
#define ADC_MODE_0_bp  4  /* Mode bit 0 position. */
#define ADC_MODE_1_bm  (1<<5)  /* Mode bit 1 mask. */
#define ADC_MODE_1_bp  5  /* Mode bit 1 position. */
#define ADC_MODE_2_bm  (1<<6)  /* Mode bit 2 mask. */
#define ADC_MODE_2_bp  6  /* Mode bit 2 position. */

/* ADC.MUXPOS  bit masks and bit positions */
#define ADC_MUXPOS_gm  0x7F  /* Analog Channel Selection Bits group mask. */
#define ADC_MUXPOS_gp  0  /* Analog Channel Selection Bits group position. */
#define ADC_MUXPOS_0_bm  (1<<0)  /* Analog Channel Selection Bits bit 0 mask. */
#define ADC_MUXPOS_0_bp  0  /* Analog Channel Selection Bits bit 0 position. */
#define ADC_MUXPOS_1_bm  (1<<1)  /* Analog Channel Selection Bits bit 1 mask. */
#define ADC_MUXPOS_1_bp  1  /* Analog Channel Selection Bits bit 1 position. */
#define ADC_MUXPOS_2_bm  (1<<2)  /* Analog Channel Selection Bits bit 2 mask. */
#define ADC_MUXPOS_2_bp  2  /* Analog Channel Selection Bits bit 2 position. */
#define ADC_MUXPOS_3_bm  (1<<3)  /* Analog Channel Selection Bits bit 3 mask. */
#define ADC_MUXPOS_3_bp  3  /* Analog Channel Selection Bits bit 3 position. */
#define ADC_MUXPOS_4_bm  (1<<4)  /* Analog Channel Selection Bits bit 4 mask. */
#define ADC_MUXPOS_4_bp  4  /* Analog Channel Selection Bits bit 4 position. */
#define ADC_MUXPOS_5_bm  (1<<5)  /* Analog Channel Selection Bits bit 5 mask. */
#define ADC_MUXPOS_5_bp  5  /* Analog Channel Selection Bits bit 5 position. */
#define ADC_MUXPOS_6_bm  (1<<6)  /* Analog Channel Selection Bits bit 6 mask. */
#define ADC_MUXPOS_6_bp  6  /* Analog Channel Selection Bits bit 6 position. */

/* ADC.RESULT  bit masks and bit positions */
#define ADC_RESULT_gm  0xFFFF  /* ADC Result group mask. */
#define ADC_RESULT_gp  0  /* ADC Result group position. */
#define ADC_RESULT_0_bm  (1<<0)  /* ADC Result bit 0 mask. */
#define ADC_RESULT_0_bp  0  /* ADC Result bit 0 position. */
#define ADC_RESULT_1_bm  (1<<1)  /* ADC Result bit 1 mask. */
#define ADC_RESULT_1_bp  1  /* ADC Result bit 1 position. */
#define ADC_RESULT_2_bm  (1<<2)  /* ADC Result bit 2 mask. */
#define ADC_RESULT_2_bp  2  /* ADC Result bit 2 position. */
#define ADC_RESULT_3_bm  (1<<3)  /* ADC Result bit 3 mask. */
#define ADC_RESULT_3_bp  3  /* ADC Result bit 3 position. */
#define ADC_RESULT_4_bm  (1<<4)  /* ADC Result bit 4 mask. */
#define ADC_RESULT_4_bp  4  /* ADC Result bit 4 position. */
#define ADC_RESULT_5_bm  (1<<5)  /* ADC Result bit 5 mask. */
#define ADC_RESULT_5_bp  5  /* ADC Result bit 5 position. */
#define ADC_RESULT_6_bm  (1<<6)  /* ADC Result bit 6 mask. */
#define ADC_RESULT_6_bp  6  /* ADC Result bit 6 position. */
#define ADC_RESULT_7_bm  (1<<7)  /* ADC Result bit 7 mask. */
#define ADC_RESULT_7_bp  7  /* ADC Result bit 7 position. */
#define ADC_RESULT_8_bm  (1<<8)  /* ADC Result bit 8 mask. */
#define ADC_RESULT_8_bp  8  /* ADC Result bit 8 position. */
#define ADC_RESULT_9_bm  (1<<9)  /* ADC Result bit 9 mask. */
#define ADC_RESULT_9_bp  9  /* ADC Result bit 9 position. */
#define ADC_RESULT_10_bm  (1<<10)  /* ADC Result bit 10 mask. */
#define ADC_RESULT_10_bp  10  /* ADC Result bit 10 position. */
#define ADC_RESULT_11_bm  (1<<11)  /* ADC Result bit 11 mask. */
#define ADC_RESULT_11_bp  11  /* ADC Result bit 11 position. */
#define ADC_RESULT_12_bm  (1<<12)  /* ADC Result bit 12 mask. */
#define ADC_RESULT_12_bp  12  /* ADC Result bit 12 position. */
#define ADC_RESULT_13_bm  (1<<13)  /* ADC Result bit 13 mask. */
#define ADC_RESULT_13_bp  13  /* ADC Result bit 13 position. */
#define ADC_RESULT_14_bm  (1<<14)  /* ADC Result bit 14 mask. */
#define ADC_RESULT_14_bp  14  /* ADC Result bit 14 position. */
#define ADC_RESULT_15_bm  (1<<15)  /* ADC Result bit 15 mask. */
#define ADC_RESULT_15_bp  15  /* ADC Result bit 15 position. */

/* ADC.SAMPLE  bit masks and bit positions */
#define ADC_SAMPLE_gm  0xFFFF  /* ADC Sample group mask. */
#define ADC_SAMPLE_gp  0  /* ADC Sample group position. */
#define ADC_SAMPLE_0_bm  (1<<0)  /* ADC Sample bit 0 mask. */
#define ADC_SAMPLE_0_bp  0  /* ADC Sample bit 0 position. */
#define ADC_SAMPLE_1_bm  (1<<1)  /* ADC Sample bit 1 mask. */
#define ADC_SAMPLE_1_bp  1  /* ADC Sample bit 1 position. */
#define ADC_SAMPLE_2_bm  (1<<2)  /* ADC Sample bit 2 mask. */
#define ADC_SAMPLE_2_bp  2  /* ADC Sample bit 2 position. */
#define ADC_SAMPLE_3_bm  (1<<3)  /* ADC Sample bit 3 mask. */
#define ADC_SAMPLE_3_bp  3  /* ADC Sample bit 3 position. */
#define ADC_SAMPLE_4_bm  (1<<4)  /* ADC Sample bit 4 mask. */
#define ADC_SAMPLE_4_bp  4  /* ADC Sample bit 4 position. */
#define ADC_SAMPLE_5_bm  (1<<5)  /* ADC Sample bit 5 mask. */
#define ADC_SAMPLE_5_bp  5  /* ADC Sample bit 5 position. */
#define ADC_SAMPLE_6_bm  (1<<6)  /* ADC Sample bit 6 mask. */
#define ADC_SAMPLE_6_bp  6  /* ADC Sample bit 6 position. */
#define ADC_SAMPLE_7_bm  (1<<7)  /* ADC Sample bit 7 mask. */
#define ADC_SAMPLE_7_bp  7  /* ADC Sample bit 7 position. */
#define ADC_SAMPLE_8_bm  (1<<8)  /* ADC Sample bit 8 mask. */
#define ADC_SAMPLE_8_bp  8  /* ADC Sample bit 8 position. */
#define ADC_SAMPLE_9_bm  (1<<9)  /* ADC Sample bit 9 mask. */
#define ADC_SAMPLE_9_bp  9  /* ADC Sample bit 9 position. */
#define ADC_SAMPLE_10_bm  (1<<10)  /* ADC Sample bit 10 mask. */
#define ADC_SAMPLE_10_bp  10  /* ADC Sample bit 10 position. */
#define ADC_SAMPLE_11_bm  (1<<11)  /* ADC Sample bit 11 mask. */
#define ADC_SAMPLE_11_bp  11  /* ADC Sample bit 11 position. */
#define ADC_SAMPLE_12_bm  (1<<12)  /* ADC Sample bit 12 mask. */
#define ADC_SAMPLE_12_bp  12  /* ADC Sample bit 12 position. */
#define ADC_SAMPLE_13_bm  (1<<13)  /* ADC Sample bit 13 mask. */
#define ADC_SAMPLE_13_bp  13  /* ADC Sample bit 13 position. */
#define ADC_SAMPLE_14_bm  (1<<14)  /* ADC Sample bit 14 mask. */
#define ADC_SAMPLE_14_bp  14  /* ADC Sample bit 14 position. */
#define ADC_SAMPLE_15_bm  (1<<15)  /* ADC Sample bit 15 mask. */
#define ADC_SAMPLE_15_bp  15  /* ADC Sample bit 15 position. */

/* ADC.WINLT  bit masks and bit positions */
#define ADC_WINLT_gm  0xFFFF  /* Window Low Threshold group mask. */
#define ADC_WINLT_gp  0  /* Window Low Threshold group position. */
#define ADC_WINLT_0_bm  (1<<0)  /* Window Low Threshold bit 0 mask. */
#define ADC_WINLT_0_bp  0  /* Window Low Threshold bit 0 position. */
#define ADC_WINLT_1_bm  (1<<1)  /* Window Low Threshold bit 1 mask. */
#define ADC_WINLT_1_bp  1  /* Window Low Threshold bit 1 position. */
#define ADC_WINLT_2_bm  (1<<2)  /* Window Low Threshold bit 2 mask. */
#define ADC_WINLT_2_bp  2  /* Window Low Threshold bit 2 position. */
#define ADC_WINLT_3_bm  (1<<3)  /* Window Low Threshold bit 3 mask. */
#define ADC_WINLT_3_bp  3  /* Window Low Threshold bit 3 position. */
#define ADC_WINLT_4_bm  (1<<4)  /* Window Low Threshold bit 4 mask. */
#define ADC_WINLT_4_bp  4  /* Window Low Threshold bit 4 position. */
#define ADC_WINLT_5_bm  (1<<5)  /* Window Low Threshold bit 5 mask. */
#define ADC_WINLT_5_bp  5  /* Window Low Threshold bit 5 position. */
#define ADC_WINLT_6_bm  (1<<6)  /* Window Low Threshold bit 6 mask. */
#define ADC_WINLT_6_bp  6  /* Window Low Threshold bit 6 position. */
#define ADC_WINLT_7_bm  (1<<7)  /* Window Low Threshold bit 7 mask. */
#define ADC_WINLT_7_bp  7  /* Window Low Threshold bit 7 position. */
#define ADC_WINLT_8_bm  (1<<8)  /* Window Low Threshold bit 8 mask. */
#define ADC_WINLT_8_bp  8  /* Window Low Threshold bit 8 position. */
#define ADC_WINLT_9_bm  (1<<9)  /* Window Low Threshold bit 9 mask. */
#define ADC_WINLT_9_bp  9  /* Window Low Threshold bit 9 position. */
#define ADC_WINLT_10_bm  (1<<10)  /* Window Low Threshold bit 10 mask. */
#define ADC_WINLT_10_bp  10  /* Window Low Threshold bit 10 position. */
#define ADC_WINLT_11_bm  (1<<11)  /* Window Low Threshold bit 11 mask. */
#define ADC_WINLT_11_bp  11  /* Window Low Threshold bit 11 position. */
#define ADC_WINLT_12_bm  (1<<12)  /* Window Low Threshold bit 12 mask. */
#define ADC_WINLT_12_bp  12  /* Window Low Threshold bit 12 position. */
#define ADC_WINLT_13_bm  (1<<13)  /* Window Low Threshold bit 13 mask. */
#define ADC_WINLT_13_bp  13  /* Window Low Threshold bit 13 position. */
#define ADC_WINLT_14_bm  (1<<14)  /* Window Low Threshold bit 14 mask. */
#define ADC_WINLT_14_bp  14  /* Window Low Threshold bit 14 position. */
#define ADC_WINLT_15_bm  (1<<15)  /* Window Low Threshold bit 15 mask. */
#define ADC_WINLT_15_bp  15  /* Window Low Threshold bit 15 position. */

/* ADC.WINHT  bit masks and bit positions */
#define ADC_WINHT_gm  0xFFFF  /* Window High Threshold group mask. */
#define ADC_WINHT_gp  0  /* Window High Threshold group position. */
#define ADC_WINHT_0_bm  (1<<0)  /* Window High Threshold bit 0 mask. */
#define ADC_WINHT_0_bp  0  /* Window High Threshold bit 0 position. */
#define ADC_WINHT_1_bm  (1<<1)  /* Window High Threshold bit 1 mask. */
#define ADC_WINHT_1_bp  1  /* Window High Threshold bit 1 position. */
#define ADC_WINHT_2_bm  (1<<2)  /* Window High Threshold bit 2 mask. */
#define ADC_WINHT_2_bp  2  /* Window High Threshold bit 2 position. */
#define ADC_WINHT_3_bm  (1<<3)  /* Window High Threshold bit 3 mask. */
#define ADC_WINHT_3_bp  3  /* Window High Threshold bit 3 position. */
#define ADC_WINHT_4_bm  (1<<4)  /* Window High Threshold bit 4 mask. */
#define ADC_WINHT_4_bp  4  /* Window High Threshold bit 4 position. */
#define ADC_WINHT_5_bm  (1<<5)  /* Window High Threshold bit 5 mask. */
#define ADC_WINHT_5_bp  5  /* Window High Threshold bit 5 position. */
#define ADC_WINHT_6_bm  (1<<6)  /* Window High Threshold bit 6 mask. */
#define ADC_WINHT_6_bp  6  /* Window High Threshold bit 6 position. */
#define ADC_WINHT_7_bm  (1<<7)  /* Window High Threshold bit 7 mask. */
#define ADC_WINHT_7_bp  7  /* Window High Threshold bit 7 position. */
#define ADC_WINHT_8_bm  (1<<8)  /* Window High Threshold bit 8 mask. */
#define ADC_WINHT_8_bp  8  /* Window High Threshold bit 8 position. */
#define ADC_WINHT_9_bm  (1<<9)  /* Window High Threshold bit 9 mask. */
#define ADC_WINHT_9_bp  9  /* Window High Threshold bit 9 position. */
#define ADC_WINHT_10_bm  (1<<10)  /* Window High Threshold bit 10 mask. */
#define ADC_WINHT_10_bp  10  /* Window High Threshold bit 10 position. */
#define ADC_WINHT_11_bm  (1<<11)  /* Window High Threshold bit 11 mask. */
#define ADC_WINHT_11_bp  11  /* Window High Threshold bit 11 position. */
#define ADC_WINHT_12_bm  (1<<12)  /* Window High Threshold bit 12 mask. */
#define ADC_WINHT_12_bp  12  /* Window High Threshold bit 12 position. */
#define ADC_WINHT_13_bm  (1<<13)  /* Window High Threshold bit 13 mask. */
#define ADC_WINHT_13_bp  13  /* Window High Threshold bit 13 position. */
#define ADC_WINHT_14_bm  (1<<14)  /* Window High Threshold bit 14 mask. */
#define ADC_WINHT_14_bp  14  /* Window High Threshold bit 14 position. */
#define ADC_WINHT_15_bm  (1<<15)  /* Window High Threshold bit 15 mask. */
#define ADC_WINHT_15_bp  15  /* Window High Threshold bit 15 position. */

/* ADC.TEMP  bit masks and bit positions */
#define ADC_TEMP_gm  0xFF  /* Temporary group mask. */
#define ADC_TEMP_gp  0  /* Temporary group position. */
#define ADC_TEMP_0_bm  (1<<0)  /* Temporary bit 0 mask. */
#define ADC_TEMP_0_bp  0  /* Temporary bit 0 position. */
#define ADC_TEMP_1_bm  (1<<1)  /* Temporary bit 1 mask. */
#define ADC_TEMP_1_bp  1  /* Temporary bit 1 position. */
#define ADC_TEMP_2_bm  (1<<2)  /* Temporary bit 2 mask. */
#define ADC_TEMP_2_bp  2  /* Temporary bit 2 position. */
#define ADC_TEMP_3_bm  (1<<3)  /* Temporary bit 3 mask. */
#define ADC_TEMP_3_bp  3  /* Temporary bit 3 position. */
#define ADC_TEMP_4_bm  (1<<4)  /* Temporary bit 4 mask. */
#define ADC_TEMP_4_bp  4  /* Temporary bit 4 position. */
#define ADC_TEMP_5_bm  (1<<5)  /* Temporary bit 5 mask. */
#define ADC_TEMP_5_bp  5  /* Temporary bit 5 position. */
#define ADC_TEMP_6_bm  (1<<6)  /* Temporary bit 6 mask. */
#define ADC_TEMP_6_bp  6  /* Temporary bit 6 position. */
#define ADC_TEMP_7_bm  (1<<7)  /* Temporary bit 7 mask. */
#define ADC_TEMP_7_bp  7  /* Temporary bit 7 position. */


/* BOD - Bod interface */
/* BOD.CTRLA  bit masks and bit positions */
#define BOD_SLEEP_gm  0x03  /* Operation in sleep mode group mask. */
#define BOD_SLEEP_gp  0  /* Operation in sleep mode group position. */
#define BOD_SLEEP_0_bm  (1<<0)  /* Operation in sleep mode bit 0 mask. */
#define BOD_SLEEP_0_bp  0  /* Operation in sleep mode bit 0 position. */
#define BOD_SLEEP_1_bm  (1<<1)  /* Operation in sleep mode bit 1 mask. */
#define BOD_SLEEP_1_bp  1  /* Operation in sleep mode bit 1 position. */
#define BOD_ACTIVE_gm  0x0C  /* Operation in active mode group mask. */
#define BOD_ACTIVE_gp  2  /* Operation in active mode group position. */
#define BOD_ACTIVE_0_bm  (1<<2)  /* Operation in active mode bit 0 mask. */
#define BOD_ACTIVE_0_bp  2  /* Operation in active mode bit 0 position. */
#define BOD_ACTIVE_1_bm  (1<<3)  /* Operation in active mode bit 1 mask. */
#define BOD_ACTIVE_1_bp  3  /* Operation in active mode bit 1 position. */
#define BOD_SAMPFREQ_bm  0x10  /* Sample frequency bit mask. */
#define BOD_SAMPFREQ_bp  4  /* Sample frequency bit position. */

/* BOD.CTRLB  bit masks and bit positions */
#define BOD_LVL_gm  0x07  /* Bod level group mask. */
#define BOD_LVL_gp  0  /* Bod level group position. */
#define BOD_LVL_0_bm  (1<<0)  /* Bod level bit 0 mask. */
#define BOD_LVL_0_bp  0  /* Bod level bit 0 position. */
#define BOD_LVL_1_bm  (1<<1)  /* Bod level bit 1 mask. */
#define BOD_LVL_1_bp  1  /* Bod level bit 1 position. */
#define BOD_LVL_2_bm  (1<<2)  /* Bod level bit 2 mask. */
#define BOD_LVL_2_bp  2  /* Bod level bit 2 position. */

/* BOD.VLMCTRLA  bit masks and bit positions */
#define BOD_VLMLVL_gm  0x03  /* voltage level monitor level group mask. */
#define BOD_VLMLVL_gp  0  /* voltage level monitor level group position. */
#define BOD_VLMLVL_0_bm  (1<<0)  /* voltage level monitor level bit 0 mask. */
#define BOD_VLMLVL_0_bp  0  /* voltage level monitor level bit 0 position. */
#define BOD_VLMLVL_1_bm  (1<<1)  /* voltage level monitor level bit 1 mask. */
#define BOD_VLMLVL_1_bp  1  /* voltage level monitor level bit 1 position. */

/* BOD.INTCTRL  bit masks and bit positions */
#define BOD_VLMIE_bm  0x01  /* voltage level monitor interrrupt enable bit mask. */
#define BOD_VLMIE_bp  0  /* voltage level monitor interrrupt enable bit position. */
#define BOD_VLMCFG_gm  0x06  /* Configuration group mask. */
#define BOD_VLMCFG_gp  1  /* Configuration group position. */
#define BOD_VLMCFG_0_bm  (1<<1)  /* Configuration bit 0 mask. */
#define BOD_VLMCFG_0_bp  1  /* Configuration bit 0 position. */
#define BOD_VLMCFG_1_bm  (1<<2)  /* Configuration bit 1 mask. */
#define BOD_VLMCFG_1_bp  2  /* Configuration bit 1 position. */

/* BOD.INTFLAGS  bit masks and bit positions */
#define BOD_VLMIF_bm  0x01  /* Voltage level monitor interrupt flag bit mask. */
#define BOD_VLMIF_bp  0  /* Voltage level monitor interrupt flag bit position. */

/* BOD.STATUS  bit masks and bit positions */
#define BOD_VLMS_bm  0x01  /* Voltage level monitor status bit mask. */
#define BOD_VLMS_bp  0  /* Voltage level monitor status bit position. */



/* CCL - Configurable Custom Logic */
/* CCL.CTRLA  bit masks and bit positions */
#define CCL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CCL_ENABLE_bp  0  /* Enable bit position. */
#define CCL_RUNSTDBY_bm  0x40  /* Run in Standby bit mask. */
#define CCL_RUNSTDBY_bp  6  /* Run in Standby bit position. */

/* CCL.SEQCTRL0  bit masks and bit positions */
#define CCL_SEQSEL_gm  0x0F  /* Sequential Selection group mask. */
#define CCL_SEQSEL_gp  0  /* Sequential Selection group position. */
#define CCL_SEQSEL_0_bm  (1<<0)  /* Sequential Selection bit 0 mask. */
#define CCL_SEQSEL_0_bp  0  /* Sequential Selection bit 0 position. */
#define CCL_SEQSEL_1_bm  (1<<1)  /* Sequential Selection bit 1 mask. */
#define CCL_SEQSEL_1_bp  1  /* Sequential Selection bit 1 position. */
#define CCL_SEQSEL_2_bm  (1<<2)  /* Sequential Selection bit 2 mask. */
#define CCL_SEQSEL_2_bp  2  /* Sequential Selection bit 2 position. */
#define CCL_SEQSEL_3_bm  (1<<3)  /* Sequential Selection bit 3 mask. */
#define CCL_SEQSEL_3_bp  3  /* Sequential Selection bit 3 position. */

/* CCL.SEQCTRL1  bit masks and bit positions */
/* CCL_SEQSEL  is already defined. */

/* CCL.SEQCTRL2  bit masks and bit positions */
/* CCL_SEQSEL  is already defined. */

/* CCL.INTCTRL0  bit masks and bit positions */
#define CCL_INTMODE0_gm  0x03  /* Interrupt Mode for LUT0 group mask. */
#define CCL_INTMODE0_gp  0  /* Interrupt Mode for LUT0 group position. */
#define CCL_INTMODE0_0_bm  (1<<0)  /* Interrupt Mode for LUT0 bit 0 mask. */
#define CCL_INTMODE0_0_bp  0  /* Interrupt Mode for LUT0 bit 0 position. */
#define CCL_INTMODE0_1_bm  (1<<1)  /* Interrupt Mode for LUT0 bit 1 mask. */
#define CCL_INTMODE0_1_bp  1  /* Interrupt Mode for LUT0 bit 1 position. */
#define CCL_INTMODE1_gm  0x0C  /* Interrupt Mode for LUT1 group mask. */
#define CCL_INTMODE1_gp  2  /* Interrupt Mode for LUT1 group position. */
#define CCL_INTMODE1_0_bm  (1<<2)  /* Interrupt Mode for LUT1 bit 0 mask. */
#define CCL_INTMODE1_0_bp  2  /* Interrupt Mode for LUT1 bit 0 position. */
#define CCL_INTMODE1_1_bm  (1<<3)  /* Interrupt Mode for LUT1 bit 1 mask. */
#define CCL_INTMODE1_1_bp  3  /* Interrupt Mode for LUT1 bit 1 position. */
#define CCL_INTMODE2_gm  0x30  /* Interrupt Mode for LUT2 group mask. */
#define CCL_INTMODE2_gp  4  /* Interrupt Mode for LUT2 group position. */
#define CCL_INTMODE2_0_bm  (1<<4)  /* Interrupt Mode for LUT2 bit 0 mask. */
#define CCL_INTMODE2_0_bp  4  /* Interrupt Mode for LUT2 bit 0 position. */
#define CCL_INTMODE2_1_bm  (1<<5)  /* Interrupt Mode for LUT2 bit 1 mask. */
#define CCL_INTMODE2_1_bp  5  /* Interrupt Mode for LUT2 bit 1 position. */
#define CCL_INTMODE3_gm  0xC0  /* Interrupt Mode for LUT3 group mask. */
#define CCL_INTMODE3_gp  6  /* Interrupt Mode for LUT3 group position. */
#define CCL_INTMODE3_0_bm  (1<<6)  /* Interrupt Mode for LUT3 bit 0 mask. */
#define CCL_INTMODE3_0_bp  6  /* Interrupt Mode for LUT3 bit 0 position. */
#define CCL_INTMODE3_1_bm  (1<<7)  /* Interrupt Mode for LUT3 bit 1 mask. */
#define CCL_INTMODE3_1_bp  7  /* Interrupt Mode for LUT3 bit 1 position. */

/* CCL.INTCTRL1  bit masks and bit positions */
#define CCL_INTMODE4_gm  0x03  /* Interrupt Mode for LUT4 group mask. */
#define CCL_INTMODE4_gp  0  /* Interrupt Mode for LUT4 group position. */
#define CCL_INTMODE4_0_bm  (1<<0)  /* Interrupt Mode for LUT4 bit 0 mask. */
#define CCL_INTMODE4_0_bp  0  /* Interrupt Mode for LUT4 bit 0 position. */
#define CCL_INTMODE4_1_bm  (1<<1)  /* Interrupt Mode for LUT4 bit 1 mask. */
#define CCL_INTMODE4_1_bp  1  /* Interrupt Mode for LUT4 bit 1 position. */
#define CCL_INTMODE5_gm  0x0C  /* Interrupt Mode for LUT5 group mask. */
#define CCL_INTMODE5_gp  2  /* Interrupt Mode for LUT5 group position. */
#define CCL_INTMODE5_0_bm  (1<<2)  /* Interrupt Mode for LUT5 bit 0 mask. */
#define CCL_INTMODE5_0_bp  2  /* Interrupt Mode for LUT5 bit 0 position. */
#define CCL_INTMODE5_1_bm  (1<<3)  /* Interrupt Mode for LUT5 bit 1 mask. */
#define CCL_INTMODE5_1_bp  3  /* Interrupt Mode for LUT5 bit 1 position. */

/* CCL.INTFLAGS  bit masks and bit positions */
#define CCL_INT_gm  0x3F  /* Interrupt Flag group mask. */
#define CCL_INT_gp  0  /* Interrupt Flag group position. */
#define CCL_INT_0_bm  (1<<0)  /* Interrupt Flag bit 0 mask. */
#define CCL_INT_0_bp  0  /* Interrupt Flag bit 0 position. */
#define CCL_INT0_bm  CCL_INT_0_bm  /* This define is deprecated and should not be used */
#define CCL_INT0_bp  CCL_INT_0_bp  /* This define is deprecated and should not be used */
#define CCL_INT_1_bm  (1<<1)  /* Interrupt Flag bit 1 mask. */
#define CCL_INT_1_bp  1  /* Interrupt Flag bit 1 position. */
#define CCL_INT1_bm  CCL_INT_1_bm  /* This define is deprecated and should not be used */
#define CCL_INT1_bp  CCL_INT_1_bp  /* This define is deprecated and should not be used */
#define CCL_INT_2_bm  (1<<2)  /* Interrupt Flag bit 2 mask. */
#define CCL_INT_2_bp  2  /* Interrupt Flag bit 2 position. */
#define CCL_INT2_bm  CCL_INT_2_bm  /* This define is deprecated and should not be used */
#define CCL_INT2_bp  CCL_INT_2_bp  /* This define is deprecated and should not be used */
#define CCL_INT_3_bm  (1<<3)  /* Interrupt Flag bit 3 mask. */
#define CCL_INT_3_bp  3  /* Interrupt Flag bit 3 position. */
#define CCL_INT3_bm  CCL_INT_3_bm  /* This define is deprecated and should not be used */
#define CCL_INT3_bp  CCL_INT_3_bp  /* This define is deprecated and should not be used */
#define CCL_INT_4_bm  (1<<4)  /* Interrupt Flag bit 4 mask. */
#define CCL_INT_4_bp  4  /* Interrupt Flag bit 4 position. */
#define CCL_INT4_bm  CCL_INT_4_bm  /* This define is deprecated and should not be used */
#define CCL_INT4_bp  CCL_INT_4_bp  /* This define is deprecated and should not be used */
#define CCL_INT_5_bm  (1<<5)  /* Interrupt Flag bit 5 mask. */
#define CCL_INT_5_bp  5  /* Interrupt Flag bit 5 position. */
#define CCL_INT5_bm  CCL_INT_5_bm  /* This define is deprecated and should not be used */
#define CCL_INT5_bp  CCL_INT_5_bp  /* This define is deprecated and should not be used */

/* CCL.LUT0CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
#define CCL_CLKSRC_gm  0x0E  /* Clock Source Selection group mask. */
#define CCL_CLKSRC_gp  1  /* Clock Source Selection group position. */
#define CCL_CLKSRC_0_bm  (1<<1)  /* Clock Source Selection bit 0 mask. */
#define CCL_CLKSRC_0_bp  1  /* Clock Source Selection bit 0 position. */
#define CCL_CLKSRC_1_bm  (1<<2)  /* Clock Source Selection bit 1 mask. */
#define CCL_CLKSRC_1_bp  2  /* Clock Source Selection bit 1 position. */
#define CCL_CLKSRC_2_bm  (1<<3)  /* Clock Source Selection bit 2 mask. */
#define CCL_CLKSRC_2_bp  3  /* Clock Source Selection bit 2 position. */
#define CCL_FILTSEL_gm  0x30  /* Filter Selection group mask. */
#define CCL_FILTSEL_gp  4  /* Filter Selection group position. */
#define CCL_FILTSEL_0_bm  (1<<4)  /* Filter Selection bit 0 mask. */
#define CCL_FILTSEL_0_bp  4  /* Filter Selection bit 0 position. */
#define CCL_FILTSEL_1_bm  (1<<5)  /* Filter Selection bit 1 mask. */
#define CCL_FILTSEL_1_bp  5  /* Filter Selection bit 1 position. */
#define CCL_OUTEN_bm  0x40  /* Output Enable bit mask. */
#define CCL_OUTEN_bp  6  /* Output Enable bit position. */
#define CCL_EDGEDET_bm  0x80  /* Edge Detection Enable bit mask. */
#define CCL_EDGEDET_bp  7  /* Edge Detection Enable bit position. */

/* CCL.LUT0CTRLB  bit masks and bit positions */
#define CCL_INSEL0_gm  0x0F  /* LUT Input 0 Source Selection group mask. */
#define CCL_INSEL0_gp  0  /* LUT Input 0 Source Selection group position. */
#define CCL_INSEL0_0_bm  (1<<0)  /* LUT Input 0 Source Selection bit 0 mask. */
#define CCL_INSEL0_0_bp  0  /* LUT Input 0 Source Selection bit 0 position. */
#define CCL_INSEL0_1_bm  (1<<1)  /* LUT Input 0 Source Selection bit 1 mask. */
#define CCL_INSEL0_1_bp  1  /* LUT Input 0 Source Selection bit 1 position. */
#define CCL_INSEL0_2_bm  (1<<2)  /* LUT Input 0 Source Selection bit 2 mask. */
#define CCL_INSEL0_2_bp  2  /* LUT Input 0 Source Selection bit 2 position. */
#define CCL_INSEL0_3_bm  (1<<3)  /* LUT Input 0 Source Selection bit 3 mask. */
#define CCL_INSEL0_3_bp  3  /* LUT Input 0 Source Selection bit 3 position. */
#define CCL_INSEL1_gm  0xF0  /* LUT Input 1 Source Selection group mask. */
#define CCL_INSEL1_gp  4  /* LUT Input 1 Source Selection group position. */
#define CCL_INSEL1_0_bm  (1<<4)  /* LUT Input 1 Source Selection bit 0 mask. */
#define CCL_INSEL1_0_bp  4  /* LUT Input 1 Source Selection bit 0 position. */
#define CCL_INSEL1_1_bm  (1<<5)  /* LUT Input 1 Source Selection bit 1 mask. */
#define CCL_INSEL1_1_bp  5  /* LUT Input 1 Source Selection bit 1 position. */
#define CCL_INSEL1_2_bm  (1<<6)  /* LUT Input 1 Source Selection bit 2 mask. */
#define CCL_INSEL1_2_bp  6  /* LUT Input 1 Source Selection bit 2 position. */
#define CCL_INSEL1_3_bm  (1<<7)  /* LUT Input 1 Source Selection bit 3 mask. */
#define CCL_INSEL1_3_bp  7  /* LUT Input 1 Source Selection bit 3 position. */

/* CCL.LUT0CTRLC  bit masks and bit positions */
#define CCL_INSEL2_gm  0x0F  /* LUT Input 2 Source Selection group mask. */
#define CCL_INSEL2_gp  0  /* LUT Input 2 Source Selection group position. */
#define CCL_INSEL2_0_bm  (1<<0)  /* LUT Input 2 Source Selection bit 0 mask. */
#define CCL_INSEL2_0_bp  0  /* LUT Input 2 Source Selection bit 0 position. */
#define CCL_INSEL2_1_bm  (1<<1)  /* LUT Input 2 Source Selection bit 1 mask. */
#define CCL_INSEL2_1_bp  1  /* LUT Input 2 Source Selection bit 1 position. */
#define CCL_INSEL2_2_bm  (1<<2)  /* LUT Input 2 Source Selection bit 2 mask. */
#define CCL_INSEL2_2_bp  2  /* LUT Input 2 Source Selection bit 2 position. */
#define CCL_INSEL2_3_bm  (1<<3)  /* LUT Input 2 Source Selection bit 3 mask. */
#define CCL_INSEL2_3_bp  3  /* LUT Input 2 Source Selection bit 3 position. */

/* CCL.TRUTH0  bit masks and bit positions */
#define CCL_TRUTH_gm  0xFF  /* Truth Table group mask. */
#define CCL_TRUTH_gp  0  /* Truth Table group position. */
#define CCL_TRUTH_0_bm  (1<<0)  /* Truth Table bit 0 mask. */
#define CCL_TRUTH_0_bp  0  /* Truth Table bit 0 position. */
#define CCL_TRUTH_1_bm  (1<<1)  /* Truth Table bit 1 mask. */
#define CCL_TRUTH_1_bp  1  /* Truth Table bit 1 position. */
#define CCL_TRUTH_2_bm  (1<<2)  /* Truth Table bit 2 mask. */
#define CCL_TRUTH_2_bp  2  /* Truth Table bit 2 position. */
#define CCL_TRUTH_3_bm  (1<<3)  /* Truth Table bit 3 mask. */
#define CCL_TRUTH_3_bp  3  /* Truth Table bit 3 position. */
#define CCL_TRUTH_4_bm  (1<<4)  /* Truth Table bit 4 mask. */
#define CCL_TRUTH_4_bp  4  /* Truth Table bit 4 position. */
#define CCL_TRUTH_5_bm  (1<<5)  /* Truth Table bit 5 mask. */
#define CCL_TRUTH_5_bp  5  /* Truth Table bit 5 position. */
#define CCL_TRUTH_6_bm  (1<<6)  /* Truth Table bit 6 mask. */
#define CCL_TRUTH_6_bp  6  /* Truth Table bit 6 position. */
#define CCL_TRUTH_7_bm  (1<<7)  /* Truth Table bit 7 mask. */
#define CCL_TRUTH_7_bp  7  /* Truth Table bit 7 position. */

/* CCL.LUT1CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT1CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT1CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH1  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */

/* CCL.LUT2CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT2CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT2CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH2  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */

/* CCL.LUT3CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT3CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT3CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH3  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */

/* CCL.LUT4CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT4CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT4CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH4  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */

/* CCL.LUT5CTRLA  bit masks and bit positions */
/* CCL_ENABLE  is already defined. */
/* CCL_CLKSRC  is already defined. */
/* CCL_FILTSEL  is already defined. */
/* CCL_OUTEN  is already defined. */
/* CCL_EDGEDET  is already defined. */

/* CCL.LUT5CTRLB  bit masks and bit positions */
/* CCL_INSEL0  is already defined. */
/* CCL_INSEL1  is already defined. */

/* CCL.LUT5CTRLC  bit masks and bit positions */
/* CCL_INSEL2  is already defined. */

/* CCL.TRUTH5  bit masks and bit positions */
/* CCL_TRUTH  is already defined. */


/* CLKCTRL - Clock controller */
/* CLKCTRL.MCLKCTRLA  bit masks and bit positions */
#define CLKCTRL_CLKSEL_gm  0x0F  /* Clock Select group mask. */
#define CLKCTRL_CLKSEL_gp  0  /* Clock Select group position. */
#define CLKCTRL_CLKSEL_0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define CLKCTRL_CLKSEL_0_bp  0  /* Clock Select bit 0 position. */
#define CLKCTRL_CLKSEL_1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define CLKCTRL_CLKSEL_1_bp  1  /* Clock Select bit 1 position. */
#define CLKCTRL_CLKSEL_2_bm  (1<<2)  /* Clock Select bit 2 mask. */
#define CLKCTRL_CLKSEL_2_bp  2  /* Clock Select bit 2 position. */
#define CLKCTRL_CLKSEL_3_bm  (1<<3)  /* Clock Select bit 3 mask. */
#define CLKCTRL_CLKSEL_3_bp  3  /* Clock Select bit 3 position. */
#define CLKCTRL_CLKOUTDIV_bm  0x40  /* Clock Out Divide bit mask. */
#define CLKCTRL_CLKOUTDIV_bp  6  /* Clock Out Divide bit position. */
#define CLKCTRL_CLKOUT_bm  0x80  /* System Clock Out bit mask. */
#define CLKCTRL_CLKOUT_bp  7  /* System Clock Out bit position. */

/* CLKCTRL.MCLKCTRLB  bit masks and bit positions */
#define CLKCTRL_PEN_bm  0x01  /* Prescaler enable bit mask. */
#define CLKCTRL_PEN_bp  0  /* Prescaler enable bit position. */
#define CLKCTRL_PDIV_gm  0x1E  /* Prescaler division group mask. */
#define CLKCTRL_PDIV_gp  1  /* Prescaler division group position. */
#define CLKCTRL_PDIV_0_bm  (1<<1)  /* Prescaler division bit 0 mask. */
#define CLKCTRL_PDIV_0_bp  1  /* Prescaler division bit 0 position. */
#define CLKCTRL_PDIV_1_bm  (1<<2)  /* Prescaler division bit 1 mask. */
#define CLKCTRL_PDIV_1_bp  2  /* Prescaler division bit 1 position. */
#define CLKCTRL_PDIV_2_bm  (1<<3)  /* Prescaler division bit 2 mask. */
#define CLKCTRL_PDIV_2_bp  3  /* Prescaler division bit 2 position. */
#define CLKCTRL_PDIV_3_bm  (1<<4)  /* Prescaler division bit 3 mask. */
#define CLKCTRL_PDIV_3_bp  4  /* Prescaler division bit 3 position. */

/* CLKCTRL.MCLKCTRLC  bit masks and bit positions */
#define CLKCTRL_CFD0_bm  0x01  /* Clock Failure Inject 0 bit mask. */
#define CLKCTRL_CFD0_bp  0  /* Clock Failure Inject 0 bit position. */
#define CLKCTRL_CFD1_bm  0x02  /* Clock Failure Inject 1 bit mask. */
#define CLKCTRL_CFD1_bp  1  /* Clock Failure Inject 1 bit position. */

/* CLKCTRL.MCLKINTCTRL  bit masks and bit positions */
/* CLKCTRL_CFD0  is already defined. */
/* CLKCTRL_CFD1  is already defined. */
#define CLKCTRL_CFM0_bm  0x04  /* Clock Measurement Failure Detected 0 bit mask. */
#define CLKCTRL_CFM0_bp  2  /* Clock Measurement Failure Detected 0 bit position. */
#define CLKCTRL_CFM1_bm  0x08  /* Clock Measurement Failure Detected 1 bit mask. */
#define CLKCTRL_CFM1_bp  3  /* Clock Measurement Failure Detected 1 bit position. */
#define CLKCTRL_CFMD0_bm  0x10  /* Clock Measurement Done 0 bit mask. */
#define CLKCTRL_CFMD0_bp  4  /* Clock Measurement Done 0 bit position. */
#define CLKCTRL_CFMD1_bm  0x20  /* Clock Measurement Done 1 bit mask. */
#define CLKCTRL_CFMD1_bp  5  /* Clock Measurement Done 1 bit position. */

/* CLKCTRL.MCLKINTFLAGS  bit masks and bit positions */
/* CLKCTRL_CFD0  is already defined. */
/* CLKCTRL_CFD1  is already defined. */
/* CLKCTRL_CFM0  is already defined. */
/* CLKCTRL_CFM1  is already defined. */
/* CLKCTRL_CFMD0  is already defined. */
/* CLKCTRL_CFMD1  is already defined. */

/* CLKCTRL.MCLKSTATUS  bit masks and bit positions */
#define CLKCTRL_SOSC_bm  0x01  /* System Oscillator Changing bit mask. */
#define CLKCTRL_SOSC_bp  0  /* System Oscillator Changing bit position. */
#define CLKCTRL_OSCHFS_bm  0x02  /* High Frequency Oscillator Status bit mask. */
#define CLKCTRL_OSCHFS_bp  1  /* High Frequency Oscillator Status bit position. */
#define CLKCTRL_OSC32KS_bm  0x04  /* 32KHz Oscillator Status bit mask. */
#define CLKCTRL_OSC32KS_bp  2  /* 32KHz Oscillator Status bit position. */
#define CLKCTRL_XOSC32KS_bm  0x08  /* 32.768 kHz Crystal Oscillator Status bit mask. */
#define CLKCTRL_XOSC32KS_bp  3  /* 32.768 kHz Crystal Oscillator Status bit position. */
#define CLKCTRL_EXTS_bm  0x10  /* External Clock Status bit mask. */
#define CLKCTRL_EXTS_bp  4  /* External Clock Status bit position. */
#define CLKCTRL_PLLS_bm  0x20  /* PLL Oscillator Status bit mask. */
#define CLKCTRL_PLLS_bp  5  /* PLL Oscillator Status bit position. */

/* CLKCTRL.MCLKTIMEBASE  bit masks and bit positions */
#define CLKCTRL_TIMEBASE_gm  0x1F  /* Timebase group mask. */
#define CLKCTRL_TIMEBASE_gp  0  /* Timebase group position. */
#define CLKCTRL_TIMEBASE_0_bm  (1<<0)  /* Timebase bit 0 mask. */
#define CLKCTRL_TIMEBASE_0_bp  0  /* Timebase bit 0 position. */
#define CLKCTRL_TIMEBASE_1_bm  (1<<1)  /* Timebase bit 1 mask. */
#define CLKCTRL_TIMEBASE_1_bp  1  /* Timebase bit 1 position. */
#define CLKCTRL_TIMEBASE_2_bm  (1<<2)  /* Timebase bit 2 mask. */
#define CLKCTRL_TIMEBASE_2_bp  2  /* Timebase bit 2 position. */
#define CLKCTRL_TIMEBASE_3_bm  (1<<3)  /* Timebase bit 3 mask. */
#define CLKCTRL_TIMEBASE_3_bp  3  /* Timebase bit 3 position. */
#define CLKCTRL_TIMEBASE_4_bm  (1<<4)  /* Timebase bit 4 mask. */
#define CLKCTRL_TIMEBASE_4_bp  4  /* Timebase bit 4 position. */

/* CLKCTRL.MCLKCFD0CTRLA  bit masks and bit positions */
#define CLKCTRL_CFDEN_bm  0x01  /* Clock Failure Detect Enable bit mask. */
#define CLKCTRL_CFDEN_bp  0  /* Clock Failure Detect Enable bit position. */
#define CLKCTRL_CFDREF_gm  0x06  /* Clock Failure Detect Reference group mask. */
#define CLKCTRL_CFDREF_gp  1  /* Clock Failure Detect Reference group position. */
#define CLKCTRL_CFDREF_0_bm  (1<<1)  /* Clock Failure Detect Reference bit 0 mask. */
#define CLKCTRL_CFDREF_0_bp  1  /* Clock Failure Detect Reference bit 0 position. */
#define CLKCTRL_CFDREF_1_bm  (1<<2)  /* Clock Failure Detect Reference bit 1 mask. */
#define CLKCTRL_CFDREF_1_bp  2  /* Clock Failure Detect Reference bit 1 position. */
#define CLKCTRL_CFDSRC_gm  0x38  /* Clock Failure Detect Source group mask. */
#define CLKCTRL_CFDSRC_gp  3  /* Clock Failure Detect Source group position. */
#define CLKCTRL_CFDSRC_0_bm  (1<<3)  /* Clock Failure Detect Source bit 0 mask. */
#define CLKCTRL_CFDSRC_0_bp  3  /* Clock Failure Detect Source bit 0 position. */
#define CLKCTRL_CFDSRC_1_bm  (1<<4)  /* Clock Failure Detect Source bit 1 mask. */
#define CLKCTRL_CFDSRC_1_bp  4  /* Clock Failure Detect Source bit 1 position. */
#define CLKCTRL_CFDSRC_2_bm  (1<<5)  /* Clock Failure Detect Source bit 2 mask. */
#define CLKCTRL_CFDSRC_2_bp  5  /* Clock Failure Detect Source bit 2 position. */

/* CLKCTRL.MCLKCFD1CTRLA  bit masks and bit positions */
/* CLKCTRL_CFDEN  is already defined. */
/* CLKCTRL_CFDREF  is already defined. */
/* CLKCTRL_CFDSRC  is already defined. */

/* CLKCTRL.MCLKCFM0CTRLA  bit masks and bit positions */
#define CLKCTRL_MEN_bm  0x01  /* Measurement Enable bit mask. */
#define CLKCTRL_MEN_bp  0  /* Measurement Enable bit position. */
#define CLKCTRL_CFMSRC_gm  0x0E  /* CFM Clock Reference group mask. */
#define CLKCTRL_CFMSRC_gp  1  /* CFM Clock Reference group position. */
#define CLKCTRL_CFMSRC_0_bm  (1<<1)  /* CFM Clock Reference bit 0 mask. */
#define CLKCTRL_CFMSRC_0_bp  1  /* CFM Clock Reference bit 0 position. */
#define CLKCTRL_CFMSRC_1_bm  (1<<2)  /* CFM Clock Reference bit 1 mask. */
#define CLKCTRL_CFMSRC_1_bp  2  /* CFM Clock Reference bit 1 position. */
#define CLKCTRL_CFMSRC_2_bm  (1<<3)  /* CFM Clock Reference bit 2 mask. */
#define CLKCTRL_CFMSRC_2_bp  3  /* CFM Clock Reference bit 2 position. */
#define CLKCTRL_TYPE_bm  0x10  /* Measurement Type bit mask. */
#define CLKCTRL_TYPE_bp  4  /* Measurement Type bit position. */

/* CLKCTRL.MCLKCFM0CTRLB  bit masks and bit positions */
#define CLKCTRL_REFCEN_bm  0x01  /* Reference Clock Enable bit mask. */
#define CLKCTRL_REFCEN_bp  0  /* Reference Clock Enable bit position. */
#define CLKCTRL_CFMREF_gm  0x06  /* CFM Reference Source group mask. */
#define CLKCTRL_CFMREF_gp  1  /* CFM Reference Source group position. */
#define CLKCTRL_CFMREF_0_bm  (1<<1)  /* CFM Reference Source bit 0 mask. */
#define CLKCTRL_CFMREF_0_bp  1  /* CFM Reference Source bit 0 position. */
#define CLKCTRL_CFMREF_1_bm  (1<<2)  /* CFM Reference Source bit 1 mask. */
#define CLKCTRL_CFMREF_1_bp  2  /* CFM Reference Source bit 1 position. */

/* CLKCTRL.MCLKCFM1CTRLA  bit masks and bit positions */
/* CLKCTRL_MEN  is already defined. */
/* CLKCTRL_CFMSRC  is already defined. */
/* CLKCTRL_TYPE  is already defined. */

/* CLKCTRL.MCLKCFM1CTRLB  bit masks and bit positions */
/* CLKCTRL_REFCEN  is already defined. */
/* CLKCTRL_CFMREF  is already defined. */

/* CLKCTRL.OSCHFCTRLA  bit masks and bit positions */
#define CLKCTRL_AUTOTUNE_bm  0x01  /* Autotune bit mask. */
#define CLKCTRL_AUTOTUNE_bp  0  /* Autotune bit position. */
#define CLKCTRL_FRQSEL_gm  0x3C  /* Frequency select group mask. */
#define CLKCTRL_FRQSEL_gp  2  /* Frequency select group position. */
#define CLKCTRL_FRQSEL_0_bm  (1<<2)  /* Frequency select bit 0 mask. */
#define CLKCTRL_FRQSEL_0_bp  2  /* Frequency select bit 0 position. */
#define CLKCTRL_FRQSEL_1_bm  (1<<3)  /* Frequency select bit 1 mask. */
#define CLKCTRL_FRQSEL_1_bp  3  /* Frequency select bit 1 position. */
#define CLKCTRL_FRQSEL_2_bm  (1<<4)  /* Frequency select bit 2 mask. */
#define CLKCTRL_FRQSEL_2_bp  4  /* Frequency select bit 2 position. */
#define CLKCTRL_FRQSEL_3_bm  (1<<5)  /* Frequency select bit 3 mask. */
#define CLKCTRL_FRQSEL_3_bp  5  /* Frequency select bit 3 position. */
#define CLKCTRL_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define CLKCTRL_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* CLKCTRL.OSCHFTUNE  bit masks and bit positions */
#define CLKCTRL_TUNE_gm  0xFF  /* Oscillator Tune group mask. */
#define CLKCTRL_TUNE_gp  0  /* Oscillator Tune group position. */
#define CLKCTRL_TUNE_0_bm  (1<<0)  /* Oscillator Tune bit 0 mask. */
#define CLKCTRL_TUNE_0_bp  0  /* Oscillator Tune bit 0 position. */
#define CLKCTRL_TUNE_1_bm  (1<<1)  /* Oscillator Tune bit 1 mask. */
#define CLKCTRL_TUNE_1_bp  1  /* Oscillator Tune bit 1 position. */
#define CLKCTRL_TUNE_2_bm  (1<<2)  /* Oscillator Tune bit 2 mask. */
#define CLKCTRL_TUNE_2_bp  2  /* Oscillator Tune bit 2 position. */
#define CLKCTRL_TUNE_3_bm  (1<<3)  /* Oscillator Tune bit 3 mask. */
#define CLKCTRL_TUNE_3_bp  3  /* Oscillator Tune bit 3 position. */
#define CLKCTRL_TUNE_4_bm  (1<<4)  /* Oscillator Tune bit 4 mask. */
#define CLKCTRL_TUNE_4_bp  4  /* Oscillator Tune bit 4 position. */
#define CLKCTRL_TUNE_5_bm  (1<<5)  /* Oscillator Tune bit 5 mask. */
#define CLKCTRL_TUNE_5_bp  5  /* Oscillator Tune bit 5 position. */
#define CLKCTRL_TUNE_6_bm  (1<<6)  /* Oscillator Tune bit 6 mask. */
#define CLKCTRL_TUNE_6_bp  6  /* Oscillator Tune bit 6 position. */
#define CLKCTRL_TUNE_7_bm  (1<<7)  /* Oscillator Tune bit 7 mask. */
#define CLKCTRL_TUNE_7_bp  7  /* Oscillator Tune bit 7 position. */

/* CLKCTRL.PLLCTRLA  bit masks and bit positions */
#define CLKCTRL_MULFAC_gm  0x03  /* Multiplication Factor group mask. */
#define CLKCTRL_MULFAC_gp  0  /* Multiplication Factor group position. */
#define CLKCTRL_MULFAC_0_bm  (1<<0)  /* Multiplication Factor bit 0 mask. */
#define CLKCTRL_MULFAC_0_bp  0  /* Multiplication Factor bit 0 position. */
#define CLKCTRL_MULFAC_1_bm  (1<<1)  /* Multiplication Factor bit 1 mask. */
#define CLKCTRL_MULFAC_1_bp  1  /* Multiplication Factor bit 1 position. */
#define CLKCTRL_SOURCE_bm  0x40  /* Source bit mask. */
#define CLKCTRL_SOURCE_bp  6  /* Source bit position. */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.OSC32KCTRLA  bit masks and bit positions */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSC32KCTRLA  bit masks and bit positions */
#define CLKCTRL_ENABLE_bm  0x01  /* Enable bit mask. */
#define CLKCTRL_ENABLE_bp  0  /* Enable bit position. */
#define CLKCTRL_LPMODE_bm  0x02  /* Low-power Mode bit mask. */
#define CLKCTRL_LPMODE_bp  1  /* Low-power Mode bit position. */
#define CLKCTRL_SEL_bm  0x04  /* Crystal Selection bit mask. */
#define CLKCTRL_SEL_bp  2  /* Crystal Selection bit position. */
#define CLKCTRL_CSUT_gm  0x30  /* Crystal Oscillator Startup Time group mask. */
#define CLKCTRL_CSUT_gp  4  /* Crystal Oscillator Startup Time group position. */
#define CLKCTRL_CSUT_0_bm  (1<<4)  /* Crystal Oscillator Startup Time bit 0 mask. */
#define CLKCTRL_CSUT_0_bp  4  /* Crystal Oscillator Startup Time bit 0 position. */
#define CLKCTRL_CSUT_1_bm  (1<<5)  /* Crystal Oscillator Startup Time bit 1 mask. */
#define CLKCTRL_CSUT_1_bp  5  /* Crystal Oscillator Startup Time bit 1 position. */
/* CLKCTRL_RUNSTDBY  is already defined. */

/* CLKCTRL.XOSCHFCTRLA  bit masks and bit positions */
/* CLKCTRL_ENABLE  is already defined. */
#define CLKCTRL_SELHF_bm  0x02  /* External Source Select bit mask. */
#define CLKCTRL_SELHF_bp  1  /* External Source Select bit position. */
#define CLKCTRL_FRQRANGE_gm  0x0C  /* Frequency Range group mask. */
#define CLKCTRL_FRQRANGE_gp  2  /* Frequency Range group position. */
#define CLKCTRL_FRQRANGE_0_bm  (1<<2)  /* Frequency Range bit 0 mask. */
#define CLKCTRL_FRQRANGE_0_bp  2  /* Frequency Range bit 0 position. */
#define CLKCTRL_FRQRANGE_1_bm  (1<<3)  /* Frequency Range bit 1 mask. */
#define CLKCTRL_FRQRANGE_1_bp  3  /* Frequency Range bit 1 position. */
#define CLKCTRL_CSUTHF_gm  0x30  /* Start-up Time group mask. */
#define CLKCTRL_CSUTHF_gp  4  /* Start-up Time group position. */
#define CLKCTRL_CSUTHF_0_bm  (1<<4)  /* Start-up Time bit 0 mask. */
#define CLKCTRL_CSUTHF_0_bp  4  /* Start-up Time bit 0 position. */
#define CLKCTRL_CSUTHF_1_bm  (1<<5)  /* Start-up Time bit 1 mask. */
#define CLKCTRL_CSUTHF_1_bp  5  /* Start-up Time bit 1 position. */
/* CLKCTRL_RUNSTDBY  is already defined. */


/* CPU - CPU */
/* CPU.CCP  bit masks and bit positions */
#define CPU_CCP_gm  0xFF  /* CCP signature group mask. */
#define CPU_CCP_gp  0  /* CCP signature group position. */
#define CPU_CCP_0_bm  (1<<0)  /* CCP signature bit 0 mask. */
#define CPU_CCP_0_bp  0  /* CCP signature bit 0 position. */
#define CPU_CCP_1_bm  (1<<1)  /* CCP signature bit 1 mask. */
#define CPU_CCP_1_bp  1  /* CCP signature bit 1 position. */
#define CPU_CCP_2_bm  (1<<2)  /* CCP signature bit 2 mask. */
#define CPU_CCP_2_bp  2  /* CCP signature bit 2 position. */
#define CPU_CCP_3_bm  (1<<3)  /* CCP signature bit 3 mask. */
#define CPU_CCP_3_bp  3  /* CCP signature bit 3 position. */
#define CPU_CCP_4_bm  (1<<4)  /* CCP signature bit 4 mask. */
#define CPU_CCP_4_bp  4  /* CCP signature bit 4 position. */
#define CPU_CCP_5_bm  (1<<5)  /* CCP signature bit 5 mask. */
#define CPU_CCP_5_bp  5  /* CCP signature bit 5 position. */
#define CPU_CCP_6_bm  (1<<6)  /* CCP signature bit 6 mask. */
#define CPU_CCP_6_bp  6  /* CCP signature bit 6 position. */
#define CPU_CCP_7_bm  (1<<7)  /* CCP signature bit 7 mask. */
#define CPU_CCP_7_bp  7  /* CCP signature bit 7 position. */

/* CPU.CTRLA  bit masks and bit positions */
#define CPU_SPLOCK_bm  0x01  /* SPLIM Lock bit mask. */
#define CPU_SPLOCK_bp  0  /* SPLIM Lock bit position. */
#define CPU_INJPIC_bm  0x02  /* Inject Parity Error on Instruction Bus Control bit mask. */
#define CPU_INJPIC_bp  1  /* Inject Parity Error on Instruction Bus Control bit position. */
#define CPU_INJPIA_bm  0x04  /* Inject Parity Error on Instruction Bus Address bit mask. */
#define CPU_INJPIA_bp  2  /* Inject Parity Error on Instruction Bus Address bit position. */
#define CPU_INJPDC_bm  0x08  /* Inject Parity Error on Data Bus Control bit mask. */
#define CPU_INJPDC_bp  3  /* Inject Parity Error on Data Bus Control bit position. */
#define CPU_INJPDA_bm  0x10  /* Inject Parity Error on Data Bus Address bit mask. */
#define CPU_INJPDA_bp  4  /* Inject Parity Error on Data Bus Address bit position. */
#define CPU_INJPDD_bm  0x20  /* Inject Parity Error on Data Bus Data bit mask. */
#define CPU_INJPDD_bp  5  /* Inject Parity Error on Data Bus Data bit position. */
#define CPU_INJCOMP_bm  0x40  /* Inject Comparator Error bit mask. */
#define CPU_INJCOMP_bp  6  /* Inject Comparator Error bit position. */
#define CPU_NMIDIS_bm  0x80  /* Disable NMI Request bit mask. */
#define CPU_NMIDIS_bp  7  /* Disable NMI Request bit position. */

/* CPU.INTFLAGS  bit masks and bit positions */
#define CPU_OPC_bm  0x01  /* Illegal Opcode Error bit mask. */
#define CPU_OPC_bp  0  /* Illegal Opcode Error bit position. */
#define CPU_BUSERR_bm  0x02  /* Bus Error bit mask. */
#define CPU_BUSERR_bp  1  /* Bus Error bit position. */
#define CPU_SPLIM_bm  0x04  /* Stack Pointer Limit Error bit mask. */
#define CPU_SPLIM_bp  2  /* Stack Pointer Limit Error bit position. */
#define CPU_PARITYD_bm  0x08  /* Parity Error on Data Bus bit mask. */
#define CPU_PARITYD_bp  3  /* Parity Error on Data Bus bit position. */
#define CPU_PARITYI_bm  0x10  /* Parity Error on Instruction Bus bit mask. */
#define CPU_PARITYI_bp  4  /* Parity Error on Instruction Bus bit position. */

/* CPU.SREG  bit masks and bit positions */
#define CPU_C_bm  0x01  /* Carry Flag bit mask. */
#define CPU_C_bp  0  /* Carry Flag bit position. */
#define CPU_Z_bm  0x02  /* Zero Flag bit mask. */
#define CPU_Z_bp  1  /* Zero Flag bit position. */
#define CPU_N_bm  0x04  /* Negative Flag bit mask. */
#define CPU_N_bp  2  /* Negative Flag bit position. */
#define CPU_V_bm  0x08  /* Two's Complement Overflow Flag bit mask. */
#define CPU_V_bp  3  /* Two's Complement Overflow Flag bit position. */
#define CPU_S_bm  0x10  /* N Exclusive Or V Flag bit mask. */
#define CPU_S_bp  4  /* N Exclusive Or V Flag bit position. */
#define CPU_H_bm  0x20  /* Half Carry Flag bit mask. */
#define CPU_H_bp  5  /* Half Carry Flag bit position. */
#define CPU_T_bm  0x40  /* Transfer Bit bit mask. */
#define CPU_T_bp  6  /* Transfer Bit bit position. */
#define CPU_I_bm  0x80  /* Global Interrupt Enable Flag bit mask. */
#define CPU_I_bp  7  /* Global Interrupt Enable Flag bit position. */


/* CPUINT - Interrupt Controller */
/* CPUINT.CTRLA  bit masks and bit positions */
#define CPUINT_LVL0RR_bm  0x01  /* Round-robin Scheduling Enable bit mask. */
#define CPUINT_LVL0RR_bp  0  /* Round-robin Scheduling Enable bit position. */
#define CPUINT_CVT_bm  0x20  /* Compact Vector Table bit mask. */
#define CPUINT_CVT_bp  5  /* Compact Vector Table bit position. */
#define CPUINT_IVSEL_bm  0x40  /* Interrupt Vector Select bit mask. */
#define CPUINT_IVSEL_bp  6  /* Interrupt Vector Select bit position. */

/* CPUINT.STATUS  bit masks and bit positions */
#define CPUINT_LVL0EX_bm  0x01  /* Level 0 Interrupt Executing bit mask. */
#define CPUINT_LVL0EX_bp  0  /* Level 0 Interrupt Executing bit position. */
#define CPUINT_LVL1EX_bm  0x02  /* Level 1 Interrupt Executing bit mask. */
#define CPUINT_LVL1EX_bp  1  /* Level 1 Interrupt Executing bit position. */
#define CPUINT_NMIEX_bm  0x80  /* Non-maskable Interrupt Executing bit mask. */
#define CPUINT_NMIEX_bp  7  /* Non-maskable Interrupt Executing bit position. */

/* CPUINT.LVL0PRI  bit masks and bit positions */
#define CPUINT_LVL0PRI_gm  0xFF  /* Interrupt Level Priority group mask. */
#define CPUINT_LVL0PRI_gp  0  /* Interrupt Level Priority group position. */
#define CPUINT_LVL0PRI_0_bm  (1<<0)  /* Interrupt Level Priority bit 0 mask. */
#define CPUINT_LVL0PRI_0_bp  0  /* Interrupt Level Priority bit 0 position. */
#define CPUINT_LVL0PRI_1_bm  (1<<1)  /* Interrupt Level Priority bit 1 mask. */
#define CPUINT_LVL0PRI_1_bp  1  /* Interrupt Level Priority bit 1 position. */
#define CPUINT_LVL0PRI_2_bm  (1<<2)  /* Interrupt Level Priority bit 2 mask. */
#define CPUINT_LVL0PRI_2_bp  2  /* Interrupt Level Priority bit 2 position. */
#define CPUINT_LVL0PRI_3_bm  (1<<3)  /* Interrupt Level Priority bit 3 mask. */
#define CPUINT_LVL0PRI_3_bp  3  /* Interrupt Level Priority bit 3 position. */
#define CPUINT_LVL0PRI_4_bm  (1<<4)  /* Interrupt Level Priority bit 4 mask. */
#define CPUINT_LVL0PRI_4_bp  4  /* Interrupt Level Priority bit 4 position. */
#define CPUINT_LVL0PRI_5_bm  (1<<5)  /* Interrupt Level Priority bit 5 mask. */
#define CPUINT_LVL0PRI_5_bp  5  /* Interrupt Level Priority bit 5 position. */
#define CPUINT_LVL0PRI_6_bm  (1<<6)  /* Interrupt Level Priority bit 6 mask. */
#define CPUINT_LVL0PRI_6_bp  6  /* Interrupt Level Priority bit 6 position. */
#define CPUINT_LVL0PRI_7_bm  (1<<7)  /* Interrupt Level Priority bit 7 mask. */
#define CPUINT_LVL0PRI_7_bp  7  /* Interrupt Level Priority bit 7 position. */

/* CPUINT.LVL1VEC  bit masks and bit positions */
#define CPUINT_LVL1VEC_gm  0xFF  /* Interrupt Vector with High Priority group mask. */
#define CPUINT_LVL1VEC_gp  0  /* Interrupt Vector with High Priority group position. */
#define CPUINT_LVL1VEC_0_bm  (1<<0)  /* Interrupt Vector with High Priority bit 0 mask. */
#define CPUINT_LVL1VEC_0_bp  0  /* Interrupt Vector with High Priority bit 0 position. */
#define CPUINT_LVL1VEC_1_bm  (1<<1)  /* Interrupt Vector with High Priority bit 1 mask. */
#define CPUINT_LVL1VEC_1_bp  1  /* Interrupt Vector with High Priority bit 1 position. */
#define CPUINT_LVL1VEC_2_bm  (1<<2)  /* Interrupt Vector with High Priority bit 2 mask. */
#define CPUINT_LVL1VEC_2_bp  2  /* Interrupt Vector with High Priority bit 2 position. */
#define CPUINT_LVL1VEC_3_bm  (1<<3)  /* Interrupt Vector with High Priority bit 3 mask. */
#define CPUINT_LVL1VEC_3_bp  3  /* Interrupt Vector with High Priority bit 3 position. */
#define CPUINT_LVL1VEC_4_bm  (1<<4)  /* Interrupt Vector with High Priority bit 4 mask. */
#define CPUINT_LVL1VEC_4_bp  4  /* Interrupt Vector with High Priority bit 4 position. */
#define CPUINT_LVL1VEC_5_bm  (1<<5)  /* Interrupt Vector with High Priority bit 5 mask. */
#define CPUINT_LVL1VEC_5_bp  5  /* Interrupt Vector with High Priority bit 5 position. */
#define CPUINT_LVL1VEC_6_bm  (1<<6)  /* Interrupt Vector with High Priority bit 6 mask. */
#define CPUINT_LVL1VEC_6_bp  6  /* Interrupt Vector with High Priority bit 6 position. */
#define CPUINT_LVL1VEC_7_bm  (1<<7)  /* Interrupt Vector with High Priority bit 7 mask. */
#define CPUINT_LVL1VEC_7_bp  7  /* Interrupt Vector with High Priority bit 7 position. */


/* CRCSCAN - CRCSCAN */
/* CRCSCAN.CTRLA  bit masks and bit positions */
#define CRCSCAN_ENABLE_bm  0x01  /* Enable CRCSCAN bit mask. */
#define CRCSCAN_ENABLE_bp  0  /* Enable CRCSCAN bit position. */
#define CRCSCAN_NMIEN_bm  0x02  /* Enable NMI Trigger bit mask. */
#define CRCSCAN_NMIEN_bp  1  /* Enable NMI Trigger bit position. */
#define CRCSCAN_CRCSEL_bm  0x08  /* CRC Mode Select bit mask. */
#define CRCSCAN_CRCSEL_bp  3  /* CRC Mode Select bit position. */
#define CRCSCAN_PEREN_bm  0x10  /* Enable Periodic Timer bit mask. */
#define CRCSCAN_PEREN_bp  4  /* Enable Periodic Timer bit position. */
#define CRCSCAN_SRC_gm  0x60  /* CRC Source group mask. */
#define CRCSCAN_SRC_gp  5  /* CRC Source group position. */
#define CRCSCAN_SRC_0_bm  (1<<5)  /* CRC Source bit 0 mask. */
#define CRCSCAN_SRC_0_bp  5  /* CRC Source bit 0 position. */
#define CRCSCAN_SRC_1_bm  (1<<6)  /* CRC Source bit 1 mask. */
#define CRCSCAN_SRC_1_bp  6  /* CRC Source bit 1 position. */
#define CRCSCAN_RESET_bm  0x80  /* Reset CRCSCAN bit mask. */
#define CRCSCAN_RESET_bp  7  /* Reset CRCSCAN bit position. */

/* CRCSCAN.CTRLB  bit masks and bit positions */
#define CRCSCAN_EINJ_bm  0x01  /* Inject CRC error bit mask. */
#define CRCSCAN_EINJ_bp  0  /* Inject CRC error bit position. */

/* CRCSCAN.INTCTRL  bit masks and bit positions */
#define CRCSCAN_DONE_bm  0x01  /* Scan Done Interrupt Enable bit mask. */
#define CRCSCAN_DONE_bp  0  /* Scan Done Interrupt Enable bit position. */
#define CRCSCAN_PERIOD_bm  0x02  /* Scan Period Done Interrupt Enable bit mask. */
#define CRCSCAN_PERIOD_bp  1  /* Scan Period Done Interrupt Enable bit position. */

/* CRCSCAN.INTFLAGS  bit masks and bit positions */
/* CRCSCAN_DONE  is already defined. */
/* CRCSCAN_PERIOD  is already defined. */

/* CRCSCAN.STATUSA  bit masks and bit positions */
#define CRCSCAN_ERROR_bm  0x01  /* Error Signal driving NMI bit mask. */
#define CRCSCAN_ERROR_bp  0  /* Error Signal driving NMI bit position. */
#define CRCSCAN_BUSY_bm  0x02  /* CRC BUSY bit mask. */
#define CRCSCAN_BUSY_bp  1  /* CRC BUSY bit position. */
#define CRCSCAN_OK_bm  0x04  /* CRC OK bit mask. */
#define CRCSCAN_OK_bp  2  /* CRC OK bit position. */

/* CRCSCAN.SCANADR  bit masks and bit positions */
#define CRCSCAN_SCANADR_gm  0xFF  /* Address Being Scanned group mask. */
#define CRCSCAN_SCANADR_gp  0  /* Address Being Scanned group position. */
#define CRCSCAN_SCANADR_0_bm  (1<<0)  /* Address Being Scanned bit 0 mask. */
#define CRCSCAN_SCANADR_0_bp  0  /* Address Being Scanned bit 0 position. */
#define CRCSCAN_SCANADR_1_bm  (1<<1)  /* Address Being Scanned bit 1 mask. */
#define CRCSCAN_SCANADR_1_bp  1  /* Address Being Scanned bit 1 position. */
#define CRCSCAN_SCANADR_2_bm  (1<<2)  /* Address Being Scanned bit 2 mask. */
#define CRCSCAN_SCANADR_2_bp  2  /* Address Being Scanned bit 2 position. */
#define CRCSCAN_SCANADR_3_bm  (1<<3)  /* Address Being Scanned bit 3 mask. */
#define CRCSCAN_SCANADR_3_bp  3  /* Address Being Scanned bit 3 position. */
#define CRCSCAN_SCANADR_4_bm  (1<<4)  /* Address Being Scanned bit 4 mask. */
#define CRCSCAN_SCANADR_4_bp  4  /* Address Being Scanned bit 4 position. */
#define CRCSCAN_SCANADR_5_bm  (1<<5)  /* Address Being Scanned bit 5 mask. */
#define CRCSCAN_SCANADR_5_bp  5  /* Address Being Scanned bit 5 position. */
#define CRCSCAN_SCANADR_6_bm  (1<<6)  /* Address Being Scanned bit 6 mask. */
#define CRCSCAN_SCANADR_6_bp  6  /* Address Being Scanned bit 6 position. */
#define CRCSCAN_SCANADR_7_bm  (1<<7)  /* Address Being Scanned bit 7 mask. */
#define CRCSCAN_SCANADR_7_bp  7  /* Address Being Scanned bit 7 position. */

/* CRCSCAN.DATA  bit masks and bit positions */
#define CRCSCAN_DATA_gm  0xFF  /* Input Data group mask. */
#define CRCSCAN_DATA_gp  0  /* Input Data group position. */
#define CRCSCAN_DATA_0_bm  (1<<0)  /* Input Data bit 0 mask. */
#define CRCSCAN_DATA_0_bp  0  /* Input Data bit 0 position. */
#define CRCSCAN_DATA_1_bm  (1<<1)  /* Input Data bit 1 mask. */
#define CRCSCAN_DATA_1_bp  1  /* Input Data bit 1 position. */
#define CRCSCAN_DATA_2_bm  (1<<2)  /* Input Data bit 2 mask. */
#define CRCSCAN_DATA_2_bp  2  /* Input Data bit 2 position. */
#define CRCSCAN_DATA_3_bm  (1<<3)  /* Input Data bit 3 mask. */
#define CRCSCAN_DATA_3_bp  3  /* Input Data bit 3 position. */
#define CRCSCAN_DATA_4_bm  (1<<4)  /* Input Data bit 4 mask. */
#define CRCSCAN_DATA_4_bp  4  /* Input Data bit 4 position. */
#define CRCSCAN_DATA_5_bm  (1<<5)  /* Input Data bit 5 mask. */
#define CRCSCAN_DATA_5_bp  5  /* Input Data bit 5 position. */
#define CRCSCAN_DATA_6_bm  (1<<6)  /* Input Data bit 6 mask. */
#define CRCSCAN_DATA_6_bp  6  /* Input Data bit 6 position. */
#define CRCSCAN_DATA_7_bm  (1<<7)  /* Input Data bit 7 mask. */
#define CRCSCAN_DATA_7_bp  7  /* Input Data bit 7 position. */

/* CRCSCAN.CRC  bit masks and bit positions */
#define CRCSCAN_CRC_gm  0xFFFFFFFF  /* CRC Result group mask. */
#define CRCSCAN_CRC_gp  0  /* CRC Result group position. */
#define CRCSCAN_CRC_0_bm  (1<<0)  /* CRC Result bit 0 mask. */
#define CRCSCAN_CRC_0_bp  0  /* CRC Result bit 0 position. */
#define CRCSCAN_CRC_1_bm  (1<<1)  /* CRC Result bit 1 mask. */
#define CRCSCAN_CRC_1_bp  1  /* CRC Result bit 1 position. */
#define CRCSCAN_CRC_2_bm  (1<<2)  /* CRC Result bit 2 mask. */
#define CRCSCAN_CRC_2_bp  2  /* CRC Result bit 2 position. */
#define CRCSCAN_CRC_3_bm  (1<<3)  /* CRC Result bit 3 mask. */
#define CRCSCAN_CRC_3_bp  3  /* CRC Result bit 3 position. */
#define CRCSCAN_CRC_4_bm  (1<<4)  /* CRC Result bit 4 mask. */
#define CRCSCAN_CRC_4_bp  4  /* CRC Result bit 4 position. */
#define CRCSCAN_CRC_5_bm  (1<<5)  /* CRC Result bit 5 mask. */
#define CRCSCAN_CRC_5_bp  5  /* CRC Result bit 5 position. */
#define CRCSCAN_CRC_6_bm  (1<<6)  /* CRC Result bit 6 mask. */
#define CRCSCAN_CRC_6_bp  6  /* CRC Result bit 6 position. */
#define CRCSCAN_CRC_7_bm  (1<<7)  /* CRC Result bit 7 mask. */
#define CRCSCAN_CRC_7_bp  7  /* CRC Result bit 7 position. */
#define CRCSCAN_CRC_8_bm  (1<<8)  /* CRC Result bit 8 mask. */
#define CRCSCAN_CRC_8_bp  8  /* CRC Result bit 8 position. */
#define CRCSCAN_CRC_9_bm  (1<<9)  /* CRC Result bit 9 mask. */
#define CRCSCAN_CRC_9_bp  9  /* CRC Result bit 9 position. */
#define CRCSCAN_CRC_10_bm  (1<<10)  /* CRC Result bit 10 mask. */
#define CRCSCAN_CRC_10_bp  10  /* CRC Result bit 10 position. */
#define CRCSCAN_CRC_11_bm  (1<<11)  /* CRC Result bit 11 mask. */
#define CRCSCAN_CRC_11_bp  11  /* CRC Result bit 11 position. */
#define CRCSCAN_CRC_12_bm  (1<<12)  /* CRC Result bit 12 mask. */
#define CRCSCAN_CRC_12_bp  12  /* CRC Result bit 12 position. */
#define CRCSCAN_CRC_13_bm  (1<<13)  /* CRC Result bit 13 mask. */
#define CRCSCAN_CRC_13_bp  13  /* CRC Result bit 13 position. */
#define CRCSCAN_CRC_14_bm  (1<<14)  /* CRC Result bit 14 mask. */
#define CRCSCAN_CRC_14_bp  14  /* CRC Result bit 14 position. */
#define CRCSCAN_CRC_15_bm  (1<<15)  /* CRC Result bit 15 mask. */
#define CRCSCAN_CRC_15_bp  15  /* CRC Result bit 15 position. */
#define CRCSCAN_CRC_16_bm  (1<<16)  /* CRC Result bit 16 mask. */
#define CRCSCAN_CRC_16_bp  16  /* CRC Result bit 16 position. */
#define CRCSCAN_CRC_17_bm  (1<<17)  /* CRC Result bit 17 mask. */
#define CRCSCAN_CRC_17_bp  17  /* CRC Result bit 17 position. */
#define CRCSCAN_CRC_18_bm  (1<<18)  /* CRC Result bit 18 mask. */
#define CRCSCAN_CRC_18_bp  18  /* CRC Result bit 18 position. */
#define CRCSCAN_CRC_19_bm  (1<<19)  /* CRC Result bit 19 mask. */
#define CRCSCAN_CRC_19_bp  19  /* CRC Result bit 19 position. */
#define CRCSCAN_CRC_20_bm  (1<<20)  /* CRC Result bit 20 mask. */
#define CRCSCAN_CRC_20_bp  20  /* CRC Result bit 20 position. */
#define CRCSCAN_CRC_21_bm  (1<<21)  /* CRC Result bit 21 mask. */
#define CRCSCAN_CRC_21_bp  21  /* CRC Result bit 21 position. */
#define CRCSCAN_CRC_22_bm  (1<<22)  /* CRC Result bit 22 mask. */
#define CRCSCAN_CRC_22_bp  22  /* CRC Result bit 22 position. */
#define CRCSCAN_CRC_23_bm  (1<<23)  /* CRC Result bit 23 mask. */
#define CRCSCAN_CRC_23_bp  23  /* CRC Result bit 23 position. */
#define CRCSCAN_CRC_24_bm  (1<<24)  /* CRC Result bit 24 mask. */
#define CRCSCAN_CRC_24_bp  24  /* CRC Result bit 24 position. */
#define CRCSCAN_CRC_25_bm  (1<<25)  /* CRC Result bit 25 mask. */
#define CRCSCAN_CRC_25_bp  25  /* CRC Result bit 25 position. */
#define CRCSCAN_CRC_26_bm  (1<<26)  /* CRC Result bit 26 mask. */
#define CRCSCAN_CRC_26_bp  26  /* CRC Result bit 26 position. */
#define CRCSCAN_CRC_27_bm  (1<<27)  /* CRC Result bit 27 mask. */
#define CRCSCAN_CRC_27_bp  27  /* CRC Result bit 27 position. */
#define CRCSCAN_CRC_28_bm  (1<<28)  /* CRC Result bit 28 mask. */
#define CRCSCAN_CRC_28_bp  28  /* CRC Result bit 28 position. */
#define CRCSCAN_CRC_29_bm  (1<<29)  /* CRC Result bit 29 mask. */
#define CRCSCAN_CRC_29_bp  29  /* CRC Result bit 29 position. */
#define CRCSCAN_CRC_30_bm  (1<<30)  /* CRC Result bit 30 mask. */
#define CRCSCAN_CRC_30_bp  30  /* CRC Result bit 30 position. */
#define CRCSCAN_CRC_31_bm  (1<<31)  /* CRC Result bit 31 mask. */
#define CRCSCAN_CRC_31_bp  31  /* CRC Result bit 31 position. */


/* DAC - Digital to Analog Converter */
/* DAC.CTRLA  bit masks and bit positions */
#define DAC_ENABLE_bm  0x01  /* DAC Enable bit mask. */
#define DAC_ENABLE_bp  0  /* DAC Enable bit position. */
#define DAC_OUTEN_bm  0x40  /* Output Buffer Enable bit mask. */
#define DAC_OUTEN_bp  6  /* Output Buffer Enable bit position. */
#define DAC_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define DAC_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* DAC.DATA  bit masks and bit positions */
#define DAC_DATA_gm  0xFFC0  /* Data group mask. */
#define DAC_DATA_gp  6  /* Data group position. */
#define DAC_DATA_0_bm  (1<<6)  /* Data bit 0 mask. */
#define DAC_DATA_0_bp  6  /* Data bit 0 position. */
#define DAC_DATA_1_bm  (1<<7)  /* Data bit 1 mask. */
#define DAC_DATA_1_bp  7  /* Data bit 1 position. */
#define DAC_DATA_2_bm  (1<<8)  /* Data bit 2 mask. */
#define DAC_DATA_2_bp  8  /* Data bit 2 position. */
#define DAC_DATA_3_bm  (1<<9)  /* Data bit 3 mask. */
#define DAC_DATA_3_bp  9  /* Data bit 3 position. */
#define DAC_DATA_4_bm  (1<<10)  /* Data bit 4 mask. */
#define DAC_DATA_4_bp  10  /* Data bit 4 position. */
#define DAC_DATA_5_bm  (1<<11)  /* Data bit 5 mask. */
#define DAC_DATA_5_bp  11  /* Data bit 5 position. */
#define DAC_DATA_6_bm  (1<<12)  /* Data bit 6 mask. */
#define DAC_DATA_6_bp  12  /* Data bit 6 position. */
#define DAC_DATA_7_bm  (1<<13)  /* Data bit 7 mask. */
#define DAC_DATA_7_bp  13  /* Data bit 7 position. */
#define DAC_DATA_8_bm  (1<<14)  /* Data bit 8 mask. */
#define DAC_DATA_8_bp  14  /* Data bit 8 position. */
#define DAC_DATA_9_bm  (1<<15)  /* Data bit 9 mask. */
#define DAC_DATA_9_bp  15  /* Data bit 9 position. */


/* ERRCTRL - Error Controller */
/* ERRCTRL.CTRLA  bit masks and bit positions */
#define ERRCTRL_STATE_gm  0x03  /* ERRCTRL State group mask. */
#define ERRCTRL_STATE_gp  0  /* ERRCTRL State group position. */
#define ERRCTRL_STATE_0_bm  (1<<0)  /* ERRCTRL State bit 0 mask. */
#define ERRCTRL_STATE_0_bp  0  /* ERRCTRL State bit 0 position. */
#define ERRCTRL_STATE_1_bm  (1<<1)  /* ERRCTRL State bit 1 mask. */
#define ERRCTRL_STATE_1_bp  1  /* ERRCTRL State bit 1 position. */
#define ERRCTRL_INTTYPE_bm  0x08  /* ALARM State Interrupt Type bit mask. */
#define ERRCTRL_INTTYPE_bp  3  /* ALARM State Interrupt Type bit position. */
#define ERRCTRL_HEART_bm  0x10  /* Heartbeat Enable bit mask. */
#define ERRCTRL_HEART_bp  4  /* Heartbeat Enable bit position. */
#define ERRCTRL_FORCEFLOAT_bm  0x20  /* Force I/O Float bit mask. */
#define ERRCTRL_FORCEFLOAT_bp  5  /* Force I/O Float bit position. */

/* ERRCTRL.STATUSA  bit masks and bit positions */
#define ERRCTRL_NOTIFICATION_bm  0x01  /* Notification Error Detected bit mask. */
#define ERRCTRL_NOTIFICATION_bp  0  /* Notification Error Detected bit position. */
#define ERRCTRL_NONCRITICAL_bm  0x02  /* Noncritical Error Detected bit mask. */
#define ERRCTRL_NONCRITICAL_bp  1  /* Noncritical Error Detected bit position. */
#define ERRCTRL_CRITICAL_bm  0x04  /* Critical Error Detected bit mask. */
#define ERRCTRL_CRITICAL_bp  2  /* Critical Error Detected bit position. */
#define ERRCTRL_IOSAFE_bm  0x40  /* All I/O pins are in safe state bit mask. */
#define ERRCTRL_IOSAFE_bp  6  /* All I/O pins are in safe state bit position. */
#define ERRCTRL_FLOAT_bm  0x80  /* Float I/O pins bit mask. */
#define ERRCTRL_FLOAT_bp  7  /* Float I/O pins bit position. */

/* ERRCTRL.TIMEOUT  bit masks and bit positions */
#define ERRCTRL_TIMEOUT_gm  0xFF  /* Timeout Value group mask. */
#define ERRCTRL_TIMEOUT_gp  0  /* Timeout Value group position. */
#define ERRCTRL_TIMEOUT_0_bm  (1<<0)  /* Timeout Value bit 0 mask. */
#define ERRCTRL_TIMEOUT_0_bp  0  /* Timeout Value bit 0 position. */
#define ERRCTRL_TIMEOUT_1_bm  (1<<1)  /* Timeout Value bit 1 mask. */
#define ERRCTRL_TIMEOUT_1_bp  1  /* Timeout Value bit 1 position. */
#define ERRCTRL_TIMEOUT_2_bm  (1<<2)  /* Timeout Value bit 2 mask. */
#define ERRCTRL_TIMEOUT_2_bp  2  /* Timeout Value bit 2 position. */
#define ERRCTRL_TIMEOUT_3_bm  (1<<3)  /* Timeout Value bit 3 mask. */
#define ERRCTRL_TIMEOUT_3_bp  3  /* Timeout Value bit 3 position. */
#define ERRCTRL_TIMEOUT_4_bm  (1<<4)  /* Timeout Value bit 4 mask. */
#define ERRCTRL_TIMEOUT_4_bp  4  /* Timeout Value bit 4 position. */
#define ERRCTRL_TIMEOUT_5_bm  (1<<5)  /* Timeout Value bit 5 mask. */
#define ERRCTRL_TIMEOUT_5_bp  5  /* Timeout Value bit 5 position. */
#define ERRCTRL_TIMEOUT_6_bm  (1<<6)  /* Timeout Value bit 6 mask. */
#define ERRCTRL_TIMEOUT_6_bp  6  /* Timeout Value bit 6 position. */
#define ERRCTRL_TIMEOUT_7_bm  (1<<7)  /* Timeout Value bit 7 mask. */
#define ERRCTRL_TIMEOUT_7_bp  7  /* Timeout Value bit 7 position. */

/* ERRCTRL.TIMECNT  bit masks and bit positions */
#define ERRCTRL_TIMECNT_gm  0xFF  /* Timeout Counter Value group mask. */
#define ERRCTRL_TIMECNT_gp  0  /* Timeout Counter Value group position. */
#define ERRCTRL_TIMECNT_0_bm  (1<<0)  /* Timeout Counter Value bit 0 mask. */
#define ERRCTRL_TIMECNT_0_bp  0  /* Timeout Counter Value bit 0 position. */
#define ERRCTRL_TIMECNT_1_bm  (1<<1)  /* Timeout Counter Value bit 1 mask. */
#define ERRCTRL_TIMECNT_1_bp  1  /* Timeout Counter Value bit 1 position. */
#define ERRCTRL_TIMECNT_2_bm  (1<<2)  /* Timeout Counter Value bit 2 mask. */
#define ERRCTRL_TIMECNT_2_bp  2  /* Timeout Counter Value bit 2 position. */
#define ERRCTRL_TIMECNT_3_bm  (1<<3)  /* Timeout Counter Value bit 3 mask. */
#define ERRCTRL_TIMECNT_3_bp  3  /* Timeout Counter Value bit 3 position. */
#define ERRCTRL_TIMECNT_4_bm  (1<<4)  /* Timeout Counter Value bit 4 mask. */
#define ERRCTRL_TIMECNT_4_bp  4  /* Timeout Counter Value bit 4 position. */
#define ERRCTRL_TIMECNT_5_bm  (1<<5)  /* Timeout Counter Value bit 5 mask. */
#define ERRCTRL_TIMECNT_5_bp  5  /* Timeout Counter Value bit 5 position. */
#define ERRCTRL_TIMECNT_6_bm  (1<<6)  /* Timeout Counter Value bit 6 mask. */
#define ERRCTRL_TIMECNT_6_bp  6  /* Timeout Counter Value bit 6 position. */
#define ERRCTRL_TIMECNT_7_bm  (1<<7)  /* Timeout Counter Value bit 7 mask. */
#define ERRCTRL_TIMECNT_7_bp  7  /* Timeout Counter Value bit 7 position. */

/* ERRCTRL.CAUSE  bit masks and bit positions */
#define ERRCTRL_CAUSE_gm  0x1F  /* Reset Cause group mask. */
#define ERRCTRL_CAUSE_gp  0  /* Reset Cause group position. */
#define ERRCTRL_CAUSE_0_bm  (1<<0)  /* Reset Cause bit 0 mask. */
#define ERRCTRL_CAUSE_0_bp  0  /* Reset Cause bit 0 position. */
#define ERRCTRL_CAUSE_1_bm  (1<<1)  /* Reset Cause bit 1 mask. */
#define ERRCTRL_CAUSE_1_bp  1  /* Reset Cause bit 1 position. */
#define ERRCTRL_CAUSE_2_bm  (1<<2)  /* Reset Cause bit 2 mask. */
#define ERRCTRL_CAUSE_2_bp  2  /* Reset Cause bit 2 position. */
#define ERRCTRL_CAUSE_3_bm  (1<<3)  /* Reset Cause bit 3 mask. */
#define ERRCTRL_CAUSE_3_bp  3  /* Reset Cause bit 3 position. */
#define ERRCTRL_CAUSE_4_bm  (1<<4)  /* Reset Cause bit 4 mask. */
#define ERRCTRL_CAUSE_4_bp  4  /* Reset Cause bit 4 position. */

/* ERRCTRL.ESCVREGFAIL  bit masks and bit positions */
#define ERRCTRL_ERRLVL_gm  0x03  /* Error Severity Level group mask. */
#define ERRCTRL_ERRLVL_gp  0  /* Error Severity Level group position. */
#define ERRCTRL_ERRLVL_0_bm  (1<<0)  /* Error Severity Level bit 0 mask. */
#define ERRCTRL_ERRLVL_0_bp  0  /* Error Severity Level bit 0 position. */
#define ERRCTRL_ERRLVL_1_bm  (1<<1)  /* Error Severity Level bit 1 mask. */
#define ERRCTRL_ERRLVL_1_bp  1  /* Error Severity Level bit 1 position. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCBUSERR  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCRAM2  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCFLASH2  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCOPC  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCSPLIM  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCRAM1  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCFLASH1  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCVREGWARN  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCCFD0  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCCFD1  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCCFM0  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCCFM1  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCSWDT  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCEEPROM  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCEVSYS0  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESCEVSYS1  bit masks and bit positions */
/* ERRCTRL_ERRLVL  is already defined. */
/* ERRCTRL_FLOAT  is already defined. */

/* ERRCTRL.ESF  bit masks and bit positions */
#define ERRCTRL_ESF0_bm  0x01  /* Error Status Flag 0 bit mask. */
#define ERRCTRL_ESF0_bp  0  /* Error Status Flag 0 bit position. */
#define ERRCTRL_ESF1_bm  0x02  /* Error Status Flag 1 bit mask. */
#define ERRCTRL_ESF1_bp  1  /* Error Status Flag 1 bit position. */
#define ERRCTRL_ESF2_bm  0x04  /* Error Status Flag 2 bit mask. */
#define ERRCTRL_ESF2_bp  2  /* Error Status Flag 2 bit position. */
#define ERRCTRL_ESF3_bm  0x08  /* Error Status Flag 3 bit mask. */
#define ERRCTRL_ESF3_bp  3  /* Error Status Flag 3 bit position. */
#define ERRCTRL_ESF4_bm  0x10  /* Error Status Flag 4 bit mask. */
#define ERRCTRL_ESF4_bp  4  /* Error Status Flag 4 bit position. */
#define ERRCTRL_ESF5_bm  0x20  /* Error Status Flag 5 bit mask. */
#define ERRCTRL_ESF5_bp  5  /* Error Status Flag 5 bit position. */
#define ERRCTRL_ESF6_bm  0x40  /* Error Status Flag 6 bit mask. */
#define ERRCTRL_ESF6_bp  6  /* Error Status Flag 6 bit position. */
#define ERRCTRL_ESF7_bm  0x80  /* Error Status Flag 7 bit mask. */
#define ERRCTRL_ESF7_bp  7  /* Error Status Flag 7 bit position. */
#define ERRCTRL_ESF8_bm  0x100  /* Error Status Flag 8 bit mask. */
#define ERRCTRL_ESF8_bp  8  /* Error Status Flag 8 bit position. */
#define ERRCTRL_ESF9_bm  0x200  /* Error Status Flag 9 bit mask. */
#define ERRCTRL_ESF9_bp  9  /* Error Status Flag 9 bit position. */
#define ERRCTRL_ESF10_bm  0x400  /* Error Status Flag 10 bit mask. */
#define ERRCTRL_ESF10_bp  10  /* Error Status Flag 10 bit position. */
#define ERRCTRL_ESF11_bm  0x800  /* Error Status Flag 11 bit mask. */
#define ERRCTRL_ESF11_bp  11  /* Error Status Flag 11 bit position. */
#define ERRCTRL_ESF12_bm  0x1000  /* Error Status Flag 12 bit mask. */
#define ERRCTRL_ESF12_bp  12  /* Error Status Flag 12 bit position. */
#define ERRCTRL_ESF13_bm  0x2000  /* Error Status Flag 13 bit mask. */
#define ERRCTRL_ESF13_bp  13  /* Error Status Flag 13 bit position. */
#define ERRCTRL_ESF14_bm  0x4000  /* Error Status Flag 14 bit mask. */
#define ERRCTRL_ESF14_bp  14  /* Error Status Flag 14 bit position. */
#define ERRCTRL_ESF15_bm  0x8000  /* Error Status Flag 15 bit mask. */
#define ERRCTRL_ESF15_bp  15  /* Error Status Flag 15 bit position. */
#define ERRCTRL_ESF16_bm  0x10000  /* Error Status Flag 16 bit mask. */
#define ERRCTRL_ESF16_bp  16  /* Error Status Flag 16 bit position. */

/* ERRCTRL.ESFTEST  bit masks and bit positions */
#define ERRCTRL_ESFTEST0_bm  0x01  /* Error Status Flag Test Injection 0 bit mask. */
#define ERRCTRL_ESFTEST0_bp  0  /* Error Status Flag Test Injection 0 bit position. */
#define ERRCTRL_ESFTEST1_bm  0x02  /* Error Status Flag Test Injection 1 bit mask. */
#define ERRCTRL_ESFTEST1_bp  1  /* Error Status Flag Test Injection 1 bit position. */
#define ERRCTRL_ESFTEST2_bm  0x04  /* Error Status Flag Test Injection 2 bit mask. */
#define ERRCTRL_ESFTEST2_bp  2  /* Error Status Flag Test Injection 2 bit position. */
#define ERRCTRL_ESFTEST3_bm  0x08  /* Error Status Flag Test Injection 3 bit mask. */
#define ERRCTRL_ESFTEST3_bp  3  /* Error Status Flag Test Injection 3 bit position. */
#define ERRCTRL_ESFTEST4_bm  0x10  /* Error Status Flag Test Injection 4 bit mask. */
#define ERRCTRL_ESFTEST4_bp  4  /* Error Status Flag Test Injection 4 bit position. */
#define ERRCTRL_ESFTEST5_bm  0x20  /* Error Status Flag Test Injection 5 bit mask. */
#define ERRCTRL_ESFTEST5_bp  5  /* Error Status Flag Test Injection 5 bit position. */
#define ERRCTRL_ESFTEST6_bm  0x40  /* Error Status Flag Test Injection 6 bit mask. */
#define ERRCTRL_ESFTEST6_bp  6  /* Error Status Flag Test Injection 6 bit position. */
#define ERRCTRL_ESFTEST7_bm  0x80  /* Error Status Flag Test Injection 7 bit mask. */
#define ERRCTRL_ESFTEST7_bp  7  /* Error Status Flag Test Injection 7 bit position. */
#define ERRCTRL_ESFTEST8_bm  0x100  /* Error Status Flag Test Injection 8 bit mask. */
#define ERRCTRL_ESFTEST8_bp  8  /* Error Status Flag Test Injection 8 bit position. */
#define ERRCTRL_ESFTEST9_bm  0x200  /* Error Status Flag Test Injection 9 bit mask. */
#define ERRCTRL_ESFTEST9_bp  9  /* Error Status Flag Test Injection 9 bit position. */
#define ERRCTRL_ESFTEST10_bm  0x400  /* Error Status Flag Test Injection 10 bit mask. */
#define ERRCTRL_ESFTEST10_bp  10  /* Error Status Flag Test Injection 10 bit position. */
#define ERRCTRL_ESFTEST11_bm  0x800  /* Error Status Flag Test Injection 11 bit mask. */
#define ERRCTRL_ESFTEST11_bp  11  /* Error Status Flag Test Injection 11 bit position. */
#define ERRCTRL_ESFTEST12_bm  0x1000  /* Error Status Flag Test Injection 12 bit mask. */
#define ERRCTRL_ESFTEST12_bp  12  /* Error Status Flag Test Injection 12 bit position. */
#define ERRCTRL_ESFTEST13_bm  0x2000  /* Error Status Flag Test Injection 13 bit mask. */
#define ERRCTRL_ESFTEST13_bp  13  /* Error Status Flag Test Injection 13 bit position. */
#define ERRCTRL_ESFTEST14_bm  0x4000  /* Error Status Flag Test Injection 14 bit mask. */
#define ERRCTRL_ESFTEST14_bp  14  /* Error Status Flag Test Injection 14 bit position. */
#define ERRCTRL_ESFTEST15_bm  0x8000  /* Error Status Flag Test Injection 15 bit mask. */
#define ERRCTRL_ESFTEST15_bp  15  /* Error Status Flag Test Injection 15 bit position. */
#define ERRCTRL_ESFTEST16_bm  0x10000  /* Error Status Flag Test Injection 16 bit mask. */
#define ERRCTRL_ESFTEST16_bp  16  /* Error Status Flag Test Injection 16 bit position. */


/* EVSYS - Event System */
/* EVSYS.SWEVENTA  bit masks and bit positions */
#define EVSYS_CH0_bm  0x01  /* Channel 0 Select bit mask. */
#define EVSYS_CH0_bp  0  /* Channel 0 Select bit position. */
#define EVSYS_CH1_bm  0x02  /* Channel 1 Select bit mask. */
#define EVSYS_CH1_bp  1  /* Channel 1 Select bit position. */
#define EVSYS_CH2_bm  0x04  /* Channel 2 Select bit mask. */
#define EVSYS_CH2_bp  2  /* Channel 2 Select bit position. */
#define EVSYS_CH3_bm  0x08  /* Channel 3 Select bit mask. */
#define EVSYS_CH3_bp  3  /* Channel 3 Select bit position. */
#define EVSYS_CH4_bm  0x10  /* Channel 4 Select bit mask. */
#define EVSYS_CH4_bp  4  /* Channel 4 Select bit position. */
#define EVSYS_CH5_bm  0x20  /* Channel 5 Select bit mask. */
#define EVSYS_CH5_bp  5  /* Channel 5 Select bit position. */

/* EVSYS.CHANNEL0  bit masks and bit positions */
#define EVSYS_CHANNEL_gm  0xFF  /* Channel Generator Select group mask. */
#define EVSYS_CHANNEL_gp  0  /* Channel Generator Select group position. */
#define EVSYS_CHANNEL_0_bm  (1<<0)  /* Channel Generator Select bit 0 mask. */
#define EVSYS_CHANNEL_0_bp  0  /* Channel Generator Select bit 0 position. */
#define EVSYS_CHANNEL_1_bm  (1<<1)  /* Channel Generator Select bit 1 mask. */
#define EVSYS_CHANNEL_1_bp  1  /* Channel Generator Select bit 1 position. */
#define EVSYS_CHANNEL_2_bm  (1<<2)  /* Channel Generator Select bit 2 mask. */
#define EVSYS_CHANNEL_2_bp  2  /* Channel Generator Select bit 2 position. */
#define EVSYS_CHANNEL_3_bm  (1<<3)  /* Channel Generator Select bit 3 mask. */
#define EVSYS_CHANNEL_3_bp  3  /* Channel Generator Select bit 3 position. */
#define EVSYS_CHANNEL_4_bm  (1<<4)  /* Channel Generator Select bit 4 mask. */
#define EVSYS_CHANNEL_4_bp  4  /* Channel Generator Select bit 4 position. */
#define EVSYS_CHANNEL_5_bm  (1<<5)  /* Channel Generator Select bit 5 mask. */
#define EVSYS_CHANNEL_5_bp  5  /* Channel Generator Select bit 5 position. */
#define EVSYS_CHANNEL_6_bm  (1<<6)  /* Channel Generator Select bit 6 mask. */
#define EVSYS_CHANNEL_6_bp  6  /* Channel Generator Select bit 6 position. */
#define EVSYS_CHANNEL_7_bm  (1<<7)  /* Channel Generator Select bit 7 mask. */
#define EVSYS_CHANNEL_7_bp  7  /* Channel Generator Select bit 7 position. */

/* EVSYS.CHANNEL1  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL2  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL3  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL4  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.CHANNEL5  bit masks and bit positions */
/* EVSYS_CHANNEL  is already defined. */

/* EVSYS.USERCCLLUT0A  bit masks and bit positions */
#define EVSYS_USER_gm  0xFF  /* User channel select group mask. */
#define EVSYS_USER_gp  0  /* User channel select group position. */
#define EVSYS_USER_0_bm  (1<<0)  /* User channel select bit 0 mask. */
#define EVSYS_USER_0_bp  0  /* User channel select bit 0 position. */
#define EVSYS_USER_1_bm  (1<<1)  /* User channel select bit 1 mask. */
#define EVSYS_USER_1_bp  1  /* User channel select bit 1 position. */
#define EVSYS_USER_2_bm  (1<<2)  /* User channel select bit 2 mask. */
#define EVSYS_USER_2_bp  2  /* User channel select bit 2 position. */
#define EVSYS_USER_3_bm  (1<<3)  /* User channel select bit 3 mask. */
#define EVSYS_USER_3_bp  3  /* User channel select bit 3 position. */
#define EVSYS_USER_4_bm  (1<<4)  /* User channel select bit 4 mask. */
#define EVSYS_USER_4_bp  4  /* User channel select bit 4 position. */
#define EVSYS_USER_5_bm  (1<<5)  /* User channel select bit 5 mask. */
#define EVSYS_USER_5_bp  5  /* User channel select bit 5 position. */
#define EVSYS_USER_6_bm  (1<<6)  /* User channel select bit 6 mask. */
#define EVSYS_USER_6_bp  6  /* User channel select bit 6 position. */
#define EVSYS_USER_7_bm  (1<<7)  /* User channel select bit 7 mask. */
#define EVSYS_USER_7_bp  7  /* User channel select bit 7 position. */

/* EVSYS.USERCCLLUT0B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT1A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT1B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT2A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT2B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT3A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT3B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT4A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT4B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT5A  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCCLLUT5B  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERADC0START  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERADC1START  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTC  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USEREVSYSEVOUTD  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART0IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERUSART1IRDA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCA0CNTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCA0CNTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB0CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB0COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB1CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB1COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB2CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB2COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB3CAPT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCB3COUNT  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCD0INPUTA  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERTCD0INPUTB  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERERRCTRLEVENT0  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERERRCTRLEVENT1  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCLKCTRLCFD  bit masks and bit positions */
/* EVSYS_USER  is already defined. */

/* EVSYS.USERCLKCTRLCFM  bit masks and bit positions */
/* EVSYS_USER  is already defined. */


/* FUSE - Fuses */
/* FUSE.WDTCFG  bit masks and bit positions */
#define FUSE_PERIOD_gm  0x0F  /* Watchdog Timeout Period group mask. */
#define FUSE_PERIOD_gp  0  /* Watchdog Timeout Period group position. */
#define FUSE_PERIOD_0_bm  (1<<0)  /* Watchdog Timeout Period bit 0 mask. */
#define FUSE_PERIOD_0_bp  0  /* Watchdog Timeout Period bit 0 position. */
#define FUSE_PERIOD_1_bm  (1<<1)  /* Watchdog Timeout Period bit 1 mask. */
#define FUSE_PERIOD_1_bp  1  /* Watchdog Timeout Period bit 1 position. */
#define FUSE_PERIOD_2_bm  (1<<2)  /* Watchdog Timeout Period bit 2 mask. */
#define FUSE_PERIOD_2_bp  2  /* Watchdog Timeout Period bit 2 position. */
#define FUSE_PERIOD_3_bm  (1<<3)  /* Watchdog Timeout Period bit 3 mask. */
#define FUSE_PERIOD_3_bp  3  /* Watchdog Timeout Period bit 3 position. */
#define FUSE_WINDOW_gm  0xF0  /* Watchdog Window Timeout Period group mask. */
#define FUSE_WINDOW_gp  4  /* Watchdog Window Timeout Period group position. */
#define FUSE_WINDOW_0_bm  (1<<4)  /* Watchdog Window Timeout Period bit 0 mask. */
#define FUSE_WINDOW_0_bp  4  /* Watchdog Window Timeout Period bit 0 position. */
#define FUSE_WINDOW_1_bm  (1<<5)  /* Watchdog Window Timeout Period bit 1 mask. */
#define FUSE_WINDOW_1_bp  5  /* Watchdog Window Timeout Period bit 1 position. */
#define FUSE_WINDOW_2_bm  (1<<6)  /* Watchdog Window Timeout Period bit 2 mask. */
#define FUSE_WINDOW_2_bp  6  /* Watchdog Window Timeout Period bit 2 position. */
#define FUSE_WINDOW_3_bm  (1<<7)  /* Watchdog Window Timeout Period bit 3 mask. */
#define FUSE_WINDOW_3_bp  7  /* Watchdog Window Timeout Period bit 3 position. */

/* FUSE.BODCFG  bit masks and bit positions */
#define FUSE_SLEEP_gm  0x03  /* BOD Operation in Sleep Mode group mask. */
#define FUSE_SLEEP_gp  0  /* BOD Operation in Sleep Mode group position. */
#define FUSE_SLEEP_0_bm  (1<<0)  /* BOD Operation in Sleep Mode bit 0 mask. */
#define FUSE_SLEEP_0_bp  0  /* BOD Operation in Sleep Mode bit 0 position. */
#define FUSE_SLEEP_1_bm  (1<<1)  /* BOD Operation in Sleep Mode bit 1 mask. */
#define FUSE_SLEEP_1_bp  1  /* BOD Operation in Sleep Mode bit 1 position. */
#define FUSE_ACTIVE_gm  0x0C  /* BOD Operation in Active Mode group mask. */
#define FUSE_ACTIVE_gp  2  /* BOD Operation in Active Mode group position. */
#define FUSE_ACTIVE_0_bm  (1<<2)  /* BOD Operation in Active Mode bit 0 mask. */
#define FUSE_ACTIVE_0_bp  2  /* BOD Operation in Active Mode bit 0 position. */
#define FUSE_ACTIVE_1_bm  (1<<3)  /* BOD Operation in Active Mode bit 1 mask. */
#define FUSE_ACTIVE_1_bp  3  /* BOD Operation in Active Mode bit 1 position. */
#define FUSE_SAMPFREQ_bm  0x10  /* BOD Sample Frequency bit mask. */
#define FUSE_SAMPFREQ_bp  4  /* BOD Sample Frequency bit position. */
#define FUSE_LVL_gm  0xE0  /* BOD Level group mask. */
#define FUSE_LVL_gp  5  /* BOD Level group position. */
#define FUSE_LVL_0_bm  (1<<5)  /* BOD Level bit 0 mask. */
#define FUSE_LVL_0_bp  5  /* BOD Level bit 0 position. */
#define FUSE_LVL_1_bm  (1<<6)  /* BOD Level bit 1 mask. */
#define FUSE_LVL_1_bp  6  /* BOD Level bit 1 position. */
#define FUSE_LVL_2_bm  (1<<7)  /* BOD Level bit 2 mask. */
#define FUSE_LVL_2_bp  7  /* BOD Level bit 2 position. */

/* FUSE.SYSCFG0  bit masks and bit positions */
#define FUSE_EESAVE_bm  0x01  /* EEPROM Save bit mask. */
#define FUSE_EESAVE_bp  0  /* EEPROM Save bit position. */
#define FUSE_BROWSAVE_bm  0x02  /* Boot Row Saved bit mask. */
#define FUSE_BROWSAVE_bp  1  /* Boot Row Saved bit position. */
#define FUSE_CRCSEL_bm  0x40  /* CRC Select bit mask. */
#define FUSE_CRCSEL_bp  6  /* CRC Select bit position. */
#define FUSE_CRCBOOT_bm  0x80  /* CRC Boot bit mask. */
#define FUSE_CRCBOOT_bp  7  /* CRC Boot bit position. */

/* FUSE.SYSCFG1  bit masks and bit positions */
#define FUSE_SUT_gm  0x07  /* Startup Time group mask. */
#define FUSE_SUT_gp  0  /* Startup Time group position. */
#define FUSE_SUT_0_bm  (1<<0)  /* Startup Time bit 0 mask. */
#define FUSE_SUT_0_bp  0  /* Startup Time bit 0 position. */
#define FUSE_SUT_1_bm  (1<<1)  /* Startup Time bit 1 mask. */
#define FUSE_SUT_1_bp  1  /* Startup Time bit 1 position. */
#define FUSE_SUT_2_bm  (1<<2)  /* Startup Time bit 2 mask. */
#define FUSE_SUT_2_bp  2  /* Startup Time bit 2 position. */
#define FUSE_MVSYSCFG_gm  0x18  /* MVIO System Configuration group mask. */
#define FUSE_MVSYSCFG_gp  3  /* MVIO System Configuration group position. */
#define FUSE_MVSYSCFG_0_bm  (1<<3)  /* MVIO System Configuration bit 0 mask. */
#define FUSE_MVSYSCFG_0_bp  3  /* MVIO System Configuration bit 0 position. */
#define FUSE_MVSYSCFG_1_bm  (1<<4)  /* MVIO System Configuration bit 1 mask. */
#define FUSE_MVSYSCFG_1_bp  4  /* MVIO System Configuration bit 1 position. */
#define FUSE_WDTMON_gm  0xC0  /* WDT Monitor Configuration group mask. */
#define FUSE_WDTMON_gp  6  /* WDT Monitor Configuration group position. */
#define FUSE_WDTMON_0_bm  (1<<6)  /* WDT Monitor Configuration bit 0 mask. */
#define FUSE_WDTMON_0_bp  6  /* WDT Monitor Configuration bit 0 position. */
#define FUSE_WDTMON_1_bm  (1<<7)  /* WDT Monitor Configuration bit 1 mask. */
#define FUSE_WDTMON_1_bp  7  /* WDT Monitor Configuration bit 1 position. */

/* FUSE.PDICFG  bit masks and bit positions */
#define FUSE_LEVEL_gm  0x03  /* Protection Level select group mask. */
#define FUSE_LEVEL_gp  0  /* Protection Level select group position. */
#define FUSE_LEVEL_0_bm  (1<<0)  /* Protection Level select bit 0 mask. */
#define FUSE_LEVEL_0_bp  0  /* Protection Level select bit 0 position. */
#define FUSE_LEVEL_1_bm  (1<<1)  /* Protection Level select bit 1 mask. */
#define FUSE_LEVEL_1_bp  1  /* Protection Level select bit 1 position. */
#define FUSE_KEY_gm  0xFFF0  /* NVM Protection Activation Key select group mask. */
#define FUSE_KEY_gp  4  /* NVM Protection Activation Key select group position. */
#define FUSE_KEY_0_bm  (1<<4)  /* NVM Protection Activation Key select bit 0 mask. */
#define FUSE_KEY_0_bp  4  /* NVM Protection Activation Key select bit 0 position. */
#define FUSE_KEY_1_bm  (1<<5)  /* NVM Protection Activation Key select bit 1 mask. */
#define FUSE_KEY_1_bp  5  /* NVM Protection Activation Key select bit 1 position. */
#define FUSE_KEY_2_bm  (1<<6)  /* NVM Protection Activation Key select bit 2 mask. */
#define FUSE_KEY_2_bp  6  /* NVM Protection Activation Key select bit 2 position. */
#define FUSE_KEY_3_bm  (1<<7)  /* NVM Protection Activation Key select bit 3 mask. */
#define FUSE_KEY_3_bp  7  /* NVM Protection Activation Key select bit 3 position. */
#define FUSE_KEY_4_bm  (1<<8)  /* NVM Protection Activation Key select bit 4 mask. */
#define FUSE_KEY_4_bp  8  /* NVM Protection Activation Key select bit 4 position. */
#define FUSE_KEY_5_bm  (1<<9)  /* NVM Protection Activation Key select bit 5 mask. */
#define FUSE_KEY_5_bp  9  /* NVM Protection Activation Key select bit 5 position. */
#define FUSE_KEY_6_bm  (1<<10)  /* NVM Protection Activation Key select bit 6 mask. */
#define FUSE_KEY_6_bp  10  /* NVM Protection Activation Key select bit 6 position. */
#define FUSE_KEY_7_bm  (1<<11)  /* NVM Protection Activation Key select bit 7 mask. */
#define FUSE_KEY_7_bp  11  /* NVM Protection Activation Key select bit 7 position. */
#define FUSE_KEY_8_bm  (1<<12)  /* NVM Protection Activation Key select bit 8 mask. */
#define FUSE_KEY_8_bp  12  /* NVM Protection Activation Key select bit 8 position. */
#define FUSE_KEY_9_bm  (1<<13)  /* NVM Protection Activation Key select bit 9 mask. */
#define FUSE_KEY_9_bp  13  /* NVM Protection Activation Key select bit 9 position. */
#define FUSE_KEY_10_bm  (1<<14)  /* NVM Protection Activation Key select bit 10 mask. */
#define FUSE_KEY_10_bp  14  /* NVM Protection Activation Key select bit 10 position. */
#define FUSE_KEY_11_bm  (1<<15)  /* NVM Protection Activation Key select bit 11 mask. */
#define FUSE_KEY_11_bp  15  /* NVM Protection Activation Key select bit 11 position. */



/* LOCK - Lockbits */
/* LOCK.KEY  bit masks and bit positions */
#define LOCK_KEY_gm  0xFFFFFFFF  /* Lock Key group mask. */
#define LOCK_KEY_gp  0  /* Lock Key group position. */
#define LOCK_KEY_0_bm  (1<<0)  /* Lock Key bit 0 mask. */
#define LOCK_KEY_0_bp  0  /* Lock Key bit 0 position. */
#define LOCK_KEY_1_bm  (1<<1)  /* Lock Key bit 1 mask. */
#define LOCK_KEY_1_bp  1  /* Lock Key bit 1 position. */
#define LOCK_KEY_2_bm  (1<<2)  /* Lock Key bit 2 mask. */
#define LOCK_KEY_2_bp  2  /* Lock Key bit 2 position. */
#define LOCK_KEY_3_bm  (1<<3)  /* Lock Key bit 3 mask. */
#define LOCK_KEY_3_bp  3  /* Lock Key bit 3 position. */
#define LOCK_KEY_4_bm  (1<<4)  /* Lock Key bit 4 mask. */
#define LOCK_KEY_4_bp  4  /* Lock Key bit 4 position. */
#define LOCK_KEY_5_bm  (1<<5)  /* Lock Key bit 5 mask. */
#define LOCK_KEY_5_bp  5  /* Lock Key bit 5 position. */
#define LOCK_KEY_6_bm  (1<<6)  /* Lock Key bit 6 mask. */
#define LOCK_KEY_6_bp  6  /* Lock Key bit 6 position. */
#define LOCK_KEY_7_bm  (1<<7)  /* Lock Key bit 7 mask. */
#define LOCK_KEY_7_bp  7  /* Lock Key bit 7 position. */
#define LOCK_KEY_8_bm  (1<<8)  /* Lock Key bit 8 mask. */
#define LOCK_KEY_8_bp  8  /* Lock Key bit 8 position. */
#define LOCK_KEY_9_bm  (1<<9)  /* Lock Key bit 9 mask. */
#define LOCK_KEY_9_bp  9  /* Lock Key bit 9 position. */
#define LOCK_KEY_10_bm  (1<<10)  /* Lock Key bit 10 mask. */
#define LOCK_KEY_10_bp  10  /* Lock Key bit 10 position. */
#define LOCK_KEY_11_bm  (1<<11)  /* Lock Key bit 11 mask. */
#define LOCK_KEY_11_bp  11  /* Lock Key bit 11 position. */
#define LOCK_KEY_12_bm  (1<<12)  /* Lock Key bit 12 mask. */
#define LOCK_KEY_12_bp  12  /* Lock Key bit 12 position. */
#define LOCK_KEY_13_bm  (1<<13)  /* Lock Key bit 13 mask. */
#define LOCK_KEY_13_bp  13  /* Lock Key bit 13 position. */
#define LOCK_KEY_14_bm  (1<<14)  /* Lock Key bit 14 mask. */
#define LOCK_KEY_14_bp  14  /* Lock Key bit 14 position. */
#define LOCK_KEY_15_bm  (1<<15)  /* Lock Key bit 15 mask. */
#define LOCK_KEY_15_bp  15  /* Lock Key bit 15 position. */
#define LOCK_KEY_16_bm  (1<<16)  /* Lock Key bit 16 mask. */
#define LOCK_KEY_16_bp  16  /* Lock Key bit 16 position. */
#define LOCK_KEY_17_bm  (1<<17)  /* Lock Key bit 17 mask. */
#define LOCK_KEY_17_bp  17  /* Lock Key bit 17 position. */
#define LOCK_KEY_18_bm  (1<<18)  /* Lock Key bit 18 mask. */
#define LOCK_KEY_18_bp  18  /* Lock Key bit 18 position. */
#define LOCK_KEY_19_bm  (1<<19)  /* Lock Key bit 19 mask. */
#define LOCK_KEY_19_bp  19  /* Lock Key bit 19 position. */
#define LOCK_KEY_20_bm  (1<<20)  /* Lock Key bit 20 mask. */
#define LOCK_KEY_20_bp  20  /* Lock Key bit 20 position. */
#define LOCK_KEY_21_bm  (1<<21)  /* Lock Key bit 21 mask. */
#define LOCK_KEY_21_bp  21  /* Lock Key bit 21 position. */
#define LOCK_KEY_22_bm  (1<<22)  /* Lock Key bit 22 mask. */
#define LOCK_KEY_22_bp  22  /* Lock Key bit 22 position. */
#define LOCK_KEY_23_bm  (1<<23)  /* Lock Key bit 23 mask. */
#define LOCK_KEY_23_bp  23  /* Lock Key bit 23 position. */
#define LOCK_KEY_24_bm  (1<<24)  /* Lock Key bit 24 mask. */
#define LOCK_KEY_24_bp  24  /* Lock Key bit 24 position. */
#define LOCK_KEY_25_bm  (1<<25)  /* Lock Key bit 25 mask. */
#define LOCK_KEY_25_bp  25  /* Lock Key bit 25 position. */
#define LOCK_KEY_26_bm  (1<<26)  /* Lock Key bit 26 mask. */
#define LOCK_KEY_26_bp  26  /* Lock Key bit 26 position. */
#define LOCK_KEY_27_bm  (1<<27)  /* Lock Key bit 27 mask. */
#define LOCK_KEY_27_bp  27  /* Lock Key bit 27 position. */
#define LOCK_KEY_28_bm  (1<<28)  /* Lock Key bit 28 mask. */
#define LOCK_KEY_28_bp  28  /* Lock Key bit 28 position. */
#define LOCK_KEY_29_bm  (1<<29)  /* Lock Key bit 29 mask. */
#define LOCK_KEY_29_bp  29  /* Lock Key bit 29 position. */
#define LOCK_KEY_30_bm  (1<<30)  /* Lock Key bit 30 mask. */
#define LOCK_KEY_30_bp  30  /* Lock Key bit 30 position. */
#define LOCK_KEY_31_bm  (1<<31)  /* Lock Key bit 31 mask. */
#define LOCK_KEY_31_bp  31  /* Lock Key bit 31 position. */


/* MVIO - Multi-Voltage I/O */
/* MVIO.INTCTRL  bit masks and bit positions */
#define MVIO_VDDIO2IE_bm  0x01  /* VDDIO2 Interrupt Enable bit mask. */
#define MVIO_VDDIO2IE_bp  0  /* VDDIO2 Interrupt Enable bit position. */

/* MVIO.INTFLAGS  bit masks and bit positions */
#define MVIO_VDDIO2IF_bm  0x01  /* VDDIO2 Interrupt Flag bit mask. */
#define MVIO_VDDIO2IF_bp  0  /* VDDIO2 Interrupt Flag bit position. */

/* MVIO.STATUS  bit masks and bit positions */
#define MVIO_VDDIO2S_bm  0x01  /* VDDIO2 Status bit mask. */
#define MVIO_VDDIO2S_bp  0  /* VDDIO2 Status bit position. */


/* NVMCTRL - Non-volatile Memory Controller */
/* NVMCTRL.CTRLA  bit masks and bit positions */
#define NVMCTRL_CMD_gm  0x7F  /* Command group mask. */
#define NVMCTRL_CMD_gp  0  /* Command group position. */
#define NVMCTRL_CMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define NVMCTRL_CMD_0_bp  0  /* Command bit 0 position. */
#define NVMCTRL_CMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define NVMCTRL_CMD_1_bp  1  /* Command bit 1 position. */
#define NVMCTRL_CMD_2_bm  (1<<2)  /* Command bit 2 mask. */
#define NVMCTRL_CMD_2_bp  2  /* Command bit 2 position. */
#define NVMCTRL_CMD_3_bm  (1<<3)  /* Command bit 3 mask. */
#define NVMCTRL_CMD_3_bp  3  /* Command bit 3 position. */
#define NVMCTRL_CMD_4_bm  (1<<4)  /* Command bit 4 mask. */
#define NVMCTRL_CMD_4_bp  4  /* Command bit 4 position. */
#define NVMCTRL_CMD_5_bm  (1<<5)  /* Command bit 5 mask. */
#define NVMCTRL_CMD_5_bp  5  /* Command bit 5 position. */
#define NVMCTRL_CMD_6_bm  (1<<6)  /* Command bit 6 mask. */
#define NVMCTRL_CMD_6_bp  6  /* Command bit 6 position. */

/* NVMCTRL.CTRLB  bit masks and bit positions */
#define NVMCTRL_APPCODEWP_bm  0x01  /* Application Code Write Protect bit mask. */
#define NVMCTRL_APPCODEWP_bp  0  /* Application Code Write Protect bit position. */
#define NVMCTRL_BOOTRP_bm  0x02  /* Boot Read Protect bit mask. */
#define NVMCTRL_BOOTRP_bp  1  /* Boot Read Protect bit position. */
#define NVMCTRL_APPDATAWP_bm  0x04  /* Application Data Write Protect bit mask. */
#define NVMCTRL_APPDATAWP_bp  2  /* Application Data Write Protect bit position. */
#define NVMCTRL_EEWP_bm  0x08  /* EEPROM Write Protect bit mask. */
#define NVMCTRL_EEWP_bp  3  /* EEPROM Write Protect bit position. */
#define NVMCTRL_FLMAP_gm  0x30  /* Flash Mapping in Data space group mask. */
#define NVMCTRL_FLMAP_gp  4  /* Flash Mapping in Data space group position. */
#define NVMCTRL_FLMAP_0_bm  (1<<4)  /* Flash Mapping in Data space bit 0 mask. */
#define NVMCTRL_FLMAP_0_bp  4  /* Flash Mapping in Data space bit 0 position. */
#define NVMCTRL_FLMAP_1_bm  (1<<5)  /* Flash Mapping in Data space bit 1 mask. */
#define NVMCTRL_FLMAP_1_bp  5  /* Flash Mapping in Data space bit 1 position. */
#define NVMCTRL_FLMAPLOCK_bm  0x80  /* Flash Mapping Lock bit mask. */
#define NVMCTRL_FLMAPLOCK_bp  7  /* Flash Mapping Lock bit position. */

/* NVMCTRL.CTRLC  bit masks and bit positions */
#define NVMCTRL_UROWWP_bm  0x01  /* User Row Write Protect bit mask. */
#define NVMCTRL_UROWWP_bp  0  /* User Row Write Protect bit position. */
#define NVMCTRL_BOOTROWWP_bm  0x02  /* Boot Row Write Protect bit mask. */
#define NVMCTRL_BOOTROWWP_bp  1  /* Boot Row Write Protect bit position. */
#define NVMCTRL_ECCALL1_gm  0xC0  /* Erased Flash ECC check group mask. */
#define NVMCTRL_ECCALL1_gp  6  /* Erased Flash ECC check group position. */
#define NVMCTRL_ECCALL1_0_bm  (1<<6)  /* Erased Flash ECC check bit 0 mask. */
#define NVMCTRL_ECCALL1_0_bp  6  /* Erased Flash ECC check bit 0 position. */
#define NVMCTRL_ECCALL1_1_bm  (1<<7)  /* Erased Flash ECC check bit 1 mask. */
#define NVMCTRL_ECCALL1_1_bp  7  /* Erased Flash ECC check bit 1 position. */

/* NVMCTRL.CTRLD  bit masks and bit positions */
#define NVMCTRL_ECC1_bm  0x01  /* 1-bit ECC error inject bit mask. */
#define NVMCTRL_ECC1_bp  0  /* 1-bit ECC error inject bit position. */
#define NVMCTRL_ECC2_bm  0x02  /* 2-bit ECC error inject bit mask. */
#define NVMCTRL_ECC2_bp  1  /* 2-bit ECC error inject bit position. */
#define NVMCTRL_PARITYI_bm  0x20  /* Parity error inject on Instruction Fetch bit mask. */
#define NVMCTRL_PARITYI_bp  5  /* Parity error inject on Instruction Fetch bit position. */
#define NVMCTRL_PARITYD_bm  0x40  /* Parity error inject on Data Read bit mask. */
#define NVMCTRL_PARITYD_bp  6  /* Parity error inject on Data Read bit position. */
#define NVMCTRL_COMP_bm  0x80  /* ECC comparator error inject bit mask. */
#define NVMCTRL_COMP_bp  7  /* ECC comparator error inject bit position. */

/* NVMCTRL.INTCTRLA  bit masks and bit positions */
#define NVMCTRL_EEREADY_bm  0x01  /* EEPROM Ready bit mask. */
#define NVMCTRL_EEREADY_bp  0  /* EEPROM Ready bit position. */

/* NVMCTRL.INTFLAGSA  bit masks and bit positions */
/* NVMCTRL_EEREADY  is already defined. */

/* NVMCTRL.INTFLAGSB  bit masks and bit positions */
#define NVMCTRL_FECC1_bm  0x01  /* Flash 1-bit ECC error detected bit mask. */
#define NVMCTRL_FECC1_bp  0  /* Flash 1-bit ECC error detected bit position. */
#define NVMCTRL_FECC2_bm  0x02  /* Flash multibit error detected bit mask. */
#define NVMCTRL_FECC2_bp  1  /* Flash multibit error detected bit position. */
#define NVMCTRL_EECC1_bm  0x04  /* EEPROM 1-bit error detected bit mask. */
#define NVMCTRL_EECC1_bp  2  /* EEPROM 1-bit error detected bit position. */
#define NVMCTRL_EECC2_bm  0x08  /* EEPROM multibit error detected bit mask. */
#define NVMCTRL_EECC2_bp  3  /* EEPROM multibit error detected bit position. */
#define NVMCTRL_PARITYC_bm  0x10  /* Parity error on Control signals detected bit mask. */
#define NVMCTRL_PARITYC_bp  4  /* Parity error on Control signals detected bit position. */
#define NVMCTRL_PARITYA_bm  0x20  /* Parity error on Address detected bit mask. */
#define NVMCTRL_PARITYA_bp  5  /* Parity error on Address detected bit position. */
/* NVMCTRL_PARITYD  is already defined. */
/* NVMCTRL_COMP  is already defined. */

/* NVMCTRL.STATUS  bit masks and bit positions */
#define NVMCTRL_EEBUSY_bm  0x01  /* EEPROM busy bit mask. */
#define NVMCTRL_EEBUSY_bp  0  /* EEPROM busy bit position. */
#define NVMCTRL_FBUSY_bm  0x02  /* Flash busy bit mask. */
#define NVMCTRL_FBUSY_bp  1  /* Flash busy bit position. */
#define NVMCTRL_ERROR_gm  0x70  /* Write error group mask. */
#define NVMCTRL_ERROR_gp  4  /* Write error group position. */
#define NVMCTRL_ERROR_0_bm  (1<<4)  /* Write error bit 0 mask. */
#define NVMCTRL_ERROR_0_bp  4  /* Write error bit 0 position. */
#define NVMCTRL_ERROR_1_bm  (1<<5)  /* Write error bit 1 mask. */
#define NVMCTRL_ERROR_1_bp  5  /* Write error bit 1 position. */
#define NVMCTRL_ERROR_2_bm  (1<<6)  /* Write error bit 2 mask. */
#define NVMCTRL_ERROR_2_bp  6  /* Write error bit 2 position. */

/* NVMCTRL.ADDR  bit masks and bit positions */
#define NVMCTRL_ADDR_gm  0xFFFFFF  /* Address group mask. */
#define NVMCTRL_ADDR_gp  0  /* Address group position. */
#define NVMCTRL_ADDR_0_bm  (1<<0)  /* Address bit 0 mask. */
#define NVMCTRL_ADDR_0_bp  0  /* Address bit 0 position. */
#define NVMCTRL_ADDR_1_bm  (1<<1)  /* Address bit 1 mask. */
#define NVMCTRL_ADDR_1_bp  1  /* Address bit 1 position. */
#define NVMCTRL_ADDR_2_bm  (1<<2)  /* Address bit 2 mask. */
#define NVMCTRL_ADDR_2_bp  2  /* Address bit 2 position. */
#define NVMCTRL_ADDR_3_bm  (1<<3)  /* Address bit 3 mask. */
#define NVMCTRL_ADDR_3_bp  3  /* Address bit 3 position. */
#define NVMCTRL_ADDR_4_bm  (1<<4)  /* Address bit 4 mask. */
#define NVMCTRL_ADDR_4_bp  4  /* Address bit 4 position. */
#define NVMCTRL_ADDR_5_bm  (1<<5)  /* Address bit 5 mask. */
#define NVMCTRL_ADDR_5_bp  5  /* Address bit 5 position. */
#define NVMCTRL_ADDR_6_bm  (1<<6)  /* Address bit 6 mask. */
#define NVMCTRL_ADDR_6_bp  6  /* Address bit 6 position. */
#define NVMCTRL_ADDR_7_bm  (1<<7)  /* Address bit 7 mask. */
#define NVMCTRL_ADDR_7_bp  7  /* Address bit 7 position. */
#define NVMCTRL_ADDR_8_bm  (1<<8)  /* Address bit 8 mask. */
#define NVMCTRL_ADDR_8_bp  8  /* Address bit 8 position. */
#define NVMCTRL_ADDR_9_bm  (1<<9)  /* Address bit 9 mask. */
#define NVMCTRL_ADDR_9_bp  9  /* Address bit 9 position. */
#define NVMCTRL_ADDR_10_bm  (1<<10)  /* Address bit 10 mask. */
#define NVMCTRL_ADDR_10_bp  10  /* Address bit 10 position. */
#define NVMCTRL_ADDR_11_bm  (1<<11)  /* Address bit 11 mask. */
#define NVMCTRL_ADDR_11_bp  11  /* Address bit 11 position. */
#define NVMCTRL_ADDR_12_bm  (1<<12)  /* Address bit 12 mask. */
#define NVMCTRL_ADDR_12_bp  12  /* Address bit 12 position. */
#define NVMCTRL_ADDR_13_bm  (1<<13)  /* Address bit 13 mask. */
#define NVMCTRL_ADDR_13_bp  13  /* Address bit 13 position. */
#define NVMCTRL_ADDR_14_bm  (1<<14)  /* Address bit 14 mask. */
#define NVMCTRL_ADDR_14_bp  14  /* Address bit 14 position. */
#define NVMCTRL_ADDR_15_bm  (1<<15)  /* Address bit 15 mask. */
#define NVMCTRL_ADDR_15_bp  15  /* Address bit 15 position. */
#define NVMCTRL_ADDR_16_bm  (1<<16)  /* Address bit 16 mask. */
#define NVMCTRL_ADDR_16_bp  16  /* Address bit 16 position. */
#define NVMCTRL_ADDR_17_bm  (1<<17)  /* Address bit 17 mask. */
#define NVMCTRL_ADDR_17_bp  17  /* Address bit 17 position. */
#define NVMCTRL_ADDR_18_bm  (1<<18)  /* Address bit 18 mask. */
#define NVMCTRL_ADDR_18_bp  18  /* Address bit 18 position. */
#define NVMCTRL_ADDR_19_bm  (1<<19)  /* Address bit 19 mask. */
#define NVMCTRL_ADDR_19_bp  19  /* Address bit 19 position. */
#define NVMCTRL_ADDR_20_bm  (1<<20)  /* Address bit 20 mask. */
#define NVMCTRL_ADDR_20_bp  20  /* Address bit 20 position. */
#define NVMCTRL_ADDR_21_bm  (1<<21)  /* Address bit 21 mask. */
#define NVMCTRL_ADDR_21_bp  21  /* Address bit 21 position. */
#define NVMCTRL_ADDR_22_bm  (1<<22)  /* Address bit 22 mask. */
#define NVMCTRL_ADDR_22_bp  22  /* Address bit 22 position. */
#define NVMCTRL_ADDR_23_bm  (1<<23)  /* Address bit 23 mask. */
#define NVMCTRL_ADDR_23_bp  23  /* Address bit 23 position. */


/* PORT - I/O Ports */
/* PORT.INTFLAGS  bit masks and bit positions */
#define PORT_INT_gm  0xFF  /* Pin Interrupt Flag group mask. */
#define PORT_INT_gp  0  /* Pin Interrupt Flag group position. */
#define PORT_INT_0_bm  (1<<0)  /* Pin Interrupt Flag bit 0 mask. */
#define PORT_INT_0_bp  0  /* Pin Interrupt Flag bit 0 position. */
#define PORT_INT0_bm  PORT_INT_0_bm  /* This define is deprecated and should not be used */
#define PORT_INT0_bp  PORT_INT_0_bp  /* This define is deprecated and should not be used */
#define PORT_INT_1_bm  (1<<1)  /* Pin Interrupt Flag bit 1 mask. */
#define PORT_INT_1_bp  1  /* Pin Interrupt Flag bit 1 position. */
#define PORT_INT1_bm  PORT_INT_1_bm  /* This define is deprecated and should not be used */
#define PORT_INT1_bp  PORT_INT_1_bp  /* This define is deprecated and should not be used */
#define PORT_INT_2_bm  (1<<2)  /* Pin Interrupt Flag bit 2 mask. */
#define PORT_INT_2_bp  2  /* Pin Interrupt Flag bit 2 position. */
#define PORT_INT2_bm  PORT_INT_2_bm  /* This define is deprecated and should not be used */
#define PORT_INT2_bp  PORT_INT_2_bp  /* This define is deprecated and should not be used */
#define PORT_INT_3_bm  (1<<3)  /* Pin Interrupt Flag bit 3 mask. */
#define PORT_INT_3_bp  3  /* Pin Interrupt Flag bit 3 position. */
#define PORT_INT3_bm  PORT_INT_3_bm  /* This define is deprecated and should not be used */
#define PORT_INT3_bp  PORT_INT_3_bp  /* This define is deprecated and should not be used */
#define PORT_INT_4_bm  (1<<4)  /* Pin Interrupt Flag bit 4 mask. */
#define PORT_INT_4_bp  4  /* Pin Interrupt Flag bit 4 position. */
#define PORT_INT4_bm  PORT_INT_4_bm  /* This define is deprecated and should not be used */
#define PORT_INT4_bp  PORT_INT_4_bp  /* This define is deprecated and should not be used */
#define PORT_INT_5_bm  (1<<5)  /* Pin Interrupt Flag bit 5 mask. */
#define PORT_INT_5_bp  5  /* Pin Interrupt Flag bit 5 position. */
#define PORT_INT5_bm  PORT_INT_5_bm  /* This define is deprecated and should not be used */
#define PORT_INT5_bp  PORT_INT_5_bp  /* This define is deprecated and should not be used */
#define PORT_INT_6_bm  (1<<6)  /* Pin Interrupt Flag bit 6 mask. */
#define PORT_INT_6_bp  6  /* Pin Interrupt Flag bit 6 position. */
#define PORT_INT6_bm  PORT_INT_6_bm  /* This define is deprecated and should not be used */
#define PORT_INT6_bp  PORT_INT_6_bp  /* This define is deprecated and should not be used */
#define PORT_INT_7_bm  (1<<7)  /* Pin Interrupt Flag bit 7 mask. */
#define PORT_INT_7_bp  7  /* Pin Interrupt Flag bit 7 position. */
#define PORT_INT7_bm  PORT_INT_7_bm  /* This define is deprecated and should not be used */
#define PORT_INT7_bp  PORT_INT_7_bp  /* This define is deprecated and should not be used */

/* PORT.PORTCTRL  bit masks and bit positions */
#define PORT_SRL_bm  0x01  /* Slew Rate Limit Enable bit mask. */
#define PORT_SRL_bp  0  /* Slew Rate Limit Enable bit position. */

/* PORT.PINCONFIG  bit masks and bit positions */
#define PORT_ISC_gm  0x07  /* Input/Sense Configuration group mask. */
#define PORT_ISC_gp  0  /* Input/Sense Configuration group position. */
#define PORT_ISC_0_bm  (1<<0)  /* Input/Sense Configuration bit 0 mask. */
#define PORT_ISC_0_bp  0  /* Input/Sense Configuration bit 0 position. */
#define PORT_ISC_1_bm  (1<<1)  /* Input/Sense Configuration bit 1 mask. */
#define PORT_ISC_1_bp  1  /* Input/Sense Configuration bit 1 position. */
#define PORT_ISC_2_bm  (1<<2)  /* Input/Sense Configuration bit 2 mask. */
#define PORT_ISC_2_bp  2  /* Input/Sense Configuration bit 2 position. */
#define PORT_PULLUPEN_bm  0x08  /* Pullup enable bit mask. */
#define PORT_PULLUPEN_bp  3  /* Pullup enable bit position. */
#define PORT_INLVL_bm  0x40  /* Input Level Select bit mask. */
#define PORT_INLVL_bp  6  /* Input Level Select bit position. */
#define PORT_INVEN_bm  0x80  /* Inverted I/O Enable bit mask. */
#define PORT_INVEN_bp  7  /* Inverted I/O Enable bit position. */

/* PORT.PIN0CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN1CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN2CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN3CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN4CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN5CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN6CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.PIN7CTRL  bit masks and bit positions */
/* PORT_ISC  is already defined. */
/* PORT_PULLUPEN  is already defined. */
/* PORT_INLVL  is already defined. */
/* PORT_INVEN  is already defined. */

/* PORT.EVGENCTRLA  bit masks and bit positions */
#define PORT_EVGEN0SEL_gm  0x07  /* Event Generator 0 Select group mask. */
#define PORT_EVGEN0SEL_gp  0  /* Event Generator 0 Select group position. */
#define PORT_EVGEN0SEL_0_bm  (1<<0)  /* Event Generator 0 Select bit 0 mask. */
#define PORT_EVGEN0SEL_0_bp  0  /* Event Generator 0 Select bit 0 position. */
#define PORT_EVGEN0SEL_1_bm  (1<<1)  /* Event Generator 0 Select bit 1 mask. */
#define PORT_EVGEN0SEL_1_bp  1  /* Event Generator 0 Select bit 1 position. */
#define PORT_EVGEN0SEL_2_bm  (1<<2)  /* Event Generator 0 Select bit 2 mask. */
#define PORT_EVGEN0SEL_2_bp  2  /* Event Generator 0 Select bit 2 position. */
#define PORT_EVGEN1SEL_gm  0x70  /* Event Generator 1 Select group mask. */
#define PORT_EVGEN1SEL_gp  4  /* Event Generator 1 Select group position. */
#define PORT_EVGEN1SEL_0_bm  (1<<4)  /* Event Generator 1 Select bit 0 mask. */
#define PORT_EVGEN1SEL_0_bp  4  /* Event Generator 1 Select bit 0 position. */
#define PORT_EVGEN1SEL_1_bm  (1<<5)  /* Event Generator 1 Select bit 1 mask. */
#define PORT_EVGEN1SEL_1_bp  5  /* Event Generator 1 Select bit 1 position. */
#define PORT_EVGEN1SEL_2_bm  (1<<6)  /* Event Generator 1 Select bit 2 mask. */
#define PORT_EVGEN1SEL_2_bp  6  /* Event Generator 1 Select bit 2 position. */


/* PORTMUX - Port Multiplexer */
/* PORTMUX.EVSYSROUTEA  bit masks and bit positions */
#define PORTMUX_EVOUTA_bm  0x01  /* Event Output A bit mask. */
#define PORTMUX_EVOUTA_bp  0  /* Event Output A bit position. */
#define PORTMUX_EVOUTC_bm  0x04  /* Event Output C bit mask. */
#define PORTMUX_EVOUTC_bp  2  /* Event Output C bit position. */
#define PORTMUX_EVOUTD_bm  0x08  /* Event Output D bit mask. */
#define PORTMUX_EVOUTD_bp  3  /* Event Output D bit position. */

/* PORTMUX.CCLROUTEA  bit masks and bit positions */
#define PORTMUX_LUT0_bm  0x01  /* CCL Look-Up Table 0 Signals bit mask. */
#define PORTMUX_LUT0_bp  0  /* CCL Look-Up Table 0 Signals bit position. */
#define PORTMUX_LUT1_bm  0x02  /* CCL Look-Up Table 1 Signals bit mask. */
#define PORTMUX_LUT1_bp  1  /* CCL Look-Up Table 1 Signals bit position. */
#define PORTMUX_LUT2_bm  0x04  /* CCL Look-Up Table 2 Signals bit mask. */
#define PORTMUX_LUT2_bp  2  /* CCL Look-Up Table 2 Signals bit position. */

/* PORTMUX.USARTROUTEA  bit masks and bit positions */
#define PORTMUX_USART0_gm  0x07  /* USART0 Signals group mask. */
#define PORTMUX_USART0_gp  0  /* USART0 Signals group position. */
#define PORTMUX_USART0_0_bm  (1<<0)  /* USART0 Signals bit 0 mask. */
#define PORTMUX_USART0_0_bp  0  /* USART0 Signals bit 0 position. */
#define PORTMUX_USART0_1_bm  (1<<1)  /* USART0 Signals bit 1 mask. */
#define PORTMUX_USART0_1_bp  1  /* USART0 Signals bit 1 position. */
#define PORTMUX_USART0_2_bm  (1<<2)  /* USART0 Signals bit 2 mask. */
#define PORTMUX_USART0_2_bp  2  /* USART0 Signals bit 2 position. */
#define PORTMUX_USART1_gm  0x18  /* USART1 Signals group mask. */
#define PORTMUX_USART1_gp  3  /* USART1 Signals group position. */
#define PORTMUX_USART1_0_bm  (1<<3)  /* USART1 Signals bit 0 mask. */
#define PORTMUX_USART1_0_bp  3  /* USART1 Signals bit 0 position. */
#define PORTMUX_USART1_1_bm  (1<<4)  /* USART1 Signals bit 1 mask. */
#define PORTMUX_USART1_1_bp  4  /* USART1 Signals bit 1 position. */

/* PORTMUX.SPIROUTEA  bit masks and bit positions */
#define PORTMUX_SPI0_gm  0x07  /* SPI0 Signals group mask. */
#define PORTMUX_SPI0_gp  0  /* SPI0 Signals group position. */
#define PORTMUX_SPI0_0_bm  (1<<0)  /* SPI0 Signals bit 0 mask. */
#define PORTMUX_SPI0_0_bp  0  /* SPI0 Signals bit 0 position. */
#define PORTMUX_SPI0_1_bm  (1<<1)  /* SPI0 Signals bit 1 mask. */
#define PORTMUX_SPI0_1_bp  1  /* SPI0 Signals bit 1 position. */
#define PORTMUX_SPI0_2_bm  (1<<2)  /* SPI0 Signals bit 2 mask. */
#define PORTMUX_SPI0_2_bp  2  /* SPI0 Signals bit 2 position. */
#define PORTMUX_SPI1_gm  0x38  /* SPI1 Signals group mask. */
#define PORTMUX_SPI1_gp  3  /* SPI1 Signals group position. */
#define PORTMUX_SPI1_0_bm  (1<<3)  /* SPI1 Signals bit 0 mask. */
#define PORTMUX_SPI1_0_bp  3  /* SPI1 Signals bit 0 position. */
#define PORTMUX_SPI1_1_bm  (1<<4)  /* SPI1 Signals bit 1 mask. */
#define PORTMUX_SPI1_1_bp  4  /* SPI1 Signals bit 1 position. */
#define PORTMUX_SPI1_2_bm  (1<<5)  /* SPI1 Signals bit 2 mask. */
#define PORTMUX_SPI1_2_bp  5  /* SPI1 Signals bit 2 position. */

/* PORTMUX.TWIROUTEA  bit masks and bit positions */
#define PORTMUX_TWI0_gm  0x03  /* TWI0 Signals group mask. */
#define PORTMUX_TWI0_gp  0  /* TWI0 Signals group position. */
#define PORTMUX_TWI0_0_bm  (1<<0)  /* TWI0 Signals bit 0 mask. */
#define PORTMUX_TWI0_0_bp  0  /* TWI0 Signals bit 0 position. */
#define PORTMUX_TWI0_1_bm  (1<<1)  /* TWI0 Signals bit 1 mask. */
#define PORTMUX_TWI0_1_bp  1  /* TWI0 Signals bit 1 position. */

/* PORTMUX.TCAROUTEA  bit masks and bit positions */
#define PORTMUX_TCA0_gm  0x07  /* TCA0 Signals group mask. */
#define PORTMUX_TCA0_gp  0  /* TCA0 Signals group position. */
#define PORTMUX_TCA0_0_bm  (1<<0)  /* TCA0 Signals bit 0 mask. */
#define PORTMUX_TCA0_0_bp  0  /* TCA0 Signals bit 0 position. */
#define PORTMUX_TCA0_1_bm  (1<<1)  /* TCA0 Signals bit 1 mask. */
#define PORTMUX_TCA0_1_bp  1  /* TCA0 Signals bit 1 position. */
#define PORTMUX_TCA0_2_bm  (1<<2)  /* TCA0 Signals bit 2 mask. */
#define PORTMUX_TCA0_2_bp  2  /* TCA0 Signals bit 2 position. */

/* PORTMUX.TCBROUTEA  bit masks and bit positions */
#define PORTMUX_TCB0_bm  0x01  /* TCB0 Output bit mask. */
#define PORTMUX_TCB0_bp  0  /* TCB0 Output bit position. */
#define PORTMUX_TCB1_bm  0x02  /* TCB1 Output bit mask. */
#define PORTMUX_TCB1_bp  1  /* TCB1 Output bit position. */
#define PORTMUX_TCB3_bm  0x08  /* TCB3 Output bit mask. */
#define PORTMUX_TCB3_bp  3  /* TCB3 Output bit position. */

/* PORTMUX.TCDROUTEA  bit masks and bit positions */
#define PORTMUX_TCD0_gm  0x07  /* TCD0 Signals group mask. */
#define PORTMUX_TCD0_gp  0  /* TCD0 Signals group position. */
#define PORTMUX_TCD0_0_bm  (1<<0)  /* TCD0 Signals bit 0 mask. */
#define PORTMUX_TCD0_0_bp  0  /* TCD0 Signals bit 0 position. */
#define PORTMUX_TCD0_1_bm  (1<<1)  /* TCD0 Signals bit 1 mask. */
#define PORTMUX_TCD0_1_bp  1  /* TCD0 Signals bit 1 position. */
#define PORTMUX_TCD0_2_bm  (1<<2)  /* TCD0 Signals bit 2 mask. */
#define PORTMUX_TCD0_2_bp  2  /* TCD0 Signals bit 2 position. */

/* PORTMUX.ACROUTEA  bit masks and bit positions */
#define PORTMUX_AC0_bm  0x01  /* Analog Comparator 0 Output bit mask. */
#define PORTMUX_AC0_bp  0  /* Analog Comparator 0 Output bit position. */
#define PORTMUX_AC1_bm  0x02  /* Analog Comparator 1 Output bit mask. */
#define PORTMUX_AC1_bp  1  /* Analog Comparator 1 Output bit position. */
#define PORTMUX_AC2_bm  0x04  /* Analog Comparator 2 Output bit mask. */
#define PORTMUX_AC2_bp  2  /* Analog Comparator 2 Output bit position. */

/* PORTMUX.ZCDROUTEA  bit masks and bit positions */
#define PORTMUX_ZCD3_bm  0x08  /* Zero Cross Detector 3 Output bit mask. */
#define PORTMUX_ZCD3_bp  3  /* Zero Cross Detector 3 Output bit position. */

/* PORTMUX.ERRCTRLROUTEA  bit masks and bit positions */
#define PORTMUX_HEART_gm  0x07  /* Error Controller Heartbeat Output group mask. */
#define PORTMUX_HEART_gp  0  /* Error Controller Heartbeat Output group position. */
#define PORTMUX_HEART_0_bm  (1<<0)  /* Error Controller Heartbeat Output bit 0 mask. */
#define PORTMUX_HEART_0_bp  0  /* Error Controller Heartbeat Output bit 0 position. */
#define PORTMUX_HEART_1_bm  (1<<1)  /* Error Controller Heartbeat Output bit 1 mask. */
#define PORTMUX_HEART_1_bp  1  /* Error Controller Heartbeat Output bit 1 position. */
#define PORTMUX_HEART_2_bm  (1<<2)  /* Error Controller Heartbeat Output bit 2 mask. */
#define PORTMUX_HEART_2_bp  2  /* Error Controller Heartbeat Output bit 2 position. */


/* RAMCTRL - RAM Controller */
/* RAMCTRL.CTRLA  bit masks and bit positions */
#define RAMCTRL_ECC1_bm  0x01  /* Inject 1-bit ECC Error bit mask. */
#define RAMCTRL_ECC1_bp  0  /* Inject 1-bit ECC Error bit position. */
#define RAMCTRL_ECC2_bm  0x02  /* Inject 2-bit ECC Error bit mask. */
#define RAMCTRL_ECC2_bp  1  /* Inject 2-bit ECC Error bit position. */
#define RAMCTRL_COMP_bm  0x04  /* Inject ECC Compare Error bit mask. */
#define RAMCTRL_COMP_bp  2  /* Inject ECC Compare Error bit position. */
#define RAMCTRL_PARITY_bm  0x08  /* Inject Parity Error bit mask. */
#define RAMCTRL_PARITY_bp  3  /* Inject Parity Error bit position. */

/* RAMCTRL.INTFLAGS  bit masks and bit positions */
/* RAMCTRL_ECC1  is already defined. */
/* RAMCTRL_ECC2  is already defined. */
/* RAMCTRL_COMP  is already defined. */
#define RAMCTRL_PARITYC_bm  0x08  /* Parity Error Detected on Control bit mask. */
#define RAMCTRL_PARITYC_bp  3  /* Parity Error Detected on Control bit position. */
#define RAMCTRL_PARITYA_bm  0x10  /* Parity Error Detected on Address bit mask. */
#define RAMCTRL_PARITYA_bp  4  /* Parity Error Detected on Address bit position. */
#define RAMCTRL_PARITYD_bm  0x20  /* Parity Error Detected on Write Data bit mask. */
#define RAMCTRL_PARITYD_bp  5  /* Parity Error Detected on Write Data bit position. */


/* RSTCTRL - Reset controller */
/* RSTCTRL.RSTFR  bit masks and bit positions */
#define RSTCTRL_PORF_bm  0x01  /* Power-On Reset Flag bit mask. */
#define RSTCTRL_PORF_bp  0  /* Power-On Reset Flag bit position. */
#define RSTCTRL_BORF_bm  0x02  /* Brown-out Detector Reset Flag bit mask. */
#define RSTCTRL_BORF_bp  1  /* Brown-out Detector Reset Flag bit position. */
#define RSTCTRL_EXTRF_bm  0x04  /* External Reset Flag bit mask. */
#define RSTCTRL_EXTRF_bp  2  /* External Reset Flag bit position. */
#define RSTCTRL_WDRF_bm  0x08  /* Watchdog Reset Flag bit mask. */
#define RSTCTRL_WDRF_bp  3  /* Watchdog Reset Flag bit position. */
#define RSTCTRL_SWRF_bm  0x10  /* Software Reset Flag bit mask. */
#define RSTCTRL_SWRF_bp  4  /* Software Reset Flag bit position. */
#define RSTCTRL_UPDIRF_bm  0x20  /* UPDI Reset Flag bit mask. */
#define RSTCTRL_UPDIRF_bp  5  /* UPDI Reset Flag bit position. */
#define RSTCTRL_ECRF_bm  0x40  /* Error Controller Reset Flag bit mask. */
#define RSTCTRL_ECRF_bp  6  /* Error Controller Reset Flag bit position. */
#define RSTCTRL_MCRF_bm  0x80  /* Machine Check Reset Flag bit mask. */
#define RSTCTRL_MCRF_bp  7  /* Machine Check Reset Flag bit position. */

/* RSTCTRL.SWRR  bit masks and bit positions */
#define RSTCTRL_SWRST_bm  0x01  /* Software Reset bit mask. */
#define RSTCTRL_SWRST_bp  0  /* Software Reset bit position. */

/* RSTCTRL.MCFLAGSA  bit masks and bit positions */
#define RSTCTRL_OCD_bm  0x01  /* OCD System Enabled bit mask. */
#define RSTCTRL_OCD_bp  0  /* OCD System Enabled bit position. */
#define RSTCTRL_DFT_bm  0x02  /* Design-for-Test Mechanism Enabled bit mask. */
#define RSTCTRL_DFT_bp  1  /* Design-for-Test Mechanism Enabled bit position. */
#define RSTCTRL_EC_bm  0x04  /* Error Controller Internal Error bit mask. */
#define RSTCTRL_EC_bp  2  /* Error Controller Internal Error bit position. */
#define RSTCTRL_DCLS_bm  0x08  /* Dual Core Lockstep Comparator Mismatch bit mask. */
#define RSTCTRL_DCLS_bp  3  /* Dual Core Lockstep Comparator Mismatch bit position. */
#define RSTCTRL_BOOT_bm  0x10  /* Boot Error Detected bit mask. */
#define RSTCTRL_BOOT_bp  4  /* Boot Error Detected bit position. */
#define RSTCTRL_WDT_bm  0x20  /* WDT Clock Failure Monitor bit mask. */
#define RSTCTRL_WDT_bp  5  /* WDT Clock Failure Monitor bit position. */
#define RSTCTRL_CRC_bm  0x40  /* CRC Scan Error bit mask. */
#define RSTCTRL_CRC_bp  6  /* CRC Scan Error bit position. */
#define RSTCTRL_VREG_bm  0x80  /* Voltage Regulator Monitor bit mask. */
#define RSTCTRL_VREG_bp  7  /* Voltage Regulator Monitor bit position. */

/* RSTCTRL.MCFLAGSB  bit masks and bit positions */
#define RSTCTRL_CFD_bm  0x01  /* Clock Failure Detect bit mask. */
#define RSTCTRL_CFD_bp  0  /* Clock Failure Detect bit position. */
#define RSTCTRL_UPDI_bm  0x02  /* Illegal UPDI bus activity detected bit mask. */
#define RSTCTRL_UPDI_bp  1  /* Illegal UPDI bus activity detected bit position. */


/* RTC - Real-Time Counter */
/* RTC.CTRLA  bit masks and bit positions */
#define RTC_RTCEN_bm  0x01  /* Enable bit mask. */
#define RTC_RTCEN_bp  0  /* Enable bit position. */
#define RTC_PRESCALER_gm  0x78  /* Prescaling Factor group mask. */
#define RTC_PRESCALER_gp  3  /* Prescaling Factor group position. */
#define RTC_PRESCALER_0_bm  (1<<3)  /* Prescaling Factor bit 0 mask. */
#define RTC_PRESCALER_0_bp  3  /* Prescaling Factor bit 0 position. */
#define RTC_PRESCALER_1_bm  (1<<4)  /* Prescaling Factor bit 1 mask. */
#define RTC_PRESCALER_1_bp  4  /* Prescaling Factor bit 1 position. */
#define RTC_PRESCALER_2_bm  (1<<5)  /* Prescaling Factor bit 2 mask. */
#define RTC_PRESCALER_2_bp  5  /* Prescaling Factor bit 2 position. */
#define RTC_PRESCALER_3_bm  (1<<6)  /* Prescaling Factor bit 3 mask. */
#define RTC_PRESCALER_3_bp  6  /* Prescaling Factor bit 3 position. */
#define RTC_RUNSTDBY_bm  0x80  /* Run In Standby bit mask. */
#define RTC_RUNSTDBY_bp  7  /* Run In Standby bit position. */

/* RTC.STATUS  bit masks and bit positions */
#define RTC_CTRLABUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLABUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */
#define RTC_CNTBUSY_bm  0x02  /* Count Synchronization Busy Flag bit mask. */
#define RTC_CNTBUSY_bp  1  /* Count Synchronization Busy Flag bit position. */
#define RTC_PERBUSY_bm  0x04  /* Period Synchronization Busy Flag bit mask. */
#define RTC_PERBUSY_bp  2  /* Period Synchronization Busy Flag bit position. */
#define RTC_CMPBUSY_bm  0x08  /* Comparator Synchronization Busy Flag bit mask. */
#define RTC_CMPBUSY_bp  3  /* Comparator Synchronization Busy Flag bit position. */

/* RTC.INTCTRL  bit masks and bit positions */
#define RTC_OVF_bm  0x01  /* Overflow Interrupt enable bit mask. */
#define RTC_OVF_bp  0  /* Overflow Interrupt enable bit position. */
#define RTC_CMP_bm  0x02  /* Compare Match Interrupt enable bit mask. */
#define RTC_CMP_bp  1  /* Compare Match Interrupt enable bit position. */

/* RTC.INTFLAGS  bit masks and bit positions */
/* RTC_OVF  is already defined. */
/* RTC_CMP  is already defined. */

/* RTC.DBGCTRL  bit masks and bit positions */
#define RTC_DBGRUN_bm  0x01  /* Run in debug bit mask. */
#define RTC_DBGRUN_bp  0  /* Run in debug bit position. */

/* RTC.CLKSEL  bit masks and bit positions */
#define RTC_CLKSEL_gm  0x03  /* Clock Select group mask. */
#define RTC_CLKSEL_gp  0  /* Clock Select group position. */
#define RTC_CLKSEL_0_bm  (1<<0)  /* Clock Select bit 0 mask. */
#define RTC_CLKSEL_0_bp  0  /* Clock Select bit 0 position. */
#define RTC_CLKSEL_1_bm  (1<<1)  /* Clock Select bit 1 mask. */
#define RTC_CLKSEL_1_bp  1  /* Clock Select bit 1 position. */

/* RTC.PITCTRLA  bit masks and bit positions */
#define RTC_PITEN_bm  0x01  /* Enable bit mask. */
#define RTC_PITEN_bp  0  /* Enable bit position. */
#define RTC_PERIOD_gm  0x78  /* Period group mask. */
#define RTC_PERIOD_gp  3  /* Period group position. */
#define RTC_PERIOD_0_bm  (1<<3)  /* Period bit 0 mask. */
#define RTC_PERIOD_0_bp  3  /* Period bit 0 position. */
#define RTC_PERIOD_1_bm  (1<<4)  /* Period bit 1 mask. */
#define RTC_PERIOD_1_bp  4  /* Period bit 1 position. */
#define RTC_PERIOD_2_bm  (1<<5)  /* Period bit 2 mask. */
#define RTC_PERIOD_2_bp  5  /* Period bit 2 position. */
#define RTC_PERIOD_3_bm  (1<<6)  /* Period bit 3 mask. */
#define RTC_PERIOD_3_bp  6  /* Period bit 3 position. */

/* RTC.PITSTATUS  bit masks and bit positions */
#define RTC_CTRLBUSY_bm  0x01  /* CTRLA Synchronization Busy Flag bit mask. */
#define RTC_CTRLBUSY_bp  0  /* CTRLA Synchronization Busy Flag bit position. */

/* RTC.PITINTCTRL  bit masks and bit positions */
#define RTC_PI_bm  0x01  /* Periodic Interrupt bit mask. */
#define RTC_PI_bp  0  /* Periodic Interrupt bit position. */

/* RTC.PITINTFLAGS  bit masks and bit positions */
/* RTC_PI  is already defined. */

/* RTC.PITDBGCTRL  bit masks and bit positions */
/* RTC_DBGRUN  is already defined. */

/* RTC.PITEVGENCTRLA  bit masks and bit positions */
#define RTC_EVGEN0SEL_gm  0x0F  /* Event Generation 0 Select group mask. */
#define RTC_EVGEN0SEL_gp  0  /* Event Generation 0 Select group position. */
#define RTC_EVGEN0SEL_0_bm  (1<<0)  /* Event Generation 0 Select bit 0 mask. */
#define RTC_EVGEN0SEL_0_bp  0  /* Event Generation 0 Select bit 0 position. */
#define RTC_EVGEN0SEL_1_bm  (1<<1)  /* Event Generation 0 Select bit 1 mask. */
#define RTC_EVGEN0SEL_1_bp  1  /* Event Generation 0 Select bit 1 position. */
#define RTC_EVGEN0SEL_2_bm  (1<<2)  /* Event Generation 0 Select bit 2 mask. */
#define RTC_EVGEN0SEL_2_bp  2  /* Event Generation 0 Select bit 2 position. */
#define RTC_EVGEN0SEL_3_bm  (1<<3)  /* Event Generation 0 Select bit 3 mask. */
#define RTC_EVGEN0SEL_3_bp  3  /* Event Generation 0 Select bit 3 position. */
#define RTC_EVGEN1SEL_gm  0xF0  /* Event Generation 1 Select group mask. */
#define RTC_EVGEN1SEL_gp  4  /* Event Generation 1 Select group position. */
#define RTC_EVGEN1SEL_0_bm  (1<<4)  /* Event Generation 1 Select bit 0 mask. */
#define RTC_EVGEN1SEL_0_bp  4  /* Event Generation 1 Select bit 0 position. */
#define RTC_EVGEN1SEL_1_bm  (1<<5)  /* Event Generation 1 Select bit 1 mask. */
#define RTC_EVGEN1SEL_1_bp  5  /* Event Generation 1 Select bit 1 position. */
#define RTC_EVGEN1SEL_2_bm  (1<<6)  /* Event Generation 1 Select bit 2 mask. */
#define RTC_EVGEN1SEL_2_bp  6  /* Event Generation 1 Select bit 2 position. */
#define RTC_EVGEN1SEL_3_bm  (1<<7)  /* Event Generation 1 Select bit 3 mask. */
#define RTC_EVGEN1SEL_3_bp  7  /* Event Generation 1 Select bit 3 position. */


/* SIGROW - Signature row */
/* SIGROW.TEMPSENSE0  bit masks and bit positions */
#define SIGROW_TEMPSENSE0_gm  0xFFFF  /* Temperature Calibration 0 group mask. */
#define SIGROW_TEMPSENSE0_gp  0  /* Temperature Calibration 0 group position. */
#define SIGROW_TEMPSENSE0_0_bm  (1<<0)  /* Temperature Calibration 0 bit 0 mask. */
#define SIGROW_TEMPSENSE0_0_bp  0  /* Temperature Calibration 0 bit 0 position. */
#define SIGROW_TEMPSENSE0_1_bm  (1<<1)  /* Temperature Calibration 0 bit 1 mask. */
#define SIGROW_TEMPSENSE0_1_bp  1  /* Temperature Calibration 0 bit 1 position. */
#define SIGROW_TEMPSENSE0_2_bm  (1<<2)  /* Temperature Calibration 0 bit 2 mask. */
#define SIGROW_TEMPSENSE0_2_bp  2  /* Temperature Calibration 0 bit 2 position. */
#define SIGROW_TEMPSENSE0_3_bm  (1<<3)  /* Temperature Calibration 0 bit 3 mask. */
#define SIGROW_TEMPSENSE0_3_bp  3  /* Temperature Calibration 0 bit 3 position. */
#define SIGROW_TEMPSENSE0_4_bm  (1<<4)  /* Temperature Calibration 0 bit 4 mask. */
#define SIGROW_TEMPSENSE0_4_bp  4  /* Temperature Calibration 0 bit 4 position. */
#define SIGROW_TEMPSENSE0_5_bm  (1<<5)  /* Temperature Calibration 0 bit 5 mask. */
#define SIGROW_TEMPSENSE0_5_bp  5  /* Temperature Calibration 0 bit 5 position. */
#define SIGROW_TEMPSENSE0_6_bm  (1<<6)  /* Temperature Calibration 0 bit 6 mask. */
#define SIGROW_TEMPSENSE0_6_bp  6  /* Temperature Calibration 0 bit 6 position. */
#define SIGROW_TEMPSENSE0_7_bm  (1<<7)  /* Temperature Calibration 0 bit 7 mask. */
#define SIGROW_TEMPSENSE0_7_bp  7  /* Temperature Calibration 0 bit 7 position. */
#define SIGROW_TEMPSENSE0_8_bm  (1<<8)  /* Temperature Calibration 0 bit 8 mask. */
#define SIGROW_TEMPSENSE0_8_bp  8  /* Temperature Calibration 0 bit 8 position. */
#define SIGROW_TEMPSENSE0_9_bm  (1<<9)  /* Temperature Calibration 0 bit 9 mask. */
#define SIGROW_TEMPSENSE0_9_bp  9  /* Temperature Calibration 0 bit 9 position. */
#define SIGROW_TEMPSENSE0_10_bm  (1<<10)  /* Temperature Calibration 0 bit 10 mask. */
#define SIGROW_TEMPSENSE0_10_bp  10  /* Temperature Calibration 0 bit 10 position. */
#define SIGROW_TEMPSENSE0_11_bm  (1<<11)  /* Temperature Calibration 0 bit 11 mask. */
#define SIGROW_TEMPSENSE0_11_bp  11  /* Temperature Calibration 0 bit 11 position. */
#define SIGROW_TEMPSENSE0_12_bm  (1<<12)  /* Temperature Calibration 0 bit 12 mask. */
#define SIGROW_TEMPSENSE0_12_bp  12  /* Temperature Calibration 0 bit 12 position. */
#define SIGROW_TEMPSENSE0_13_bm  (1<<13)  /* Temperature Calibration 0 bit 13 mask. */
#define SIGROW_TEMPSENSE0_13_bp  13  /* Temperature Calibration 0 bit 13 position. */
#define SIGROW_TEMPSENSE0_14_bm  (1<<14)  /* Temperature Calibration 0 bit 14 mask. */
#define SIGROW_TEMPSENSE0_14_bp  14  /* Temperature Calibration 0 bit 14 position. */
#define SIGROW_TEMPSENSE0_15_bm  (1<<15)  /* Temperature Calibration 0 bit 15 mask. */
#define SIGROW_TEMPSENSE0_15_bp  15  /* Temperature Calibration 0 bit 15 position. */

/* SIGROW.TEMPSENSE1  bit masks and bit positions */
#define SIGROW_TEMPSENSE1_gm  0xFFFF  /* Temperature Calibration 1 group mask. */
#define SIGROW_TEMPSENSE1_gp  0  /* Temperature Calibration 1 group position. */
#define SIGROW_TEMPSENSE1_0_bm  (1<<0)  /* Temperature Calibration 1 bit 0 mask. */
#define SIGROW_TEMPSENSE1_0_bp  0  /* Temperature Calibration 1 bit 0 position. */
#define SIGROW_TEMPSENSE1_1_bm  (1<<1)  /* Temperature Calibration 1 bit 1 mask. */
#define SIGROW_TEMPSENSE1_1_bp  1  /* Temperature Calibration 1 bit 1 position. */
#define SIGROW_TEMPSENSE1_2_bm  (1<<2)  /* Temperature Calibration 1 bit 2 mask. */
#define SIGROW_TEMPSENSE1_2_bp  2  /* Temperature Calibration 1 bit 2 position. */
#define SIGROW_TEMPSENSE1_3_bm  (1<<3)  /* Temperature Calibration 1 bit 3 mask. */
#define SIGROW_TEMPSENSE1_3_bp  3  /* Temperature Calibration 1 bit 3 position. */
#define SIGROW_TEMPSENSE1_4_bm  (1<<4)  /* Temperature Calibration 1 bit 4 mask. */
#define SIGROW_TEMPSENSE1_4_bp  4  /* Temperature Calibration 1 bit 4 position. */
#define SIGROW_TEMPSENSE1_5_bm  (1<<5)  /* Temperature Calibration 1 bit 5 mask. */
#define SIGROW_TEMPSENSE1_5_bp  5  /* Temperature Calibration 1 bit 5 position. */
#define SIGROW_TEMPSENSE1_6_bm  (1<<6)  /* Temperature Calibration 1 bit 6 mask. */
#define SIGROW_TEMPSENSE1_6_bp  6  /* Temperature Calibration 1 bit 6 position. */
#define SIGROW_TEMPSENSE1_7_bm  (1<<7)  /* Temperature Calibration 1 bit 7 mask. */
#define SIGROW_TEMPSENSE1_7_bp  7  /* Temperature Calibration 1 bit 7 position. */
#define SIGROW_TEMPSENSE1_8_bm  (1<<8)  /* Temperature Calibration 1 bit 8 mask. */
#define SIGROW_TEMPSENSE1_8_bp  8  /* Temperature Calibration 1 bit 8 position. */
#define SIGROW_TEMPSENSE1_9_bm  (1<<9)  /* Temperature Calibration 1 bit 9 mask. */
#define SIGROW_TEMPSENSE1_9_bp  9  /* Temperature Calibration 1 bit 9 position. */
#define SIGROW_TEMPSENSE1_10_bm  (1<<10)  /* Temperature Calibration 1 bit 10 mask. */
#define SIGROW_TEMPSENSE1_10_bp  10  /* Temperature Calibration 1 bit 10 position. */
#define SIGROW_TEMPSENSE1_11_bm  (1<<11)  /* Temperature Calibration 1 bit 11 mask. */
#define SIGROW_TEMPSENSE1_11_bp  11  /* Temperature Calibration 1 bit 11 position. */
#define SIGROW_TEMPSENSE1_12_bm  (1<<12)  /* Temperature Calibration 1 bit 12 mask. */
#define SIGROW_TEMPSENSE1_12_bp  12  /* Temperature Calibration 1 bit 12 position. */
#define SIGROW_TEMPSENSE1_13_bm  (1<<13)  /* Temperature Calibration 1 bit 13 mask. */
#define SIGROW_TEMPSENSE1_13_bp  13  /* Temperature Calibration 1 bit 13 position. */
#define SIGROW_TEMPSENSE1_14_bm  (1<<14)  /* Temperature Calibration 1 bit 14 mask. */
#define SIGROW_TEMPSENSE1_14_bp  14  /* Temperature Calibration 1 bit 14 position. */
#define SIGROW_TEMPSENSE1_15_bm  (1<<15)  /* Temperature Calibration 1 bit 15 mask. */
#define SIGROW_TEMPSENSE1_15_bp  15  /* Temperature Calibration 1 bit 15 position. */


/* SLPCTRL - Sleep Controller */
/* SLPCTRL.CTRLA  bit masks and bit positions */
#define SLPCTRL_SEN_bm  0x01  /* Sleep enable bit mask. */
#define SLPCTRL_SEN_bp  0  /* Sleep enable bit position. */
#define SLPCTRL_SMODE_gm  0x0E  /* Sleep mode group mask. */
#define SLPCTRL_SMODE_gp  1  /* Sleep mode group position. */
#define SLPCTRL_SMODE_0_bm  (1<<1)  /* Sleep mode bit 0 mask. */
#define SLPCTRL_SMODE_0_bp  1  /* Sleep mode bit 0 position. */
#define SLPCTRL_SMODE_1_bm  (1<<2)  /* Sleep mode bit 1 mask. */
#define SLPCTRL_SMODE_1_bp  2  /* Sleep mode bit 1 position. */
#define SLPCTRL_SMODE_2_bm  (1<<3)  /* Sleep mode bit 2 mask. */
#define SLPCTRL_SMODE_2_bp  3  /* Sleep mode bit 2 position. */

/* SLPCTRL.CTRLB  bit masks and bit positions */
#define SLPCTRL_DMODE_gm  0x03  /* VMON Diagnostic Mode group mask. */
#define SLPCTRL_DMODE_gp  0  /* VMON Diagnostic Mode group position. */
#define SLPCTRL_DMODE_0_bm  (1<<0)  /* VMON Diagnostic Mode bit 0 mask. */
#define SLPCTRL_DMODE_0_bp  0  /* VMON Diagnostic Mode bit 0 position. */
#define SLPCTRL_DMODE_1_bm  (1<<1)  /* VMON Diagnostic Mode bit 1 mask. */
#define SLPCTRL_DMODE_1_bp  1  /* VMON Diagnostic Mode bit 1 position. */

/* SLPCTRL.VREGCTRL  bit masks and bit positions */
#define SLPCTRL_PMODE_gm  0x07  /* Performance Mode group mask. */
#define SLPCTRL_PMODE_gp  0  /* Performance Mode group position. */
#define SLPCTRL_PMODE_0_bm  (1<<0)  /* Performance Mode bit 0 mask. */
#define SLPCTRL_PMODE_0_bp  0  /* Performance Mode bit 0 position. */
#define SLPCTRL_PMODE_1_bm  (1<<1)  /* Performance Mode bit 1 mask. */
#define SLPCTRL_PMODE_1_bp  1  /* Performance Mode bit 1 position. */
#define SLPCTRL_PMODE_2_bm  (1<<2)  /* Performance Mode bit 2 mask. */
#define SLPCTRL_PMODE_2_bp  2  /* Performance Mode bit 2 position. */
#define SLPCTRL_VMONSEN_bm  0x40  /* VMON Sleep Mode Enable bit mask. */
#define SLPCTRL_VMONSEN_bp  6  /* VMON Sleep Mode Enable bit position. */

/* SLPCTRL.INTCTRL  bit masks and bit positions */
#define SLPCTRL_SERR_bm  0x01  /* Sleep Error bit mask. */
#define SLPCTRL_SERR_bp  0  /* Sleep Error bit position. */
#define SLPCTRL_VDIS_bm  0x02  /* VMON is Disabled bit mask. */
#define SLPCTRL_VDIS_bp  1  /* VMON is Disabled bit position. */
#define SLPCTRL_VSLP_bm  0x04  /* VMON is in Sleep Mode bit mask. */
#define SLPCTRL_VSLP_bp  2  /* VMON is in Sleep Mode bit position. */
#define SLPCTRL_VERR_bm  0x08  /* VMON Error bit mask. */
#define SLPCTRL_VERR_bp  3  /* VMON Error bit position. */
#define SLPCTRL_VDEXIT_bm  0x10  /* VMON Diagnostic Mode Exit bit mask. */
#define SLPCTRL_VDEXIT_bp  4  /* VMON Diagnostic Mode Exit bit position. */
#define SLPCTRL_VDENTER_bm  0x20  /* VMON Diagnostic Mode Enter bit mask. */
#define SLPCTRL_VDENTER_bp  5  /* VMON Diagnostic Mode Enter bit position. */
#define SLPCTRL_VUV_bm  0x40  /* VMON Undervoltage Detected bit mask. */
#define SLPCTRL_VUV_bp  6  /* VMON Undervoltage Detected bit position. */
#define SLPCTRL_VOV_bm  0x80  /* VMON Overvoltage Detected bit mask. */
#define SLPCTRL_VOV_bp  7  /* VMON Overvoltage Detected bit position. */

/* SLPCTRL.INTFLAGS  bit masks and bit positions */
/* SLPCTRL_SERR  is already defined. */
/* SLPCTRL_VDIS  is already defined. */
/* SLPCTRL_VSLP  is already defined. */
/* SLPCTRL_VERR  is already defined. */
/* SLPCTRL_VDEXIT  is already defined. */
/* SLPCTRL_VDENTER  is already defined. */
/* SLPCTRL_VUV  is already defined. */
/* SLPCTRL_VOV  is already defined. */


/* SPI - Serial Peripheral Interface */
/* SPI.CTRLA  bit masks and bit positions */
#define SPI_ENABLE_bm  0x01  /* Enable Module bit mask. */
#define SPI_ENABLE_bp  0  /* Enable Module bit position. */
#define SPI_PRESC_gm  0x06  /* Prescaler group mask. */
#define SPI_PRESC_gp  1  /* Prescaler group position. */
#define SPI_PRESC_0_bm  (1<<1)  /* Prescaler bit 0 mask. */
#define SPI_PRESC_0_bp  1  /* Prescaler bit 0 position. */
#define SPI_PRESC_1_bm  (1<<2)  /* Prescaler bit 1 mask. */
#define SPI_PRESC_1_bp  2  /* Prescaler bit 1 position. */
#define SPI_CLK2X_bm  0x10  /* Enable Double Speed bit mask. */
#define SPI_CLK2X_bp  4  /* Enable Double Speed bit position. */
#define SPI_MASTER_bm  0x20  /* Host Operation Enable bit mask. */
#define SPI_MASTER_bp  5  /* Host Operation Enable bit position. */
#define SPI_DORD_bm  0x40  /* Data Order Setting bit mask. */
#define SPI_DORD_bp  6  /* Data Order Setting bit position. */

/* SPI.CTRLB  bit masks and bit positions */
#define SPI_MODE_gm  0x03  /* SPI Mode group mask. */
#define SPI_MODE_gp  0  /* SPI Mode group position. */
#define SPI_MODE_0_bm  (1<<0)  /* SPI Mode bit 0 mask. */
#define SPI_MODE_0_bp  0  /* SPI Mode bit 0 position. */
#define SPI_MODE_1_bm  (1<<1)  /* SPI Mode bit 1 mask. */
#define SPI_MODE_1_bp  1  /* SPI Mode bit 1 position. */
#define SPI_SSD_bm  0x04  /* SPI Select Disable bit mask. */
#define SPI_SSD_bp  2  /* SPI Select Disable bit position. */
#define SPI_BUFWR_bm  0x40  /* Buffer Mode Wait for Receive bit mask. */
#define SPI_BUFWR_bp  6  /* Buffer Mode Wait for Receive bit position. */
#define SPI_BUFEN_bm  0x80  /* Buffer Mode Enable bit mask. */
#define SPI_BUFEN_bp  7  /* Buffer Mode Enable bit position. */

/* SPI.INTCTRL  bit masks and bit positions */
#define SPI_IE_bm  0x01  /* Interrupt Enable bit mask. */
#define SPI_IE_bp  0  /* Interrupt Enable bit position. */
#define SPI_SSIE_bm  0x10  /* SPI Select Trigger Interrupt Enable bit mask. */
#define SPI_SSIE_bp  4  /* SPI Select Trigger Interrupt Enable bit position. */
#define SPI_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define SPI_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define SPI_TXCIE_bm  0x40  /* Transfer Complete Interrupt Enable bit mask. */
#define SPI_TXCIE_bp  6  /* Transfer Complete Interrupt Enable bit position. */
#define SPI_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define SPI_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* SPI.INTFLAGS  bit masks and bit positions */
#define SPI_BUFOVF_bm  0x01  /* Buffer Overflow bit mask. */
#define SPI_BUFOVF_bp  0  /* Buffer Overflow bit position. */
#define SPI_SSIF_bm  0x10  /* SPI Select Trigger Interrupt Flag bit mask. */
#define SPI_SSIF_bp  4  /* SPI Select Trigger Interrupt Flag bit position. */
#define SPI_DREIF_bm  0x20  /* Data Register Empty Interrupt Flag bit mask. */
#define SPI_DREIF_bp  5  /* Data Register Empty Interrupt Flag bit position. */
#define SPI_TXCIF_bm  0x40  /* Transfer Complete Interrupt Flag bit mask. */
#define SPI_TXCIF_bp  6  /* Transfer Complete Interrupt Flag bit position. */
#define SPI_WRCOL_bm  0x40  /* Write Collision bit mask. */
#define SPI_WRCOL_bp  6  /* Write Collision bit position. */
#define SPI_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define SPI_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */
#define SPI_IF_bm  0x80  /* Interrupt Flag bit mask. */
#define SPI_IF_bp  7  /* Interrupt Flag bit position. */


/* SWDT - Synchronous Watchdog Timer */
/* SWDT.CTRLA  bit masks and bit positions */
#define SWDT_ENABLE_bm  0x01  /* Peripheral Enable bit mask. */
#define SWDT_ENABLE_bp  0  /* Peripheral Enable bit position. */
#define SWDT_MODE_bm  0x02  /* Peripheral Mode bit mask. */
#define SWDT_MODE_bp  1  /* Peripheral Mode bit position. */
#define SWDT_LOCK_bm  0x04  /* Register Lock bit mask. */
#define SWDT_LOCK_bp  2  /* Register Lock bit position. */
#define SWDT_CCP_bm  0x08  /* SWDT Register Lock bit mask. */
#define SWDT_CCP_bp  3  /* SWDT Register Lock bit position. */

/* SWDT.CTRLB  bit masks and bit positions */
#define SWDT_TEST_bm  0x01  /* Test bit mask. */
#define SWDT_TEST_bp  0  /* Test bit position. */

/* SWDT.INTCTRL  bit masks and bit positions */
#define SWDT_ERROR_bm  0x08  /* SWDT Error interrupt enable bit mask. */
#define SWDT_ERROR_bp  3  /* SWDT Error interrupt enable bit position. */

/* SWDT.INTFLAGS  bit masks and bit positions */
#define SWDT_CLEAR_bm  0x01  /* Clear Ready bit mask. */
#define SWDT_CLEAR_bp  0  /* Clear Ready bit position. */
#define SWDT_PRECLEAR_bm  0x02  /* Preclear Ready bit mask. */
#define SWDT_PRECLEAR_bp  1  /* Preclear Ready bit position. */
/* SWDT_ERROR  is already defined. */
#define SWDT_EXP_bm  0x10  /* Counter has expired bit mask. */
#define SWDT_EXP_bp  4  /* Counter has expired bit position. */
#define SWDT_UC_bm  0x20  /* Unexpected Command bit mask. */
#define SWDT_UC_bp  5  /* Unexpected Command bit position. */
#define SWDT_BADC_bm  0x40  /* Non-CLEAR Command received while expecting CLEAR bit mask. */
#define SWDT_BADC_bp  6  /* Non-CLEAR Command received while expecting CLEAR bit position. */
#define SWDT_BADPC_bm  0x80  /* Non-PRECLEAR Command received while expecting PRECLEAR bit mask. */
#define SWDT_BADPC_bp  7  /* Non-PRECLEAR Command received while expecting PRECLEAR bit position. */

/* SWDT.CNT  bit masks and bit positions */
#define SWDT_CNT_gm  0xFFFFFF  /* SWDT Counter group mask. */
#define SWDT_CNT_gp  0  /* SWDT Counter group position. */
#define SWDT_CNT_0_bm  (1<<0)  /* SWDT Counter bit 0 mask. */
#define SWDT_CNT_0_bp  0  /* SWDT Counter bit 0 position. */
#define SWDT_CNT_1_bm  (1<<1)  /* SWDT Counter bit 1 mask. */
#define SWDT_CNT_1_bp  1  /* SWDT Counter bit 1 position. */
#define SWDT_CNT_2_bm  (1<<2)  /* SWDT Counter bit 2 mask. */
#define SWDT_CNT_2_bp  2  /* SWDT Counter bit 2 position. */
#define SWDT_CNT_3_bm  (1<<3)  /* SWDT Counter bit 3 mask. */
#define SWDT_CNT_3_bp  3  /* SWDT Counter bit 3 position. */
#define SWDT_CNT_4_bm  (1<<4)  /* SWDT Counter bit 4 mask. */
#define SWDT_CNT_4_bp  4  /* SWDT Counter bit 4 position. */
#define SWDT_CNT_5_bm  (1<<5)  /* SWDT Counter bit 5 mask. */
#define SWDT_CNT_5_bp  5  /* SWDT Counter bit 5 position. */
#define SWDT_CNT_6_bm  (1<<6)  /* SWDT Counter bit 6 mask. */
#define SWDT_CNT_6_bp  6  /* SWDT Counter bit 6 position. */
#define SWDT_CNT_7_bm  (1<<7)  /* SWDT Counter bit 7 mask. */
#define SWDT_CNT_7_bp  7  /* SWDT Counter bit 7 position. */
#define SWDT_CNT_8_bm  (1<<8)  /* SWDT Counter bit 8 mask. */
#define SWDT_CNT_8_bp  8  /* SWDT Counter bit 8 position. */
#define SWDT_CNT_9_bm  (1<<9)  /* SWDT Counter bit 9 mask. */
#define SWDT_CNT_9_bp  9  /* SWDT Counter bit 9 position. */
#define SWDT_CNT_10_bm  (1<<10)  /* SWDT Counter bit 10 mask. */
#define SWDT_CNT_10_bp  10  /* SWDT Counter bit 10 position. */
#define SWDT_CNT_11_bm  (1<<11)  /* SWDT Counter bit 11 mask. */
#define SWDT_CNT_11_bp  11  /* SWDT Counter bit 11 position. */
#define SWDT_CNT_12_bm  (1<<12)  /* SWDT Counter bit 12 mask. */
#define SWDT_CNT_12_bp  12  /* SWDT Counter bit 12 position. */
#define SWDT_CNT_13_bm  (1<<13)  /* SWDT Counter bit 13 mask. */
#define SWDT_CNT_13_bp  13  /* SWDT Counter bit 13 position. */
#define SWDT_CNT_14_bm  (1<<14)  /* SWDT Counter bit 14 mask. */
#define SWDT_CNT_14_bp  14  /* SWDT Counter bit 14 position. */
#define SWDT_CNT_15_bm  (1<<15)  /* SWDT Counter bit 15 mask. */
#define SWDT_CNT_15_bp  15  /* SWDT Counter bit 15 position. */
#define SWDT_CNT_16_bm  (1<<16)  /* SWDT Counter bit 16 mask. */
#define SWDT_CNT_16_bp  16  /* SWDT Counter bit 16 position. */
#define SWDT_CNT_17_bm  (1<<17)  /* SWDT Counter bit 17 mask. */
#define SWDT_CNT_17_bp  17  /* SWDT Counter bit 17 position. */
#define SWDT_CNT_18_bm  (1<<18)  /* SWDT Counter bit 18 mask. */
#define SWDT_CNT_18_bp  18  /* SWDT Counter bit 18 position. */
#define SWDT_CNT_19_bm  (1<<19)  /* SWDT Counter bit 19 mask. */
#define SWDT_CNT_19_bp  19  /* SWDT Counter bit 19 position. */
#define SWDT_CNT_20_bm  (1<<20)  /* SWDT Counter bit 20 mask. */
#define SWDT_CNT_20_bp  20  /* SWDT Counter bit 20 position. */
#define SWDT_CNT_21_bm  (1<<21)  /* SWDT Counter bit 21 mask. */
#define SWDT_CNT_21_bp  21  /* SWDT Counter bit 21 position. */
#define SWDT_CNT_22_bm  (1<<22)  /* SWDT Counter bit 22 mask. */
#define SWDT_CNT_22_bp  22  /* SWDT Counter bit 22 position. */
#define SWDT_CNT_23_bm  (1<<23)  /* SWDT Counter bit 23 mask. */
#define SWDT_CNT_23_bp  23  /* SWDT Counter bit 23 position. */

/* SWDT.RESET  bit masks and bit positions */
#define SWDT_RESET_gm  0xFFFFFF  /* SWDT Counter Reset Value group mask. */
#define SWDT_RESET_gp  0  /* SWDT Counter Reset Value group position. */
#define SWDT_RESET_0_bm  (1<<0)  /* SWDT Counter Reset Value bit 0 mask. */
#define SWDT_RESET_0_bp  0  /* SWDT Counter Reset Value bit 0 position. */
#define SWDT_RESET_1_bm  (1<<1)  /* SWDT Counter Reset Value bit 1 mask. */
#define SWDT_RESET_1_bp  1  /* SWDT Counter Reset Value bit 1 position. */
#define SWDT_RESET_2_bm  (1<<2)  /* SWDT Counter Reset Value bit 2 mask. */
#define SWDT_RESET_2_bp  2  /* SWDT Counter Reset Value bit 2 position. */
#define SWDT_RESET_3_bm  (1<<3)  /* SWDT Counter Reset Value bit 3 mask. */
#define SWDT_RESET_3_bp  3  /* SWDT Counter Reset Value bit 3 position. */
#define SWDT_RESET_4_bm  (1<<4)  /* SWDT Counter Reset Value bit 4 mask. */
#define SWDT_RESET_4_bp  4  /* SWDT Counter Reset Value bit 4 position. */
#define SWDT_RESET_5_bm  (1<<5)  /* SWDT Counter Reset Value bit 5 mask. */
#define SWDT_RESET_5_bp  5  /* SWDT Counter Reset Value bit 5 position. */
#define SWDT_RESET_6_bm  (1<<6)  /* SWDT Counter Reset Value bit 6 mask. */
#define SWDT_RESET_6_bp  6  /* SWDT Counter Reset Value bit 6 position. */
#define SWDT_RESET_7_bm  (1<<7)  /* SWDT Counter Reset Value bit 7 mask. */
#define SWDT_RESET_7_bp  7  /* SWDT Counter Reset Value bit 7 position. */
#define SWDT_RESET_8_bm  (1<<8)  /* SWDT Counter Reset Value bit 8 mask. */
#define SWDT_RESET_8_bp  8  /* SWDT Counter Reset Value bit 8 position. */
#define SWDT_RESET_9_bm  (1<<9)  /* SWDT Counter Reset Value bit 9 mask. */
#define SWDT_RESET_9_bp  9  /* SWDT Counter Reset Value bit 9 position. */
#define SWDT_RESET_10_bm  (1<<10)  /* SWDT Counter Reset Value bit 10 mask. */
#define SWDT_RESET_10_bp  10  /* SWDT Counter Reset Value bit 10 position. */
#define SWDT_RESET_11_bm  (1<<11)  /* SWDT Counter Reset Value bit 11 mask. */
#define SWDT_RESET_11_bp  11  /* SWDT Counter Reset Value bit 11 position. */
#define SWDT_RESET_12_bm  (1<<12)  /* SWDT Counter Reset Value bit 12 mask. */
#define SWDT_RESET_12_bp  12  /* SWDT Counter Reset Value bit 12 position. */
#define SWDT_RESET_13_bm  (1<<13)  /* SWDT Counter Reset Value bit 13 mask. */
#define SWDT_RESET_13_bp  13  /* SWDT Counter Reset Value bit 13 position. */
#define SWDT_RESET_14_bm  (1<<14)  /* SWDT Counter Reset Value bit 14 mask. */
#define SWDT_RESET_14_bp  14  /* SWDT Counter Reset Value bit 14 position. */
#define SWDT_RESET_15_bm  (1<<15)  /* SWDT Counter Reset Value bit 15 mask. */
#define SWDT_RESET_15_bp  15  /* SWDT Counter Reset Value bit 15 position. */
#define SWDT_RESET_16_bm  (1<<16)  /* SWDT Counter Reset Value bit 16 mask. */
#define SWDT_RESET_16_bp  16  /* SWDT Counter Reset Value bit 16 position. */
#define SWDT_RESET_17_bm  (1<<17)  /* SWDT Counter Reset Value bit 17 mask. */
#define SWDT_RESET_17_bp  17  /* SWDT Counter Reset Value bit 17 position. */
#define SWDT_RESET_18_bm  (1<<18)  /* SWDT Counter Reset Value bit 18 mask. */
#define SWDT_RESET_18_bp  18  /* SWDT Counter Reset Value bit 18 position. */
#define SWDT_RESET_19_bm  (1<<19)  /* SWDT Counter Reset Value bit 19 mask. */
#define SWDT_RESET_19_bp  19  /* SWDT Counter Reset Value bit 19 position. */
#define SWDT_RESET_20_bm  (1<<20)  /* SWDT Counter Reset Value bit 20 mask. */
#define SWDT_RESET_20_bp  20  /* SWDT Counter Reset Value bit 20 position. */
#define SWDT_RESET_21_bm  (1<<21)  /* SWDT Counter Reset Value bit 21 mask. */
#define SWDT_RESET_21_bp  21  /* SWDT Counter Reset Value bit 21 position. */
#define SWDT_RESET_22_bm  (1<<22)  /* SWDT Counter Reset Value bit 22 mask. */
#define SWDT_RESET_22_bp  22  /* SWDT Counter Reset Value bit 22 position. */
#define SWDT_RESET_23_bm  (1<<23)  /* SWDT Counter Reset Value bit 23 mask. */
#define SWDT_RESET_23_bp  23  /* SWDT Counter Reset Value bit 23 position. */

/* SWDT.COMMAND  bit masks and bit positions */
#define SWDT_COMMAND_gm  0xFF  /* SWDT Command group mask. */
#define SWDT_COMMAND_gp  0  /* SWDT Command group position. */
#define SWDT_COMMAND_0_bm  (1<<0)  /* SWDT Command bit 0 mask. */
#define SWDT_COMMAND_0_bp  0  /* SWDT Command bit 0 position. */
#define SWDT_COMMAND_1_bm  (1<<1)  /* SWDT Command bit 1 mask. */
#define SWDT_COMMAND_1_bp  1  /* SWDT Command bit 1 position. */
#define SWDT_COMMAND_2_bm  (1<<2)  /* SWDT Command bit 2 mask. */
#define SWDT_COMMAND_2_bp  2  /* SWDT Command bit 2 position. */
#define SWDT_COMMAND_3_bm  (1<<3)  /* SWDT Command bit 3 mask. */
#define SWDT_COMMAND_3_bp  3  /* SWDT Command bit 3 position. */
#define SWDT_COMMAND_4_bm  (1<<4)  /* SWDT Command bit 4 mask. */
#define SWDT_COMMAND_4_bp  4  /* SWDT Command bit 4 position. */
#define SWDT_COMMAND_5_bm  (1<<5)  /* SWDT Command bit 5 mask. */
#define SWDT_COMMAND_5_bp  5  /* SWDT Command bit 5 position. */
#define SWDT_COMMAND_6_bm  (1<<6)  /* SWDT Command bit 6 mask. */
#define SWDT_COMMAND_6_bp  6  /* SWDT Command bit 6 position. */
#define SWDT_COMMAND_7_bm  (1<<7)  /* SWDT Command bit 7 mask. */
#define SWDT_COMMAND_7_bp  7  /* SWDT Command bit 7 position. */


/* SYSCFG - System Configuration Registers */
/* SYSCFG.REVID  bit masks and bit positions */
#define SYSCFG_MINOR_gm  0x0F  /* Minor Revision group mask. */
#define SYSCFG_MINOR_gp  0  /* Minor Revision group position. */
#define SYSCFG_MINOR_0_bm  (1<<0)  /* Minor Revision bit 0 mask. */
#define SYSCFG_MINOR_0_bp  0  /* Minor Revision bit 0 position. */
#define SYSCFG_MINOR_1_bm  (1<<1)  /* Minor Revision bit 1 mask. */
#define SYSCFG_MINOR_1_bp  1  /* Minor Revision bit 1 position. */
#define SYSCFG_MINOR_2_bm  (1<<2)  /* Minor Revision bit 2 mask. */
#define SYSCFG_MINOR_2_bp  2  /* Minor Revision bit 2 position. */
#define SYSCFG_MINOR_3_bm  (1<<3)  /* Minor Revision bit 3 mask. */
#define SYSCFG_MINOR_3_bp  3  /* Minor Revision bit 3 position. */
#define SYSCFG_MAJOR_gm  0xF0  /* Major Revision group mask. */
#define SYSCFG_MAJOR_gp  4  /* Major Revision group position. */
#define SYSCFG_MAJOR_0_bm  (1<<4)  /* Major Revision bit 0 mask. */
#define SYSCFG_MAJOR_0_bp  4  /* Major Revision bit 0 position. */
#define SYSCFG_MAJOR_1_bm  (1<<5)  /* Major Revision bit 1 mask. */
#define SYSCFG_MAJOR_1_bp  5  /* Major Revision bit 1 position. */
#define SYSCFG_MAJOR_2_bm  (1<<6)  /* Major Revision bit 2 mask. */
#define SYSCFG_MAJOR_2_bp  6  /* Major Revision bit 2 position. */
#define SYSCFG_MAJOR_3_bm  (1<<7)  /* Major Revision bit 3 mask. */
#define SYSCFG_MAJOR_3_bp  7  /* Major Revision bit 3 position. */


/* TCA - 16-bit Timer/Counter Type A */
/* TCA_SINGLE.CTRLA  bit masks and bit positions */
#define TCA_SINGLE_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SINGLE_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SINGLE_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SINGLE_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SINGLE_CLKSEL_0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SINGLE_CLKSEL_0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SINGLE_CLKSEL_1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SINGLE_CLKSEL_1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SINGLE_CLKSEL_2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SINGLE_CLKSEL_2_bp  3  /* Clock Selection bit 2 position. */
#define TCA_SINGLE_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define TCA_SINGLE_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* TCA_SINGLE.CTRLB  bit masks and bit positions */
#define TCA_SINGLE_WGMODE_gm  0x07  /* Waveform generation mode group mask. */
#define TCA_SINGLE_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCA_SINGLE_WGMODE_0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCA_SINGLE_WGMODE_0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCA_SINGLE_WGMODE_1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCA_SINGLE_WGMODE_1_bp  1  /* Waveform generation mode bit 1 position. */
#define TCA_SINGLE_WGMODE_2_bm  (1<<2)  /* Waveform generation mode bit 2 mask. */
#define TCA_SINGLE_WGMODE_2_bp  2  /* Waveform generation mode bit 2 position. */
#define TCA_SINGLE_ALUPD_bm  0x08  /* Auto Lock Update bit mask. */
#define TCA_SINGLE_ALUPD_bp  3  /* Auto Lock Update bit position. */
#define TCA_SINGLE_CMP0EN_bm  0x10  /* Compare 0 Enable bit mask. */
#define TCA_SINGLE_CMP0EN_bp  4  /* Compare 0 Enable bit position. */
#define TCA_SINGLE_CMP1EN_bm  0x20  /* Compare 1 Enable bit mask. */
#define TCA_SINGLE_CMP1EN_bp  5  /* Compare 1 Enable bit position. */
#define TCA_SINGLE_CMP2EN_bm  0x40  /* Compare 2 Enable bit mask. */
#define TCA_SINGLE_CMP2EN_bp  6  /* Compare 2 Enable bit position. */

/* TCA_SINGLE.CTRLC  bit masks and bit positions */
#define TCA_SINGLE_CMP0OV_bm  0x01  /* Compare 0 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP0OV_bp  0  /* Compare 0 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP1OV_bm  0x02  /* Compare 1 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP1OV_bp  1  /* Compare 1 Waveform Output Value bit position. */
#define TCA_SINGLE_CMP2OV_bm  0x04  /* Compare 2 Waveform Output Value bit mask. */
#define TCA_SINGLE_CMP2OV_bp  2  /* Compare 2 Waveform Output Value bit position. */

/* TCA_SINGLE.CTRLD  bit masks and bit positions */
#define TCA_SINGLE_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SINGLE_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SINGLE.CTRLECLR  bit masks and bit positions */
#define TCA_SINGLE_DIR_bm  0x01  /* Direction bit mask. */
#define TCA_SINGLE_DIR_bp  0  /* Direction bit position. */
#define TCA_SINGLE_LUPD_bm  0x02  /* Lock Update bit mask. */
#define TCA_SINGLE_LUPD_bp  1  /* Lock Update bit position. */
#define TCA_SINGLE_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SINGLE_CMD_gp  2  /* Command group position. */
#define TCA_SINGLE_CMD_0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SINGLE_CMD_0_bp  2  /* Command bit 0 position. */
#define TCA_SINGLE_CMD_1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SINGLE_CMD_1_bp  3  /* Command bit 1 position. */

/* TCA_SINGLE.CTRLESET  bit masks and bit positions */
/* TCA_SINGLE_DIR  is already defined. */
/* TCA_SINGLE_LUPD  is already defined. */
/* TCA_SINGLE_CMD  is already defined. */

/* TCA_SINGLE.CTRLFCLR  bit masks and bit positions */
#define TCA_SINGLE_PERBV_bm  0x01  /* Period Buffer Valid bit mask. */
#define TCA_SINGLE_PERBV_bp  0  /* Period Buffer Valid bit position. */
#define TCA_SINGLE_CMP0BV_bm  0x02  /* Compare 0 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP0BV_bp  1  /* Compare 0 Buffer Valid bit position. */
#define TCA_SINGLE_CMP1BV_bm  0x04  /* Compare 1 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP1BV_bp  2  /* Compare 1 Buffer Valid bit position. */
#define TCA_SINGLE_CMP2BV_bm  0x08  /* Compare 2 Buffer Valid bit mask. */
#define TCA_SINGLE_CMP2BV_bp  3  /* Compare 2 Buffer Valid bit position. */

/* TCA_SINGLE.CTRLFSET  bit masks and bit positions */
/* TCA_SINGLE_PERBV  is already defined. */
/* TCA_SINGLE_CMP0BV  is already defined. */
/* TCA_SINGLE_CMP1BV  is already defined. */
/* TCA_SINGLE_CMP2BV  is already defined. */

/* TCA_SINGLE.EVCTRL  bit masks and bit positions */
#define TCA_SINGLE_CNTAEI_bm  0x01  /* Count on Event Input A bit mask. */
#define TCA_SINGLE_CNTAEI_bp  0  /* Count on Event Input A bit position. */
#define TCA_SINGLE_EVACTA_gm  0x0E  /* Event Action A group mask. */
#define TCA_SINGLE_EVACTA_gp  1  /* Event Action A group position. */
#define TCA_SINGLE_EVACTA_0_bm  (1<<1)  /* Event Action A bit 0 mask. */
#define TCA_SINGLE_EVACTA_0_bp  1  /* Event Action A bit 0 position. */
#define TCA_SINGLE_EVACTA_1_bm  (1<<2)  /* Event Action A bit 1 mask. */
#define TCA_SINGLE_EVACTA_1_bp  2  /* Event Action A bit 1 position. */
#define TCA_SINGLE_EVACTA_2_bm  (1<<3)  /* Event Action A bit 2 mask. */
#define TCA_SINGLE_EVACTA_2_bp  3  /* Event Action A bit 2 position. */
#define TCA_SINGLE_CNTBEI_bm  0x10  /* Count on Event Input B bit mask. */
#define TCA_SINGLE_CNTBEI_bp  4  /* Count on Event Input B bit position. */
#define TCA_SINGLE_EVACTB_gm  0xE0  /* Event Action B group mask. */
#define TCA_SINGLE_EVACTB_gp  5  /* Event Action B group position. */
#define TCA_SINGLE_EVACTB_0_bm  (1<<5)  /* Event Action B bit 0 mask. */
#define TCA_SINGLE_EVACTB_0_bp  5  /* Event Action B bit 0 position. */
#define TCA_SINGLE_EVACTB_1_bm  (1<<6)  /* Event Action B bit 1 mask. */
#define TCA_SINGLE_EVACTB_1_bp  6  /* Event Action B bit 1 position. */
#define TCA_SINGLE_EVACTB_2_bm  (1<<7)  /* Event Action B bit 2 mask. */
#define TCA_SINGLE_EVACTB_2_bp  7  /* Event Action B bit 2 position. */

/* TCA_SINGLE.INTCTRL  bit masks and bit positions */
#define TCA_SINGLE_OVF_bm  0x01  /* Overflow Interrupt bit mask. */
#define TCA_SINGLE_OVF_bp  0  /* Overflow Interrupt bit position. */
#define TCA_SINGLE_CMP0_bm  0x10  /* Compare 0 Interrupt bit mask. */
#define TCA_SINGLE_CMP0_bp  4  /* Compare 0 Interrupt bit position. */
#define TCA_SINGLE_CMP1_bm  0x20  /* Compare 1 Interrupt bit mask. */
#define TCA_SINGLE_CMP1_bp  5  /* Compare 1 Interrupt bit position. */
#define TCA_SINGLE_CMP2_bm  0x40  /* Compare 2 Interrupt bit mask. */
#define TCA_SINGLE_CMP2_bp  6  /* Compare 2 Interrupt bit position. */

/* TCA_SINGLE.INTFLAGS  bit masks and bit positions */
/* TCA_SINGLE_OVF  is already defined. */
/* TCA_SINGLE_CMP0  is already defined. */
/* TCA_SINGLE_CMP1  is already defined. */
/* TCA_SINGLE_CMP2  is already defined. */

/* TCA_SINGLE.DBGCTRL  bit masks and bit positions */
#define TCA_SINGLE_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SINGLE_DBGRUN_bp  0  /* Debug Run bit position. */

/* TCA_SPLIT.CTRLA  bit masks and bit positions */
#define TCA_SPLIT_ENABLE_bm  0x01  /* Module Enable bit mask. */
#define TCA_SPLIT_ENABLE_bp  0  /* Module Enable bit position. */
#define TCA_SPLIT_CLKSEL_gm  0x0E  /* Clock Selection group mask. */
#define TCA_SPLIT_CLKSEL_gp  1  /* Clock Selection group position. */
#define TCA_SPLIT_CLKSEL_0_bm  (1<<1)  /* Clock Selection bit 0 mask. */
#define TCA_SPLIT_CLKSEL_0_bp  1  /* Clock Selection bit 0 position. */
#define TCA_SPLIT_CLKSEL_1_bm  (1<<2)  /* Clock Selection bit 1 mask. */
#define TCA_SPLIT_CLKSEL_1_bp  2  /* Clock Selection bit 1 position. */
#define TCA_SPLIT_CLKSEL_2_bm  (1<<3)  /* Clock Selection bit 2 mask. */
#define TCA_SPLIT_CLKSEL_2_bp  3  /* Clock Selection bit 2 position. */
#define TCA_SPLIT_RUNSTDBY_bm  0x80  /* Run in Standby bit mask. */
#define TCA_SPLIT_RUNSTDBY_bp  7  /* Run in Standby bit position. */

/* TCA_SPLIT.CTRLB  bit masks and bit positions */
#define TCA_SPLIT_LCMP0EN_bm  0x01  /* Low Compare 0 Enable bit mask. */
#define TCA_SPLIT_LCMP0EN_bp  0  /* Low Compare 0 Enable bit position. */
#define TCA_SPLIT_LCMP1EN_bm  0x02  /* Low Compare 1 Enable bit mask. */
#define TCA_SPLIT_LCMP1EN_bp  1  /* Low Compare 1 Enable bit position. */
#define TCA_SPLIT_LCMP2EN_bm  0x04  /* Low Compare 2 Enable bit mask. */
#define TCA_SPLIT_LCMP2EN_bp  2  /* Low Compare 2 Enable bit position. */
#define TCA_SPLIT_HCMP0EN_bm  0x10  /* High Compare 0 Enable bit mask. */
#define TCA_SPLIT_HCMP0EN_bp  4  /* High Compare 0 Enable bit position. */
#define TCA_SPLIT_HCMP1EN_bm  0x20  /* High Compare 1 Enable bit mask. */
#define TCA_SPLIT_HCMP1EN_bp  5  /* High Compare 1 Enable bit position. */
#define TCA_SPLIT_HCMP2EN_bm  0x40  /* High Compare 2 Enable bit mask. */
#define TCA_SPLIT_HCMP2EN_bp  6  /* High Compare 2 Enable bit position. */

/* TCA_SPLIT.CTRLC  bit masks and bit positions */
#define TCA_SPLIT_LCMP0OV_bm  0x01  /* Low Compare 0 Output Value bit mask. */
#define TCA_SPLIT_LCMP0OV_bp  0  /* Low Compare 0 Output Value bit position. */
#define TCA_SPLIT_LCMP1OV_bm  0x02  /* Low Compare 1 Output Value bit mask. */
#define TCA_SPLIT_LCMP1OV_bp  1  /* Low Compare 1 Output Value bit position. */
#define TCA_SPLIT_LCMP2OV_bm  0x04  /* Low Compare 2 Output Value bit mask. */
#define TCA_SPLIT_LCMP2OV_bp  2  /* Low Compare 2 Output Value bit position. */
#define TCA_SPLIT_HCMP0OV_bm  0x10  /* High Compare 0 Output Value bit mask. */
#define TCA_SPLIT_HCMP0OV_bp  4  /* High Compare 0 Output Value bit position. */
#define TCA_SPLIT_HCMP1OV_bm  0x20  /* High Compare 1 Output Value bit mask. */
#define TCA_SPLIT_HCMP1OV_bp  5  /* High Compare 1 Output Value bit position. */
#define TCA_SPLIT_HCMP2OV_bm  0x40  /* High Compare 2 Output Value bit mask. */
#define TCA_SPLIT_HCMP2OV_bp  6  /* High Compare 2 Output Value bit position. */

/* TCA_SPLIT.CTRLD  bit masks and bit positions */
#define TCA_SPLIT_SPLITM_bm  0x01  /* Split Mode Enable bit mask. */
#define TCA_SPLIT_SPLITM_bp  0  /* Split Mode Enable bit position. */

/* TCA_SPLIT.CTRLECLR  bit masks and bit positions */
#define TCA_SPLIT_CMDEN_gm  0x03  /* Command Enable group mask. */
#define TCA_SPLIT_CMDEN_gp  0  /* Command Enable group position. */
#define TCA_SPLIT_CMDEN_0_bm  (1<<0)  /* Command Enable bit 0 mask. */
#define TCA_SPLIT_CMDEN_0_bp  0  /* Command Enable bit 0 position. */
#define TCA_SPLIT_CMDEN_1_bm  (1<<1)  /* Command Enable bit 1 mask. */
#define TCA_SPLIT_CMDEN_1_bp  1  /* Command Enable bit 1 position. */
#define TCA_SPLIT_CMD_gm  0x0C  /* Command group mask. */
#define TCA_SPLIT_CMD_gp  2  /* Command group position. */
#define TCA_SPLIT_CMD_0_bm  (1<<2)  /* Command bit 0 mask. */
#define TCA_SPLIT_CMD_0_bp  2  /* Command bit 0 position. */
#define TCA_SPLIT_CMD_1_bm  (1<<3)  /* Command bit 1 mask. */
#define TCA_SPLIT_CMD_1_bp  3  /* Command bit 1 position. */

/* TCA_SPLIT.CTRLESET  bit masks and bit positions */
/* TCA_SPLIT_CMDEN  is already defined. */
/* TCA_SPLIT_CMD  is already defined. */

/* TCA_SPLIT.INTCTRL  bit masks and bit positions */
#define TCA_SPLIT_LUNF_bm  0x01  /* Low Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_LUNF_bp  0  /* Low Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_HUNF_bm  0x02  /* High Underflow Interrupt Enable bit mask. */
#define TCA_SPLIT_HUNF_bp  1  /* High Underflow Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP0_bm  0x10  /* Low Compare 0 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP0_bp  4  /* Low Compare 0 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP1_bm  0x20  /* Low Compare 1 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP1_bp  5  /* Low Compare 1 Interrupt Enable bit position. */
#define TCA_SPLIT_LCMP2_bm  0x40  /* Low Compare 2 Interrupt Enable bit mask. */
#define TCA_SPLIT_LCMP2_bp  6  /* Low Compare 2 Interrupt Enable bit position. */

/* TCA_SPLIT.INTFLAGS  bit masks and bit positions */
/* TCA_SPLIT_LUNF  is already defined. */
/* TCA_SPLIT_HUNF  is already defined. */
/* TCA_SPLIT_LCMP0  is already defined. */
/* TCA_SPLIT_LCMP1  is already defined. */
/* TCA_SPLIT_LCMP2  is already defined. */

/* TCA_SPLIT.DBGCTRL  bit masks and bit positions */
#define TCA_SPLIT_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCA_SPLIT_DBGRUN_bp  0  /* Debug Run bit position. */


/* TCB - 16-bit Timer Type B */
/* TCB.CTRLA  bit masks and bit positions */
#define TCB_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCB_ENABLE_bp  0  /* Enable bit position. */
#define TCB_CLKSEL_gm  0x0E  /* Clock Select group mask. */
#define TCB_CLKSEL_gp  1  /* Clock Select group position. */
#define TCB_CLKSEL_0_bm  (1<<1)  /* Clock Select bit 0 mask. */
#define TCB_CLKSEL_0_bp  1  /* Clock Select bit 0 position. */
#define TCB_CLKSEL_1_bm  (1<<2)  /* Clock Select bit 1 mask. */
#define TCB_CLKSEL_1_bp  2  /* Clock Select bit 1 position. */
#define TCB_CLKSEL_2_bm  (1<<3)  /* Clock Select bit 2 mask. */
#define TCB_CLKSEL_2_bp  3  /* Clock Select bit 2 position. */
#define TCB_SYNCUPD_bm  0x10  /* Synchronize Update bit mask. */
#define TCB_SYNCUPD_bp  4  /* Synchronize Update bit position. */
#define TCB_CASCADE_bm  0x20  /* Cascade two timers bit mask. */
#define TCB_CASCADE_bp  5  /* Cascade two timers bit position. */
#define TCB_RUNSTDBY_bm  0x40  /* Run Standby bit mask. */
#define TCB_RUNSTDBY_bp  6  /* Run Standby bit position. */

/* TCB.CTRLB  bit masks and bit positions */
#define TCB_CNTMODE_gm  0x07  /* Timer Mode group mask. */
#define TCB_CNTMODE_gp  0  /* Timer Mode group position. */
#define TCB_CNTMODE_0_bm  (1<<0)  /* Timer Mode bit 0 mask. */
#define TCB_CNTMODE_0_bp  0  /* Timer Mode bit 0 position. */
#define TCB_CNTMODE_1_bm  (1<<1)  /* Timer Mode bit 1 mask. */
#define TCB_CNTMODE_1_bp  1  /* Timer Mode bit 1 position. */
#define TCB_CNTMODE_2_bm  (1<<2)  /* Timer Mode bit 2 mask. */
#define TCB_CNTMODE_2_bp  2  /* Timer Mode bit 2 position. */
#define TCB_CCMPEN_bm  0x10  /* Pin Output Enable bit mask. */
#define TCB_CCMPEN_bp  4  /* Pin Output Enable bit position. */
#define TCB_CCMPINIT_bm  0x20  /* Pin Initial State bit mask. */
#define TCB_CCMPINIT_bp  5  /* Pin Initial State bit position. */
#define TCB_ASYNC_bm  0x40  /* Asynchronous Enable bit mask. */
#define TCB_ASYNC_bp  6  /* Asynchronous Enable bit position. */

/* TCB.EVCTRL  bit masks and bit positions */
#define TCB_CAPTEI_bm  0x01  /* Event Input Enable bit mask. */
#define TCB_CAPTEI_bp  0  /* Event Input Enable bit position. */
#define TCB_EDGE_bm  0x10  /* Event Edge bit mask. */
#define TCB_EDGE_bp  4  /* Event Edge bit position. */
#define TCB_FILTER_bm  0x40  /* Input Capture Noise Cancellation Filter bit mask. */
#define TCB_FILTER_bp  6  /* Input Capture Noise Cancellation Filter bit position. */

/* TCB.INTCTRL  bit masks and bit positions */
#define TCB_CAPT_bm  0x01  /* Capture or Timeout bit mask. */
#define TCB_CAPT_bp  0  /* Capture or Timeout bit position. */
#define TCB_OVF_bm  0x02  /* Overflow bit mask. */
#define TCB_OVF_bp  1  /* Overflow bit position. */

/* TCB.INTFLAGS  bit masks and bit positions */
/* TCB_CAPT  is already defined. */
/* TCB_OVF  is already defined. */

/* TCB.STATUS  bit masks and bit positions */
#define TCB_RUN_bm  0x01  /* Run bit mask. */
#define TCB_RUN_bp  0  /* Run bit position. */

/* TCB.DBGCTRL  bit masks and bit positions */
#define TCB_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TCB_DBGRUN_bp  0  /* Debug Run bit position. */


/* TCD - Timer Counter D */
/* TCD.CTRLA  bit masks and bit positions */
#define TCD_ENABLE_bm  0x01  /* Enable bit mask. */
#define TCD_ENABLE_bp  0  /* Enable bit position. */
#define TCD_SYNCPRES_gm  0x06  /* Synchronization prescaler group mask. */
#define TCD_SYNCPRES_gp  1  /* Synchronization prescaler group position. */
#define TCD_SYNCPRES_0_bm  (1<<1)  /* Synchronization prescaler bit 0 mask. */
#define TCD_SYNCPRES_0_bp  1  /* Synchronization prescaler bit 0 position. */
#define TCD_SYNCPRES_1_bm  (1<<2)  /* Synchronization prescaler bit 1 mask. */
#define TCD_SYNCPRES_1_bp  2  /* Synchronization prescaler bit 1 position. */
#define TCD_CNTPRES_gm  0x18  /* Counter prescaler group mask. */
#define TCD_CNTPRES_gp  3  /* Counter prescaler group position. */
#define TCD_CNTPRES_0_bm  (1<<3)  /* Counter prescaler bit 0 mask. */
#define TCD_CNTPRES_0_bp  3  /* Counter prescaler bit 0 position. */
#define TCD_CNTPRES_1_bm  (1<<4)  /* Counter prescaler bit 1 mask. */
#define TCD_CNTPRES_1_bp  4  /* Counter prescaler bit 1 position. */
#define TCD_CLKSEL_gm  0x60  /* Clock select group mask. */
#define TCD_CLKSEL_gp  5  /* Clock select group position. */
#define TCD_CLKSEL_0_bm  (1<<5)  /* Clock select bit 0 mask. */
#define TCD_CLKSEL_0_bp  5  /* Clock select bit 0 position. */
#define TCD_CLKSEL_1_bm  (1<<6)  /* Clock select bit 1 mask. */
#define TCD_CLKSEL_1_bp  6  /* Clock select bit 1 position. */

/* TCD.CTRLB  bit masks and bit positions */
#define TCD_WGMODE_gm  0x03  /* Waveform generation mode group mask. */
#define TCD_WGMODE_gp  0  /* Waveform generation mode group position. */
#define TCD_WGMODE_0_bm  (1<<0)  /* Waveform generation mode bit 0 mask. */
#define TCD_WGMODE_0_bp  0  /* Waveform generation mode bit 0 position. */
#define TCD_WGMODE_1_bm  (1<<1)  /* Waveform generation mode bit 1 mask. */
#define TCD_WGMODE_1_bp  1  /* Waveform generation mode bit 1 position. */

/* TCD.CTRLC  bit masks and bit positions */
#define TCD_CMPOVR_bm  0x01  /* Compare output value override bit mask. */
#define TCD_CMPOVR_bp  0  /* Compare output value override bit position. */
#define TCD_AUPDATE_bm  0x02  /* Auto update bit mask. */
#define TCD_AUPDATE_bp  1  /* Auto update bit position. */
#define TCD_FIFTY_bm  0x08  /* Fifty percent waveform bit mask. */
#define TCD_FIFTY_bp  3  /* Fifty percent waveform bit position. */
#define TCD_CMPCSEL_bm  0x40  /* Compare C output select bit mask. */
#define TCD_CMPCSEL_bp  6  /* Compare C output select bit position. */
#define TCD_CMPDSEL_bm  0x80  /* Compare D output select bit mask. */
#define TCD_CMPDSEL_bp  7  /* Compare D output select bit position. */

/* TCD.CTRLD  bit masks and bit positions */
#define TCD_CMPAVAL_gm  0x0F  /* Compare A value group mask. */
#define TCD_CMPAVAL_gp  0  /* Compare A value group position. */
#define TCD_CMPAVAL_0_bm  (1<<0)  /* Compare A value bit 0 mask. */
#define TCD_CMPAVAL_0_bp  0  /* Compare A value bit 0 position. */
#define TCD_CMPAVAL_1_bm  (1<<1)  /* Compare A value bit 1 mask. */
#define TCD_CMPAVAL_1_bp  1  /* Compare A value bit 1 position. */
#define TCD_CMPAVAL_2_bm  (1<<2)  /* Compare A value bit 2 mask. */
#define TCD_CMPAVAL_2_bp  2  /* Compare A value bit 2 position. */
#define TCD_CMPAVAL_3_bm  (1<<3)  /* Compare A value bit 3 mask. */
#define TCD_CMPAVAL_3_bp  3  /* Compare A value bit 3 position. */
#define TCD_CMPBVAL_gm  0xF0  /* Compare B value group mask. */
#define TCD_CMPBVAL_gp  4  /* Compare B value group position. */
#define TCD_CMPBVAL_0_bm  (1<<4)  /* Compare B value bit 0 mask. */
#define TCD_CMPBVAL_0_bp  4  /* Compare B value bit 0 position. */
#define TCD_CMPBVAL_1_bm  (1<<5)  /* Compare B value bit 1 mask. */
#define TCD_CMPBVAL_1_bp  5  /* Compare B value bit 1 position. */
#define TCD_CMPBVAL_2_bm  (1<<6)  /* Compare B value bit 2 mask. */
#define TCD_CMPBVAL_2_bp  6  /* Compare B value bit 2 position. */
#define TCD_CMPBVAL_3_bm  (1<<7)  /* Compare B value bit 3 mask. */
#define TCD_CMPBVAL_3_bp  7  /* Compare B value bit 3 position. */

/* TCD.CTRLE  bit masks and bit positions */
#define TCD_SYNCEOC_bm  0x01  /* Synchronize end of cycle strobe bit mask. */
#define TCD_SYNCEOC_bp  0  /* Synchronize end of cycle strobe bit position. */
#define TCD_SYNC_bm  0x02  /* synchronize strobe bit mask. */
#define TCD_SYNC_bp  1  /* synchronize strobe bit position. */
#define TCD_RESTART_bm  0x04  /* Restart strobe bit mask. */
#define TCD_RESTART_bp  2  /* Restart strobe bit position. */
#define TCD_SCAPTUREA_bm  0x08  /* Software Capture A Strobe bit mask. */
#define TCD_SCAPTUREA_bp  3  /* Software Capture A Strobe bit position. */
#define TCD_SCAPTUREB_bm  0x10  /* Software Capture B Strobe bit mask. */
#define TCD_SCAPTUREB_bp  4  /* Software Capture B Strobe bit position. */
#define TCD_DISEOC_bm  0x80  /* Disable at end of cycle bit mask. */
#define TCD_DISEOC_bp  7  /* Disable at end of cycle bit position. */

/* TCD.EVCTRLA  bit masks and bit positions */
#define TCD_TRIGEI_bm  0x01  /* Trigger event enable bit mask. */
#define TCD_TRIGEI_bp  0  /* Trigger event enable bit position. */
#define TCD_ACTION_bm  0x04  /* Event action bit mask. */
#define TCD_ACTION_bp  2  /* Event action bit position. */
#define TCD_EDGE_bm  0x10  /* Edge select bit mask. */
#define TCD_EDGE_bp  4  /* Edge select bit position. */
#define TCD_CFG_gm  0xC0  /* Event config group mask. */
#define TCD_CFG_gp  6  /* Event config group position. */
#define TCD_CFG_0_bm  (1<<6)  /* Event config bit 0 mask. */
#define TCD_CFG_0_bp  6  /* Event config bit 0 position. */
#define TCD_CFG_1_bm  (1<<7)  /* Event config bit 1 mask. */
#define TCD_CFG_1_bp  7  /* Event config bit 1 position. */

/* TCD.EVCTRLB  bit masks and bit positions */
/* TCD_TRIGEI  is already defined. */
/* TCD_ACTION  is already defined. */
/* TCD_EDGE  is already defined. */
/* TCD_CFG  is already defined. */

/* TCD.INTCTRL  bit masks and bit positions */
#define TCD_OVF_bm  0x01  /* Overflow interrupt enable bit mask. */
#define TCD_OVF_bp  0  /* Overflow interrupt enable bit position. */
#define TCD_TRIGA_bm  0x04  /* Trigger A interrupt enable bit mask. */
#define TCD_TRIGA_bp  2  /* Trigger A interrupt enable bit position. */
#define TCD_TRIGB_bm  0x08  /* Trigger B interrupt enable bit mask. */
#define TCD_TRIGB_bp  3  /* Trigger B interrupt enable bit position. */

/* TCD.INTFLAGS  bit masks and bit positions */
/* TCD_OVF  is already defined. */
/* TCD_TRIGA  is already defined. */
/* TCD_TRIGB  is already defined. */

/* TCD.STATUS  bit masks and bit positions */
#define TCD_ENRDY_bm  0x01  /* Enable ready bit mask. */
#define TCD_ENRDY_bp  0  /* Enable ready bit position. */
#define TCD_CMDRDY_bm  0x02  /* Command ready bit mask. */
#define TCD_CMDRDY_bp  1  /* Command ready bit position. */
#define TCD_PWMACTA_bm  0x40  /* PWM activity on A bit mask. */
#define TCD_PWMACTA_bp  6  /* PWM activity on A bit position. */
#define TCD_PWMACTB_bm  0x80  /* PWM activity on B bit mask. */
#define TCD_PWMACTB_bp  7  /* PWM activity on B bit position. */

/* TCD.INPUTCTRLA  bit masks and bit positions */
#define TCD_INPUTMODE_gm  0x0F  /* Input mode group mask. */
#define TCD_INPUTMODE_gp  0  /* Input mode group position. */
#define TCD_INPUTMODE_0_bm  (1<<0)  /* Input mode bit 0 mask. */
#define TCD_INPUTMODE_0_bp  0  /* Input mode bit 0 position. */
#define TCD_INPUTMODE_1_bm  (1<<1)  /* Input mode bit 1 mask. */
#define TCD_INPUTMODE_1_bp  1  /* Input mode bit 1 position. */
#define TCD_INPUTMODE_2_bm  (1<<2)  /* Input mode bit 2 mask. */
#define TCD_INPUTMODE_2_bp  2  /* Input mode bit 2 position. */
#define TCD_INPUTMODE_3_bm  (1<<3)  /* Input mode bit 3 mask. */
#define TCD_INPUTMODE_3_bp  3  /* Input mode bit 3 position. */

/* TCD.INPUTCTRLB  bit masks and bit positions */
/* TCD_INPUTMODE  is already defined. */

/* TCD.FAULTCTRL  bit masks and bit positions */
#define TCD_CMPA_bm  0x01  /* Compare A value bit mask. */
#define TCD_CMPA_bp  0  /* Compare A value bit position. */
#define TCD_CMPB_bm  0x02  /* Compare B value bit mask. */
#define TCD_CMPB_bp  1  /* Compare B value bit position. */
#define TCD_CMPC_bm  0x04  /* Compare C value bit mask. */
#define TCD_CMPC_bp  2  /* Compare C value bit position. */
#define TCD_CMPD_bm  0x08  /* Compare D vaule bit mask. */
#define TCD_CMPD_bp  3  /* Compare D vaule bit position. */
#define TCD_CMPAEN_bm  0x10  /* Compare A enable bit mask. */
#define TCD_CMPAEN_bp  4  /* Compare A enable bit position. */
#define TCD_CMPBEN_bm  0x20  /* Compare B enable bit mask. */
#define TCD_CMPBEN_bp  5  /* Compare B enable bit position. */
#define TCD_CMPCEN_bm  0x40  /* Compare C enable bit mask. */
#define TCD_CMPCEN_bp  6  /* Compare C enable bit position. */
#define TCD_CMPDEN_bm  0x80  /* Compare D enable bit mask. */
#define TCD_CMPDEN_bp  7  /* Compare D enable bit position. */

/* TCD.DLYCTRL  bit masks and bit positions */
#define TCD_DLYSEL_gm  0x03  /* Delay select group mask. */
#define TCD_DLYSEL_gp  0  /* Delay select group position. */
#define TCD_DLYSEL_0_bm  (1<<0)  /* Delay select bit 0 mask. */
#define TCD_DLYSEL_0_bp  0  /* Delay select bit 0 position. */
#define TCD_DLYSEL_1_bm  (1<<1)  /* Delay select bit 1 mask. */
#define TCD_DLYSEL_1_bp  1  /* Delay select bit 1 position. */
#define TCD_DLYTRIG_gm  0x0C  /* Delay trigger group mask. */
#define TCD_DLYTRIG_gp  2  /* Delay trigger group position. */
#define TCD_DLYTRIG_0_bm  (1<<2)  /* Delay trigger bit 0 mask. */
#define TCD_DLYTRIG_0_bp  2  /* Delay trigger bit 0 position. */
#define TCD_DLYTRIG_1_bm  (1<<3)  /* Delay trigger bit 1 mask. */
#define TCD_DLYTRIG_1_bp  3  /* Delay trigger bit 1 position. */
#define TCD_DLYPRESC_gm  0x30  /* Delay prescaler group mask. */
#define TCD_DLYPRESC_gp  4  /* Delay prescaler group position. */
#define TCD_DLYPRESC_0_bm  (1<<4)  /* Delay prescaler bit 0 mask. */
#define TCD_DLYPRESC_0_bp  4  /* Delay prescaler bit 0 position. */
#define TCD_DLYPRESC_1_bm  (1<<5)  /* Delay prescaler bit 1 mask. */
#define TCD_DLYPRESC_1_bp  5  /* Delay prescaler bit 1 position. */

/* TCD.DLYVAL  bit masks and bit positions */
#define TCD_DLYVAL_gm  0xFF  /* Delay value group mask. */
#define TCD_DLYVAL_gp  0  /* Delay value group position. */
#define TCD_DLYVAL_0_bm  (1<<0)  /* Delay value bit 0 mask. */
#define TCD_DLYVAL_0_bp  0  /* Delay value bit 0 position. */
#define TCD_DLYVAL_1_bm  (1<<1)  /* Delay value bit 1 mask. */
#define TCD_DLYVAL_1_bp  1  /* Delay value bit 1 position. */
#define TCD_DLYVAL_2_bm  (1<<2)  /* Delay value bit 2 mask. */
#define TCD_DLYVAL_2_bp  2  /* Delay value bit 2 position. */
#define TCD_DLYVAL_3_bm  (1<<3)  /* Delay value bit 3 mask. */
#define TCD_DLYVAL_3_bp  3  /* Delay value bit 3 position. */
#define TCD_DLYVAL_4_bm  (1<<4)  /* Delay value bit 4 mask. */
#define TCD_DLYVAL_4_bp  4  /* Delay value bit 4 position. */
#define TCD_DLYVAL_5_bm  (1<<5)  /* Delay value bit 5 mask. */
#define TCD_DLYVAL_5_bp  5  /* Delay value bit 5 position. */
#define TCD_DLYVAL_6_bm  (1<<6)  /* Delay value bit 6 mask. */
#define TCD_DLYVAL_6_bp  6  /* Delay value bit 6 position. */
#define TCD_DLYVAL_7_bm  (1<<7)  /* Delay value bit 7 mask. */
#define TCD_DLYVAL_7_bp  7  /* Delay value bit 7 position. */

/* TCD.DITCTRL  bit masks and bit positions */
#define TCD_DITHERSEL_gm  0x03  /* Dither select group mask. */
#define TCD_DITHERSEL_gp  0  /* Dither select group position. */
#define TCD_DITHERSEL_0_bm  (1<<0)  /* Dither select bit 0 mask. */
#define TCD_DITHERSEL_0_bp  0  /* Dither select bit 0 position. */
#define TCD_DITHERSEL_1_bm  (1<<1)  /* Dither select bit 1 mask. */
#define TCD_DITHERSEL_1_bp  1  /* Dither select bit 1 position. */

/* TCD.DITVAL  bit masks and bit positions */
#define TCD_DITHER_gm  0x0F  /* Dither value group mask. */
#define TCD_DITHER_gp  0  /* Dither value group position. */
#define TCD_DITHER_0_bm  (1<<0)  /* Dither value bit 0 mask. */
#define TCD_DITHER_0_bp  0  /* Dither value bit 0 position. */
#define TCD_DITHER_1_bm  (1<<1)  /* Dither value bit 1 mask. */
#define TCD_DITHER_1_bp  1  /* Dither value bit 1 position. */
#define TCD_DITHER_2_bm  (1<<2)  /* Dither value bit 2 mask. */
#define TCD_DITHER_2_bp  2  /* Dither value bit 2 position. */
#define TCD_DITHER_3_bm  (1<<3)  /* Dither value bit 3 mask. */
#define TCD_DITHER_3_bp  3  /* Dither value bit 3 position. */

/* TCD.DBGCTRL  bit masks and bit positions */
#define TCD_DBGRUN_bm  0x01  /* Debug run bit mask. */
#define TCD_DBGRUN_bp  0  /* Debug run bit position. */
#define TCD_FAULTDET_bm  0x04  /* Fault detection bit mask. */
#define TCD_FAULTDET_bp  2  /* Fault detection bit position. */

/* TCD.CAPTUREA  bit masks and bit positions */
#define TCD_CAPTUREA_gm  0xFFF  /* Capture A group mask. */
#define TCD_CAPTUREA_gp  0  /* Capture A group position. */
#define TCD_CAPTUREA_0_bm  (1<<0)  /* Capture A bit 0 mask. */
#define TCD_CAPTUREA_0_bp  0  /* Capture A bit 0 position. */
#define TCD_CAPTUREA_1_bm  (1<<1)  /* Capture A bit 1 mask. */
#define TCD_CAPTUREA_1_bp  1  /* Capture A bit 1 position. */
#define TCD_CAPTUREA_2_bm  (1<<2)  /* Capture A bit 2 mask. */
#define TCD_CAPTUREA_2_bp  2  /* Capture A bit 2 position. */
#define TCD_CAPTUREA_3_bm  (1<<3)  /* Capture A bit 3 mask. */
#define TCD_CAPTUREA_3_bp  3  /* Capture A bit 3 position. */
#define TCD_CAPTUREA_4_bm  (1<<4)  /* Capture A bit 4 mask. */
#define TCD_CAPTUREA_4_bp  4  /* Capture A bit 4 position. */
#define TCD_CAPTUREA_5_bm  (1<<5)  /* Capture A bit 5 mask. */
#define TCD_CAPTUREA_5_bp  5  /* Capture A bit 5 position. */
#define TCD_CAPTUREA_6_bm  (1<<6)  /* Capture A bit 6 mask. */
#define TCD_CAPTUREA_6_bp  6  /* Capture A bit 6 position. */
#define TCD_CAPTUREA_7_bm  (1<<7)  /* Capture A bit 7 mask. */
#define TCD_CAPTUREA_7_bp  7  /* Capture A bit 7 position. */
#define TCD_CAPTUREA_8_bm  (1<<8)  /* Capture A bit 8 mask. */
#define TCD_CAPTUREA_8_bp  8  /* Capture A bit 8 position. */
#define TCD_CAPTUREA_9_bm  (1<<9)  /* Capture A bit 9 mask. */
#define TCD_CAPTUREA_9_bp  9  /* Capture A bit 9 position. */
#define TCD_CAPTUREA_10_bm  (1<<10)  /* Capture A bit 10 mask. */
#define TCD_CAPTUREA_10_bp  10  /* Capture A bit 10 position. */
#define TCD_CAPTUREA_11_bm  (1<<11)  /* Capture A bit 11 mask. */
#define TCD_CAPTUREA_11_bp  11  /* Capture A bit 11 position. */

/* TCD.CAPTUREB  bit masks and bit positions */
#define TCD_CAPTUREB_gm  0xFFF  /* Capture B group mask. */
#define TCD_CAPTUREB_gp  0  /* Capture B group position. */
#define TCD_CAPTUREB_0_bm  (1<<0)  /* Capture B bit 0 mask. */
#define TCD_CAPTUREB_0_bp  0  /* Capture B bit 0 position. */
#define TCD_CAPTUREB_1_bm  (1<<1)  /* Capture B bit 1 mask. */
#define TCD_CAPTUREB_1_bp  1  /* Capture B bit 1 position. */
#define TCD_CAPTUREB_2_bm  (1<<2)  /* Capture B bit 2 mask. */
#define TCD_CAPTUREB_2_bp  2  /* Capture B bit 2 position. */
#define TCD_CAPTUREB_3_bm  (1<<3)  /* Capture B bit 3 mask. */
#define TCD_CAPTUREB_3_bp  3  /* Capture B bit 3 position. */
#define TCD_CAPTUREB_4_bm  (1<<4)  /* Capture B bit 4 mask. */
#define TCD_CAPTUREB_4_bp  4  /* Capture B bit 4 position. */
#define TCD_CAPTUREB_5_bm  (1<<5)  /* Capture B bit 5 mask. */
#define TCD_CAPTUREB_5_bp  5  /* Capture B bit 5 position. */
#define TCD_CAPTUREB_6_bm  (1<<6)  /* Capture B bit 6 mask. */
#define TCD_CAPTUREB_6_bp  6  /* Capture B bit 6 position. */
#define TCD_CAPTUREB_7_bm  (1<<7)  /* Capture B bit 7 mask. */
#define TCD_CAPTUREB_7_bp  7  /* Capture B bit 7 position. */
#define TCD_CAPTUREB_8_bm  (1<<8)  /* Capture B bit 8 mask. */
#define TCD_CAPTUREB_8_bp  8  /* Capture B bit 8 position. */
#define TCD_CAPTUREB_9_bm  (1<<9)  /* Capture B bit 9 mask. */
#define TCD_CAPTUREB_9_bp  9  /* Capture B bit 9 position. */
#define TCD_CAPTUREB_10_bm  (1<<10)  /* Capture B bit 10 mask. */
#define TCD_CAPTUREB_10_bp  10  /* Capture B bit 10 position. */
#define TCD_CAPTUREB_11_bm  (1<<11)  /* Capture B bit 11 mask. */
#define TCD_CAPTUREB_11_bp  11  /* Capture B bit 11 position. */

/* TCD.CMPASET  bit masks and bit positions */
#define TCD_CMPASET_gm  0xFFF  /* Compare A Set group mask. */
#define TCD_CMPASET_gp  0  /* Compare A Set group position. */
#define TCD_CMPASET_0_bm  (1<<0)  /* Compare A Set bit 0 mask. */
#define TCD_CMPASET_0_bp  0  /* Compare A Set bit 0 position. */
#define TCD_CMPASET_1_bm  (1<<1)  /* Compare A Set bit 1 mask. */
#define TCD_CMPASET_1_bp  1  /* Compare A Set bit 1 position. */
#define TCD_CMPASET_2_bm  (1<<2)  /* Compare A Set bit 2 mask. */
#define TCD_CMPASET_2_bp  2  /* Compare A Set bit 2 position. */
#define TCD_CMPASET_3_bm  (1<<3)  /* Compare A Set bit 3 mask. */
#define TCD_CMPASET_3_bp  3  /* Compare A Set bit 3 position. */
#define TCD_CMPASET_4_bm  (1<<4)  /* Compare A Set bit 4 mask. */
#define TCD_CMPASET_4_bp  4  /* Compare A Set bit 4 position. */
#define TCD_CMPASET_5_bm  (1<<5)  /* Compare A Set bit 5 mask. */
#define TCD_CMPASET_5_bp  5  /* Compare A Set bit 5 position. */
#define TCD_CMPASET_6_bm  (1<<6)  /* Compare A Set bit 6 mask. */
#define TCD_CMPASET_6_bp  6  /* Compare A Set bit 6 position. */
#define TCD_CMPASET_7_bm  (1<<7)  /* Compare A Set bit 7 mask. */
#define TCD_CMPASET_7_bp  7  /* Compare A Set bit 7 position. */
#define TCD_CMPASET_8_bm  (1<<8)  /* Compare A Set bit 8 mask. */
#define TCD_CMPASET_8_bp  8  /* Compare A Set bit 8 position. */
#define TCD_CMPASET_9_bm  (1<<9)  /* Compare A Set bit 9 mask. */
#define TCD_CMPASET_9_bp  9  /* Compare A Set bit 9 position. */
#define TCD_CMPASET_10_bm  (1<<10)  /* Compare A Set bit 10 mask. */
#define TCD_CMPASET_10_bp  10  /* Compare A Set bit 10 position. */
#define TCD_CMPASET_11_bm  (1<<11)  /* Compare A Set bit 11 mask. */
#define TCD_CMPASET_11_bp  11  /* Compare A Set bit 11 position. */

/* TCD.CMPACLR  bit masks and bit positions */
#define TCD_CMPACLR_gm  0xFFF  /* Compare A Clear group mask. */
#define TCD_CMPACLR_gp  0  /* Compare A Clear group position. */
#define TCD_CMPACLR_0_bm  (1<<0)  /* Compare A Clear bit 0 mask. */
#define TCD_CMPACLR_0_bp  0  /* Compare A Clear bit 0 position. */
#define TCD_CMPACLR_1_bm  (1<<1)  /* Compare A Clear bit 1 mask. */
#define TCD_CMPACLR_1_bp  1  /* Compare A Clear bit 1 position. */
#define TCD_CMPACLR_2_bm  (1<<2)  /* Compare A Clear bit 2 mask. */
#define TCD_CMPACLR_2_bp  2  /* Compare A Clear bit 2 position. */
#define TCD_CMPACLR_3_bm  (1<<3)  /* Compare A Clear bit 3 mask. */
#define TCD_CMPACLR_3_bp  3  /* Compare A Clear bit 3 position. */
#define TCD_CMPACLR_4_bm  (1<<4)  /* Compare A Clear bit 4 mask. */
#define TCD_CMPACLR_4_bp  4  /* Compare A Clear bit 4 position. */
#define TCD_CMPACLR_5_bm  (1<<5)  /* Compare A Clear bit 5 mask. */
#define TCD_CMPACLR_5_bp  5  /* Compare A Clear bit 5 position. */
#define TCD_CMPACLR_6_bm  (1<<6)  /* Compare A Clear bit 6 mask. */
#define TCD_CMPACLR_6_bp  6  /* Compare A Clear bit 6 position. */
#define TCD_CMPACLR_7_bm  (1<<7)  /* Compare A Clear bit 7 mask. */
#define TCD_CMPACLR_7_bp  7  /* Compare A Clear bit 7 position. */
#define TCD_CMPACLR_8_bm  (1<<8)  /* Compare A Clear bit 8 mask. */
#define TCD_CMPACLR_8_bp  8  /* Compare A Clear bit 8 position. */
#define TCD_CMPACLR_9_bm  (1<<9)  /* Compare A Clear bit 9 mask. */
#define TCD_CMPACLR_9_bp  9  /* Compare A Clear bit 9 position. */
#define TCD_CMPACLR_10_bm  (1<<10)  /* Compare A Clear bit 10 mask. */
#define TCD_CMPACLR_10_bp  10  /* Compare A Clear bit 10 position. */
#define TCD_CMPACLR_11_bm  (1<<11)  /* Compare A Clear bit 11 mask. */
#define TCD_CMPACLR_11_bp  11  /* Compare A Clear bit 11 position. */

/* TCD.CMPBSET  bit masks and bit positions */
#define TCD_CMPBSET_gm  0xFFF  /* Compare B Set group mask. */
#define TCD_CMPBSET_gp  0  /* Compare B Set group position. */
#define TCD_CMPBSET_0_bm  (1<<0)  /* Compare B Set bit 0 mask. */
#define TCD_CMPBSET_0_bp  0  /* Compare B Set bit 0 position. */
#define TCD_CMPBSET_1_bm  (1<<1)  /* Compare B Set bit 1 mask. */
#define TCD_CMPBSET_1_bp  1  /* Compare B Set bit 1 position. */
#define TCD_CMPBSET_2_bm  (1<<2)  /* Compare B Set bit 2 mask. */
#define TCD_CMPBSET_2_bp  2  /* Compare B Set bit 2 position. */
#define TCD_CMPBSET_3_bm  (1<<3)  /* Compare B Set bit 3 mask. */
#define TCD_CMPBSET_3_bp  3  /* Compare B Set bit 3 position. */
#define TCD_CMPBSET_4_bm  (1<<4)  /* Compare B Set bit 4 mask. */
#define TCD_CMPBSET_4_bp  4  /* Compare B Set bit 4 position. */
#define TCD_CMPBSET_5_bm  (1<<5)  /* Compare B Set bit 5 mask. */
#define TCD_CMPBSET_5_bp  5  /* Compare B Set bit 5 position. */
#define TCD_CMPBSET_6_bm  (1<<6)  /* Compare B Set bit 6 mask. */
#define TCD_CMPBSET_6_bp  6  /* Compare B Set bit 6 position. */
#define TCD_CMPBSET_7_bm  (1<<7)  /* Compare B Set bit 7 mask. */
#define TCD_CMPBSET_7_bp  7  /* Compare B Set bit 7 position. */
#define TCD_CMPBSET_8_bm  (1<<8)  /* Compare B Set bit 8 mask. */
#define TCD_CMPBSET_8_bp  8  /* Compare B Set bit 8 position. */
#define TCD_CMPBSET_9_bm  (1<<9)  /* Compare B Set bit 9 mask. */
#define TCD_CMPBSET_9_bp  9  /* Compare B Set bit 9 position. */
#define TCD_CMPBSET_10_bm  (1<<10)  /* Compare B Set bit 10 mask. */
#define TCD_CMPBSET_10_bp  10  /* Compare B Set bit 10 position. */
#define TCD_CMPBSET_11_bm  (1<<11)  /* Compare B Set bit 11 mask. */
#define TCD_CMPBSET_11_bp  11  /* Compare B Set bit 11 position. */

/* TCD.CMPBCLR  bit masks and bit positions */
#define TCD_COMPBCLR_gm  0xFFF  /* Compare B Clear group mask. */
#define TCD_COMPBCLR_gp  0  /* Compare B Clear group position. */
#define TCD_COMPBCLR_0_bm  (1<<0)  /* Compare B Clear bit 0 mask. */
#define TCD_COMPBCLR_0_bp  0  /* Compare B Clear bit 0 position. */
#define TCD_COMPBCLR_1_bm  (1<<1)  /* Compare B Clear bit 1 mask. */
#define TCD_COMPBCLR_1_bp  1  /* Compare B Clear bit 1 position. */
#define TCD_COMPBCLR_2_bm  (1<<2)  /* Compare B Clear bit 2 mask. */
#define TCD_COMPBCLR_2_bp  2  /* Compare B Clear bit 2 position. */
#define TCD_COMPBCLR_3_bm  (1<<3)  /* Compare B Clear bit 3 mask. */
#define TCD_COMPBCLR_3_bp  3  /* Compare B Clear bit 3 position. */
#define TCD_COMPBCLR_4_bm  (1<<4)  /* Compare B Clear bit 4 mask. */
#define TCD_COMPBCLR_4_bp  4  /* Compare B Clear bit 4 position. */
#define TCD_COMPBCLR_5_bm  (1<<5)  /* Compare B Clear bit 5 mask. */
#define TCD_COMPBCLR_5_bp  5  /* Compare B Clear bit 5 position. */
#define TCD_COMPBCLR_6_bm  (1<<6)  /* Compare B Clear bit 6 mask. */
#define TCD_COMPBCLR_6_bp  6  /* Compare B Clear bit 6 position. */
#define TCD_COMPBCLR_7_bm  (1<<7)  /* Compare B Clear bit 7 mask. */
#define TCD_COMPBCLR_7_bp  7  /* Compare B Clear bit 7 position. */
#define TCD_COMPBCLR_8_bm  (1<<8)  /* Compare B Clear bit 8 mask. */
#define TCD_COMPBCLR_8_bp  8  /* Compare B Clear bit 8 position. */
#define TCD_COMPBCLR_9_bm  (1<<9)  /* Compare B Clear bit 9 mask. */
#define TCD_COMPBCLR_9_bp  9  /* Compare B Clear bit 9 position. */
#define TCD_COMPBCLR_10_bm  (1<<10)  /* Compare B Clear bit 10 mask. */
#define TCD_COMPBCLR_10_bp  10  /* Compare B Clear bit 10 position. */
#define TCD_COMPBCLR_11_bm  (1<<11)  /* Compare B Clear bit 11 mask. */
#define TCD_COMPBCLR_11_bp  11  /* Compare B Clear bit 11 position. */


/* TWI - Two-Wire Interface */
/* TWI.CTRLA  bit masks and bit positions */
#define TWI_FMPEN_bm  0x02  /* Fast-mode Plus Enable bit mask. */
#define TWI_FMPEN_bp  1  /* Fast-mode Plus Enable bit position. */
#define TWI_SDAHOLD_gm  0x0C  /* SDA Hold Time group mask. */
#define TWI_SDAHOLD_gp  2  /* SDA Hold Time group position. */
#define TWI_SDAHOLD_0_bm  (1<<2)  /* SDA Hold Time bit 0 mask. */
#define TWI_SDAHOLD_0_bp  2  /* SDA Hold Time bit 0 position. */
#define TWI_SDAHOLD_1_bm  (1<<3)  /* SDA Hold Time bit 1 mask. */
#define TWI_SDAHOLD_1_bp  3  /* SDA Hold Time bit 1 position. */
#define TWI_SDASETUP_bm  0x10  /* SDA Setup Time bit mask. */
#define TWI_SDASETUP_bp  4  /* SDA Setup Time bit position. */
#define TWI_INPUTLVL_bm  0x40  /* Input voltage transition level bit mask. */
#define TWI_INPUTLVL_bp  6  /* Input voltage transition level bit position. */

/* TWI.DUALCTRL  bit masks and bit positions */
#define TWI_ENABLE_bm  0x01  /* Enable bit mask. */
#define TWI_ENABLE_bp  0  /* Enable bit position. */
/* TWI_FMPEN  is already defined. */
/* TWI_SDAHOLD  is already defined. */
/* TWI_INPUTLVL  is already defined. */

/* TWI.DBGCTRL  bit masks and bit positions */
#define TWI_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define TWI_DBGRUN_bp  0  /* Debug Run bit position. */

/* TWI.MCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
#define TWI_SMEN_bm  0x02  /* Smart Mode Enable bit mask. */
#define TWI_SMEN_bp  1  /* Smart Mode Enable bit position. */
#define TWI_TIMEOUT_gm  0x0C  /* Inactive Bus Time-Out group mask. */
#define TWI_TIMEOUT_gp  2  /* Inactive Bus Time-Out group position. */
#define TWI_TIMEOUT_0_bm  (1<<2)  /* Inactive Bus Time-Out bit 0 mask. */
#define TWI_TIMEOUT_0_bp  2  /* Inactive Bus Time-Out bit 0 position. */
#define TWI_TIMEOUT_1_bm  (1<<3)  /* Inactive Bus Time-Out bit 1 mask. */
#define TWI_TIMEOUT_1_bp  3  /* Inactive Bus Time-Out bit 1 position. */
#define TWI_QCEN_bm  0x10  /* Quick Command Enable bit mask. */
#define TWI_QCEN_bp  4  /* Quick Command Enable bit position. */
#define TWI_WIEN_bm  0x40  /* Write Interrupt Enable bit mask. */
#define TWI_WIEN_bp  6  /* Write Interrupt Enable bit position. */
#define TWI_RIEN_bm  0x80  /* Read Interrupt Enable bit mask. */
#define TWI_RIEN_bp  7  /* Read Interrupt Enable bit position. */

/* TWI.MCTRLB  bit masks and bit positions */
#define TWI_MCMD_gm  0x03  /* Command group mask. */
#define TWI_MCMD_gp  0  /* Command group position. */
#define TWI_MCMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_MCMD_0_bp  0  /* Command bit 0 position. */
#define TWI_MCMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_MCMD_1_bp  1  /* Command bit 1 position. */
#define TWI_ACKACT_bm  0x04  /* Acknowledge Action bit mask. */
#define TWI_ACKACT_bp  2  /* Acknowledge Action bit position. */
#define TWI_FLUSH_bm  0x08  /* Flush bit mask. */
#define TWI_FLUSH_bp  3  /* Flush bit position. */

/* TWI.MSTATUS  bit masks and bit positions */
#define TWI_BUSSTATE_gm  0x03  /* Bus State group mask. */
#define TWI_BUSSTATE_gp  0  /* Bus State group position. */
#define TWI_BUSSTATE_0_bm  (1<<0)  /* Bus State bit 0 mask. */
#define TWI_BUSSTATE_0_bp  0  /* Bus State bit 0 position. */
#define TWI_BUSSTATE_1_bm  (1<<1)  /* Bus State bit 1 mask. */
#define TWI_BUSSTATE_1_bp  1  /* Bus State bit 1 position. */
#define TWI_BUSERR_bm  0x04  /* Bus Error bit mask. */
#define TWI_BUSERR_bp  2  /* Bus Error bit position. */
#define TWI_ARBLOST_bm  0x08  /* Arbitration Lost bit mask. */
#define TWI_ARBLOST_bp  3  /* Arbitration Lost bit position. */
#define TWI_RXACK_bm  0x10  /* Received Acknowledge bit mask. */
#define TWI_RXACK_bp  4  /* Received Acknowledge bit position. */
#define TWI_CLKHOLD_bm  0x20  /* Clock Hold bit mask. */
#define TWI_CLKHOLD_bp  5  /* Clock Hold bit position. */
#define TWI_WIF_bm  0x40  /* Write Interrupt Flag bit mask. */
#define TWI_WIF_bp  6  /* Write Interrupt Flag bit position. */
#define TWI_RIF_bm  0x80  /* Read Interrupt Flag bit mask. */
#define TWI_RIF_bp  7  /* Read Interrupt Flag bit position. */

/* TWI.MBAUD  bit masks and bit positions */
#define TWI_BAUD_gm  0xFF  /* Baud Rate group mask. */
#define TWI_BAUD_gp  0  /* Baud Rate group position. */
#define TWI_BAUD_0_bm  (1<<0)  /* Baud Rate bit 0 mask. */
#define TWI_BAUD_0_bp  0  /* Baud Rate bit 0 position. */
#define TWI_BAUD_1_bm  (1<<1)  /* Baud Rate bit 1 mask. */
#define TWI_BAUD_1_bp  1  /* Baud Rate bit 1 position. */
#define TWI_BAUD_2_bm  (1<<2)  /* Baud Rate bit 2 mask. */
#define TWI_BAUD_2_bp  2  /* Baud Rate bit 2 position. */
#define TWI_BAUD_3_bm  (1<<3)  /* Baud Rate bit 3 mask. */
#define TWI_BAUD_3_bp  3  /* Baud Rate bit 3 position. */
#define TWI_BAUD_4_bm  (1<<4)  /* Baud Rate bit 4 mask. */
#define TWI_BAUD_4_bp  4  /* Baud Rate bit 4 position. */
#define TWI_BAUD_5_bm  (1<<5)  /* Baud Rate bit 5 mask. */
#define TWI_BAUD_5_bp  5  /* Baud Rate bit 5 position. */
#define TWI_BAUD_6_bm  (1<<6)  /* Baud Rate bit 6 mask. */
#define TWI_BAUD_6_bp  6  /* Baud Rate bit 6 position. */
#define TWI_BAUD_7_bm  (1<<7)  /* Baud Rate bit 7 mask. */
#define TWI_BAUD_7_bp  7  /* Baud Rate bit 7 position. */

/* TWI.MADDR  bit masks and bit positions */
#define TWI_ADDR_gm  0xFF  /* Address group mask. */
#define TWI_ADDR_gp  0  /* Address group position. */
#define TWI_ADDR_0_bm  (1<<0)  /* Address bit 0 mask. */
#define TWI_ADDR_0_bp  0  /* Address bit 0 position. */
#define TWI_ADDR_1_bm  (1<<1)  /* Address bit 1 mask. */
#define TWI_ADDR_1_bp  1  /* Address bit 1 position. */
#define TWI_ADDR_2_bm  (1<<2)  /* Address bit 2 mask. */
#define TWI_ADDR_2_bp  2  /* Address bit 2 position. */
#define TWI_ADDR_3_bm  (1<<3)  /* Address bit 3 mask. */
#define TWI_ADDR_3_bp  3  /* Address bit 3 position. */
#define TWI_ADDR_4_bm  (1<<4)  /* Address bit 4 mask. */
#define TWI_ADDR_4_bp  4  /* Address bit 4 position. */
#define TWI_ADDR_5_bm  (1<<5)  /* Address bit 5 mask. */
#define TWI_ADDR_5_bp  5  /* Address bit 5 position. */
#define TWI_ADDR_6_bm  (1<<6)  /* Address bit 6 mask. */
#define TWI_ADDR_6_bp  6  /* Address bit 6 position. */
#define TWI_ADDR_7_bm  (1<<7)  /* Address bit 7 mask. */
#define TWI_ADDR_7_bp  7  /* Address bit 7 position. */

/* TWI.MDATA  bit masks and bit positions */
#define TWI_DATA_gm  0xFF  /* Data group mask. */
#define TWI_DATA_gp  0  /* Data group position. */
#define TWI_DATA_0_bm  (1<<0)  /* Data bit 0 mask. */
#define TWI_DATA_0_bp  0  /* Data bit 0 position. */
#define TWI_DATA_1_bm  (1<<1)  /* Data bit 1 mask. */
#define TWI_DATA_1_bp  1  /* Data bit 1 position. */
#define TWI_DATA_2_bm  (1<<2)  /* Data bit 2 mask. */
#define TWI_DATA_2_bp  2  /* Data bit 2 position. */
#define TWI_DATA_3_bm  (1<<3)  /* Data bit 3 mask. */
#define TWI_DATA_3_bp  3  /* Data bit 3 position. */
#define TWI_DATA_4_bm  (1<<4)  /* Data bit 4 mask. */
#define TWI_DATA_4_bp  4  /* Data bit 4 position. */
#define TWI_DATA_5_bm  (1<<5)  /* Data bit 5 mask. */
#define TWI_DATA_5_bp  5  /* Data bit 5 position. */
#define TWI_DATA_6_bm  (1<<6)  /* Data bit 6 mask. */
#define TWI_DATA_6_bp  6  /* Data bit 6 position. */
#define TWI_DATA_7_bm  (1<<7)  /* Data bit 7 mask. */
#define TWI_DATA_7_bp  7  /* Data bit 7 position. */

/* TWI.SCTRLA  bit masks and bit positions */
/* TWI_ENABLE  is already defined. */
/* TWI_SMEN  is already defined. */
#define TWI_PMEN_bm  0x04  /* Address Recognition Mode bit mask. */
#define TWI_PMEN_bp  2  /* Address Recognition Mode bit position. */
#define TWI_PIEN_bm  0x20  /* Stop Interrupt Enable bit mask. */
#define TWI_PIEN_bp  5  /* Stop Interrupt Enable bit position. */
#define TWI_APIEN_bm  0x40  /* Address or Stop Interrupt Enable bit mask. */
#define TWI_APIEN_bp  6  /* Address or Stop Interrupt Enable bit position. */
#define TWI_DIEN_bm  0x80  /* Data Interrupt Enable bit mask. */
#define TWI_DIEN_bp  7  /* Data Interrupt Enable bit position. */

/* TWI.SCTRLB  bit masks and bit positions */
#define TWI_SCMD_gm  0x03  /* Command group mask. */
#define TWI_SCMD_gp  0  /* Command group position. */
#define TWI_SCMD_0_bm  (1<<0)  /* Command bit 0 mask. */
#define TWI_SCMD_0_bp  0  /* Command bit 0 position. */
#define TWI_SCMD_1_bm  (1<<1)  /* Command bit 1 mask. */
#define TWI_SCMD_1_bp  1  /* Command bit 1 position. */
/* TWI_ACKACT  is already defined. */

/* TWI.SSTATUS  bit masks and bit positions */
#define TWI_AP_bm  0x01  /* Address or Stop bit mask. */
#define TWI_AP_bp  0  /* Address or Stop bit position. */
#define TWI_DIR_bm  0x02  /* Read/Write Direction bit mask. */
#define TWI_DIR_bp  1  /* Read/Write Direction bit position. */
/* TWI_BUSERR  is already defined. */
#define TWI_COLL_bm  0x08  /* Collision bit mask. */
#define TWI_COLL_bp  3  /* Collision bit position. */
/* TWI_RXACK  is already defined. */
/* TWI_CLKHOLD  is already defined. */
#define TWI_APIF_bm  0x40  /* Address or Stop Interrupt Flag bit mask. */
#define TWI_APIF_bp  6  /* Address or Stop Interrupt Flag bit position. */
#define TWI_DIF_bm  0x80  /* Data Interrupt Flag bit mask. */
#define TWI_DIF_bp  7  /* Data Interrupt Flag bit position. */

/* TWI.SADDR  bit masks and bit positions */
/* TWI_ADDR  is already defined. */

/* TWI.SDATA  bit masks and bit positions */
/* TWI_DATA  is already defined. */

/* TWI.SADDRMASK  bit masks and bit positions */
#define TWI_ADDREN_bm  0x01  /* Address Mask Enable bit mask. */
#define TWI_ADDREN_bp  0  /* Address Mask Enable bit position. */
#define TWI_ADDRMASK_gm  0xFE  /* Address Mask group mask. */
#define TWI_ADDRMASK_gp  1  /* Address Mask group position. */
#define TWI_ADDRMASK_0_bm  (1<<1)  /* Address Mask bit 0 mask. */
#define TWI_ADDRMASK_0_bp  1  /* Address Mask bit 0 position. */
#define TWI_ADDRMASK_1_bm  (1<<2)  /* Address Mask bit 1 mask. */
#define TWI_ADDRMASK_1_bp  2  /* Address Mask bit 1 position. */
#define TWI_ADDRMASK_2_bm  (1<<3)  /* Address Mask bit 2 mask. */
#define TWI_ADDRMASK_2_bp  3  /* Address Mask bit 2 position. */
#define TWI_ADDRMASK_3_bm  (1<<4)  /* Address Mask bit 3 mask. */
#define TWI_ADDRMASK_3_bp  4  /* Address Mask bit 3 position. */
#define TWI_ADDRMASK_4_bm  (1<<5)  /* Address Mask bit 4 mask. */
#define TWI_ADDRMASK_4_bp  5  /* Address Mask bit 4 position. */
#define TWI_ADDRMASK_5_bm  (1<<6)  /* Address Mask bit 5 mask. */
#define TWI_ADDRMASK_5_bp  6  /* Address Mask bit 5 position. */
#define TWI_ADDRMASK_6_bm  (1<<7)  /* Address Mask bit 6 mask. */
#define TWI_ADDRMASK_6_bp  7  /* Address Mask bit 6 position. */


/* USART - Universal Synchronous and Asynchronous Receiver and Transmitter */
/* USART.RXDATAL  bit masks and bit positions */
#define USART_DATA_gm  0xFF  /* RX Data group mask. */
#define USART_DATA_gp  0  /* RX Data group position. */
#define USART_DATA_0_bm  (1<<0)  /* RX Data bit 0 mask. */
#define USART_DATA_0_bp  0  /* RX Data bit 0 position. */
#define USART_DATA_1_bm  (1<<1)  /* RX Data bit 1 mask. */
#define USART_DATA_1_bp  1  /* RX Data bit 1 position. */
#define USART_DATA_2_bm  (1<<2)  /* RX Data bit 2 mask. */
#define USART_DATA_2_bp  2  /* RX Data bit 2 position. */
#define USART_DATA_3_bm  (1<<3)  /* RX Data bit 3 mask. */
#define USART_DATA_3_bp  3  /* RX Data bit 3 position. */
#define USART_DATA_4_bm  (1<<4)  /* RX Data bit 4 mask. */
#define USART_DATA_4_bp  4  /* RX Data bit 4 position. */
#define USART_DATA_5_bm  (1<<5)  /* RX Data bit 5 mask. */
#define USART_DATA_5_bp  5  /* RX Data bit 5 position. */
#define USART_DATA_6_bm  (1<<6)  /* RX Data bit 6 mask. */
#define USART_DATA_6_bp  6  /* RX Data bit 6 position. */
#define USART_DATA_7_bm  (1<<7)  /* RX Data bit 7 mask. */
#define USART_DATA_7_bp  7  /* RX Data bit 7 position. */

/* USART.RXDATAH  bit masks and bit positions */
#define USART_DATA8_bm  0x01  /* Receiver Data Register bit mask. */
#define USART_DATA8_bp  0  /* Receiver Data Register bit position. */
#define USART_PERR_bm  0x02  /* Parity Error bit mask. */
#define USART_PERR_bp  1  /* Parity Error bit position. */
#define USART_FERR_bm  0x04  /* Frame Error bit mask. */
#define USART_FERR_bp  2  /* Frame Error bit position. */
#define USART_BUFOVF_bm  0x40  /* Buffer Overflow bit mask. */
#define USART_BUFOVF_bp  6  /* Buffer Overflow bit position. */
#define USART_RXCIF_bm  0x80  /* Receive Complete Interrupt Flag bit mask. */
#define USART_RXCIF_bp  7  /* Receive Complete Interrupt Flag bit position. */

/* USART.TXDATAL  bit masks and bit positions */
/* USART_DATA  is already defined. */

/* USART.TXDATAH  bit masks and bit positions */
/* USART_DATA8  is already defined. */

/* USART.STATUS  bit masks and bit positions */
#define USART_WFB_bm  0x01  /* Wait For Break bit mask. */
#define USART_WFB_bp  0  /* Wait For Break bit position. */
#define USART_BDF_bm  0x02  /* Break Detected Flag bit mask. */
#define USART_BDF_bp  1  /* Break Detected Flag bit position. */
#define USART_ISFIF_bm  0x08  /* Inconsistent Sync Field Interrupt Flag bit mask. */
#define USART_ISFIF_bp  3  /* Inconsistent Sync Field Interrupt Flag bit position. */
#define USART_RXSIF_bm  0x10  /* Receive Start Interrupt bit mask. */
#define USART_RXSIF_bp  4  /* Receive Start Interrupt bit position. */
#define USART_DREIF_bm  0x20  /* Data Register Empty Flag bit mask. */
#define USART_DREIF_bp  5  /* Data Register Empty Flag bit position. */
#define USART_TXCIF_bm  0x40  /* Transmit Interrupt Flag bit mask. */
#define USART_TXCIF_bp  6  /* Transmit Interrupt Flag bit position. */
/* USART_RXCIF  is already defined. */

/* USART.CTRLA  bit masks and bit positions */
#define USART_RS485_bm  0x01  /* RS485 Mode internal transmitter bit mask. */
#define USART_RS485_bp  0  /* RS485 Mode internal transmitter bit position. */
#define USART_ABEIE_bm  0x04  /* Auto-baud Error Interrupt Enable bit mask. */
#define USART_ABEIE_bp  2  /* Auto-baud Error Interrupt Enable bit position. */
#define USART_LBME_bm  0x08  /* Loop-back Mode Enable bit mask. */
#define USART_LBME_bp  3  /* Loop-back Mode Enable bit position. */
#define USART_RXSIE_bm  0x10  /* Receiver Start Frame Interrupt Enable bit mask. */
#define USART_RXSIE_bp  4  /* Receiver Start Frame Interrupt Enable bit position. */
#define USART_DREIE_bm  0x20  /* Data Register Empty Interrupt Enable bit mask. */
#define USART_DREIE_bp  5  /* Data Register Empty Interrupt Enable bit position. */
#define USART_TXCIE_bm  0x40  /* Transmit Complete Interrupt Enable bit mask. */
#define USART_TXCIE_bp  6  /* Transmit Complete Interrupt Enable bit position. */
#define USART_RXCIE_bm  0x80  /* Receive Complete Interrupt Enable bit mask. */
#define USART_RXCIE_bp  7  /* Receive Complete Interrupt Enable bit position. */

/* USART.CTRLB  bit masks and bit positions */
#define USART_MPCM_bm  0x01  /* Multi-processor Communication Mode bit mask. */
#define USART_MPCM_bp  0  /* Multi-processor Communication Mode bit position. */
#define USART_RXMODE_gm  0x06  /* Receiver Mode group mask. */
#define USART_RXMODE_gp  1  /* Receiver Mode group position. */
#define USART_RXMODE_0_bm  (1<<1)  /* Receiver Mode bit 0 mask. */
#define USART_RXMODE_0_bp  1  /* Receiver Mode bit 0 position. */
#define USART_RXMODE_1_bm  (1<<2)  /* Receiver Mode bit 1 mask. */
#define USART_RXMODE_1_bp  2  /* Receiver Mode bit 1 position. */
#define USART_ODME_bm  0x08  /* Open Drain Mode Enable bit mask. */
#define USART_ODME_bp  3  /* Open Drain Mode Enable bit position. */
#define USART_SFDEN_bm  0x10  /* Start Frame Detection Enable bit mask. */
#define USART_SFDEN_bp  4  /* Start Frame Detection Enable bit position. */
#define USART_TXEN_bm  0x40  /* Transmitter Enable bit mask. */
#define USART_TXEN_bp  6  /* Transmitter Enable bit position. */
#define USART_RXEN_bm  0x80  /* Reciever enable bit mask. */
#define USART_RXEN_bp  7  /* Reciever enable bit position. */

/* USART.CTRLC  bit masks and bit positions */
#define USART_UCPHA_bm  0x02  /* SPI Host Mode, Clock Phase bit mask. */
#define USART_UCPHA_bp  1  /* SPI Host Mode, Clock Phase bit position. */
#define USART_UDORD_bm  0x04  /* SPI Host Mode, Data Order bit mask. */
#define USART_UDORD_bp  2  /* SPI Host Mode, Data Order bit position. */
#define USART_CHSIZE_gm  0x07  /* Character Size group mask. */
#define USART_CHSIZE_gp  0  /* Character Size group position. */
#define USART_CHSIZE_0_bm  (1<<0)  /* Character Size bit 0 mask. */
#define USART_CHSIZE_0_bp  0  /* Character Size bit 0 position. */
#define USART_CHSIZE_1_bm  (1<<1)  /* Character Size bit 1 mask. */
#define USART_CHSIZE_1_bp  1  /* Character Size bit 1 position. */
#define USART_CHSIZE_2_bm  (1<<2)  /* Character Size bit 2 mask. */
#define USART_CHSIZE_2_bp  2  /* Character Size bit 2 position. */
#define USART_SBMODE_bm  0x08  /* Stop Bit Mode bit mask. */
#define USART_SBMODE_bp  3  /* Stop Bit Mode bit position. */
#define USART_PMODE_gm  0x30  /* Parity Mode group mask. */
#define USART_PMODE_gp  4  /* Parity Mode group position. */
#define USART_PMODE_0_bm  (1<<4)  /* Parity Mode bit 0 mask. */
#define USART_PMODE_0_bp  4  /* Parity Mode bit 0 position. */
#define USART_PMODE_1_bm  (1<<5)  /* Parity Mode bit 1 mask. */
#define USART_PMODE_1_bp  5  /* Parity Mode bit 1 position. */
#define USART_CMODE_gm  0xC0  /* Communication Mode group mask. */
#define USART_CMODE_gp  6  /* Communication Mode group position. */
#define USART_CMODE_0_bm  (1<<6)  /* Communication Mode bit 0 mask. */
#define USART_CMODE_0_bp  6  /* Communication Mode bit 0 position. */
#define USART_CMODE_1_bm  (1<<7)  /* Communication Mode bit 1 mask. */
#define USART_CMODE_1_bp  7  /* Communication Mode bit 1 position. */

/* USART.CTRLD  bit masks and bit positions */
#define USART_ABW_gm  0xC0  /* Auto Baud Window group mask. */
#define USART_ABW_gp  6  /* Auto Baud Window group position. */
#define USART_ABW_0_bm  (1<<6)  /* Auto Baud Window bit 0 mask. */
#define USART_ABW_0_bp  6  /* Auto Baud Window bit 0 position. */
#define USART_ABW_1_bm  (1<<7)  /* Auto Baud Window bit 1 mask. */
#define USART_ABW_1_bp  7  /* Auto Baud Window bit 1 position. */

/* USART.DBGCTRL  bit masks and bit positions */
#define USART_DBGRUN_bm  0x01  /* Debug Run bit mask. */
#define USART_DBGRUN_bp  0  /* Debug Run bit position. */

/* USART.EVCTRL  bit masks and bit positions */
#define USART_IREI_bm  0x01  /* IrDA Event Input Enable bit mask. */
#define USART_IREI_bp  0  /* IrDA Event Input Enable bit position. */

/* USART.TXPLCTRL  bit masks and bit positions */
#define USART_TXPL_gm  0xFF  /* Transmit pulse length group mask. */
#define USART_TXPL_gp  0  /* Transmit pulse length group position. */
#define USART_TXPL_0_bm  (1<<0)  /* Transmit pulse length bit 0 mask. */
#define USART_TXPL_0_bp  0  /* Transmit pulse length bit 0 position. */
#define USART_TXPL_1_bm  (1<<1)  /* Transmit pulse length bit 1 mask. */
#define USART_TXPL_1_bp  1  /* Transmit pulse length bit 1 position. */
#define USART_TXPL_2_bm  (1<<2)  /* Transmit pulse length bit 2 mask. */
#define USART_TXPL_2_bp  2  /* Transmit pulse length bit 2 position. */
#define USART_TXPL_3_bm  (1<<3)  /* Transmit pulse length bit 3 mask. */
#define USART_TXPL_3_bp  3  /* Transmit pulse length bit 3 position. */
#define USART_TXPL_4_bm  (1<<4)  /* Transmit pulse length bit 4 mask. */
#define USART_TXPL_4_bp  4  /* Transmit pulse length bit 4 position. */
#define USART_TXPL_5_bm  (1<<5)  /* Transmit pulse length bit 5 mask. */
#define USART_TXPL_5_bp  5  /* Transmit pulse length bit 5 position. */
#define USART_TXPL_6_bm  (1<<6)  /* Transmit pulse length bit 6 mask. */
#define USART_TXPL_6_bp  6  /* Transmit pulse length bit 6 position. */
#define USART_TXPL_7_bm  (1<<7)  /* Transmit pulse length bit 7 mask. */
#define USART_TXPL_7_bp  7  /* Transmit pulse length bit 7 position. */

/* USART.RXPLCTRL  bit masks and bit positions */
#define USART_RXPL_gm  0x7F  /* Receiver Pulse Lenght group mask. */
#define USART_RXPL_gp  0  /* Receiver Pulse Lenght group position. */
#define USART_RXPL_0_bm  (1<<0)  /* Receiver Pulse Lenght bit 0 mask. */
#define USART_RXPL_0_bp  0  /* Receiver Pulse Lenght bit 0 position. */
#define USART_RXPL_1_bm  (1<<1)  /* Receiver Pulse Lenght bit 1 mask. */
#define USART_RXPL_1_bp  1  /* Receiver Pulse Lenght bit 1 position. */
#define USART_RXPL_2_bm  (1<<2)  /* Receiver Pulse Lenght bit 2 mask. */
#define USART_RXPL_2_bp  2  /* Receiver Pulse Lenght bit 2 position. */
#define USART_RXPL_3_bm  (1<<3)  /* Receiver Pulse Lenght bit 3 mask. */
#define USART_RXPL_3_bp  3  /* Receiver Pulse Lenght bit 3 position. */
#define USART_RXPL_4_bm  (1<<4)  /* Receiver Pulse Lenght bit 4 mask. */
#define USART_RXPL_4_bp  4  /* Receiver Pulse Lenght bit 4 position. */
#define USART_RXPL_5_bm  (1<<5)  /* Receiver Pulse Lenght bit 5 mask. */
#define USART_RXPL_5_bp  5  /* Receiver Pulse Lenght bit 5 position. */
#define USART_RXPL_6_bm  (1<<6)  /* Receiver Pulse Lenght bit 6 mask. */
#define USART_RXPL_6_bp  6  /* Receiver Pulse Lenght bit 6 position. */



/* VPORT - Virtual Ports */
/* VPORT.INTFLAGS  bit masks and bit positions */
#define VPORT_INT_gm  0xFF  /* Pin Interrupt Flag group mask. */
#define VPORT_INT_gp  0  /* Pin Interrupt Flag group position. */
#define VPORT_INT_0_bm  (1<<0)  /* Pin Interrupt Flag bit 0 mask. */
#define VPORT_INT_0_bp  0  /* Pin Interrupt Flag bit 0 position. */
#define VPORT_INT_1_bm  (1<<1)  /* Pin Interrupt Flag bit 1 mask. */
#define VPORT_INT_1_bp  1  /* Pin Interrupt Flag bit 1 position. */
#define VPORT_INT_2_bm  (1<<2)  /* Pin Interrupt Flag bit 2 mask. */
#define VPORT_INT_2_bp  2  /* Pin Interrupt Flag bit 2 position. */
#define VPORT_INT_3_bm  (1<<3)  /* Pin Interrupt Flag bit 3 mask. */
#define VPORT_INT_3_bp  3  /* Pin Interrupt Flag bit 3 position. */
#define VPORT_INT_4_bm  (1<<4)  /* Pin Interrupt Flag bit 4 mask. */
#define VPORT_INT_4_bp  4  /* Pin Interrupt Flag bit 4 position. */
#define VPORT_INT_5_bm  (1<<5)  /* Pin Interrupt Flag bit 5 mask. */
#define VPORT_INT_5_bp  5  /* Pin Interrupt Flag bit 5 position. */
#define VPORT_INT_6_bm  (1<<6)  /* Pin Interrupt Flag bit 6 mask. */
#define VPORT_INT_6_bp  6  /* Pin Interrupt Flag bit 6 position. */
#define VPORT_INT_7_bm  (1<<7)  /* Pin Interrupt Flag bit 7 mask. */
#define VPORT_INT_7_bp  7  /* Pin Interrupt Flag bit 7 position. */


/* VREF - Voltage Reference */
/* VREF.DAC0REF  bit masks and bit positions */
#define VREF_REFSEL_gm  0x07  /* Reference select group mask. */
#define VREF_REFSEL_gp  0  /* Reference select group position. */
#define VREF_REFSEL_0_bm  (1<<0)  /* Reference select bit 0 mask. */
#define VREF_REFSEL_0_bp  0  /* Reference select bit 0 position. */
#define VREF_REFSEL_1_bm  (1<<1)  /* Reference select bit 1 mask. */
#define VREF_REFSEL_1_bp  1  /* Reference select bit 1 position. */
#define VREF_REFSEL_2_bm  (1<<2)  /* Reference select bit 2 mask. */
#define VREF_REFSEL_2_bp  2  /* Reference select bit 2 position. */
#define VREF_ALWAYSON_bm  0x80  /* Always on bit mask. */
#define VREF_ALWAYSON_bp  7  /* Always on bit position. */

/* VREF.ACREF  bit masks and bit positions */
/* VREF_REFSEL  is already defined. */
/* VREF_ALWAYSON  is already defined. */


/* WDT - Watchdog Timer */
/* WDT.CTRLA  bit masks and bit positions */
#define WDT_PERIOD_gm  0x0F  /* Period group mask. */
#define WDT_PERIOD_gp  0  /* Period group position. */
#define WDT_PERIOD_0_bm  (1<<0)  /* Period bit 0 mask. */
#define WDT_PERIOD_0_bp  0  /* Period bit 0 position. */
#define WDT_PERIOD_1_bm  (1<<1)  /* Period bit 1 mask. */
#define WDT_PERIOD_1_bp  1  /* Period bit 1 position. */
#define WDT_PERIOD_2_bm  (1<<2)  /* Period bit 2 mask. */
#define WDT_PERIOD_2_bp  2  /* Period bit 2 position. */
#define WDT_PERIOD_3_bm  (1<<3)  /* Period bit 3 mask. */
#define WDT_PERIOD_3_bp  3  /* Period bit 3 position. */
#define WDT_WINDOW_gm  0xF0  /* Window group mask. */
#define WDT_WINDOW_gp  4  /* Window group position. */
#define WDT_WINDOW_0_bm  (1<<4)  /* Window bit 0 mask. */
#define WDT_WINDOW_0_bp  4  /* Window bit 0 position. */
#define WDT_WINDOW_1_bm  (1<<5)  /* Window bit 1 mask. */
#define WDT_WINDOW_1_bp  5  /* Window bit 1 position. */
#define WDT_WINDOW_2_bm  (1<<6)  /* Window bit 2 mask. */
#define WDT_WINDOW_2_bp  6  /* Window bit 2 position. */
#define WDT_WINDOW_3_bm  (1<<7)  /* Window bit 3 mask. */
#define WDT_WINDOW_3_bp  7  /* Window bit 3 position. */

/* WDT.CTRLB  bit masks and bit positions */
#define WDT_WDTMON_gm  0xC0  /* WDT Clock Monitor group mask. */
#define WDT_WDTMON_gp  6  /* WDT Clock Monitor group position. */
#define WDT_WDTMON_0_bm  (1<<6)  /* WDT Clock Monitor bit 0 mask. */
#define WDT_WDTMON_0_bp  6  /* WDT Clock Monitor bit 0 position. */
#define WDT_WDTMON_1_bm  (1<<7)  /* WDT Clock Monitor bit 1 mask. */
#define WDT_WDTMON_1_bp  7  /* WDT Clock Monitor bit 1 position. */

/* WDT.STATUS  bit masks and bit positions */
#define WDT_SYNCBUSY_bm  0x01  /* Syncronization busy bit mask. */
#define WDT_SYNCBUSY_bp  0  /* Syncronization busy bit position. */
#define WDT_CNTBUSY_bm  0x02  /* CNT Synchronization Busy bit mask. */
#define WDT_CNTBUSY_bp  1  /* CNT Synchronization Busy bit position. */
#define WDT_CAUSE_bm  0x04  /* Reset Cause bit mask. */
#define WDT_CAUSE_bp  2  /* Reset Cause bit position. */
#define WDT_LOCK_bm  0x80  /* Lock enable bit mask. */
#define WDT_LOCK_bp  7  /* Lock enable bit position. */

/* WDT.CNT  bit masks and bit positions */
#define WDT_CNT_gm  0x3FFF  /* Counter group mask. */
#define WDT_CNT_gp  0  /* Counter group position. */
#define WDT_CNT_0_bm  (1<<0)  /* Counter bit 0 mask. */
#define WDT_CNT_0_bp  0  /* Counter bit 0 position. */
#define WDT_CNT_1_bm  (1<<1)  /* Counter bit 1 mask. */
#define WDT_CNT_1_bp  1  /* Counter bit 1 position. */
#define WDT_CNT_2_bm  (1<<2)  /* Counter bit 2 mask. */
#define WDT_CNT_2_bp  2  /* Counter bit 2 position. */
#define WDT_CNT_3_bm  (1<<3)  /* Counter bit 3 mask. */
#define WDT_CNT_3_bp  3  /* Counter bit 3 position. */
#define WDT_CNT_4_bm  (1<<4)  /* Counter bit 4 mask. */
#define WDT_CNT_4_bp  4  /* Counter bit 4 position. */
#define WDT_CNT_5_bm  (1<<5)  /* Counter bit 5 mask. */
#define WDT_CNT_5_bp  5  /* Counter bit 5 position. */
#define WDT_CNT_6_bm  (1<<6)  /* Counter bit 6 mask. */
#define WDT_CNT_6_bp  6  /* Counter bit 6 position. */
#define WDT_CNT_7_bm  (1<<7)  /* Counter bit 7 mask. */
#define WDT_CNT_7_bp  7  /* Counter bit 7 position. */
#define WDT_CNT_8_bm  (1<<8)  /* Counter bit 8 mask. */
#define WDT_CNT_8_bp  8  /* Counter bit 8 position. */
#define WDT_CNT_9_bm  (1<<9)  /* Counter bit 9 mask. */
#define WDT_CNT_9_bp  9  /* Counter bit 9 position. */
#define WDT_CNT_10_bm  (1<<10)  /* Counter bit 10 mask. */
#define WDT_CNT_10_bp  10  /* Counter bit 10 position. */
#define WDT_CNT_11_bm  (1<<11)  /* Counter bit 11 mask. */
#define WDT_CNT_11_bp  11  /* Counter bit 11 position. */
#define WDT_CNT_12_bm  (1<<12)  /* Counter bit 12 mask. */
#define WDT_CNT_12_bp  12  /* Counter bit 12 position. */
#define WDT_CNT_13_bm  (1<<13)  /* Counter bit 13 mask. */
#define WDT_CNT_13_bp  13  /* Counter bit 13 position. */


/* ZCD - Zero Cross Detect */
/* ZCD.CTRLA  bit masks and bit positions */
#define ZCD_ENABLE_bm  0x01  /* Enable bit mask. */
#define ZCD_ENABLE_bp  0  /* Enable bit position. */
#define ZCD_INVERT_bm  0x08  /* Invert signal from pin bit mask. */
#define ZCD_INVERT_bp  3  /* Invert signal from pin bit position. */
#define ZCD_OUTEN_bm  0x40  /* Output Pad Enable bit mask. */
#define ZCD_OUTEN_bp  6  /* Output Pad Enable bit position. */
#define ZCD_RUNSTDBY_bm  0x80  /* Run in Standby Mode bit mask. */
#define ZCD_RUNSTDBY_bp  7  /* Run in Standby Mode bit position. */

/* ZCD.INTCTRL  bit masks and bit positions */
#define ZCD_INTMODE_gm  0x03  /* Interrupt Mode group mask. */
#define ZCD_INTMODE_gp  0  /* Interrupt Mode group position. */
#define ZCD_INTMODE_0_bm  (1<<0)  /* Interrupt Mode bit 0 mask. */
#define ZCD_INTMODE_0_bp  0  /* Interrupt Mode bit 0 position. */
#define ZCD_INTMODE_1_bm  (1<<1)  /* Interrupt Mode bit 1 mask. */
#define ZCD_INTMODE_1_bp  1  /* Interrupt Mode bit 1 position. */

/* ZCD.STATUS  bit masks and bit positions */
#define ZCD_CROSSIF_bm  0x01  /* ZCD Interrupt Flag bit mask. */
#define ZCD_CROSSIF_bp  0  /* ZCD Interrupt Flag bit position. */
#define ZCD_STATE_bm  0x10  /* ZCD State bit mask. */
#define ZCD_STATE_bp  4  /* ZCD State bit position. */

/* C Language Only */
#if !defined (__ASSEMBLER__)
/*
==========================================================================
IO Module Structures
==========================================================================
*/


/*
--------------------------------------------------------------------------
AC - Analog Comparator
--------------------------------------------------------------------------
*/

/* Analog Comparator */
typedef struct AC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t MUXCTRL;  /* Mux Control A */
    register8_t reserved_1[2];
    register8_t DACREF;  /* DAC Voltage Reference */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t STATUS;  /* Status */
} AC_t;

/* Hysteresis Mode select bit group values */
typedef enum AC_HYSMODE_VALUES_enum
{
    AC_HYSMODE_NONE_gv             = 0x00,  /* No hysteresis */
    AC_HYSMODE_SMALL_gv            = 0x01,  /* Small hysteresis */
    AC_HYSMODE_MEDIUM_gv           = 0x02,  /* Medium hysteresis */
    AC_HYSMODE_LARGE_gv            = 0x03   /* Large hysteresis */
} AC_HYSMODE_values_t;

/* Hysteresis Mode select bit group configurations*/
typedef enum AC_HYSMODE_enum
{
    AC_HYSMODE_NONE_gc             = (AC_HYSMODE_NONE_gv << AC_HYSMODE_gp),  /* No hysteresis */
    AC_HYSMODE_SMALL_gc            = (AC_HYSMODE_SMALL_gv << AC_HYSMODE_gp),  /* Small hysteresis */
    AC_HYSMODE_MEDIUM_gc           = (AC_HYSMODE_MEDIUM_gv << AC_HYSMODE_gp),  /* Medium hysteresis */
    AC_HYSMODE_LARGE_gc            = (AC_HYSMODE_LARGE_gv << AC_HYSMODE_gp)   /* Large hysteresis */
} AC_HYSMODE_t;

/* AC Output Initial Value select bit group values */
typedef enum AC_INITVAL_VALUES_enum
{
    AC_INITVAL_LOW_gv              = 0x00,  /* Output initialized to 0 */
    AC_INITVAL_HIGH_gv             = 0x01   /* Output initialized to 1 */
} AC_INITVAL_values_t;

/* AC Output Initial Value select bit group configurations*/
typedef enum AC_INITVAL_enum
{
    AC_INITVAL_LOW_gc              = (AC_INITVAL_LOW_gv << AC_INITVAL_bp),  /* Output initialized to 0 */
    AC_INITVAL_HIGH_gc             = (AC_INITVAL_HIGH_gv << AC_INITVAL_bp)   /* Output initialized to 1 */
} AC_INITVAL_t;

/* Interrupt Mode select bit group values */
typedef enum AC_INTMODE_NORMAL_VALUES_enum
{
    AC_INTMODE_NORMAL_BOTHEDGE_gv  = 0x00,  /* Positive and negative inputs crosses */
    AC_INTMODE_NORMAL_NEGEDGE_gv   = 0x02,  /* Positive input goes below negative input */
    AC_INTMODE_NORMAL_POSEDGE_gv   = 0x03   /* Positive input goes above negative input */
} AC_INTMODE_NORMAL_values_t;

/* Interrupt Mode select bit group configurations*/
typedef enum AC_INTMODE_NORMAL_enum
{
    AC_INTMODE_NORMAL_BOTHEDGE_gc  = (AC_INTMODE_NORMAL_BOTHEDGE_gv << AC_INTMODE_NORMAL_gp),  /* Positive and negative inputs crosses */
    AC_INTMODE_NORMAL_NEGEDGE_gc   = (AC_INTMODE_NORMAL_NEGEDGE_gv << AC_INTMODE_NORMAL_gp),  /* Positive input goes below negative input */
    AC_INTMODE_NORMAL_POSEDGE_gc   = (AC_INTMODE_NORMAL_POSEDGE_gv << AC_INTMODE_NORMAL_gp)   /* Positive input goes above negative input */
} AC_INTMODE_NORMAL_t;

/* Interrupt Mode select bit group values */
typedef enum AC_INTMODE_WINDOW_VALUES_enum
{
    AC_INTMODE_WINDOW_ABOVE_gv     = 0x00,  /* Window interrupt when input above both references */
    AC_INTMODE_WINDOW_INSIDE_gv    = 0x01,  /* Window interrupt when input betweeen references */
    AC_INTMODE_WINDOW_BELOW_gv     = 0x02,  /* Window interrupt when input below both references */
    AC_INTMODE_WINDOW_OUTSIDE_gv   = 0x03   /* Window interrupt when input outside reference */
} AC_INTMODE_WINDOW_values_t;

/* Interrupt Mode select bit group configurations*/
typedef enum AC_INTMODE_WINDOW_enum
{
    AC_INTMODE_WINDOW_ABOVE_gc     = (AC_INTMODE_WINDOW_ABOVE_gv << AC_INTMODE_WINDOW_gp),  /* Window interrupt when input above both references */
    AC_INTMODE_WINDOW_INSIDE_gc    = (AC_INTMODE_WINDOW_INSIDE_gv << AC_INTMODE_WINDOW_gp),  /* Window interrupt when input betweeen references */
    AC_INTMODE_WINDOW_BELOW_gc     = (AC_INTMODE_WINDOW_BELOW_gv << AC_INTMODE_WINDOW_gp),  /* Window interrupt when input below both references */
    AC_INTMODE_WINDOW_OUTSIDE_gc   = (AC_INTMODE_WINDOW_OUTSIDE_gv << AC_INTMODE_WINDOW_gp)   /* Window interrupt when input outside reference */
} AC_INTMODE_WINDOW_t;

/* Negative Input MUX Selection bit group values */
typedef enum AC_MUXNEG_VALUES_enum
{
    AC_MUXNEG_AINN0_gv             = 0x00,  /* Negative Pin 0 */
    AC_MUXNEG_AINN2_gv             = 0x02,  /* Negative Pin 2 */
    AC_MUXNEG_AINN3_gv             = 0x03,  /* Negative Pin 3 */
    AC_MUXNEG_DACREF_gv            = 0x04   /* DAC Reference */
} AC_MUXNEG_values_t;

/* Negative Input MUX Selection bit group configurations*/
typedef enum AC_MUXNEG_enum
{
    AC_MUXNEG_AINN0_gc             = (AC_MUXNEG_AINN0_gv << AC_MUXNEG_gp),  /* Negative Pin 0 */
    AC_MUXNEG_AINN2_gc             = (AC_MUXNEG_AINN2_gv << AC_MUXNEG_gp),  /* Negative Pin 2 */
    AC_MUXNEG_AINN3_gc             = (AC_MUXNEG_AINN3_gv << AC_MUXNEG_gp),  /* Negative Pin 3 */
    AC_MUXNEG_DACREF_gc            = (AC_MUXNEG_DACREF_gv << AC_MUXNEG_gp)   /* DAC Reference */
} AC_MUXNEG_t;

/* Positive Input MUX Selection bit group values */
typedef enum AC_MUXPOS_VALUES_enum
{
    AC_MUXPOS_AINP0_gv             = 0x00,  /* Positive Pin 0 */
    AC_MUXPOS_AINP1_gv             = 0x01,  /* Positive Pin 1 */
    AC_MUXPOS_AINP2_gv             = 0x02,  /* Positive Pin 2 */
    AC_MUXPOS_AINP3_gv             = 0x03,  /* Positive Pin 3 */
    AC_MUXPOS_AINP4_gv             = 0x04   /* Positive Pin 4 */
} AC_MUXPOS_values_t;

/* Positive Input MUX Selection bit group configurations*/
typedef enum AC_MUXPOS_enum
{
    AC_MUXPOS_AINP0_gc             = (AC_MUXPOS_AINP0_gv << AC_MUXPOS_gp),  /* Positive Pin 0 */
    AC_MUXPOS_AINP1_gc             = (AC_MUXPOS_AINP1_gv << AC_MUXPOS_gp),  /* Positive Pin 1 */
    AC_MUXPOS_AINP2_gc             = (AC_MUXPOS_AINP2_gv << AC_MUXPOS_gp),  /* Positive Pin 2 */
    AC_MUXPOS_AINP3_gc             = (AC_MUXPOS_AINP3_gv << AC_MUXPOS_gp),  /* Positive Pin 3 */
    AC_MUXPOS_AINP4_gc             = (AC_MUXPOS_AINP4_gv << AC_MUXPOS_gp)   /* Positive Pin 4 */
} AC_MUXPOS_t;

/* Power profile select bit group values */
typedef enum AC_POWER_VALUES_enum
{
    AC_POWER_PROFILE0_gv           = 0x00,  /* Power profile 0, Shortest response time, highest consumption */
    AC_POWER_PROFILE1_gv           = 0x01,  /* Power profile 1 */
    AC_POWER_PROFILE2_gv           = 0x02   /* Power profile 2 */
} AC_POWER_values_t;

/* Power profile select bit group configurations*/
typedef enum AC_POWER_enum
{
    AC_POWER_PROFILE0_gc           = (AC_POWER_PROFILE0_gv << AC_POWER_gp),  /* Power profile 0, Shortest response time, highest consumption */
    AC_POWER_PROFILE1_gc           = (AC_POWER_PROFILE1_gv << AC_POWER_gp),  /* Power profile 1 */
    AC_POWER_PROFILE2_gc           = (AC_POWER_PROFILE2_gv << AC_POWER_gp)   /* Power profile 2 */
} AC_POWER_t;

/* Window selection mode bit group values */
typedef enum AC_WINSEL_VALUES_enum
{
    AC_WINSEL_DISABLED_gv          = 0x00,  /* Window function disabled */
    AC_WINSEL_UPSEL1_gv            = 0x01,  /* Select ACn+1 as upper limit in window compare */
    AC_WINSEL_UPSEL2_gv            = 0x02   /* Select ACn+2 as upper limit in window compare */
} AC_WINSEL_values_t;

/* Window selection mode bit group configurations*/
typedef enum AC_WINSEL_enum
{
    AC_WINSEL_DISABLED_gc          = (AC_WINSEL_DISABLED_gv << AC_WINSEL_gp),  /* Window function disabled */
    AC_WINSEL_UPSEL1_gc            = (AC_WINSEL_UPSEL1_gv << AC_WINSEL_gp),  /* Select ACn+1 as upper limit in window compare */
    AC_WINSEL_UPSEL2_gc            = (AC_WINSEL_UPSEL2_gv << AC_WINSEL_gp)   /* Select ACn+2 as upper limit in window compare */
} AC_WINSEL_t;

/* Analog Comparator Window State select bit group values */
typedef enum AC_WINSTATE_VALUES_enum
{
    AC_WINSTATE_ABOVE_gv           = 0x00,  /* Above window */
    AC_WINSTATE_INSIDE_gv          = 0x01,  /* Inside window */
    AC_WINSTATE_BELOW_gv           = 0x02   /* Below window */
} AC_WINSTATE_values_t;

/* Analog Comparator Window State select bit group configurations*/
typedef enum AC_WINSTATE_enum
{
    AC_WINSTATE_ABOVE_gc           = (AC_WINSTATE_ABOVE_gv << AC_WINSTATE_gp),  /* Above window */
    AC_WINSTATE_INSIDE_gc          = (AC_WINSTATE_INSIDE_gv << AC_WINSTATE_gp),  /* Inside window */
    AC_WINSTATE_BELOW_gc           = (AC_WINSTATE_BELOW_gv << AC_WINSTATE_gp)   /* Below window */
} AC_WINSTATE_t;

/*
--------------------------------------------------------------------------
ADC - Analog to Digital Converter
--------------------------------------------------------------------------
*/

/* Analog to Digital Converter */
typedef struct ADC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control C */
    register8_t CTRLC;  /* Control B */
    register8_t CTRLD;  /* Control E */
    register8_t CTRLE;  /* Control F */
    register8_t CTRLF;  /* Control D */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t COMMAND;  /* Command */
    register8_t MUXPOS;  /* Positive mux input */
    _WORDREGISTER(RESULT);  /* ADC Accumulator Result */
    _WORDREGISTER(SAMPLE);  /* ADC Sample */
    _WORDREGISTER(WINLT);  /* Window comparator low threshold */
    _WORDREGISTER(WINHT);  /* Window comparator high threshold */
    register8_t TEMP;  /* Temporary Data */
    register8_t reserved_1[43];
} ADC_t;

/* Mode select bit group values */
typedef enum ADC_MODE_VALUES_enum
{
    ADC_MODE_SINGLE_8BIT_gv        = 0x00,  /* Single 8-bit conv */
    ADC_MODE_SINGLE_10BIT_gv       = 0x01,  /* Single 10-bit conv */
    ADC_MODE_SERIES_gv             = 0x02,  /* Series of 10-bit conv */
    ADC_MODE_BURST_gv              = 0x03,  /* Burst of 10-bit conv */
    ADC_MODE_ACCTEST_gv            = 0x07   /* Acc test mode for FuSa */
} ADC_MODE_values_t;

/* Mode select bit group configurations*/
typedef enum ADC_MODE_enum
{
    ADC_MODE_SINGLE_8BIT_gc        = (ADC_MODE_SINGLE_8BIT_gv << ADC_MODE_gp),  /* Single 8-bit conv */
    ADC_MODE_SINGLE_10BIT_gc       = (ADC_MODE_SINGLE_10BIT_gv << ADC_MODE_gp),  /* Single 10-bit conv */
    ADC_MODE_SERIES_gc             = (ADC_MODE_SERIES_gv << ADC_MODE_gp),  /* Series of 10-bit conv */
    ADC_MODE_BURST_gc              = (ADC_MODE_BURST_gv << ADC_MODE_gp),  /* Burst of 10-bit conv */
    ADC_MODE_ACCTEST_gc            = (ADC_MODE_ACCTEST_gv << ADC_MODE_gp)   /* Acc test mode for FuSa */
} ADC_MODE_t;

/* Analog Channel Selection Bits bit group values */
typedef enum ADC_MUXPOS_VALUES_enum
{
    ADC_MUXPOS_AIN0_gv             = 0x00,  /* ADC input pin 0 */
    ADC_MUXPOS_AIN1_gv             = 0x01,  /* ADC input pin 1 */
    ADC_MUXPOS_AIN2_gv             = 0x02,  /* ADC input pin 2 */
    ADC_MUXPOS_AIN3_gv             = 0x03,  /* ADC input pin 3 */
    ADC_MUXPOS_AIN4_gv             = 0x04,  /* ADC input pin 4 */
    ADC_MUXPOS_AIN5_gv             = 0x05,  /* ADC input pin 5 */
    ADC_MUXPOS_AIN6_gv             = 0x06,  /* ADC input pin 6 */
    ADC_MUXPOS_AIN7_gv             = 0x07,  /* ADC input pin 7 */
    ADC_MUXPOS_AIN8_gv             = 0x08,  /* ADC input pin 8 */
    ADC_MUXPOS_AIN9_gv             = 0x09,  /* ADC input pin 9 */
    ADC_MUXPOS_AIN10_gv            = 0x0A,  /* ADC input pin 10 */
    ADC_MUXPOS_AIN11_gv            = 0x0B,  /* ADC input pin 11 */
    ADC_MUXPOS_AIN16_gv            = 0x10,  /* ADC input pin 16 */
    ADC_MUXPOS_AIN17_gv            = 0x11,  /* ADC input pin 17 */
    ADC_MUXPOS_AIN18_gv            = 0x12,  /* ADC input pin 18 */
    ADC_MUXPOS_AIN19_gv            = 0x13,  /* ADC input pin 19 */
    ADC_MUXPOS_AIN20_gv            = 0x14,  /* ADC input pin 20 */
    ADC_MUXPOS_AIN21_gv            = 0x15,  /* ADC input pin 21 */
    ADC_MUXPOS_AIN22_gv            = 0x16,  /* ADC input pin 22 */
    ADC_MUXPOS_AIN23_gv            = 0x17,  /* ADC input pin 23 */
    ADC_MUXPOS_AIN24_gv            = 0x18,  /* ADC input pin 24 */
    ADC_MUXPOS_AIN25_gv            = 0x19,  /* ADC input pin 25 */
    ADC_MUXPOS_AIN26_gv            = 0x1A,  /* ADC input pin 26 */
    ADC_MUXPOS_AIN27_gv            = 0x1B,  /* ADC input pin 27 */
    ADC_MUXPOS_AIN28_gv            = 0x1C,  /* ADC input pin 28 */
    ADC_MUXPOS_AIN29_gv            = 0x1D,  /* ADC input pin 29 */
    ADC_MUXPOS_AIN30_gv            = 0x1E,  /* ADC input pin 30 */
    ADC_MUXPOS_AIN31_gv            = 0x1F,  /* ADC input pin 31 */
    ADC_MUXPOS_GND_gv              = 0x40,  /* Ground */
    ADC_MUXPOS_VDDCOREDIV4_gv      = 0x41,  /* VDDCORE/4 */
    ADC_MUXPOS_TEMPSENSE_gv        = 0x42,  /* Temperature sensor */
    ADC_MUXPOS_VDDDIV10_gv         = 0x44,  /* VDD/10 */
    ADC_MUXPOS_VDDIO2DIV10_gv      = 0x45,  /* VDDIO2/10 */
    ADC_MUXPOS_DAC0_gv             = 0x48,  /* DAC0 */
    ADC_MUXPOS_DACREF0_gv          = 0x49,  /* DACREF0 */
    ADC_MUXPOS_DACREF1_gv          = 0x4A,  /* DACREF1 */
    ADC_MUXPOS_DACREF2_gv          = 0x4B   /* DACREF2 */
} ADC_MUXPOS_values_t;

/* Analog Channel Selection Bits bit group configurations*/
typedef enum ADC_MUXPOS_enum
{
    ADC_MUXPOS_AIN0_gc             = (ADC_MUXPOS_AIN0_gv << ADC_MUXPOS_gp),  /* ADC input pin 0 */
    ADC_MUXPOS_AIN1_gc             = (ADC_MUXPOS_AIN1_gv << ADC_MUXPOS_gp),  /* ADC input pin 1 */
    ADC_MUXPOS_AIN2_gc             = (ADC_MUXPOS_AIN2_gv << ADC_MUXPOS_gp),  /* ADC input pin 2 */
    ADC_MUXPOS_AIN3_gc             = (ADC_MUXPOS_AIN3_gv << ADC_MUXPOS_gp),  /* ADC input pin 3 */
    ADC_MUXPOS_AIN4_gc             = (ADC_MUXPOS_AIN4_gv << ADC_MUXPOS_gp),  /* ADC input pin 4 */
    ADC_MUXPOS_AIN5_gc             = (ADC_MUXPOS_AIN5_gv << ADC_MUXPOS_gp),  /* ADC input pin 5 */
    ADC_MUXPOS_AIN6_gc             = (ADC_MUXPOS_AIN6_gv << ADC_MUXPOS_gp),  /* ADC input pin 6 */
    ADC_MUXPOS_AIN7_gc             = (ADC_MUXPOS_AIN7_gv << ADC_MUXPOS_gp),  /* ADC input pin 7 */
    ADC_MUXPOS_AIN8_gc             = (ADC_MUXPOS_AIN8_gv << ADC_MUXPOS_gp),  /* ADC input pin 8 */
    ADC_MUXPOS_AIN9_gc             = (ADC_MUXPOS_AIN9_gv << ADC_MUXPOS_gp),  /* ADC input pin 9 */
    ADC_MUXPOS_AIN10_gc            = (ADC_MUXPOS_AIN10_gv << ADC_MUXPOS_gp),  /* ADC input pin 10 */
    ADC_MUXPOS_AIN11_gc            = (ADC_MUXPOS_AIN11_gv << ADC_MUXPOS_gp),  /* ADC input pin 11 */
    ADC_MUXPOS_AIN16_gc            = (ADC_MUXPOS_AIN16_gv << ADC_MUXPOS_gp),  /* ADC input pin 16 */
    ADC_MUXPOS_AIN17_gc            = (ADC_MUXPOS_AIN17_gv << ADC_MUXPOS_gp),  /* ADC input pin 17 */
    ADC_MUXPOS_AIN18_gc            = (ADC_MUXPOS_AIN18_gv << ADC_MUXPOS_gp),  /* ADC input pin 18 */
    ADC_MUXPOS_AIN19_gc            = (ADC_MUXPOS_AIN19_gv << ADC_MUXPOS_gp),  /* ADC input pin 19 */
    ADC_MUXPOS_AIN20_gc            = (ADC_MUXPOS_AIN20_gv << ADC_MUXPOS_gp),  /* ADC input pin 20 */
    ADC_MUXPOS_AIN21_gc            = (ADC_MUXPOS_AIN21_gv << ADC_MUXPOS_gp),  /* ADC input pin 21 */
    ADC_MUXPOS_AIN22_gc            = (ADC_MUXPOS_AIN22_gv << ADC_MUXPOS_gp),  /* ADC input pin 22 */
    ADC_MUXPOS_AIN23_gc            = (ADC_MUXPOS_AIN23_gv << ADC_MUXPOS_gp),  /* ADC input pin 23 */
    ADC_MUXPOS_AIN24_gc            = (ADC_MUXPOS_AIN24_gv << ADC_MUXPOS_gp),  /* ADC input pin 24 */
    ADC_MUXPOS_AIN25_gc            = (ADC_MUXPOS_AIN25_gv << ADC_MUXPOS_gp),  /* ADC input pin 25 */
    ADC_MUXPOS_AIN26_gc            = (ADC_MUXPOS_AIN26_gv << ADC_MUXPOS_gp),  /* ADC input pin 26 */
    ADC_MUXPOS_AIN27_gc            = (ADC_MUXPOS_AIN27_gv << ADC_MUXPOS_gp),  /* ADC input pin 27 */
    ADC_MUXPOS_AIN28_gc            = (ADC_MUXPOS_AIN28_gv << ADC_MUXPOS_gp),  /* ADC input pin 28 */
    ADC_MUXPOS_AIN29_gc            = (ADC_MUXPOS_AIN29_gv << ADC_MUXPOS_gp),  /* ADC input pin 29 */
    ADC_MUXPOS_AIN30_gc            = (ADC_MUXPOS_AIN30_gv << ADC_MUXPOS_gp),  /* ADC input pin 30 */
    ADC_MUXPOS_AIN31_gc            = (ADC_MUXPOS_AIN31_gv << ADC_MUXPOS_gp),  /* ADC input pin 31 */
    ADC_MUXPOS_GND_gc              = (ADC_MUXPOS_GND_gv << ADC_MUXPOS_gp),  /* Ground */
    ADC_MUXPOS_VDDCOREDIV4_gc      = (ADC_MUXPOS_VDDCOREDIV4_gv << ADC_MUXPOS_gp),  /* VDDCORE/4 */
    ADC_MUXPOS_TEMPSENSE_gc        = (ADC_MUXPOS_TEMPSENSE_gv << ADC_MUXPOS_gp),  /* Temperature sensor */
    ADC_MUXPOS_VDDDIV10_gc         = (ADC_MUXPOS_VDDDIV10_gv << ADC_MUXPOS_gp),  /* VDD/10 */
    ADC_MUXPOS_VDDIO2DIV10_gc      = (ADC_MUXPOS_VDDIO2DIV10_gv << ADC_MUXPOS_gp),  /* VDDIO2/10 */
    ADC_MUXPOS_DAC0_gc             = (ADC_MUXPOS_DAC0_gv << ADC_MUXPOS_gp),  /* DAC0 */
    ADC_MUXPOS_DACREF0_gc          = (ADC_MUXPOS_DACREF0_gv << ADC_MUXPOS_gp),  /* DACREF0 */
    ADC_MUXPOS_DACREF1_gc          = (ADC_MUXPOS_DACREF1_gv << ADC_MUXPOS_gp),  /* DACREF1 */
    ADC_MUXPOS_DACREF2_gc          = (ADC_MUXPOS_DACREF2_gv << ADC_MUXPOS_gp)   /* DACREF2 */
} ADC_MUXPOS_t;

/* Clock Pre-scaler select bit group values */
typedef enum ADC_PRESC_VALUES_enum
{
    ADC_PRESC_DIV2_gv              = 0x00,  /* CLK_PER divided by 2 */
    ADC_PRESC_DIV4_gv              = 0x01,  /* CLK_PER divided by 4 */
    ADC_PRESC_DIV6_gv              = 0x02,  /* CLK_PER divided by 6 */
    ADC_PRESC_DIV8_gv              = 0x03,  /* CLK_PER divided by 8 */
    ADC_PRESC_DIV10_gv             = 0x04,  /* CLK_PER divided by 10 */
    ADC_PRESC_DIV12_gv             = 0x05,  /* CLK_PER divided by 12 */
    ADC_PRESC_DIV14_gv             = 0x06,  /* CLK_PER divided by 14 */
    ADC_PRESC_DIV16_gv             = 0x07,  /* CLK_PER divided by 16 */
    ADC_PRESC_DIV20_gv             = 0x08,  /* CLK_PER divided by 20 */
    ADC_PRESC_DIV24_gv             = 0x09,  /* CLK_PER divided by 24 */
    ADC_PRESC_DIV28_gv             = 0x0A,  /* CLK_PER divided by 28 */
    ADC_PRESC_DIV32_gv             = 0x0B,  /* CLK_PER divided by 32 */
    ADC_PRESC_DIV40_gv             = 0x0C,  /* CLK_PER divided by 40 */
    ADC_PRESC_DIV48_gv             = 0x0D,  /* CLK_PER divided by 48 */
    ADC_PRESC_DIV56_gv             = 0x0E,  /* CLK_PER divided by 56 */
    ADC_PRESC_DIV64_gv             = 0x0F   /* CLK_PER divided by 64 */
} ADC_PRESC_values_t;

/* Clock Pre-scaler select bit group configurations*/
typedef enum ADC_PRESC_enum
{
    ADC_PRESC_DIV2_gc              = (ADC_PRESC_DIV2_gv << ADC_PRESC_gp),  /* CLK_PER divided by 2 */
    ADC_PRESC_DIV4_gc              = (ADC_PRESC_DIV4_gv << ADC_PRESC_gp),  /* CLK_PER divided by 4 */
    ADC_PRESC_DIV6_gc              = (ADC_PRESC_DIV6_gv << ADC_PRESC_gp),  /* CLK_PER divided by 6 */
    ADC_PRESC_DIV8_gc              = (ADC_PRESC_DIV8_gv << ADC_PRESC_gp),  /* CLK_PER divided by 8 */
    ADC_PRESC_DIV10_gc             = (ADC_PRESC_DIV10_gv << ADC_PRESC_gp),  /* CLK_PER divided by 10 */
    ADC_PRESC_DIV12_gc             = (ADC_PRESC_DIV12_gv << ADC_PRESC_gp),  /* CLK_PER divided by 12 */
    ADC_PRESC_DIV14_gc             = (ADC_PRESC_DIV14_gv << ADC_PRESC_gp),  /* CLK_PER divided by 14 */
    ADC_PRESC_DIV16_gc             = (ADC_PRESC_DIV16_gv << ADC_PRESC_gp),  /* CLK_PER divided by 16 */
    ADC_PRESC_DIV20_gc             = (ADC_PRESC_DIV20_gv << ADC_PRESC_gp),  /* CLK_PER divided by 20 */
    ADC_PRESC_DIV24_gc             = (ADC_PRESC_DIV24_gv << ADC_PRESC_gp),  /* CLK_PER divided by 24 */
    ADC_PRESC_DIV28_gc             = (ADC_PRESC_DIV28_gv << ADC_PRESC_gp),  /* CLK_PER divided by 28 */
    ADC_PRESC_DIV32_gc             = (ADC_PRESC_DIV32_gv << ADC_PRESC_gp),  /* CLK_PER divided by 32 */
    ADC_PRESC_DIV40_gc             = (ADC_PRESC_DIV40_gv << ADC_PRESC_gp),  /* CLK_PER divided by 40 */
    ADC_PRESC_DIV48_gc             = (ADC_PRESC_DIV48_gv << ADC_PRESC_gp),  /* CLK_PER divided by 48 */
    ADC_PRESC_DIV56_gc             = (ADC_PRESC_DIV56_gv << ADC_PRESC_gp),  /* CLK_PER divided by 56 */
    ADC_PRESC_DIV64_gc             = (ADC_PRESC_DIV64_gv << ADC_PRESC_gp)   /* CLK_PER divided by 64 */
} ADC_PRESC_t;

/* Reference Selection bit group values */
typedef enum ADC_REFSEL_VALUES_enum
{
    ADC_REFSEL_VDD_gv              = 0x00,  /* VDD */
    ADC_REFSEL_EXTVREF_gv          = 0x02,  /* VREFA for ADC0, VREFB for ADC1 */
    ADC_REFSEL_1V024_gv            = 0x04,  /* 1.024V */
    ADC_REFSEL_2V048_gv            = 0x05,  /* 2.048V */
    ADC_REFSEL_4V096_gv            = 0x06,  /* 4.096V */
    ADC_REFSEL_2V500_gv            = 0x07   /* 2.5V */
} ADC_REFSEL_values_t;

/* Reference Selection bit group configurations*/
typedef enum ADC_REFSEL_enum
{
    ADC_REFSEL_VDD_gc              = (ADC_REFSEL_VDD_gv << ADC_REFSEL_gp),  /* VDD */
    ADC_REFSEL_EXTVREF_gc          = (ADC_REFSEL_EXTVREF_gv << ADC_REFSEL_gp),  /* VREFA for ADC0, VREFB for ADC1 */
    ADC_REFSEL_1V024_gc            = (ADC_REFSEL_1V024_gv << ADC_REFSEL_gp),  /* 1.024V */
    ADC_REFSEL_2V048_gc            = (ADC_REFSEL_2V048_gv << ADC_REFSEL_gp),  /* 2.048V */
    ADC_REFSEL_4V096_gc            = (ADC_REFSEL_4V096_gv << ADC_REFSEL_gp),  /* 4.096V */
    ADC_REFSEL_2V500_gc            = (ADC_REFSEL_2V500_gv << ADC_REFSEL_gp)   /* 2.5V */
} ADC_REFSEL_t;

/* Sampling Number select bit group values */
typedef enum ADC_SAMPNUM_VALUES_enum
{
    ADC_SAMPNUM_NONE_gv            = 0x00,  /* No accumulation */
    ADC_SAMPNUM_ACC2_gv            = 0x01,  /* 2 results accumulated */
    ADC_SAMPNUM_ACC4_gv            = 0x02,  /* 4 results accumulated */
    ADC_SAMPNUM_ACC8_gv            = 0x03,  /* 8 results accumulated */
    ADC_SAMPNUM_ACC16_gv           = 0x04,  /* 16 results accumulated */
    ADC_SAMPNUM_ACC32_gv           = 0x05,  /* 32 results accumulated */
    ADC_SAMPNUM_ACC64_gv           = 0x06   /* 64 results accumulated */
} ADC_SAMPNUM_values_t;

/* Sampling Number select bit group configurations*/
typedef enum ADC_SAMPNUM_enum
{
    ADC_SAMPNUM_NONE_gc            = (ADC_SAMPNUM_NONE_gv << ADC_SAMPNUM_gp),  /* No accumulation */
    ADC_SAMPNUM_ACC2_gc            = (ADC_SAMPNUM_ACC2_gv << ADC_SAMPNUM_gp),  /* 2 results accumulated */
    ADC_SAMPNUM_ACC4_gc            = (ADC_SAMPNUM_ACC4_gv << ADC_SAMPNUM_gp),  /* 4 results accumulated */
    ADC_SAMPNUM_ACC8_gc            = (ADC_SAMPNUM_ACC8_gv << ADC_SAMPNUM_gp),  /* 8 results accumulated */
    ADC_SAMPNUM_ACC16_gc           = (ADC_SAMPNUM_ACC16_gv << ADC_SAMPNUM_gp),  /* 16 results accumulated */
    ADC_SAMPNUM_ACC32_gc           = (ADC_SAMPNUM_ACC32_gv << ADC_SAMPNUM_gp),  /* 32 results accumulated */
    ADC_SAMPNUM_ACC64_gc           = (ADC_SAMPNUM_ACC64_gv << ADC_SAMPNUM_gp)   /* 64 results accumulated */
} ADC_SAMPNUM_t;

/* Start Conversion select bit group values */
typedef enum ADC_START_VALUES_enum
{
    ADC_START_STOP_gv              = 0x00,  /* Stop/No ongoing conv */
    ADC_START_IMMEDIATE_gv         = 0x01,  /* Start Immediately */
    ADC_START_MUXPOS_WRITE_gv      = 0x02,  /* Start after a write to MUXPOS */
    ADC_START_EVENT_TRIGGER_gv     = 0x04   /* Start upon event reception */
} ADC_START_values_t;

/* Start Conversion select bit group configurations*/
typedef enum ADC_START_enum
{
    ADC_START_STOP_gc              = (ADC_START_STOP_gv << ADC_START_gp),  /* Stop/No ongoing conv */
    ADC_START_IMMEDIATE_gc         = (ADC_START_IMMEDIATE_gv << ADC_START_gp),  /* Start Immediately */
    ADC_START_MUXPOS_WRITE_gc      = (ADC_START_MUXPOS_WRITE_gv << ADC_START_gp),  /* Start after a write to MUXPOS */
    ADC_START_EVENT_TRIGGER_gc     = (ADC_START_EVENT_TRIGGER_gv << ADC_START_gp)   /* Start upon event reception */
} ADC_START_t;

/* Window Comparator Mode select bit group values */
typedef enum ADC_WINCM_VALUES_enum
{
    ADC_WINCM_NONE_gv              = 0x00,  /* No Window Comparison */
    ADC_WINCM_BELOW_gv             = 0x01,  /* Below Window */
    ADC_WINCM_ABOVE_gv             = 0x02,  /* Above Window */
    ADC_WINCM_INSIDE_gv            = 0x03,  /* Inside Window */
    ADC_WINCM_OUTSIDE_gv           = 0x04   /* Outside Window */
} ADC_WINCM_values_t;

/* Window Comparator Mode select bit group configurations*/
typedef enum ADC_WINCM_enum
{
    ADC_WINCM_NONE_gc              = (ADC_WINCM_NONE_gv << ADC_WINCM_gp),  /* No Window Comparison */
    ADC_WINCM_BELOW_gc             = (ADC_WINCM_BELOW_gv << ADC_WINCM_gp),  /* Below Window */
    ADC_WINCM_ABOVE_gc             = (ADC_WINCM_ABOVE_gv << ADC_WINCM_gp),  /* Above Window */
    ADC_WINCM_INSIDE_gc            = (ADC_WINCM_INSIDE_gv << ADC_WINCM_gp),  /* Inside Window */
    ADC_WINCM_OUTSIDE_gc           = (ADC_WINCM_OUTSIDE_gv << ADC_WINCM_gp)   /* Outside Window */
} ADC_WINCM_t;

/*
--------------------------------------------------------------------------
BOD - Bod interface
--------------------------------------------------------------------------
*/

/* Bod interface */
typedef struct BOD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t reserved_1[6];
    register8_t VLMCTRLA;  /* Voltage level monitor Control */
    register8_t INTCTRL;  /* Voltage level monitor interrupt Control */
    register8_t INTFLAGS;  /* Voltage level monitor interrupt Flags */
    register8_t STATUS;  /* Voltage level monitor status */
    register8_t reserved_2[4];
} BOD_t;

/* Operation in active mode select bit group values */
typedef enum BOD_ACTIVE_VALUES_enum
{
    BOD_ACTIVE_DISABLE_gv          = 0x00,  /* BOD disabled */
    BOD_ACTIVE_ENABLE_gv           = 0x01,  /* BOD enabled in continuous mode */
    BOD_ACTIVE_SAMPLE_gv           = 0x02,  /* BOD enabled in sampled mode */
    BOD_ACTIVE_ENABLEWAIT_gv       = 0x03   /* BOD enabled in continuous mode. Execution is halted at wake-up until BOD is running. */
} BOD_ACTIVE_values_t;

/* Operation in active mode select bit group configurations*/
typedef enum BOD_ACTIVE_enum
{
    BOD_ACTIVE_DISABLE_gc          = (BOD_ACTIVE_DISABLE_gv << BOD_ACTIVE_gp),  /* BOD disabled */
    BOD_ACTIVE_ENABLE_gc           = (BOD_ACTIVE_ENABLE_gv << BOD_ACTIVE_gp),  /* BOD enabled in continuous mode */
    BOD_ACTIVE_SAMPLE_gc           = (BOD_ACTIVE_SAMPLE_gv << BOD_ACTIVE_gp),  /* BOD enabled in sampled mode */
    BOD_ACTIVE_ENABLEWAIT_gc       = (BOD_ACTIVE_ENABLEWAIT_gv << BOD_ACTIVE_gp)   /* BOD enabled in continuous mode. Execution is halted at wake-up until BOD is running. */
} BOD_ACTIVE_t;

/* Bod level select bit group values */
typedef enum BOD_LVL_VALUES_enum
{
    BOD_LVL_BODLEVEL0_gv           = 0x00,  /* 1.9V */
    BOD_LVL_BODLEVEL1_gv           = 0x01,  /* 2.45V */
    BOD_LVL_BODLEVEL2_gv           = 0x02,  /* 2.7V */
    BOD_LVL_BODLEVEL3_gv           = 0x03   /* 2.85V */
} BOD_LVL_values_t;

/* Bod level select bit group configurations*/
typedef enum BOD_LVL_enum
{
    BOD_LVL_BODLEVEL0_gc           = (BOD_LVL_BODLEVEL0_gv << BOD_LVL_gp),  /* 1.9V */
    BOD_LVL_BODLEVEL1_gc           = (BOD_LVL_BODLEVEL1_gv << BOD_LVL_gp),  /* 2.45V */
    BOD_LVL_BODLEVEL2_gc           = (BOD_LVL_BODLEVEL2_gv << BOD_LVL_gp),  /* 2.7V */
    BOD_LVL_BODLEVEL3_gc           = (BOD_LVL_BODLEVEL3_gv << BOD_LVL_gp)   /* 2.85V */
} BOD_LVL_t;

/* Sample frequency select bit group values */
typedef enum BOD_SAMPFREQ_VALUES_enum
{
    BOD_SAMPFREQ_128HZ_gv          = 0x00,  /* Sample frequency is 128 Hz */
    BOD_SAMPFREQ_32HZ_gv           = 0x01   /* Sample frequency is 32 Hz */
} BOD_SAMPFREQ_values_t;

/* Sample frequency select bit group configurations*/
typedef enum BOD_SAMPFREQ_enum
{
    BOD_SAMPFREQ_128HZ_gc          = (BOD_SAMPFREQ_128HZ_gv << BOD_SAMPFREQ_bp),  /* Sample frequency is 128 Hz */
    BOD_SAMPFREQ_32HZ_gc           = (BOD_SAMPFREQ_32HZ_gv << BOD_SAMPFREQ_bp)   /* Sample frequency is 32 Hz */
} BOD_SAMPFREQ_t;

/* Operation in sleep mode select bit group values */
typedef enum BOD_SLEEP_VALUES_enum
{
    BOD_SLEEP_DISABLE_gv           = 0x00,  /* BOD disabled */
    BOD_SLEEP_ENABLE_gv            = 0x01,  /* BOD enabled in continuous mode */
    BOD_SLEEP_SAMPLE_gv            = 0x02   /* BOD enabled in sampled mode */
} BOD_SLEEP_values_t;

/* Operation in sleep mode select bit group configurations*/
typedef enum BOD_SLEEP_enum
{
    BOD_SLEEP_DISABLE_gc           = (BOD_SLEEP_DISABLE_gv << BOD_SLEEP_gp),  /* BOD disabled */
    BOD_SLEEP_ENABLE_gc            = (BOD_SLEEP_ENABLE_gv << BOD_SLEEP_gp),  /* BOD enabled in continuous mode */
    BOD_SLEEP_SAMPLE_gc            = (BOD_SLEEP_SAMPLE_gv << BOD_SLEEP_gp)   /* BOD enabled in sampled mode */
} BOD_SLEEP_t;

/* Configuration select bit group values */
typedef enum BOD_VLMCFG_VALUES_enum
{
    BOD_VLMCFG_FALLING_gv          = 0x00,  /* VDD falls below VLM threshold */
    BOD_VLMCFG_RISING_gv           = 0x01,  /* VDD rises above VLM threshold */
    BOD_VLMCFG_BOTH_gv             = 0x02   /* VDD crosses VLM threshold */
} BOD_VLMCFG_values_t;

/* Configuration select bit group configurations*/
typedef enum BOD_VLMCFG_enum
{
    BOD_VLMCFG_FALLING_gc          = (BOD_VLMCFG_FALLING_gv << BOD_VLMCFG_gp),  /* VDD falls below VLM threshold */
    BOD_VLMCFG_RISING_gc           = (BOD_VLMCFG_RISING_gv << BOD_VLMCFG_gp),  /* VDD rises above VLM threshold */
    BOD_VLMCFG_BOTH_gc             = (BOD_VLMCFG_BOTH_gv << BOD_VLMCFG_gp)   /* VDD crosses VLM threshold */
} BOD_VLMCFG_t;

/* voltage level monitor level select bit group values */
typedef enum BOD_VLMLVL_VALUES_enum
{
    BOD_VLMLVL_OFF_gv              = 0x00,  /* VLM Disabled */
    BOD_VLMLVL_5ABOVE_gv           = 0x01,  /* VLM threshold 5% above BOD level */
    BOD_VLMLVL_15ABOVE_gv          = 0x02,  /* VLM threshold 15% above BOD level */
    BOD_VLMLVL_25ABOVE_gv          = 0x03   /* VLM threshold 25% above BOD level */
} BOD_VLMLVL_values_t;

/* voltage level monitor level select bit group configurations*/
typedef enum BOD_VLMLVL_enum
{
    BOD_VLMLVL_OFF_gc              = (BOD_VLMLVL_OFF_gv << BOD_VLMLVL_gp),  /* VLM Disabled */
    BOD_VLMLVL_5ABOVE_gc           = (BOD_VLMLVL_5ABOVE_gv << BOD_VLMLVL_gp),  /* VLM threshold 5% above BOD level */
    BOD_VLMLVL_15ABOVE_gc          = (BOD_VLMLVL_15ABOVE_gv << BOD_VLMLVL_gp),  /* VLM threshold 15% above BOD level */
    BOD_VLMLVL_25ABOVE_gc          = (BOD_VLMLVL_25ABOVE_gv << BOD_VLMLVL_gp)   /* VLM threshold 25% above BOD level */
} BOD_VLMLVL_t;

/* Voltage level monitor status select bit group values */
typedef enum BOD_VLMS_VALUES_enum
{
    BOD_VLMS_ABOVE_gv              = 0x00,  /* The voltage is above the VLM threshold level */
    BOD_VLMS_BELOW_gv              = 0x01   /* The voltage is below the VLM threshold level */
} BOD_VLMS_values_t;

/* Voltage level monitor status select bit group configurations*/
typedef enum BOD_VLMS_enum
{
    BOD_VLMS_ABOVE_gc              = (BOD_VLMS_ABOVE_gv << BOD_VLMS_bp),  /* The voltage is above the VLM threshold level */
    BOD_VLMS_BELOW_gc              = (BOD_VLMS_BELOW_gv << BOD_VLMS_bp)   /* The voltage is below the VLM threshold level */
} BOD_VLMS_t;

/*
--------------------------------------------------------------------------
BOOTROW - Boot Row
--------------------------------------------------------------------------
*/

/* Boot Row */
typedef struct BOOTROW_struct
{
    register8_t BOOTROW[256];  /* Boot Row */
} BOOTROW_t;


/*
--------------------------------------------------------------------------
CCL - Configurable Custom Logic
--------------------------------------------------------------------------
*/

/* Configurable Custom Logic */
typedef struct CCL_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t SEQCTRL0;  /* Sequential Control 0 */
    register8_t SEQCTRL1;  /* Sequential Control 1 */
    register8_t SEQCTRL2;  /* Sequential Control 2 */
    register8_t reserved_1[1];
    register8_t INTCTRL0;  /* Interrupt Control 0 */
    register8_t INTCTRL1;  /* Interrupt Control 1 */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t LUT0CTRLA;  /* LUT 0 Control A */
    register8_t LUT0CTRLB;  /* LUT 0 Control B */
    register8_t LUT0CTRLC;  /* LUT 0 Control C */
    register8_t TRUTH0;  /* Truth 0 */
    register8_t LUT1CTRLA;  /* LUT 1 Control A */
    register8_t LUT1CTRLB;  /* LUT 1 Control B */
    register8_t LUT1CTRLC;  /* LUT 1 Control C */
    register8_t TRUTH1;  /* Truth 1 */
    register8_t LUT2CTRLA;  /* LUT 2 Control A */
    register8_t LUT2CTRLB;  /* LUT 2 Control B */
    register8_t LUT2CTRLC;  /* LUT 2 Control C */
    register8_t TRUTH2;  /* Truth 2 */
    register8_t LUT3CTRLA;  /* LUT 3 Control A */
    register8_t LUT3CTRLB;  /* LUT 3 Control B */
    register8_t LUT3CTRLC;  /* LUT 3 Control C */
    register8_t TRUTH3;  /* Truth 3 */
    register8_t LUT4CTRLA;  /* LUT 4 Control A */
    register8_t LUT4CTRLB;  /* LUT 4 Control B */
    register8_t LUT4CTRLC;  /* LUT 4 Control C */
    register8_t TRUTH4;  /* Truth 4 */
    register8_t LUT5CTRLA;  /* LUT 5 Control A */
    register8_t LUT5CTRLB;  /* LUT 5 Control B */
    register8_t LUT5CTRLC;  /* LUT 5 Control C */
    register8_t TRUTH5;  /* Truth 5 */
    register8_t reserved_2[32];
} CCL_t;

/* Clock Source Selection bit group values */
typedef enum CCL_CLKSRC_VALUES_enum
{
    CCL_CLKSRC_CLKPER_gv           = 0x00,  /* Peripheral Clock */
    CCL_CLKSRC_IN2_gv              = 0x01,  /* Selection by INSEL2 */
    CCL_CLKSRC_OSCHF_gv            = 0x04,  /* Internal High-Frequency Oscillator */
    CCL_CLKSRC_OSC32K_gv           = 0x05,  /* 32.768 kHz oscillator */
    CCL_CLKSRC_OSC1K_gv            = 0x06   /* 32.768 kHz oscillator divided by 32 */
} CCL_CLKSRC_values_t;

/* Clock Source Selection bit group configurations*/
typedef enum CCL_CLKSRC_enum
{
    CCL_CLKSRC_CLKPER_gc           = (CCL_CLKSRC_CLKPER_gv << CCL_CLKSRC_gp),  /* Peripheral Clock */
    CCL_CLKSRC_IN2_gc              = (CCL_CLKSRC_IN2_gv << CCL_CLKSRC_gp),  /* Selection by INSEL2 */
    CCL_CLKSRC_OSCHF_gc            = (CCL_CLKSRC_OSCHF_gv << CCL_CLKSRC_gp),  /* Internal High-Frequency Oscillator */
    CCL_CLKSRC_OSC32K_gc           = (CCL_CLKSRC_OSC32K_gv << CCL_CLKSRC_gp),  /* 32.768 kHz oscillator */
    CCL_CLKSRC_OSC1K_gc            = (CCL_CLKSRC_OSC1K_gv << CCL_CLKSRC_gp)   /* 32.768 kHz oscillator divided by 32 */
} CCL_CLKSRC_t;

/* Edge Detection Enable select bit group values */
typedef enum CCL_EDGEDET_VALUES_enum
{
    CCL_EDGEDET_DIS_gv             = 0x00,  /* Edge detector is disabled */
    CCL_EDGEDET_EN_gv              = 0x01   /* Edge detector is enabled */
} CCL_EDGEDET_values_t;

/* Edge Detection Enable select bit group configurations*/
typedef enum CCL_EDGEDET_enum
{
    CCL_EDGEDET_DIS_gc             = (CCL_EDGEDET_DIS_gv << CCL_EDGEDET_bp),  /* Edge detector is disabled */
    CCL_EDGEDET_EN_gc              = (CCL_EDGEDET_EN_gv << CCL_EDGEDET_bp)   /* Edge detector is enabled */
} CCL_EDGEDET_t;

/* Filter Selection bit group values */
typedef enum CCL_FILTSEL_VALUES_enum
{
    CCL_FILTSEL_DISABLE_gv         = 0x00,  /* Filter disabled */
    CCL_FILTSEL_SYNCH_gv           = 0x01,  /* Synchronizer enabled */
    CCL_FILTSEL_FILTER_gv          = 0x02   /* Filter enabled */
} CCL_FILTSEL_values_t;

/* Filter Selection bit group configurations*/
typedef enum CCL_FILTSEL_enum
{
    CCL_FILTSEL_DISABLE_gc         = (CCL_FILTSEL_DISABLE_gv << CCL_FILTSEL_gp),  /* Filter disabled */
    CCL_FILTSEL_SYNCH_gc           = (CCL_FILTSEL_SYNCH_gv << CCL_FILTSEL_gp),  /* Synchronizer enabled */
    CCL_FILTSEL_FILTER_gc          = (CCL_FILTSEL_FILTER_gv << CCL_FILTSEL_gp)   /* Filter enabled */
} CCL_FILTSEL_t;

/* LUT Input 0 Source Selection bit group values */
typedef enum CCL_INSEL0_VALUES_enum
{
    CCL_INSEL0_MASK_gv             = 0x00,  /* Masked input */
    CCL_INSEL0_FEEDBACK_gv         = 0x01,  /* Feedback input source */
    CCL_INSEL0_LINK_gv             = 0x02,  /* Linked LUT input source */
    CCL_INSEL0_EVENTA_gv           = 0x03,  /* Event input source A */
    CCL_INSEL0_EVENTB_gv           = 0x04,  /* Event input source B */
    CCL_INSEL0_IN0_gv              = 0x05,  /* IO pin LUTn-IN0 input source */
    CCL_INSEL0_AC0_gv              = 0x06,  /* AC0 OUT input source */
    CCL_INSEL0_USART0_gv           = 0x08,  /* USART0 TXD input source */
    CCL_INSEL0_SPI0_gv             = 0x09,  /* SPI0 MOSI input source */
    CCL_INSEL0_TCA0_gv             = 0x0A,  /* TCA0 WO0 input source */
    CCL_INSEL0_TCB0_gv             = 0x0B,  /* TCB0 WO input source */
    CCL_INSEL0_TCD0_gv             = 0x0C   /* TCD0 WOA input source */
} CCL_INSEL0_values_t;

/* LUT Input 0 Source Selection bit group configurations*/
typedef enum CCL_INSEL0_enum
{
    CCL_INSEL0_MASK_gc             = (CCL_INSEL0_MASK_gv << CCL_INSEL0_gp),  /* Masked input */
    CCL_INSEL0_FEEDBACK_gc         = (CCL_INSEL0_FEEDBACK_gv << CCL_INSEL0_gp),  /* Feedback input source */
    CCL_INSEL0_LINK_gc             = (CCL_INSEL0_LINK_gv << CCL_INSEL0_gp),  /* Linked LUT input source */
    CCL_INSEL0_EVENTA_gc           = (CCL_INSEL0_EVENTA_gv << CCL_INSEL0_gp),  /* Event input source A */
    CCL_INSEL0_EVENTB_gc           = (CCL_INSEL0_EVENTB_gv << CCL_INSEL0_gp),  /* Event input source B */
    CCL_INSEL0_IN0_gc              = (CCL_INSEL0_IN0_gv << CCL_INSEL0_gp),  /* IO pin LUTn-IN0 input source */
    CCL_INSEL0_AC0_gc              = (CCL_INSEL0_AC0_gv << CCL_INSEL0_gp),  /* AC0 OUT input source */
    CCL_INSEL0_USART0_gc           = (CCL_INSEL0_USART0_gv << CCL_INSEL0_gp),  /* USART0 TXD input source */
    CCL_INSEL0_SPI0_gc             = (CCL_INSEL0_SPI0_gv << CCL_INSEL0_gp),  /* SPI0 MOSI input source */
    CCL_INSEL0_TCA0_gc             = (CCL_INSEL0_TCA0_gv << CCL_INSEL0_gp),  /* TCA0 WO0 input source */
    CCL_INSEL0_TCB0_gc             = (CCL_INSEL0_TCB0_gv << CCL_INSEL0_gp),  /* TCB0 WO input source */
    CCL_INSEL0_TCD0_gc             = (CCL_INSEL0_TCD0_gv << CCL_INSEL0_gp)   /* TCD0 WOA input source */
} CCL_INSEL0_t;

/* LUT Input 1 Source Selection bit group values */
typedef enum CCL_INSEL1_VALUES_enum
{
    CCL_INSEL1_MASK_gv             = 0x00,  /* Masked input */
    CCL_INSEL1_FEEDBACK_gv         = 0x01,  /* Feedback input source */
    CCL_INSEL1_LINK_gv             = 0x02,  /* Linked LUT input source */
    CCL_INSEL1_EVENTA_gv           = 0x03,  /* Event input source A */
    CCL_INSEL1_EVENTB_gv           = 0x04,  /* Event input source B */
    CCL_INSEL1_IN1_gv              = 0x05,  /* IO pin LUTn-IN1 input source */
    CCL_INSEL1_AC1_gv              = 0x06,  /* AC1 OUT input source */
    CCL_INSEL1_ZCD3_gv             = 0x07,  /* ZCD3 OUT input source */
    CCL_INSEL1_USART1_gv           = 0x08,  /* USART1 TXD input source */
    CCL_INSEL1_SPI0_gv             = 0x09,  /* SPI0 MOSI input source */
    CCL_INSEL1_TCA0_gv             = 0x0A,  /* TCA0 WO1 input source */
    CCL_INSEL1_TCB1_gv             = 0x0B,  /* TCB1 WO input source */
    CCL_INSEL1_TCD0_gv             = 0x0C   /* TCD0 WOB input source */
} CCL_INSEL1_values_t;

/* LUT Input 1 Source Selection bit group configurations*/
typedef enum CCL_INSEL1_enum
{
    CCL_INSEL1_MASK_gc             = (CCL_INSEL1_MASK_gv << CCL_INSEL1_gp),  /* Masked input */
    CCL_INSEL1_FEEDBACK_gc         = (CCL_INSEL1_FEEDBACK_gv << CCL_INSEL1_gp),  /* Feedback input source */
    CCL_INSEL1_LINK_gc             = (CCL_INSEL1_LINK_gv << CCL_INSEL1_gp),  /* Linked LUT input source */
    CCL_INSEL1_EVENTA_gc           = (CCL_INSEL1_EVENTA_gv << CCL_INSEL1_gp),  /* Event input source A */
    CCL_INSEL1_EVENTB_gc           = (CCL_INSEL1_EVENTB_gv << CCL_INSEL1_gp),  /* Event input source B */
    CCL_INSEL1_IN1_gc              = (CCL_INSEL1_IN1_gv << CCL_INSEL1_gp),  /* IO pin LUTn-IN1 input source */
    CCL_INSEL1_AC1_gc              = (CCL_INSEL1_AC1_gv << CCL_INSEL1_gp),  /* AC1 OUT input source */
    CCL_INSEL1_ZCD3_gc             = (CCL_INSEL1_ZCD3_gv << CCL_INSEL1_gp),  /* ZCD3 OUT input source */
    CCL_INSEL1_USART1_gc           = (CCL_INSEL1_USART1_gv << CCL_INSEL1_gp),  /* USART1 TXD input source */
    CCL_INSEL1_SPI0_gc             = (CCL_INSEL1_SPI0_gv << CCL_INSEL1_gp),  /* SPI0 MOSI input source */
    CCL_INSEL1_TCA0_gc             = (CCL_INSEL1_TCA0_gv << CCL_INSEL1_gp),  /* TCA0 WO1 input source */
    CCL_INSEL1_TCB1_gc             = (CCL_INSEL1_TCB1_gv << CCL_INSEL1_gp),  /* TCB1 WO input source */
    CCL_INSEL1_TCD0_gc             = (CCL_INSEL1_TCD0_gv << CCL_INSEL1_gp)   /* TCD0 WOB input source */
} CCL_INSEL1_t;

/* LUT Input 2 Source Selection bit group values */
typedef enum CCL_INSEL2_VALUES_enum
{
    CCL_INSEL2_MASK_gv             = 0x00,  /* Masked input */
    CCL_INSEL2_FEEDBACK_gv         = 0x01,  /* Feedback input source */
    CCL_INSEL2_LINK_gv             = 0x02,  /* Linked LUT input source */
    CCL_INSEL2_EVENTA_gv           = 0x03,  /* Event input source A */
    CCL_INSEL2_EVENTB_gv           = 0x04,  /* Event input source B */
    CCL_INSEL2_IN2_gv              = 0x05,  /* IO pin LUTn-IN2 input source */
    CCL_INSEL2_AC2_gv              = 0x06,  /* AC2 OUT input source */
    CCL_INSEL2_ZCD3_gv             = 0x07,  /* ZCD3 OUT input source */
    CCL_INSEL2_USART2_gv           = 0x08,  /* USART2 TXD input source */
    CCL_INSEL2_SPI0_gv             = 0x09,  /* SPI0 SCK input source */
    CCL_INSEL2_TCA0_gv             = 0x0A,  /* TCA0 WO2 input source */
    CCL_INSEL2_TCB2_gv             = 0x0B,  /* TCB2 WO input source */
    CCL_INSEL2_TCD0_gv             = 0x0C   /* TCD0 WOC input source */
} CCL_INSEL2_values_t;

/* LUT Input 2 Source Selection bit group configurations*/
typedef enum CCL_INSEL2_enum
{
    CCL_INSEL2_MASK_gc             = (CCL_INSEL2_MASK_gv << CCL_INSEL2_gp),  /* Masked input */
    CCL_INSEL2_FEEDBACK_gc         = (CCL_INSEL2_FEEDBACK_gv << CCL_INSEL2_gp),  /* Feedback input source */
    CCL_INSEL2_LINK_gc             = (CCL_INSEL2_LINK_gv << CCL_INSEL2_gp),  /* Linked LUT input source */
    CCL_INSEL2_EVENTA_gc           = (CCL_INSEL2_EVENTA_gv << CCL_INSEL2_gp),  /* Event input source A */
    CCL_INSEL2_EVENTB_gc           = (CCL_INSEL2_EVENTB_gv << CCL_INSEL2_gp),  /* Event input source B */
    CCL_INSEL2_IN2_gc              = (CCL_INSEL2_IN2_gv << CCL_INSEL2_gp),  /* IO pin LUTn-IN2 input source */
    CCL_INSEL2_AC2_gc              = (CCL_INSEL2_AC2_gv << CCL_INSEL2_gp),  /* AC2 OUT input source */
    CCL_INSEL2_ZCD3_gc             = (CCL_INSEL2_ZCD3_gv << CCL_INSEL2_gp),  /* ZCD3 OUT input source */
    CCL_INSEL2_USART2_gc           = (CCL_INSEL2_USART2_gv << CCL_INSEL2_gp),  /* USART2 TXD input source */
    CCL_INSEL2_SPI0_gc             = (CCL_INSEL2_SPI0_gv << CCL_INSEL2_gp),  /* SPI0 SCK input source */
    CCL_INSEL2_TCA0_gc             = (CCL_INSEL2_TCA0_gv << CCL_INSEL2_gp),  /* TCA0 WO2 input source */
    CCL_INSEL2_TCB2_gc             = (CCL_INSEL2_TCB2_gv << CCL_INSEL2_gp),  /* TCB2 WO input source */
    CCL_INSEL2_TCD0_gc             = (CCL_INSEL2_TCD0_gv << CCL_INSEL2_gp)   /* TCD0 WOC input source */
} CCL_INSEL2_t;

/* Interrupt Mode for LUT0 select bit group values */
typedef enum CCL_INTMODE0_VALUES_enum
{
    CCL_INTMODE0_INTDISABLE_gv     = 0x00,  /* Interrupt disabled */
    CCL_INTMODE0_RISING_gv         = 0x01,  /* Sense rising edge */
    CCL_INTMODE0_FALLING_gv        = 0x02,  /* Sense falling edge */
    CCL_INTMODE0_BOTH_gv           = 0x03   /* Sense both edges */
} CCL_INTMODE0_values_t;

/* Interrupt Mode for LUT0 select bit group configurations*/
typedef enum CCL_INTMODE0_enum
{
    CCL_INTMODE0_INTDISABLE_gc     = (CCL_INTMODE0_INTDISABLE_gv << CCL_INTMODE0_gp),  /* Interrupt disabled */
    CCL_INTMODE0_RISING_gc         = (CCL_INTMODE0_RISING_gv << CCL_INTMODE0_gp),  /* Sense rising edge */
    CCL_INTMODE0_FALLING_gc        = (CCL_INTMODE0_FALLING_gv << CCL_INTMODE0_gp),  /* Sense falling edge */
    CCL_INTMODE0_BOTH_gc           = (CCL_INTMODE0_BOTH_gv << CCL_INTMODE0_gp)   /* Sense both edges */
} CCL_INTMODE0_t;

/* Interrupt Mode for LUT1 select bit group values */
typedef enum CCL_INTMODE1_VALUES_enum
{
    CCL_INTMODE1_INTDISABLE_gv     = 0x00,  /* Interrupt disabled */
    CCL_INTMODE1_RISING_gv         = 0x01,  /* Sense rising edge */
    CCL_INTMODE1_FALLING_gv        = 0x02,  /* Sense falling edge */
    CCL_INTMODE1_BOTH_gv           = 0x03   /* Sense both edges */
} CCL_INTMODE1_values_t;

/* Interrupt Mode for LUT1 select bit group configurations*/
typedef enum CCL_INTMODE1_enum
{
    CCL_INTMODE1_INTDISABLE_gc     = (CCL_INTMODE1_INTDISABLE_gv << CCL_INTMODE1_gp),  /* Interrupt disabled */
    CCL_INTMODE1_RISING_gc         = (CCL_INTMODE1_RISING_gv << CCL_INTMODE1_gp),  /* Sense rising edge */
    CCL_INTMODE1_FALLING_gc        = (CCL_INTMODE1_FALLING_gv << CCL_INTMODE1_gp),  /* Sense falling edge */
    CCL_INTMODE1_BOTH_gc           = (CCL_INTMODE1_BOTH_gv << CCL_INTMODE1_gp)   /* Sense both edges */
} CCL_INTMODE1_t;

/* Interrupt Mode for LUT2 select bit group values */
typedef enum CCL_INTMODE2_VALUES_enum
{
    CCL_INTMODE2_INTDISABLE_gv     = 0x00,  /* Interrupt disabled */
    CCL_INTMODE2_RISING_gv         = 0x01,  /* Sense rising edge */
    CCL_INTMODE2_FALLING_gv        = 0x02,  /* Sense falling edge */
    CCL_INTMODE2_BOTH_gv           = 0x03   /* Sense both edges */
} CCL_INTMODE2_values_t;

/* Interrupt Mode for LUT2 select bit group configurations*/
typedef enum CCL_INTMODE2_enum
{
    CCL_INTMODE2_INTDISABLE_gc     = (CCL_INTMODE2_INTDISABLE_gv << CCL_INTMODE2_gp),  /* Interrupt disabled */
    CCL_INTMODE2_RISING_gc         = (CCL_INTMODE2_RISING_gv << CCL_INTMODE2_gp),  /* Sense rising edge */
    CCL_INTMODE2_FALLING_gc        = (CCL_INTMODE2_FALLING_gv << CCL_INTMODE2_gp),  /* Sense falling edge */
    CCL_INTMODE2_BOTH_gc           = (CCL_INTMODE2_BOTH_gv << CCL_INTMODE2_gp)   /* Sense both edges */
} CCL_INTMODE2_t;

/* Interrupt Mode for LUT3 select bit group values */
typedef enum CCL_INTMODE3_VALUES_enum
{
    CCL_INTMODE3_INTDISABLE_gv     = 0x00,  /* Interrupt disabled */
    CCL_INTMODE3_RISING_gv         = 0x01,  /* Sense rising edge */
    CCL_INTMODE3_FALLING_gv        = 0x02,  /* Sense falling edge */
    CCL_INTMODE3_BOTH_gv           = 0x03   /* Sense both edges */
} CCL_INTMODE3_values_t;

/* Interrupt Mode for LUT3 select bit group configurations*/
typedef enum CCL_INTMODE3_enum
{
    CCL_INTMODE3_INTDISABLE_gc     = (CCL_INTMODE3_INTDISABLE_gv << CCL_INTMODE3_gp),  /* Interrupt disabled */
    CCL_INTMODE3_RISING_gc         = (CCL_INTMODE3_RISING_gv << CCL_INTMODE3_gp),  /* Sense rising edge */
    CCL_INTMODE3_FALLING_gc        = (CCL_INTMODE3_FALLING_gv << CCL_INTMODE3_gp),  /* Sense falling edge */
    CCL_INTMODE3_BOTH_gc           = (CCL_INTMODE3_BOTH_gv << CCL_INTMODE3_gp)   /* Sense both edges */
} CCL_INTMODE3_t;

/* Interrupt Mode for LUT4 select bit group values */
typedef enum CCL_INTMODE4_VALUES_enum
{
    CCL_INTMODE4_INTDISABLE_gv     = 0x00,  /* Interrupt disabled */
    CCL_INTMODE4_RISING_gv         = 0x01,  /* Sense rising edge */
    CCL_INTMODE4_FALLING_gv        = 0x02,  /* Sense falling edge */
    CCL_INTMODE4_BOTH_gv           = 0x03   /* Sense both edges */
} CCL_INTMODE4_values_t;

/* Interrupt Mode for LUT4 select bit group configurations*/
typedef enum CCL_INTMODE4_enum
{
    CCL_INTMODE4_INTDISABLE_gc     = (CCL_INTMODE4_INTDISABLE_gv << CCL_INTMODE4_gp),  /* Interrupt disabled */
    CCL_INTMODE4_RISING_gc         = (CCL_INTMODE4_RISING_gv << CCL_INTMODE4_gp),  /* Sense rising edge */
    CCL_INTMODE4_FALLING_gc        = (CCL_INTMODE4_FALLING_gv << CCL_INTMODE4_gp),  /* Sense falling edge */
    CCL_INTMODE4_BOTH_gc           = (CCL_INTMODE4_BOTH_gv << CCL_INTMODE4_gp)   /* Sense both edges */
} CCL_INTMODE4_t;

/* Interrupt Mode for LUT5 select bit group values */
typedef enum CCL_INTMODE5_VALUES_enum
{
    CCL_INTMODE5_INTDISABLE_gv     = 0x00,  /* Interrupt disabled */
    CCL_INTMODE5_RISING_gv         = 0x01,  /* Sense rising edge */
    CCL_INTMODE5_FALLING_gv        = 0x02,  /* Sense falling edge */
    CCL_INTMODE5_BOTH_gv           = 0x03   /* Sense both edges */
} CCL_INTMODE5_values_t;

/* Interrupt Mode for LUT5 select bit group configurations*/
typedef enum CCL_INTMODE5_enum
{
    CCL_INTMODE5_INTDISABLE_gc     = (CCL_INTMODE5_INTDISABLE_gv << CCL_INTMODE5_gp),  /* Interrupt disabled */
    CCL_INTMODE5_RISING_gc         = (CCL_INTMODE5_RISING_gv << CCL_INTMODE5_gp),  /* Sense rising edge */
    CCL_INTMODE5_FALLING_gc        = (CCL_INTMODE5_FALLING_gv << CCL_INTMODE5_gp),  /* Sense falling edge */
    CCL_INTMODE5_BOTH_gc           = (CCL_INTMODE5_BOTH_gv << CCL_INTMODE5_gp)   /* Sense both edges */
} CCL_INTMODE5_t;

/* Sequential Selection bit group values */
typedef enum CCL_SEQSEL_VALUES_enum
{
    CCL_SEQSEL_DISABLE_gv          = 0x00,  /* Sequential logic disabled */
    CCL_SEQSEL_DFF_gv              = 0x01,  /* D FlipFlop */
    CCL_SEQSEL_JK_gv               = 0x02,  /* JK FlipFlop */
    CCL_SEQSEL_LATCH_gv            = 0x03,  /* D Latch */
    CCL_SEQSEL_RS_gv               = 0x04   /* RS Latch */
} CCL_SEQSEL_values_t;

/* Sequential Selection bit group configurations*/
typedef enum CCL_SEQSEL_enum
{
    CCL_SEQSEL_DISABLE_gc          = (CCL_SEQSEL_DISABLE_gv << CCL_SEQSEL_gp),  /* Sequential logic disabled */
    CCL_SEQSEL_DFF_gc              = (CCL_SEQSEL_DFF_gv << CCL_SEQSEL_gp),  /* D FlipFlop */
    CCL_SEQSEL_JK_gc               = (CCL_SEQSEL_JK_gv << CCL_SEQSEL_gp),  /* JK FlipFlop */
    CCL_SEQSEL_LATCH_gc            = (CCL_SEQSEL_LATCH_gv << CCL_SEQSEL_gp),  /* D Latch */
    CCL_SEQSEL_RS_gc               = (CCL_SEQSEL_RS_gv << CCL_SEQSEL_gp)   /* RS Latch */
} CCL_SEQSEL_t;

/*
--------------------------------------------------------------------------
CLKCTRL - Clock controller
--------------------------------------------------------------------------
*/

/* Clock controller */
typedef struct CLKCTRL_struct
{
    register8_t MCLKCTRLA;  /* MCLK Control A */
    register8_t MCLKCTRLB;  /* MCLK Control B */
    register8_t MCLKCTRLC;  /* MCLK Control C */
    register8_t MCLKINTCTRL;  /* MCLK Interrupt Control */
    register8_t MCLKINTFLAGS;  /* MCLK Interrupt Flags */
    register8_t MCLKSTATUS;  /* MCLK Status */
    register8_t MCLKTIMEBASE;  /* MCLK Timebase */
    register8_t reserved_1[1];
    register8_t MCLKCFD0CTRLA;  /* MCLK Clock Failure Detect 0 Control A */
    register8_t MCLKCFD1CTRLA;  /* MCLK Clock Failure Detect 1 Control A */
    register8_t reserved_2[6];
    _WORDREGISTER(MCLKCFM0VALUE);  /* MCLK Clock Failure Measurement 0 Value */
    _WORDREGISTER(MCLKCFM0WINLT);  /* MCLK Clock Failure Measurement 0 Window Low Threshold */
    _WORDREGISTER(MCLKCFM0WINHT);  /* MCLK Clock Failure Measurement 0 Window High Threshold */
    _WORDREGISTER(MCLKCFM0REFNUM);  /* MCLK Clock Failure Measurement 0 Reference Clock Cycles */
    register8_t MCLKCFM0CTRLA;  /* MCLK Clock Failure Measurement 0 Control A */
    register8_t MCLKCFM0CTRLB;  /* MCLK Clock Failure Measurement 0 Control B */
    register8_t reserved_3[6];
    _WORDREGISTER(MCLKCFM1VALUE);  /* MCLK Clock Failure Measurement 1 Value */
    _WORDREGISTER(MCLKCFM1WINLT);  /* MCLK Clock Failure Measurement 1 Window Low Threshold */
    _WORDREGISTER(MCLKCFM1WINHT);  /* MCLK Clock Failure Measurement 1 Window High Threshold */
    _WORDREGISTER(MCLKCFM1REFNUM);  /* MCLK Clock Failure Measurement 1 Reference Clock Cycles */
    register8_t MCLKCFM1CTRLA;  /* MCLK Clock Failure Measurement 1 Control A */
    register8_t MCLKCFM1CTRLB;  /* MCLK Clock Failure Measurement 1 Control B */
    register8_t reserved_4[22];
    register8_t OSCHFCTRLA;  /* OSCHF Control A */
    register8_t OSCHFTUNE;  /* OSCHF Tune */
    register8_t reserved_5[6];
    register8_t PLLCTRLA;  /* PLL Control A */
    register8_t reserved_6[7];
    register8_t OSC32KCTRLA;  /* OSC32K Control A */
    register8_t reserved_7[3];
    register8_t XOSC32KCTRLA;  /* XOSC32K Control A */
    register8_t reserved_8[3];
    register8_t XOSCHFCTRLA;  /* XTALHF Control A */
    register8_t reserved_9[39];
} CLKCTRL_t;

/* Autotune select bit group values */
typedef enum CLKCTRL_AUTOTUNE_VALUES_enum
{
    CLKCTRL_AUTOTUNE_OFF_gv        = 0x00,  /* Automatic oscillator frequency tune disabled */
    CLKCTRL_AUTOTUNE_ON_gv         = 0x01   /* Automatic oscillator frequency tune enabled */
} CLKCTRL_AUTOTUNE_values_t;

/* Autotune select bit group configurations*/
typedef enum CLKCTRL_AUTOTUNE_enum
{
    CLKCTRL_AUTOTUNE_OFF_gc        = (CLKCTRL_AUTOTUNE_OFF_gv << CLKCTRL_AUTOTUNE_bp),  /* Automatic oscillator frequency tune disabled */
    CLKCTRL_AUTOTUNE_ON_gc         = (CLKCTRL_AUTOTUNE_ON_gv << CLKCTRL_AUTOTUNE_bp)   /* Automatic oscillator frequency tune enabled */
} CLKCTRL_AUTOTUNE_t;

/* Clock Failure Detect Reference select bit group values */
typedef enum CLKCTRL_CFDREF_VALUES_enum
{
    CLKCTRL_CFDREF_OSC32K_gv       = 0x00,  /* OSC32K as reference */
    CLKCTRL_CFDREF_ONEDIV32_gv     = 0x01,  /* (1MHz from OSCHF) / 32 as reference */
    CLKCTRL_CFDREF_XOSC32K_gv      = 0x02   /* XOSC32K as reference */
} CLKCTRL_CFDREF_values_t;

/* Clock Failure Detect Reference select bit group configurations*/
typedef enum CLKCTRL_CFDREF_enum
{
    CLKCTRL_CFDREF_OSC32K_gc       = (CLKCTRL_CFDREF_OSC32K_gv << CLKCTRL_CFDREF_gp),  /* OSC32K as reference */
    CLKCTRL_CFDREF_ONEDIV32_gc     = (CLKCTRL_CFDREF_ONEDIV32_gv << CLKCTRL_CFDREF_gp),  /* (1MHz from OSCHF) / 32 as reference */
    CLKCTRL_CFDREF_XOSC32K_gc      = (CLKCTRL_CFDREF_XOSC32K_gv << CLKCTRL_CFDREF_gp)   /* XOSC32K as reference */
} CLKCTRL_CFDREF_t;

/* Clock Failure Detect Source select bit group values */
typedef enum CLKCTRL_CFDSRC_VALUES_enum
{
    CLKCTRL_CFDSRC_MCLK_gv         = 0x00,  /* Main clock as source */
    CLKCTRL_CFDSRC_OSCHF_gv        = 0x01,  /* OSCHF as source */
    CLKCTRL_CFDSRC_OSC32K_gv       = 0x02,  /* OSC32K as source */
    CLKCTRL_CFDSRC_XOSCHF_gv       = 0x03,  /* XOSCHF as source */
    CLKCTRL_CFDSRC_XOSC32K_gv      = 0x04,  /* XOSC32K as source */
    CLKCTRL_CFDSRC_EVSYS_gv        = 0x07   /* Event Channel input */
} CLKCTRL_CFDSRC_values_t;

/* Clock Failure Detect Source select bit group configurations*/
typedef enum CLKCTRL_CFDSRC_enum
{
    CLKCTRL_CFDSRC_MCLK_gc         = (CLKCTRL_CFDSRC_MCLK_gv << CLKCTRL_CFDSRC_gp),  /* Main clock as source */
    CLKCTRL_CFDSRC_OSCHF_gc        = (CLKCTRL_CFDSRC_OSCHF_gv << CLKCTRL_CFDSRC_gp),  /* OSCHF as source */
    CLKCTRL_CFDSRC_OSC32K_gc       = (CLKCTRL_CFDSRC_OSC32K_gv << CLKCTRL_CFDSRC_gp),  /* OSC32K as source */
    CLKCTRL_CFDSRC_XOSCHF_gc       = (CLKCTRL_CFDSRC_XOSCHF_gv << CLKCTRL_CFDSRC_gp),  /* XOSCHF as source */
    CLKCTRL_CFDSRC_XOSC32K_gc      = (CLKCTRL_CFDSRC_XOSC32K_gv << CLKCTRL_CFDSRC_gp),  /* XOSC32K as source */
    CLKCTRL_CFDSRC_EVSYS_gc        = (CLKCTRL_CFDSRC_EVSYS_gv << CLKCTRL_CFDSRC_gp)   /* Event Channel input */
} CLKCTRL_CFDSRC_t;

/* CFM Reference Source select bit group values */
typedef enum CLKCTRL_CFMREF_VALUES_enum
{
    CLKCTRL_CFMREF_OSCHF_gv        = 0x00,  /* High-frequency oscillator as reference */
    CLKCTRL_CFMREF_XOSCHF_gv       = 0x01,  /* External high-frequency oscillator as reference */
    CLKCTRL_CFMREF_XOSC32K_gv      = 0x02,  /* External 32K oscillator as reference */
    CLKCTRL_CFMREF_OSC32K_gv       = 0x03   /* 32K oscillator as reference */
} CLKCTRL_CFMREF_values_t;

/* CFM Reference Source select bit group configurations*/
typedef enum CLKCTRL_CFMREF_enum
{
    CLKCTRL_CFMREF_OSCHF_gc        = (CLKCTRL_CFMREF_OSCHF_gv << CLKCTRL_CFMREF_gp),  /* High-frequency oscillator as reference */
    CLKCTRL_CFMREF_XOSCHF_gc       = (CLKCTRL_CFMREF_XOSCHF_gv << CLKCTRL_CFMREF_gp),  /* External high-frequency oscillator as reference */
    CLKCTRL_CFMREF_XOSC32K_gc      = (CLKCTRL_CFMREF_XOSC32K_gv << CLKCTRL_CFMREF_gp),  /* External 32K oscillator as reference */
    CLKCTRL_CFMREF_OSC32K_gc       = (CLKCTRL_CFMREF_OSC32K_gv << CLKCTRL_CFMREF_gp)   /* 32K oscillator as reference */
} CLKCTRL_CFMREF_t;

/* CFM Clock Reference select bit group values */
typedef enum CLKCTRL_CFMSRC_VALUES_enum
{
    CLKCTRL_CFMSRC_CLK_MAIN_gv     = 0x00,  /* Measure Main clock */
    CLKCTRL_CFMSRC_OSCHF_gv        = 0x01,  /* Measure high frequency oscillator */
    CLKCTRL_CFMSRC_OSC32K_gv       = 0x02,  /* Measure OSC32K */
    CLKCTRL_CFMSRC_XOSCHF_gv       = 0x03,  /* Measure high frequency external oscillator */
    CLKCTRL_CFMSRC_XOSC32K_gv      = 0x04,  /* Measure 32K external oscillator */
    CLKCTRL_CFMSRC_EVSYS_gv        = 0x05   /* Measure event system channel */
} CLKCTRL_CFMSRC_values_t;

/* CFM Clock Reference select bit group configurations*/
typedef enum CLKCTRL_CFMSRC_enum
{
    CLKCTRL_CFMSRC_CLK_MAIN_gc     = (CLKCTRL_CFMSRC_CLK_MAIN_gv << CLKCTRL_CFMSRC_gp),  /* Measure Main clock */
    CLKCTRL_CFMSRC_OSCHF_gc        = (CLKCTRL_CFMSRC_OSCHF_gv << CLKCTRL_CFMSRC_gp),  /* Measure high frequency oscillator */
    CLKCTRL_CFMSRC_OSC32K_gc       = (CLKCTRL_CFMSRC_OSC32K_gv << CLKCTRL_CFMSRC_gp),  /* Measure OSC32K */
    CLKCTRL_CFMSRC_XOSCHF_gc       = (CLKCTRL_CFMSRC_XOSCHF_gv << CLKCTRL_CFMSRC_gp),  /* Measure high frequency external oscillator */
    CLKCTRL_CFMSRC_XOSC32K_gc      = (CLKCTRL_CFMSRC_XOSC32K_gv << CLKCTRL_CFMSRC_gp),  /* Measure 32K external oscillator */
    CLKCTRL_CFMSRC_EVSYS_gc        = (CLKCTRL_CFMSRC_EVSYS_gv << CLKCTRL_CFMSRC_gp)   /* Measure event system channel */
} CLKCTRL_CFMSRC_t;

/* Clock Out Divide select bit group values */
typedef enum CLKCTRL_CLKOUTDIV_VALUES_enum
{
    CLKCTRL_CLKOUTDIV_DIV1_gv      = 0x00,  /* Divide by one */
    CLKCTRL_CLKOUTDIV_DIV32_gv     = 0x01   /* Divide by 32 */
} CLKCTRL_CLKOUTDIV_values_t;

/* Clock Out Divide select bit group configurations*/
typedef enum CLKCTRL_CLKOUTDIV_enum
{
    CLKCTRL_CLKOUTDIV_DIV1_gc      = (CLKCTRL_CLKOUTDIV_DIV1_gv << CLKCTRL_CLKOUTDIV_bp),  /* Divide by one */
    CLKCTRL_CLKOUTDIV_DIV32_gc     = (CLKCTRL_CLKOUTDIV_DIV32_gv << CLKCTRL_CLKOUTDIV_bp)   /* Divide by 32 */
} CLKCTRL_CLKOUTDIV_t;

/* Clock Select bit group values */
typedef enum CLKCTRL_CLKSEL_VALUES_enum
{
    CLKCTRL_CLKSEL_OSCHF_gv        = 0x00,  /* Internal high-frequency oscillator */
    CLKCTRL_CLKSEL_OSC32K_gv       = 0x01,  /* Internal 32.768 kHz oscillator */
    CLKCTRL_CLKSEL_XOSC32K_gv      = 0x02,  /* 32.768 kHz crystal oscillator */
    CLKCTRL_CLKSEL_EXTCLK_gv       = 0x03   /* External clock */
} CLKCTRL_CLKSEL_values_t;

/* Clock Select bit group configurations*/
typedef enum CLKCTRL_CLKSEL_enum
{
    CLKCTRL_CLKSEL_OSCHF_gc        = (CLKCTRL_CLKSEL_OSCHF_gv << CLKCTRL_CLKSEL_gp),  /* Internal high-frequency oscillator */
    CLKCTRL_CLKSEL_OSC32K_gc       = (CLKCTRL_CLKSEL_OSC32K_gv << CLKCTRL_CLKSEL_gp),  /* Internal 32.768 kHz oscillator */
    CLKCTRL_CLKSEL_XOSC32K_gc      = (CLKCTRL_CLKSEL_XOSC32K_gv << CLKCTRL_CLKSEL_gp),  /* 32.768 kHz crystal oscillator */
    CLKCTRL_CLKSEL_EXTCLK_gc       = (CLKCTRL_CLKSEL_EXTCLK_gv << CLKCTRL_CLKSEL_gp)   /* External clock */
} CLKCTRL_CLKSEL_t;

/* Crystal Oscillator Startup Time select bit group values */
typedef enum CLKCTRL_CSUT_VALUES_enum
{
    CLKCTRL_CSUT_1K_gv             = 0x00,  /* 1k cycles */
    CLKCTRL_CSUT_16K_gv            = 0x01,  /* 16k cycles */
    CLKCTRL_CSUT_32K_gv            = 0x02,  /* 32k cycles */
    CLKCTRL_CSUT_64K_gv            = 0x03   /* 64k cycles */
} CLKCTRL_CSUT_values_t;

/* Crystal Oscillator Startup Time select bit group configurations*/
typedef enum CLKCTRL_CSUT_enum
{
    CLKCTRL_CSUT_1K_gc             = (CLKCTRL_CSUT_1K_gv << CLKCTRL_CSUT_gp),  /* 1k cycles */
    CLKCTRL_CSUT_16K_gc            = (CLKCTRL_CSUT_16K_gv << CLKCTRL_CSUT_gp),  /* 16k cycles */
    CLKCTRL_CSUT_32K_gc            = (CLKCTRL_CSUT_32K_gv << CLKCTRL_CSUT_gp),  /* 32k cycles */
    CLKCTRL_CSUT_64K_gc            = (CLKCTRL_CSUT_64K_gv << CLKCTRL_CSUT_gp)   /* 64k cycles */
} CLKCTRL_CSUT_t;

/* Start-up Time select bit group values */
typedef enum CLKCTRL_CSUTHF_VALUES_enum
{
    CLKCTRL_CSUTHF_256_gv          = 0x00,  /* 256 XOSCHF cycles */
    CLKCTRL_CSUTHF_1K_gv           = 0x01,  /* 1K XOSCHF cycles */
    CLKCTRL_CSUTHF_4K_gv           = 0x02   /* 4K XOSCHF cycles */
} CLKCTRL_CSUTHF_values_t;

/* Start-up Time select bit group configurations*/
typedef enum CLKCTRL_CSUTHF_enum
{
    CLKCTRL_CSUTHF_256_gc          = (CLKCTRL_CSUTHF_256_gv << CLKCTRL_CSUTHF_gp),  /* 256 XOSCHF cycles */
    CLKCTRL_CSUTHF_1K_gc           = (CLKCTRL_CSUTHF_1K_gv << CLKCTRL_CSUTHF_gp),  /* 1K XOSCHF cycles */
    CLKCTRL_CSUTHF_4K_gc           = (CLKCTRL_CSUTHF_4K_gv << CLKCTRL_CSUTHF_gp)   /* 4K XOSCHF cycles */
} CLKCTRL_CSUTHF_t;

/* Frequency Range select bit group values */
typedef enum CLKCTRL_FRQRANGE_VALUES_enum
{
    CLKCTRL_FRQRANGE_8M_gv         = 0x00,  /* Max 8 MHz XTAL Frequency */
    CLKCTRL_FRQRANGE_16M_gv        = 0x01,  /* Max 16 MHz XTAL Frequency */
    CLKCTRL_FRQRANGE_24M_gv        = 0x02,  /* Max 24 MHz XTAL Frequency */
    CLKCTRL_FRQRANGE_32M_gv        = 0x03   /* Max 32 MHz XTAL Frequency */
} CLKCTRL_FRQRANGE_values_t;

/* Frequency Range select bit group configurations*/
typedef enum CLKCTRL_FRQRANGE_enum
{
    CLKCTRL_FRQRANGE_8M_gc         = (CLKCTRL_FRQRANGE_8M_gv << CLKCTRL_FRQRANGE_gp),  /* Max 8 MHz XTAL Frequency */
    CLKCTRL_FRQRANGE_16M_gc        = (CLKCTRL_FRQRANGE_16M_gv << CLKCTRL_FRQRANGE_gp),  /* Max 16 MHz XTAL Frequency */
    CLKCTRL_FRQRANGE_24M_gc        = (CLKCTRL_FRQRANGE_24M_gv << CLKCTRL_FRQRANGE_gp),  /* Max 24 MHz XTAL Frequency */
    CLKCTRL_FRQRANGE_32M_gc        = (CLKCTRL_FRQRANGE_32M_gv << CLKCTRL_FRQRANGE_gp)   /* Max 32 MHz XTAL Frequency */
} CLKCTRL_FRQRANGE_t;

/* Frequency select bit group values */
typedef enum CLKCTRL_FRQSEL_VALUES_enum
{
    CLKCTRL_FRQSEL_1M_gv           = 0x00,  /* 1 MHz system clock */
    CLKCTRL_FRQSEL_2M_gv           = 0x01,  /* 2 MHz system clock */
    CLKCTRL_FRQSEL_3M_gv           = 0x02,  /* 3 MHz system clock */
    CLKCTRL_FRQSEL_4M_gv           = 0x03,  /* 4 MHz system clock (default) */
    CLKCTRL_FRQSEL_8M_gv           = 0x05,  /* 8 MHz system clock */
    CLKCTRL_FRQSEL_12M_gv          = 0x06,  /* 12 MHz system clock */
    CLKCTRL_FRQSEL_16M_gv          = 0x07,  /* 16 MHz system clock */
    CLKCTRL_FRQSEL_20M_gv          = 0x08   /* 20 MHz system clock */
} CLKCTRL_FRQSEL_values_t;

/* Frequency select bit group configurations*/
typedef enum CLKCTRL_FRQSEL_enum
{
    CLKCTRL_FRQSEL_1M_gc           = (CLKCTRL_FRQSEL_1M_gv << CLKCTRL_FRQSEL_gp),  /* 1 MHz system clock */
    CLKCTRL_FRQSEL_2M_gc           = (CLKCTRL_FRQSEL_2M_gv << CLKCTRL_FRQSEL_gp),  /* 2 MHz system clock */
    CLKCTRL_FRQSEL_3M_gc           = (CLKCTRL_FRQSEL_3M_gv << CLKCTRL_FRQSEL_gp),  /* 3 MHz system clock */
    CLKCTRL_FRQSEL_4M_gc           = (CLKCTRL_FRQSEL_4M_gv << CLKCTRL_FRQSEL_gp),  /* 4 MHz system clock (default) */
    CLKCTRL_FRQSEL_8M_gc           = (CLKCTRL_FRQSEL_8M_gv << CLKCTRL_FRQSEL_gp),  /* 8 MHz system clock */
    CLKCTRL_FRQSEL_12M_gc          = (CLKCTRL_FRQSEL_12M_gv << CLKCTRL_FRQSEL_gp),  /* 12 MHz system clock */
    CLKCTRL_FRQSEL_16M_gc          = (CLKCTRL_FRQSEL_16M_gv << CLKCTRL_FRQSEL_gp),  /* 16 MHz system clock */
    CLKCTRL_FRQSEL_20M_gc          = (CLKCTRL_FRQSEL_20M_gv << CLKCTRL_FRQSEL_gp)   /* 20 MHz system clock */
} CLKCTRL_FRQSEL_t;

/* Low-power Mode select bit group values */
typedef enum CLKCTRL_LPMODE_VALUES_enum
{
    CLKCTRL_LPMODE_OFF_gv          = 0x00,  /* Low-power mode disabled */
    CLKCTRL_LPMODE_ON_gv           = 0x01   /* Low-power mode enabled */
} CLKCTRL_LPMODE_values_t;

/* Low-power Mode select bit group configurations*/
typedef enum CLKCTRL_LPMODE_enum
{
    CLKCTRL_LPMODE_OFF_gc          = (CLKCTRL_LPMODE_OFF_gv << CLKCTRL_LPMODE_bp),  /* Low-power mode disabled */
    CLKCTRL_LPMODE_ON_gc           = (CLKCTRL_LPMODE_ON_gv << CLKCTRL_LPMODE_bp)   /* Low-power mode enabled */
} CLKCTRL_LPMODE_t;

/* Multiplication Factor select bit group values */
typedef enum CLKCTRL_MULFAC_VALUES_enum
{
    CLKCTRL_MULFAC_DISABLE_gv      = 0x00,  /* PLL is disabled */
    CLKCTRL_MULFAC_X2_gv           = 0x01,  /* 2 x multiplication factor */
    CLKCTRL_MULFAC_X3_gv           = 0x02   /* 3 x multiplication factor */
} CLKCTRL_MULFAC_values_t;

/* Multiplication Factor select bit group configurations*/
typedef enum CLKCTRL_MULFAC_enum
{
    CLKCTRL_MULFAC_DISABLE_gc      = (CLKCTRL_MULFAC_DISABLE_gv << CLKCTRL_MULFAC_gp),  /* PLL is disabled */
    CLKCTRL_MULFAC_X2_gc           = (CLKCTRL_MULFAC_X2_gv << CLKCTRL_MULFAC_gp),  /* 2 x multiplication factor */
    CLKCTRL_MULFAC_X3_gc           = (CLKCTRL_MULFAC_X3_gv << CLKCTRL_MULFAC_gp)   /* 3 x multiplication factor */
} CLKCTRL_MULFAC_t;

/* Prescaler division select bit group values */
typedef enum CLKCTRL_PDIV_VALUES_enum
{
    CLKCTRL_PDIV_DIV2_gv           = 0x00,  /* Divide by 2 */
    CLKCTRL_PDIV_DIV4_gv           = 0x01,  /* Divide by 4 */
    CLKCTRL_PDIV_DIV8_gv           = 0x02,  /* Divide by 8 */
    CLKCTRL_PDIV_DIV16_gv          = 0x03,  /* Divide by 16 */
    CLKCTRL_PDIV_DIV32_gv          = 0x04,  /* Divide by 32 */
    CLKCTRL_PDIV_DIV64_gv          = 0x05,  /* Divide by 64 */
    CLKCTRL_PDIV_DIV6_gv           = 0x08,  /* Divide by 6 */
    CLKCTRL_PDIV_DIV10_gv          = 0x09,  /* Divide by 10 */
    CLKCTRL_PDIV_DIV12_gv          = 0x0A,  /* Divide by 12 */
    CLKCTRL_PDIV_DIV24_gv          = 0x0B,  /* Divide by 24 */
    CLKCTRL_PDIV_DIV48_gv          = 0x0C   /* Divide by 48 */
} CLKCTRL_PDIV_values_t;

/* Prescaler division select bit group configurations*/
typedef enum CLKCTRL_PDIV_enum
{
    CLKCTRL_PDIV_DIV2_gc           = (CLKCTRL_PDIV_DIV2_gv << CLKCTRL_PDIV_gp),  /* Divide by 2 */
    CLKCTRL_PDIV_DIV4_gc           = (CLKCTRL_PDIV_DIV4_gv << CLKCTRL_PDIV_gp),  /* Divide by 4 */
    CLKCTRL_PDIV_DIV8_gc           = (CLKCTRL_PDIV_DIV8_gv << CLKCTRL_PDIV_gp),  /* Divide by 8 */
    CLKCTRL_PDIV_DIV16_gc          = (CLKCTRL_PDIV_DIV16_gv << CLKCTRL_PDIV_gp),  /* Divide by 16 */
    CLKCTRL_PDIV_DIV32_gc          = (CLKCTRL_PDIV_DIV32_gv << CLKCTRL_PDIV_gp),  /* Divide by 32 */
    CLKCTRL_PDIV_DIV64_gc          = (CLKCTRL_PDIV_DIV64_gv << CLKCTRL_PDIV_gp),  /* Divide by 64 */
    CLKCTRL_PDIV_DIV6_gc           = (CLKCTRL_PDIV_DIV6_gv << CLKCTRL_PDIV_gp),  /* Divide by 6 */
    CLKCTRL_PDIV_DIV10_gc          = (CLKCTRL_PDIV_DIV10_gv << CLKCTRL_PDIV_gp),  /* Divide by 10 */
    CLKCTRL_PDIV_DIV12_gc          = (CLKCTRL_PDIV_DIV12_gv << CLKCTRL_PDIV_gp),  /* Divide by 12 */
    CLKCTRL_PDIV_DIV24_gc          = (CLKCTRL_PDIV_DIV24_gv << CLKCTRL_PDIV_gp),  /* Divide by 24 */
    CLKCTRL_PDIV_DIV48_gc          = (CLKCTRL_PDIV_DIV48_gv << CLKCTRL_PDIV_gp)   /* Divide by 48 */
} CLKCTRL_PDIV_t;

/* Crystal Selection bit group values */
typedef enum CLKCTRL_SEL_VALUES_enum
{
    CLKCTRL_SEL_XTAL_gv            = 0x00,  /* External crystal */
    CLKCTRL_SEL_EXTCLK_gv          = 0x01   /* External clock on XTAL32K1 pin */
} CLKCTRL_SEL_values_t;

/* Crystal Selection bit group configurations*/
typedef enum CLKCTRL_SEL_enum
{
    CLKCTRL_SEL_XTAL_gc            = (CLKCTRL_SEL_XTAL_gv << CLKCTRL_SEL_bp),  /* External crystal */
    CLKCTRL_SEL_EXTCLK_gc          = (CLKCTRL_SEL_EXTCLK_gv << CLKCTRL_SEL_bp)   /* External clock on XTAL32K1 pin */
} CLKCTRL_SEL_t;

/* External Source Select bit group values */
typedef enum CLKCTRL_SELHF_VALUES_enum
{
    CLKCTRL_SELHF_XTAL_gv          = 0x00,  /* External Crystal */
    CLKCTRL_SELHF_EXTCLK_gv        = 0x01   /* External clock on XTALHF1 pin */
} CLKCTRL_SELHF_values_t;

/* External Source Select bit group configurations*/
typedef enum CLKCTRL_SELHF_enum
{
    CLKCTRL_SELHF_XTAL_gc          = (CLKCTRL_SELHF_XTAL_gv << CLKCTRL_SELHF_bp),  /* External Crystal */
    CLKCTRL_SELHF_EXTCLK_gc        = (CLKCTRL_SELHF_EXTCLK_gv << CLKCTRL_SELHF_bp)   /* External clock on XTALHF1 pin */
} CLKCTRL_SELHF_t;

/* Source select bit group values */
typedef enum CLKCTRL_SOURCE_VALUES_enum
{
    CLKCTRL_SOURCE_OSCHF_gv        = 0x00,  /* High frequency internal oscillator as PLL source */
    CLKCTRL_SOURCE_EXTCLK_gv       = 0x01   /* High frequency external clock or external high frequency oscillator as PLL source */
} CLKCTRL_SOURCE_values_t;

/* Source select bit group configurations*/
typedef enum CLKCTRL_SOURCE_enum
{
    CLKCTRL_SOURCE_OSCHF_gc        = (CLKCTRL_SOURCE_OSCHF_gv << CLKCTRL_SOURCE_bp),  /* High frequency internal oscillator as PLL source */
    CLKCTRL_SOURCE_EXTCLK_gc       = (CLKCTRL_SOURCE_EXTCLK_gv << CLKCTRL_SOURCE_bp)   /* High frequency external clock or external high frequency oscillator as PLL source */
} CLKCTRL_SOURCE_t;

/* Measurement Type select bit group values */
typedef enum CLKCTRL_TYPE_VALUES_enum
{
    CLKCTRL_TYPE_ONESHOT_gv        = 0x00,  /* One-shot measurement */
    CLKCTRL_TYPE_CONTINUOUS_gv     = 0x01   /* Continuous measurement */
} CLKCTRL_TYPE_values_t;

/* Measurement Type select bit group configurations*/
typedef enum CLKCTRL_TYPE_enum
{
    CLKCTRL_TYPE_ONESHOT_gc        = (CLKCTRL_TYPE_ONESHOT_gv << CLKCTRL_TYPE_bp),  /* One-shot measurement */
    CLKCTRL_TYPE_CONTINUOUS_gc     = (CLKCTRL_TYPE_CONTINUOUS_gv << CLKCTRL_TYPE_bp)   /* Continuous measurement */
} CLKCTRL_TYPE_t;

/*
--------------------------------------------------------------------------
CPU - CPU
--------------------------------------------------------------------------
*/

#define CORE_VERSION  V4S

/* CCP signature select bit group values */
typedef enum CCP_VALUES_enum
{
    CCP_SPM_gv                     = 0x9D,  /* SPM Instruction Protection */
    CCP_IOREG_gv                   = 0xD8   /* IO Register Protection */
} CCP_values_t;

/* CCP signature select bit group configurations*/
typedef enum CCP_enum
{
    CCP_SPM_gc                     = (CCP_SPM_gv << CPU_CCP_gp),  /* SPM Instruction Protection */
    CCP_IOREG_gc                   = (CCP_IOREG_gv << CPU_CCP_gp)   /* IO Register Protection */
} CCP_t;

/*
--------------------------------------------------------------------------
CPUINT - Interrupt Controller
--------------------------------------------------------------------------
*/

/* Interrupt Controller */
typedef struct CPUINT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t LVL0PRI;  /* Interrupt Level 0 Priority */
    register8_t LVL1VEC;  /* Interrupt Level 1 Priority Vector */
    register8_t reserved_1[12];
} CPUINT_t;


/*
--------------------------------------------------------------------------
CRCSCAN - CRCSCAN
--------------------------------------------------------------------------
*/

/* CRCSCAN */
typedef struct CRCSCAN_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUSA;  /* Status A */
    register8_t SCANADR;  /* Scan Address */
    register8_t DATA;  /* Input Data */
    register8_t reserved_1[1];
    _DWORDREGISTER(CRC);  /* CRC Result */
    register8_t reserved_2[4];
} CRCSCAN_t;

/* CRC Mode Select bit group values */
typedef enum CRCSCAN_CRCSEL_VALUES_enum
{
    CRCSCAN_CRCSEL_CRC16_gv        = 0x00,  /* The CRC is performed using CRC16 */
    CRCSCAN_CRCSEL_CRC32_gv        = 0x01   /* The CRC is performed using CRC32 */
} CRCSCAN_CRCSEL_values_t;

/* CRC Mode Select bit group configurations*/
typedef enum CRCSCAN_CRCSEL_enum
{
    CRCSCAN_CRCSEL_CRC16_gc        = (CRCSCAN_CRCSEL_CRC16_gv << CRCSCAN_CRCSEL_bp),  /* The CRC is performed using CRC16 */
    CRCSCAN_CRCSEL_CRC32_gc        = (CRCSCAN_CRCSEL_CRC32_gv << CRCSCAN_CRCSEL_bp)   /* The CRC is performed using CRC32 */
} CRCSCAN_CRCSEL_t;

/* Enable Periodic Timer select bit group values */
typedef enum CRCSCAN_PEREN_VALUES_enum
{
    CRCSCAN_PEREN_DISABLE_gv       = 0x00,  /* The periodic timer is disabled */
    CRCSCAN_PEREN_ENABLE_gv        = 0x01   /* The periodic timer is enabled */
} CRCSCAN_PEREN_values_t;

/* Enable Periodic Timer select bit group configurations*/
typedef enum CRCSCAN_PEREN_enum
{
    CRCSCAN_PEREN_DISABLE_gc       = (CRCSCAN_PEREN_DISABLE_gv << CRCSCAN_PEREN_bp),  /* The periodic timer is disabled */
    CRCSCAN_PEREN_ENABLE_gc        = (CRCSCAN_PEREN_ENABLE_gv << CRCSCAN_PEREN_bp)   /* The periodic timer is enabled */
} CRCSCAN_PEREN_t;

/* CRC Source select bit group values */
typedef enum CRCSCAN_SRC_VALUES_enum
{
    CRCSCAN_SRC_BOOT_gv            = 0x00,  /* The CRC is performed on the boot section of Flash */
    CRCSCAN_SRC_CODE_gv            = 0x01,  /* The CRC is performed on the application code section of Flash */
    CRCSCAN_SRC_DATA_gv            = 0x02,  /* The CRC is performed on the application data section of Flash */
    CRCSCAN_SRC_MANUAL_gv          = 0x03   /* Manual mode, CRC is performed on data written to DATA */
} CRCSCAN_SRC_values_t;

/* CRC Source select bit group configurations*/
typedef enum CRCSCAN_SRC_enum
{
    CRCSCAN_SRC_BOOT_gc            = (CRCSCAN_SRC_BOOT_gv << CRCSCAN_SRC_gp),  /* The CRC is performed on the boot section of Flash */
    CRCSCAN_SRC_CODE_gc            = (CRCSCAN_SRC_CODE_gv << CRCSCAN_SRC_gp),  /* The CRC is performed on the application code section of Flash */
    CRCSCAN_SRC_DATA_gc            = (CRCSCAN_SRC_DATA_gv << CRCSCAN_SRC_gp),  /* The CRC is performed on the application data section of Flash */
    CRCSCAN_SRC_MANUAL_gc          = (CRCSCAN_SRC_MANUAL_gv << CRCSCAN_SRC_gp)   /* Manual mode, CRC is performed on data written to DATA */
} CRCSCAN_SRC_t;

/*
--------------------------------------------------------------------------
DAC - Digital to Analog Converter
--------------------------------------------------------------------------
*/

/* Digital to Analog Converter */
typedef struct DAC_struct
{
    register8_t CTRLA;  /* Control Register A */
    register8_t reserved_1[1];
    _WORDREGISTER(DATA);  /* DATA Register */
} DAC_t;


/*
--------------------------------------------------------------------------
ERRCTRL - Error Controller
--------------------------------------------------------------------------
*/

/* Error Controller */
typedef struct ERRCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUSA;  /* Status A */
    register8_t TIMEOUT;  /* Timeout Value */
    register8_t TIMECNT;  /* Timeout Counter */
    register8_t CAUSE;  /* Reset Cause */
    register8_t reserved_1[11];
    register8_t ESCVREGFAIL;  /* Error Source Control VREGFAIL */
    register8_t ESCBUSERR;  /* Error Source Control BUSERR */
    register8_t ESCRAM2;  /* Error Source Control RAM2 */
    register8_t ESCFLASH2;  /* Error Source Control FLASH2 */
    register8_t ESCOPC;  /* Error Source Control OPC */
    register8_t ESCSPLIM;  /* Error Source Control SPLIM */
    register8_t ESCRAM1;  /* Error Source Control RAM1 */
    register8_t ESCFLASH1;  /* Error Source Control FLASH1 */
    register8_t ESCVREGWARN;  /* Error Source Control VREGWARN */
    register8_t ESCCFD0;  /* Error Source Control CFD0 */
    register8_t ESCCFD1;  /* Error Source Control CFD1 */
    register8_t ESCCFM0;  /* Error Source Control CFM0 */
    register8_t ESCCFM1;  /* Error Source Control CFM1 */
    register8_t ESCSWDT;  /* Error Source Control SWDT */
    register8_t ESCEEPROM;  /* Error Source Control EEPROM */
    register8_t ESCEVSYS0;  /* Error Source Control EVSYS0 */
    register8_t ESCEVSYS1;  /* Error Source Control EVSYS1 */
    register8_t reserved_2[15];
    _DWORDREGISTER(ESF);  /* Error Status Flags */
    _DWORDREGISTER(ESFTEST);  /* Error Status Flag Test Injection */
    register8_t reserved_3[8];
} ERRCTRL_t;

/* Reset Cause select bit group values */
typedef enum ERRCTRL_CAUSE_VALUES_enum
{
    ERRCTRL_CAUSE_VREGFAIL_gv      = 0x00,  /* VREG Low/High voltage detect */
    ERRCTRL_CAUSE_BUSERR_gv        = 0x01,  /* Bus Error on data bus or parity error on data */
    ERRCTRL_CAUSE_RAM2_gv          = 0x02,  /* Data (RAM) ECC double bit or comparator error */
    ERRCTRL_CAUSE_FLASH2_gv        = 0x03,  /* Flash ECC double bit or comparator error */
    ERRCTRL_CAUSE_OPC_gv           = 0x04,  /* Illegal opcode instruction or parity error on fetched instruction */
    ERRCTRL_CAUSE_SPLIM_gv         = 0x05,  /* Stack Pointer Limit */
    ERRCTRL_CAUSE_RAM1_gv          = 0x06,  /* Data (RAM) ECC single bit error */
    ERRCTRL_CAUSE_FLASH1_gv        = 0x07,  /* Flash ECC single bit error */
    ERRCTRL_CAUSE_VREGWARN_gv      = 0x08,  /* VREG diagnostic enter/exit or other SLPCTRL error */
    ERRCTRL_CAUSE_CFD0_gv          = 0x09,  /* CFD 0 */
    ERRCTRL_CAUSE_CFD1_gv          = 0x0A,  /* CFD 1 */
    ERRCTRL_CAUSE_CFM0_gv          = 0x0B,  /* CFM Frequency Error 0 */
    ERRCTRL_CAUSE_CFM1_gv          = 0x0C,  /* CFM Frequency Error 1 */
    ERRCTRL_CAUSE_SWDT_gv          = 0x0D,  /* SWDT Error */
    ERRCTRL_CAUSE_EEPROM_gv        = 0x0E,  /* EEPROM ECC error */
    ERRCTRL_CAUSE_EVSYS0_gv        = 0x0F,  /* Event system input 0 */
    ERRCTRL_CAUSE_EVSYS1_gv        = 0x10   /* Event system input 1 */
} ERRCTRL_CAUSE_values_t;

/* Reset Cause select bit group configurations*/
typedef enum ERRCTRL_CAUSE_enum
{
    ERRCTRL_CAUSE_VREGFAIL_gc      = (ERRCTRL_CAUSE_VREGFAIL_gv << ERRCTRL_CAUSE_gp),  /* VREG Low/High voltage detect */
    ERRCTRL_CAUSE_BUSERR_gc        = (ERRCTRL_CAUSE_BUSERR_gv << ERRCTRL_CAUSE_gp),  /* Bus Error on data bus or parity error on data */
    ERRCTRL_CAUSE_RAM2_gc          = (ERRCTRL_CAUSE_RAM2_gv << ERRCTRL_CAUSE_gp),  /* Data (RAM) ECC double bit or comparator error */
    ERRCTRL_CAUSE_FLASH2_gc        = (ERRCTRL_CAUSE_FLASH2_gv << ERRCTRL_CAUSE_gp),  /* Flash ECC double bit or comparator error */
    ERRCTRL_CAUSE_OPC_gc           = (ERRCTRL_CAUSE_OPC_gv << ERRCTRL_CAUSE_gp),  /* Illegal opcode instruction or parity error on fetched instruction */
    ERRCTRL_CAUSE_SPLIM_gc         = (ERRCTRL_CAUSE_SPLIM_gv << ERRCTRL_CAUSE_gp),  /* Stack Pointer Limit */
    ERRCTRL_CAUSE_RAM1_gc          = (ERRCTRL_CAUSE_RAM1_gv << ERRCTRL_CAUSE_gp),  /* Data (RAM) ECC single bit error */
    ERRCTRL_CAUSE_FLASH1_gc        = (ERRCTRL_CAUSE_FLASH1_gv << ERRCTRL_CAUSE_gp),  /* Flash ECC single bit error */
    ERRCTRL_CAUSE_VREGWARN_gc      = (ERRCTRL_CAUSE_VREGWARN_gv << ERRCTRL_CAUSE_gp),  /* VREG diagnostic enter/exit or other SLPCTRL error */
    ERRCTRL_CAUSE_CFD0_gc          = (ERRCTRL_CAUSE_CFD0_gv << ERRCTRL_CAUSE_gp),  /* CFD 0 */
    ERRCTRL_CAUSE_CFD1_gc          = (ERRCTRL_CAUSE_CFD1_gv << ERRCTRL_CAUSE_gp),  /* CFD 1 */
    ERRCTRL_CAUSE_CFM0_gc          = (ERRCTRL_CAUSE_CFM0_gv << ERRCTRL_CAUSE_gp),  /* CFM Frequency Error 0 */
    ERRCTRL_CAUSE_CFM1_gc          = (ERRCTRL_CAUSE_CFM1_gv << ERRCTRL_CAUSE_gp),  /* CFM Frequency Error 1 */
    ERRCTRL_CAUSE_SWDT_gc          = (ERRCTRL_CAUSE_SWDT_gv << ERRCTRL_CAUSE_gp),  /* SWDT Error */
    ERRCTRL_CAUSE_EEPROM_gc        = (ERRCTRL_CAUSE_EEPROM_gv << ERRCTRL_CAUSE_gp),  /* EEPROM ECC error */
    ERRCTRL_CAUSE_EVSYS0_gc        = (ERRCTRL_CAUSE_EVSYS0_gv << ERRCTRL_CAUSE_gp),  /* Event system input 0 */
    ERRCTRL_CAUSE_EVSYS1_gc        = (ERRCTRL_CAUSE_EVSYS1_gv << ERRCTRL_CAUSE_gp)   /* Event system input 1 */
} ERRCTRL_CAUSE_t;

/* Critical Error Detected select bit group values */
typedef enum ERRCTRL_CRITICAL_VALUES_enum
{
    ERRCTRL_CRITICAL_NOERROR_gv    = 0x00,  /* There are no Critical errors in the system */
    ERRCTRL_CRITICAL_ERROR_gv      = 0x01   /* There are one or more Critical errors in the system */
} ERRCTRL_CRITICAL_values_t;

/* Critical Error Detected select bit group configurations*/
typedef enum ERRCTRL_CRITICAL_enum
{
    ERRCTRL_CRITICAL_NOERROR_gc    = (ERRCTRL_CRITICAL_NOERROR_gv << ERRCTRL_CRITICAL_bp),  /* There are no Critical errors in the system */
    ERRCTRL_CRITICAL_ERROR_gc      = (ERRCTRL_CRITICAL_ERROR_gv << ERRCTRL_CRITICAL_bp)   /* There are one or more Critical errors in the system */
} ERRCTRL_CRITICAL_t;

/* Error Severity Level select bit group values */
typedef enum ERRCTRL_ERRLVL_VALUES_enum
{
    ERRCTRL_ERRLVL_CRITICAL_gv     = 0x00,  /* Critical error */
    ERRCTRL_ERRLVL_NONCRITICAL_gv  = 0x02,  /* Noncritical error (reset value) */
    ERRCTRL_ERRLVL_NOTIFICATION_gv = 0x03   /* Notification error */
} ERRCTRL_ERRLVL_values_t;

/* Error Severity Level select bit group configurations*/
typedef enum ERRCTRL_ERRLVL_enum
{
    ERRCTRL_ERRLVL_CRITICAL_gc     = (ERRCTRL_ERRLVL_CRITICAL_gv << ERRCTRL_ERRLVL_gp),  /* Critical error */
    ERRCTRL_ERRLVL_NONCRITICAL_gc  = (ERRCTRL_ERRLVL_NONCRITICAL_gv << ERRCTRL_ERRLVL_gp),  /* Noncritical error (reset value) */
    ERRCTRL_ERRLVL_NOTIFICATION_gc = (ERRCTRL_ERRLVL_NOTIFICATION_gv << ERRCTRL_ERRLVL_gp)   /* Notification error */
} ERRCTRL_ERRLVL_t;

/* Float I/O pins select bit group values */
typedef enum ERRCTRL_FLOAT_VALUES_enum
{
    ERRCTRL_FLOAT_NORMAL_gv        = 0x00,  /* I/O pins are not forced to floating state */
    ERRCTRL_FLOAT_FLOAT_gv         = 0x01   /* I/O pins are forced to floating state */
} ERRCTRL_FLOAT_values_t;

/* Float I/O pins select bit group configurations*/
typedef enum ERRCTRL_FLOAT_enum
{
    ERRCTRL_FLOAT_NORMAL_gc        = (ERRCTRL_FLOAT_NORMAL_gv << ERRCTRL_FLOAT_bp),  /* I/O pins are not forced to floating state */
    ERRCTRL_FLOAT_FLOAT_gc         = (ERRCTRL_FLOAT_FLOAT_gv << ERRCTRL_FLOAT_bp)   /* I/O pins are forced to floating state */
} ERRCTRL_FLOAT_t;

/* ALARM State Interrupt Type select bit group values */
typedef enum ERRCTRL_INTTYPE_VALUES_enum
{
    ERRCTRL_INTTYPE_INT_gv         = 0x00,  /* Interrupt */
    ERRCTRL_INTTYPE_NMI_gv         = 0x01   /* Non-maskable interrupt */
} ERRCTRL_INTTYPE_values_t;

/* ALARM State Interrupt Type select bit group configurations*/
typedef enum ERRCTRL_INTTYPE_enum
{
    ERRCTRL_INTTYPE_INT_gc         = (ERRCTRL_INTTYPE_INT_gv << ERRCTRL_INTTYPE_bp),  /* Interrupt */
    ERRCTRL_INTTYPE_NMI_gc         = (ERRCTRL_INTTYPE_NMI_gv << ERRCTRL_INTTYPE_bp)   /* Non-maskable interrupt */
} ERRCTRL_INTTYPE_t;

/* All I/O pins are in safe state select bit group values */
typedef enum ERRCTRL_IOSAFE_VALUES_enum
{
    ERRCTRL_IOSAFE_NOSAFE_gv       = 0x00,  /* One or more I/O pins are not in safe state */
    ERRCTRL_IOSAFE_SAFE_gv         = 0x01   /* All I/O pins are in a safe state */
} ERRCTRL_IOSAFE_values_t;

/* All I/O pins are in safe state select bit group configurations*/
typedef enum ERRCTRL_IOSAFE_enum
{
    ERRCTRL_IOSAFE_NOSAFE_gc       = (ERRCTRL_IOSAFE_NOSAFE_gv << ERRCTRL_IOSAFE_bp),  /* One or more I/O pins are not in safe state */
    ERRCTRL_IOSAFE_SAFE_gc         = (ERRCTRL_IOSAFE_SAFE_gv << ERRCTRL_IOSAFE_bp)   /* All I/O pins are in a safe state */
} ERRCTRL_IOSAFE_t;

/* Noncritical Error Detected select bit group values */
typedef enum ERRCTRL_NONCRITICAL_VALUES_enum
{
    ERRCTRL_NONCRITICAL_NOERROR_gv = 0x00,  /* There are no Noncritical errors in the system */
    ERRCTRL_NONCRITICAL_ERROR_gv   = 0x01   /* There are one or more Noncritical errors in the system */
} ERRCTRL_NONCRITICAL_values_t;

/* Noncritical Error Detected select bit group configurations*/
typedef enum ERRCTRL_NONCRITICAL_enum
{
    ERRCTRL_NONCRITICAL_NOERROR_gc = (ERRCTRL_NONCRITICAL_NOERROR_gv << ERRCTRL_NONCRITICAL_bp),  /* There are no Noncritical errors in the system */
    ERRCTRL_NONCRITICAL_ERROR_gc   = (ERRCTRL_NONCRITICAL_ERROR_gv << ERRCTRL_NONCRITICAL_bp)   /* There are one or more Noncritical errors in the system */
} ERRCTRL_NONCRITICAL_t;

/* Notification Error Detected select bit group values */
typedef enum ERRCTRL_NOTIFICATION_VALUES_enum
{
    ERRCTRL_NOTIFICATION_NOERROR_gv = 0x00,  /* There are no Notification errors in the system */
    ERRCTRL_NOTIFICATION_ERROR_gv  = 0x01   /* There are one or more Notification errors in the system */
} ERRCTRL_NOTIFICATION_values_t;

/* Notification Error Detected select bit group configurations*/
typedef enum ERRCTRL_NOTIFICATION_enum
{
    ERRCTRL_NOTIFICATION_NOERROR_gc = (ERRCTRL_NOTIFICATION_NOERROR_gv << ERRCTRL_NOTIFICATION_bp),  /* There are no Notification errors in the system */
    ERRCTRL_NOTIFICATION_ERROR_gc  = (ERRCTRL_NOTIFICATION_ERROR_gv << ERRCTRL_NOTIFICATION_bp)   /* There are one or more Notification errors in the system */
} ERRCTRL_NOTIFICATION_t;

/* ERRCTRL State select bit group values */
typedef enum ERRCTRL_STATE_VALUES_enum
{
    ERRCTRL_STATE_CONFIG_gv        = 0x00,  /* Configuration state */
    ERRCTRL_STATE_NORMAL_gv        = 0x01,  /* Normal state */
    ERRCTRL_STATE_ALARM_gv         = 0x02,  /* Alarm state */
    ERRCTRL_STATE_FAULT_gv         = 0x03   /* Fault state */
} ERRCTRL_STATE_values_t;

/* ERRCTRL State select bit group configurations*/
typedef enum ERRCTRL_STATE_enum
{
    ERRCTRL_STATE_CONFIG_gc        = (ERRCTRL_STATE_CONFIG_gv << ERRCTRL_STATE_gp),  /* Configuration state */
    ERRCTRL_STATE_NORMAL_gc        = (ERRCTRL_STATE_NORMAL_gv << ERRCTRL_STATE_gp),  /* Normal state */
    ERRCTRL_STATE_ALARM_gc         = (ERRCTRL_STATE_ALARM_gv << ERRCTRL_STATE_gp),  /* Alarm state */
    ERRCTRL_STATE_FAULT_gc         = (ERRCTRL_STATE_FAULT_gv << ERRCTRL_STATE_gp)   /* Fault state */
} ERRCTRL_STATE_t;

/*
--------------------------------------------------------------------------
EVSYS - Event System
--------------------------------------------------------------------------
*/

/* Event System */
typedef struct EVSYS_struct
{
    register8_t SWEVENTA;  /* Software Event A */
    register8_t reserved_1[15];
    register8_t CHANNEL0;  /* Multiplexer Channel 0 */
    register8_t CHANNEL1;  /* Multiplexer Channel 1 */
    register8_t CHANNEL2;  /* Multiplexer Channel 2 */
    register8_t CHANNEL3;  /* Multiplexer Channel 3 */
    register8_t CHANNEL4;  /* Multiplexer Channel 4 */
    register8_t CHANNEL5;  /* Multiplexer Channel 5 */
    register8_t reserved_2[10];
    register8_t USERCCLLUT0A;  /* User 0 - CCL LUT0 Event A */
    register8_t USERCCLLUT0B;  /* User 1 - CCL LUT0 Event B */
    register8_t USERCCLLUT1A;  /* User 2 - CCL LUT1 Event A */
    register8_t USERCCLLUT1B;  /* User 3 - CCL LUT1 Event B */
    register8_t USERCCLLUT2A;  /* User 4 - CCL LUT2 Event A */
    register8_t USERCCLLUT2B;  /* User 5 - CCL LUT2 Event B */
    register8_t USERCCLLUT3A;  /* User 6 - CCL LUT3 Event A */
    register8_t USERCCLLUT3B;  /* User 7 - CCL LUT3 Event B */
    register8_t USERCCLLUT4A;  /* User 8 - CCL LUT4 Event A */
    register8_t USERCCLLUT4B;  /* User 9 - CCL LUT4 Event B */
    register8_t USERCCLLUT5A;  /* User 10 - CCL LUT5 Event A */
    register8_t USERCCLLUT5B;  /* User 11 - CCL LUT5 Event B */
    register8_t USERADC0START;  /* User 12 - ADC0 */
    register8_t USERADC1START;  /* User 13 - ADC1 */
    register8_t USEREVSYSEVOUTA;  /* User 14 - EVOUTA */
    register8_t USEREVSYSEVOUTC;  /* User 15 - EVOUTC */
    register8_t USEREVSYSEVOUTD;  /* User 16 - EVOUTD */
    register8_t reserved_3[1];
    register8_t USERUSART0IRDA;  /* User 18 - USART0 */
    register8_t USERUSART1IRDA;  /* User 19 - USART1 */
    register8_t reserved_4[1];
    register8_t USERTCA0CNTA;  /* User 21 - TCA0 Event A */
    register8_t USERTCA0CNTB;  /* User 22 - TCA0 Event B */
    register8_t USERTCB0CAPT;  /* User 23 - TCB0 Event A */
    register8_t USERTCB0COUNT;  /* User 24 - TCB0 Event B */
    register8_t USERTCB1CAPT;  /* User 25 - TCB1 Event A */
    register8_t USERTCB1COUNT;  /* User 26 - TCB1 Event B */
    register8_t USERTCB2CAPT;  /* User 27 - TCB2 Event A */
    register8_t USERTCB2COUNT;  /* User 28 - TCB2 Event B */
    register8_t USERTCB3CAPT;  /* User 29 - TCB3 Event A */
    register8_t USERTCB3COUNT;  /* User 30 - TCB3 Event B */
    register8_t USERTCD0INPUTA;  /* User 31 - TCD0 Event A */
    register8_t USERTCD0INPUTB;  /* User 32 - TCD0 Event B */
    register8_t USERERRCTRLEVENT0;  /* User 33 - ERRCTRL Event 0 */
    register8_t USERERRCTRLEVENT1;  /* User 34 - ERRCTRL Event 1 */
    register8_t USERCLKCTRLCFD;  /* User 35 - CLKCTRL CFD */
    register8_t USERCLKCTRLCFM;  /* User 36 - CLKCTRL CFM */
    register8_t reserved_5[59];
} EVSYS_t;

/* Channel Generator Select bit group values */
typedef enum EVSYS_CHANNEL_VALUES_enum
{
    EVSYS_CHANNEL_OFF_gv           = 0x00,  /* Off */
    EVSYS_CHANNEL_UPDI_SYNCH_gv    = 0x01,  /* UPDI SYNCH character */
    EVSYS_CHANNEL_WDT_TICK_gv      = 0x03,  /* WDT LSB Tick */
    EVSYS_CHANNEL_SWDT_ERROR_gv    = 0x04,  /* SWDT Error */
    EVSYS_CHANNEL_MVIO_VDDIO2OK_gv = 0x05,  /* VDDIO2 OK */
    EVSYS_CHANNEL_RTC_OVF_gv       = 0x06,  /* Real Time Counter overflow */
    EVSYS_CHANNEL_RTC_CMP_gv       = 0x07,  /* Real Time Counter compare */
    EVSYS_CHANNEL_RTC_EVGEN0_gv    = 0x08,  /* Event output 0 */
    EVSYS_CHANNEL_RTC_EVGEN1_gv    = 0x09,  /* Event output 1 */
    EVSYS_CHANNEL_CCL_LUT0_gv      = 0x10,  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL_CCL_LUT1_gv      = 0x11,  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL_CCL_LUT2_gv      = 0x12,  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL_CCL_LUT3_gv      = 0x13,  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL_CCL_LUT4_gv      = 0x14,  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL_CCL_LUT5_gv      = 0x15,  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL_AC0_OUT_gv       = 0x20,  /* Analog Comparator 0 out */
    EVSYS_CHANNEL_AC1_OUT_gv       = 0x21,  /* Analog Comparator 1 out */
    EVSYS_CHANNEL_AC2_OUT_gv       = 0x22,  /* Analog Comparator 2 out */
    EVSYS_CHANNEL_ADC0_RESRDY_gv   = 0x24,  /* ADC 0 Result Ready */
    EVSYS_CHANNEL_ADC0_SAMPRDY_gv  = 0x25,  /* ADC 0 Sample Ready */
    EVSYS_CHANNEL_ADC0_WCMP_gv     = 0x26,  /* ADC 0 Window Comparator */
    EVSYS_CHANNEL_ADC1_RESRDY_gv   = 0x27,  /* ADC 1 Result Ready */
    EVSYS_CHANNEL_ADC1_SAMPRDY_gv  = 0x28,  /* ADC 1 Sample Ready */
    EVSYS_CHANNEL_ADC1_WCMP_gv     = 0x29,  /* ADC 1 Window Comparator */
    EVSYS_CHANNEL_ZCD3_OUT_gv      = 0x33,  /* Zero Cross Detect 3 out */
    EVSYS_CHANNEL_PORTA_EVGEN0_gv  = 0x40,  /* Port A Event 0 */
    EVSYS_CHANNEL_PORTA_EVGEN1_gv  = 0x41,  /* Port A Event 1 */
    EVSYS_CHANNEL_PORTC_EVGEN0_gv  = 0x44,  /* Port C Event 0 */
    EVSYS_CHANNEL_PORTC_EVGEN1_gv  = 0x45,  /* Port C Event 1 */
    EVSYS_CHANNEL_PORTD_EVGEN0_gv  = 0x46,  /* Port D Event 0 */
    EVSYS_CHANNEL_PORTD_EVGEN1_gv  = 0x47,  /* Port D Event 1 */
    EVSYS_CHANNEL_USART0_XCK_gv    = 0x60,  /* USART 0 XCK */
    EVSYS_CHANNEL_USART1_XCK_gv    = 0x61,  /* USART 1 XCK */
    EVSYS_CHANNEL_USART2_XCK_gv    = 0x62,  /* USART 2 XCK */
    EVSYS_CHANNEL_SPI0_SCK_gv      = 0x68,  /* SPI 0 SCK */
    EVSYS_CHANNEL_SPI1_SCK_gv      = 0x69,  /* SPI 1 SCK */
    EVSYS_CHANNEL_TCA0_OVF_LUNF_gv = 0x80,  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL_TCA0_HUNF_gv     = 0x81,  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL_TCA0_CMP0_LCMP0_gv = 0x84,  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL_TCA0_CMP1_LCMP1_gv = 0x85,  /* Timer/Counter A0 compare 0 / low byte timer compare 1 */
    EVSYS_CHANNEL_TCA0_CMP2_LCMP2_gv = 0x86,  /* Timer/Counter A0 compare 0 / low byte timer compare 2 */
    EVSYS_CHANNEL_TCB0_CAPT_gv     = 0xA0,  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL_TCB0_OVF_gv      = 0xA1,  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL_TCB1_CAPT_gv     = 0xA2,  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL_TCB1_OVF_gv      = 0xA3,  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL_TCB2_CAPT_gv     = 0xA4,  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL_TCB2_OVF_gv      = 0xA5,  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL_TCB3_CAPT_gv     = 0xA6,  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL_TCB3_OVF_gv      = 0xA7,  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL_TCD0_CMPBCLR_gv  = 0xB0,  /* Counter matches CMPBCLR */
    EVSYS_CHANNEL_TCD0_CMPASET_gv  = 0xB1,  /* Counter matches CMPASET */
    EVSYS_CHANNEL_TCD0_CMPBSET_gv  = 0xB2,  /* Counter matches CMPBSET */
    EVSYS_CHANNEL_TCD0_PROGEV_gv   = 0xB3   /* Programmable event output */
} EVSYS_CHANNEL_values_t;

/* Channel Generator Select bit group configurations*/
typedef enum EVSYS_CHANNEL_enum
{
    EVSYS_CHANNEL_OFF_gc           = (EVSYS_CHANNEL_OFF_gv << EVSYS_CHANNEL_gp),  /* Off */
    EVSYS_CHANNEL_UPDI_SYNCH_gc    = (EVSYS_CHANNEL_UPDI_SYNCH_gv << EVSYS_CHANNEL_gp),  /* UPDI SYNCH character */
    EVSYS_CHANNEL_WDT_TICK_gc      = (EVSYS_CHANNEL_WDT_TICK_gv << EVSYS_CHANNEL_gp),  /* WDT LSB Tick */
    EVSYS_CHANNEL_SWDT_ERROR_gc    = (EVSYS_CHANNEL_SWDT_ERROR_gv << EVSYS_CHANNEL_gp),  /* SWDT Error */
    EVSYS_CHANNEL_MVIO_VDDIO2OK_gc = (EVSYS_CHANNEL_MVIO_VDDIO2OK_gv << EVSYS_CHANNEL_gp),  /* VDDIO2 OK */
    EVSYS_CHANNEL_RTC_OVF_gc       = (EVSYS_CHANNEL_RTC_OVF_gv << EVSYS_CHANNEL_gp),  /* Real Time Counter overflow */
    EVSYS_CHANNEL_RTC_CMP_gc       = (EVSYS_CHANNEL_RTC_CMP_gv << EVSYS_CHANNEL_gp),  /* Real Time Counter compare */
    EVSYS_CHANNEL_RTC_EVGEN0_gc    = (EVSYS_CHANNEL_RTC_EVGEN0_gv << EVSYS_CHANNEL_gp),  /* Event output 0 */
    EVSYS_CHANNEL_RTC_EVGEN1_gc    = (EVSYS_CHANNEL_RTC_EVGEN1_gv << EVSYS_CHANNEL_gp),  /* Event output 1 */
    EVSYS_CHANNEL_CCL_LUT0_gc      = (EVSYS_CHANNEL_CCL_LUT0_gv << EVSYS_CHANNEL_gp),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL_CCL_LUT1_gc      = (EVSYS_CHANNEL_CCL_LUT1_gv << EVSYS_CHANNEL_gp),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL_CCL_LUT2_gc      = (EVSYS_CHANNEL_CCL_LUT2_gv << EVSYS_CHANNEL_gp),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL_CCL_LUT3_gc      = (EVSYS_CHANNEL_CCL_LUT3_gv << EVSYS_CHANNEL_gp),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL_CCL_LUT4_gc      = (EVSYS_CHANNEL_CCL_LUT4_gv << EVSYS_CHANNEL_gp),  /* Configurable Custom Logic LUT4 */
    EVSYS_CHANNEL_CCL_LUT5_gc      = (EVSYS_CHANNEL_CCL_LUT5_gv << EVSYS_CHANNEL_gp),  /* Configurable Custom Logic LUT5 */
    EVSYS_CHANNEL_AC0_OUT_gc       = (EVSYS_CHANNEL_AC0_OUT_gv << EVSYS_CHANNEL_gp),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL_AC1_OUT_gc       = (EVSYS_CHANNEL_AC1_OUT_gv << EVSYS_CHANNEL_gp),  /* Analog Comparator 1 out */
    EVSYS_CHANNEL_AC2_OUT_gc       = (EVSYS_CHANNEL_AC2_OUT_gv << EVSYS_CHANNEL_gp),  /* Analog Comparator 2 out */
    EVSYS_CHANNEL_ADC0_RESRDY_gc   = (EVSYS_CHANNEL_ADC0_RESRDY_gv << EVSYS_CHANNEL_gp),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL_ADC0_SAMPRDY_gc  = (EVSYS_CHANNEL_ADC0_SAMPRDY_gv << EVSYS_CHANNEL_gp),  /* ADC 0 Sample Ready */
    EVSYS_CHANNEL_ADC0_WCMP_gc     = (EVSYS_CHANNEL_ADC0_WCMP_gv << EVSYS_CHANNEL_gp),  /* ADC 0 Window Comparator */
    EVSYS_CHANNEL_ADC1_RESRDY_gc   = (EVSYS_CHANNEL_ADC1_RESRDY_gv << EVSYS_CHANNEL_gp),  /* ADC 1 Result Ready */
    EVSYS_CHANNEL_ADC1_SAMPRDY_gc  = (EVSYS_CHANNEL_ADC1_SAMPRDY_gv << EVSYS_CHANNEL_gp),  /* ADC 1 Sample Ready */
    EVSYS_CHANNEL_ADC1_WCMP_gc     = (EVSYS_CHANNEL_ADC1_WCMP_gv << EVSYS_CHANNEL_gp),  /* ADC 1 Window Comparator */
    EVSYS_CHANNEL_ZCD3_OUT_gc      = (EVSYS_CHANNEL_ZCD3_OUT_gv << EVSYS_CHANNEL_gp),  /* Zero Cross Detect 3 out */
    EVSYS_CHANNEL_PORTA_EVGEN0_gc  = (EVSYS_CHANNEL_PORTA_EVGEN0_gv << EVSYS_CHANNEL_gp),  /* Port A Event 0 */
    EVSYS_CHANNEL_PORTA_EVGEN1_gc  = (EVSYS_CHANNEL_PORTA_EVGEN1_gv << EVSYS_CHANNEL_gp),  /* Port A Event 1 */
    EVSYS_CHANNEL_PORTC_EVGEN0_gc  = (EVSYS_CHANNEL_PORTC_EVGEN0_gv << EVSYS_CHANNEL_gp),  /* Port C Event 0 */
    EVSYS_CHANNEL_PORTC_EVGEN1_gc  = (EVSYS_CHANNEL_PORTC_EVGEN1_gv << EVSYS_CHANNEL_gp),  /* Port C Event 1 */
    EVSYS_CHANNEL_PORTD_EVGEN0_gc  = (EVSYS_CHANNEL_PORTD_EVGEN0_gv << EVSYS_CHANNEL_gp),  /* Port D Event 0 */
    EVSYS_CHANNEL_PORTD_EVGEN1_gc  = (EVSYS_CHANNEL_PORTD_EVGEN1_gv << EVSYS_CHANNEL_gp),  /* Port D Event 1 */
    EVSYS_CHANNEL_USART0_XCK_gc    = (EVSYS_CHANNEL_USART0_XCK_gv << EVSYS_CHANNEL_gp),  /* USART 0 XCK */
    EVSYS_CHANNEL_USART1_XCK_gc    = (EVSYS_CHANNEL_USART1_XCK_gv << EVSYS_CHANNEL_gp),  /* USART 1 XCK */
    EVSYS_CHANNEL_USART2_XCK_gc    = (EVSYS_CHANNEL_USART2_XCK_gv << EVSYS_CHANNEL_gp),  /* USART 2 XCK */
    EVSYS_CHANNEL_SPI0_SCK_gc      = (EVSYS_CHANNEL_SPI0_SCK_gv << EVSYS_CHANNEL_gp),  /* SPI 0 SCK */
    EVSYS_CHANNEL_SPI1_SCK_gc      = (EVSYS_CHANNEL_SPI1_SCK_gv << EVSYS_CHANNEL_gp),  /* SPI 1 SCK */
    EVSYS_CHANNEL_TCA0_OVF_LUNF_gc = (EVSYS_CHANNEL_TCA0_OVF_LUNF_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL_TCA0_HUNF_gc     = (EVSYS_CHANNEL_TCA0_HUNF_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL_TCA0_CMP0_LCMP0_gc = (EVSYS_CHANNEL_TCA0_CMP0_LCMP0_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL_TCA0_CMP1_LCMP1_gc = (EVSYS_CHANNEL_TCA0_CMP1_LCMP1_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter A0 compare 0 / low byte timer compare 1 */
    EVSYS_CHANNEL_TCA0_CMP2_LCMP2_gc = (EVSYS_CHANNEL_TCA0_CMP2_LCMP2_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter A0 compare 0 / low byte timer compare 2 */
    EVSYS_CHANNEL_TCB0_CAPT_gc     = (EVSYS_CHANNEL_TCB0_CAPT_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL_TCB0_OVF_gc      = (EVSYS_CHANNEL_TCB0_OVF_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B0 overflow */
    EVSYS_CHANNEL_TCB1_CAPT_gc     = (EVSYS_CHANNEL_TCB1_CAPT_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL_TCB1_OVF_gc      = (EVSYS_CHANNEL_TCB1_OVF_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B1 overflow */
    EVSYS_CHANNEL_TCB2_CAPT_gc     = (EVSYS_CHANNEL_TCB2_CAPT_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL_TCB2_OVF_gc      = (EVSYS_CHANNEL_TCB2_OVF_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B2 overflow */
    EVSYS_CHANNEL_TCB3_CAPT_gc     = (EVSYS_CHANNEL_TCB3_CAPT_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B3 capture */
    EVSYS_CHANNEL_TCB3_OVF_gc      = (EVSYS_CHANNEL_TCB3_OVF_gv << EVSYS_CHANNEL_gp),  /* Timer/Counter B3 overflow */
    EVSYS_CHANNEL_TCD0_CMPBCLR_gc  = (EVSYS_CHANNEL_TCD0_CMPBCLR_gv << EVSYS_CHANNEL_gp),  /* Counter matches CMPBCLR */
    EVSYS_CHANNEL_TCD0_CMPASET_gc  = (EVSYS_CHANNEL_TCD0_CMPASET_gv << EVSYS_CHANNEL_gp),  /* Counter matches CMPASET */
    EVSYS_CHANNEL_TCD0_CMPBSET_gc  = (EVSYS_CHANNEL_TCD0_CMPBSET_gv << EVSYS_CHANNEL_gp),  /* Counter matches CMPBSET */
    EVSYS_CHANNEL_TCD0_PROGEV_gc   = (EVSYS_CHANNEL_TCD0_PROGEV_gv << EVSYS_CHANNEL_gp)   /* Programmable event output */
} EVSYS_CHANNEL_t;

/* User channel select bit group values */
typedef enum EVSYS_USER_VALUES_enum
{
    EVSYS_USER_OFF_gv              = 0x00,  /* Off */
    EVSYS_USER_CHANNEL0_gv         = 0x01,  /* Connect user to event channel 0 */
    EVSYS_USER_CHANNEL1_gv         = 0x02,  /* Connect user to event channel 1 */
    EVSYS_USER_CHANNEL2_gv         = 0x03,  /* Connect user to event channel 2 */
    EVSYS_USER_CHANNEL3_gv         = 0x04,  /* Connect user to event channel 3 */
    EVSYS_USER_CHANNEL4_gv         = 0x05,  /* Connect user to event channel 4 */
    EVSYS_USER_CHANNEL5_gv         = 0x06   /* Connect user to event channel 5 */
} EVSYS_USER_values_t;

/* User channel select bit group configurations*/
typedef enum EVSYS_USER_enum
{
    EVSYS_USER_OFF_gc              = (EVSYS_USER_OFF_gv << EVSYS_USER_gp),  /* Off */
    EVSYS_USER_CHANNEL0_gc         = (EVSYS_USER_CHANNEL0_gv << EVSYS_USER_gp),  /* Connect user to event channel 0 */
    EVSYS_USER_CHANNEL1_gc         = (EVSYS_USER_CHANNEL1_gv << EVSYS_USER_gp),  /* Connect user to event channel 1 */
    EVSYS_USER_CHANNEL2_gc         = (EVSYS_USER_CHANNEL2_gv << EVSYS_USER_gp),  /* Connect user to event channel 2 */
    EVSYS_USER_CHANNEL3_gc         = (EVSYS_USER_CHANNEL3_gv << EVSYS_USER_gp),  /* Connect user to event channel 3 */
    EVSYS_USER_CHANNEL4_gc         = (EVSYS_USER_CHANNEL4_gv << EVSYS_USER_gp),  /* Connect user to event channel 4 */
    EVSYS_USER_CHANNEL5_gc         = (EVSYS_USER_CHANNEL5_gv << EVSYS_USER_gp)   /* Connect user to event channel 5 */
} EVSYS_USER_t;

/*
--------------------------------------------------------------------------
FUSE - Fuses
--------------------------------------------------------------------------
*/

/* Fuses */
typedef struct FUSE_struct
{
    register8_t WDTCFG;  /* Watchdog Configuration */
    register8_t BODCFG;  /* BOD Configuration */
    register8_t reserved_1[3];
    register8_t SYSCFG0;  /* System Configuration 0 */
    register8_t SYSCFG1;  /* System Configuration 1 */
    register8_t CODESIZE;  /* Code Section Size */
    register8_t BOOTSIZE;  /* Boot Section Size */
    register8_t reserved_2[1];
    _WORDREGISTER(PDICFG);  /* Programming and Debugging Interface Configuration */
} FUSE_t;

/* avr-libc typedef for avr/fuse.h */
typedef FUSE_t NVM_FUSES_t;

/* BOD Operation in Active Mode select bit group values */
typedef enum ACTIVE_VALUES_enum
{
    ACTIVE_DISABLE_gv              = 0x00,  /* BOD disabled */
    ACTIVE_ENABLE_gv               = 0x01,  /* BOD enabled in continuous mode */
    ACTIVE_SAMPLE_gv               = 0x02,  /* BOD enabled in sampled mode */
    ACTIVE_ENABLEWAIT_gv           = 0x03   /* BOD enabled in continuous mode. Execution is halted at wake-up until BOD is running. */
} ACTIVE_values_t;

/* BOD Operation in Active Mode select bit group configurations*/
typedef enum ACTIVE_enum
{
    ACTIVE_DISABLE_gc              = (ACTIVE_DISABLE_gv << FUSE_ACTIVE_gp),  /* BOD disabled */
    ACTIVE_ENABLE_gc               = (ACTIVE_ENABLE_gv << FUSE_ACTIVE_gp),  /* BOD enabled in continuous mode */
    ACTIVE_SAMPLE_gc               = (ACTIVE_SAMPLE_gv << FUSE_ACTIVE_gp),  /* BOD enabled in sampled mode */
    ACTIVE_ENABLEWAIT_gc           = (ACTIVE_ENABLEWAIT_gv << FUSE_ACTIVE_gp)   /* BOD enabled in continuous mode. Execution is halted at wake-up until BOD is running. */
} ACTIVE_t;

/* CRC Select bit group values */
typedef enum CRCSEL_VALUES_enum
{
    CRCSEL_CRC16_gv                = 0x00,  /* Enable CRC16 */
    CRCSEL_CRC32_gv                = 0x01   /* Enable CRC32 */
} CRCSEL_values_t;

/* CRC Select bit group configurations*/
typedef enum CRCSEL_enum
{
    CRCSEL_CRC16_gc                = (CRCSEL_CRC16_gv << FUSE_CRCSEL_bp),  /* Enable CRC16 */
    CRCSEL_CRC32_gc                = (CRCSEL_CRC32_gv << FUSE_CRCSEL_bp)   /* Enable CRC32 */
} CRCSEL_t;

/* NVM Protection Activation Key select bit group values */
typedef enum KEY_VALUES_enum
{
    KEY_NOTACT_gv                  = 0x00,  /* Not active */
    KEY_NVMACT_gv                  = 0xB45   /* NVM Protection active */
} KEY_values_t;

/* NVM Protection Activation Key select bit group configurations*/
typedef enum KEY_enum
{
    KEY_NOTACT_gc                  = (KEY_NOTACT_gv << FUSE_KEY_gp),  /* Not active */
    KEY_NVMACT_gc                  = (KEY_NVMACT_gv << FUSE_KEY_gp)   /* NVM Protection active */
} KEY_t;

/* Protection Level select bit group values */
typedef enum LEVEL_VALUES_enum
{
    LEVEL_NVMACCDIS_gv             = 0x02,  /* NVM access through UPDI disabled */
    LEVEL_BASIC_gv                 = 0x03   /* UPDI and UPDI pins working normally */
} LEVEL_values_t;

/* Protection Level select bit group configurations*/
typedef enum LEVEL_enum
{
    LEVEL_NVMACCDIS_gc             = (LEVEL_NVMACCDIS_gv << FUSE_LEVEL_gp),  /* NVM access through UPDI disabled */
    LEVEL_BASIC_gc                 = (LEVEL_BASIC_gv << FUSE_LEVEL_gp)   /* UPDI and UPDI pins working normally */
} LEVEL_t;

/* BOD Level select bit group values */
typedef enum LVL_VALUES_enum
{
    LVL_BODLEVEL0_gv               = 0x00,  /* 1.9V */
    LVL_BODLEVEL1_gv               = 0x01,  /* 2.45V */
    LVL_BODLEVEL2_gv               = 0x02,  /* 2.7V */
    LVL_BODLEVEL3_gv               = 0x03   /* 2.85V */
} LVL_values_t;

/* BOD Level select bit group configurations*/
typedef enum LVL_enum
{
    LVL_BODLEVEL0_gc               = (LVL_BODLEVEL0_gv << FUSE_LVL_gp),  /* 1.9V */
    LVL_BODLEVEL1_gc               = (LVL_BODLEVEL1_gv << FUSE_LVL_gp),  /* 2.45V */
    LVL_BODLEVEL2_gc               = (LVL_BODLEVEL2_gv << FUSE_LVL_gp),  /* 2.7V */
    LVL_BODLEVEL3_gc               = (LVL_BODLEVEL3_gv << FUSE_LVL_gp)   /* 2.85V */
} LVL_t;

/* MVIO System Configuration select bit group values */
typedef enum MVSYSCFG_VALUES_enum
{
    MVSYSCFG_RESERVED_gv           = 0x00,  /* Reserved */
    MVSYSCFG_DUAL_gv               = 0x01,  /* Device used in a dual supply configuration */
    MVSYSCFG_SINGLE_gv             = 0x02   /* Device used in a single supply configuration */
} MVSYSCFG_values_t;

/* MVIO System Configuration select bit group configurations*/
typedef enum MVSYSCFG_enum
{
    MVSYSCFG_RESERVED_gc           = (MVSYSCFG_RESERVED_gv << FUSE_MVSYSCFG_gp),  /* Reserved */
    MVSYSCFG_DUAL_gc               = (MVSYSCFG_DUAL_gv << FUSE_MVSYSCFG_gp),  /* Device used in a dual supply configuration */
    MVSYSCFG_SINGLE_gc             = (MVSYSCFG_SINGLE_gv << FUSE_MVSYSCFG_gp)   /* Device used in a single supply configuration */
} MVSYSCFG_t;

/* Watchdog Timeout Period select bit group values */
typedef enum PERIOD_VALUES_enum
{
    PERIOD_OFF_gv                  = 0x00,  /* Off */
    PERIOD_8CLK_gv                 = 0x01,  /* 8 cycles (244 us) */
    PERIOD_16CLK_gv                = 0x02,  /* 16 cycles (488 us) */
    PERIOD_32CLK_gv                = 0x03,  /* 32 cycles (976 us) */
    PERIOD_64CLK_gv                = 0x04,  /* 64 cycles (1.95 ms) */
    PERIOD_128CLK_gv               = 0x05,  /* 128 cycles (3.9 ms) */
    PERIOD_256CLK_gv               = 0x06,  /* 256 cycles (7.8 ms) */
    PERIOD_512CLK_gv               = 0x07,  /* 512 cycles (15.625 ms) */
    PERIOD_1KCLK_gv                = 0x08,  /* 1K cycles (31.25 ms) */
    PERIOD_2KCLK_gv                = 0x09,  /* 2K cycles (62.5 ms) */
    PERIOD_4KCLK_gv                = 0x0A,  /* 4K cycles (125 ms) */
    PERIOD_8KCLK_gv                = 0x0B   /* 8K cycles (250 ms) */
} PERIOD_values_t;

/* Watchdog Timeout Period select bit group configurations*/
typedef enum PERIOD_enum
{
    PERIOD_OFF_gc                  = (PERIOD_OFF_gv << FUSE_PERIOD_gp),  /* Off */
    PERIOD_8CLK_gc                 = (PERIOD_8CLK_gv << FUSE_PERIOD_gp),  /* 8 cycles (244 us) */
    PERIOD_16CLK_gc                = (PERIOD_16CLK_gv << FUSE_PERIOD_gp),  /* 16 cycles (488 us) */
    PERIOD_32CLK_gc                = (PERIOD_32CLK_gv << FUSE_PERIOD_gp),  /* 32 cycles (976 us) */
    PERIOD_64CLK_gc                = (PERIOD_64CLK_gv << FUSE_PERIOD_gp),  /* 64 cycles (1.95 ms) */
    PERIOD_128CLK_gc               = (PERIOD_128CLK_gv << FUSE_PERIOD_gp),  /* 128 cycles (3.9 ms) */
    PERIOD_256CLK_gc               = (PERIOD_256CLK_gv << FUSE_PERIOD_gp),  /* 256 cycles (7.8 ms) */
    PERIOD_512CLK_gc               = (PERIOD_512CLK_gv << FUSE_PERIOD_gp),  /* 512 cycles (15.625 ms) */
    PERIOD_1KCLK_gc                = (PERIOD_1KCLK_gv << FUSE_PERIOD_gp),  /* 1K cycles (31.25 ms) */
    PERIOD_2KCLK_gc                = (PERIOD_2KCLK_gv << FUSE_PERIOD_gp),  /* 2K cycles (62.5 ms) */
    PERIOD_4KCLK_gc                = (PERIOD_4KCLK_gv << FUSE_PERIOD_gp),  /* 4K cycles (125 ms) */
    PERIOD_8KCLK_gc                = (PERIOD_8KCLK_gv << FUSE_PERIOD_gp)   /* 8K cycles (250 ms) */
} PERIOD_t;

/* BOD Sample Frequency select bit group values */
typedef enum SAMPFREQ_VALUES_enum
{
    SAMPFREQ_128HZ_gv              = 0x00,  /* Sample frequency is 128 Hz */
    SAMPFREQ_32HZ_gv               = 0x01   /* Sample frequency is 32 Hz */
} SAMPFREQ_values_t;

/* BOD Sample Frequency select bit group configurations*/
typedef enum SAMPFREQ_enum
{
    SAMPFREQ_128HZ_gc              = (SAMPFREQ_128HZ_gv << FUSE_SAMPFREQ_bp),  /* Sample frequency is 128 Hz */
    SAMPFREQ_32HZ_gc               = (SAMPFREQ_32HZ_gv << FUSE_SAMPFREQ_bp)   /* Sample frequency is 32 Hz */
} SAMPFREQ_t;

/* BOD Operation in Sleep Mode select bit group values */
typedef enum SLEEP_VALUES_enum
{
    SLEEP_DISABLE_gv               = 0x00,  /* BOD disabled */
    SLEEP_ENABLE_gv                = 0x01,  /* BOD enabled in continuous mode */
    SLEEP_SAMPLE_gv                = 0x02   /* BOD enabled in sampled mode */
} SLEEP_values_t;

/* BOD Operation in Sleep Mode select bit group configurations*/
typedef enum SLEEP_enum
{
    SLEEP_DISABLE_gc               = (SLEEP_DISABLE_gv << FUSE_SLEEP_gp),  /* BOD disabled */
    SLEEP_ENABLE_gc                = (SLEEP_ENABLE_gv << FUSE_SLEEP_gp),  /* BOD enabled in continuous mode */
    SLEEP_SAMPLE_gc                = (SLEEP_SAMPLE_gv << FUSE_SLEEP_gp)   /* BOD enabled in sampled mode */
} SLEEP_t;

/* Startup Time select bit group values */
typedef enum SUT_VALUES_enum
{
    SUT_0MS_gv                     = 0x00,  /* 0 ms */
    SUT_1MS_gv                     = 0x01,  /* 1 ms */
    SUT_2MS_gv                     = 0x02,  /* 2 ms */
    SUT_4MS_gv                     = 0x03,  /* 4 ms */
    SUT_8MS_gv                     = 0x04,  /* 8 ms */
    SUT_16MS_gv                    = 0x05,  /* 16 ms */
    SUT_32MS_gv                    = 0x06,  /* 32 ms */
    SUT_64MS_gv                    = 0x07   /* 64 ms */
} SUT_values_t;

/* Startup Time select bit group configurations*/
typedef enum SUT_enum
{
    SUT_0MS_gc                     = (SUT_0MS_gv << FUSE_SUT_gp),  /* 0 ms */
    SUT_1MS_gc                     = (SUT_1MS_gv << FUSE_SUT_gp),  /* 1 ms */
    SUT_2MS_gc                     = (SUT_2MS_gv << FUSE_SUT_gp),  /* 2 ms */
    SUT_4MS_gc                     = (SUT_4MS_gv << FUSE_SUT_gp),  /* 4 ms */
    SUT_8MS_gc                     = (SUT_8MS_gv << FUSE_SUT_gp),  /* 8 ms */
    SUT_16MS_gc                    = (SUT_16MS_gv << FUSE_SUT_gp),  /* 16 ms */
    SUT_32MS_gc                    = (SUT_32MS_gv << FUSE_SUT_gp),  /* 32 ms */
    SUT_64MS_gc                    = (SUT_64MS_gv << FUSE_SUT_gp)   /* 64 ms */
} SUT_t;

/* WDT Monitor Configuration select bit group values */
typedef enum WDTMON_VALUES_enum
{
    WDTMON_OFF_gv                  = 0x00,  /* Monitor is disabled */
    WDTMON_ON_gv                   = 0x01,  /* Monitor is always on (Reset value) */
    WDTMON_SLEEP_gv                = 0x02,  /* Monitor is always on in normal and IDLE mode, but automatically disabled when the MCU is in POWERDOWN and STANDBY sleep modes */
    WDTMON_RESERVED_gv             = 0x03   /* Reserved */
} WDTMON_values_t;

/* WDT Monitor Configuration select bit group configurations*/
typedef enum WDTMON_enum
{
    WDTMON_OFF_gc                  = (WDTMON_OFF_gv << FUSE_WDTMON_gp),  /* Monitor is disabled */
    WDTMON_ON_gc                   = (WDTMON_ON_gv << FUSE_WDTMON_gp),  /* Monitor is always on (Reset value) */
    WDTMON_SLEEP_gc                = (WDTMON_SLEEP_gv << FUSE_WDTMON_gp),  /* Monitor is always on in normal and IDLE mode, but automatically disabled when the MCU is in POWERDOWN and STANDBY sleep modes */
    WDTMON_RESERVED_gc             = (WDTMON_RESERVED_gv << FUSE_WDTMON_gp)   /* Reserved */
} WDTMON_t;

/* Watchdog Window Timeout Period select bit group values */
typedef enum WINDOW_VALUES_enum
{
    WINDOW_OFF_gv                  = 0x00,  /* Off */
    WINDOW_8CLK_gv                 = 0x01,  /* 8 cycles (244 us) */
    WINDOW_16CLK_gv                = 0x02,  /* 16 cycles (488 us) */
    WINDOW_32CLK_gv                = 0x03,  /* 32 cycles (976 us) */
    WINDOW_64CLK_gv                = 0x04,  /* 64 cycles (1.95 ms) */
    WINDOW_128CLK_gv               = 0x05,  /* 128 cycles (3.9 ms) */
    WINDOW_256CLK_gv               = 0x06,  /* 256 cycles (7.8 ms) */
    WINDOW_512CLK_gv               = 0x07,  /* 512 cycles (15.625 ms) */
    WINDOW_1KCLK_gv                = 0x08,  /* 1K cycles (31.25 ms) */
    WINDOW_2KCLK_gv                = 0x09,  /* 2K cycles (62.5 ms) */
    WINDOW_4KCLK_gv                = 0x0A,  /* 4K cycles (125 ms) */
    WINDOW_8KCLK_gv                = 0x0B   /* 8K cycles (250 ms) */
} WINDOW_values_t;

/* Watchdog Window Timeout Period select bit group configurations*/
typedef enum WINDOW_enum
{
    WINDOW_OFF_gc                  = (WINDOW_OFF_gv << FUSE_WINDOW_gp),  /* Off */
    WINDOW_8CLK_gc                 = (WINDOW_8CLK_gv << FUSE_WINDOW_gp),  /* 8 cycles (244 us) */
    WINDOW_16CLK_gc                = (WINDOW_16CLK_gv << FUSE_WINDOW_gp),  /* 16 cycles (488 us) */
    WINDOW_32CLK_gc                = (WINDOW_32CLK_gv << FUSE_WINDOW_gp),  /* 32 cycles (976 us) */
    WINDOW_64CLK_gc                = (WINDOW_64CLK_gv << FUSE_WINDOW_gp),  /* 64 cycles (1.95 ms) */
    WINDOW_128CLK_gc               = (WINDOW_128CLK_gv << FUSE_WINDOW_gp),  /* 128 cycles (3.9 ms) */
    WINDOW_256CLK_gc               = (WINDOW_256CLK_gv << FUSE_WINDOW_gp),  /* 256 cycles (7.8 ms) */
    WINDOW_512CLK_gc               = (WINDOW_512CLK_gv << FUSE_WINDOW_gp),  /* 512 cycles (15.625 ms) */
    WINDOW_1KCLK_gc                = (WINDOW_1KCLK_gv << FUSE_WINDOW_gp),  /* 1K cycles (31.25 ms) */
    WINDOW_2KCLK_gc                = (WINDOW_2KCLK_gv << FUSE_WINDOW_gp),  /* 2K cycles (62.5 ms) */
    WINDOW_4KCLK_gc                = (WINDOW_4KCLK_gv << FUSE_WINDOW_gp),  /* 4K cycles (125 ms) */
    WINDOW_8KCLK_gc                = (WINDOW_8KCLK_gv << FUSE_WINDOW_gp)   /* 8K cycles (250 ms) */
} WINDOW_t;

/*
--------------------------------------------------------------------------
GPR - General Purpose Registers
--------------------------------------------------------------------------
*/

/* General Purpose Registers */
typedef struct GPR_struct
{
    register8_t GPR0;  /* General Purpose Register 0 */
    register8_t GPR1;  /* General Purpose Register 1 */
    register8_t GPR2;  /* General Purpose Register 2 */
    register8_t GPR3;  /* General Purpose Register 3 */
} GPR_t;


/*
--------------------------------------------------------------------------
LOCK - Lockbits
--------------------------------------------------------------------------
*/

/* Lockbits */
typedef struct LOCK_struct
{
    _DWORDREGISTER(KEY);  /* Lock Key Bits */
} LOCK_t;

/* Lock Key select bit group values */
typedef enum LOCK_KEY_VALUES_enum
{
    LOCK_KEY_RWLOCK_gv             = 0x00,  /*  */
    LOCK_KEY_NOLOCK_gv             = 0x5CC5C55C   /* No locks */
} LOCK_KEY_values_t;

/* Lock Key select bit group configurations*/
typedef enum LOCK_KEY_enum
{
    LOCK_KEY_RWLOCK_gc             = (LOCK_KEY_RWLOCK_gv << LOCK_KEY_gp),  /*  */
    LOCK_KEY_NOLOCK_gc             = (LOCK_KEY_NOLOCK_gv << LOCK_KEY_gp)   /* No locks */
} LOCK_KEY_t;

/*
--------------------------------------------------------------------------
MVIO - Multi-Voltage I/O
--------------------------------------------------------------------------
*/

/* Multi-Voltage I/O */
typedef struct MVIO_struct
{
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[1];
} MVIO_t;


/*
--------------------------------------------------------------------------
NVMCTRL - Non-volatile Memory Controller
--------------------------------------------------------------------------
*/

/* Non-volatile Memory Controller */
typedef struct NVMCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t INTCTRLA;  /* Interrupt Control A */
    register8_t INTFLAGSA;  /* Interrupt Flags A */
    register8_t INTFLAGSB;  /* Interrupt Flags B */
    register8_t STATUS;  /* Status */
    _DWORDREGISTER(DATA);  /* Data */
    _DWORDREGISTER(ADDR);  /* Address */
    register8_t PARITY;  /* ECC Parity */
    register8_t SYNDROME;  /* ECC Syndrome */
    register8_t reserved_1[46];
} NVMCTRL_t;

/* Command select bit group values */
typedef enum NVMCTRL_CMD_VALUES_enum
{
    NVMCTRL_CMD_NOCMD_gv           = 0x00,  /* No Command */
    NVMCTRL_CMD_NOOP_gv            = 0x01,  /* No Operation */
    NVMCTRL_CMD_FLWR_gv            = 0x02,  /* Flash Write */
    NVMCTRL_CMD_FLPER_gv           = 0x08,  /* Flash Page Erase */
    NVMCTRL_CMD_FLMPER2_gv         = 0x09,  /* Flash Multi-Page Erase 2 pages */
    NVMCTRL_CMD_FLMPER4_gv         = 0x0A,  /* Flash Multi-Page Erase 4 pages */
    NVMCTRL_CMD_FLMPER8_gv         = 0x0B,  /* Flash Multi-Page Erase 8 pages */
    NVMCTRL_CMD_FLMPER16_gv        = 0x0C,  /* Flash Multi-Page Erase 16 pages */
    NVMCTRL_CMD_FLMPER32_gv        = 0x0D,  /* Flash Multi-Page Erase 32 pages */
    NVMCTRL_CMD_EEWR_gv            = 0x12,  /* EEPROM Write */
    NVMCTRL_CMD_EEERWR_gv          = 0x13,  /* EEPROM Erase and Write */
    NVMCTRL_CMD_EEBER_gv           = 0x18,  /* EEPROM Byte Erase */
    NVMCTRL_CMD_EEMBER2_gv         = 0x19,  /* EEPROM Multi-Byte Erase 2 bytes */
    NVMCTRL_CMD_EEMBER4_gv         = 0x1A,  /* EEPROM Multi-Byte Erase 4 bytes */
    NVMCTRL_CMD_EEMBER8_gv         = 0x1B,  /* EEPROM Multi-Byte Erase 8 bytes */
    NVMCTRL_CMD_EEMBER16_gv        = 0x1C,  /* EEPROM Multi-Byte Erase 16 bytes */
    NVMCTRL_CMD_EEMBER32_gv        = 0x1D,  /* EEPROM Multi-Byte Erase 32 bytes */
    NVMCTRL_CMD_CHER_gv            = 0x20,  /* Chip Erase Command */
    NVMCTRL_CMD_EECHER_gv          = 0x30   /* EEPROM Erase Command */
} NVMCTRL_CMD_values_t;

/* Command select bit group configurations*/
typedef enum NVMCTRL_CMD_enum
{
    NVMCTRL_CMD_NOCMD_gc           = (NVMCTRL_CMD_NOCMD_gv << NVMCTRL_CMD_gp),  /* No Command */
    NVMCTRL_CMD_NOOP_gc            = (NVMCTRL_CMD_NOOP_gv << NVMCTRL_CMD_gp),  /* No Operation */
    NVMCTRL_CMD_FLWR_gc            = (NVMCTRL_CMD_FLWR_gv << NVMCTRL_CMD_gp),  /* Flash Write */
    NVMCTRL_CMD_FLPER_gc           = (NVMCTRL_CMD_FLPER_gv << NVMCTRL_CMD_gp),  /* Flash Page Erase */
    NVMCTRL_CMD_FLMPER2_gc         = (NVMCTRL_CMD_FLMPER2_gv << NVMCTRL_CMD_gp),  /* Flash Multi-Page Erase 2 pages */
    NVMCTRL_CMD_FLMPER4_gc         = (NVMCTRL_CMD_FLMPER4_gv << NVMCTRL_CMD_gp),  /* Flash Multi-Page Erase 4 pages */
    NVMCTRL_CMD_FLMPER8_gc         = (NVMCTRL_CMD_FLMPER8_gv << NVMCTRL_CMD_gp),  /* Flash Multi-Page Erase 8 pages */
    NVMCTRL_CMD_FLMPER16_gc        = (NVMCTRL_CMD_FLMPER16_gv << NVMCTRL_CMD_gp),  /* Flash Multi-Page Erase 16 pages */
    NVMCTRL_CMD_FLMPER32_gc        = (NVMCTRL_CMD_FLMPER32_gv << NVMCTRL_CMD_gp),  /* Flash Multi-Page Erase 32 pages */
    NVMCTRL_CMD_EEWR_gc            = (NVMCTRL_CMD_EEWR_gv << NVMCTRL_CMD_gp),  /* EEPROM Write */
    NVMCTRL_CMD_EEERWR_gc          = (NVMCTRL_CMD_EEERWR_gv << NVMCTRL_CMD_gp),  /* EEPROM Erase and Write */
    NVMCTRL_CMD_EEBER_gc           = (NVMCTRL_CMD_EEBER_gv << NVMCTRL_CMD_gp),  /* EEPROM Byte Erase */
    NVMCTRL_CMD_EEMBER2_gc         = (NVMCTRL_CMD_EEMBER2_gv << NVMCTRL_CMD_gp),  /* EEPROM Multi-Byte Erase 2 bytes */
    NVMCTRL_CMD_EEMBER4_gc         = (NVMCTRL_CMD_EEMBER4_gv << NVMCTRL_CMD_gp),  /* EEPROM Multi-Byte Erase 4 bytes */
    NVMCTRL_CMD_EEMBER8_gc         = (NVMCTRL_CMD_EEMBER8_gv << NVMCTRL_CMD_gp),  /* EEPROM Multi-Byte Erase 8 bytes */
    NVMCTRL_CMD_EEMBER16_gc        = (NVMCTRL_CMD_EEMBER16_gv << NVMCTRL_CMD_gp),  /* EEPROM Multi-Byte Erase 16 bytes */
    NVMCTRL_CMD_EEMBER32_gc        = (NVMCTRL_CMD_EEMBER32_gv << NVMCTRL_CMD_gp),  /* EEPROM Multi-Byte Erase 32 bytes */
    NVMCTRL_CMD_CHER_gc            = (NVMCTRL_CMD_CHER_gv << NVMCTRL_CMD_gp),  /* Chip Erase Command */
    NVMCTRL_CMD_EECHER_gc          = (NVMCTRL_CMD_EECHER_gv << NVMCTRL_CMD_gp)   /* EEPROM Erase Command */
} NVMCTRL_CMD_t;

/* Erased Flash ECC check select bit group values */
typedef enum NVMCTRL_ECCALL1_VALUES_enum
{
    NVMCTRL_ECCALL1_CHECKALL_gv    = 0x00,  /* ECC check on all flash words including those read as all-ones. */
    NVMCTRL_ECCALL1_DISALL_gv      = 0x01,  /* Disregard ECC check on flash words read as all-ones from the entire flash. */
    NVMCTRL_ECCALL1_DISAPPDATA_gv  = 0x02,  /* Disregard ECC check on flash words read as all-ones from from the APPDATA section or USER row */
    NVMCTRL_ECCALL1_DISAPPDATAEE_gv = 0x03   /* Disregard ECC check on EEPROM bytes read as all-ones, and flash words read as all-ones from the APPDATA section, USER row, or BOOTROW */
} NVMCTRL_ECCALL1_values_t;

/* Erased Flash ECC check select bit group configurations*/
typedef enum NVMCTRL_ECCALL1_enum
{
    NVMCTRL_ECCALL1_CHECKALL_gc    = (NVMCTRL_ECCALL1_CHECKALL_gv << NVMCTRL_ECCALL1_gp),  /* ECC check on all flash words including those read as all-ones. */
    NVMCTRL_ECCALL1_DISALL_gc      = (NVMCTRL_ECCALL1_DISALL_gv << NVMCTRL_ECCALL1_gp),  /* Disregard ECC check on flash words read as all-ones from the entire flash. */
    NVMCTRL_ECCALL1_DISAPPDATA_gc  = (NVMCTRL_ECCALL1_DISAPPDATA_gv << NVMCTRL_ECCALL1_gp),  /* Disregard ECC check on flash words read as all-ones from from the APPDATA section or USER row */
    NVMCTRL_ECCALL1_DISAPPDATAEE_gc = (NVMCTRL_ECCALL1_DISAPPDATAEE_gv << NVMCTRL_ECCALL1_gp)   /* Disregard ECC check on EEPROM bytes read as all-ones, and flash words read as all-ones from the APPDATA section, USER row, or BOOTROW */
} NVMCTRL_ECCALL1_t;

/* Write error select bit group values */
typedef enum NVMCTRL_ERROR_VALUES_enum
{
    NVMCTRL_ERROR_NONE_gv          = 0x00,  /* No Error */
    NVMCTRL_ERROR_INVALIDCMD_gv    = 0x01,  /* Write command not selected or not valid */
    NVMCTRL_ERROR_WRITEPROTECT_gv  = 0x02,  /* Write to section not allowed */
    NVMCTRL_ERROR_CMDCOLLISION_gv  = 0x03   /* Selecting new write command while programming is ongoing */
} NVMCTRL_ERROR_values_t;

/* Write error select bit group configurations*/
typedef enum NVMCTRL_ERROR_enum
{
    NVMCTRL_ERROR_NONE_gc          = (NVMCTRL_ERROR_NONE_gv << NVMCTRL_ERROR_gp),  /* No Error */
    NVMCTRL_ERROR_INVALIDCMD_gc    = (NVMCTRL_ERROR_INVALIDCMD_gv << NVMCTRL_ERROR_gp),  /* Write command not selected or not valid */
    NVMCTRL_ERROR_WRITEPROTECT_gc  = (NVMCTRL_ERROR_WRITEPROTECT_gv << NVMCTRL_ERROR_gp),  /* Write to section not allowed */
    NVMCTRL_ERROR_CMDCOLLISION_gc  = (NVMCTRL_ERROR_CMDCOLLISION_gv << NVMCTRL_ERROR_gp)   /* Selecting new write command while programming is ongoing */
} NVMCTRL_ERROR_t;

/* Flash Mapping in Data space select bit group values */
typedef enum NVMCTRL_FLMAP_VALUES_enum
{
    NVMCTRL_FLMAP_SECTION0_gv      = 0x00,  /* Flash section 0 */
    NVMCTRL_FLMAP_SECTION1_gv      = 0x01,  /* Flash section 1 */
    NVMCTRL_FLMAP_SECTION2_gv      = 0x02,  /* Flash section 2 */
    NVMCTRL_FLMAP_SECTION3_gv      = 0x03   /* Flash section 3 */
} NVMCTRL_FLMAP_values_t;

/* Flash Mapping in Data space select bit group configurations*/
typedef enum NVMCTRL_FLMAP_enum
{
    NVMCTRL_FLMAP_SECTION0_gc      = (NVMCTRL_FLMAP_SECTION0_gv << NVMCTRL_FLMAP_gp),  /* Flash section 0 */
    NVMCTRL_FLMAP_SECTION1_gc      = (NVMCTRL_FLMAP_SECTION1_gv << NVMCTRL_FLMAP_gp),  /* Flash section 1 */
    NVMCTRL_FLMAP_SECTION2_gc      = (NVMCTRL_FLMAP_SECTION2_gv << NVMCTRL_FLMAP_gp),  /* Flash section 2 */
    NVMCTRL_FLMAP_SECTION3_gc      = (NVMCTRL_FLMAP_SECTION3_gv << NVMCTRL_FLMAP_gp)   /* Flash section 3 */
} NVMCTRL_FLMAP_t;

/*
--------------------------------------------------------------------------
PORT - I/O Ports
--------------------------------------------------------------------------
*/

/* I/O Ports */
typedef struct PORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t DIRSET;  /* Data Direction Set */
    register8_t DIRCLR;  /* Data Direction Clear */
    register8_t DIRTGL;  /* Data Direction Toggle */
    register8_t OUT;  /* Output Value */
    register8_t OUTSET;  /* Output Value Set */
    register8_t OUTCLR;  /* Output Value Clear */
    register8_t OUTTGL;  /* Output Value Toggle */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t PORTCTRL;  /* Port Control */
    register8_t PINCONFIG;  /* Pin Control Config */
    register8_t PINCTRLUPD;  /* Pin Control Update */
    register8_t PINCTRLSET;  /* Pin Control Set */
    register8_t PINCTRLCLR;  /* Pin Control Clear */
    register8_t reserved_1[1];
    register8_t PIN0CTRL;  /* Pin 0 Control */
    register8_t PIN1CTRL;  /* Pin 1 Control */
    register8_t PIN2CTRL;  /* Pin 2 Control */
    register8_t PIN3CTRL;  /* Pin 3 Control */
    register8_t PIN4CTRL;  /* Pin 4 Control */
    register8_t PIN5CTRL;  /* Pin 5 Control */
    register8_t PIN6CTRL;  /* Pin 6 Control */
    register8_t PIN7CTRL;  /* Pin 7 Control */
    register8_t EVGENCTRLA;  /* Event Generation Control A */
    register8_t reserved_2[7];
} PORT_t;

/* Event Generator 0 Select bit group values */
typedef enum PORT_EVGEN0SEL_VALUES_enum
{
    PORT_EVGEN0SEL_PIN0_gv         = 0x00,  /* Pin 0 used as event generator */
    PORT_EVGEN0SEL_PIN1_gv         = 0x01,  /* Pin 1 used as event generator */
    PORT_EVGEN0SEL_PIN2_gv         = 0x02,  /* Pin 2 used as event generator */
    PORT_EVGEN0SEL_PIN3_gv         = 0x03,  /* Pin 3 used as event generator */
    PORT_EVGEN0SEL_PIN4_gv         = 0x04,  /* Pin 4 used as event generator */
    PORT_EVGEN0SEL_PIN5_gv         = 0x05,  /* Pin 5 used as event generator */
    PORT_EVGEN0SEL_PIN6_gv         = 0x06,  /* Pin 6 used as event generator */
    PORT_EVGEN0SEL_PIN7_gv         = 0x07   /* Pin 7 used as event generator */
} PORT_EVGEN0SEL_values_t;

/* Event Generator 0 Select bit group configurations*/
typedef enum PORT_EVGEN0SEL_enum
{
    PORT_EVGEN0SEL_PIN0_gc         = (PORT_EVGEN0SEL_PIN0_gv << PORT_EVGEN0SEL_gp),  /* Pin 0 used as event generator */
    PORT_EVGEN0SEL_PIN1_gc         = (PORT_EVGEN0SEL_PIN1_gv << PORT_EVGEN0SEL_gp),  /* Pin 1 used as event generator */
    PORT_EVGEN0SEL_PIN2_gc         = (PORT_EVGEN0SEL_PIN2_gv << PORT_EVGEN0SEL_gp),  /* Pin 2 used as event generator */
    PORT_EVGEN0SEL_PIN3_gc         = (PORT_EVGEN0SEL_PIN3_gv << PORT_EVGEN0SEL_gp),  /* Pin 3 used as event generator */
    PORT_EVGEN0SEL_PIN4_gc         = (PORT_EVGEN0SEL_PIN4_gv << PORT_EVGEN0SEL_gp),  /* Pin 4 used as event generator */
    PORT_EVGEN0SEL_PIN5_gc         = (PORT_EVGEN0SEL_PIN5_gv << PORT_EVGEN0SEL_gp),  /* Pin 5 used as event generator */
    PORT_EVGEN0SEL_PIN6_gc         = (PORT_EVGEN0SEL_PIN6_gv << PORT_EVGEN0SEL_gp),  /* Pin 6 used as event generator */
    PORT_EVGEN0SEL_PIN7_gc         = (PORT_EVGEN0SEL_PIN7_gv << PORT_EVGEN0SEL_gp)   /* Pin 7 used as event generator */
} PORT_EVGEN0SEL_t;

/* Event Generator 1 Select bit group values */
typedef enum PORT_EVGEN1SEL_VALUES_enum
{
    PORT_EVGEN1SEL_PIN0_gv         = 0x00,  /* Pin 0 used as event generator */
    PORT_EVGEN1SEL_PIN1_gv         = 0x01,  /* Pin 1 used as event generator */
    PORT_EVGEN1SEL_PIN2_gv         = 0x02,  /* Pin 2 used as event generator */
    PORT_EVGEN1SEL_PIN3_gv         = 0x03,  /* Pin 3 used as event generator */
    PORT_EVGEN1SEL_PIN4_gv         = 0x04,  /* Pin 4 used as event generator */
    PORT_EVGEN1SEL_PIN5_gv         = 0x05,  /* Pin 5 used as event generator */
    PORT_EVGEN1SEL_PIN6_gv         = 0x06,  /* Pin 6 used as event generator */
    PORT_EVGEN1SEL_PIN7_gv         = 0x07   /* Pin 7 used as event generator */
} PORT_EVGEN1SEL_values_t;

/* Event Generator 1 Select bit group configurations*/
typedef enum PORT_EVGEN1SEL_enum
{
    PORT_EVGEN1SEL_PIN0_gc         = (PORT_EVGEN1SEL_PIN0_gv << PORT_EVGEN1SEL_gp),  /* Pin 0 used as event generator */
    PORT_EVGEN1SEL_PIN1_gc         = (PORT_EVGEN1SEL_PIN1_gv << PORT_EVGEN1SEL_gp),  /* Pin 1 used as event generator */
    PORT_EVGEN1SEL_PIN2_gc         = (PORT_EVGEN1SEL_PIN2_gv << PORT_EVGEN1SEL_gp),  /* Pin 2 used as event generator */
    PORT_EVGEN1SEL_PIN3_gc         = (PORT_EVGEN1SEL_PIN3_gv << PORT_EVGEN1SEL_gp),  /* Pin 3 used as event generator */
    PORT_EVGEN1SEL_PIN4_gc         = (PORT_EVGEN1SEL_PIN4_gv << PORT_EVGEN1SEL_gp),  /* Pin 4 used as event generator */
    PORT_EVGEN1SEL_PIN5_gc         = (PORT_EVGEN1SEL_PIN5_gv << PORT_EVGEN1SEL_gp),  /* Pin 5 used as event generator */
    PORT_EVGEN1SEL_PIN6_gc         = (PORT_EVGEN1SEL_PIN6_gv << PORT_EVGEN1SEL_gp),  /* Pin 6 used as event generator */
    PORT_EVGEN1SEL_PIN7_gc         = (PORT_EVGEN1SEL_PIN7_gv << PORT_EVGEN1SEL_gp)   /* Pin 7 used as event generator */
} PORT_EVGEN1SEL_t;

/* Input Level Select bit group values */
typedef enum PORT_INLVL_VALUES_enum
{
    PORT_INLVL_ST_gv               = 0x00,  /* Schmitt-Trigger input level */
    PORT_INLVL_TTL_gv              = 0x01   /* TTL Input level */
} PORT_INLVL_values_t;

/* Input Level Select bit group configurations*/
typedef enum PORT_INLVL_enum
{
    PORT_INLVL_ST_gc               = (PORT_INLVL_ST_gv << PORT_INLVL_bp),  /* Schmitt-Trigger input level */
    PORT_INLVL_TTL_gc              = (PORT_INLVL_TTL_gv << PORT_INLVL_bp)   /* TTL Input level */
} PORT_INLVL_t;

/* Input/Sense Configuration select bit group values */
typedef enum PORT_ISC_VALUES_enum
{
    PORT_ISC_INTDISABLE_gv         = 0x00,  /* Interrupt disabled but input buffer enabled */
    PORT_ISC_BOTHEDGES_gv          = 0x01,  /* Sense Both Edges */
    PORT_ISC_RISING_gv             = 0x02,  /* Sense Rising Edge */
    PORT_ISC_FALLING_gv            = 0x03,  /* Sense Falling Edge */
    PORT_ISC_INPUT_DISABLE_gv      = 0x04,  /* Digital Input Buffer disabled */
    PORT_ISC_LEVEL_gv              = 0x05   /* Sense low Level */
} PORT_ISC_values_t;

/* Input/Sense Configuration select bit group configurations*/
typedef enum PORT_ISC_enum
{
    PORT_ISC_INTDISABLE_gc         = (PORT_ISC_INTDISABLE_gv << PORT_ISC_gp),  /* Interrupt disabled but input buffer enabled */
    PORT_ISC_BOTHEDGES_gc          = (PORT_ISC_BOTHEDGES_gv << PORT_ISC_gp),  /* Sense Both Edges */
    PORT_ISC_RISING_gc             = (PORT_ISC_RISING_gv << PORT_ISC_gp),  /* Sense Rising Edge */
    PORT_ISC_FALLING_gc            = (PORT_ISC_FALLING_gv << PORT_ISC_gp),  /* Sense Falling Edge */
    PORT_ISC_INPUT_DISABLE_gc      = (PORT_ISC_INPUT_DISABLE_gv << PORT_ISC_gp),  /* Digital Input Buffer disabled */
    PORT_ISC_LEVEL_gc              = (PORT_ISC_LEVEL_gv << PORT_ISC_gp)   /* Sense low Level */
} PORT_ISC_t;

/*
--------------------------------------------------------------------------
PORTMUX - Port Multiplexer
--------------------------------------------------------------------------
*/

/* Port Multiplexer */
typedef struct PORTMUX_struct
{
    register8_t EVSYSROUTEA;  /* EVSYS route A */
    register8_t CCLROUTEA;  /* CCL route A */
    register8_t USARTROUTEA;  /* USART route A */
    register8_t reserved_1[2];
    register8_t SPIROUTEA;  /* SPI route A */
    register8_t TWIROUTEA;  /* TWI route A */
    register8_t TCAROUTEA;  /* TCA route A */
    register8_t TCBROUTEA;  /* TCB route A */
    register8_t TCDROUTEA;  /* TCD route A */
    register8_t ACROUTEA;  /* AC route A */
    register8_t ZCDROUTEA;  /* ZCD route A */
    register8_t reserved_2[1];
    register8_t ERRCTRLROUTEA;  /* Error Controller Route A */
    register8_t reserved_3[18];
} PORTMUX_t;

/* Analog Comparator 0 Output select bit group values */
typedef enum PORTMUX_AC0_VALUES_enum
{
    PORTMUX_AC0_DEFAULT_gv         = 0x00   /* OUT on PA7 */
} PORTMUX_AC0_values_t;

/* Analog Comparator 0 Output select bit group configurations*/
typedef enum PORTMUX_AC0_enum
{
    PORTMUX_AC0_DEFAULT_gc         = (PORTMUX_AC0_DEFAULT_gv << PORTMUX_AC0_bp)   /* OUT on PA7 */
} PORTMUX_AC0_t;

/* Analog Comparator 1 Output select bit group values */
typedef enum PORTMUX_AC1_VALUES_enum
{
    PORTMUX_AC1_DEFAULT_gv         = 0x00   /* OUT on PA7 */
} PORTMUX_AC1_values_t;

/* Analog Comparator 1 Output select bit group configurations*/
typedef enum PORTMUX_AC1_enum
{
    PORTMUX_AC1_DEFAULT_gc         = (PORTMUX_AC1_DEFAULT_gv << PORTMUX_AC1_bp)   /* OUT on PA7 */
} PORTMUX_AC1_t;

/* Analog Comparator 2 Output select bit group values */
typedef enum PORTMUX_AC2_VALUES_enum
{
    PORTMUX_AC2_DEFAULT_gv         = 0x00   /* OUT on PA7 */
} PORTMUX_AC2_values_t;

/* Analog Comparator 2 Output select bit group configurations*/
typedef enum PORTMUX_AC2_enum
{
    PORTMUX_AC2_DEFAULT_gc         = (PORTMUX_AC2_DEFAULT_gv << PORTMUX_AC2_bp)   /* OUT on PA7 */
} PORTMUX_AC2_t;

/* Event Output A select bit group values */
typedef enum PORTMUX_EVOUTA_VALUES_enum
{
    PORTMUX_EVOUTA_DEFAULT_gv      = 0x00,  /* EVOUT on PA2 */
    PORTMUX_EVOUTA_ALT1_gv         = 0x01   /* EVOUT on PA7 */
} PORTMUX_EVOUTA_values_t;

/* Event Output A select bit group configurations*/
typedef enum PORTMUX_EVOUTA_enum
{
    PORTMUX_EVOUTA_DEFAULT_gc      = (PORTMUX_EVOUTA_DEFAULT_gv << PORTMUX_EVOUTA_bp),  /* EVOUT on PA2 */
    PORTMUX_EVOUTA_ALT1_gc         = (PORTMUX_EVOUTA_ALT1_gv << PORTMUX_EVOUTA_bp)   /* EVOUT on PA7 */
} PORTMUX_EVOUTA_t;

/* Event Output C select bit group values */
typedef enum PORTMUX_EVOUTC_VALUES_enum
{
    PORTMUX_EVOUTC_DEFAULT_gv      = 0x00   /* EVOUT on PC2 */
} PORTMUX_EVOUTC_values_t;

/* Event Output C select bit group configurations*/
typedef enum PORTMUX_EVOUTC_enum
{
    PORTMUX_EVOUTC_DEFAULT_gc      = (PORTMUX_EVOUTC_DEFAULT_gv << PORTMUX_EVOUTC_bp)   /* EVOUT on PC2 */
} PORTMUX_EVOUTC_t;

/* Event Output D select bit group values */
typedef enum PORTMUX_EVOUTD_VALUES_enum
{
    PORTMUX_EVOUTD_DEFAULT_gv      = 0x00,  /* Not connected to any pins */
    PORTMUX_EVOUTD_ALT1_gv         = 0x01   /* EVOUT on PD7 */
} PORTMUX_EVOUTD_values_t;

/* Event Output D select bit group configurations*/
typedef enum PORTMUX_EVOUTD_enum
{
    PORTMUX_EVOUTD_DEFAULT_gc      = (PORTMUX_EVOUTD_DEFAULT_gv << PORTMUX_EVOUTD_bp),  /* Not connected to any pins */
    PORTMUX_EVOUTD_ALT1_gc         = (PORTMUX_EVOUTD_ALT1_gv << PORTMUX_EVOUTD_bp)   /* EVOUT on PD7 */
} PORTMUX_EVOUTD_t;

/* Error Controller Heartbeat Output select bit group values */
typedef enum PORTMUX_HEART_VALUES_enum
{
    PORTMUX_HEART_DEFAULT_gv       = 0x00,  /* HEART on PA2 */
    PORTMUX_HEART_ALT1_gv          = 0x01,  /* HEART on PA4 */
    PORTMUX_HEART_ALT2_gv          = 0x02,  /* HEART on PA6 */
    PORTMUX_HEART_ALT3_gv          = 0x03,  /* HEART on PA7 */
    PORTMUX_HEART_ALT4_gv          = 0x04   /* HEART on PD4 */
} PORTMUX_HEART_values_t;

/* Error Controller Heartbeat Output select bit group configurations*/
typedef enum PORTMUX_HEART_enum
{
    PORTMUX_HEART_DEFAULT_gc       = (PORTMUX_HEART_DEFAULT_gv << PORTMUX_HEART_gp),  /* HEART on PA2 */
    PORTMUX_HEART_ALT1_gc          = (PORTMUX_HEART_ALT1_gv << PORTMUX_HEART_gp),  /* HEART on PA4 */
    PORTMUX_HEART_ALT2_gc          = (PORTMUX_HEART_ALT2_gv << PORTMUX_HEART_gp),  /* HEART on PA6 */
    PORTMUX_HEART_ALT3_gc          = (PORTMUX_HEART_ALT3_gv << PORTMUX_HEART_gp),  /* HEART on PA7 */
    PORTMUX_HEART_ALT4_gc          = (PORTMUX_HEART_ALT4_gv << PORTMUX_HEART_gp)   /* HEART on PD4 */
} PORTMUX_HEART_t;

/* CCL Look-Up Table 0 Signals select bit group values */
typedef enum PORTMUX_LUT0_VALUES_enum
{
    PORTMUX_LUT0_DEFAULT_gv        = 0x00,  /* Out: PA3 In: PA0, PA1, PA2 */
    PORTMUX_LUT0_ALT1_gv           = 0x01   /* Out: PA6 In: PA0, PA1, PA2 */
} PORTMUX_LUT0_values_t;

/* CCL Look-Up Table 0 Signals select bit group configurations*/
typedef enum PORTMUX_LUT0_enum
{
    PORTMUX_LUT0_DEFAULT_gc        = (PORTMUX_LUT0_DEFAULT_gv << PORTMUX_LUT0_bp),  /* Out: PA3 In: PA0, PA1, PA2 */
    PORTMUX_LUT0_ALT1_gc           = (PORTMUX_LUT0_ALT1_gv << PORTMUX_LUT0_bp)   /* Out: PA6 In: PA0, PA1, PA2 */
} PORTMUX_LUT0_t;

/* CCL Look-Up Table 1 Signals select bit group values */
typedef enum PORTMUX_LUT1_VALUES_enum
{
    PORTMUX_LUT1_DEFAULT_gv        = 0x00,  /* Out: PC3 In: -, PC1, PC2 */
    PORTMUX_LUT1_ALT1_gv           = 0x01   /* Out: - In: -, PC1, PC2 */
} PORTMUX_LUT1_values_t;

/* CCL Look-Up Table 1 Signals select bit group configurations*/
typedef enum PORTMUX_LUT1_enum
{
    PORTMUX_LUT1_DEFAULT_gc        = (PORTMUX_LUT1_DEFAULT_gv << PORTMUX_LUT1_bp),  /* Out: PC3 In: -, PC1, PC2 */
    PORTMUX_LUT1_ALT1_gc           = (PORTMUX_LUT1_ALT1_gv << PORTMUX_LUT1_bp)   /* Out: - In: -, PC1, PC2 */
} PORTMUX_LUT1_t;

/* CCL Look-Up Table 2 Signals select bit group values */
typedef enum PORTMUX_LUT2_VALUES_enum
{
    PORTMUX_LUT2_DEFAULT_gv        = 0x00,  /* Not connected to any pins */
    PORTMUX_LUT2_ALT1_gv           = 0x01   /* Out: PD6 In: -, -, - */
} PORTMUX_LUT2_values_t;

/* CCL Look-Up Table 2 Signals select bit group configurations*/
typedef enum PORTMUX_LUT2_enum
{
    PORTMUX_LUT2_DEFAULT_gc        = (PORTMUX_LUT2_DEFAULT_gv << PORTMUX_LUT2_bp),  /* Not connected to any pins */
    PORTMUX_LUT2_ALT1_gc           = (PORTMUX_LUT2_ALT1_gv << PORTMUX_LUT2_bp)   /* Out: PD6 In: -, -, - */
} PORTMUX_LUT2_t;

/* SPI0 Signals select bit group values */
typedef enum PORTMUX_SPI0_VALUES_enum
{
    PORTMUX_SPI0_DEFAULT_gv        = 0x00,  /* PA4, PA5, PA6, PA7 */
    PORTMUX_SPI0_ALT3_gv           = 0x03,  /* PA0, PA1, -, PC1 */
    PORTMUX_SPI0_ALT4_gv           = 0x04,  /* PD4, PD5, PD6, PD7 */
    PORTMUX_SPI0_ALT5_gv           = 0x05,  /* -, PC1, PC2, PC3 */
    PORTMUX_SPI0_ALT6_gv           = 0x06,  /* PC1, PC2, PC3. SS Set to 1 */
    PORTMUX_SPI0_NONE_gv           = 0x07   /* MOSI, MISO, SCK: N/A. SS Set to 1 */
} PORTMUX_SPI0_values_t;

/* SPI0 Signals select bit group configurations*/
typedef enum PORTMUX_SPI0_enum
{
    PORTMUX_SPI0_DEFAULT_gc        = (PORTMUX_SPI0_DEFAULT_gv << PORTMUX_SPI0_gp),  /* PA4, PA5, PA6, PA7 */
    PORTMUX_SPI0_ALT3_gc           = (PORTMUX_SPI0_ALT3_gv << PORTMUX_SPI0_gp),  /* PA0, PA1, -, PC1 */
    PORTMUX_SPI0_ALT4_gc           = (PORTMUX_SPI0_ALT4_gv << PORTMUX_SPI0_gp),  /* PD4, PD5, PD6, PD7 */
    PORTMUX_SPI0_ALT5_gc           = (PORTMUX_SPI0_ALT5_gv << PORTMUX_SPI0_gp),  /* -, PC1, PC2, PC3 */
    PORTMUX_SPI0_ALT6_gc           = (PORTMUX_SPI0_ALT6_gv << PORTMUX_SPI0_gp),  /* PC1, PC2, PC3. SS Set to 1 */
    PORTMUX_SPI0_NONE_gc           = (PORTMUX_SPI0_NONE_gv << PORTMUX_SPI0_gp)   /* MOSI, MISO, SCK: N/A. SS Set to 1 */
} PORTMUX_SPI0_t;

/* SPI1 Signals select bit group values */
typedef enum PORTMUX_SPI1_VALUES_enum
{
    PORTMUX_SPI1_DEFAULT_gv        = 0x00,  /* -, PC1, PC2, PC3 */
    PORTMUX_SPI1_NONE_gv           = 0x07   /* MOSI, MISO, SCK: N/A. SS Set to 1 */
} PORTMUX_SPI1_values_t;

/* SPI1 Signals select bit group configurations*/
typedef enum PORTMUX_SPI1_enum
{
    PORTMUX_SPI1_DEFAULT_gc        = (PORTMUX_SPI1_DEFAULT_gv << PORTMUX_SPI1_gp),  /* -, PC1, PC2, PC3 */
    PORTMUX_SPI1_NONE_gc           = (PORTMUX_SPI1_NONE_gv << PORTMUX_SPI1_gp)   /* MOSI, MISO, SCK: N/A. SS Set to 1 */
} PORTMUX_SPI1_t;

/* TCA0 Signals select bit group values */
typedef enum PORTMUX_TCA0_VALUES_enum
{
    PORTMUX_TCA0_PORTA_gv          = 0x00,  /* PA0, PA1, PA2, PA3, PA4, PA5 */
    PORTMUX_TCA0_PORTC_gv          = 0x02,  /* -, PC1, PC2, PC3, -, - */
    PORTMUX_TCA0_PORTD_gv          = 0x03   /* -, -, -, -, PD4, PD5 */
} PORTMUX_TCA0_values_t;

/* TCA0 Signals select bit group configurations*/
typedef enum PORTMUX_TCA0_enum
{
    PORTMUX_TCA0_PORTA_gc          = (PORTMUX_TCA0_PORTA_gv << PORTMUX_TCA0_gp),  /* PA0, PA1, PA2, PA3, PA4, PA5 */
    PORTMUX_TCA0_PORTC_gc          = (PORTMUX_TCA0_PORTC_gv << PORTMUX_TCA0_gp),  /* -, PC1, PC2, PC3, -, - */
    PORTMUX_TCA0_PORTD_gc          = (PORTMUX_TCA0_PORTD_gv << PORTMUX_TCA0_gp)   /* -, -, -, -, PD4, PD5 */
} PORTMUX_TCA0_t;

/* TCB0 Output select bit group values */
typedef enum PORTMUX_TCB0_VALUES_enum
{
    PORTMUX_TCB0_DEFAULT_gv        = 0x00   /* WO on PA2 */
} PORTMUX_TCB0_values_t;

/* TCB0 Output select bit group configurations*/
typedef enum PORTMUX_TCB0_enum
{
    PORTMUX_TCB0_DEFAULT_gc        = (PORTMUX_TCB0_DEFAULT_gv << PORTMUX_TCB0_bp)   /* WO on PA2 */
} PORTMUX_TCB0_t;

/* TCB1 Output select bit group values */
typedef enum PORTMUX_TCB1_VALUES_enum
{
    PORTMUX_TCB1_DEFAULT_gv        = 0x00   /* WO on PA3 */
} PORTMUX_TCB1_values_t;

/* TCB1 Output select bit group configurations*/
typedef enum PORTMUX_TCB1_enum
{
    PORTMUX_TCB1_DEFAULT_gc        = (PORTMUX_TCB1_DEFAULT_gv << PORTMUX_TCB1_bp)   /* WO on PA3 */
} PORTMUX_TCB1_t;

/* TCB3 Output select bit group values */
typedef enum PORTMUX_TCB3_VALUES_enum
{
    PORTMUX_TCB3_DEFAULT_gv        = 0x00,  /* Not connected to any pins */
    PORTMUX_TCB3_ALT1_gv           = 0x01   /* WO on PC1 */
} PORTMUX_TCB3_values_t;

/* TCB3 Output select bit group configurations*/
typedef enum PORTMUX_TCB3_enum
{
    PORTMUX_TCB3_DEFAULT_gc        = (PORTMUX_TCB3_DEFAULT_gv << PORTMUX_TCB3_bp),  /* Not connected to any pins */
    PORTMUX_TCB3_ALT1_gc           = (PORTMUX_TCB3_ALT1_gv << PORTMUX_TCB3_bp)   /* WO on PC1 */
} PORTMUX_TCB3_t;

/* TCD0 Signals select bit group values */
typedef enum PORTMUX_TCD0_VALUES_enum
{
    PORTMUX_TCD0_DEFAULT_gv        = 0x00,  /* PA4, PA5, PA6, PA7 */
    PORTMUX_TCD0_ALT4_gv           = 0x04   /* PA4, PA5, PD4, PD5 */
} PORTMUX_TCD0_values_t;

/* TCD0 Signals select bit group configurations*/
typedef enum PORTMUX_TCD0_enum
{
    PORTMUX_TCD0_DEFAULT_gc        = (PORTMUX_TCD0_DEFAULT_gv << PORTMUX_TCD0_gp),  /* PA4, PA5, PA6, PA7 */
    PORTMUX_TCD0_ALT4_gc           = (PORTMUX_TCD0_ALT4_gv << PORTMUX_TCD0_gp)   /* PA4, PA5, PD4, PD5 */
} PORTMUX_TCD0_t;

/* TWI0 Signals select bit group values */
typedef enum PORTMUX_TWI0_VALUES_enum
{
    PORTMUX_TWI0_DEFAULT_gv        = 0x00,  /* PA2, PA3, PC2, PC3 */
    PORTMUX_TWI0_ALT1_gv           = 0x01,  /* PA2, PA3, -, - */
    PORTMUX_TWI0_ALT2_gv           = 0x02,  /* PC2, PC3, -, - */
    PORTMUX_TWI0_ALT3_gv           = 0x03   /* PA0, PA1, PC2, PC3 */
} PORTMUX_TWI0_values_t;

/* TWI0 Signals select bit group configurations*/
typedef enum PORTMUX_TWI0_enum
{
    PORTMUX_TWI0_DEFAULT_gc        = (PORTMUX_TWI0_DEFAULT_gv << PORTMUX_TWI0_gp),  /* PA2, PA3, PC2, PC3 */
    PORTMUX_TWI0_ALT1_gc           = (PORTMUX_TWI0_ALT1_gv << PORTMUX_TWI0_gp),  /* PA2, PA3, -, - */
    PORTMUX_TWI0_ALT2_gc           = (PORTMUX_TWI0_ALT2_gv << PORTMUX_TWI0_gp),  /* PC2, PC3, -, - */
    PORTMUX_TWI0_ALT3_gc           = (PORTMUX_TWI0_ALT3_gv << PORTMUX_TWI0_gp)   /* PA0, PA1, PC2, PC3 */
} PORTMUX_TWI0_t;

/* USART0 Signals select bit group values */
typedef enum PORTMUX_USART0_VALUES_enum
{
    PORTMUX_USART0_DEFAULT_gv      = 0x00,  /* PA0, PA1, PA2, PA3 */
    PORTMUX_USART0_ALT1_gv         = 0x01,  /* PA4, PA5, PA6, PA7 */
    PORTMUX_USART0_ALT2_gv         = 0x02,  /* PA2, PA3 */
    PORTMUX_USART0_ALT3_gv         = 0x03,  /* PD4, PD5, PD6, PD7 */
    PORTMUX_USART0_ALT4_gv         = 0x04,  /* PC1, PC2, PC3 */
    PORTMUX_USART0_NONE_gv         = 0x05   /* Not connected to any pins */
} PORTMUX_USART0_values_t;

/* USART0 Signals select bit group configurations*/
typedef enum PORTMUX_USART0_enum
{
    PORTMUX_USART0_DEFAULT_gc      = (PORTMUX_USART0_DEFAULT_gv << PORTMUX_USART0_gp),  /* PA0, PA1, PA2, PA3 */
    PORTMUX_USART0_ALT1_gc         = (PORTMUX_USART0_ALT1_gv << PORTMUX_USART0_gp),  /* PA4, PA5, PA6, PA7 */
    PORTMUX_USART0_ALT2_gc         = (PORTMUX_USART0_ALT2_gv << PORTMUX_USART0_gp),  /* PA2, PA3 */
    PORTMUX_USART0_ALT3_gc         = (PORTMUX_USART0_ALT3_gv << PORTMUX_USART0_gp),  /* PD4, PD5, PD6, PD7 */
    PORTMUX_USART0_ALT4_gc         = (PORTMUX_USART0_ALT4_gv << PORTMUX_USART0_gp),  /* PC1, PC2, PC3 */
    PORTMUX_USART0_NONE_gc         = (PORTMUX_USART0_NONE_gv << PORTMUX_USART0_gp)   /* Not connected to any pins */
} PORTMUX_USART0_t;

/* USART1 Signals select bit group values */
typedef enum PORTMUX_USART1_VALUES_enum
{
    PORTMUX_USART1_DEFAULT_gv      = 0x00,  /* -, PC1, PC2, PC3 */
    PORTMUX_USART1_ALT2_gv         = 0x02,  /* PD6, PD7 */
    PORTMUX_USART1_NONE_gv         = 0x03   /* Not connected to any pins */
} PORTMUX_USART1_values_t;

/* USART1 Signals select bit group configurations*/
typedef enum PORTMUX_USART1_enum
{
    PORTMUX_USART1_DEFAULT_gc      = (PORTMUX_USART1_DEFAULT_gv << PORTMUX_USART1_gp),  /* -, PC1, PC2, PC3 */
    PORTMUX_USART1_ALT2_gc         = (PORTMUX_USART1_ALT2_gv << PORTMUX_USART1_gp),  /* PD6, PD7 */
    PORTMUX_USART1_NONE_gc         = (PORTMUX_USART1_NONE_gv << PORTMUX_USART1_gp)   /* Not connected to any pins */
} PORTMUX_USART1_t;

/* Zero Cross Detector 3 Output select bit group values */
typedef enum PORTMUX_ZCD3_VALUES_enum
{
    PORTMUX_ZCD3_DEFAULT_gv        = 0x00   /* OUT on PA7 */
} PORTMUX_ZCD3_values_t;

/* Zero Cross Detector 3 Output select bit group configurations*/
typedef enum PORTMUX_ZCD3_enum
{
    PORTMUX_ZCD3_DEFAULT_gc        = (PORTMUX_ZCD3_DEFAULT_gv << PORTMUX_ZCD3_bp)   /* OUT on PA7 */
} PORTMUX_ZCD3_t;

/*
--------------------------------------------------------------------------
RAMCTRL - RAM Controller
--------------------------------------------------------------------------
*/

/* RAM Controller */
typedef struct RAMCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t INTFLAGS;  /* Interrupt Flags */
    _WORDREGISTER(ADDR);  /* ECC Address */
    register8_t SYNDROME;  /* ECC Syndrome */
    register8_t reserved_1[11];
} RAMCTRL_t;


/*
--------------------------------------------------------------------------
RSTCTRL - Reset controller
--------------------------------------------------------------------------
*/

/* Reset controller */
typedef struct RSTCTRL_struct
{
    register8_t RSTFR;  /* Reset Flags */
    register8_t SWRR;  /* Software Reset */
    register8_t MCFLAGSA;  /* Machine Check Flags A */
    register8_t MCFLAGSB;  /* Machine Check Flags B */
    register8_t reserved_1[12];
} RSTCTRL_t;


/*
--------------------------------------------------------------------------
RTC - Real-Time Counter
--------------------------------------------------------------------------
*/

/* Real-Time Counter */
typedef struct RTC_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t STATUS;  /* Status */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t TEMP;  /* Temporary */
    register8_t DBGCTRL;  /* Debug control */
    register8_t reserved_1[1];
    register8_t CLKSEL;  /* Clock Select */
    _WORDREGISTER(CNT);  /* Counter */
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP);  /* Compare */
    register8_t reserved_2[2];
    register8_t PITCTRLA;  /* PIT Control A */
    register8_t PITSTATUS;  /* PIT Status */
    register8_t PITINTCTRL;  /* PIT Interrupt Control */
    register8_t PITINTFLAGS;  /* PIT Interrupt Flags */
    register8_t reserved_3[1];
    register8_t PITDBGCTRL;  /* PIT Debug control */
    register8_t PITEVGENCTRLA;  /* PIT Event Generation Control A */
    register8_t reserved_4[9];
} RTC_t;

/* Clock Select bit group values */
typedef enum RTC_CLKSEL_VALUES_enum
{
    RTC_CLKSEL_OSC32K_gv           = 0x00,  /* 32.768 kHz from OSC32K */
    RTC_CLKSEL_OSC1K_gv            = 0x01,  /* 1.024 kHz from OSC32K */
    RTC_CLKSEL_XTAL32K_gv          = 0x02,  /* 32.768 kHz from XOSC32K or external clock from XTAL32K1 pin */
    RTC_CLKSEL_EXTCLK_gv           = 0x03   /* External clock from XOSCHF or external clock from the XTALHF1 pin */
} RTC_CLKSEL_values_t;

/* Clock Select bit group configurations*/
typedef enum RTC_CLKSEL_enum
{
    RTC_CLKSEL_OSC32K_gc           = (RTC_CLKSEL_OSC32K_gv << RTC_CLKSEL_gp),  /* 32.768 kHz from OSC32K */
    RTC_CLKSEL_OSC1K_gc            = (RTC_CLKSEL_OSC1K_gv << RTC_CLKSEL_gp),  /* 1.024 kHz from OSC32K */
    RTC_CLKSEL_XTAL32K_gc          = (RTC_CLKSEL_XTAL32K_gv << RTC_CLKSEL_gp),  /* 32.768 kHz from XOSC32K or external clock from XTAL32K1 pin */
    RTC_CLKSEL_EXTCLK_gc           = (RTC_CLKSEL_EXTCLK_gv << RTC_CLKSEL_gp)   /* External clock from XOSCHF or external clock from the XTALHF1 pin */
} RTC_CLKSEL_t;

/* Event Generation 0 Select bit group values */
typedef enum RTC_EVGEN0SEL_VALUES_enum
{
    RTC_EVGEN0SEL_OFF_gv           = 0x00,  /* No Event Generated */
    RTC_EVGEN0SEL_DIV4_gv          = 0x01,  /* CLK_RTC divided by 4 */
    RTC_EVGEN0SEL_DIV8_gv          = 0x02,  /* CLK_RTC divided by 8 */
    RTC_EVGEN0SEL_DIV16_gv         = 0x03,  /* CLK_RTC divided by 16 */
    RTC_EVGEN0SEL_DIV32_gv         = 0x04,  /* CLK_RTC divided by 32 */
    RTC_EVGEN0SEL_DIV64_gv         = 0x05,  /* CLK_RTC divided by 64 */
    RTC_EVGEN0SEL_DIV128_gv        = 0x06,  /* CLK_RTC divided by 128 */
    RTC_EVGEN0SEL_DIV256_gv        = 0x07,  /* CLK_RTC divided by 256 */
    RTC_EVGEN0SEL_DIV512_gv        = 0x08,  /* CLK_RTC divided by 512 */
    RTC_EVGEN0SEL_DIV1024_gv       = 0x09,  /* CLK_RTC divided by 1024 */
    RTC_EVGEN0SEL_DIV2048_gv       = 0x0A,  /* CLK_RTC divided by 2048 */
    RTC_EVGEN0SEL_DIV4096_gv       = 0x0B,  /* CLK_RTC divided by 4096 */
    RTC_EVGEN0SEL_DIV8192_gv       = 0x0C,  /* CLK_RTC divided by 8192 */
    RTC_EVGEN0SEL_DIV16384_gv      = 0x0D,  /* CLK_RTC divided by 16384 */
    RTC_EVGEN0SEL_DIV32768_gv      = 0x0E   /* CLK_RTC divided by 32768 */
} RTC_EVGEN0SEL_values_t;

/* Event Generation 0 Select bit group configurations*/
typedef enum RTC_EVGEN0SEL_enum
{
    RTC_EVGEN0SEL_OFF_gc           = (RTC_EVGEN0SEL_OFF_gv << RTC_EVGEN0SEL_gp),  /* No Event Generated */
    RTC_EVGEN0SEL_DIV4_gc          = (RTC_EVGEN0SEL_DIV4_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 4 */
    RTC_EVGEN0SEL_DIV8_gc          = (RTC_EVGEN0SEL_DIV8_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 8 */
    RTC_EVGEN0SEL_DIV16_gc         = (RTC_EVGEN0SEL_DIV16_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 16 */
    RTC_EVGEN0SEL_DIV32_gc         = (RTC_EVGEN0SEL_DIV32_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 32 */
    RTC_EVGEN0SEL_DIV64_gc         = (RTC_EVGEN0SEL_DIV64_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 64 */
    RTC_EVGEN0SEL_DIV128_gc        = (RTC_EVGEN0SEL_DIV128_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 128 */
    RTC_EVGEN0SEL_DIV256_gc        = (RTC_EVGEN0SEL_DIV256_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 256 */
    RTC_EVGEN0SEL_DIV512_gc        = (RTC_EVGEN0SEL_DIV512_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 512 */
    RTC_EVGEN0SEL_DIV1024_gc       = (RTC_EVGEN0SEL_DIV1024_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 1024 */
    RTC_EVGEN0SEL_DIV2048_gc       = (RTC_EVGEN0SEL_DIV2048_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 2048 */
    RTC_EVGEN0SEL_DIV4096_gc       = (RTC_EVGEN0SEL_DIV4096_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 4096 */
    RTC_EVGEN0SEL_DIV8192_gc       = (RTC_EVGEN0SEL_DIV8192_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 8192 */
    RTC_EVGEN0SEL_DIV16384_gc      = (RTC_EVGEN0SEL_DIV16384_gv << RTC_EVGEN0SEL_gp),  /* CLK_RTC divided by 16384 */
    RTC_EVGEN0SEL_DIV32768_gc      = (RTC_EVGEN0SEL_DIV32768_gv << RTC_EVGEN0SEL_gp)   /* CLK_RTC divided by 32768 */
} RTC_EVGEN0SEL_t;

/* Event Generation 1 Select bit group values */
typedef enum RTC_EVGEN1SEL_VALUES_enum
{
    RTC_EVGEN1SEL_OFF_gv           = 0x00,  /* No Event Generated */
    RTC_EVGEN1SEL_DIV4_gv          = 0x01,  /* CLK_RTC divided by 4 */
    RTC_EVGEN1SEL_DIV8_gv          = 0x02,  /* CLK_RTC divided by 8 */
    RTC_EVGEN1SEL_DIV16_gv         = 0x03,  /* CLK_RTC divided by 16 */
    RTC_EVGEN1SEL_DIV32_gv         = 0x04,  /* CLK_RTC divided by 32 */
    RTC_EVGEN1SEL_DIV64_gv         = 0x05,  /* CLK_RTC divided by 64 */
    RTC_EVGEN1SEL_DIV128_gv        = 0x06,  /* CLK_RTC divided by 128 */
    RTC_EVGEN1SEL_DIV256_gv        = 0x07,  /* CLK_RTC divided by 256 */
    RTC_EVGEN1SEL_DIV512_gv        = 0x08,  /* CLK_RTC divided by 512 */
    RTC_EVGEN1SEL_DIV1024_gv       = 0x09,  /* CLK_RTC divided by 1024 */
    RTC_EVGEN1SEL_DIV2048_gv       = 0x0A,  /* CLK_RTC divided by 2048 */
    RTC_EVGEN1SEL_DIV4096_gv       = 0x0B,  /* CLK_RTC divided by 4096 */
    RTC_EVGEN1SEL_DIV8192_gv       = 0x0C,  /* CLK_RTC divided by 8192 */
    RTC_EVGEN1SEL_DIV16384_gv      = 0x0D,  /* CLK_RTC divided by 16384 */
    RTC_EVGEN1SEL_DIV32768_gv      = 0x0E   /* CLK_RTC divided by 32768 */
} RTC_EVGEN1SEL_values_t;

/* Event Generation 1 Select bit group configurations*/
typedef enum RTC_EVGEN1SEL_enum
{
    RTC_EVGEN1SEL_OFF_gc           = (RTC_EVGEN1SEL_OFF_gv << RTC_EVGEN1SEL_gp),  /* No Event Generated */
    RTC_EVGEN1SEL_DIV4_gc          = (RTC_EVGEN1SEL_DIV4_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 4 */
    RTC_EVGEN1SEL_DIV8_gc          = (RTC_EVGEN1SEL_DIV8_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 8 */
    RTC_EVGEN1SEL_DIV16_gc         = (RTC_EVGEN1SEL_DIV16_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 16 */
    RTC_EVGEN1SEL_DIV32_gc         = (RTC_EVGEN1SEL_DIV32_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 32 */
    RTC_EVGEN1SEL_DIV64_gc         = (RTC_EVGEN1SEL_DIV64_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 64 */
    RTC_EVGEN1SEL_DIV128_gc        = (RTC_EVGEN1SEL_DIV128_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 128 */
    RTC_EVGEN1SEL_DIV256_gc        = (RTC_EVGEN1SEL_DIV256_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 256 */
    RTC_EVGEN1SEL_DIV512_gc        = (RTC_EVGEN1SEL_DIV512_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 512 */
    RTC_EVGEN1SEL_DIV1024_gc       = (RTC_EVGEN1SEL_DIV1024_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 1024 */
    RTC_EVGEN1SEL_DIV2048_gc       = (RTC_EVGEN1SEL_DIV2048_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 2048 */
    RTC_EVGEN1SEL_DIV4096_gc       = (RTC_EVGEN1SEL_DIV4096_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 4096 */
    RTC_EVGEN1SEL_DIV8192_gc       = (RTC_EVGEN1SEL_DIV8192_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 8192 */
    RTC_EVGEN1SEL_DIV16384_gc      = (RTC_EVGEN1SEL_DIV16384_gv << RTC_EVGEN1SEL_gp),  /* CLK_RTC divided by 16384 */
    RTC_EVGEN1SEL_DIV32768_gc      = (RTC_EVGEN1SEL_DIV32768_gv << RTC_EVGEN1SEL_gp)   /* CLK_RTC divided by 32768 */
} RTC_EVGEN1SEL_t;

/* Period select bit group values */
typedef enum RTC_PERIOD_VALUES_enum
{
    RTC_PERIOD_OFF_gv              = 0x00,  /* Off */
    RTC_PERIOD_CYC4_gv             = 0x01,  /* RTC Clock Cycles 4 */
    RTC_PERIOD_CYC8_gv             = 0x02,  /* RTC Clock Cycles 8 */
    RTC_PERIOD_CYC16_gv            = 0x03,  /* RTC Clock Cycles 16 */
    RTC_PERIOD_CYC32_gv            = 0x04,  /* RTC Clock Cycles 32 */
    RTC_PERIOD_CYC64_gv            = 0x05,  /* RTC Clock Cycles 64 */
    RTC_PERIOD_CYC128_gv           = 0x06,  /* RTC Clock Cycles 128 */
    RTC_PERIOD_CYC256_gv           = 0x07,  /* RTC Clock Cycles 256 */
    RTC_PERIOD_CYC512_gv           = 0x08,  /* RTC Clock Cycles 512 */
    RTC_PERIOD_CYC1024_gv          = 0x09,  /* RTC Clock Cycles 1024 */
    RTC_PERIOD_CYC2048_gv          = 0x0A,  /* RTC Clock Cycles 2048 */
    RTC_PERIOD_CYC4096_gv          = 0x0B,  /* RTC Clock Cycles 4096 */
    RTC_PERIOD_CYC8192_gv          = 0x0C,  /* RTC Clock Cycles 8192 */
    RTC_PERIOD_CYC16384_gv         = 0x0D,  /* RTC Clock Cycles 16384 */
    RTC_PERIOD_CYC32768_gv         = 0x0E   /* RTC Clock Cycles 32768 */
} RTC_PERIOD_values_t;

/* Period select bit group configurations*/
typedef enum RTC_PERIOD_enum
{
    RTC_PERIOD_OFF_gc              = (RTC_PERIOD_OFF_gv << RTC_PERIOD_gp),  /* Off */
    RTC_PERIOD_CYC4_gc             = (RTC_PERIOD_CYC4_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 4 */
    RTC_PERIOD_CYC8_gc             = (RTC_PERIOD_CYC8_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 8 */
    RTC_PERIOD_CYC16_gc            = (RTC_PERIOD_CYC16_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 16 */
    RTC_PERIOD_CYC32_gc            = (RTC_PERIOD_CYC32_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 32 */
    RTC_PERIOD_CYC64_gc            = (RTC_PERIOD_CYC64_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 64 */
    RTC_PERIOD_CYC128_gc           = (RTC_PERIOD_CYC128_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 128 */
    RTC_PERIOD_CYC256_gc           = (RTC_PERIOD_CYC256_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 256 */
    RTC_PERIOD_CYC512_gc           = (RTC_PERIOD_CYC512_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 512 */
    RTC_PERIOD_CYC1024_gc          = (RTC_PERIOD_CYC1024_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 1024 */
    RTC_PERIOD_CYC2048_gc          = (RTC_PERIOD_CYC2048_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 2048 */
    RTC_PERIOD_CYC4096_gc          = (RTC_PERIOD_CYC4096_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 4096 */
    RTC_PERIOD_CYC8192_gc          = (RTC_PERIOD_CYC8192_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 8192 */
    RTC_PERIOD_CYC16384_gc         = (RTC_PERIOD_CYC16384_gv << RTC_PERIOD_gp),  /* RTC Clock Cycles 16384 */
    RTC_PERIOD_CYC32768_gc         = (RTC_PERIOD_CYC32768_gv << RTC_PERIOD_gp)   /* RTC Clock Cycles 32768 */
} RTC_PERIOD_t;

/* Prescaling Factor select bit group values */
typedef enum RTC_PRESCALER_VALUES_enum
{
    RTC_PRESCALER_DIV1_gv          = 0x00,  /* RTC Clock / 1 */
    RTC_PRESCALER_DIV2_gv          = 0x01,  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV4_gv          = 0x02,  /* RTC Clock / 4 */
    RTC_PRESCALER_DIV8_gv          = 0x03,  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gv         = 0x04,  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV32_gv         = 0x05,  /* RTC Clock / 32 */
    RTC_PRESCALER_DIV64_gv         = 0x06,  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV128_gv        = 0x07,  /* RTC Clock / 128 */
    RTC_PRESCALER_DIV256_gv        = 0x08,  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV512_gv        = 0x09,  /* RTC Clock / 512 */
    RTC_PRESCALER_DIV1024_gv       = 0x0A,  /* RTC Clock / 1024 */
    RTC_PRESCALER_DIV2048_gv       = 0x0B,  /* RTC Clock / 2048 */
    RTC_PRESCALER_DIV4096_gv       = 0x0C,  /* RTC Clock / 4096 */
    RTC_PRESCALER_DIV8192_gv       = 0x0D,  /* RTC Clock / 8192 */
    RTC_PRESCALER_DIV16384_gv      = 0x0E,  /* RTC Clock / 16384 */
    RTC_PRESCALER_DIV32768_gv      = 0x0F   /* RTC Clock / 32768 */
} RTC_PRESCALER_values_t;

/* Prescaling Factor select bit group configurations*/
typedef enum RTC_PRESCALER_enum
{
    RTC_PRESCALER_DIV1_gc          = (RTC_PRESCALER_DIV1_gv << RTC_PRESCALER_gp),  /* RTC Clock / 1 */
    RTC_PRESCALER_DIV2_gc          = (RTC_PRESCALER_DIV2_gv << RTC_PRESCALER_gp),  /* RTC Clock / 2 */
    RTC_PRESCALER_DIV4_gc          = (RTC_PRESCALER_DIV4_gv << RTC_PRESCALER_gp),  /* RTC Clock / 4 */
    RTC_PRESCALER_DIV8_gc          = (RTC_PRESCALER_DIV8_gv << RTC_PRESCALER_gp),  /* RTC Clock / 8 */
    RTC_PRESCALER_DIV16_gc         = (RTC_PRESCALER_DIV16_gv << RTC_PRESCALER_gp),  /* RTC Clock / 16 */
    RTC_PRESCALER_DIV32_gc         = (RTC_PRESCALER_DIV32_gv << RTC_PRESCALER_gp),  /* RTC Clock / 32 */
    RTC_PRESCALER_DIV64_gc         = (RTC_PRESCALER_DIV64_gv << RTC_PRESCALER_gp),  /* RTC Clock / 64 */
    RTC_PRESCALER_DIV128_gc        = (RTC_PRESCALER_DIV128_gv << RTC_PRESCALER_gp),  /* RTC Clock / 128 */
    RTC_PRESCALER_DIV256_gc        = (RTC_PRESCALER_DIV256_gv << RTC_PRESCALER_gp),  /* RTC Clock / 256 */
    RTC_PRESCALER_DIV512_gc        = (RTC_PRESCALER_DIV512_gv << RTC_PRESCALER_gp),  /* RTC Clock / 512 */
    RTC_PRESCALER_DIV1024_gc       = (RTC_PRESCALER_DIV1024_gv << RTC_PRESCALER_gp),  /* RTC Clock / 1024 */
    RTC_PRESCALER_DIV2048_gc       = (RTC_PRESCALER_DIV2048_gv << RTC_PRESCALER_gp),  /* RTC Clock / 2048 */
    RTC_PRESCALER_DIV4096_gc       = (RTC_PRESCALER_DIV4096_gv << RTC_PRESCALER_gp),  /* RTC Clock / 4096 */
    RTC_PRESCALER_DIV8192_gc       = (RTC_PRESCALER_DIV8192_gv << RTC_PRESCALER_gp),  /* RTC Clock / 8192 */
    RTC_PRESCALER_DIV16384_gc      = (RTC_PRESCALER_DIV16384_gv << RTC_PRESCALER_gp),  /* RTC Clock / 16384 */
    RTC_PRESCALER_DIV32768_gc      = (RTC_PRESCALER_DIV32768_gv << RTC_PRESCALER_gp)   /* RTC Clock / 32768 */
} RTC_PRESCALER_t;

/*
--------------------------------------------------------------------------
SIGROW - Signature row
--------------------------------------------------------------------------
*/

/* Signature row */
typedef struct SIGROW_struct
{
    register8_t DEVICEID0;  /* Device ID Byte 0 */
    register8_t DEVICEID1;  /* Device ID Byte 1 */
    register8_t DEVICEID2;  /* Device ID Byte 2 */
    register8_t reserved_1[1];
    _WORDREGISTER(TEMPSENSE0);  /* Temperature Calibration 0 */
    _WORDREGISTER(TEMPSENSE1);  /* Temperature Calibration 1 */
    register8_t reserved_2[8];
    register8_t SERNUM0;  /* LOTNUM0 */
    register8_t SERNUM1;  /* LOTNUM1 */
    register8_t SERNUM2;  /* LOTNUM2 */
    register8_t SERNUM3;  /* LOTNUM3 */
    register8_t SERNUM4;  /* LOTNUM4 */
    register8_t SERNUM5;  /* LOTNUM5 */
    register8_t SERNUM6;  /* RANDOM */
    register8_t SERNUM7;  /* SCRIBE */
    register8_t SERNUM8;  /* XPOS0 */
    register8_t SERNUM9;  /* XPOS1 */
    register8_t SERNUM10;  /* YPOS0 */
    register8_t SERNUM11;  /* YPOS1 */
    register8_t SERNUM12;  /* RES0 */
    register8_t SERNUM13;  /* RES1 */
    register8_t SERNUM14;  /* RES2 */
    register8_t SERNUM15;  /* RES3 */
    register8_t reserved_3[96];
} SIGROW_t;


/*
--------------------------------------------------------------------------
SLPCTRL - Sleep Controller
--------------------------------------------------------------------------
*/

/* Sleep Controller */
typedef struct SLPCTRL_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t VREGCTRL;  /* Voltage Regulator Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrup Status */
    register8_t reserved_1[11];
} SLPCTRL_t;

/* VMON Diagnostic Mode select bit group values */
typedef enum SLPCTRL_DMODE_VALUES_enum
{
    SLPCTRL_DMODE_NO_gv            = 0x00,  /* No VMON error should be detected */
    SLPCTRL_DMODE_UNDER_gv         = 0x01,  /* VMON Undervoltage error should be detected */
    SLPCTRL_DMODE_OVER_gv          = 0x02   /* VMON Overvoltage error should be detected */
} SLPCTRL_DMODE_values_t;

/* VMON Diagnostic Mode select bit group configurations*/
typedef enum SLPCTRL_DMODE_enum
{
    SLPCTRL_DMODE_NO_gc            = (SLPCTRL_DMODE_NO_gv << SLPCTRL_DMODE_gp),  /* No VMON error should be detected */
    SLPCTRL_DMODE_UNDER_gc         = (SLPCTRL_DMODE_UNDER_gv << SLPCTRL_DMODE_gp),  /* VMON Undervoltage error should be detected */
    SLPCTRL_DMODE_OVER_gc          = (SLPCTRL_DMODE_OVER_gv << SLPCTRL_DMODE_gp)   /* VMON Overvoltage error should be detected */
} SLPCTRL_DMODE_t;

/* Performance Mode select bit group values */
typedef enum SLPCTRL_PMODE_VALUES_enum
{
    SLPCTRL_PMODE_AUTO_gv          = 0x00,  /* Automatically switch from LDO to to ULP regulator in sleep and when running on 32.768 kHz oscillator */
    SLPCTRL_PMODE_FULL_gv          = 0x01   /* Run on LDO in all modes */
} SLPCTRL_PMODE_values_t;

/* Performance Mode select bit group configurations*/
typedef enum SLPCTRL_PMODE_enum
{
    SLPCTRL_PMODE_AUTO_gc          = (SLPCTRL_PMODE_AUTO_gv << SLPCTRL_PMODE_gp),  /* Automatically switch from LDO to to ULP regulator in sleep and when running on 32.768 kHz oscillator */
    SLPCTRL_PMODE_FULL_gc          = (SLPCTRL_PMODE_FULL_gv << SLPCTRL_PMODE_gp)   /* Run on LDO in all modes */
} SLPCTRL_PMODE_t;

/* Sleep mode select bit group values */
typedef enum SLPCTRL_SMODE_VALUES_enum
{
    SLPCTRL_SMODE_IDLE_gv          = 0x00,  /* Idle mode */
    SLPCTRL_SMODE_STDBY_gv         = 0x01,  /* Standby Mode */
    SLPCTRL_SMODE_PDOWN_gv         = 0x02   /* Power-down Mode */
} SLPCTRL_SMODE_values_t;

/* Sleep mode select bit group configurations*/
typedef enum SLPCTRL_SMODE_enum
{
    SLPCTRL_SMODE_IDLE_gc          = (SLPCTRL_SMODE_IDLE_gv << SLPCTRL_SMODE_gp),  /* Idle mode */
    SLPCTRL_SMODE_STDBY_gc         = (SLPCTRL_SMODE_STDBY_gv << SLPCTRL_SMODE_gp),  /* Standby Mode */
    SLPCTRL_SMODE_PDOWN_gc         = (SLPCTRL_SMODE_PDOWN_gv << SLPCTRL_SMODE_gp)   /* Power-down Mode */
} SLPCTRL_SMODE_t;

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_STANDBY (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
/* VMON Sleep Mode Enable select bit group values */
typedef enum SLPCTRL_VMONSEN_VALUES_enum
{
    SLPCTRL_VMONSEN_DISABLE_gv     = 0x00,  /* VMON disabled in STANDBY */
    SLPCTRL_VMONSEN_ENABLE_gv      = 0x01   /* VMON enabled in STANDBY */
} SLPCTRL_VMONSEN_values_t;

/* VMON Sleep Mode Enable select bit group configurations*/
typedef enum SLPCTRL_VMONSEN_enum
{
    SLPCTRL_VMONSEN_DISABLE_gc     = (SLPCTRL_VMONSEN_DISABLE_gv << SLPCTRL_VMONSEN_bp),  /* VMON disabled in STANDBY */
    SLPCTRL_VMONSEN_ENABLE_gc      = (SLPCTRL_VMONSEN_ENABLE_gv << SLPCTRL_VMONSEN_bp)   /* VMON enabled in STANDBY */
} SLPCTRL_VMONSEN_t;

/*
--------------------------------------------------------------------------
SPI - Serial Peripheral Interface
--------------------------------------------------------------------------
*/

/* Serial Peripheral Interface */
typedef struct SPI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t DATA;  /* Data */
    register8_t reserved_1[11];
} SPI_t;

/* SPI Mode select bit group values */
typedef enum SPI_MODE_VALUES_enum
{
    SPI_MODE_0_gv                  = 0x00,  /* SPI Mode 0 */
    SPI_MODE_1_gv                  = 0x01,  /* SPI Mode 1 */
    SPI_MODE_2_gv                  = 0x02,  /* SPI Mode 2 */
    SPI_MODE_3_gv                  = 0x03   /* SPI Mode 3 */
} SPI_MODE_values_t;

/* SPI Mode select bit group configurations*/
typedef enum SPI_MODE_enum
{
    SPI_MODE_0_gc                  = (SPI_MODE_0_gv << SPI_MODE_gp),  /* SPI Mode 0 */
    SPI_MODE_1_gc                  = (SPI_MODE_1_gv << SPI_MODE_gp),  /* SPI Mode 1 */
    SPI_MODE_2_gc                  = (SPI_MODE_2_gv << SPI_MODE_gp),  /* SPI Mode 2 */
    SPI_MODE_3_gc                  = (SPI_MODE_3_gv << SPI_MODE_gp)   /* SPI Mode 3 */
} SPI_MODE_t;

/* Prescaler select bit group values */
typedef enum SPI_PRESC_VALUES_enum
{
    SPI_PRESC_DIV4_gv              = 0x00,  /* CLK_PER / 4 */
    SPI_PRESC_DIV16_gv             = 0x01,  /* CLK_PER / 16 */
    SPI_PRESC_DIV64_gv             = 0x02,  /* CLK_PER / 64 */
    SPI_PRESC_DIV128_gv            = 0x03   /* CLK_PER / 128 */
} SPI_PRESC_values_t;

/* Prescaler select bit group configurations*/
typedef enum SPI_PRESC_enum
{
    SPI_PRESC_DIV4_gc              = (SPI_PRESC_DIV4_gv << SPI_PRESC_gp),  /* CLK_PER / 4 */
    SPI_PRESC_DIV16_gc             = (SPI_PRESC_DIV16_gv << SPI_PRESC_gp),  /* CLK_PER / 16 */
    SPI_PRESC_DIV64_gc             = (SPI_PRESC_DIV64_gv << SPI_PRESC_gp),  /* CLK_PER / 64 */
    SPI_PRESC_DIV128_gc            = (SPI_PRESC_DIV128_gv << SPI_PRESC_gp)   /* CLK_PER / 128 */
} SPI_PRESC_t;

/*
--------------------------------------------------------------------------
SWDT - Synchronous Watchdog Timer
--------------------------------------------------------------------------
*/

/* Synchronous Watchdog Timer */
typedef struct SWDT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    _DWORDREGISTER(CNT);  /* Counter */
    _DWORDREGISTER(RESET);  /* Counter Reset */
    _WORDREGISTER(WINDOW);  /* Counter Window */
    register8_t COMMAND;  /* Command */
    register8_t reserved_1[1];
} SWDT_t;

/* SWDT Command select bit group values */
typedef enum SWDT_COMMAND_VALUES_enum
{
    SWDT_COMMAND_PRECLEAR_gv       = 0x08,  /* Step 1 in the SWDT clear sequence */
    SWDT_COMMAND_CLEAR_gv          = 0x10   /* Step 2 in the SWDT clear sequence */
} SWDT_COMMAND_values_t;

/* SWDT Command select bit group configurations*/
typedef enum SWDT_COMMAND_enum
{
    SWDT_COMMAND_PRECLEAR_gc       = (SWDT_COMMAND_PRECLEAR_gv << SWDT_COMMAND_gp),  /* Step 1 in the SWDT clear sequence */
    SWDT_COMMAND_CLEAR_gc          = (SWDT_COMMAND_CLEAR_gv << SWDT_COMMAND_gp)   /* Step 2 in the SWDT clear sequence */
} SWDT_COMMAND_t;

/* Register Lock select bit group values */
typedef enum SWDT_LOCK_VALUES_enum
{
    SWDT_LOCK_UNLOCKED_gv          = 0x00,  /* SWDT SFRs are not LOCK-Protected */
    SWDT_LOCK_LOCKED_gv            = 0x01   /* SWDT SFRs are LOCK-Protected */
} SWDT_LOCK_values_t;

/* Register Lock select bit group configurations*/
typedef enum SWDT_LOCK_enum
{
    SWDT_LOCK_UNLOCKED_gc          = (SWDT_LOCK_UNLOCKED_gv << SWDT_LOCK_bp),  /* SWDT SFRs are not LOCK-Protected */
    SWDT_LOCK_LOCKED_gc            = (SWDT_LOCK_LOCKED_gv << SWDT_LOCK_bp)   /* SWDT SFRs are LOCK-Protected */
} SWDT_LOCK_t;

/* Peripheral Mode select bit group values */
typedef enum SWDT_MODE_VALUES_enum
{
    SWDT_MODE_CLOCK_gv             = 0x00,  /* SWDT counts clock cycles */
    SWDT_MODE_INSTRUCTION_gv       = 0x01   /* SWDT counts executed instructions */
} SWDT_MODE_values_t;

/* Peripheral Mode select bit group configurations*/
typedef enum SWDT_MODE_enum
{
    SWDT_MODE_CLOCK_gc             = (SWDT_MODE_CLOCK_gv << SWDT_MODE_bp),  /* SWDT counts clock cycles */
    SWDT_MODE_INSTRUCTION_gc       = (SWDT_MODE_INSTRUCTION_gv << SWDT_MODE_bp)   /* SWDT counts executed instructions */
} SWDT_MODE_t;

/*
--------------------------------------------------------------------------
SYSCFG - System Configuration Registers
--------------------------------------------------------------------------
*/

/* System Configuration Registers */
typedef struct SYSCFG_struct
{
    register8_t reserved_1[1];
    register8_t REVID;  /* Revision ID */
    register8_t reserved_2[126];
} SYSCFG_t;


/*
--------------------------------------------------------------------------
TCA - 16-bit Timer/Counter Type A
--------------------------------------------------------------------------
*/

/* 16-bit Timer/Counter Type A - Single Mode */
typedef struct TCA_SINGLE_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t CTRLFCLR;  /* Control F Clear */
    register8_t CTRLFSET;  /* Control F Set */
    register8_t reserved_1[1];
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary data for 16-bit Access */
    register8_t reserved_3[16];
    _WORDREGISTER(CNT);  /* Count */
    register8_t reserved_4[4];
    _WORDREGISTER(PER);  /* Period */
    _WORDREGISTER(CMP0);  /* Compare 0 */
    _WORDREGISTER(CMP1);  /* Compare 1 */
    _WORDREGISTER(CMP2);  /* Compare 2 */
    register8_t reserved_5[8];
    _WORDREGISTER(PERBUF);  /* Period Buffer */
    _WORDREGISTER(CMP0BUF);  /* Compare 0 Buffer */
    _WORDREGISTER(CMP1BUF);  /* Compare 1 Buffer */
    _WORDREGISTER(CMP2BUF);  /* Compare 2 Buffer */
    register8_t reserved_6[2];
} TCA_SINGLE_t;

/* 16-bit Timer/Counter Type A - Split Mode */
typedef struct TCA_SPLIT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLECLR;  /* Control E Clear */
    register8_t CTRLESET;  /* Control E Set */
    register8_t reserved_1[4];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t reserved_2[2];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_3[17];
    register8_t LCNT;  /* Low Count */
    register8_t HCNT;  /* High Count */
    register8_t reserved_4[4];
    register8_t LPER;  /* Low Period */
    register8_t HPER;  /* High Period */
    register8_t LCMP0;  /* Low Compare */
    register8_t HCMP0;  /* High Compare */
    register8_t LCMP1;  /* Low Compare */
    register8_t HCMP1;  /* High Compare */
    register8_t LCMP2;  /* Low Compare */
    register8_t HCMP2;  /* High Compare */
    register8_t reserved_5[18];
} TCA_SPLIT_t;

/* 16-bit Timer/Counter Type A */
typedef union TCA_union
{
    TCA_SINGLE_t SINGLE;  /* Single Mode */
    TCA_SPLIT_t SPLIT;  /* Split Mode */
} TCA_t;

/* Clock Selection bit group values */
typedef enum TCA_SINGLE_CLKSEL_VALUES_enum
{
    TCA_SINGLE_CLKSEL_DIV1_gv      = 0x00,  /* CLK_PER */
    TCA_SINGLE_CLKSEL_DIV2_gv      = 0x01,  /* CLK_PER / 2 */
    TCA_SINGLE_CLKSEL_DIV4_gv      = 0x02,  /* CLK_PER / 4 */
    TCA_SINGLE_CLKSEL_DIV8_gv      = 0x03,  /* CLK_PER / 8 */
    TCA_SINGLE_CLKSEL_DIV16_gv     = 0x04,  /* CLK_PER / 16 */
    TCA_SINGLE_CLKSEL_DIV64_gv     = 0x05,  /* CLK_PER / 64 */
    TCA_SINGLE_CLKSEL_DIV256_gv    = 0x06,  /* CLK_PER / 256 */
    TCA_SINGLE_CLKSEL_DIV1024_gv   = 0x07   /* CLK_PER / 1024 */
} TCA_SINGLE_CLKSEL_values_t;

/* Clock Selection bit group configurations*/
typedef enum TCA_SINGLE_CLKSEL_enum
{
    TCA_SINGLE_CLKSEL_DIV1_gc      = (TCA_SINGLE_CLKSEL_DIV1_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER */
    TCA_SINGLE_CLKSEL_DIV2_gc      = (TCA_SINGLE_CLKSEL_DIV2_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER / 2 */
    TCA_SINGLE_CLKSEL_DIV4_gc      = (TCA_SINGLE_CLKSEL_DIV4_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER / 4 */
    TCA_SINGLE_CLKSEL_DIV8_gc      = (TCA_SINGLE_CLKSEL_DIV8_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER / 8 */
    TCA_SINGLE_CLKSEL_DIV16_gc     = (TCA_SINGLE_CLKSEL_DIV16_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER / 16 */
    TCA_SINGLE_CLKSEL_DIV64_gc     = (TCA_SINGLE_CLKSEL_DIV64_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER / 64 */
    TCA_SINGLE_CLKSEL_DIV256_gc    = (TCA_SINGLE_CLKSEL_DIV256_gv << TCA_SINGLE_CLKSEL_gp),  /* CLK_PER / 256 */
    TCA_SINGLE_CLKSEL_DIV1024_gc   = (TCA_SINGLE_CLKSEL_DIV1024_gv << TCA_SINGLE_CLKSEL_gp)   /* CLK_PER / 1024 */
} TCA_SINGLE_CLKSEL_t;

/* Command select bit group values */
typedef enum TCA_SINGLE_CMD_VALUES_enum
{
    TCA_SINGLE_CMD_NONE_gv         = 0x00,  /* No Command */
    TCA_SINGLE_CMD_UPDATE_gv       = 0x01,  /* Force Update */
    TCA_SINGLE_CMD_RESTART_gv      = 0x02,  /* Force Restart */
    TCA_SINGLE_CMD_RESET_gv        = 0x03   /* Force Hard Reset */
} TCA_SINGLE_CMD_values_t;

/* Command select bit group configurations*/
typedef enum TCA_SINGLE_CMD_enum
{
    TCA_SINGLE_CMD_NONE_gc         = (TCA_SINGLE_CMD_NONE_gv << TCA_SINGLE_CMD_gp),  /* No Command */
    TCA_SINGLE_CMD_UPDATE_gc       = (TCA_SINGLE_CMD_UPDATE_gv << TCA_SINGLE_CMD_gp),  /* Force Update */
    TCA_SINGLE_CMD_RESTART_gc      = (TCA_SINGLE_CMD_RESTART_gv << TCA_SINGLE_CMD_gp),  /* Force Restart */
    TCA_SINGLE_CMD_RESET_gc        = (TCA_SINGLE_CMD_RESET_gv << TCA_SINGLE_CMD_gp)   /* Force Hard Reset */
} TCA_SINGLE_CMD_t;

/* Direction select bit group values */
typedef enum TCA_SINGLE_DIR_VALUES_enum
{
    TCA_SINGLE_DIR_UP_gv           = 0x00,  /* Count up */
    TCA_SINGLE_DIR_DOWN_gv         = 0x01   /* Count down */
} TCA_SINGLE_DIR_values_t;

/* Direction select bit group configurations*/
typedef enum TCA_SINGLE_DIR_enum
{
    TCA_SINGLE_DIR_UP_gc           = (TCA_SINGLE_DIR_UP_gv << TCA_SINGLE_DIR_bp),  /* Count up */
    TCA_SINGLE_DIR_DOWN_gc         = (TCA_SINGLE_DIR_DOWN_gv << TCA_SINGLE_DIR_bp)   /* Count down */
} TCA_SINGLE_DIR_t;

/* Event Action A select bit group values */
typedef enum TCA_SINGLE_EVACTA_VALUES_enum
{
    TCA_SINGLE_EVACTA_CNT_POSEDGE_gv = 0x00,  /* Count on positive edge event */
    TCA_SINGLE_EVACTA_CNT_ANYEDGE_gv = 0x01,  /* Count on any edge event */
    TCA_SINGLE_EVACTA_CNT_HIGHLVL_gv = 0x02,  /* Count on prescaled clock while event line is 1. */
    TCA_SINGLE_EVACTA_UPDOWN_gv    = 0x03   /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCA_SINGLE_EVACTA_values_t;

/* Event Action A select bit group configurations*/
typedef enum TCA_SINGLE_EVACTA_enum
{
    TCA_SINGLE_EVACTA_CNT_POSEDGE_gc = (TCA_SINGLE_EVACTA_CNT_POSEDGE_gv << TCA_SINGLE_EVACTA_gp),  /* Count on positive edge event */
    TCA_SINGLE_EVACTA_CNT_ANYEDGE_gc = (TCA_SINGLE_EVACTA_CNT_ANYEDGE_gv << TCA_SINGLE_EVACTA_gp),  /* Count on any edge event */
    TCA_SINGLE_EVACTA_CNT_HIGHLVL_gc = (TCA_SINGLE_EVACTA_CNT_HIGHLVL_gv << TCA_SINGLE_EVACTA_gp),  /* Count on prescaled clock while event line is 1. */
    TCA_SINGLE_EVACTA_UPDOWN_gc    = (TCA_SINGLE_EVACTA_UPDOWN_gv << TCA_SINGLE_EVACTA_gp)   /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCA_SINGLE_EVACTA_t;

/* Event Action B select bit group values */
typedef enum TCA_SINGLE_EVACTB_VALUES_enum
{
    TCA_SINGLE_EVACTB_NONE_gv      = 0x00,  /* No Action */
    TCA_SINGLE_EVACTB_UPDOWN_gv    = 0x03,  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
    TCA_SINGLE_EVACTB_RESTART_POSEDGE_gv = 0x04,  /* Restart counter at positive edge event */
    TCA_SINGLE_EVACTB_RESTART_ANYEDGE_gv = 0x05,  /* Restart counter on any edge event */
    TCA_SINGLE_EVACTB_RESTART_HIGHLVL_gv = 0x06   /* Restart counter while event line is 1. */
} TCA_SINGLE_EVACTB_values_t;

/* Event Action B select bit group configurations*/
typedef enum TCA_SINGLE_EVACTB_enum
{
    TCA_SINGLE_EVACTB_NONE_gc      = (TCA_SINGLE_EVACTB_NONE_gv << TCA_SINGLE_EVACTB_gp),  /* No Action */
    TCA_SINGLE_EVACTB_UPDOWN_gc    = (TCA_SINGLE_EVACTB_UPDOWN_gv << TCA_SINGLE_EVACTB_gp),  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
    TCA_SINGLE_EVACTB_RESTART_POSEDGE_gc = (TCA_SINGLE_EVACTB_RESTART_POSEDGE_gv << TCA_SINGLE_EVACTB_gp),  /* Restart counter at positive edge event */
    TCA_SINGLE_EVACTB_RESTART_ANYEDGE_gc = (TCA_SINGLE_EVACTB_RESTART_ANYEDGE_gv << TCA_SINGLE_EVACTB_gp),  /* Restart counter on any edge event */
    TCA_SINGLE_EVACTB_RESTART_HIGHLVL_gc = (TCA_SINGLE_EVACTB_RESTART_HIGHLVL_gv << TCA_SINGLE_EVACTB_gp)   /* Restart counter while event line is 1. */
} TCA_SINGLE_EVACTB_t;

/* Waveform generation mode select bit group values */
typedef enum TCA_SINGLE_WGMODE_VALUES_enum
{
    TCA_SINGLE_WGMODE_NORMAL_gv    = 0x00,  /* Normal Mode */
    TCA_SINGLE_WGMODE_FRQ_gv       = 0x01,  /* Frequency Generation Mode */
    TCA_SINGLE_WGMODE_SINGLESLOPE_gv = 0x03,  /* Single Slope PWM */
    TCA_SINGLE_WGMODE_DSTOP_gv     = 0x05,  /* Dual Slope PWM, overflow on TOP */
    TCA_SINGLE_WGMODE_DSBOTH_gv    = 0x06,  /* Dual Slope PWM, overflow on TOP and BOTTOM */
    TCA_SINGLE_WGMODE_DSBOTTOM_gv  = 0x07   /* Dual Slope PWM, overflow on BOTTOM */
} TCA_SINGLE_WGMODE_values_t;

/* Waveform generation mode select bit group configurations*/
typedef enum TCA_SINGLE_WGMODE_enum
{
    TCA_SINGLE_WGMODE_NORMAL_gc    = (TCA_SINGLE_WGMODE_NORMAL_gv << TCA_SINGLE_WGMODE_gp),  /* Normal Mode */
    TCA_SINGLE_WGMODE_FRQ_gc       = (TCA_SINGLE_WGMODE_FRQ_gv << TCA_SINGLE_WGMODE_gp),  /* Frequency Generation Mode */
    TCA_SINGLE_WGMODE_SINGLESLOPE_gc = (TCA_SINGLE_WGMODE_SINGLESLOPE_gv << TCA_SINGLE_WGMODE_gp),  /* Single Slope PWM */
    TCA_SINGLE_WGMODE_DSTOP_gc     = (TCA_SINGLE_WGMODE_DSTOP_gv << TCA_SINGLE_WGMODE_gp),  /* Dual Slope PWM, overflow on TOP */
    TCA_SINGLE_WGMODE_DSBOTH_gc    = (TCA_SINGLE_WGMODE_DSBOTH_gv << TCA_SINGLE_WGMODE_gp),  /* Dual Slope PWM, overflow on TOP and BOTTOM */
    TCA_SINGLE_WGMODE_DSBOTTOM_gc  = (TCA_SINGLE_WGMODE_DSBOTTOM_gv << TCA_SINGLE_WGMODE_gp)   /* Dual Slope PWM, overflow on BOTTOM */
} TCA_SINGLE_WGMODE_t;

/* Clock Selection bit group values */
typedef enum TCA_SPLIT_CLKSEL_VALUES_enum
{
    TCA_SPLIT_CLKSEL_DIV1_gv       = 0x00,  /* CLK_PER */
    TCA_SPLIT_CLKSEL_DIV2_gv       = 0x01,  /* CLK_PER / 2 */
    TCA_SPLIT_CLKSEL_DIV4_gv       = 0x02,  /* CLK_PER / 4 */
    TCA_SPLIT_CLKSEL_DIV8_gv       = 0x03,  /* CLK_PER / 8 */
    TCA_SPLIT_CLKSEL_DIV16_gv      = 0x04,  /* CLK_PER / 16 */
    TCA_SPLIT_CLKSEL_DIV64_gv      = 0x05,  /* CLK_PER / 64 */
    TCA_SPLIT_CLKSEL_DIV256_gv     = 0x06,  /* CLK_PER / 256 */
    TCA_SPLIT_CLKSEL_DIV1024_gv    = 0x07   /* CLK_PER / 1024 */
} TCA_SPLIT_CLKSEL_values_t;

/* Clock Selection bit group configurations*/
typedef enum TCA_SPLIT_CLKSEL_enum
{
    TCA_SPLIT_CLKSEL_DIV1_gc       = (TCA_SPLIT_CLKSEL_DIV1_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER */
    TCA_SPLIT_CLKSEL_DIV2_gc       = (TCA_SPLIT_CLKSEL_DIV2_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER / 2 */
    TCA_SPLIT_CLKSEL_DIV4_gc       = (TCA_SPLIT_CLKSEL_DIV4_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER / 4 */
    TCA_SPLIT_CLKSEL_DIV8_gc       = (TCA_SPLIT_CLKSEL_DIV8_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER / 8 */
    TCA_SPLIT_CLKSEL_DIV16_gc      = (TCA_SPLIT_CLKSEL_DIV16_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER / 16 */
    TCA_SPLIT_CLKSEL_DIV64_gc      = (TCA_SPLIT_CLKSEL_DIV64_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER / 64 */
    TCA_SPLIT_CLKSEL_DIV256_gc     = (TCA_SPLIT_CLKSEL_DIV256_gv << TCA_SPLIT_CLKSEL_gp),  /* CLK_PER / 256 */
    TCA_SPLIT_CLKSEL_DIV1024_gc    = (TCA_SPLIT_CLKSEL_DIV1024_gv << TCA_SPLIT_CLKSEL_gp)   /* CLK_PER / 1024 */
} TCA_SPLIT_CLKSEL_t;

/* Command select bit group values */
typedef enum TCA_SPLIT_CMD_VALUES_enum
{
    TCA_SPLIT_CMD_NONE_gv          = 0x00,  /* No Command */
    TCA_SPLIT_CMD_RESTART_gv       = 0x02,  /* Force Restart */
    TCA_SPLIT_CMD_RESET_gv         = 0x03   /* Force Hard Reset */
} TCA_SPLIT_CMD_values_t;

/* Command select bit group configurations*/
typedef enum TCA_SPLIT_CMD_enum
{
    TCA_SPLIT_CMD_NONE_gc          = (TCA_SPLIT_CMD_NONE_gv << TCA_SPLIT_CMD_gp),  /* No Command */
    TCA_SPLIT_CMD_RESTART_gc       = (TCA_SPLIT_CMD_RESTART_gv << TCA_SPLIT_CMD_gp),  /* Force Restart */
    TCA_SPLIT_CMD_RESET_gc         = (TCA_SPLIT_CMD_RESET_gv << TCA_SPLIT_CMD_gp)   /* Force Hard Reset */
} TCA_SPLIT_CMD_t;

/* Command Enable select bit group values */
typedef enum TCA_SPLIT_CMDEN_VALUES_enum
{
    TCA_SPLIT_CMDEN_NONE_gv        = 0x00,  /* None */
    TCA_SPLIT_CMDEN_BOTH_gv        = 0x03   /* Both low byte and high byte counter */
} TCA_SPLIT_CMDEN_values_t;

/* Command Enable select bit group configurations*/
typedef enum TCA_SPLIT_CMDEN_enum
{
    TCA_SPLIT_CMDEN_NONE_gc        = (TCA_SPLIT_CMDEN_NONE_gv << TCA_SPLIT_CMDEN_gp),  /* None */
    TCA_SPLIT_CMDEN_BOTH_gc        = (TCA_SPLIT_CMDEN_BOTH_gv << TCA_SPLIT_CMDEN_gp)   /* Both low byte and high byte counter */
} TCA_SPLIT_CMDEN_t;

/*
--------------------------------------------------------------------------
TCB - 16-bit Timer Type B
--------------------------------------------------------------------------
*/

/* 16-bit Timer Type B */
typedef struct TCB_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control Register B */
    register8_t reserved_1[2];
    register8_t EVCTRL;  /* Event Control */
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t TEMP;  /* Temporary Value */
    _WORDREGISTER(CNT);  /* Count */
    _WORDREGISTER(CCMP);  /* Compare or Capture */
    register8_t reserved_2[2];
} TCB_t;

/* Clock Select bit group values */
typedef enum TCB_CLKSEL_VALUES_enum
{
    TCB_CLKSEL_DIV1_gv             = 0x00,  /* CLK_PER */
    TCB_CLKSEL_DIV2_gv             = 0x01,  /* CLK_PER/2 */
    TCB_CLKSEL_TCA0_gv             = 0x02,  /* Use CLK_TCA from TCA0 */
    TCB_CLKSEL_EVENT_gv            = 0x07   /* Count on event edge */
} TCB_CLKSEL_values_t;

/* Clock Select bit group configurations*/
typedef enum TCB_CLKSEL_enum
{
    TCB_CLKSEL_DIV1_gc             = (TCB_CLKSEL_DIV1_gv << TCB_CLKSEL_gp),  /* CLK_PER */
    TCB_CLKSEL_DIV2_gc             = (TCB_CLKSEL_DIV2_gv << TCB_CLKSEL_gp),  /* CLK_PER/2 */
    TCB_CLKSEL_TCA0_gc             = (TCB_CLKSEL_TCA0_gv << TCB_CLKSEL_gp),  /* Use CLK_TCA from TCA0 */
    TCB_CLKSEL_EVENT_gc            = (TCB_CLKSEL_EVENT_gv << TCB_CLKSEL_gp)   /* Count on event edge */
} TCB_CLKSEL_t;

/* Timer Mode select bit group values */
typedef enum TCB_CNTMODE_VALUES_enum
{
    TCB_CNTMODE_INT_gv             = 0x00,  /* Periodic Interrupt */
    TCB_CNTMODE_TIMEOUT_gv         = 0x01,  /* Periodic Timeout */
    TCB_CNTMODE_CAPT_gv            = 0x02,  /* Input Capture Event */
    TCB_CNTMODE_FRQ_gv             = 0x03,  /* Input Capture Frequency measurement */
    TCB_CNTMODE_PW_gv              = 0x04,  /* Input Capture Pulse-Width measurement */
    TCB_CNTMODE_FRQPW_gv           = 0x05,  /* Input Capture Frequency and Pulse-Width measurement */
    TCB_CNTMODE_SINGLE_gv          = 0x06,  /* Single Shot */
    TCB_CNTMODE_PWM8_gv            = 0x07   /* 8-bit PWM */
} TCB_CNTMODE_values_t;

/* Timer Mode select bit group configurations*/
typedef enum TCB_CNTMODE_enum
{
    TCB_CNTMODE_INT_gc             = (TCB_CNTMODE_INT_gv << TCB_CNTMODE_gp),  /* Periodic Interrupt */
    TCB_CNTMODE_TIMEOUT_gc         = (TCB_CNTMODE_TIMEOUT_gv << TCB_CNTMODE_gp),  /* Periodic Timeout */
    TCB_CNTMODE_CAPT_gc            = (TCB_CNTMODE_CAPT_gv << TCB_CNTMODE_gp),  /* Input Capture Event */
    TCB_CNTMODE_FRQ_gc             = (TCB_CNTMODE_FRQ_gv << TCB_CNTMODE_gp),  /* Input Capture Frequency measurement */
    TCB_CNTMODE_PW_gc              = (TCB_CNTMODE_PW_gv << TCB_CNTMODE_gp),  /* Input Capture Pulse-Width measurement */
    TCB_CNTMODE_FRQPW_gc           = (TCB_CNTMODE_FRQPW_gv << TCB_CNTMODE_gp),  /* Input Capture Frequency and Pulse-Width measurement */
    TCB_CNTMODE_SINGLE_gc          = (TCB_CNTMODE_SINGLE_gv << TCB_CNTMODE_gp),  /* Single Shot */
    TCB_CNTMODE_PWM8_gc            = (TCB_CNTMODE_PWM8_gv << TCB_CNTMODE_gp)   /* 8-bit PWM */
} TCB_CNTMODE_t;

/*
--------------------------------------------------------------------------
TCD - Timer Counter D
--------------------------------------------------------------------------
*/

/* Timer Counter D */
typedef struct TCD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    register8_t CTRLD;  /* Control D */
    register8_t CTRLE;  /* Control E */
    register8_t reserved_1[3];
    register8_t EVCTRLA;  /* EVCTRLA */
    register8_t EVCTRLB;  /* EVCTRLB */
    register8_t reserved_2[2];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t INTFLAGS;  /* Interrupt Flags */
    register8_t STATUS;  /* Status */
    register8_t reserved_3[1];
    register8_t INPUTCTRLA;  /* Input Control A */
    register8_t INPUTCTRLB;  /* Input Control B */
    register8_t FAULTCTRL;  /* Fault Control */
    register8_t reserved_4[1];
    register8_t DLYCTRL;  /* Delay Control */
    register8_t DLYVAL;  /* Delay value */
    register8_t reserved_5[2];
    register8_t DITCTRL;  /* Dither Control A */
    register8_t DITVAL;  /* Dither value */
    register8_t reserved_6[4];
    register8_t DBGCTRL;  /* Debug Control */
    register8_t reserved_7[3];
    _WORDREGISTER(CAPTUREA);  /* Capture A */
    _WORDREGISTER(CAPTUREB);  /* Capture B */
    register8_t reserved_8[2];
    _WORDREGISTER(CMPASET);  /* Compare A Set */
    _WORDREGISTER(CMPACLR);  /* Compare A Clear */
    _WORDREGISTER(CMPBSET);  /* Compare B Set */
    _WORDREGISTER(CMPBCLR);  /* Compare B Clear */
    register8_t reserved_9[16];
} TCD_t;

/* Event action select bit group values */
typedef enum TCD_ACTION_VALUES_enum
{
    TCD_ACTION_FAULT_gv            = 0x00,  /* Event trigger a fault */
    TCD_ACTION_CAPTURE_gv          = 0x01   /* Event trigger a fault and capture */
} TCD_ACTION_values_t;

/* Event action select bit group configurations*/
typedef enum TCD_ACTION_enum
{
    TCD_ACTION_FAULT_gc            = (TCD_ACTION_FAULT_gv << TCD_ACTION_bp),  /* Event trigger a fault */
    TCD_ACTION_CAPTURE_gc          = (TCD_ACTION_CAPTURE_gv << TCD_ACTION_bp)   /* Event trigger a fault and capture */
} TCD_ACTION_t;

/* Event config select bit group values */
typedef enum TCD_CFG_VALUES_enum
{
    TCD_CFG_NEITHER_gv             = 0x00,  /* Neither Filter nor Asynchronous Event is enabled */
    TCD_CFG_FILTER_gv              = 0x01,  /* Input Capture Noise Cancellation Filter enabled */
    TCD_CFG_ASYNC_gv               = 0x02   /* Asynchronous Event output qualification enabled */
} TCD_CFG_values_t;

/* Event config select bit group configurations*/
typedef enum TCD_CFG_enum
{
    TCD_CFG_NEITHER_gc             = (TCD_CFG_NEITHER_gv << TCD_CFG_gp),  /* Neither Filter nor Asynchronous Event is enabled */
    TCD_CFG_FILTER_gc              = (TCD_CFG_FILTER_gv << TCD_CFG_gp),  /* Input Capture Noise Cancellation Filter enabled */
    TCD_CFG_ASYNC_gc               = (TCD_CFG_ASYNC_gv << TCD_CFG_gp)   /* Asynchronous Event output qualification enabled */
} TCD_CFG_t;

/* Clock select bit group values */
typedef enum TCD_CLKSEL_VALUES_enum
{
    TCD_CLKSEL_OSCHF_gv            = 0x00,  /* Internal High-Frequency oscillator */
    TCD_CLKSEL_PLL_gv              = 0x01,  /* PLL */
    TCD_CLKSEL_EXTCLK_gv           = 0x02,  /* External Clock */
    TCD_CLKSEL_CLKPER_gv           = 0x03   /* Peripheral Clock */
} TCD_CLKSEL_values_t;

/* Clock select bit group configurations*/
typedef enum TCD_CLKSEL_enum
{
    TCD_CLKSEL_OSCHF_gc            = (TCD_CLKSEL_OSCHF_gv << TCD_CLKSEL_gp),  /* Internal High-Frequency oscillator */
    TCD_CLKSEL_PLL_gc              = (TCD_CLKSEL_PLL_gv << TCD_CLKSEL_gp),  /* PLL */
    TCD_CLKSEL_EXTCLK_gc           = (TCD_CLKSEL_EXTCLK_gv << TCD_CLKSEL_gp),  /* External Clock */
    TCD_CLKSEL_CLKPER_gc           = (TCD_CLKSEL_CLKPER_gv << TCD_CLKSEL_gp)   /* Peripheral Clock */
} TCD_CLKSEL_t;

/* Compare C output select bit group values */
typedef enum TCD_CMPCSEL_VALUES_enum
{
    TCD_CMPCSEL_PWMA_gv            = 0x00,  /* PWM A output */
    TCD_CMPCSEL_PWMB_gv            = 0x01   /* PWM B output */
} TCD_CMPCSEL_values_t;

/* Compare C output select bit group configurations*/
typedef enum TCD_CMPCSEL_enum
{
    TCD_CMPCSEL_PWMA_gc            = (TCD_CMPCSEL_PWMA_gv << TCD_CMPCSEL_bp),  /* PWM A output */
    TCD_CMPCSEL_PWMB_gc            = (TCD_CMPCSEL_PWMB_gv << TCD_CMPCSEL_bp)   /* PWM B output */
} TCD_CMPCSEL_t;

/* Compare D output select bit group values */
typedef enum TCD_CMPDSEL_VALUES_enum
{
    TCD_CMPDSEL_PWMA_gv            = 0x00,  /* PWM A output */
    TCD_CMPDSEL_PWMB_gv            = 0x01   /* PWM B output */
} TCD_CMPDSEL_values_t;

/* Compare D output select bit group configurations*/
typedef enum TCD_CMPDSEL_enum
{
    TCD_CMPDSEL_PWMA_gc            = (TCD_CMPDSEL_PWMA_gv << TCD_CMPDSEL_bp),  /* PWM A output */
    TCD_CMPDSEL_PWMB_gc            = (TCD_CMPDSEL_PWMB_gv << TCD_CMPDSEL_bp)   /* PWM B output */
} TCD_CMPDSEL_t;

/* Counter prescaler select bit group values */
typedef enum TCD_CNTPRES_VALUES_enum
{
    TCD_CNTPRES_DIV1_gv            = 0x00,  /* Sync clock divided by 1 */
    TCD_CNTPRES_DIV4_gv            = 0x01,  /* Sync clock divided by 4 */
    TCD_CNTPRES_DIV32_gv           = 0x02   /* Sync clock divided by 32 */
} TCD_CNTPRES_values_t;

/* Counter prescaler select bit group configurations*/
typedef enum TCD_CNTPRES_enum
{
    TCD_CNTPRES_DIV1_gc            = (TCD_CNTPRES_DIV1_gv << TCD_CNTPRES_gp),  /* Sync clock divided by 1 */
    TCD_CNTPRES_DIV4_gc            = (TCD_CNTPRES_DIV4_gv << TCD_CNTPRES_gp),  /* Sync clock divided by 4 */
    TCD_CNTPRES_DIV32_gc           = (TCD_CNTPRES_DIV32_gv << TCD_CNTPRES_gp)   /* Sync clock divided by 32 */
} TCD_CNTPRES_t;

/* Dither select bit group values */
typedef enum TCD_DITHERSEL_VALUES_enum
{
    TCD_DITHERSEL_ONTIMEB_gv       = 0x00,  /* On-time ramp B */
    TCD_DITHERSEL_ONTIMEAB_gv      = 0x01,  /* On-time ramp A and B */
    TCD_DITHERSEL_DEADTIMEB_gv     = 0x02,  /* Dead-time rampB */
    TCD_DITHERSEL_DEADTIMEAB_gv    = 0x03   /* Dead-time ramp A and B */
} TCD_DITHERSEL_values_t;

/* Dither select bit group configurations*/
typedef enum TCD_DITHERSEL_enum
{
    TCD_DITHERSEL_ONTIMEB_gc       = (TCD_DITHERSEL_ONTIMEB_gv << TCD_DITHERSEL_gp),  /* On-time ramp B */
    TCD_DITHERSEL_ONTIMEAB_gc      = (TCD_DITHERSEL_ONTIMEAB_gv << TCD_DITHERSEL_gp),  /* On-time ramp A and B */
    TCD_DITHERSEL_DEADTIMEB_gc     = (TCD_DITHERSEL_DEADTIMEB_gv << TCD_DITHERSEL_gp),  /* Dead-time rampB */
    TCD_DITHERSEL_DEADTIMEAB_gc    = (TCD_DITHERSEL_DEADTIMEAB_gv << TCD_DITHERSEL_gp)   /* Dead-time ramp A and B */
} TCD_DITHERSEL_t;

/* Delay prescaler select bit group values */
typedef enum TCD_DLYPRESC_VALUES_enum
{
    TCD_DLYPRESC_DIV1_gv           = 0x00,  /* No prescaling */
    TCD_DLYPRESC_DIV2_gv           = 0x01,  /* Prescale with 2 */
    TCD_DLYPRESC_DIV4_gv           = 0x02,  /* Prescale with 4 */
    TCD_DLYPRESC_DIV8_gv           = 0x03   /* Prescale with 8 */
} TCD_DLYPRESC_values_t;

/* Delay prescaler select bit group configurations*/
typedef enum TCD_DLYPRESC_enum
{
    TCD_DLYPRESC_DIV1_gc           = (TCD_DLYPRESC_DIV1_gv << TCD_DLYPRESC_gp),  /* No prescaling */
    TCD_DLYPRESC_DIV2_gc           = (TCD_DLYPRESC_DIV2_gv << TCD_DLYPRESC_gp),  /* Prescale with 2 */
    TCD_DLYPRESC_DIV4_gc           = (TCD_DLYPRESC_DIV4_gv << TCD_DLYPRESC_gp),  /* Prescale with 4 */
    TCD_DLYPRESC_DIV8_gc           = (TCD_DLYPRESC_DIV8_gv << TCD_DLYPRESC_gp)   /* Prescale with 8 */
} TCD_DLYPRESC_t;

/* Delay select bit group values */
typedef enum TCD_DLYSEL_VALUES_enum
{
    TCD_DLYSEL_OFF_gv              = 0x00,  /* No delay */
    TCD_DLYSEL_INBLANK_gv          = 0x01,  /* Input blanking enabled */
    TCD_DLYSEL_EVENT_gv            = 0x02   /* Event delay enabled */
} TCD_DLYSEL_values_t;

/* Delay select bit group configurations*/
typedef enum TCD_DLYSEL_enum
{
    TCD_DLYSEL_OFF_gc              = (TCD_DLYSEL_OFF_gv << TCD_DLYSEL_gp),  /* No delay */
    TCD_DLYSEL_INBLANK_gc          = (TCD_DLYSEL_INBLANK_gv << TCD_DLYSEL_gp),  /* Input blanking enabled */
    TCD_DLYSEL_EVENT_gc            = (TCD_DLYSEL_EVENT_gv << TCD_DLYSEL_gp)   /* Event delay enabled */
} TCD_DLYSEL_t;

/* Delay trigger select bit group values */
typedef enum TCD_DLYTRIG_VALUES_enum
{
    TCD_DLYTRIG_CMPASET_gv         = 0x00,  /* Compare A set */
    TCD_DLYTRIG_CMPACLR_gv         = 0x01,  /* Compare A clear */
    TCD_DLYTRIG_CMPBSET_gv         = 0x02,  /* Compare B set */
    TCD_DLYTRIG_CMPBCLR_gv         = 0x03   /* Compare B clear */
} TCD_DLYTRIG_values_t;

/* Delay trigger select bit group configurations*/
typedef enum TCD_DLYTRIG_enum
{
    TCD_DLYTRIG_CMPASET_gc         = (TCD_DLYTRIG_CMPASET_gv << TCD_DLYTRIG_gp),  /* Compare A set */
    TCD_DLYTRIG_CMPACLR_gc         = (TCD_DLYTRIG_CMPACLR_gv << TCD_DLYTRIG_gp),  /* Compare A clear */
    TCD_DLYTRIG_CMPBSET_gc         = (TCD_DLYTRIG_CMPBSET_gv << TCD_DLYTRIG_gp),  /* Compare B set */
    TCD_DLYTRIG_CMPBCLR_gc         = (TCD_DLYTRIG_CMPBCLR_gv << TCD_DLYTRIG_gp)   /* Compare B clear */
} TCD_DLYTRIG_t;

/* Edge select bit group values */
typedef enum TCD_EDGE_VALUES_enum
{
    TCD_EDGE_FALL_LOW_gv           = 0x00,  /* The falling edge or low level of event generates retrigger or fault action */
    TCD_EDGE_RISE_HIGH_gv          = 0x01   /* The rising edge or high level of event generates retrigger or fault action */
} TCD_EDGE_values_t;

/* Edge select bit group configurations*/
typedef enum TCD_EDGE_enum
{
    TCD_EDGE_FALL_LOW_gc           = (TCD_EDGE_FALL_LOW_gv << TCD_EDGE_bp),  /* The falling edge or low level of event generates retrigger or fault action */
    TCD_EDGE_RISE_HIGH_gc          = (TCD_EDGE_RISE_HIGH_gv << TCD_EDGE_bp)   /* The rising edge or high level of event generates retrigger or fault action */
} TCD_EDGE_t;

/* Input mode select bit group values */
typedef enum TCD_INPUTMODE_VALUES_enum
{
    TCD_INPUTMODE_NONE_gv          = 0x00,  /* Input has no actions */
    TCD_INPUTMODE_JMPWAIT_gv       = 0x01,  /* Stop output, jump to opposite compare cycle and wait */
    TCD_INPUTMODE_EXECWAIT_gv      = 0x02,  /* Stop output, execute opposite compare cycle and wait */
    TCD_INPUTMODE_EXECFAULT_gv     = 0x03,  /* stop output, execute opposite compare cycle while fault active */
    TCD_INPUTMODE_FREQ_gv          = 0x04,  /* Stop all outputs, maintain frequency */
    TCD_INPUTMODE_EXECDT_gv        = 0x05,  /* Stop all outputs, execute dead time while fault active */
    TCD_INPUTMODE_WAIT_gv          = 0x06,  /* Stop all outputs, jump to next compare cycle and wait */
    TCD_INPUTMODE_WAITSW_gv        = 0x07,  /* Stop all outputs, wait for software action */
    TCD_INPUTMODE_EDGETRIG_gv      = 0x08,  /* Stop output on edge, jump to next compare cycle */
    TCD_INPUTMODE_EDGETRIGFREQ_gv  = 0x09,  /* Stop output on edge, maintain frequency */
    TCD_INPUTMODE_LVLTRIGFREQ_gv   = 0x0A   /* Stop output at level, maintain frequency */
} TCD_INPUTMODE_values_t;

/* Input mode select bit group configurations*/
typedef enum TCD_INPUTMODE_enum
{
    TCD_INPUTMODE_NONE_gc          = (TCD_INPUTMODE_NONE_gv << TCD_INPUTMODE_gp),  /* Input has no actions */
    TCD_INPUTMODE_JMPWAIT_gc       = (TCD_INPUTMODE_JMPWAIT_gv << TCD_INPUTMODE_gp),  /* Stop output, jump to opposite compare cycle and wait */
    TCD_INPUTMODE_EXECWAIT_gc      = (TCD_INPUTMODE_EXECWAIT_gv << TCD_INPUTMODE_gp),  /* Stop output, execute opposite compare cycle and wait */
    TCD_INPUTMODE_EXECFAULT_gc     = (TCD_INPUTMODE_EXECFAULT_gv << TCD_INPUTMODE_gp),  /* stop output, execute opposite compare cycle while fault active */
    TCD_INPUTMODE_FREQ_gc          = (TCD_INPUTMODE_FREQ_gv << TCD_INPUTMODE_gp),  /* Stop all outputs, maintain frequency */
    TCD_INPUTMODE_EXECDT_gc        = (TCD_INPUTMODE_EXECDT_gv << TCD_INPUTMODE_gp),  /* Stop all outputs, execute dead time while fault active */
    TCD_INPUTMODE_WAIT_gc          = (TCD_INPUTMODE_WAIT_gv << TCD_INPUTMODE_gp),  /* Stop all outputs, jump to next compare cycle and wait */
    TCD_INPUTMODE_WAITSW_gc        = (TCD_INPUTMODE_WAITSW_gv << TCD_INPUTMODE_gp),  /* Stop all outputs, wait for software action */
    TCD_INPUTMODE_EDGETRIG_gc      = (TCD_INPUTMODE_EDGETRIG_gv << TCD_INPUTMODE_gp),  /* Stop output on edge, jump to next compare cycle */
    TCD_INPUTMODE_EDGETRIGFREQ_gc  = (TCD_INPUTMODE_EDGETRIGFREQ_gv << TCD_INPUTMODE_gp),  /* Stop output on edge, maintain frequency */
    TCD_INPUTMODE_LVLTRIGFREQ_gc   = (TCD_INPUTMODE_LVLTRIGFREQ_gv << TCD_INPUTMODE_gp)   /* Stop output at level, maintain frequency */
} TCD_INPUTMODE_t;

/* Synchronization prescaler select bit group values */
typedef enum TCD_SYNCPRES_VALUES_enum
{
    TCD_SYNCPRES_DIV1_gv           = 0x00,  /* Selected clock source divided by 1 */
    TCD_SYNCPRES_DIV2_gv           = 0x01,  /* Selected clock source divided by 2 */
    TCD_SYNCPRES_DIV4_gv           = 0x02,  /* Selected clock source divided by 4 */
    TCD_SYNCPRES_DIV8_gv           = 0x03   /* Selected clock source divided by 8 */
} TCD_SYNCPRES_values_t;

/* Synchronization prescaler select bit group configurations*/
typedef enum TCD_SYNCPRES_enum
{
    TCD_SYNCPRES_DIV1_gc           = (TCD_SYNCPRES_DIV1_gv << TCD_SYNCPRES_gp),  /* Selected clock source divided by 1 */
    TCD_SYNCPRES_DIV2_gc           = (TCD_SYNCPRES_DIV2_gv << TCD_SYNCPRES_gp),  /* Selected clock source divided by 2 */
    TCD_SYNCPRES_DIV4_gc           = (TCD_SYNCPRES_DIV4_gv << TCD_SYNCPRES_gp),  /* Selected clock source divided by 4 */
    TCD_SYNCPRES_DIV8_gc           = (TCD_SYNCPRES_DIV8_gv << TCD_SYNCPRES_gp)   /* Selected clock source divided by 8 */
} TCD_SYNCPRES_t;

/* Waveform generation mode select bit group values */
typedef enum TCD_WGMODE_VALUES_enum
{
    TCD_WGMODE_ONERAMP_gv          = 0x00,  /* One ramp mode */
    TCD_WGMODE_TWORAMP_gv          = 0x01,  /* Two ramp mode */
    TCD_WGMODE_FOURRAMP_gv         = 0x02,  /* Four ramp mode */
    TCD_WGMODE_DS_gv               = 0x03   /* Dual slope mode */
} TCD_WGMODE_values_t;

/* Waveform generation mode select bit group configurations*/
typedef enum TCD_WGMODE_enum
{
    TCD_WGMODE_ONERAMP_gc          = (TCD_WGMODE_ONERAMP_gv << TCD_WGMODE_gp),  /* One ramp mode */
    TCD_WGMODE_TWORAMP_gc          = (TCD_WGMODE_TWORAMP_gv << TCD_WGMODE_gp),  /* Two ramp mode */
    TCD_WGMODE_FOURRAMP_gc         = (TCD_WGMODE_FOURRAMP_gv << TCD_WGMODE_gp),  /* Four ramp mode */
    TCD_WGMODE_DS_gc               = (TCD_WGMODE_DS_gv << TCD_WGMODE_gp)   /* Dual slope mode */
} TCD_WGMODE_t;

/*
--------------------------------------------------------------------------
TWI - Two-Wire Interface
--------------------------------------------------------------------------
*/

/* Two-Wire Interface */
typedef struct TWI_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t DUALCTRL;  /* Dual Mode Control */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t MCTRLA;  /* Host Control A */
    register8_t MCTRLB;  /* Host Control B */
    register8_t MSTATUS;  /* Host STATUS */
    register8_t MBAUD;  /* Host Baud Rate */
    register8_t MADDR;  /* Host Address */
    register8_t MDATA;  /* Host Data */
    register8_t SCTRLA;  /* Client Control A */
    register8_t SCTRLB;  /* Client Control B */
    register8_t SSTATUS;  /* Client Status */
    register8_t SADDR;  /* Client Address */
    register8_t SDATA;  /* Client Data */
    register8_t SADDRMASK;  /* Client Address Mask */
    register8_t reserved_1[1];
} TWI_t;

/* Acknowledge Action select bit group values */
typedef enum TWI_ACKACT_VALUES_enum
{
    TWI_ACKACT_ACK_gv              = 0x00,  /* Send ACK */
    TWI_ACKACT_NACK_gv             = 0x01   /* Send NACK */
} TWI_ACKACT_values_t;

/* Acknowledge Action select bit group configurations*/
typedef enum TWI_ACKACT_enum
{
    TWI_ACKACT_ACK_gc              = (TWI_ACKACT_ACK_gv << TWI_ACKACT_bp),  /* Send ACK */
    TWI_ACKACT_NACK_gc             = (TWI_ACKACT_NACK_gv << TWI_ACKACT_bp)   /* Send NACK */
} TWI_ACKACT_t;

/* Address or Stop select bit group values */
typedef enum TWI_AP_VALUES_enum
{
    TWI_AP_STOP_gv                 = 0x00,  /* A Stop condition generated the interrupt on APIF flag */
    TWI_AP_ADR_gv                  = 0x01   /* Address detection generated the interrupt on APIF flag */
} TWI_AP_values_t;

/* Address or Stop select bit group configurations*/
typedef enum TWI_AP_enum
{
    TWI_AP_STOP_gc                 = (TWI_AP_STOP_gv << TWI_AP_bp),  /* A Stop condition generated the interrupt on APIF flag */
    TWI_AP_ADR_gc                  = (TWI_AP_ADR_gv << TWI_AP_bp)   /* Address detection generated the interrupt on APIF flag */
} TWI_AP_t;

/* Bus State select bit group values */
typedef enum TWI_BUSSTATE_VALUES_enum
{
    TWI_BUSSTATE_UNKNOWN_gv        = 0x00,  /* Unknown bus state */
    TWI_BUSSTATE_IDLE_gv           = 0x01,  /* Bus is idle */
    TWI_BUSSTATE_OWNER_gv          = 0x02,  /* This TWI controls the bus */
    TWI_BUSSTATE_BUSY_gv           = 0x03   /* The bus is busy */
} TWI_BUSSTATE_values_t;

/* Bus State select bit group configurations*/
typedef enum TWI_BUSSTATE_enum
{
    TWI_BUSSTATE_UNKNOWN_gc        = (TWI_BUSSTATE_UNKNOWN_gv << TWI_BUSSTATE_gp),  /* Unknown bus state */
    TWI_BUSSTATE_IDLE_gc           = (TWI_BUSSTATE_IDLE_gv << TWI_BUSSTATE_gp),  /* Bus is idle */
    TWI_BUSSTATE_OWNER_gc          = (TWI_BUSSTATE_OWNER_gv << TWI_BUSSTATE_gp),  /* This TWI controls the bus */
    TWI_BUSSTATE_BUSY_gc           = (TWI_BUSSTATE_BUSY_gv << TWI_BUSSTATE_gp)   /* The bus is busy */
} TWI_BUSSTATE_t;

/* Debug Run select bit group values */
typedef enum TWI_DBGRUN_VALUES_enum
{
    TWI_DBGRUN_HALT_gv             = 0x00,  /* The peripheral is halted in Break Debug mode and ignores events */
    TWI_DBGRUN_RUN_gv              = 0x01   /* The peripheral will continue to run in Break Debug mode when the CPU is halted */
} TWI_DBGRUN_values_t;

/* Debug Run select bit group configurations*/
typedef enum TWI_DBGRUN_enum
{
    TWI_DBGRUN_HALT_gc             = (TWI_DBGRUN_HALT_gv << TWI_DBGRUN_bp),  /* The peripheral is halted in Break Debug mode and ignores events */
    TWI_DBGRUN_RUN_gc              = (TWI_DBGRUN_RUN_gv << TWI_DBGRUN_bp)   /* The peripheral will continue to run in Break Debug mode when the CPU is halted */
} TWI_DBGRUN_t;

/* Fast-mode Plus Enable select bit group values */
typedef enum TWI_FMPEN_VALUES_enum
{
    TWI_FMPEN_OFF_gv               = 0x00,  /* Operating in Standard-mode or Fast-mode */
    TWI_FMPEN_ON_gv                = 0x01   /* Operating in Fast-mode Plus */
} TWI_FMPEN_values_t;

/* Fast-mode Plus Enable select bit group configurations*/
typedef enum TWI_FMPEN_enum
{
    TWI_FMPEN_OFF_gc               = (TWI_FMPEN_OFF_gv << TWI_FMPEN_bp),  /* Operating in Standard-mode or Fast-mode */
    TWI_FMPEN_ON_gc                = (TWI_FMPEN_ON_gv << TWI_FMPEN_bp)   /* Operating in Fast-mode Plus */
} TWI_FMPEN_t;

/* Input voltage transition level select bit group values */
typedef enum TWI_INPUTLVL_VALUES_enum
{
    TWI_INPUTLVL_I2C_gv            = 0x00,  /* I2C input voltage transition level */
    TWI_INPUTLVL_SMBUS_gv          = 0x01   /* SMBus 3.0 input voltage transition level */
} TWI_INPUTLVL_values_t;

/* Input voltage transition level select bit group configurations*/
typedef enum TWI_INPUTLVL_enum
{
    TWI_INPUTLVL_I2C_gc            = (TWI_INPUTLVL_I2C_gv << TWI_INPUTLVL_bp),  /* I2C input voltage transition level */
    TWI_INPUTLVL_SMBUS_gc          = (TWI_INPUTLVL_SMBUS_gv << TWI_INPUTLVL_bp)   /* SMBus 3.0 input voltage transition level */
} TWI_INPUTLVL_t;

/* Command select bit group values */
typedef enum TWI_MCMD_VALUES_enum
{
    TWI_MCMD_NOACT_gv              = 0x00,  /* No action */
    TWI_MCMD_REPSTART_gv           = 0x01,  /* Execute Acknowledge Action followed by repeated Start. */
    TWI_MCMD_RECVTRANS_gv          = 0x02,  /* Execute Acknowledge Action followed by a byte read/write operation. Read/write is defined by DIR. */
    TWI_MCMD_STOP_gv               = 0x03   /* Execute Acknowledge Action followed by issuing a Stop condition. */
} TWI_MCMD_values_t;

/* Command select bit group configurations*/
typedef enum TWI_MCMD_enum
{
    TWI_MCMD_NOACT_gc              = (TWI_MCMD_NOACT_gv << TWI_MCMD_gp),  /* No action */
    TWI_MCMD_REPSTART_gc           = (TWI_MCMD_REPSTART_gv << TWI_MCMD_gp),  /* Execute Acknowledge Action followed by repeated Start. */
    TWI_MCMD_RECVTRANS_gc          = (TWI_MCMD_RECVTRANS_gv << TWI_MCMD_gp),  /* Execute Acknowledge Action followed by a byte read/write operation. Read/write is defined by DIR. */
    TWI_MCMD_STOP_gc               = (TWI_MCMD_STOP_gv << TWI_MCMD_gp)   /* Execute Acknowledge Action followed by issuing a Stop condition. */
} TWI_MCMD_t;

/* Command select bit group values */
typedef enum TWI_SCMD_VALUES_enum
{
    TWI_SCMD_NOACT_gv              = 0x00,  /* No Action */
    TWI_SCMD_COMPTRANS_gv          = 0x02,  /* Complete transaction */
    TWI_SCMD_RESPONSE_gv           = 0x03   /* Used in response to an interrupt */
} TWI_SCMD_values_t;

/* Command select bit group configurations*/
typedef enum TWI_SCMD_enum
{
    TWI_SCMD_NOACT_gc              = (TWI_SCMD_NOACT_gv << TWI_SCMD_gp),  /* No Action */
    TWI_SCMD_COMPTRANS_gc          = (TWI_SCMD_COMPTRANS_gv << TWI_SCMD_gp),  /* Complete transaction */
    TWI_SCMD_RESPONSE_gc           = (TWI_SCMD_RESPONSE_gv << TWI_SCMD_gp)   /* Used in response to an interrupt */
} TWI_SCMD_t;

/* SDA Hold Time select bit group values */
typedef enum TWI_SDAHOLD_VALUES_enum
{
    TWI_SDAHOLD_OFF_gv             = 0x00,  /* No SDA Hold Delay */
    TWI_SDAHOLD_50NS_gv            = 0x01,  /* Short SDA hold time */
    TWI_SDAHOLD_300NS_gv           = 0x02,  /* Meets SMBUS 2.0 specification under typical conditions */
    TWI_SDAHOLD_500NS_gv           = 0x03   /* Meets SMBUS 2.0 specificaiton across all corners */
} TWI_SDAHOLD_values_t;

/* SDA Hold Time select bit group configurations*/
typedef enum TWI_SDAHOLD_enum
{
    TWI_SDAHOLD_OFF_gc             = (TWI_SDAHOLD_OFF_gv << TWI_SDAHOLD_gp),  /* No SDA Hold Delay */
    TWI_SDAHOLD_50NS_gc            = (TWI_SDAHOLD_50NS_gv << TWI_SDAHOLD_gp),  /* Short SDA hold time */
    TWI_SDAHOLD_300NS_gc           = (TWI_SDAHOLD_300NS_gv << TWI_SDAHOLD_gp),  /* Meets SMBUS 2.0 specification under typical conditions */
    TWI_SDAHOLD_500NS_gc           = (TWI_SDAHOLD_500NS_gv << TWI_SDAHOLD_gp)   /* Meets SMBUS 2.0 specificaiton across all corners */
} TWI_SDAHOLD_t;

/* SDA Setup Time select bit group values */
typedef enum TWI_SDASETUP_VALUES_enum
{
    TWI_SDASETUP_4CYC_gv           = 0x00,  /* SDA setup time is four clock cycles */
    TWI_SDASETUP_8CYC_gv           = 0x01   /* SDA setup time is eight clock cycle */
} TWI_SDASETUP_values_t;

/* SDA Setup Time select bit group configurations*/
typedef enum TWI_SDASETUP_enum
{
    TWI_SDASETUP_4CYC_gc           = (TWI_SDASETUP_4CYC_gv << TWI_SDASETUP_bp),  /* SDA setup time is four clock cycles */
    TWI_SDASETUP_8CYC_gc           = (TWI_SDASETUP_8CYC_gv << TWI_SDASETUP_bp)   /* SDA setup time is eight clock cycle */
} TWI_SDASETUP_t;

/* Inactive Bus Time-Out select bit group values */
typedef enum TWI_TIMEOUT_VALUES_enum
{
    TWI_TIMEOUT_DISABLED_gv        = 0x00,  /* Bus time-out disabled. I2C. */
    TWI_TIMEOUT_50US_gv            = 0x01,  /* 50us - SMBus */
    TWI_TIMEOUT_100US_gv           = 0x02,  /* 100us */
    TWI_TIMEOUT_200US_gv           = 0x03   /* 200us */
} TWI_TIMEOUT_values_t;

/* Inactive Bus Time-Out select bit group configurations*/
typedef enum TWI_TIMEOUT_enum
{
    TWI_TIMEOUT_DISABLED_gc        = (TWI_TIMEOUT_DISABLED_gv << TWI_TIMEOUT_gp),  /* Bus time-out disabled. I2C. */
    TWI_TIMEOUT_50US_gc            = (TWI_TIMEOUT_50US_gv << TWI_TIMEOUT_gp),  /* 50us - SMBus */
    TWI_TIMEOUT_100US_gc           = (TWI_TIMEOUT_100US_gv << TWI_TIMEOUT_gp),  /* 100us */
    TWI_TIMEOUT_200US_gc           = (TWI_TIMEOUT_200US_gv << TWI_TIMEOUT_gp)   /* 200us */
} TWI_TIMEOUT_t;

/*
--------------------------------------------------------------------------
USART - Universal Synchronous and Asynchronous Receiver and Transmitter
--------------------------------------------------------------------------
*/

/* Universal Synchronous and Asynchronous Receiver and Transmitter */
typedef struct USART_struct
{
    register8_t RXDATAL;  /* Receive Data Low Byte */
    register8_t RXDATAH;  /* Receive Data High Byte */
    register8_t TXDATAL;  /* Transmit Data Low Byte */
    register8_t TXDATAH;  /* Transmit Data High Byte */
    register8_t STATUS;  /* Status */
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t CTRLC;  /* Control C */
    _WORDREGISTER(BAUD);  /* Baud Rate */
    register8_t CTRLD;  /* Control D */
    register8_t DBGCTRL;  /* Debug Control */
    register8_t EVCTRL;  /* Event Control */
    register8_t TXPLCTRL;  /* IRCOM Transmitter Pulse Length Control */
    register8_t RXPLCTRL;  /* IRCOM Receiver Pulse Length Control */
    register8_t reserved_1[1];
} USART_t;

/* Auto Baud Window select bit group values */
typedef enum USART_ABW_VALUES_enum
{
    USART_ABW_WDW0_gv              = 0x00,  /* 18% tolerance */
    USART_ABW_WDW1_gv              = 0x01,  /* 15% tolerance */
    USART_ABW_WDW2_gv              = 0x02,  /* 21% tolerance */
    USART_ABW_WDW3_gv              = 0x03   /* 25% tolerance */
} USART_ABW_values_t;

/* Auto Baud Window select bit group configurations*/
typedef enum USART_ABW_enum
{
    USART_ABW_WDW0_gc              = (USART_ABW_WDW0_gv << USART_ABW_gp),  /* 18% tolerance */
    USART_ABW_WDW1_gc              = (USART_ABW_WDW1_gv << USART_ABW_gp),  /* 15% tolerance */
    USART_ABW_WDW2_gc              = (USART_ABW_WDW2_gv << USART_ABW_gp),  /* 21% tolerance */
    USART_ABW_WDW3_gc              = (USART_ABW_WDW3_gv << USART_ABW_gp)   /* 25% tolerance */
} USART_ABW_t;

/* Character Size select bit group values */
typedef enum USART_CHSIZE_VALUES_enum
{
    USART_CHSIZE_5BIT_gv           = 0x00,  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gv           = 0x01,  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gv           = 0x02,  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gv           = 0x03,  /* Character size: 8 bit */
    USART_CHSIZE_9BITL_gv          = 0x06,  /* Character size: 9 bit read low byte first */
    USART_CHSIZE_9BITH_gv          = 0x07   /* Character size: 9 bit read high byte first */
} USART_CHSIZE_values_t;

/* Character Size select bit group configurations*/
typedef enum USART_CHSIZE_enum
{
    USART_CHSIZE_5BIT_gc           = (USART_CHSIZE_5BIT_gv << USART_CHSIZE_gp),  /* Character size: 5 bit */
    USART_CHSIZE_6BIT_gc           = (USART_CHSIZE_6BIT_gv << USART_CHSIZE_gp),  /* Character size: 6 bit */
    USART_CHSIZE_7BIT_gc           = (USART_CHSIZE_7BIT_gv << USART_CHSIZE_gp),  /* Character size: 7 bit */
    USART_CHSIZE_8BIT_gc           = (USART_CHSIZE_8BIT_gv << USART_CHSIZE_gp),  /* Character size: 8 bit */
    USART_CHSIZE_9BITL_gc          = (USART_CHSIZE_9BITL_gv << USART_CHSIZE_gp),  /* Character size: 9 bit read low byte first */
    USART_CHSIZE_9BITH_gc          = (USART_CHSIZE_9BITH_gv << USART_CHSIZE_gp)   /* Character size: 9 bit read high byte first */
} USART_CHSIZE_t;

/* Communication Mode select bit group values */
typedef enum USART_CMODE_VALUES_enum
{
    USART_CMODE_ASYNCHRONOUS_gv    = 0x00,  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gv     = 0x01,  /* Synchronous Mode */
    USART_CMODE_IRCOM_gv           = 0x02,  /* Infrared Communication */
    USART_CMODE_MSPI_gv            = 0x03   /* SPI Host Mode */
} USART_CMODE_values_t;

/* Communication Mode select bit group configurations*/
typedef enum USART_CMODE_enum
{
    USART_CMODE_ASYNCHRONOUS_gc    = (USART_CMODE_ASYNCHRONOUS_gv << USART_CMODE_gp),  /* Asynchronous Mode */
    USART_CMODE_SYNCHRONOUS_gc     = (USART_CMODE_SYNCHRONOUS_gv << USART_CMODE_gp),  /* Synchronous Mode */
    USART_CMODE_IRCOM_gc           = (USART_CMODE_IRCOM_gv << USART_CMODE_gp),  /* Infrared Communication */
    USART_CMODE_MSPI_gc            = (USART_CMODE_MSPI_gv << USART_CMODE_gp)   /* SPI Host Mode */
} USART_CMODE_t;

/* Parity Mode select bit group values */
typedef enum USART_PMODE_VALUES_enum
{
    USART_PMODE_DISABLED_gv        = 0x00,  /* No Parity */
    USART_PMODE_EVEN_gv            = 0x02,  /* Even Parity */
    USART_PMODE_ODD_gv             = 0x03   /* Odd Parity */
} USART_PMODE_values_t;

/* Parity Mode select bit group configurations*/
typedef enum USART_PMODE_enum
{
    USART_PMODE_DISABLED_gc        = (USART_PMODE_DISABLED_gv << USART_PMODE_gp),  /* No Parity */
    USART_PMODE_EVEN_gc            = (USART_PMODE_EVEN_gv << USART_PMODE_gp),  /* Even Parity */
    USART_PMODE_ODD_gc             = (USART_PMODE_ODD_gv << USART_PMODE_gp)   /* Odd Parity */
} USART_PMODE_t;

/* RS485 Mode internal transmitter select bit group values */
typedef enum USART_RS485_VALUES_enum
{
    USART_RS485_DISABLE_gv         = 0x00,  /* RS485 Mode disabled */
    USART_RS485_ENABLE_gv          = 0x01   /* RS485 Mode enabled */
} USART_RS485_values_t;

/* RS485 Mode internal transmitter select bit group configurations*/
typedef enum USART_RS485_enum
{
    USART_RS485_DISABLE_gc         = (USART_RS485_DISABLE_gv << USART_RS485_bp),  /* RS485 Mode disabled */
    USART_RS485_ENABLE_gc          = (USART_RS485_ENABLE_gv << USART_RS485_bp)   /* RS485 Mode enabled */
} USART_RS485_t;

/* Receiver Mode select bit group values */
typedef enum USART_RXMODE_VALUES_enum
{
    USART_RXMODE_NORMAL_gv         = 0x00,  /* Normal mode */
    USART_RXMODE_CLK2X_gv          = 0x01,  /* CLK2x mode */
    USART_RXMODE_GENAUTO_gv        = 0x02,  /* Generic autobaud mode */
    USART_RXMODE_LINAUTO_gv        = 0x03   /* LIN constrained autobaud mode */
} USART_RXMODE_values_t;

/* Receiver Mode select bit group configurations*/
typedef enum USART_RXMODE_enum
{
    USART_RXMODE_NORMAL_gc         = (USART_RXMODE_NORMAL_gv << USART_RXMODE_gp),  /* Normal mode */
    USART_RXMODE_CLK2X_gc          = (USART_RXMODE_CLK2X_gv << USART_RXMODE_gp),  /* CLK2x mode */
    USART_RXMODE_GENAUTO_gc        = (USART_RXMODE_GENAUTO_gv << USART_RXMODE_gp),  /* Generic autobaud mode */
    USART_RXMODE_LINAUTO_gc        = (USART_RXMODE_LINAUTO_gv << USART_RXMODE_gp)   /* LIN constrained autobaud mode */
} USART_RXMODE_t;

/* Stop Bit Mode select bit group values */
typedef enum USART_SBMODE_VALUES_enum
{
    USART_SBMODE_1BIT_gv           = 0x00,  /* 1 stop bit */
    USART_SBMODE_2BIT_gv           = 0x01   /* 2 stop bits */
} USART_SBMODE_values_t;

/* Stop Bit Mode select bit group configurations*/
typedef enum USART_SBMODE_enum
{
    USART_SBMODE_1BIT_gc           = (USART_SBMODE_1BIT_gv << USART_SBMODE_bp),  /* 1 stop bit */
    USART_SBMODE_2BIT_gc           = (USART_SBMODE_2BIT_gv << USART_SBMODE_bp)   /* 2 stop bits */
} USART_SBMODE_t;

/*
--------------------------------------------------------------------------
USERROW - User Row
--------------------------------------------------------------------------
*/

/* User Row */
typedef struct USERROW_struct
{
    register8_t USERROW[512];  /* User Row */
} USERROW_t;


/*
--------------------------------------------------------------------------
VPORT - Virtual Ports
--------------------------------------------------------------------------
*/

/* Virtual Ports */
typedef struct VPORT_struct
{
    register8_t DIR;  /* Data Direction */
    register8_t OUT;  /* Output Value */
    register8_t IN;  /* Input Value */
    register8_t INTFLAGS;  /* Interrupt Flags */
} VPORT_t;


/*
--------------------------------------------------------------------------
VREF - Voltage Reference
--------------------------------------------------------------------------
*/

/* Voltage Reference */
typedef struct VREF_struct
{
    register8_t reserved_1[2];
    register8_t DAC0REF;  /* DAC0 Reference */
    register8_t reserved_2[1];
    register8_t ACREF;  /* AC Reference */
    register8_t reserved_3[11];
} VREF_t;

/* Reference select bit group values */
typedef enum VREF_REFSEL_VALUES_enum
{
    VREF_REFSEL_1V024_gv           = 0x00,  /* Internal 1.024V reference */
    VREF_REFSEL_2V048_gv           = 0x01,  /* Internal 2.048V reference */
    VREF_REFSEL_4V096_gv           = 0x02,  /* Internal 4.096V reference */
    VREF_REFSEL_2V500_gv           = 0x03,  /* Internal 2.500V reference */
    VREF_REFSEL_VDD_gv             = 0x05,  /* VDD as reference */
    VREF_REFSEL_VREFA_gv           = 0x06   /* External reference on VREFA pin */
} VREF_REFSEL_values_t;

/* Reference select bit group configurations*/
typedef enum VREF_REFSEL_enum
{
    VREF_REFSEL_1V024_gc           = (VREF_REFSEL_1V024_gv << VREF_REFSEL_gp),  /* Internal 1.024V reference */
    VREF_REFSEL_2V048_gc           = (VREF_REFSEL_2V048_gv << VREF_REFSEL_gp),  /* Internal 2.048V reference */
    VREF_REFSEL_4V096_gc           = (VREF_REFSEL_4V096_gv << VREF_REFSEL_gp),  /* Internal 4.096V reference */
    VREF_REFSEL_2V500_gc           = (VREF_REFSEL_2V500_gv << VREF_REFSEL_gp),  /* Internal 2.500V reference */
    VREF_REFSEL_VDD_gc             = (VREF_REFSEL_VDD_gv << VREF_REFSEL_gp),  /* VDD as reference */
    VREF_REFSEL_VREFA_gc           = (VREF_REFSEL_VREFA_gv << VREF_REFSEL_gp)   /* External reference on VREFA pin */
} VREF_REFSEL_t;

/*
--------------------------------------------------------------------------
WDT - Watchdog Timer
--------------------------------------------------------------------------
*/

/* Watchdog Timer */
typedef struct WDT_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t CTRLB;  /* Control B */
    register8_t STATUS;  /* Status */
    register8_t reserved_1[1];
    _WORDREGISTER(CNT);  /* Counter */
    register8_t reserved_2[10];
} WDT_t;

/* Reset Cause select bit group values */
typedef enum WDT_CAUSE_VALUES_enum
{
    WDT_CAUSE_OUTSIDE_gv           = 0x00,  /* Outside window */
    WDT_CAUSE_TIMEOUT_gv           = 0x01   /* Timeout */
} WDT_CAUSE_values_t;

/* Reset Cause select bit group configurations*/
typedef enum WDT_CAUSE_enum
{
    WDT_CAUSE_OUTSIDE_gc           = (WDT_CAUSE_OUTSIDE_gv << WDT_CAUSE_bp),  /* Outside window */
    WDT_CAUSE_TIMEOUT_gc           = (WDT_CAUSE_TIMEOUT_gv << WDT_CAUSE_bp)   /* Timeout */
} WDT_CAUSE_t;

/* Period select bit group values */
typedef enum WDT_PERIOD_VALUES_enum
{
    WDT_PERIOD_OFF_gv              = 0x00,  /* Off */
    WDT_PERIOD_8CLK_gv             = 0x01,  /* 8 cycles (244 us) */
    WDT_PERIOD_16CLK_gv            = 0x02,  /* 16 cycles (488 us) */
    WDT_PERIOD_32CLK_gv            = 0x03,  /* 32 cycles (976 us) */
    WDT_PERIOD_64CLK_gv            = 0x04,  /* 64 cycles (1.95 ms) */
    WDT_PERIOD_128CLK_gv           = 0x05,  /* 128 cycles (3.9 ms) */
    WDT_PERIOD_256CLK_gv           = 0x06,  /* 256 cycles (7.8 ms) */
    WDT_PERIOD_512CLK_gv           = 0x07,  /* 512 cycles (15.625 ms) */
    WDT_PERIOD_1KCLK_gv            = 0x08,  /* 1K cycles (31.25 ms) */
    WDT_PERIOD_2KCLK_gv            = 0x09,  /* 2K cycles (62.5 ms) */
    WDT_PERIOD_4KCLK_gv            = 0x0A,  /* 4K cycles (125 ms) */
    WDT_PERIOD_8KCLK_gv            = 0x0B   /* 8K cycles (250 ms) */
} WDT_PERIOD_values_t;

/* Period select bit group configurations*/
typedef enum WDT_PERIOD_enum
{
    WDT_PERIOD_OFF_gc              = (WDT_PERIOD_OFF_gv << WDT_PERIOD_gp),  /* Off */
    WDT_PERIOD_8CLK_gc             = (WDT_PERIOD_8CLK_gv << WDT_PERIOD_gp),  /* 8 cycles (244 us) */
    WDT_PERIOD_16CLK_gc            = (WDT_PERIOD_16CLK_gv << WDT_PERIOD_gp),  /* 16 cycles (488 us) */
    WDT_PERIOD_32CLK_gc            = (WDT_PERIOD_32CLK_gv << WDT_PERIOD_gp),  /* 32 cycles (976 us) */
    WDT_PERIOD_64CLK_gc            = (WDT_PERIOD_64CLK_gv << WDT_PERIOD_gp),  /* 64 cycles (1.95 ms) */
    WDT_PERIOD_128CLK_gc           = (WDT_PERIOD_128CLK_gv << WDT_PERIOD_gp),  /* 128 cycles (3.9 ms) */
    WDT_PERIOD_256CLK_gc           = (WDT_PERIOD_256CLK_gv << WDT_PERIOD_gp),  /* 256 cycles (7.8 ms) */
    WDT_PERIOD_512CLK_gc           = (WDT_PERIOD_512CLK_gv << WDT_PERIOD_gp),  /* 512 cycles (15.625 ms) */
    WDT_PERIOD_1KCLK_gc            = (WDT_PERIOD_1KCLK_gv << WDT_PERIOD_gp),  /* 1K cycles (31.25 ms) */
    WDT_PERIOD_2KCLK_gc            = (WDT_PERIOD_2KCLK_gv << WDT_PERIOD_gp),  /* 2K cycles (62.5 ms) */
    WDT_PERIOD_4KCLK_gc            = (WDT_PERIOD_4KCLK_gv << WDT_PERIOD_gp),  /* 4K cycles (125 ms) */
    WDT_PERIOD_8KCLK_gc            = (WDT_PERIOD_8KCLK_gv << WDT_PERIOD_gp)   /* 8K cycles (250 ms) */
} WDT_PERIOD_t;

/* WDT Clock Monitor select bit group values */
typedef enum WDT_WDTMON_VALUES_enum
{
    WDT_WDTMON_OFF_gv              = 0x00,  /* Monitor is disabled */
    WDT_WDTMON_ON_gv               = 0x01,  /* Monitor is always on */
    WDT_WDTMON_SLEEP_gv            = 0x02   /* Monitor is always on in normal and IDLE mode, but automatically disabled when the MCU is in POWERDOWN and STANDBY sleep modes */
} WDT_WDTMON_values_t;

/* WDT Clock Monitor select bit group configurations*/
typedef enum WDT_WDTMON_enum
{
    WDT_WDTMON_OFF_gc              = (WDT_WDTMON_OFF_gv << WDT_WDTMON_gp),  /* Monitor is disabled */
    WDT_WDTMON_ON_gc               = (WDT_WDTMON_ON_gv << WDT_WDTMON_gp),  /* Monitor is always on */
    WDT_WDTMON_SLEEP_gc            = (WDT_WDTMON_SLEEP_gv << WDT_WDTMON_gp)   /* Monitor is always on in normal and IDLE mode, but automatically disabled when the MCU is in POWERDOWN and STANDBY sleep modes */
} WDT_WDTMON_t;

/* Window select bit group values */
typedef enum WDT_WINDOW_VALUES_enum
{
    WDT_WINDOW_OFF_gv              = 0x00,  /* Off */
    WDT_WINDOW_8CLK_gv             = 0x01,  /* 8 cycles (244 us) */
    WDT_WINDOW_16CLK_gv            = 0x02,  /* 16 cycles (488 us) */
    WDT_WINDOW_32CLK_gv            = 0x03,  /* 32 cycles (976 us) */
    WDT_WINDOW_64CLK_gv            = 0x04,  /* 64 cycles (1.95 ms) */
    WDT_WINDOW_128CLK_gv           = 0x05,  /* 128 cycles (3.9 ms) */
    WDT_WINDOW_256CLK_gv           = 0x06,  /* 256 cycles (7.8 ms) */
    WDT_WINDOW_512CLK_gv           = 0x07,  /* 512 cycles (15.625 ms) */
    WDT_WINDOW_1KCLK_gv            = 0x08,  /* 1K cycles (31.25 ms) */
    WDT_WINDOW_2KCLK_gv            = 0x09,  /* 2K cycles (62.5 ms) */
    WDT_WINDOW_4KCLK_gv            = 0x0A,  /* 4K cycles (125 ms) */
    WDT_WINDOW_8KCLK_gv            = 0x0B   /* 8K cycles (250 ms) */
} WDT_WINDOW_values_t;

/* Window select bit group configurations*/
typedef enum WDT_WINDOW_enum
{
    WDT_WINDOW_OFF_gc              = (WDT_WINDOW_OFF_gv << WDT_WINDOW_gp),  /* Off */
    WDT_WINDOW_8CLK_gc             = (WDT_WINDOW_8CLK_gv << WDT_WINDOW_gp),  /* 8 cycles (244 us) */
    WDT_WINDOW_16CLK_gc            = (WDT_WINDOW_16CLK_gv << WDT_WINDOW_gp),  /* 16 cycles (488 us) */
    WDT_WINDOW_32CLK_gc            = (WDT_WINDOW_32CLK_gv << WDT_WINDOW_gp),  /* 32 cycles (976 us) */
    WDT_WINDOW_64CLK_gc            = (WDT_WINDOW_64CLK_gv << WDT_WINDOW_gp),  /* 64 cycles (1.95 ms) */
    WDT_WINDOW_128CLK_gc           = (WDT_WINDOW_128CLK_gv << WDT_WINDOW_gp),  /* 128 cycles (3.9 ms) */
    WDT_WINDOW_256CLK_gc           = (WDT_WINDOW_256CLK_gv << WDT_WINDOW_gp),  /* 256 cycles (7.8 ms) */
    WDT_WINDOW_512CLK_gc           = (WDT_WINDOW_512CLK_gv << WDT_WINDOW_gp),  /* 512 cycles (15.625 ms) */
    WDT_WINDOW_1KCLK_gc            = (WDT_WINDOW_1KCLK_gv << WDT_WINDOW_gp),  /* 1K cycles (31.25 ms) */
    WDT_WINDOW_2KCLK_gc            = (WDT_WINDOW_2KCLK_gv << WDT_WINDOW_gp),  /* 2K cycles (62.5 ms) */
    WDT_WINDOW_4KCLK_gc            = (WDT_WINDOW_4KCLK_gv << WDT_WINDOW_gp),  /* 4K cycles (125 ms) */
    WDT_WINDOW_8KCLK_gc            = (WDT_WINDOW_8KCLK_gv << WDT_WINDOW_gp)   /* 8K cycles (250 ms) */
} WDT_WINDOW_t;

/*
--------------------------------------------------------------------------
ZCD - Zero Cross Detect
--------------------------------------------------------------------------
*/

/* Zero Cross Detect */
typedef struct ZCD_struct
{
    register8_t CTRLA;  /* Control A */
    register8_t reserved_1[1];
    register8_t INTCTRL;  /* Interrupt Control */
    register8_t STATUS;  /* Status */
    register8_t reserved_2[4];
} ZCD_t;

/* Interrupt Mode select bit group values */
typedef enum ZCD_INTMODE_VALUES_enum
{
    ZCD_INTMODE_NONE_gv            = 0x00,  /* No interrupt */
    ZCD_INTMODE_RISING_gv          = 0x01,  /* Interrupt on rising input signal */
    ZCD_INTMODE_FALLING_gv         = 0x02,  /* Interrupt on falling input signal */
    ZCD_INTMODE_BOTH_gv            = 0x03   /* Interrupt on both rising and falling input signal */
} ZCD_INTMODE_values_t;

/* Interrupt Mode select bit group configurations*/
typedef enum ZCD_INTMODE_enum
{
    ZCD_INTMODE_NONE_gc            = (ZCD_INTMODE_NONE_gv << ZCD_INTMODE_gp),  /* No interrupt */
    ZCD_INTMODE_RISING_gc          = (ZCD_INTMODE_RISING_gv << ZCD_INTMODE_gp),  /* Interrupt on rising input signal */
    ZCD_INTMODE_FALLING_gc         = (ZCD_INTMODE_FALLING_gv << ZCD_INTMODE_gp),  /* Interrupt on falling input signal */
    ZCD_INTMODE_BOTH_gc            = (ZCD_INTMODE_BOTH_gv << ZCD_INTMODE_gp)   /* Interrupt on both rising and falling input signal */
} ZCD_INTMODE_t;

/* ZCD State select bit group values */
typedef enum ZCD_STATE_VALUES_enum
{
    ZCD_STATE_LOW_gv               = 0x00,  /* Output is 0 */
    ZCD_STATE_HIGH_gv              = 0x01   /* Output is 1 */
} ZCD_STATE_values_t;

/* ZCD State select bit group configurations*/
typedef enum ZCD_STATE_enum
{
    ZCD_STATE_LOW_gc               = (ZCD_STATE_LOW_gv << ZCD_STATE_bp),  /* Output is 0 */
    ZCD_STATE_HIGH_gc              = (ZCD_STATE_HIGH_gv << ZCD_STATE_bp)   /* Output is 1 */
} ZCD_STATE_t;
/*
==========================================================================
IO Module Instances. Mapped to memory.
==========================================================================
*/

#define VPORTA              (*(VPORT_t *) 0x0000) /* Virtual Ports */
#define VPORTC              (*(VPORT_t *) 0x0008) /* Virtual Ports */
#define VPORTD              (*(VPORT_t *) 0x000C) /* Virtual Ports */
#define VPORTF              (*(VPORT_t *) 0x0014) /* Virtual Ports */
#define GPR                   (*(GPR_t *) 0x001C) /* General Purpose Registers */
#define RSTCTRL           (*(RSTCTRL_t *) 0x0040) /* Reset controller */
#define SLPCTRL           (*(SLPCTRL_t *) 0x0050) /* Sleep Controller */
#define BOD                   (*(BOD_t *) 0x0060) /* Bod interface */
#define VREF                 (*(VREF_t *) 0x0070) /* Voltage Reference */
#define CLKCTRL           (*(CLKCTRL_t *) 0x0080) /* Clock controller */
#define MVIO                 (*(MVIO_t *) 0x0100) /* Multi-Voltage I/O */
#define WDT                   (*(WDT_t *) 0x0110) /* Watchdog Timer */
#define CPUINT             (*(CPUINT_t *) 0x0120) /* Interrupt Controller */
#define CRCSCAN           (*(CRCSCAN_t *) 0x0130) /* CRCSCAN */
#define RTC                   (*(RTC_t *) 0x0140) /* Real-Time Counter */
#define CCL                   (*(CCL_t *) 0x01C0) /* Configurable Custom Logic */
#define EVSYS               (*(EVSYS_t *) 0x0200) /* Event System */
#define PORTA                (*(PORT_t *) 0x0400) /* I/O Ports */
#define PORTC                (*(PORT_t *) 0x0440) /* I/O Ports */
#define PORTD                (*(PORT_t *) 0x0460) /* I/O Ports */
#define PORTF                (*(PORT_t *) 0x04A0) /* I/O Ports */
#define PORTMUX           (*(PORTMUX_t *) 0x05E0) /* Port Multiplexer */
#define ADC0                  (*(ADC_t *) 0x0600) /* Analog to Digital Converter */
#define ADC1                  (*(ADC_t *) 0x0640) /* Analog to Digital Converter */
#define AC0                    (*(AC_t *) 0x0680) /* Analog Comparator */
#define AC1                    (*(AC_t *) 0x0688) /* Analog Comparator */
#define AC2                    (*(AC_t *) 0x0690) /* Analog Comparator */
#define DAC0                  (*(DAC_t *) 0x06A0) /* Digital to Analog Converter */
#define ZCD3                  (*(ZCD_t *) 0x06D8) /* Zero Cross Detect */
#define USART0              (*(USART_t *) 0x0800) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1              (*(USART_t *) 0x0820) /* Universal Synchronous and Asynchronous Receiver and Transmitter */
#define TWI0                  (*(TWI_t *) 0x0900) /* Two-Wire Interface */
#define SPI0                  (*(SPI_t *) 0x0940) /* Serial Peripheral Interface */
#define SPI1                  (*(SPI_t *) 0x0960) /* Serial Peripheral Interface */
#define TCA0                  (*(TCA_t *) 0x0A00) /* 16-bit Timer/Counter Type A */
#define TCB0                  (*(TCB_t *) 0x0B00) /* 16-bit Timer Type B */
#define TCB1                  (*(TCB_t *) 0x0B10) /* 16-bit Timer Type B */
#define TCB2                  (*(TCB_t *) 0x0B20) /* 16-bit Timer Type B */
#define TCB3                  (*(TCB_t *) 0x0B30) /* 16-bit Timer Type B */
#define TCD0                  (*(TCD_t *) 0x0B80) /* Timer Counter D */
#define SWDT                 (*(SWDT_t *) 0x0E20) /* Synchronous Watchdog Timer */
#define RAMCTRL           (*(RAMCTRL_t *) 0x0E30) /* RAM Controller */
#define ERRCTRL           (*(ERRCTRL_t *) 0x0E40) /* Error Controller */
#define SYSCFG             (*(SYSCFG_t *) 0x0F00) /* System Configuration Registers */
#define NVMCTRL           (*(NVMCTRL_t *) 0x1000) /* Non-volatile Memory Controller */
#define LOCK                 (*(LOCK_t *) 0x1040) /* Lockbits */
#define FUSE                 (*(FUSE_t *) 0x1050) /* Fuses */
#define SIGROW             (*(SIGROW_t *) 0x1080) /* Signature row */
#define BOOTROW           (*(BOOTROW_t *) 0x1100) /* Boot Row */
#define USERROW           (*(USERROW_t *) 0x1200) /* User Row */

#endif /* !defined (__ASSEMBLER__) */


/* ========== Flattened fully qualified IO register names ========== */


/* VPORT (VPORTA) - Virtual Ports */
#define VPORTA_DIR  _SFR_MEM8(0x0000)
#define VPORTA_OUT  _SFR_MEM8(0x0001)
#define VPORTA_IN  _SFR_MEM8(0x0002)
#define VPORTA_INTFLAGS  _SFR_MEM8(0x0003)


/* VPORT (VPORTC) - Virtual Ports */
#define VPORTC_DIR  _SFR_MEM8(0x0008)
#define VPORTC_OUT  _SFR_MEM8(0x0009)
#define VPORTC_IN  _SFR_MEM8(0x000A)
#define VPORTC_INTFLAGS  _SFR_MEM8(0x000B)


/* VPORT (VPORTD) - Virtual Ports */
#define VPORTD_DIR  _SFR_MEM8(0x000C)
#define VPORTD_OUT  _SFR_MEM8(0x000D)
#define VPORTD_IN  _SFR_MEM8(0x000E)
#define VPORTD_INTFLAGS  _SFR_MEM8(0x000F)


/* VPORT (VPORTF) - Virtual Ports */
#define VPORTF_DIR  _SFR_MEM8(0x0014)
#define VPORTF_OUT  _SFR_MEM8(0x0015)
#define VPORTF_IN  _SFR_MEM8(0x0016)
#define VPORTF_INTFLAGS  _SFR_MEM8(0x0017)


/* GPR - General Purpose Registers */
#define GPR_GPR0  _SFR_MEM8(0x001C)
#define GPR_GPR1  _SFR_MEM8(0x001D)
#define GPR_GPR2  _SFR_MEM8(0x001E)
#define GPR_GPR3  _SFR_MEM8(0x001F)


/* CPU - CPU */
#define CPU_SPLIM  _SFR_MEM16(0x0030)
#define CPU_SPLIML  _SFR_MEM8(0x0030)
#define CPU_SPLIMH  _SFR_MEM8(0x0031)
#define CPU_CCP  _SFR_MEM8(0x0034)
#define CPU_CTRLA  _SFR_MEM8(0x0035)
#define CPU_INTFLAGS  _SFR_MEM8(0x0036)
#define CPU_SP  _SFR_MEM16(0x003D)
#define CPU_SPL  _SFR_MEM8(0x003D)
#define CPU_SPH  _SFR_MEM8(0x003E)
#define CPU_SREG  _SFR_MEM8(0x003F)


/* RSTCTRL - Reset controller */
#define RSTCTRL_RSTFR  _SFR_MEM8(0x0040)
#define RSTCTRL_SWRR  _SFR_MEM8(0x0041)
#define RSTCTRL_MCFLAGSA  _SFR_MEM8(0x0042)
#define RSTCTRL_MCFLAGSB  _SFR_MEM8(0x0043)


/* SLPCTRL - Sleep Controller */
#define SLPCTRL_CTRLA  _SFR_MEM8(0x0050)
#define SLPCTRL_CTRLB  _SFR_MEM8(0x0051)
#define SLPCTRL_VREGCTRL  _SFR_MEM8(0x0052)
#define SLPCTRL_INTCTRL  _SFR_MEM8(0x0053)
#define SLPCTRL_INTFLAGS  _SFR_MEM8(0x0054)


/* BOD - Bod interface */
#define BOD_CTRLA  _SFR_MEM8(0x0060)
#define BOD_CTRLB  _SFR_MEM8(0x0061)
#define BOD_VLMCTRLA  _SFR_MEM8(0x0068)
#define BOD_INTCTRL  _SFR_MEM8(0x0069)
#define BOD_INTFLAGS  _SFR_MEM8(0x006A)
#define BOD_STATUS  _SFR_MEM8(0x006B)


/* VREF - Voltage Reference */
#define VREF_DAC0REF  _SFR_MEM8(0x0072)
#define VREF_ACREF  _SFR_MEM8(0x0074)


/* CLKCTRL - Clock controller */
#define CLKCTRL_MCLKCTRLA  _SFR_MEM8(0x0080)
#define CLKCTRL_MCLKCTRLB  _SFR_MEM8(0x0081)
#define CLKCTRL_MCLKCTRLC  _SFR_MEM8(0x0082)
#define CLKCTRL_MCLKINTCTRL  _SFR_MEM8(0x0083)
#define CLKCTRL_MCLKINTFLAGS  _SFR_MEM8(0x0084)
#define CLKCTRL_MCLKSTATUS  _SFR_MEM8(0x0085)
#define CLKCTRL_MCLKTIMEBASE  _SFR_MEM8(0x0086)
#define CLKCTRL_MCLKCFD0CTRLA  _SFR_MEM8(0x0088)
#define CLKCTRL_MCLKCFD1CTRLA  _SFR_MEM8(0x0089)
#define CLKCTRL_MCLKCFM0VALUE  _SFR_MEM16(0x0090)
#define CLKCTRL_MCLKCFM0VALUEL  _SFR_MEM8(0x0090)
#define CLKCTRL_MCLKCFM0VALUEH  _SFR_MEM8(0x0091)
#define CLKCTRL_MCLKCFM0WINLT  _SFR_MEM16(0x0092)
#define CLKCTRL_MCLKCFM0WINLTL  _SFR_MEM8(0x0092)
#define CLKCTRL_MCLKCFM0WINLTH  _SFR_MEM8(0x0093)
#define CLKCTRL_MCLKCFM0WINHT  _SFR_MEM16(0x0094)
#define CLKCTRL_MCLKCFM0WINHTL  _SFR_MEM8(0x0094)
#define CLKCTRL_MCLKCFM0WINHTH  _SFR_MEM8(0x0095)
#define CLKCTRL_MCLKCFM0REFNUM  _SFR_MEM16(0x0096)
#define CLKCTRL_MCLKCFM0REFNUML  _SFR_MEM8(0x0096)
#define CLKCTRL_MCLKCFM0REFNUMH  _SFR_MEM8(0x0097)
#define CLKCTRL_MCLKCFM0CTRLA  _SFR_MEM8(0x0098)
#define CLKCTRL_MCLKCFM0CTRLB  _SFR_MEM8(0x0099)
#define CLKCTRL_MCLKCFM1VALUE  _SFR_MEM16(0x00A0)
#define CLKCTRL_MCLKCFM1VALUEL  _SFR_MEM8(0x00A0)
#define CLKCTRL_MCLKCFM1VALUEH  _SFR_MEM8(0x00A1)
#define CLKCTRL_MCLKCFM1WINLT  _SFR_MEM16(0x00A2)
#define CLKCTRL_MCLKCFM1WINLTL  _SFR_MEM8(0x00A2)
#define CLKCTRL_MCLKCFM1WINLTH  _SFR_MEM8(0x00A3)
#define CLKCTRL_MCLKCFM1WINHT  _SFR_MEM16(0x00A4)
#define CLKCTRL_MCLKCFM1WINHTL  _SFR_MEM8(0x00A4)
#define CLKCTRL_MCLKCFM1WINHTH  _SFR_MEM8(0x00A5)
#define CLKCTRL_MCLKCFM1REFNUM  _SFR_MEM16(0x00A6)
#define CLKCTRL_MCLKCFM1REFNUML  _SFR_MEM8(0x00A6)
#define CLKCTRL_MCLKCFM1REFNUMH  _SFR_MEM8(0x00A7)
#define CLKCTRL_MCLKCFM1CTRLA  _SFR_MEM8(0x00A8)
#define CLKCTRL_MCLKCFM1CTRLB  _SFR_MEM8(0x00A9)
#define CLKCTRL_OSCHFCTRLA  _SFR_MEM8(0x00C0)
#define CLKCTRL_OSCHFTUNE  _SFR_MEM8(0x00C1)
#define CLKCTRL_PLLCTRLA  _SFR_MEM8(0x00C8)
#define CLKCTRL_OSC32KCTRLA  _SFR_MEM8(0x00D0)
#define CLKCTRL_XOSC32KCTRLA  _SFR_MEM8(0x00D4)
#define CLKCTRL_XOSCHFCTRLA  _SFR_MEM8(0x00D8)


/* MVIO - Multi-Voltage I/O */
#define MVIO_INTCTRL  _SFR_MEM8(0x0100)
#define MVIO_INTFLAGS  _SFR_MEM8(0x0101)
#define MVIO_STATUS  _SFR_MEM8(0x0102)


/* WDT - Watchdog Timer */
#define WDT_CTRLA  _SFR_MEM8(0x0110)
#define WDT_CTRLB  _SFR_MEM8(0x0111)
#define WDT_STATUS  _SFR_MEM8(0x0112)
#define WDT_CNT  _SFR_MEM16(0x0114)
#define WDT_CNTL  _SFR_MEM8(0x0114)
#define WDT_CNTH  _SFR_MEM8(0x0115)


/* CPUINT - Interrupt Controller */
#define CPUINT_CTRLA  _SFR_MEM8(0x0120)
#define CPUINT_STATUS  _SFR_MEM8(0x0121)
#define CPUINT_LVL0PRI  _SFR_MEM8(0x0122)
#define CPUINT_LVL1VEC  _SFR_MEM8(0x0123)


/* CRCSCAN - CRCSCAN */
#define CRCSCAN_CTRLA  _SFR_MEM8(0x0130)
#define CRCSCAN_CTRLB  _SFR_MEM8(0x0131)
#define CRCSCAN_INTCTRL  _SFR_MEM8(0x0132)
#define CRCSCAN_INTFLAGS  _SFR_MEM8(0x0133)
#define CRCSCAN_STATUSA  _SFR_MEM8(0x0134)
#define CRCSCAN_SCANADR  _SFR_MEM8(0x0135)
#define CRCSCAN_DATA  _SFR_MEM8(0x0136)
#define CRCSCAN_CRC  _SFR_MEM32(0x0138)
#define CRCSCAN_CRC0  _SFR_MEM8(0x0138)
#define CRCSCAN_CRC1  _SFR_MEM8(0x0139)
#define CRCSCAN_CRC2  _SFR_MEM8(0x013A)
#define CRCSCAN_CRC3  _SFR_MEM8(0x013B)


/* RTC - Real-Time Counter */
#define RTC_CTRLA  _SFR_MEM8(0x0140)
#define RTC_STATUS  _SFR_MEM8(0x0141)
#define RTC_INTCTRL  _SFR_MEM8(0x0142)
#define RTC_INTFLAGS  _SFR_MEM8(0x0143)
#define RTC_TEMP  _SFR_MEM8(0x0144)
#define RTC_DBGCTRL  _SFR_MEM8(0x0145)
#define RTC_CLKSEL  _SFR_MEM8(0x0147)
#define RTC_CNT  _SFR_MEM16(0x0148)
#define RTC_CNTL  _SFR_MEM8(0x0148)
#define RTC_CNTH  _SFR_MEM8(0x0149)
#define RTC_PER  _SFR_MEM16(0x014A)
#define RTC_PERL  _SFR_MEM8(0x014A)
#define RTC_PERH  _SFR_MEM8(0x014B)
#define RTC_CMP  _SFR_MEM16(0x014C)
#define RTC_CMPL  _SFR_MEM8(0x014C)
#define RTC_CMPH  _SFR_MEM8(0x014D)
#define RTC_PITCTRLA  _SFR_MEM8(0x0150)
#define RTC_PITSTATUS  _SFR_MEM8(0x0151)
#define RTC_PITINTCTRL  _SFR_MEM8(0x0152)
#define RTC_PITINTFLAGS  _SFR_MEM8(0x0153)
#define RTC_PITDBGCTRL  _SFR_MEM8(0x0155)
#define RTC_PITEVGENCTRLA  _SFR_MEM8(0x0156)


/* CCL - Configurable Custom Logic */
#define CCL_CTRLA  _SFR_MEM8(0x01C0)
#define CCL_SEQCTRL0  _SFR_MEM8(0x01C1)
#define CCL_SEQCTRL1  _SFR_MEM8(0x01C2)
#define CCL_SEQCTRL2  _SFR_MEM8(0x01C3)
#define CCL_INTCTRL0  _SFR_MEM8(0x01C5)
#define CCL_INTCTRL1  _SFR_MEM8(0x01C6)
#define CCL_INTFLAGS  _SFR_MEM8(0x01C7)
#define CCL_LUT0CTRLA  _SFR_MEM8(0x01C8)
#define CCL_LUT0CTRLB  _SFR_MEM8(0x01C9)
#define CCL_LUT0CTRLC  _SFR_MEM8(0x01CA)
#define CCL_TRUTH0  _SFR_MEM8(0x01CB)
#define CCL_LUT1CTRLA  _SFR_MEM8(0x01CC)
#define CCL_LUT1CTRLB  _SFR_MEM8(0x01CD)
#define CCL_LUT1CTRLC  _SFR_MEM8(0x01CE)
#define CCL_TRUTH1  _SFR_MEM8(0x01CF)
#define CCL_LUT2CTRLA  _SFR_MEM8(0x01D0)
#define CCL_LUT2CTRLB  _SFR_MEM8(0x01D1)
#define CCL_LUT2CTRLC  _SFR_MEM8(0x01D2)
#define CCL_TRUTH2  _SFR_MEM8(0x01D3)
#define CCL_LUT3CTRLA  _SFR_MEM8(0x01D4)
#define CCL_LUT3CTRLB  _SFR_MEM8(0x01D5)
#define CCL_LUT3CTRLC  _SFR_MEM8(0x01D6)
#define CCL_TRUTH3  _SFR_MEM8(0x01D7)
#define CCL_LUT4CTRLA  _SFR_MEM8(0x01D8)
#define CCL_LUT4CTRLB  _SFR_MEM8(0x01D9)
#define CCL_LUT4CTRLC  _SFR_MEM8(0x01DA)
#define CCL_TRUTH4  _SFR_MEM8(0x01DB)
#define CCL_LUT5CTRLA  _SFR_MEM8(0x01DC)
#define CCL_LUT5CTRLB  _SFR_MEM8(0x01DD)
#define CCL_LUT5CTRLC  _SFR_MEM8(0x01DE)
#define CCL_TRUTH5  _SFR_MEM8(0x01DF)


/* EVSYS - Event System */
#define EVSYS_SWEVENTA  _SFR_MEM8(0x0200)
#define EVSYS_CHANNEL0  _SFR_MEM8(0x0210)
#define EVSYS_CHANNEL1  _SFR_MEM8(0x0211)
#define EVSYS_CHANNEL2  _SFR_MEM8(0x0212)
#define EVSYS_CHANNEL3  _SFR_MEM8(0x0213)
#define EVSYS_CHANNEL4  _SFR_MEM8(0x0214)
#define EVSYS_CHANNEL5  _SFR_MEM8(0x0215)
#define EVSYS_USERCCLLUT0A  _SFR_MEM8(0x0220)
#define EVSYS_USERCCLLUT0B  _SFR_MEM8(0x0221)
#define EVSYS_USERCCLLUT1A  _SFR_MEM8(0x0222)
#define EVSYS_USERCCLLUT1B  _SFR_MEM8(0x0223)
#define EVSYS_USERCCLLUT2A  _SFR_MEM8(0x0224)
#define EVSYS_USERCCLLUT2B  _SFR_MEM8(0x0225)
#define EVSYS_USERCCLLUT3A  _SFR_MEM8(0x0226)
#define EVSYS_USERCCLLUT3B  _SFR_MEM8(0x0227)
#define EVSYS_USERCCLLUT4A  _SFR_MEM8(0x0228)
#define EVSYS_USERCCLLUT4B  _SFR_MEM8(0x0229)
#define EVSYS_USERCCLLUT5A  _SFR_MEM8(0x022A)
#define EVSYS_USERCCLLUT5B  _SFR_MEM8(0x022B)
#define EVSYS_USERADC0START  _SFR_MEM8(0x022C)
#define EVSYS_USERADC1START  _SFR_MEM8(0x022D)
#define EVSYS_USEREVSYSEVOUTA  _SFR_MEM8(0x022E)
#define EVSYS_USEREVSYSEVOUTC  _SFR_MEM8(0x022F)
#define EVSYS_USEREVSYSEVOUTD  _SFR_MEM8(0x0230)
#define EVSYS_USERUSART0IRDA  _SFR_MEM8(0x0232)
#define EVSYS_USERUSART1IRDA  _SFR_MEM8(0x0233)
#define EVSYS_USERTCA0CNTA  _SFR_MEM8(0x0235)
#define EVSYS_USERTCA0CNTB  _SFR_MEM8(0x0236)
#define EVSYS_USERTCB0CAPT  _SFR_MEM8(0x0237)
#define EVSYS_USERTCB0COUNT  _SFR_MEM8(0x0238)
#define EVSYS_USERTCB1CAPT  _SFR_MEM8(0x0239)
#define EVSYS_USERTCB1COUNT  _SFR_MEM8(0x023A)
#define EVSYS_USERTCB2CAPT  _SFR_MEM8(0x023B)
#define EVSYS_USERTCB2COUNT  _SFR_MEM8(0x023C)
#define EVSYS_USERTCB3CAPT  _SFR_MEM8(0x023D)
#define EVSYS_USERTCB3COUNT  _SFR_MEM8(0x023E)
#define EVSYS_USERTCD0INPUTA  _SFR_MEM8(0x023F)
#define EVSYS_USERTCD0INPUTB  _SFR_MEM8(0x0240)
#define EVSYS_USERERRCTRLEVENT0  _SFR_MEM8(0x0241)
#define EVSYS_USERERRCTRLEVENT1  _SFR_MEM8(0x0242)
#define EVSYS_USERCLKCTRLCFD  _SFR_MEM8(0x0243)
#define EVSYS_USERCLKCTRLCFM  _SFR_MEM8(0x0244)


/* PORT (PORTA) - I/O Ports */
#define PORTA_DIR  _SFR_MEM8(0x0400)
#define PORTA_DIRSET  _SFR_MEM8(0x0401)
#define PORTA_DIRCLR  _SFR_MEM8(0x0402)
#define PORTA_DIRTGL  _SFR_MEM8(0x0403)
#define PORTA_OUT  _SFR_MEM8(0x0404)
#define PORTA_OUTSET  _SFR_MEM8(0x0405)
#define PORTA_OUTCLR  _SFR_MEM8(0x0406)
#define PORTA_OUTTGL  _SFR_MEM8(0x0407)
#define PORTA_IN  _SFR_MEM8(0x0408)
#define PORTA_INTFLAGS  _SFR_MEM8(0x0409)
#define PORTA_PORTCTRL  _SFR_MEM8(0x040A)
#define PORTA_PINCONFIG  _SFR_MEM8(0x040B)
#define PORTA_PINCTRLUPD  _SFR_MEM8(0x040C)
#define PORTA_PINCTRLSET  _SFR_MEM8(0x040D)
#define PORTA_PINCTRLCLR  _SFR_MEM8(0x040E)
#define PORTA_PIN0CTRL  _SFR_MEM8(0x0410)
#define PORTA_PIN1CTRL  _SFR_MEM8(0x0411)
#define PORTA_PIN2CTRL  _SFR_MEM8(0x0412)
#define PORTA_PIN3CTRL  _SFR_MEM8(0x0413)
#define PORTA_PIN4CTRL  _SFR_MEM8(0x0414)
#define PORTA_PIN5CTRL  _SFR_MEM8(0x0415)
#define PORTA_PIN6CTRL  _SFR_MEM8(0x0416)
#define PORTA_PIN7CTRL  _SFR_MEM8(0x0417)
#define PORTA_EVGENCTRLA  _SFR_MEM8(0x0418)


/* PORT (PORTC) - I/O Ports */
#define PORTC_DIR  _SFR_MEM8(0x0440)
#define PORTC_DIRSET  _SFR_MEM8(0x0441)
#define PORTC_DIRCLR  _SFR_MEM8(0x0442)
#define PORTC_DIRTGL  _SFR_MEM8(0x0443)
#define PORTC_OUT  _SFR_MEM8(0x0444)
#define PORTC_OUTSET  _SFR_MEM8(0x0445)
#define PORTC_OUTCLR  _SFR_MEM8(0x0446)
#define PORTC_OUTTGL  _SFR_MEM8(0x0447)
#define PORTC_IN  _SFR_MEM8(0x0448)
#define PORTC_INTFLAGS  _SFR_MEM8(0x0449)
#define PORTC_PORTCTRL  _SFR_MEM8(0x044A)
#define PORTC_PINCONFIG  _SFR_MEM8(0x044B)
#define PORTC_PINCTRLUPD  _SFR_MEM8(0x044C)
#define PORTC_PINCTRLSET  _SFR_MEM8(0x044D)
#define PORTC_PINCTRLCLR  _SFR_MEM8(0x044E)
#define PORTC_PIN0CTRL  _SFR_MEM8(0x0450)
#define PORTC_PIN1CTRL  _SFR_MEM8(0x0451)
#define PORTC_PIN2CTRL  _SFR_MEM8(0x0452)
#define PORTC_PIN3CTRL  _SFR_MEM8(0x0453)
#define PORTC_PIN4CTRL  _SFR_MEM8(0x0454)
#define PORTC_PIN5CTRL  _SFR_MEM8(0x0455)
#define PORTC_PIN6CTRL  _SFR_MEM8(0x0456)
#define PORTC_PIN7CTRL  _SFR_MEM8(0x0457)
#define PORTC_EVGENCTRLA  _SFR_MEM8(0x0458)


/* PORT (PORTD) - I/O Ports */
#define PORTD_DIR  _SFR_MEM8(0x0460)
#define PORTD_DIRSET  _SFR_MEM8(0x0461)
#define PORTD_DIRCLR  _SFR_MEM8(0x0462)
#define PORTD_DIRTGL  _SFR_MEM8(0x0463)
#define PORTD_OUT  _SFR_MEM8(0x0464)
#define PORTD_OUTSET  _SFR_MEM8(0x0465)
#define PORTD_OUTCLR  _SFR_MEM8(0x0466)
#define PORTD_OUTTGL  _SFR_MEM8(0x0467)
#define PORTD_IN  _SFR_MEM8(0x0468)
#define PORTD_INTFLAGS  _SFR_MEM8(0x0469)
#define PORTD_PORTCTRL  _SFR_MEM8(0x046A)
#define PORTD_PINCONFIG  _SFR_MEM8(0x046B)
#define PORTD_PINCTRLUPD  _SFR_MEM8(0x046C)
#define PORTD_PINCTRLSET  _SFR_MEM8(0x046D)
#define PORTD_PINCTRLCLR  _SFR_MEM8(0x046E)
#define PORTD_PIN0CTRL  _SFR_MEM8(0x0470)
#define PORTD_PIN1CTRL  _SFR_MEM8(0x0471)
#define PORTD_PIN2CTRL  _SFR_MEM8(0x0472)
#define PORTD_PIN3CTRL  _SFR_MEM8(0x0473)
#define PORTD_PIN4CTRL  _SFR_MEM8(0x0474)
#define PORTD_PIN5CTRL  _SFR_MEM8(0x0475)
#define PORTD_PIN6CTRL  _SFR_MEM8(0x0476)
#define PORTD_PIN7CTRL  _SFR_MEM8(0x0477)
#define PORTD_EVGENCTRLA  _SFR_MEM8(0x0478)


/* PORT (PORTF) - I/O Ports */
#define PORTF_DIR  _SFR_MEM8(0x04A0)
#define PORTF_DIRSET  _SFR_MEM8(0x04A1)
#define PORTF_DIRCLR  _SFR_MEM8(0x04A2)
#define PORTF_DIRTGL  _SFR_MEM8(0x04A3)
#define PORTF_OUT  _SFR_MEM8(0x04A4)
#define PORTF_OUTSET  _SFR_MEM8(0x04A5)
#define PORTF_OUTCLR  _SFR_MEM8(0x04A6)
#define PORTF_OUTTGL  _SFR_MEM8(0x04A7)
#define PORTF_IN  _SFR_MEM8(0x04A8)
#define PORTF_INTFLAGS  _SFR_MEM8(0x04A9)
#define PORTF_PORTCTRL  _SFR_MEM8(0x04AA)
#define PORTF_PINCONFIG  _SFR_MEM8(0x04AB)
#define PORTF_PINCTRLUPD  _SFR_MEM8(0x04AC)
#define PORTF_PINCTRLSET  _SFR_MEM8(0x04AD)
#define PORTF_PINCTRLCLR  _SFR_MEM8(0x04AE)
#define PORTF_PIN0CTRL  _SFR_MEM8(0x04B0)
#define PORTF_PIN1CTRL  _SFR_MEM8(0x04B1)
#define PORTF_PIN2CTRL  _SFR_MEM8(0x04B2)
#define PORTF_PIN3CTRL  _SFR_MEM8(0x04B3)
#define PORTF_PIN4CTRL  _SFR_MEM8(0x04B4)
#define PORTF_PIN5CTRL  _SFR_MEM8(0x04B5)
#define PORTF_PIN6CTRL  _SFR_MEM8(0x04B6)
#define PORTF_PIN7CTRL  _SFR_MEM8(0x04B7)
#define PORTF_EVGENCTRLA  _SFR_MEM8(0x04B8)


/* PORTMUX - Port Multiplexer */
#define PORTMUX_EVSYSROUTEA  _SFR_MEM8(0x05E0)
#define PORTMUX_CCLROUTEA  _SFR_MEM8(0x05E1)
#define PORTMUX_USARTROUTEA  _SFR_MEM8(0x05E2)
#define PORTMUX_SPIROUTEA  _SFR_MEM8(0x05E5)
#define PORTMUX_TWIROUTEA  _SFR_MEM8(0x05E6)
#define PORTMUX_TCAROUTEA  _SFR_MEM8(0x05E7)
#define PORTMUX_TCBROUTEA  _SFR_MEM8(0x05E8)
#define PORTMUX_TCDROUTEA  _SFR_MEM8(0x05E9)
#define PORTMUX_ACROUTEA  _SFR_MEM8(0x05EA)
#define PORTMUX_ZCDROUTEA  _SFR_MEM8(0x05EB)
#define PORTMUX_ERRCTRLROUTEA  _SFR_MEM8(0x05ED)


/* ADC (ADC0) - Analog to Digital Converter */
#define ADC0_CTRLA  _SFR_MEM8(0x0600)
#define ADC0_CTRLB  _SFR_MEM8(0x0601)
#define ADC0_CTRLC  _SFR_MEM8(0x0602)
#define ADC0_CTRLD  _SFR_MEM8(0x0603)
#define ADC0_CTRLE  _SFR_MEM8(0x0604)
#define ADC0_CTRLF  _SFR_MEM8(0x0605)
#define ADC0_INTCTRL  _SFR_MEM8(0x0606)
#define ADC0_INTFLAGS  _SFR_MEM8(0x0607)
#define ADC0_STATUS  _SFR_MEM8(0x0608)
#define ADC0_DBGCTRL  _SFR_MEM8(0x0609)
#define ADC0_COMMAND  _SFR_MEM8(0x060A)
#define ADC0_MUXPOS  _SFR_MEM8(0x060B)
#define ADC0_RESULT  _SFR_MEM16(0x060C)
#define ADC0_RESULTL  _SFR_MEM8(0x060C)
#define ADC0_RESULTH  _SFR_MEM8(0x060D)
#define ADC0_SAMPLE  _SFR_MEM16(0x060E)
#define ADC0_SAMPLEL  _SFR_MEM8(0x060E)
#define ADC0_SAMPLEH  _SFR_MEM8(0x060F)
#define ADC0_WINLT  _SFR_MEM16(0x0610)
#define ADC0_WINLTL  _SFR_MEM8(0x0610)
#define ADC0_WINLTH  _SFR_MEM8(0x0611)
#define ADC0_WINHT  _SFR_MEM16(0x0612)
#define ADC0_WINHTL  _SFR_MEM8(0x0612)
#define ADC0_WINHTH  _SFR_MEM8(0x0613)
#define ADC0_TEMP  _SFR_MEM8(0x0614)


/* ADC (ADC1) - Analog to Digital Converter */
#define ADC1_CTRLA  _SFR_MEM8(0x0640)
#define ADC1_CTRLB  _SFR_MEM8(0x0641)
#define ADC1_CTRLC  _SFR_MEM8(0x0642)
#define ADC1_CTRLD  _SFR_MEM8(0x0643)
#define ADC1_CTRLE  _SFR_MEM8(0x0644)
#define ADC1_CTRLF  _SFR_MEM8(0x0645)
#define ADC1_INTCTRL  _SFR_MEM8(0x0646)
#define ADC1_INTFLAGS  _SFR_MEM8(0x0647)
#define ADC1_STATUS  _SFR_MEM8(0x0648)
#define ADC1_DBGCTRL  _SFR_MEM8(0x0649)
#define ADC1_COMMAND  _SFR_MEM8(0x064A)
#define ADC1_MUXPOS  _SFR_MEM8(0x064B)
#define ADC1_RESULT  _SFR_MEM16(0x064C)
#define ADC1_RESULTL  _SFR_MEM8(0x064C)
#define ADC1_RESULTH  _SFR_MEM8(0x064D)
#define ADC1_SAMPLE  _SFR_MEM16(0x064E)
#define ADC1_SAMPLEL  _SFR_MEM8(0x064E)
#define ADC1_SAMPLEH  _SFR_MEM8(0x064F)
#define ADC1_WINLT  _SFR_MEM16(0x0650)
#define ADC1_WINLTL  _SFR_MEM8(0x0650)
#define ADC1_WINLTH  _SFR_MEM8(0x0651)
#define ADC1_WINHT  _SFR_MEM16(0x0652)
#define ADC1_WINHTL  _SFR_MEM8(0x0652)
#define ADC1_WINHTH  _SFR_MEM8(0x0653)
#define ADC1_TEMP  _SFR_MEM8(0x0654)


/* AC (AC0) - Analog Comparator */
#define AC0_CTRLA  _SFR_MEM8(0x0680)
#define AC0_CTRLB  _SFR_MEM8(0x0681)
#define AC0_MUXCTRL  _SFR_MEM8(0x0682)
#define AC0_DACREF  _SFR_MEM8(0x0685)
#define AC0_INTCTRL  _SFR_MEM8(0x0686)
#define AC0_STATUS  _SFR_MEM8(0x0687)


/* AC (AC1) - Analog Comparator */
#define AC1_CTRLA  _SFR_MEM8(0x0688)
#define AC1_CTRLB  _SFR_MEM8(0x0689)
#define AC1_MUXCTRL  _SFR_MEM8(0x068A)
#define AC1_DACREF  _SFR_MEM8(0x068D)
#define AC1_INTCTRL  _SFR_MEM8(0x068E)
#define AC1_STATUS  _SFR_MEM8(0x068F)


/* AC (AC2) - Analog Comparator */
#define AC2_CTRLA  _SFR_MEM8(0x0690)
#define AC2_CTRLB  _SFR_MEM8(0x0691)
#define AC2_MUXCTRL  _SFR_MEM8(0x0692)
#define AC2_DACREF  _SFR_MEM8(0x0695)
#define AC2_INTCTRL  _SFR_MEM8(0x0696)
#define AC2_STATUS  _SFR_MEM8(0x0697)


/* DAC (DAC0) - Digital to Analog Converter */
#define DAC0_CTRLA  _SFR_MEM8(0x06A0)
#define DAC0_DATA  _SFR_MEM16(0x06A2)
#define DAC0_DATAL  _SFR_MEM8(0x06A2)
#define DAC0_DATAH  _SFR_MEM8(0x06A3)


/* ZCD (ZCD3) - Zero Cross Detect */
#define ZCD3_CTRLA  _SFR_MEM8(0x06D8)
#define ZCD3_INTCTRL  _SFR_MEM8(0x06DA)
#define ZCD3_STATUS  _SFR_MEM8(0x06DB)


/* USART (USART0) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART0_RXDATAL  _SFR_MEM8(0x0800)
#define USART0_RXDATAH  _SFR_MEM8(0x0801)
#define USART0_TXDATAL  _SFR_MEM8(0x0802)
#define USART0_TXDATAH  _SFR_MEM8(0x0803)
#define USART0_STATUS  _SFR_MEM8(0x0804)
#define USART0_CTRLA  _SFR_MEM8(0x0805)
#define USART0_CTRLB  _SFR_MEM8(0x0806)
#define USART0_CTRLC  _SFR_MEM8(0x0807)
#define USART0_BAUD  _SFR_MEM16(0x0808)
#define USART0_BAUDL  _SFR_MEM8(0x0808)
#define USART0_BAUDH  _SFR_MEM8(0x0809)
#define USART0_CTRLD  _SFR_MEM8(0x080A)
#define USART0_DBGCTRL  _SFR_MEM8(0x080B)
#define USART0_EVCTRL  _SFR_MEM8(0x080C)
#define USART0_TXPLCTRL  _SFR_MEM8(0x080D)
#define USART0_RXPLCTRL  _SFR_MEM8(0x080E)


/* USART (USART1) - Universal Synchronous and Asynchronous Receiver and Transmitter */
#define USART1_RXDATAL  _SFR_MEM8(0x0820)
#define USART1_RXDATAH  _SFR_MEM8(0x0821)
#define USART1_TXDATAL  _SFR_MEM8(0x0822)
#define USART1_TXDATAH  _SFR_MEM8(0x0823)
#define USART1_STATUS  _SFR_MEM8(0x0824)
#define USART1_CTRLA  _SFR_MEM8(0x0825)
#define USART1_CTRLB  _SFR_MEM8(0x0826)
#define USART1_CTRLC  _SFR_MEM8(0x0827)
#define USART1_BAUD  _SFR_MEM16(0x0828)
#define USART1_BAUDL  _SFR_MEM8(0x0828)
#define USART1_BAUDH  _SFR_MEM8(0x0829)
#define USART1_CTRLD  _SFR_MEM8(0x082A)
#define USART1_DBGCTRL  _SFR_MEM8(0x082B)
#define USART1_EVCTRL  _SFR_MEM8(0x082C)
#define USART1_TXPLCTRL  _SFR_MEM8(0x082D)
#define USART1_RXPLCTRL  _SFR_MEM8(0x082E)


/* TWI (TWI0) - Two-Wire Interface */
#define TWI0_CTRLA  _SFR_MEM8(0x0900)
#define TWI0_DUALCTRL  _SFR_MEM8(0x0901)
#define TWI0_DBGCTRL  _SFR_MEM8(0x0902)
#define TWI0_MCTRLA  _SFR_MEM8(0x0903)
#define TWI0_MCTRLB  _SFR_MEM8(0x0904)
#define TWI0_MSTATUS  _SFR_MEM8(0x0905)
#define TWI0_MBAUD  _SFR_MEM8(0x0906)
#define TWI0_MADDR  _SFR_MEM8(0x0907)
#define TWI0_MDATA  _SFR_MEM8(0x0908)
#define TWI0_SCTRLA  _SFR_MEM8(0x0909)
#define TWI0_SCTRLB  _SFR_MEM8(0x090A)
#define TWI0_SSTATUS  _SFR_MEM8(0x090B)
#define TWI0_SADDR  _SFR_MEM8(0x090C)
#define TWI0_SDATA  _SFR_MEM8(0x090D)
#define TWI0_SADDRMASK  _SFR_MEM8(0x090E)


/* SPI (SPI0) - Serial Peripheral Interface */
#define SPI0_CTRLA  _SFR_MEM8(0x0940)
#define SPI0_CTRLB  _SFR_MEM8(0x0941)
#define SPI0_INTCTRL  _SFR_MEM8(0x0942)
#define SPI0_INTFLAGS  _SFR_MEM8(0x0943)
#define SPI0_DATA  _SFR_MEM8(0x0944)


/* SPI (SPI1) - Serial Peripheral Interface */
#define SPI1_CTRLA  _SFR_MEM8(0x0960)
#define SPI1_CTRLB  _SFR_MEM8(0x0961)
#define SPI1_INTCTRL  _SFR_MEM8(0x0962)
#define SPI1_INTFLAGS  _SFR_MEM8(0x0963)
#define SPI1_DATA  _SFR_MEM8(0x0964)


/* TCA (TCA0) - 16-bit Timer/Counter Type A - Single Mode */
#define TCA0_SINGLE_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SINGLE_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SINGLE_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SINGLE_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SINGLE_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SINGLE_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SINGLE_CTRLFCLR  _SFR_MEM8(0x0A06)
#define TCA0_SINGLE_CTRLFSET  _SFR_MEM8(0x0A07)
#define TCA0_SINGLE_EVCTRL  _SFR_MEM8(0x0A09)
#define TCA0_SINGLE_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SINGLE_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SINGLE_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SINGLE_TEMP  _SFR_MEM8(0x0A0F)
#define TCA0_SINGLE_CNT  _SFR_MEM16(0x0A20)
#define TCA0_SINGLE_CNTL  _SFR_MEM8(0x0A20)
#define TCA0_SINGLE_CNTH  _SFR_MEM8(0x0A21)
#define TCA0_SINGLE_PER  _SFR_MEM16(0x0A26)
#define TCA0_SINGLE_PERL  _SFR_MEM8(0x0A26)
#define TCA0_SINGLE_PERH  _SFR_MEM8(0x0A27)
#define TCA0_SINGLE_CMP0  _SFR_MEM16(0x0A28)
#define TCA0_SINGLE_CMP0L  _SFR_MEM8(0x0A28)
#define TCA0_SINGLE_CMP0H  _SFR_MEM8(0x0A29)
#define TCA0_SINGLE_CMP1  _SFR_MEM16(0x0A2A)
#define TCA0_SINGLE_CMP1L  _SFR_MEM8(0x0A2A)
#define TCA0_SINGLE_CMP1H  _SFR_MEM8(0x0A2B)
#define TCA0_SINGLE_CMP2  _SFR_MEM16(0x0A2C)
#define TCA0_SINGLE_CMP2L  _SFR_MEM8(0x0A2C)
#define TCA0_SINGLE_CMP2H  _SFR_MEM8(0x0A2D)
#define TCA0_SINGLE_PERBUF  _SFR_MEM16(0x0A36)
#define TCA0_SINGLE_PERBUFL  _SFR_MEM8(0x0A36)
#define TCA0_SINGLE_PERBUFH  _SFR_MEM8(0x0A37)
#define TCA0_SINGLE_CMP0BUF  _SFR_MEM16(0x0A38)
#define TCA0_SINGLE_CMP0BUFL  _SFR_MEM8(0x0A38)
#define TCA0_SINGLE_CMP0BUFH  _SFR_MEM8(0x0A39)
#define TCA0_SINGLE_CMP1BUF  _SFR_MEM16(0x0A3A)
#define TCA0_SINGLE_CMP1BUFL  _SFR_MEM8(0x0A3A)
#define TCA0_SINGLE_CMP1BUFH  _SFR_MEM8(0x0A3B)
#define TCA0_SINGLE_CMP2BUF  _SFR_MEM16(0x0A3C)
#define TCA0_SINGLE_CMP2BUFL  _SFR_MEM8(0x0A3C)
#define TCA0_SINGLE_CMP2BUFH  _SFR_MEM8(0x0A3D)


/* TCA (TCA0) - 16-bit Timer/Counter Type A - Split Mode */
#define TCA0_SPLIT_CTRLA  _SFR_MEM8(0x0A00)
#define TCA0_SPLIT_CTRLB  _SFR_MEM8(0x0A01)
#define TCA0_SPLIT_CTRLC  _SFR_MEM8(0x0A02)
#define TCA0_SPLIT_CTRLD  _SFR_MEM8(0x0A03)
#define TCA0_SPLIT_CTRLECLR  _SFR_MEM8(0x0A04)
#define TCA0_SPLIT_CTRLESET  _SFR_MEM8(0x0A05)
#define TCA0_SPLIT_INTCTRL  _SFR_MEM8(0x0A0A)
#define TCA0_SPLIT_INTFLAGS  _SFR_MEM8(0x0A0B)
#define TCA0_SPLIT_DBGCTRL  _SFR_MEM8(0x0A0E)
#define TCA0_SPLIT_LCNT  _SFR_MEM8(0x0A20)
#define TCA0_SPLIT_HCNT  _SFR_MEM8(0x0A21)
#define TCA0_SPLIT_LPER  _SFR_MEM8(0x0A26)
#define TCA0_SPLIT_HPER  _SFR_MEM8(0x0A27)
#define TCA0_SPLIT_LCMP0  _SFR_MEM8(0x0A28)
#define TCA0_SPLIT_HCMP0  _SFR_MEM8(0x0A29)
#define TCA0_SPLIT_LCMP1  _SFR_MEM8(0x0A2A)
#define TCA0_SPLIT_HCMP1  _SFR_MEM8(0x0A2B)
#define TCA0_SPLIT_LCMP2  _SFR_MEM8(0x0A2C)
#define TCA0_SPLIT_HCMP2  _SFR_MEM8(0x0A2D)


/* TCB (TCB0) - 16-bit Timer Type B */
#define TCB0_CTRLA  _SFR_MEM8(0x0B00)
#define TCB0_CTRLB  _SFR_MEM8(0x0B01)
#define TCB0_EVCTRL  _SFR_MEM8(0x0B04)
#define TCB0_INTCTRL  _SFR_MEM8(0x0B05)
#define TCB0_INTFLAGS  _SFR_MEM8(0x0B06)
#define TCB0_STATUS  _SFR_MEM8(0x0B07)
#define TCB0_DBGCTRL  _SFR_MEM8(0x0B08)
#define TCB0_TEMP  _SFR_MEM8(0x0B09)
#define TCB0_CNT  _SFR_MEM16(0x0B0A)
#define TCB0_CNTL  _SFR_MEM8(0x0B0A)
#define TCB0_CNTH  _SFR_MEM8(0x0B0B)
#define TCB0_CCMP  _SFR_MEM16(0x0B0C)
#define TCB0_CCMPL  _SFR_MEM8(0x0B0C)
#define TCB0_CCMPH  _SFR_MEM8(0x0B0D)


/* TCB (TCB1) - 16-bit Timer Type B */
#define TCB1_CTRLA  _SFR_MEM8(0x0B10)
#define TCB1_CTRLB  _SFR_MEM8(0x0B11)
#define TCB1_EVCTRL  _SFR_MEM8(0x0B14)
#define TCB1_INTCTRL  _SFR_MEM8(0x0B15)
#define TCB1_INTFLAGS  _SFR_MEM8(0x0B16)
#define TCB1_STATUS  _SFR_MEM8(0x0B17)
#define TCB1_DBGCTRL  _SFR_MEM8(0x0B18)
#define TCB1_TEMP  _SFR_MEM8(0x0B19)
#define TCB1_CNT  _SFR_MEM16(0x0B1A)
#define TCB1_CNTL  _SFR_MEM8(0x0B1A)
#define TCB1_CNTH  _SFR_MEM8(0x0B1B)
#define TCB1_CCMP  _SFR_MEM16(0x0B1C)
#define TCB1_CCMPL  _SFR_MEM8(0x0B1C)
#define TCB1_CCMPH  _SFR_MEM8(0x0B1D)


/* TCB (TCB2) - 16-bit Timer Type B */
#define TCB2_CTRLA  _SFR_MEM8(0x0B20)
#define TCB2_CTRLB  _SFR_MEM8(0x0B21)
#define TCB2_EVCTRL  _SFR_MEM8(0x0B24)
#define TCB2_INTCTRL  _SFR_MEM8(0x0B25)
#define TCB2_INTFLAGS  _SFR_MEM8(0x0B26)
#define TCB2_STATUS  _SFR_MEM8(0x0B27)
#define TCB2_DBGCTRL  _SFR_MEM8(0x0B28)
#define TCB2_TEMP  _SFR_MEM8(0x0B29)
#define TCB2_CNT  _SFR_MEM16(0x0B2A)
#define TCB2_CNTL  _SFR_MEM8(0x0B2A)
#define TCB2_CNTH  _SFR_MEM8(0x0B2B)
#define TCB2_CCMP  _SFR_MEM16(0x0B2C)
#define TCB2_CCMPL  _SFR_MEM8(0x0B2C)
#define TCB2_CCMPH  _SFR_MEM8(0x0B2D)


/* TCB (TCB3) - 16-bit Timer Type B */
#define TCB3_CTRLA  _SFR_MEM8(0x0B30)
#define TCB3_CTRLB  _SFR_MEM8(0x0B31)
#define TCB3_EVCTRL  _SFR_MEM8(0x0B34)
#define TCB3_INTCTRL  _SFR_MEM8(0x0B35)
#define TCB3_INTFLAGS  _SFR_MEM8(0x0B36)
#define TCB3_STATUS  _SFR_MEM8(0x0B37)
#define TCB3_DBGCTRL  _SFR_MEM8(0x0B38)
#define TCB3_TEMP  _SFR_MEM8(0x0B39)
#define TCB3_CNT  _SFR_MEM16(0x0B3A)
#define TCB3_CNTL  _SFR_MEM8(0x0B3A)
#define TCB3_CNTH  _SFR_MEM8(0x0B3B)
#define TCB3_CCMP  _SFR_MEM16(0x0B3C)
#define TCB3_CCMPL  _SFR_MEM8(0x0B3C)
#define TCB3_CCMPH  _SFR_MEM8(0x0B3D)


/* TCD (TCD0) - Timer Counter D */
#define TCD0_CTRLA  _SFR_MEM8(0x0B80)
#define TCD0_CTRLB  _SFR_MEM8(0x0B81)
#define TCD0_CTRLC  _SFR_MEM8(0x0B82)
#define TCD0_CTRLD  _SFR_MEM8(0x0B83)
#define TCD0_CTRLE  _SFR_MEM8(0x0B84)
#define TCD0_EVCTRLA  _SFR_MEM8(0x0B88)
#define TCD0_EVCTRLB  _SFR_MEM8(0x0B89)
#define TCD0_INTCTRL  _SFR_MEM8(0x0B8C)
#define TCD0_INTFLAGS  _SFR_MEM8(0x0B8D)
#define TCD0_STATUS  _SFR_MEM8(0x0B8E)
#define TCD0_INPUTCTRLA  _SFR_MEM8(0x0B90)
#define TCD0_INPUTCTRLB  _SFR_MEM8(0x0B91)
#define TCD0_FAULTCTRL  _SFR_MEM8(0x0B92)
#define TCD0_DLYCTRL  _SFR_MEM8(0x0B94)
#define TCD0_DLYVAL  _SFR_MEM8(0x0B95)
#define TCD0_DITCTRL  _SFR_MEM8(0x0B98)
#define TCD0_DITVAL  _SFR_MEM8(0x0B99)
#define TCD0_DBGCTRL  _SFR_MEM8(0x0B9E)
#define TCD0_CAPTUREA  _SFR_MEM16(0x0BA2)
#define TCD0_CAPTUREAL  _SFR_MEM8(0x0BA2)
#define TCD0_CAPTUREAH  _SFR_MEM8(0x0BA3)
#define TCD0_CAPTUREB  _SFR_MEM16(0x0BA4)
#define TCD0_CAPTUREBL  _SFR_MEM8(0x0BA4)
#define TCD0_CAPTUREBH  _SFR_MEM8(0x0BA5)
#define TCD0_CMPASET  _SFR_MEM16(0x0BA8)
#define TCD0_CMPASETL  _SFR_MEM8(0x0BA8)
#define TCD0_CMPASETH  _SFR_MEM8(0x0BA9)
#define TCD0_CMPACLR  _SFR_MEM16(0x0BAA)
#define TCD0_CMPACLRL  _SFR_MEM8(0x0BAA)
#define TCD0_CMPACLRH  _SFR_MEM8(0x0BAB)
#define TCD0_CMPBSET  _SFR_MEM16(0x0BAC)
#define TCD0_CMPBSETL  _SFR_MEM8(0x0BAC)
#define TCD0_CMPBSETH  _SFR_MEM8(0x0BAD)
#define TCD0_CMPBCLR  _SFR_MEM16(0x0BAE)
#define TCD0_CMPBCLRL  _SFR_MEM8(0x0BAE)
#define TCD0_CMPBCLRH  _SFR_MEM8(0x0BAF)


/* SWDT - Synchronous Watchdog Timer */
#define SWDT_CTRLA  _SFR_MEM8(0x0E20)
#define SWDT_CTRLB  _SFR_MEM8(0x0E21)
#define SWDT_INTCTRL  _SFR_MEM8(0x0E22)
#define SWDT_INTFLAGS  _SFR_MEM8(0x0E23)
#define SWDT_CNT  _SFR_MEM32(0x0E24)
#define SWDT_CNT0  _SFR_MEM8(0x0E24)
#define SWDT_CNT1  _SFR_MEM8(0x0E25)
#define SWDT_CNT2  _SFR_MEM8(0x0E26)
#define SWDT_CNT3  _SFR_MEM8(0x0E27)
#define SWDT_RESET  _SFR_MEM32(0x0E28)
#define SWDT_RESET0  _SFR_MEM8(0x0E28)
#define SWDT_RESET1  _SFR_MEM8(0x0E29)
#define SWDT_RESET2  _SFR_MEM8(0x0E2A)
#define SWDT_RESET3  _SFR_MEM8(0x0E2B)
#define SWDT_WINDOW  _SFR_MEM16(0x0E2C)
#define SWDT_WINDOWL  _SFR_MEM8(0x0E2C)
#define SWDT_WINDOWH  _SFR_MEM8(0x0E2D)
#define SWDT_COMMAND  _SFR_MEM8(0x0E2E)


/* RAMCTRL - RAM Controller */
#define RAMCTRL_CTRLA  _SFR_MEM8(0x0E30)
#define RAMCTRL_INTFLAGS  _SFR_MEM8(0x0E31)
#define RAMCTRL_ADDR  _SFR_MEM16(0x0E32)
#define RAMCTRL_ADDRL  _SFR_MEM8(0x0E32)
#define RAMCTRL_ADDRH  _SFR_MEM8(0x0E33)
#define RAMCTRL_SYNDROME  _SFR_MEM8(0x0E34)


/* ERRCTRL - Error Controller */
#define ERRCTRL_CTRLA  _SFR_MEM8(0x0E40)
#define ERRCTRL_STATUSA  _SFR_MEM8(0x0E41)
#define ERRCTRL_TIMEOUT  _SFR_MEM8(0x0E42)
#define ERRCTRL_TIMECNT  _SFR_MEM8(0x0E43)
#define ERRCTRL_CAUSE  _SFR_MEM8(0x0E44)
#define ERRCTRL_ESCVREGFAIL  _SFR_MEM8(0x0E50)
#define ERRCTRL_ESCBUSERR  _SFR_MEM8(0x0E51)
#define ERRCTRL_ESCRAM2  _SFR_MEM8(0x0E52)
#define ERRCTRL_ESCFLASH2  _SFR_MEM8(0x0E53)
#define ERRCTRL_ESCOPC  _SFR_MEM8(0x0E54)
#define ERRCTRL_ESCSPLIM  _SFR_MEM8(0x0E55)
#define ERRCTRL_ESCRAM1  _SFR_MEM8(0x0E56)
#define ERRCTRL_ESCFLASH1  _SFR_MEM8(0x0E57)
#define ERRCTRL_ESCVREGWARN  _SFR_MEM8(0x0E58)
#define ERRCTRL_ESCCFD0  _SFR_MEM8(0x0E59)
#define ERRCTRL_ESCCFD1  _SFR_MEM8(0x0E5A)
#define ERRCTRL_ESCCFM0  _SFR_MEM8(0x0E5B)
#define ERRCTRL_ESCCFM1  _SFR_MEM8(0x0E5C)
#define ERRCTRL_ESCSWDT  _SFR_MEM8(0x0E5D)
#define ERRCTRL_ESCEEPROM  _SFR_MEM8(0x0E5E)
#define ERRCTRL_ESCEVSYS0  _SFR_MEM8(0x0E5F)
#define ERRCTRL_ESCEVSYS1  _SFR_MEM8(0x0E60)
#define ERRCTRL_ESF  _SFR_MEM32(0x0E70)
#define ERRCTRL_ESF0  _SFR_MEM8(0x0E70)
#define ERRCTRL_ESF1  _SFR_MEM8(0x0E71)
#define ERRCTRL_ESF2  _SFR_MEM8(0x0E72)
#define ERRCTRL_ESF3  _SFR_MEM8(0x0E73)
#define ERRCTRL_ESFTEST  _SFR_MEM32(0x0E74)
#define ERRCTRL_ESFTEST0  _SFR_MEM8(0x0E74)
#define ERRCTRL_ESFTEST1  _SFR_MEM8(0x0E75)
#define ERRCTRL_ESFTEST2  _SFR_MEM8(0x0E76)
#define ERRCTRL_ESFTEST3  _SFR_MEM8(0x0E77)


/* SYSCFG - System Configuration Registers */
#define SYSCFG_REVID  _SFR_MEM8(0x0F01)


/* NVMCTRL - Non-volatile Memory Controller */
#define NVMCTRL_CTRLA  _SFR_MEM8(0x1000)
#define NVMCTRL_CTRLB  _SFR_MEM8(0x1001)
#define NVMCTRL_CTRLC  _SFR_MEM8(0x1002)
#define NVMCTRL_CTRLD  _SFR_MEM8(0x1003)
#define NVMCTRL_INTCTRLA  _SFR_MEM8(0x1004)
#define NVMCTRL_INTFLAGSA  _SFR_MEM8(0x1005)
#define NVMCTRL_INTFLAGSB  _SFR_MEM8(0x1006)
#define NVMCTRL_STATUS  _SFR_MEM8(0x1007)
#define NVMCTRL_DATA  _SFR_MEM32(0x1008)
#define NVMCTRL_DATA0  _SFR_MEM8(0x1008)
#define NVMCTRL_DATA1  _SFR_MEM8(0x1009)
#define NVMCTRL_DATA2  _SFR_MEM8(0x100A)
#define NVMCTRL_DATA3  _SFR_MEM8(0x100B)
#define NVMCTRL_ADDR  _SFR_MEM32(0x100C)
#define NVMCTRL_ADDR0  _SFR_MEM8(0x100C)
#define NVMCTRL_ADDR1  _SFR_MEM8(0x100D)
#define NVMCTRL_ADDR2  _SFR_MEM8(0x100E)
#define NVMCTRL_ADDR3  _SFR_MEM8(0x100F)
#define NVMCTRL_PARITY  _SFR_MEM8(0x1010)
#define NVMCTRL_SYNDROME  _SFR_MEM8(0x1011)


/* LOCK - Lockbits */
#define LOCK_KEY  _SFR_MEM32(0x1040)
#define LOCK_KEY0  _SFR_MEM8(0x1040)
#define LOCK_KEY1  _SFR_MEM8(0x1041)
#define LOCK_KEY2  _SFR_MEM8(0x1042)
#define LOCK_KEY3  _SFR_MEM8(0x1043)


/* FUSE - Fuses */
#define FUSE_WDTCFG  _SFR_MEM8(0x1050)
#define FUSE_BODCFG  _SFR_MEM8(0x1051)
#define FUSE_SYSCFG0  _SFR_MEM8(0x1055)
#define FUSE_SYSCFG1  _SFR_MEM8(0x1056)
#define FUSE_CODESIZE  _SFR_MEM8(0x1057)
#define FUSE_BOOTSIZE  _SFR_MEM8(0x1058)
#define FUSE_PDICFG  _SFR_MEM16(0x105A)
#define FUSE_PDICFGL  _SFR_MEM8(0x105A)
#define FUSE_PDICFGH  _SFR_MEM8(0x105B)


/* SIGROW - Signature row */
#define SIGROW_DEVICEID0  _SFR_MEM8(0x1080)
#define SIGROW_DEVICEID1  _SFR_MEM8(0x1081)
#define SIGROW_DEVICEID2  _SFR_MEM8(0x1082)
#define SIGROW_TEMPSENSE0  _SFR_MEM16(0x1084)
#define SIGROW_TEMPSENSE0L  _SFR_MEM8(0x1084)
#define SIGROW_TEMPSENSE0H  _SFR_MEM8(0x1085)
#define SIGROW_TEMPSENSE1  _SFR_MEM16(0x1086)
#define SIGROW_TEMPSENSE1L  _SFR_MEM8(0x1086)
#define SIGROW_TEMPSENSE1H  _SFR_MEM8(0x1087)
#define SIGROW_SERNUM0  _SFR_MEM8(0x1090)
#define SIGROW_SERNUM1  _SFR_MEM8(0x1091)
#define SIGROW_SERNUM2  _SFR_MEM8(0x1092)
#define SIGROW_SERNUM3  _SFR_MEM8(0x1093)
#define SIGROW_SERNUM4  _SFR_MEM8(0x1094)
#define SIGROW_SERNUM5  _SFR_MEM8(0x1095)
#define SIGROW_SERNUM6  _SFR_MEM8(0x1096)
#define SIGROW_SERNUM7  _SFR_MEM8(0x1097)
#define SIGROW_SERNUM8  _SFR_MEM8(0x1098)
#define SIGROW_SERNUM9  _SFR_MEM8(0x1099)
#define SIGROW_SERNUM10  _SFR_MEM8(0x109A)
#define SIGROW_SERNUM11  _SFR_MEM8(0x109B)
#define SIGROW_SERNUM12  _SFR_MEM8(0x109C)
#define SIGROW_SERNUM13  _SFR_MEM8(0x109D)
#define SIGROW_SERNUM14  _SFR_MEM8(0x109E)
#define SIGROW_SERNUM15  _SFR_MEM8(0x109F)


/* BOOTROW - Boot Row */
#define BOOTROW_BOOTROW  _SFR_MEM8(0x1100)


/* USERROW - User Row */
#define USERROW_USERROW  _SFR_MEM8(0x1200)




/* ========== Generic Port Pins ========== */
#define PIN0_bm 0x01
#define PIN0_bp 0
#define PIN1_bm 0x02
#define PIN1_bp 1
#define PIN2_bm 0x04
#define PIN2_bp 2
#define PIN3_bm 0x08
#define PIN3_bp 3
#define PIN4_bm 0x10
#define PIN4_bp 4
#define PIN5_bm 0x20
#define PIN5_bp 5
#define PIN6_bm 0x40
#define PIN6_bp 6
#define PIN7_bm 0x80
#define PIN7_bp 7

/* ========== Interrupt Vector Definitions ========== */
/* Vector 0 is the reset vector */

/* NMI interrupt vectors */
#define NMI_vect_num  1
#define NMI_vect      _VECTOR(1)  /*  */

/* BOD interrupt vectors */
#define BOD_VLM_vect_num  2
#define BOD_VLM_vect      _VECTOR(2)  /*  */

/* ERRCTRL interrupt vectors */
#define ERRCTRL_INT_vect_num  3
#define ERRCTRL_INT_vect      _VECTOR(3)  /*  */

/* CLKCTRL interrupt vectors */
#define CLKCTRL_INT_vect_num  4
#define CLKCTRL_INT_vect      _VECTOR(4)  /*  */

/* SLPCTRL interrupt vectors */
#define SLPCTRL_INT_vect_num  5
#define SLPCTRL_INT_vect      _VECTOR(5)  /*  */

/* SWDT interrupt vectors */
#define SWDT_INT_vect_num  6
#define SWDT_INT_vect      _VECTOR(6)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_ERROR_vect_num  7
#define NVMCTRL_ERROR_vect      _VECTOR(7)  /*  */

/* RAMCTRL interrupt vectors */
#define RAMCTRL_INT_vect_num  8
#define RAMCTRL_INT_vect      _VECTOR(8)  /*  */

/* CRCSCAN interrupt vectors */
#define CRCSCAN_INT_vect_num  9
#define CRCSCAN_INT_vect      _VECTOR(9)  /*  */

/* MVIO interrupt vectors */
#define MVIO_MVIO_vect_num  10
#define MVIO_MVIO_vect      _VECTOR(10)  /*  */

/* RTC interrupt vectors */
#define RTC_CNT_vect_num  11
#define RTC_CNT_vect      _VECTOR(11)  /*  */
#define RTC_PIT_vect_num  12
#define RTC_PIT_vect      _VECTOR(12)  /*  */

/* CCL interrupt vectors */
#define CCL_CCL_vect_num  13
#define CCL_CCL_vect      _VECTOR(13)  /*  */

/* PORTA interrupt vectors */
#define PORTA_PORT_vect_num  14
#define PORTA_PORT_vect      _VECTOR(14)  /*  */

/* TCA0 interrupt vectors */
#define TCA0_OVF_vect_num  15
#define TCA0_OVF_vect      _VECTOR(15)  /*  */
#define TCA0_HUNF_vect_num  16
#define TCA0_HUNF_vect      _VECTOR(16)  /*  */
#define TCA0_CMP0_vect_num  17
#define TCA0_CMP0_vect      _VECTOR(17)  /*  */
#define TCA0_CMP1_vect_num  18
#define TCA0_CMP1_vect      _VECTOR(18)  /*  */
#define TCA0_CMP2_vect_num  19
#define TCA0_CMP2_vect      _VECTOR(19)  /*  */

/* TCB0 interrupt vectors */
#define TCB0_INT_vect_num  20
#define TCB0_INT_vect      _VECTOR(20)  /*  */

/* TCB1 interrupt vectors */
#define TCB1_INT_vect_num  21
#define TCB1_INT_vect      _VECTOR(21)  /*  */

/* TCD0 interrupt vectors */
#define TCD0_OVF_vect_num  22
#define TCD0_OVF_vect      _VECTOR(22)  /*  */
#define TCD0_TRIG_vect_num  23
#define TCD0_TRIG_vect      _VECTOR(23)  /*  */

/* TWI0 interrupt vectors */
#define TWI0_TWIS_vect_num  24
#define TWI0_TWIS_vect      _VECTOR(24)  /*  */
#define TWI0_TWIM_vect_num  25
#define TWI0_TWIM_vect      _VECTOR(25)  /*  */

/* SPI0 interrupt vectors */
#define SPI0_INT_vect_num  26
#define SPI0_INT_vect      _VECTOR(26)  /*  */

/* SPI1 interrupt vectors */
#define SPI1_INT_vect_num  27
#define SPI1_INT_vect      _VECTOR(27)  /*  */

/* USART0 interrupt vectors */
#define USART0_RXC_vect_num  28
#define USART0_RXC_vect      _VECTOR(28)  /*  */
#define USART0_DRE_vect_num  29
#define USART0_DRE_vect      _VECTOR(29)  /*  */
#define USART0_TXC_vect_num  30
#define USART0_TXC_vect      _VECTOR(30)  /*  */

/* PORTD interrupt vectors */
#define PORTD_PORT_vect_num  31
#define PORTD_PORT_vect      _VECTOR(31)  /*  */

/* AC0 interrupt vectors */
#define AC0_AC_vect_num  32
#define AC0_AC_vect      _VECTOR(32)  /*  */

/* AC1 interrupt vectors */
#define AC1_AC_vect_num  33
#define AC1_AC_vect      _VECTOR(33)  /*  */

/* AC2 interrupt vectors */
#define AC2_AC_vect_num  34
#define AC2_AC_vect      _VECTOR(34)  /*  */

/* ADC0 interrupt vectors */
#define ADC0_ERROR_vect_num  35
#define ADC0_ERROR_vect      _VECTOR(35)  /*  */
#define ADC0_RESRDY_vect_num  36
#define ADC0_RESRDY_vect      _VECTOR(36)  /*  */
#define ADC0_SAMPRDY_vect_num  37
#define ADC0_SAMPRDY_vect      _VECTOR(37)  /*  */

/* ADC1 interrupt vectors */
#define ADC1_ERROR_vect_num  38
#define ADC1_ERROR_vect      _VECTOR(38)  /*  */
#define ADC1_RESRDY_vect_num  39
#define ADC1_RESRDY_vect      _VECTOR(39)  /*  */
#define ADC1_SAMPRDY_vect_num  40
#define ADC1_SAMPRDY_vect      _VECTOR(40)  /*  */

/* ZCD3 interrupt vectors */
#define ZCD3_ZCD_vect_num  41
#define ZCD3_ZCD_vect      _VECTOR(41)  /*  */

/* PORTC interrupt vectors */
#define PORTC_PORT_vect_num  42
#define PORTC_PORT_vect      _VECTOR(42)  /*  */

/* USART1 interrupt vectors */
#define USART1_RXC_vect_num  43
#define USART1_RXC_vect      _VECTOR(43)  /*  */
#define USART1_DRE_vect_num  44
#define USART1_DRE_vect      _VECTOR(44)  /*  */
#define USART1_TXC_vect_num  45
#define USART1_TXC_vect      _VECTOR(45)  /*  */

/* PORTF interrupt vectors */
#define PORTF_PORT_vect_num  46
#define PORTF_PORT_vect      _VECTOR(46)  /*  */

/* NVMCTRL interrupt vectors */
#define NVMCTRL_READY_vect_num  47
#define NVMCTRL_READY_vect      _VECTOR(47)  /*  */

/* TCB2 interrupt vectors */
#define TCB2_INT_vect_num  48
#define TCB2_INT_vect      _VECTOR(48)  /*  */

/* TCB3 interrupt vectors */
#define TCB3_INT_vect_num  49
#define TCB3_INT_vect      _VECTOR(49)  /*  */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (50 * _VECTOR_SIZE)


/* ========== Constants ========== */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define DATAMEM_START     (0x0000)
#  define DATAMEM_SIZE      (32768)
#else
#  define DATAMEM_START     (0x0000U)
#  define DATAMEM_SIZE      (32768U)
#endif
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define IO_START     (0x0000)
#  define IO_SIZE      (4159)
#  define IO_PAGE_SIZE (0)
#else
#  define IO_START     (0x0000U)
#  define IO_SIZE      (4159U)
#  define IO_PAGE_SIZE (0U)
#endif
#define IO_END       (IO_START + IO_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define LOCKBITS_START     (0x1040)
#  define LOCKBITS_SIZE      (4)
#  define LOCKBITS_PAGE_SIZE (1)
#else
#  define LOCKBITS_START     (0x1040U)
#  define LOCKBITS_SIZE      (4U)
#  define LOCKBITS_PAGE_SIZE (1U)
#endif
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define FUSES_START     (0x1050)
#  define FUSES_SIZE      (16)
#  define FUSES_PAGE_SIZE (1)
#else
#  define FUSES_START     (0x1050U)
#  define FUSES_SIZE      (16U)
#  define FUSES_PAGE_SIZE (1U)
#endif
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SIGNATURES_START     (0x1080)
#  define SIGNATURES_SIZE      (3)
#  define SIGNATURES_PAGE_SIZE (128)
#else
#  define SIGNATURES_START     (0x1080U)
#  define SIGNATURES_SIZE      (3U)
#  define SIGNATURES_PAGE_SIZE (128U)
#endif
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROD_SIGNATURES_START     (0x1083)
#  define PROD_SIGNATURES_SIZE      (125)
#  define PROD_SIGNATURES_PAGE_SIZE (128)
#else
#  define PROD_SIGNATURES_START     (0x1083U)
#  define PROD_SIGNATURES_SIZE      (125U)
#  define PROD_SIGNATURES_PAGE_SIZE (128U)
#endif
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define BOOTROW_START     (0x1100)
#  define BOOTROW_SIZE      (256)
#  define BOOTROW_PAGE_SIZE (64)
#else
#  define BOOTROW_START     (0x1100U)
#  define BOOTROW_SIZE      (256U)
#  define BOOTROW_PAGE_SIZE (64U)
#endif
#define BOOTROW_END       (BOOTROW_START + BOOTROW_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define USER_SIGNATURES_START     (0x1200)
#  define USER_SIGNATURES_SIZE      (512)
#  define USER_SIGNATURES_PAGE_SIZE (512)
#else
#  define USER_SIGNATURES_START     (0x1200U)
#  define USER_SIGNATURES_SIZE      (512U)
#  define USER_SIGNATURES_PAGE_SIZE (512U)
#endif
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define EEPROM_START     (0x1400)
#  define EEPROM_SIZE      (256)
#  define EEPROM_PAGE_SIZE (1)
#else
#  define EEPROM_START     (0x1400U)
#  define EEPROM_SIZE      (256U)
#  define EEPROM_PAGE_SIZE (1U)
#endif
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

/* Added MAPPED_EEPROM segment names for avr-libc */
#define MAPPED_EEPROM_START     (EEPROM_START)
#define MAPPED_EEPROM_SIZE      (EEPROM_SIZE)
#define MAPPED_EEPROM_PAGE_SIZE (EEPROM_PAGE_SIZE)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define INTERNAL_SRAM_START     (0x7000)
#  define INTERNAL_SRAM_SIZE      (4096)
#  define INTERNAL_SRAM_PAGE_SIZE (0)
#else
#  define INTERNAL_SRAM_START     (0x7000U)
#  define INTERNAL_SRAM_SIZE      (4096U)
#  define INTERNAL_SRAM_PAGE_SIZE (0U)
#endif
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define MAPPED_PROGMEM_START     (0x8000)
#  define MAPPED_PROGMEM_SIZE      (32768)
#  define MAPPED_PROGMEM_PAGE_SIZE (512)
#else
#  define MAPPED_PROGMEM_START     (0x8000U)
#  define MAPPED_PROGMEM_SIZE      (32768U)
#  define MAPPED_PROGMEM_PAGE_SIZE (512U)
#endif
#define MAPPED_PROGMEM_END       (MAPPED_PROGMEM_START + MAPPED_PROGMEM_SIZE - 1)

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define PROGMEM_START     (0x0000)
#  define PROGMEM_SIZE      (32768)
#  define PROGMEM_PAGE_SIZE (512)
#else
#  define PROGMEM_START     (0x0000U)
#  define PROGMEM_SIZE      (32768U)
#  define PROGMEM_PAGE_SIZE (512U)
#endif
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE

/* ========== Fuses ========== */
#define FUSE_MEMORY_SIZE 16

/* Fuse Byte 0 (WDTCFG) */
#define FUSE_PERIOD0  (unsigned char)_BV(0)  /* Watchdog Timeout Period Bit 0 */
#define FUSE_PERIOD1  (unsigned char)_BV(1)  /* Watchdog Timeout Period Bit 1 */
#define FUSE_PERIOD2  (unsigned char)_BV(2)  /* Watchdog Timeout Period Bit 2 */
#define FUSE_PERIOD3  (unsigned char)_BV(3)  /* Watchdog Timeout Period Bit 3 */
#define FUSE_WINDOW0  (unsigned char)_BV(4)  /* Watchdog Window Timeout Period Bit 0 */
#define FUSE_WINDOW1  (unsigned char)_BV(5)  /* Watchdog Window Timeout Period Bit 1 */
#define FUSE_WINDOW2  (unsigned char)_BV(6)  /* Watchdog Window Timeout Period Bit 2 */
#define FUSE_WINDOW3  (unsigned char)_BV(7)  /* Watchdog Window Timeout Period Bit 3 */
#define FUSE0_DEFAULT  (0x0)
#define FUSE_WDTCFG_DEFAULT  (0x0)

/* Fuse Byte 1 (BODCFG) */
#define FUSE_SLEEP0  (unsigned char)_BV(0)  /* BOD Operation in Sleep Mode Bit 0 */
#define FUSE_SLEEP1  (unsigned char)_BV(1)  /* BOD Operation in Sleep Mode Bit 1 */
#define FUSE_ACTIVE0  (unsigned char)_BV(2)  /* BOD Operation in Active Mode Bit 0 */
#define FUSE_ACTIVE1  (unsigned char)_BV(3)  /* BOD Operation in Active Mode Bit 1 */
#define FUSE_SAMPFREQ  (unsigned char)_BV(4)  /* BOD Sample Frequency */
#define FUSE_LVL0  (unsigned char)_BV(5)  /* BOD Level Bit 0 */
#define FUSE_LVL1  (unsigned char)_BV(6)  /* BOD Level Bit 1 */
#define FUSE_LVL2  (unsigned char)_BV(7)  /* BOD Level Bit 2 */
#define FUSE1_DEFAULT  (0x0)
#define FUSE_BODCFG_DEFAULT  (0x0)

/* Fuse Byte 2 Reserved */

/* Fuse Byte 3 Reserved */

/* Fuse Byte 4 Reserved */

/* Fuse Byte 5 (SYSCFG0) */
#define FUSE_EESAVE  (unsigned char)_BV(0)  /* EEPROM Save */
#define FUSE_BROWSAVE  (unsigned char)_BV(1)  /* Boot Row Saved */
#define FUSE_CRCSEL  (unsigned char)_BV(6)  /* CRC Select */
#define FUSE_CRCBOOT  (unsigned char)_BV(7)  /* CRC Boot */
#define FUSE5_DEFAULT  (0x0)
#define FUSE_SYSCFG0_DEFAULT  (0x0)

/* Fuse Byte 6 (SYSCFG1) */
#define FUSE_SUT0  (unsigned char)_BV(0)  /* Startup Time Bit 0 */
#define FUSE_SUT1  (unsigned char)_BV(1)  /* Startup Time Bit 1 */
#define FUSE_SUT2  (unsigned char)_BV(2)  /* Startup Time Bit 2 */
#define FUSE_MVSYSCFG0  (unsigned char)_BV(3)  /* MVIO System Configuration Bit 0 */
#define FUSE_MVSYSCFG1  (unsigned char)_BV(4)  /* MVIO System Configuration Bit 1 */
#define FUSE_WDTMON0  (unsigned char)_BV(6)  /* WDT Monitor Configuration Bit 0 */
#define FUSE_WDTMON1  (unsigned char)_BV(7)  /* WDT Monitor Configuration Bit 1 */
#define FUSE6_DEFAULT  (0x48)
#define FUSE_SYSCFG1_DEFAULT  (0x48)

/* Fuse Byte 7 (CODESIZE) */
#define FUSE7_DEFAULT  (0x0)
#define FUSE_CODESIZE_DEFAULT  (0x0)

/* Fuse Byte 8 (BOOTSIZE) */
#define FUSE8_DEFAULT  (0x0)
#define FUSE_BOOTSIZE_DEFAULT  (0x0)

/* Fuse Byte 9 Reserved */

/* Fuse Byte 10 (PDICFG) */
#define FUSE_LEVEL0  (unsigned char)_BV(0)  /* Protection Level select Bit 0 */
#define FUSE_LEVEL1  (unsigned char)_BV(1)  /* Protection Level select Bit 1 */
#define FUSE_KEY0  (unsigned char)_BV(4)  /* NVM Protection Activation Key select Bit 0 */
#define FUSE_KEY1  (unsigned char)_BV(5)  /* NVM Protection Activation Key select Bit 1 */
#define FUSE_KEY2  (unsigned char)_BV(6)  /* NVM Protection Activation Key select Bit 2 */
#define FUSE_KEY3  (unsigned char)_BV(7)  /* NVM Protection Activation Key select Bit 3 */
#define FUSE_KEY4  (unsigned char)_BV(8)  /* NVM Protection Activation Key select Bit 4 */
#define FUSE_KEY5  (unsigned char)_BV(9)  /* NVM Protection Activation Key select Bit 5 */
#define FUSE_KEY6  (unsigned char)_BV(10)  /* NVM Protection Activation Key select Bit 6 */
#define FUSE_KEY7  (unsigned char)_BV(11)  /* NVM Protection Activation Key select Bit 7 */
#define FUSE_KEY8  (unsigned char)_BV(12)  /* NVM Protection Activation Key select Bit 8 */
#define FUSE_KEY9  (unsigned char)_BV(13)  /* NVM Protection Activation Key select Bit 9 */
#define FUSE_KEY10  (unsigned char)_BV(14)  /* NVM Protection Activation Key select Bit 10 */
#define FUSE_KEY11  (unsigned char)_BV(15)  /* NVM Protection Activation Key select Bit 11 */
#define FUSE10_DEFAULT  (0x3)
#define FUSE_PDICFG_DEFAULT  (0x3)

/* ========== Lock Bits ========== */
#define __LOCK_KEY_EXIST
#ifdef LOCKBITS_DEFAULT
#undef LOCKBITS_DEFAULT
#endif //LOCKBITS_DEFAULT
#define LOCKBITS_DEFAULT  (0x5CC5C55C)

/* ========== Signature ========== */

#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x54

#endif /* #ifdef _AVR_AVR32SD20_H_INCLUDED */

