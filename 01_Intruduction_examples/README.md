# 01 Intruduction examples

Some examples.

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/01_Intruduction_examples/
```

To compile run:

```sh
gcc src/pipe.c -o bin/pipe.out
```

To execute run:

```sh
./bin/pipe.out
```

Do the same for the other source files.

## On Windows operating systems
Install MinGW GCC or [Cygwin GCC](https://www.ntu.edu.sg/home/ehchua/programming/howto/Cygwin_HowTo.html).

[More on gcc](https://www.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html).

Using CMD, navigate to the directory where you have saved the files of this repository:

```sh
cd c:\Path\To\Repo\01_Intruduction_examples\
```

To compile run:

```sh
gcc src\pipe.c -o bin\pipe.exe
```

To execute run:

```sh
bin\pipe
```

Do the same for the other source files.

# Definitions

`pid` integer identifier of a process.

The header file `unistd.h` provides access to the POSIX operating system API. The meaning of some calls:

`open()`, `read()`, `write()`, `close()` used for file manipulation.

Process control calls:

`fork()`: creates a new child process.

`wait()`: makes a process wait.

`exit()`: terminates the calling process.

`execlp()`: the `exec()` family of functions replaces the current process image with a new process image.

`pipe()`: used for inter-process communication.
