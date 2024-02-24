#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_shell.h"

/**
 * _getenv - Retrieve the value of an environ. variable.
 * @name: the name of the environment var to retrieve.
 *
 * Return: A pointer to the value of the envrionment variable if found
 * 	otherwise return NULL.
 */
char *_getenv(const char *name)
{
	char *equal_sign;

	if (name == NULL || environ == NULL)
		return (NULL);
	/* Iterate throught the envrion array */
	for (int i = 0; environ[i] != NULL; i++)
	{
		equal_sign = strchr(environ[i], '=');
		if (equal_sign == NULL)
			continue;
		if (strncmp(environ[i], name, equal_sign - environ[i] == 0)
			return (equal_sign + 1);
	}
	return (NULL);
}
