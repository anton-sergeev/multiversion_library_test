
#include <stdio.h>
#include <A.h>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  printf("  main_A->");
  call_A();
  return 0;
}
