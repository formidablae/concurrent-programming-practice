#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	const int SIZE = 4096; // Dimension in bytes of the shared memory object
	const char *name = "OS"; // Name of the shared memory object
	const char *message0= "Studying "; // Message
	const char *message1= "Operating Systems and Cuncurrent programming"; // Message
	const char *message2= "is fun!"; //Message

	int shm_fd; // Decriptor of the shared memory file
	void *ptr; // Pointer to the shared memory object

	// Create the shared memory segment
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	// Configure the size of the shared memory segment
	ftruncate(shm_fd,SIZE);

	// Map the shared memory segment in the address space of the process
	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED)
	{
		printf("Map failed\n");
		return -1;
	}

	/**
	 * Write to the shared memory region.
 	 *
	 * Increment the value of ptr after each write.
	 */
	sprintf(ptr,"%s",message0);
	ptr += strlen(message0);
	sprintf(ptr,"%s",message1);
	ptr += strlen(message1);
	sprintf(ptr,"%s",message2);
	ptr += strlen(message2);

	return 0;
}
