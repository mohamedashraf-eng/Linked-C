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



/*
* ================================================================================================================================
* -> Compiler Generic Declaration
* ================================================================================================================================
**/


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
 * =============================================================================
 * = COMPILER SPECIFIC DECLARATION
 * =============================================================================
*/

#ifndef COMPILER_BEING_USED
	#define COMPILER_BEING_USED
#endif /* COMPILER_BEING_USED */

/** 
 * @defgroup GREENHILLS Compiler specifications
*/
#ifdef _GREENHILLS_C_STM32F103_
	/**
	 * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
	 * 				inline. 
	 */
	#define INLINE __inline
	/**
	 * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword
	 * 				inline in function with static scope. 
	 */
	#define STATIC 
	#define LOCAL_INLINE STATIC INLINE
	/**
	 * @brief The compiler abstraction of specifiying an interrupt handler.
	 */
	#define INTERRUPT_FUNC __interrupt
#endif /* _GREENHILLS_C_STM32F103_ */

/** 
 * @defgroup IAR Compiler specifications
*/
#ifdef _IAR_C_STM32F103_
	/**
	 * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
	 * 				inline. 
	 */
	#define INLINE inline
	/**
	 * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword
	 * 				inline in function with static scope. 
	 */
	#define STATIC static
	#define LOCAL_INLINE STATIC INLINE
	/**
	 * @brief The compiler abstraction of specifiying an interrupt handler.
	 */
	#define INTERRUPT_FUNC 
#endif /* _IAR_C_STM32F103_ */

/** 
 * @defgroup GNU ARM Compiler specifications
*/
#ifdef _GNU_ARM_C_STM32F103_
	/**
	 * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
	 * 				inline. 
	 */
	#define INLINE inline
	/**
	 * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword
	 * 				inline in function with static scope. 
	 */
	#define STATIC static
	#define LOCAL_INLINE STATIC INLINE
	/**
	 * @brief The compiler abstraction of specifiying an interrupt handler.
	 */
	#define INTERRUPT_FUNC 
#endif /* _GNU_ARM_C_STM32F103_ */
/*
* ================================================================================================================================
* -> Macros
* ================================================================================================================================
**/
/**
 * @brief The compiler abstraction shall define the FUNC macro for the declaration and definitions of
 * 				functions, that ensures correct syntax of function declarations as required by a specific compiler.
 */
#define FUNC(rettype, memclass) rettype
/**
 * @brief The compiler abstraction shall define the P2VAR macro for the delcaration and definition of
 * 				pointers in RAM, pointing to variables.
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
/**
 * @brief The compiler abstraction shall define the P2CONST macro for the delcaration and definition of
 * 				pointers pointing to constants.
 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
/**
 * @brief The compiler abstraction shall define the CONSTP2CONST macro for the delcaration and definition of
 * 				constant pointers pointing to constants.
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
/**
 * @brief The compiler abstraction shall define the P2FUNC macro for the delcaration and definition of
 * 				pointer to function.
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)
/**
 * @brief The compiler abstraction shall define the CONST macro for the delcaration and definition of
 * 				constants
 */
#define CONST(consttype, memclass) const consttype
/**
 * @brief The compiler abstraction shall define the VAR macro for the delcaration and definition of
 * 				variables.
 */
#define VAR(vartype, memclass) vartype
 


#endif /* __COMPILER_H__ */