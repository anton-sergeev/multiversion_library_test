
#include <stdio.h>
#include <C.h>

#include "B.h"

int call_B(void)
{
  printf("call_B->");
  if(call_C() != 2) {
    printf("    # <- wrong");
  }
  printf("\n");

  return 0;
}

