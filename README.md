# Multiversion library test

This repo is a test for the following situation: two libraries depend on the same third library, but different versions.

Code in this repo based on [this stackoverflow answer](https://stackoverflow.com/a/44686776/1677270).
`dlopen`-variant based on [this stackoverflow answer](https://stackoverflow.com/a/3249833/1677270).

## Function calls scheme

```text
main_A.exe ───┮━━━> libA ━━━━> libC.v1
              │
main_AB.exe ──┤
              │
main_B.exe ───┶━━━> libB ━━━━> libC.v2
```


## How to build and run

1.  (_optional_) You can choose compiler by setting CC environment.
    * For using GCC:
      ```bash
      export CC=gcc
      ```
    * For using Clang:
      ```bash
      export CC=clang
      ```
1.  Configure build:
    ```bash
    BUILD_DIR=build
    cmake -S . -B "$BUILD_DIR"
    ```
1.  Build:
    ```bash
    cmake --build "$BUILD_DIR"
    ```
1.  Run tests:
    * In Linux:
      ```bash
      for i in "$BUILD_DIR"/main_{A,B,AB}.*; do
        echo "* ${i##*/}:";
        LD_LIBRARY_PATH="$BUILD_DIR/A:$BUILD_DIR/B:$LD_LIBRARY_PATH" $i;
      done
      ```
    * In Mac:
      ```bash
      for i in "$BUILD_DIR"/main_A.* "$BUILD_DIR"/main_B.* "$BUILD_DIR"/main_AB.*; do
        echo "* $i:";
        DYLD_LIBRARY_PATH="$BUILD_DIR/A:$BUILD_DIR/B:$DYLD_LIBRARY_PATH" $i;
      done
      ```

## Results

* Ubuntu 16.04.02, CentOS 7.3: result the same for both GCC and Clang:
  ```text
  * main_A.shared:
    main_A->call_A->call_C (v1)
  * main_A.static:
    main_A->call_A->call_C (v1)
  * main_B.shared:
    main_B->call_B->call_C (v2)
  * main_B.static:
    main_B->call_B->call_C (v2)
  * main_AB.dlopen:
    main_AB->call_A->call_C (v1)
    main_AB->call_B->call_C (v2)
  * main_AB.shared:
    main_AB->call_A->call_C (v1)
    main_AB->call_B->call_C (v1)    # <- wrong
  * main_AB.static:
    main_AB->call_A->call_C (v1)
    main_AB->call_B->call_C (v1)    # <- wrong
  ```
* MacOSX El Capitan 10.11.6, result same for both GCC and Clang:
  ```text
  * main_A.shared:
    main_A->call_A->call_C (v1)
  * main_A.static:
    main_A->call_A->call_C (v1)
  * main_B.shared:
    main_B->call_B->call_C (v2)
  * main_B.static:
    main_B->call_B->call_C (v2)
  * main_AB.dlopen:
    main_AB->call_A->call_C (v1)
    main_AB->call_B->call_C (v2)
  * main_AB.shared:
    main_AB->call_A->call_C (v1)
    main_AB->call_B->call_C (v1)
  * main_AB.static:
    main_AB->call_A->call_C (v1)
    main_AB->call_B->call_C (v1)    # <- wrong
  ```


