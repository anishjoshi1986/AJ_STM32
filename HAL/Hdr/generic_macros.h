/*
 * generic_macros.h
 *
 *  Created on: Jan 2, 2026
 *      Author: anish
 */

#ifndef GENERIC_MACROS_H_
#define GENERIC_MACROS_H_

// --------------------------------------------------------------------------------------------------------//
// Generic macros
// --------------------------------------------------------------------------------------------------------//

#define __vo					volatile

#define U8						uint8_t
#define U16						uint16_t
#define U32						uint32_t
#define I8						int8_t
#define I16						int16_t
#define I32						int32_t

#define TRUE					1U
#define FALSE					0U
#define SET						TRUE
#define RESET					FALSE
#define ENABLE					TRUE
#define DISABLE					FALSE

#define FREQ_100MS				10U
#define FREQ_10MS				100U
#define FREQ_1MS				1000U

#define UINT16_T_MAX			(U32)65536

#endif /* HAL_HDR_GENERIC_MACROS_H_ */
