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

#include "linked_c.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * ================================================================================================================================
 * -> Private Macros
 * ================================================================================================================================
 **/

/**
 * @defgroup Logging/Debugging Macros
 *
 * @brief Simple debugging/logging function like macro to trace the code.
 */
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_INACTIVE)
/** @brief Function like macro used for debug messages
 * 	@attention
 * 		This function like macro is compatible starts from GCC-89/90
 */
#define _wxtrace_log(format, ...)                                              \
  ({                                                                           \
    fprintf(stderr,                                                            \
            "\n=> File: %s, Function: %s, Line: %d\n DBG_MSG: " format "\n",   \
            __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);                  \
  })
#endif

#if (FULL_ASSERTION_FLAG == FULL_ASSERTION_ACTIVE)

/** @brief Function like macro used for terminating the program on assertion
 * failure
 * 	@attention
 * 		This function like macro is compatible starts from GCC-89/90
 */
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_INACTIVE)
#define exit_on_failure(_EXIT_CODE)                                            \
  ({                                                                           \
    _wxtrace_log("ASSERTION_FAILURE - EXIT_CODE=%d", (_EXIT_CODE));            \
    exit((_EXIT_CODE));                                                        \
  })
#else
#define exit_on_failure(_EXIT_CODE) ({ exit((_EXIT_CODE)); })
#endif
#define DEFAULT_EXIT_CODE (-1)
/** @brief Function like macro used for assertion statically
 * 	@attention
 * 		This function like macro is compatible starts from GCC-89/90
 */
#define STATIC_ASSERT(EXPRESSION, _EXIT_CODE)                                  \
  ({ (EXPRESSION) ? (NULL) : (exit_on_failure(_EXIT_CODE)); })
#endif
/**
 * @def Debugging/Logging Configuration Parameters
 */
#define WXTRACE_LOG_STATE_INACTIVE (0)
#define WXTRACE_LOG_STATE_ACTIVE (1)
/**
 * @def Configuration Parameters
 *    @arg WXTRACE_LOG_STATE_ACTIVE
 *    @arg WXTRACE_LOG_STATE_INACTIVE
 */
#define WXTRACE_LOG_STATE (WXTRACE_LOG_STATE_ACTIVE)

/*
 * ================================================================================================================================
 * -> Private Structs
 * ================================================================================================================================
 **/

/**
 * @brief linked list main building block;
 *        used for inhertiance.
 */
_FORCE_PACKING(0)
struct linkedlist_ancestor {
  struct linkedlist_ancestor *next;
  void *data;
};
/** @brief Usability typedef */
typedef struct linkedlist_ancestor lg_st_ll_ancestor_t;

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

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status ll_create_heap(lg_st_ll_ancestor_t **pa_ll_node);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status ll_append_node(
    lg_st_ll_ancestor_t **_CONST pa_ll_head, void *_CONST pa_ll_node_data);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status ll_push_node(
    lg_st_ll_ancestor_t **_CONST pa_ll_head, void *_CONST pa_ll_node_data);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status
ll_insert_node_kth(lg_st_ll_ancestor_t *_CONST pa_ll_head,
                   void *_CONST pa_ll_node_data, _CONST uint64 a_ll_kth_node);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status ll_remove_node_kth(
    lg_st_ll_ancestor_t *_CONST pa_ll_head, _CONST uint64 a_ll_kth_node);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status
ll_remove_node_end(lg_st_ll_ancestor_t *pa_ll_head);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status
ll_remove_node_begin(lg_st_ll_ancestor_t *pa_ll_head);

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status ll_node_init(
    lg_st_ll_ancestor_t **_CONST pa_ll_node, void *_CONST pa_ll_node_data);

/*
 * ================================================================================================================================
 * -> Public Functions Implementation
 * ================================================================================================================================
 **/

