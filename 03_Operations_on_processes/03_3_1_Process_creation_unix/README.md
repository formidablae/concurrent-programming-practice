# 3_3_1_Process_creation_unix

Code on process creation in unix/linux-like operation systems.

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/03_Operations_on_processes/03_3_1_Process_creation_unix/
```

To compile run:

```sh
gcc src/newproc-posix.c -o bin/newproc-posix.out
```

To execute run:

```sh
./bin/newproc-posix.out
```

# Definitions

`pid` integer identifier of a process.

The header file `unistd.h` provides access to the POSIX operating system API. The meaning of some calls:

`open()`, `read()`, `write()`, `close()` are used for file manipulation.

Process control calls:

`fork()`: creates a new child process.

`wait()`: makes a process wait.

`execlp()`: the `exec()` family of functions replaces the current process image with a new process image.
