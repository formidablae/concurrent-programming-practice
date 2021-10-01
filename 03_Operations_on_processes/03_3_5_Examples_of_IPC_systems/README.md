# 3_5_Examples_of_IPC_systems

# Compilation and execution istructions
For compilation and execution use the following commands:

## On Linux-like operating systems
C (GNU Toolchain) is already included in all Unix like systems.

Using a terminal shell, navigate to the directory where you have saved the files of this repository:

```sh
cd ~/Path/To/Repo/03_Operations_on_processes/03_3_5_Examples_of_IPC_systems/
```

To compile run:

```sh
gcc src/shm-posix-producer.c -o bin/shm-posix-producer.out
gcc src/shm-posix-consumer.c -o bin/shm-posix-consumer.out
```

To execute run:

```sh
./bin/shm-posix-producer.out
./bin/shm-posix-consumer.out
```

# Definitions

The meaning of some calls of the POSIX API:

`shm_open()`: creates a shared memory object.

`O_CREAT`: create if doesn't exist.

`O_RDRW`: create if object is opened in read/write mode.

`ftruncate()`: truncates the dimension of the shared memory object to the indicated size.

`mmap()`: maps the shared memory object in memory returning a pointer to access it.

`shm_unlink()`: removes the shared memory segment after it has been accessed by the consumer.
