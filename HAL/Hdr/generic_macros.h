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

#define TRUE					1
#define FALSE					0
#define SET						TRUE
#define RESET					FALSE
#define ENABLE					TRUE
#define DISABLE					FALSE

#define PERIOD_100MS			0.1F
#define PERIOD_10MS				0.01F
#define PERIOD_1MS				0.001F

#define UINT16_T_MAX			65536

#endif /* HAL_HDR_GENERIC_MACROS_H_ */
