/**
 * @file linked_c.c
 * @author Mohamed Ashraf (wx@wx.com)
 * @brief The C file that contains the API's implementation
 * @version 0.1
 * @date 2023-01-07
 * 
 * @copyright Copyright (c) 2023
 * 
 * @attention
 * 
 */
/*
* ================================================================================================================================
* -> Included Headers
* ================================================================================================================================
**/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_c.h"

/*
* ================================================================================================================================
* -> Private Macros
* ================================================================================================================================
**/

/*
* ================================================================================================================================
* -> Private Structs
* ================================================================================================================================
**/

/**
 * @brief linked list main building block;
 *        used for inhertiance.
*/
FORCE_PACKING(0)
struct linkedlist_ancestor{
  struct linkedlist_ancestor *next;
  void *data;
}; 
/** @brief Usability typedef */
typedef struct linkedlist_ancestor _st_ll_ancestor_t;

/*
* ================================================================================================================================
* -> Private Enums
* ================================================================================================================================
**/


/*
* ================================================================================================================================
* -> Private Datatypes
* ================================================================================================================================
**/

/*
* ================================================================================================================================
* -> Private Functions Declaration
* ================================================================================================================================
**/

LOCAL_INLINE en_ll_log_status 
ll_create_heap(_st_ll_ancestor_t **pa_ll_head);


/*
* ================================================================================================================================
* -> Public Functions Implementation
* ================================================================================================================================
**/

void portal_test(void){
  
  _st_ll_ancestor_t *myList = NULL;

  en_ll_log_status test = ll_create_heap(&myList);
  if( (LOG_ERROR_INVALID_ALLOCATION == test) ){
    printf("\n Invalid heaping. ");
  }
  else if( (LOG_STATUS_OK == test) ){
    printf("\n LOG_STATUS_OK");

  }
}

/*
* ================================================================================================================================
* -> Private Functions Implementation
* ================================================================================================================================
**/

/**
 * @brief Function to create & initialize a linked list's head,
 *        created in heap and return by pointer-pointer assign.
 * 
 * @param pa_ll_head 
 * @return LOCAL_INLINE 
 */
FORCE_INLINE
LOCAL_INLINE en_ll_log_status 
ll_create_heap(_st_ll_ancestor_t **pa_ll_head){
  en_ll_log_status this_function_log_status = LOG_STATUS_NOT_OK;
  /**
   * @brief If the head purely created.
   */
  if( (NULL == (*pa_ll_head)) ){
    _st_ll_ancestor_t *new_head = (_st_ll_ancestor_t *) malloc(sizeof(_st_ll_ancestor_t));
    if( (NULL == new_head) ){
      this_function_log_status = LOG_ERROR_INVALID_ALLOCATION;
    }else{
      new_head->data = NULL;
      new_head->next = NULL;
      *pa_ll_head = new_head;
      this_function_log_status = LOG_STATUS_OK;
    }
  }
  return this_function_log_status;  
}




















