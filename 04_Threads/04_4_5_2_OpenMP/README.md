# OpenMP

Example of openmp parallel region

You should see the message "I am a parallel region" for each processing core on your system.

If you are running this in a virtual machine, make sure you set the number of processing cores > 1 to see parallel execution of the parallel region.

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/04_Threads/04_4_5_2_OpenMP/
```

To compile run:

```sh
gcc -fopenmp src/openmp.c -o bin/openmp.out
```

To execute run:

```sh 
bin/openmp.out
```
# Definitions

`omp.h`: OpenMP header.

`#pragma omp parallel`: is used to fork additional threads to carry out the work enclosed in the construct in parallel. The original thread will be denoted as master thread with thread ID 0.
