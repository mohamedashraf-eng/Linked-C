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
#define LINKEDC_VENDOR_ID (1332)
#define LINKEDC_MODULE_ID (12)
/** @brief Program based version */
#define LINKEDC_SW_MAJOR_VERSION (1)
#define LINKEDC_SW_MINOR_VERSION (0)
#define LINKEDC_SW_PATCH_VERSION (0)

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

#if ((LINKEDC_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) ||                     \
     (LINKEDC_SW_MINOR_VERSION != STD_SW_MINOR_VERSION) ||                     \
     (LINKEDC_SW_PATCH_VERSION != STD_SW_PATCH_VERSION))
#error("`linked_c.h` and `std_types.h` version doesn't met.")
#endif

/*
 * ================================================================================================================================
 * -> Public Macros
 * ================================================================================================================================
 **/

/**
 * @brief Detailed user interface flag
 * @details The detailed user interface option is used to display all
 *          hidden data in the backend.
 *
 * @defgroup Configuration Parameters
 *    @arg DUI_INACTIVE
 *    @arg DUI_ACTIVE
 */
#define DETAILED_USER_INTERFACE (DUI_ACTIVE)

/*
 * ================================================================================================================================
 * -> Public Datatypes
 * ================================================================================================================================
 **/

typedef struct _sll_struct *sll_class;

/*
 * ================================================================================================================================
 * -> Public Enums
 * ================================================================================================================================
 **/

typedef enum ll_status {
  InstanceCreateSucc = 0,
  InstanceCreateFail,
  InsertionSucc,
  InsertionFail,
  DeletionSucc,
  DeletionFail,
  NOK,
  OK
} en_ll_user_status;

/*
 * ================================================================================================================================
 * -> Public Structs
 * ================================================================================================================================
 **/

/*
 * ================================================================================================================================
 * -> Public Functions Declaration
 * ================================================================================================================================
 **/

/**
 * @brief
 *
 * @param a_log_status
 * @return sll_class
 */
sll_class sll_getInstance(en_ll_user_status *a_log_status);
/**
 * @brief
 *
 * @param mySllInstance
 * @param myData
 * @return en_ll_user_status
 */
en_ll_user_status sll_append(sll_class mySllInstance, void *myData);
/**
 * @brief
 *
 * @param mySllInstance
 * @param myData
 * @return en_ll_user_status
 */
en_ll_user_status sll_push(sll_class mySllInstance, void *myData);
/**
 * @brief
 *
 * @param mySllInstance
 * @param myData
 * @param myKth
 * @return en_ll_user_status
 */
en_ll_user_status sll_insert_kth(sll_class mySllInstance, void *myData,
                                 uint64 _CONST myKth);
/**
 * @brief
 *
 * @param mySllInstance
 * @return en_ll_user_status
 */
en_ll_user_status sll_remove_at_begin(sll_class mySllInstance);
/**
 * @brief
 *
 * @param mySllInstance
 * @return en_ll_user_status
 */
en_ll_user_status sll_remove_at_end(sll_class mySllInstance);
/**
 * @brief
 *
 * @param mySllInstance
 * @param myKth
 * @return en_ll_user_status
 */
en_ll_user_status sll_remove_at_kth(sll_class mySllInstance,
                                    uint64 _CONST myKth);
/**
 * @brief
 *
 * @param mySllInstance
 * @return en_ll_user_status
 */
en_ll_user_status sll_list_delete(sll_class mySllInstance);

/** @def C++ Guards */
#ifdef __cplusplus
}
#endif

#endif /* __LINKED_C_H__ */