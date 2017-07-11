
#include <stdio.h>
#include <C.h>

#include "A.h"

int call_A(void)
{
  printf("call_A->");
  call_C();
  return 0;
}

