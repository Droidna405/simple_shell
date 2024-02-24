#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * main - entry point of the program.
 *
 * Description: this function emulates a simple CLI
 * by continously prompting the user for input, printing a "$ " prompt
 *
 * Return: always returns o t indicate successfull completion.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (getline(&line, &len, stdin) == -1)
		{
			perror("getline");
			free(line);
			exit(EXIT_FAILURE);
		}
		printf("%s", line);
	}
	free(line);
	return (0);
}
