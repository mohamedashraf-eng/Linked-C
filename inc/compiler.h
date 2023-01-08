/**
 * @file Compiler.h
 * @author Mohamed Ashraf (wx@wx.com)
 * @brief AUTOSAR Base - SWS Compiler Abstractrion.
 * @version 1.0.0
 * @date 2023-01-04
 * @details The file Compiler.h provides macros for the encapsulation of defintions and declarations.
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/** @def Header Guards */
#ifndef __COMPILER_H__
#define __COMPILER_H__
/** @brief Included headers */
#include "compiler_cfg.h"

/* 
 * =============================================================================
 * = SOURCE FILE VERSION INFORMATION
 * =============================================================================
*/

/** @brief Vendor specific ID */
#define COMPILER_VENDOR_ID 								   (1332)
/** @brief Program based version */
#define COMPILER_SW_MAJOR_VERSION	 					 (1)
#define COMPILER_SW_MINOR_VERSION	 					 (0)
#define COMPILER_SW_PATCH_VERSION	 					 (0)

/*
* ================================================================================================================================
* -> File Version Checks
* ================================================================================================================================
**/

#if ( (COMPILER_CFG_SW_MAJOR_VERSION != COMPILER_SW_MAJOR_VERSION) || \
      (COMPILER_CFG_SW_MINOR_VERSION != COMPILER_SW_MINOR_VERSION) || \
      (COMPILER_CFG_SW_PATCH_VERSION != COMPILER_SW_PATCH_VERSION) ) 
    #error ("`compiler_cfg.h` and `compiler.h` version doesn't met.")
#endif

/*
* ================================================================================================================================
* -> Compiler Generic Declaration
* ================================================================================================================================
**/

/** @brief The compiler being used. */
#define _GNU_C_
/**
 * @brief Defining the compiler being used.
 * 
 */
#define COMPILER_BEING_USED _GNU_ARM_C_STM32F103_

/**
 * @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration
 * 				of local pointers.
 */
#define AUTOMATIC
/**
 * @brief The memory class TYPEDEF shall be provided as empty definition. This memory class shall be
 * 				used within type definitions, where no memory qualifier can be specified. This can be
 * 				necessary for defining pointer types, with e.g. P2VAR, where the macros require two
 * 				parameters. first parameter can be specified in the type definition (distance to memory location
 * 				referenced by the pointer), but the second one (memory allocation of the pointer itself),
 * 				cannot be defined at this time. Hence memory class TYPEDEF shall be applied
 * 				
 */
#define TYPEDEF
/**
 * @brief The compiler abstraction shall provide NULL_PTR define with a void pointer to zero definition.
 */
#define NULL_PTR ((void *) 0)

/**
 * @brief The memory class AUTOMATIC shall be provided as empty definition, user for the declaration
 * 				of local pointers.
 */
#define AUTOMATIC

/*
* ================================================================================================================================
* -> Compiler Specific Declarations
* ================================================================================================================================
**/

#ifdef _GNU_C_
	/**
	 * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
	 * 				inline. 
	 */
	#define _INLINE inline
	/**
	 * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword
	 * 				inline in function with static scope. 
	 */
	#define _STATIC static
	#define _LOCAL_INLINE _STATIC _INLINE
	#define _CONST const
	#define _FORCE_INLINE __attribute__((always_inline))
	#define _FORCE_CONST __attribute__((const))
	#define _FORCE_PACKING(PAD_SIZE) __attribute__((packed))
#endif /* _GNU_ARM_C_STM32F103_ */

#endif /* __COMPILER_H__ */