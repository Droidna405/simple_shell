#include "simple_shell.h"

/**
 * my_print - Print a string to a specified file descriptor.
 * @input_string: The string to be printed.
 * @file_descriptor: Where the file is to be printed to.
 * Return: Nothing.
 */
void my_print(char *input_string, int file_descriptor)
{
int index;

for (index = 0; input_string[index] != '\0'; index++)
write(file_descriptor, &input_string[index], 1);
}

/**
 * show_prompt - Display prompt to the user.
 * Return: Nothing.
 */
void show_prompt(void)
{
my_print("$ ", STDOUT_FILENO);
}

/**
 * get_input - Get user input from stdin.
 * @user_command: Pointer to the buffer where the user input will be stored.
 * @size: The size of the buffer to prevent overflow.
 * Return: Nothing.
 */
void get_input(char *user_command, size_t size)
{
/* Read a line of input from stdin into 'user_command' */
if (fgets(user_command, size, stdin) == NULL)
{
/* Check if EOF (Ctrl+D) is encountered */
if (feof(stdin))
{
my_print("\n", STDOUT_FILENO);
exit(EXIT_SUCCESS);
}
else
{
perror("fgets");
exit(EXIT_FAILURE);
}
}
/* Remove the newline character from the input */
user_command[strcspn(user_command, "\n")] = '\0';
}

/**
 * execute_user_command - Execute a user command by forking a child process
 * and calling execvp to replace the child process with specified command.
 * @user_command: The name of the command to execute.
 * Return: Nothing.
 */
void execute_user_command(char *user_command)
{
pid_t child_process_id = fork();
char *arguments[2];

if (child_process_id == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_process_id == 0)
{
arguments[0] = user_command;
arguments[1] = NULL;
execvp(user_command, arguments);
perror("execvp");
exit(EXIT_FAILURE);
}
else
wait(NULL);
}
