 # Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/03_Operations_on_processes/03_Project_1_UNIX_Shell/
```

To compile run:

```sh
gcc src/simple-shell.c -o bin/simple-shell.out
```

To execute run:

```sh
./bin/simple-shell.out
```

# Definitions

`fflush(stdout)`: forces a flush of all user-space buffered data for `stdout`.
