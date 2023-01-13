/**
 * @file main.c
 * @author Mohamed Wx (wx@wx.com)
 * @brief The main entry point for the program
 * @version 0.1
 * @date 2023-01-07
 *
 * @copyright Copyright (c) 2023
 *
 */

/** @defgroup Included headers */
#include "linked_c.h"
#include <stdio.h>

int main(void) {

  // portal_test();

  en_ll_user_status status = 0;
  sll_class sll_instance = sll_getInstance(&status);

  double data = 5.0;
  sll_append(sll_instance, &data);

  printf("\n");
  while (1) {
    ;
  }

  return 0;
}
