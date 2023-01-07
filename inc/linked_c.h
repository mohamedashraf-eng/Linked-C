/**
 * @file linked_c.h
 * @author Mohamed Wx (wx@wx.com)
 * @brief The linked list c library header file.
 * @version 0.1
 * @date 2023-01-07
 * 
 * @copyright Copyright (c) 2023
 * 
 * @attention
 * 
 */
/** @defgroup Header guards */
#ifndef __LINKED_C_H__
#define __LINKED_C_H__
/** @def C++ Guards */
#ifdef __cplusplus
extern "C" {
#endif
/*
* ================================================================================================================================
* -> File Version Information
* ================================================================================================================================
**/

/** @brief Vendor specific ID */
#define LINKEDC_VENDOR_ID         (1332)
#define LINKEDC_MODULE_ID         (12)
/** @brief Program based version */
#define LINKEDC_SW_MAJOR_VERSION  (1)
#define LINKEDC_SW_MINOR_VERSION  (0)
#define LINKEDC_SW_PATCH_VERSION  (0)

/*
* ================================================================================================================================
* -> Included Headers
* ================================================================================================================================
**/

#include "std_types.h"

/*
* ================================================================================================================================
* -> File Version Checks
* ================================================================================================================================
**/

#if ( (LINKEDC_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
      (LINKEDC_SW_MINOR_VERSION != STD_SW_MINOR_VERSION) || \
      (LINKEDC_SW_PATCH_VERSION != STD_SW_PATCH_VERSION) ) 
    #error ("`linked_c.h` and `std_types.h` version doesn't met.")
#endif

/*
* ================================================================================================================================
* -> Public Macros
* ================================================================================================================================
**/

/*
* ================================================================================================================================
* -> Public Structs
* ================================================================================================================================
**/


/*
* ================================================================================================================================
* -> Public Enums
* ================================================================================================================================
**/

typedef enum ll_logStatus{
  LOG_INFO_OK,
  LOG_INFO_NOT_OK,
  
  LOG_ERROR_INVALID_ALLOCATION,
  LOG_ERROR_NULL,

  LOG_STATUS_OK,
  LOG_STATUS_NOT_OK
}en_ll_log_status;

/*
* ================================================================================================================================
* -> Public Datatypes
* ================================================================================================================================
**/

/*
* ================================================================================================================================
* -> Public Functions Declaration
* ================================================================================================================================
**/












/** @def C++ Guards */
#ifdef __cplusplus
}
#endif




#endif /* __LINKED_C_H__ */