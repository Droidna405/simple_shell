#include "shell.h"

/**
 * execute_command - Execute a command given its arguments.
 *
 * @av: Array of strings representing the command and its arguments.
 * @envp: Array of strings representing the environment variables.
 *
 * This function forks a child process to execute the command specified in
 * @av using execve(). It waits for the child process to complete before
 * returning.
 */

void execute_command(char **av, char **envp)
{
int status;
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (child_pid == 0)
{
if (string_chr(av[0], '/') == NULL)
av[0] = path_srch(av[0]);
if (execve(av[0], av, envp) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
wait(&status);
}


/**
 * handle_built_in_commands - Handle built-in commands.
 *
 * @av: Array of strings representing the command and its arguments.
 * @buffer: String containing the command entered by the user.
 *
 * This function checks if the command specified in @av is a built-in command,
 * such as 'env' or 'exit'. If it is, the appropriate action is taken. If not,
 * the function returns without performing any action.
 */
void handle_built_in_commands(char **av, char *buffer)
{
if (!av[0])
{
free(av);
return;
}

if (string_cmp(av[0], "env") == 0)
{
print_env();
free(av);
return;
}

if (string_cmp(av[0], "exit") == 0)
{
free(av);
free(buffer);
exit(0);
}
}

/**
 * main - Entry point of the program.
 *
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings representing the arguments.
 * @envp: Array of strings representing the environment variables.
 *
 * This function is the entry point of the program. It handles the main
 * loop of the shell, reading commands from the user, parsing them,
 * and executing them accordingly.
 *
 * Return: Always returns 0.
 */
int main(int ac __attribute__((unused)), char *av[], char *envp[])
{
char *buffer = NULL;
size_t bufsize = 0;

signal(SIGINT, SIG_IGN);

while (1)
{
if (isatty(STDIN_FILENO))
printf("~$ ");

if (getline(&buffer, &bufsize, stdin) == -1)
break;

if (buffer == NULL)
exit(0);

av = parse_input_str(buffer);
handle_built_in_commands(av, buffer);
execute_command(av, envp);

free(av);
}

free(buffer);
return (0);
}