void portal_test(void) {

  lg_st_ll_ancestor_t *myList = NULL;

  char name[] = "Mohamed";
  char name2[] = "Body";

#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("&name = %p", &name);
#endif

  en_ll_log_status test = LOG_INFO_OK;

  register uint8 i = 0;

  test = ll_append_node(&myList, &name);
  test = ll_append_node(&myList, &name);
  test = ll_append_node(&myList, &name);
  test = ll_append_node(&myList, &name);
  test = ll_append_node(&myList, &name);
  test = ll_insert_node_kth(myList, &name2, 2);
  test = ll_insert_node_kth(myList, &name2, 2);
  test = ll_remove_node_end(myList);
  test = ll_remove_node_begin(myList);

  for (i = 0; myList != NULL;) {
    printf("%s\n", myList->data);
    myList = myList->next;
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
 * @details Explained..
 * *         main stack frame       ll_create_heap stack frame
 * *         +-+                    +-+ `Passed using double pointer`
 * *         | | &passed_ptr   ->   | | passed_ptr=new_head
 * *         +-+                    +-+
 * =After function terminating (Context switched)
 * *         main stack frame
 * *         +-+
 * *         | | passed_ptr=new_head
 * *         +-+
 *
 * @param pa_ll_node
 * @return en_ll_log_status
 */
_LOCAL_INLINE en_ll_log_status
ll_create_heap(lg_st_ll_ancestor_t **pa_ll_node) {
  en_ll_log_status l_this_function_log_status = LOG_STATUS_NOT_OK;
  if ((NULL == (*pa_ll_node))) {
    lg_st_ll_ancestor_t *new_node =
        (lg_st_ll_ancestor_t *)malloc(sizeof(lg_st_ll_ancestor_t));
    if ((NULL == new_node)) {
      l_this_function_log_status = LOG_ERROR_INVALID_ALLOCATION;
    } else {
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
      _wxtrace_log("new_node heap allocated address = %p", new_node);
#endif
      new_node->data = NULL;
      new_node->next = NULL;
      *pa_ll_node = new_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
      _wxtrace_log("pa_ll_node = %p", *pa_ll_node);
#endif
      l_this_function_log_status = LOG_STATUS_OK;
    }
  }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("l_this_function_log_status: %d", l_this_function_log_status);
#endif
  return l_this_function_log_status;
}

/**
 * @brief Function to insert a node in front (appending).
 * @note Simple iterator algorithm (to be modifed with front, rear).
 *
 * @details Explained..
 * - passed reference to head
 *    * head is NULL
 *         |
 * Create new node let the head point to it
 *     `new_node`
 * *        +-+
 * * head-> | | ->NULL
 * *        +-+
 *    * head isn't NULL
 *        |
 * Iterate through the passed reference to the list `head`
 * untill the last element.
 *      `node:1` `node:n` `new_node`
 * *        +-+     +-+     +-+
 * * head-> | | ... | | ->  | | ->NULL
 * *        +-+     +-+     +-+
 * @note Other validations are defined.
 *
 * @param pa_ll_head
 * @param pa_ll_node_data
 * @return en_ll_log_status
 */
_LOCAL_INLINE en_ll_log_status ll_append_node(
    lg_st_ll_ancestor_t **_CONST pa_ll_head, void *_CONST pa_ll_node_data) {
  en_ll_log_status l_this_function_log_status = LOG_STATUS_NOT_OK;
  lg_st_ll_ancestor_t *lp_temp_to_head = *pa_ll_head;
  lg_st_ll_ancestor_t *new_node = NULL;
  en_ll_log_status l_create_heap_function_status = ll_create_heap(&new_node);
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("lp_temp_to_head = %p", lp_temp_to_head);
  _wxtrace_log("new_node = %p", new_node);
#endif
  if ((LOG_STATUS_OK == l_create_heap_function_status)) {
    en_ll_log_status l_node_init_function_status =
        ll_node_init(&new_node, pa_ll_node_data);
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log("new_node->next = %p", new_node->next);
    _wxtrace_log("new_node->data = %p", new_node->data);
#endif
    if ((LOG_STATUS_OK == l_node_init_function_status)) {
      /** @brief If the passed list is in its initial */
      if ((NULL == lp_temp_to_head)) {
        if ((NULL != pa_ll_node_data)) {
          *pa_ll_head = new_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
          _wxtrace_log("new_node->data = %p", new_node->data);
          _wxtrace_log("*pa_ll_head = %p", *pa_ll_head);
#endif
          l_this_function_log_status = LOG_STATUS_OK;
        } else {
          free(new_node);
          l_this_function_log_status = LOG_ERROR_NULL;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
          _wxtrace_log(" ");
#endif
        }
        /** @brief If the passed list is already initalized */
      } else {
        while ((NULL != lp_temp_to_head->next)) {
          lp_temp_to_head = lp_temp_to_head->next;
        }
        lp_temp_to_head->next = new_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
        _wxtrace_log("new_node->data = %p", new_node->data);
        _wxtrace_log("*pa_ll_head = %p", *pa_ll_head);
#endif
        l_this_function_log_status = LOG_STATUS_OK;
      }
    } else {
      free(new_node);
      l_this_function_log_status = l_node_init_function_status;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
      _wxtrace_log(" ");
#endif
    }
  } else {
    free(new_node);
    l_this_function_log_status = l_create_heap_function_status;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log(" ");
#endif
  }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("l_this_function_log_status: %d", l_this_function_log_status);
#endif
  return l_this_function_log_status;
}

/**
 * @brief Function to insert a node in back (pushing).
 * @note Simple iterator algorithm (to be modifed with front, rear).
 *
 * @details Explained..
 * - passed reference to head
 *    * head is NULL
 *         |
 * Create new node let the head point to it
 *     `new_node`
 * *        +-+
 * * head-> | | ->NULL
 * *        +-+
 *    * head isn't NULL
 *        |
 * Let the next of the new node assigned with the head,
 * let the head assigned with the new node.
 *       `new_node` `node:2` `node:n`
 * *         +-+       +-+     +-+
 * * head->  | | ->	   | | ... | | -> NULL
 * *         +-+       +-+     +-+
 * @note Other validations are defined.
 *
 * @param pa_ll_head
 * @param pa_ll_node_data
 * @return en_ll_log_status
 */
_LOCAL_INLINE en_ll_log_status ll_push_node(
    lg_st_ll_ancestor_t **_CONST pa_ll_head, void *_CONST pa_ll_node_data) {
  en_ll_log_status l_this_function_log_status = LOG_STATUS_NOT_OK;
  lg_st_ll_ancestor_t *lp_temp_to_head = *pa_ll_head;
  lg_st_ll_ancestor_t *new_node = NULL;
  en_ll_log_status l_create_heap_function_status = ll_create_heap(&new_node);
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("lp_temp_to_head = %p", lp_temp_to_head);
  _wxtrace_log("new_node = %p", new_node);
#endif
  if ((LOG_STATUS_OK == l_create_heap_function_status)) {
    en_ll_log_status l_node_init_function_status =
        ll_node_init(&new_node, pa_ll_node_data);
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log("new_node->next = %p", new_node->next);
    _wxtrace_log("new_node->data = %p", new_node->data);
#endif
    if ((LOG_STATUS_OK == l_node_init_function_status)) {
      /** @brief If the passed list is in its initial */
      if ((NULL == lp_temp_to_head)) {
        if ((NULL != pa_ll_node_data)) {
          *pa_ll_head = new_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
          _wxtrace_log("new_node->data = %p", new_node->data);
          _wxtrace_log("*pa_ll_head = %p", *pa_ll_head);
#endif
          l_this_function_log_status = LOG_STATUS_OK;
        } else {
          free(new_node);
          l_this_function_log_status = LOG_ERROR_NULL;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
          _wxtrace_log(" ");
#endif
        }
        /** @brief If the passed list is already initalized */
      } else {
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
        _wxtrace_log("current head = %p", lp_temp_to_head);
#endif
        new_node->next = lp_temp_to_head;
        *pa_ll_head = new_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
        _wxtrace_log("new_node->next = %p", new_node->next);
        _wxtrace_log("*pa_ll_head = %p", *pa_ll_head);
#endif
        l_this_function_log_status = LOG_STATUS_OK;
      }
    } else {
      free(new_node);
      l_this_function_log_status = l_node_init_function_status;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
      _wxtrace_log(" ");
#endif
    }
  } else {
    free(new_node);
    l_this_function_log_status = l_create_heap_function_status;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log(" ");
#endif
  }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("l_this_function_log_status: %d", l_this_function_log_status);
#endif
  return l_this_function_log_status;
}

/**
 * @brief Function to insert a node in kth node.
 * @note Simple iterator algorithm (to be modifed with front, rear).
 *
 * @details Explained..
 * - passed reference to head
 *    * head is not equal to NULL
 *         |
 * Create new node.
 * Iterate `kth` number through the passed list.
 *		* if node exists and there is available slot to the new node.
 * 						|
 * iterate till (iterator < kth-1)
 *         `node:n` `new_node` `node:n+1`
 * *				  +-+		 +-+			+-+
 * *	...			| | -> | | -> 	| | ...
 * *				  +-+		 +-+			+-+
 * @note Other validations are defined.
 *
 * @param pa_ll_head
 * @param pa_ll_node_data
 * @param a_ll_kth_node
 * @return _LOCAL_INLINE
 */
_LOCAL_INLINE en_ll_log_status
ll_insert_node_kth(lg_st_ll_ancestor_t *_CONST pa_ll_head,
                   void *_CONST pa_ll_node_data, _CONST uint64 a_ll_kth_node) {
  en_ll_log_status l_this_function_log_status = LOG_STATUS_NOT_OK;
  lg_st_ll_ancestor_t *new_node = NULL;
  en_ll_log_status l_create_heap_function_status = ll_create_heap(&new_node);
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("pa_ll_head = %p", pa_ll_head);
  _wxtrace_log("new_node = %p", new_node);
#endif
  if ((LOG_STATUS_OK == l_create_heap_function_status)) {
    en_ll_log_status l_node_init_function_status =
        ll_node_init(&new_node, pa_ll_node_data);
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log("new_node->next = %p", new_node->next);
    _wxtrace_log("new_node->data = %p", new_node->data);
#endif
    if ((LOG_STATUS_OK == l_node_init_function_status)) {
      /** @brief If the passed list is in its initial */
      if ((NULL == pa_ll_head)) {
        l_this_function_log_status = LOG_STATUS_INVALID_KTH;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
        _wxtrace_log(" ");
#endif
        /** @brief If the passed list is already initalized */
      } else {
        register uint64 l_list_iterator = 0;
        lg_st_ll_ancestor_t *lp_temp_to_head = pa_ll_head;
        while ((l_list_iterator < (a_ll_kth_node - 1))) {
          lp_temp_to_head = lp_temp_to_head->next;
          ++l_list_iterator;
        }
        if ((NULL != lp_temp_to_head) && (NULL != lp_temp_to_head->next)) {
          new_node->next = lp_temp_to_head->next;
          lp_temp_to_head->next = new_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
          _wxtrace_log("new_node->next = %p", new_node->next);
          _wxtrace_log("lp_temp_to_head->next = %p", lp_temp_to_head->next);
#endif
          l_this_function_log_status = LOG_STATUS_OK;
        } else {
          l_this_function_log_status = LOG_STATUS_INVALID_KTH;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
          _wxtrace_log(" ");
#endif
        }
      }
    } else {
      free(new_node);
      l_this_function_log_status = l_node_init_function_status;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
      _wxtrace_log(" ");
#endif
    }
  } else {
    free(new_node);
    l_this_function_log_status = l_create_heap_function_status;
  }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("l_this_function_log_status: %d", l_this_function_log_status);
#endif
  return l_this_function_log_status;
}

/**
 * @brief Function to remove a node at end of a list.
 *
 * @details Explained..
 *
 *
 * @param pa_ll_head
 * @return en_ll_log_status
 */
_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status
ll_remove_node_end(lg_st_ll_ancestor_t *pa_ll_head) {
  en_ll_log_status l_this_function_log_status = LOG_STATUS_NOT_OK;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("pa_ll_head: %p", pa_ll_head);
#endif
  if ((NULL != pa_ll_head)) {
    lg_st_ll_ancestor_t *lp_temp_to_head = pa_ll_head;
    while ((NULL != pa_ll_head->next)) {
      pa_ll_head = pa_ll_head->next;
    }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log("pa_ll_head=%p", pa_ll_head);
#endif
    while ((NULL != lp_temp_to_head->next->next)) {
      lp_temp_to_head = lp_temp_to_head->next;
    }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log("lp_temp_to_head=%p", lp_temp_to_head);
#endif
    lp_temp_to_head->next = NULL;
    free(pa_ll_head);
    l_this_function_log_status = LOG_STATUS_OK;
  } else {
    l_this_function_log_status = LOG_ERROR_NULL;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log("Empty List");
#endif
  }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("l_this_function_log_status: %d", l_this_function_log_status);
#endif
  return l_this_function_log_status;
}

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status
ll_remove_node_begin(lg_st_ll_ancestor_t *_CONST pa_ll_head) {

  /** @todo */
}

_FORCE_INLINE
_LOCAL_INLINE en_ll_log_status ll_remove_node_kth(
    lg_st_ll_ancestor_t *_CONST pa_ll_head, _CONST uint64 a_ll_kth_node) {

  /** @todo */
}

/**
 * @brief Function to initalize a node.
 *
 * @param pa_ll_node
 * @param pa_ll_node_data
 * @return _LOCAL_INLINE
 */
_LOCAL_INLINE en_ll_log_status ll_node_init(
    lg_st_ll_ancestor_t **_CONST pa_ll_node, void *_CONST pa_ll_node_data) {
  en_ll_log_status l_this_function_log_status = LOG_STATUS_NOT_OK;
  lg_st_ll_ancestor_t *lp_temp_ptr_to_node = *pa_ll_node;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("lp_temp_ptr_to_node = %p", lp_temp_ptr_to_node);
#endif
  if ((NULL != lp_temp_ptr_to_node)) {
    lp_temp_ptr_to_node->next = NULL;
    lp_temp_ptr_to_node->data = pa_ll_node_data;
    l_this_function_log_status = LOG_STATUS_OK;
  } else {
    l_this_function_log_status = LOG_STATUS_INVALID_ARGUMENT;
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
    _wxtrace_log(" ");
#endif
  }
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("lp_temp_ptr_to_node->next = %p", lp_temp_ptr_to_node->next);
  _wxtrace_log("lp_temp_ptr_to_node->data = %p", lp_temp_ptr_to_node->data);
#endif
#if (WXTRACE_LOG_STATE == WXTRACE_LOG_STATE_ACTIVE)
  _wxtrace_log("l_this_function_log_status: %d", l_this_function_log_status);
#endif
  return l_this_function_log_status;
}
