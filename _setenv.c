#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_shell.h"

/**
 * _setent - changes or add an environment var.
 * @name: The name of the environment varible.
 * @value: The value to assigne to the envrironment var.
 * @overwrite: if non-zero, the function will overwriter an existing var.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i;
	char *new_env;
	int env_count;
	char **new_environ;

	if (name == NULL || value == NULL)
	{
		fprintf(stderr, " Invalid arguments\n");
		return (-1);
	}
	/* Iterate thro' the environment vars to find the target var */
	for (i = 0; environ[i] != NULL; i++)
	{
	if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
	{
		/* If overwrite not allowed, return without modifying env */
		if (!overwrite)
			return (0);
		/* if overwrite allowed, modify the existing var */
		else
		{
			new_env = malloc(strlen(name) + strlen(value) + 2);
			if (new_env == NULL)
			{
				perror("malloc");
				return (-1);
			}
		sprintf(new_env, "%s=%s", name, value);
		free(environ[i]);
		environ[i] = new_env;
		return (0);
		}
	}
	}
	/* if the var does'nt exits, create a new one */
	sprintf(new_env, "%s=%s", name, value);
	/* count the existing environment variables */
	env_count = 0;
	while (environ[env_count] != NULL)
		env_count++;
	/* Allocate memory for the new environment array */
	new_environ = malloc((env_count + 2) * sizeof(char *)):
	if (new_environ == NULL)
	{
		perror("malloc");
		free(new_env);
		return (-1);
	}
	/* copy the existing environment variables to the new array */
	for (i = 0; i < env_count; i++)
		new_environ[i] = environ[i];
	new_environ[env_count] = new_env;
	new_environ[env_count + 1] = NULL;
	/* Replace the old environ with the new one */
	free(environ);
	environ = new_environ;
	return (0);
}
