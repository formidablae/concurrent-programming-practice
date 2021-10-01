#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid, pid1;
	
	// create a child process using fork
	pid = fork();
	
	if (pid < 0)
	{
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if (pid == 0) // no error, child process
	{
		pid1 = getpid();
		printf("child: pid = %d\n", pid);		// LINE A
		printf("child: pid1 = %d\n", pid1);		// LINE B
	}
	else // no error, parent process
	{
		pid1 = getpid();
		printf("parent: pid = %d\n", pid);		// LINE C
		printf("parent: pid1 = %d\n", pid1);	// LINE D
		wait(NULL);
	}
	
	return 0;
}
