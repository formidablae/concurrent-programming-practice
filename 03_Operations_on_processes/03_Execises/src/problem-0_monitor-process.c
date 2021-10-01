#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 11			// PID is an integer whose max size is 10 digits long + 1 for the ending char
#define READ_END 0				// parent process reads form this pipe's end
#define WRITE_END 1				// child process writes to this pipe's end

int main(void)
{
	char write_message[BUFFER_SIZE];		// string vector to which the child will write the message (the child's PID number)
	char read_message[BUFFER_SIZE];		// string vector from which the parent will read the message (the child's PID number)
	
	int pipe_file_desc[2];		// pipe's argument (file descriptor array)
	pid_t pid;
	
	if (pipe(pipe_file_desc) == -1)
	{
		fprintf(stderr, "Pipe creation failed");
		return 1;
	}
	
	pid = fork();

	if (pid < 0) // failed fork
	{
		fprintf(stderr, "Fork failed");
		return 1;
	}
	
	// fork successful
	if (pid == 0) // child process
	{
		pid = getpid();
		snprintf(write_message, BUFFER_SIZE, "%d", pid);				// conversion of integer PID to string message.

		printf("Child created. PID = %d\n", pid);
		
		close(pipe_file_desc[READ_END]);								// closes the reading end. Child only needs to write.
		
		write(pipe_file_desc[WRITE_END], write_message, BUFFER_SIZE);	// writes the message to the writing end.
		
		close(pipe_file_desc[WRITE_END]);								// closes also the writing end.
		
		printf("Child process going to sleep for 5 seconds.\n");
		sleep(5);														// put the child to sleep for 5 seconds
		exit(0);														// exiting child
	}
	else // (pid > 0) parent process
	{
		pid_t childs_pid;
		int status;
		pid_t report;
		time_t t;
		int seconds = 10;													// seconds to monitor the child.
		
		printf("Parent process. PID = %d\n", getpid());
		
		close(pipe_file_desc[WRITE_END]);									// closes the writing end. Parent only needs to read.
		
		read(pipe_file_desc[READ_END], read_message, BUFFER_SIZE);			// reads the message from the reading end.
		printf("Message is: %d\n", childs_pid = atoi(read_message));		// prints the message.
		
		close(pipe_file_desc[READ_END]);									// closes also the reading end.
		
		do
		{
			report = waitpid(childs_pid, &status, WNOHANG);
		
			if (report == -1)
			{
				perror("Report: Wait() error\n");								// status information failed to be obtained
			}
			else if (report == 0)												// status: running
			{
				time(&t);														// the time information was obtained
				printf("Report: Child is still present at %s", ctime(&t));
			}
			else
			{
				if (WIFEXITED(status))
				{
					printf("Report: Child exited with status of %d.\n",			// status: child exited
					WEXITSTATUS(status));										// with this status
			  	}
			 	else
			 	{
			  		printf("Report: Child did not exit successfully.\n");		// status: child didn't exit successfully
			  	}
			}
			sleep(1);															// sleep a second
			seconds = seconds - 1;
		}
		while (seconds > 0);
	}
	
	return 0;
}
