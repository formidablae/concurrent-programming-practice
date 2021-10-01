# Exercises

Exercises

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/03_Operations_on_processes/03_Exercises/
```

To compile run:

```sh
gcc src/question-1_fork.c -o bin/question-1_fork.out
gcc src/question-2_fork.c -o bin/question-2_fork.out
gcc src/question-3_list-launcher.c -o bin/question-3_list-launcher.out
gcc src/question-4_pid-numbers.c -o bin/question-4_pid-numbers.out
gcc src/question-5_minus-square.c -o bin/question-5_minus-square.out
gcc src/problem-0_monitor-process.c -o bin/problem-0_monitor-process.out
gcc src/problem-1_collatz_no-fork.c -o bin/problem-1_collatz_no-fork.out
gcc src/problem-1_collatz_with-fork.c -o bin/problem-1_collatz_with-fork.out
```

To execute run:

```sh
./bin/question-1_fork.out
./bin/question-2_fork.out
./bin/question-3_list-launcher.out
./bin/question-4_pid-numbers.out
./bin/question-5_minus-square.out
./bin/problem-0_monitor-process.out
./bin/problem-1_collatz_no-fork.out 35
./bin/problem-1_collatz_with-fork.out 35
```

# Questions

`question-1_fork.c`: Explain why the output of LINE A is 5.

`question-2_fork.c`: How many processes will be created (including the parent process)?

`question-3_list-launcher.c`: Explain the circumstances under which the line of code marked printf("LINE J") will be reached.

`question-4_pid-numbers.c`: Identify the values of pid at lines A, B, C and D. (Assume that the actual pids of the parent and child are 2600 and 2603, respectively.)

`question-5_minus-square.c`: What is the output of the lines X and Y?

`monitor-process.c`: Child monitoring program.

`problem-1_collatz`: Collatz conjenture says that when to an integer n is applied interactively: n = n / 2 (if n is odd) and n = 3 * n + 1 (if n is even); at the end 1 is obtained. For example, if n = 35, the sequence produced would be: 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1 . Write a C program which takes an integer argument as input n and that uses the fork() system call to produce the Collatz sequence in the child process making parent wait the child to finish. Check for incorrect arguments inputs. n must be a positive integer.

# Answers

`question-1_fork.c`: The output of LINE A is 5 because parent and child have distinct copies of `value`.

`question-2_fork.c`: The number of created processes is 8, found by counting the unique pid outputs.

`question-3_list-launcher.c`: The call to execlp() replaces the address space of the process with the program specified as the parameter to execlp(). If the call to execlp() succeeds, the new program is now running and control from the call to execlp() never returns. In this scenario, the line printf("Line J"); would never be performed. However, if an error occurs in the call to execlp(), the function returns control and therefor the line printf("Line J"); would be performed.

`question-4_pid-numbers.c`: A = 0, B = 2603, C = 2603, D = 2600.

`question-5_minus-square.c`: Line Y prints the i-th element of the array. Line X prints the product of the i-th element of the array with -i;

`monitor-process.c`: See `src/problem-0_monitor-process.c`.

`problem-1_collatz`: See `src/problem-1_collatz_with-fork.c`.
