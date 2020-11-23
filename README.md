# J3DE native

Java 3D Engine native implementation.
Sub project of [Java 3D Engine](https://github.com/ZXseITz/zx-j3de).


## jni headers

To create the jni header files, build the `j3de_generate_header` target.
This target executes the `javac -h` command and saves the header files into `./header/<header_name>.h`.

## build dll

To create the dynamic link library implement the header files in `./source/<header_name>.cpp` first
and execute the `j3de_native` target afterwards.
This target builds the dll and if the mode is release this target moves the output dll to the main project