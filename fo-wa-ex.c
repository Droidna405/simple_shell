#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: Always o.
 */
int main(void)
{
	pid_t pid;
	int i;

	/* loop to create 5 child processes */
	for (i = 0; i < 5; i++)
	{
		pid = fork();
		/* check for fork failure */
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			/* Execute ls -l /tmp command */
			execlp("ls", "ls", "/tmp", NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	return (0);
}
