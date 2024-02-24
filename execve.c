#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example with current environment 
 *
 * Return: always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	extern char **environ; /* External ref to the current environment */

	printf("Before execve\n");
	/* pass the current environmenta as last argument */
	if (execve(argv[0], argv, environ) == -1)
		perror("Error:");
	printf("After execve\n");
	return (0);
}
