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
export CC=gcc
```
For using Clang:
```bash
export CC=clang
```

Build:
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Run tests using Linux:
```bash
for i in ./main_A.* ./main_B.* ./main_AB.*; do echo "$i:"; LD_LIBRARY_PATH=./A:./B:$LD_LIBRARY_PATH $i; done
```

Run tests using Mac:
```bash
for i in ./main_A.* ./main_B.* ./main_AB.*; do echo "$i:"; DYLD_LIBRARY_PATH=./A:./B:$DYLD_LIBRARY_PATH $i; done
```

## Results

Ubuntu 16.04.02, CentOS 7.3: result the same for both GCC and Clang:
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

MacOSX El Capitan 10.11.6, result same for both GCC and Clang:
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
 main_AB->call_B->call_C (v2)    # <- correct
./main_AB.static:
 main_AB->call_A->call_C (v1)    # <- correct
 main_AB->call_B->call_C (v1)    # <- wrong
 ```


