
#include <stdio.h>
#include <B.h>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  printf("  main_B->");
  call_B();
  return 0;
}
