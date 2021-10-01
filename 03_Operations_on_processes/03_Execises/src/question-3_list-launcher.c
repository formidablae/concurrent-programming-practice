#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	
	// create child process
	pid = fork();
	
	if (pid < 0) // error
	{
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if (pid == 0) // no error, child process
	{
		execlp("/bin/ls", "ls", NULL);
		printf("LINE J");
	}
	else // no error, parent process
	{
		wait(NULL);
		printf("Child complete");
	}
	
	return 0;
}
