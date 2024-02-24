#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

/**
 * main - verision of "which"
 *
 * Return: Always 0(success)
 */
int main(int argc, char *argv[])
{
	char *path_env = getenv("PATH");
	char *path;
	char *dir;
	char full_path[MAX_PATH_LEN];
	int i;

	if (argc < 2)
	{

		printf("Usage: %s filename ..\n", argv[0]);
		exit(EXIT_FAILURE);
	}
if (path_env == NULL)
{
	fprintf(stderr, "Error: PATH NOT FOUND.\n");
	exit(EXIT_FAILURE);
}
path = strdup(path_env);
if (path == NULL)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
dir = strtok(path, ":");
while (dir != NULL)
{
	for (i = 1; i < argc; i++)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, argv[i]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			printf("%s\n", full_path);
			break;
		}
	}
	dir = strtok(NULL, ":");
}
free(path);
return (0);
}
