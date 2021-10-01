# Thread Summation

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/04_Threads/04_4_4_Thread_Summation/
```

To compile run:

```sh
gcc src/thrd-posix.c -lpthread -o bin/thrd-posix.out
```

To execute run:

```sh 
bin/thrd-posix.out 4
```

## On Windows operating systems
Install MinGW GCC or [Cygwin GCC](https://www.ntu.edu.sg/home/ehchua/programming/howto/Cygwin_HowTo.html).

[More on gcc](https://www.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html).

Using CMD, navigate to the directory where you have saved the files of this repository:

```sh
cd c:\Path\To\Repo\04_Threads\04_4_4_Thread_Summation\
```

To compile run:

```sh
gcc src\thrd-win32.c -o bin\thrd-win32.exe
```

## Java Thread
Install [Java JDK](https://www.oracle.com/technetwork/java/javase/overview/index.html).

Using a terminal, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/04_Threads/04_4_4_Thread_Summation/
```

To compile run:

```sh
javac src/Driver.java -d bin/
```

To execute run:

```sh
java -cp bin Driver 4
```

# Definitions

## Pthreads

`runner()`: function that starts the execution of a thread.

`pthread_t tid`: thread's identificator.

`pthread_attr_t attr`: data structure of the to attributes of the to be created thread.

`pthread_create()`: creates a new thread.

`pthread_join()`: waits for the created thread to exit.

`pthread_exit()`: terminates a thread.

## Threads in Windows

`LPVOIP`: Windows pointer to `void`.

`CreateThread()`: creates a new thread. Equivalent of `pthread_create()` in pthreads.

`WaitForSingleObjects()`: waits for the created thread to exit. Equivalent of `pthread_join()` in pthreads.

## Java Threads

`Runnable`: interface to be implemented by a class whose thread will be created.

`run()`: method of the `Runnable` interface. It's implementation is defined by a class whose thread will be created. It is not called directly, only by calling `start()`.

`new Thread()`: creates a new thread. Equivalent of `pthread_create()` in pthreads and `CreateThread()` in Windows threads.

`start()`: method called to start a newly created thread.

`join()`: waits for the created thread to finish. Equivalent of `pthread_join()` in pthreads and `WaitForSingleObjects()` in Windows threads.
