
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// #define DLOPEN_FLAGS RTLD_LAZY | RTLD_LOCAL
#define DLOPEN_FLAGS RTLD_LAZY

#if defined(_WIN32) || defined(__CYGWIN__)
    // Windows (x86 or x64)
    const char* libA = "libA.shared.dll";
    const char* libB = "libB.shared.dll";
#elif defined(__linux__)
    // Linux
    const char* libA = "libA.shared.so";
    const char* libB = "libB.shared.so";
#elif defined(__APPLE__) && defined(__MACH__)
    // Mac OS
    const char* libA = "libA.shared.dylib";
    const char* libB = "libB.shared.dylib";
#elif defined(unix) || defined(__unix__) || defined(__unix)
    // Unix like OS
    const char* libA = "libA.shared.so";
    const char* libB = "libB.shared.so";
#else
    #error Unknown environment!
#endif

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  void *handle_A;
  void *handle_B;
  int (*call_A)(void);
  int (*call_B)(void);
  char *error;

  handle_B = dlopen(libB, DLOPEN_FLAGS);
  if(handle_B == NULL) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  handle_A = dlopen(libA, DLOPEN_FLAGS);
  if(handle_A == NULL) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }


  call_A = dlsym(handle_A, "call_A");
  error = dlerror();
  if(error != NULL) {
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
  }
  call_B = dlsym(handle_B, "call_B");
  error = dlerror();
  if(error != NULL) {
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
  }

  printf("  main_AB->");
  call_A();
  printf("  main_AB->");
  call_B();

  dlclose(handle_B);
  dlclose(handle_A);

  return 0;
}
