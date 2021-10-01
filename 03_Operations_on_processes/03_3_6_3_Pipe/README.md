 # Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/03_Operations_on_processes/03_3_6_3_Pipe/
```

To compile run:

```sh
gcc src/unix_pipe.c -o bin/unix_pipe.out
```

To execute run:

```sh
./bin/unix_pipe.out
```

## On Windows operating systems
Install MinGW GCC or [Cygwin GCC](https://www.ntu.edu.sg/home/ehchua/programming/howto/Cygwin_HowTo.html).

[More on gcc](https://www.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html).

Using CMD, navigate to the directory where you have saved the files of this repository:

```sh
cd c:\Path\To\Repo\03_Operations_on_processes\03_3_6_3_Pipe\
```

To compile run:

```sh
gcc src\win32-pipe-parent.c -o bin\win32-pipe-parent.exe
gcc src\win32-pipe-child.c -o bin\win32-pipe-child.exe
```

To execute run:

```sh
bin\win32-pipe-parent
bin\win32-pipe-child
```

# Definitions

##Posix API pipes:

`pipe()`: creates a pipe.

`read()`: reads from an end of the pipe.

`write()`: writes to an end of the pipe.

`close()`: closes un end of the pipe.

##Windows API pipes:

`HANDLE`: a HANDLE in Win32 programming is a token that represents a resource that is managed by the Windows kernel. A handle can be to a window, a file, etc. Handles are simply a way of identifying a particulate resource that you want to work with using the Win32 APIs.

`STARTUPINFO`: specifies the window station, desktop, standard handles, and appearance of the main window for a process at creation time.

`PROCESS_INFORMATION`: information about a newly created process and its primary thread.

`DWORD`: is a 32-bit unsigned integer (range: 0 through 4294967295 decimal). Because a DWORD is unsigned, its first bit (Most Significant Bit (MSB)) is not reserved for signing.

`SECURITY_ATTRIBUTES`: contains the security descriptor for an object and specifies whether the handle retrieved by specifying this structure is inheritable.

`ZeroMemory()`: allocates memory for the new process.

`CreatePipe()`: creates a pipe.

`GetStartupInfo()`: retrieves the contents of the STARTUPINFO structure that was specified when the calling process was created.

`hStdOutput`: standard output handle of the child process.

`hStdInput`: standard input handle of the child process.

`GetStdHandle()`: retrieves a handle to the specified standard device (standard input, standard output, or standard error).

`dwFlags`: 

`SetHandleInformation()`: sets certain properties of an object handle.

`CreateProcess()`: starts a new process (fork).

`CloseHandle()`: sloses an open object handle.

`WriteFile()`: writes data to the specified file or input/output (I/O) device. This function is designed for both synchronous and asynchronous operation.

`WaitForSingleObject()`: waits until the specified object is in the signaled state or the time-out interval elapses (For example, until a child process has terminated).

`hProcess`:

`hThread`:
