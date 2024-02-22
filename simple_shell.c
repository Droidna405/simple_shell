#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define DELIMITER " \t\n"

/**
 * main - entry point
 * Runs the shell in interactive or non-interactive
 * mode based on command-line arguments.
 * Return: nothing
 */
int main(void)
{
read_execute_loop();
return (EXIT_SUCCESS);
}
