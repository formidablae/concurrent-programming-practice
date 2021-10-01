# Process creation in Windows

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Windows operating systems
Install MinGW GCC or [Cygwin GCC](https://www.ntu.edu.sg/home/ehchua/programming/howto/Cygwin_HowTo.html).

[More on gcc](https://www.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html).

Using CMD, navigate to the directory where you have saved the files of this repository:

```sh
cd c:\Path\To\Repo\03_Operations_on_processes\03_3_1_Process_creation_windows\
```

To compile run:

```sh
gcc src\newproc-win32.c -o bin\newproc-win32.exe
```

To execute run:

```sh
bin\newproc-win32
```

# Definitions

`pid` integer identifier of a process.

The header file `unistd.h` provides access to the Windows operating system API. The meaning of some functions:

`open()`, `read()`, `write()`, `close()` used for file manipulation.

Process control calls:

`CreateProcess()`: creates a new child process.

`WaitForSingleObject()`: makes a process wait the termination of its child.

`ZeroMemory()`: allocates memory.

`CloseHandle()`: closes process or thread handles.
