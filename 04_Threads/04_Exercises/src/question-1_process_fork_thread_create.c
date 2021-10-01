#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void *runner(void *param); // the thread

int main(int argc, char *argv[])
{
	pid_t pid1;
	pid_t pid2;
	pid_t pid3;
	
	printf("I am the original process              pid = %d",getpid());
	printf(". tid = %d.\n", pthread_self());
	
	// fork a child process
	pid1 = fork();

	if (pid1 < 0) // error occurred
	{
		fprintf(stderr, "Original process fork failed\n");
		return 1;
	}
	else if (pid1 == 0) // child process
	{
		pthread_t tid; // the thread identifier
		pthread_attr_t attr; // set of attributes for the thread
		printf(" > I am the child process.             pid = %d",getpid());
		printf(". tid = %d.\n", pthread_self());
		
		pid2 = fork();
		// get the default attributes
		pthread_attr_init(&attr);

		// create the thread
		pthread_create(&tid, &attr, runner, argv[1]);
		
		printf(" > # Thread printing something.        pid = %d", getpid());
		printf(". tid = %d.\n", pthread_self());
		
		// now wait for the thread to exit
		// pthread_join(tid, NULL);
		
		if (pid2 < 0) // error occurred
		{
			fprintf(stderr, "Child's process fork failed\n");
			return 1;
		}
		else if (pid2 == 0) // child process
		{
			printf(" >> I am the child's child process.    pid = %d",getpid());
			printf(". tid = %d.\n", pthread_self());
		}
		else // parent process
		{
			// parent will wait for the child to complete
			printf(" >> I am the child's parent process.   pid = %d",getpid());
			printf(". tid = %d.\n", pthread_self());
			
			wait(NULL);
		
			printf("Child's child complete\n");
		}
	}
	else // parent process
	{
		// parent will wait for the child to complete
		printf(" > I am the parent process.            pid = %d",getpid());
		printf(". tid = %d.\n", pthread_self());
		
		wait(NULL);
		
		printf("Child Complete\n");
		
		
	}
	
	pid3 = fork();
	
	printf("After 3° fork, I'm printing something. pid = %d",getpid());
	printf(". tid = %d.\n", pthread_self());
    
    return 0;
}

void *runner(void *param)
{
	printf(" > # Thread runner printing something. pid = %d", getpid());
	printf(". tid = %d.\n", pthread_self());

	pthread_exit(0);
}
