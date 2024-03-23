#include "shell.h"

/**
 * print_environ - Prints all the environment variables.
 *
 * Return: Nothing.
 */
void print_env(void)
{
int i;

i = 0;
while (environ[i])
printf("%s\n", environ[i++]);
}
