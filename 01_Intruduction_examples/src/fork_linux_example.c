/**
 * This program forks a separate process using the fork()/exec() system calls.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid;

	// fork a child process
	pid = fork();

	if (pid < 0) // error occurred
  	{
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0) // child process
  	{
		printf("I am the child %d\n",pid);
		execlp("/bin/ls","ls",NULL);
	}
	else // parent process
  	{
		// parent will wait for the child to complete
		printf("I am the parent %d\n",pid);
		wait(NULL);

		printf("Child Complete\n");
		exit(0);
	}
}
