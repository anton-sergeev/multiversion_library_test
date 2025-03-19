
#include <stdio.h>
#include <C.h>

#include "A.h"

int call_A(void)
{
  printf("call_A->");
  if(call_C() != 1) {
    printf("    # <- wrong");
  }
  printf("\n");

  return 0;
}

