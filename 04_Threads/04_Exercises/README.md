# Exercises

Exercises

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/04_Threads/04_Exercises
```

To compile run:

```sh
gcc src/question-1_process_fork_thread_create.c -o bin/question-1_process_fork_thread_create.out -lpthread
```

To execute run:

```sh
./bin/question-1_process_fork_thread_create.out
```

# Questions

`question-1_process_fork_thread_create.c`: How many distinct processes and threads are created?

# Answers

`question-1_process_fork_thread_create.c`: 6 processes are in total created of which 4 have 2 threads each and the remaining 2 have only 1 thread (LWP).
