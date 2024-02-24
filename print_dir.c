#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * print_path_dirs - print each dir contained in the PATH  envriron var 
 *
 * Return: void.
 */
void print_path_dirs(void)
{
	char *path = getenv("PATH");
	char *token;
	
	if (path == NULL)
	{
		fprintf(stderr, "PATH  environment var not found.\n");
		return;
	}
	/* tokenize the PATH string usning ':' as the delimiter */
	token = strtok(path, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}

int main(void)
{
	print_path_dirs();
	return (0);
}
