#include <string.h>
#include "simple_shell.h"
/**
 * handle_builtin_command - Handles built-in commands
 * @command: The command to handle
 *
 * This function handles built-in commands such as "exit".
 *
 * Return: 0 if the command is "exit", -1 otherwise.
 */
int handle_builtin_command(const char *command)
{
if (strcmp(command, "exit") == 0)
{
/* Exits the shell */
return (0);
}
else
{
/* Add implementation for other built-in commands (optional) */
return (-1);/* Command not found */
}
}

/**
 * read_execute_loop - function for prompt loop
 * Read input from user and execute commands
 */
void read_execute_loop(void)
{
char input_buffer[BUFFER_SIZE];
/* char *args[BUFFER_SIZE / 2 + 1]; */
int should_run = 1;

while (should_run)
{
printf("$ ");
fflush(stdout);

if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL)
{
perror("Error reading input");
continue;
}
}
}
/**
 * tokenize_input - Tokenize input string into array of arguments.
 * @input_buffer: Input string to tokenize.
 * @args: Array to store tokenized arguments.
 */
void tokenize_input(char *input_buffer, char *args[])
{
char *token;
int i = 0;

token = strtok(input_buffer, DELIMITER);
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, DELIMITER);
}
args[i] = NULL;
}

/**
 * execute_command - Execute a command with arguments.
 * @args: Array of command arguments.
 */
void execute_command(char *args[])
{
pid_t pid;

pid = fork();
if (pid < 0)
{
perror("Fork failed");
return;
}
else if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("Error executing command");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
wait(NULL);
}
}
