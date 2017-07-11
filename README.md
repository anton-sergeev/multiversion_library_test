# Multiversion library test
Test linux linking the next situation: two libraries depends on different versions third library.

This code based on [this stackoverflow answer](https://stackoverflow.com/a/44686776/1677270). dlopen-variant is based on [this stackoverflow answer](https://stackoverflow.com/a/3249833/1677270).

## Functions calls scheme

```
main_A.exe ───┮━━━> libA ━━━━> libC.v1
              │
main_AB.exe ──┤
              │
main_B.exe ───┶━━━> libB ━━━━> libC.v2
```


## How to build and run

You can choose compiler by setting CC environment.
For using GCC:
```bash
CC=/usr/bin/gcc
```
For using Clang:
```bash
CC=/usr/bin/clang
```

Build:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run tests:
```bash
for i in ./main_A.* ./main_B.* ./main_AB.*; do echo "$i:"; LD_LIBRARY_PATH=./A:./B:$LD_LIBRARY_PATH $i; do
```

## Results for Ubuntu 16.04.02

Result the same for both GCC and Clang:
```
./main_A.shared:
 main_A->call_A->call_C (v1)
./main_A.static:
 main_A->call_A->call_C (v1)
./main_B.shared:
 main_B->call_B->call_C (v2)
./main_B.static:
 main_B->call_B->call_C (v2)
./main_AB.dlopen:
 main_AB->call_A->call_C (v1)    # <- correct
 main_AB->call_B->call_C (v2)    # <- correct
./main_AB.shared:
 main_AB->call_A->call_C (v1)    # <- correct
 main_AB->call_B->call_C (v1)    # <- wrong
./main_AB.static:
 main_AB->call_A->call_C (v1)    # <- correct
 main_AB->call_B->call_C (v1)    # <- wrong
 ```
