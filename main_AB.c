
#include <stdio.h>
#include <A.h>
#include <B.h>

int main(int argc, char **argv)
{
  printf(" main_AB->");
  call_A();
  printf(" main_AB->");
  call_B();
  return 0;
}
