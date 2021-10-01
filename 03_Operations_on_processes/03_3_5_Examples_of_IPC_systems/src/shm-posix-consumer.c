#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	const int SIZE = 4096; // Dimension in bytes of the shared memory object
	const char *name = "OS"; // Name of the shared memory object

	int shm_fd; // Decriptor of the shared memory file
	void *ptr; // Pointer to the shared memory object
	int i;

	// Open the shared memory segment
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if (shm_fd == -1)
	{
		printf("shared memory failed\n");
		exit(-1);
	}

	// Map the shared memory segment in the address space of the process
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED)
	{
		printf("Map failed\n");
		exit(-1);
	}

	// Read from the shared memory region
	printf("%s",ptr);

	// Remove the shared memory segment
	if (shm_unlink(name) == -1)
	{
		printf("Error removing %s\n",name);
		exit(-1);
	}

	return 0;
}
