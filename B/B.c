
#include <stdio.h>
#include <C.h>

#include "B.h"

int call_B(void)
{
  printf("call_B->");
  call_C();
  return 0;
}

