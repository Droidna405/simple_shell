#include "simple_shell.h"
/* THIS FILE CONTAIN HELPER FUNCTIONS TO BUILD OUR SIMPLE SHELL (MAX 5) */

/* 1. OUR PRINTF VERSION */
/**
 * my_print - print a string to a specified file descritor
 * @input_string: the string to be printed
 * @file_descriptor: where the file is to be printed to
 * Return: nothing
 */
void my_print(char *input_string, int file_descriptor)
{
	int index;

	for (index = 0; input_string[index] != '\0'; index++)
		write(file_descriptor, &input_string[index], 1);
}

/*2. SHOW PROMPT TO THE USER */
/**
 * show_prompt - displays prompt on terminal to indicate shell is ready
 * Return: nothing
 */
void show_prompt(void)
{
	my_print("Ready$ ", STDOUT_FILENO);
}

/*3. GET USER INPUT */
/**
 * get_input - get user input from stdin
 * @user_command: pointer to the buffer where the user input will be stored
 * @size: the size of the buffer to prevent overflow
 * Return: nothing
 */
void get_input(char *user_command, size_t size)
{
	/* Remove the newline character from the input */
	user_command[strcspn(user_command, "\n")] = '\0';
	/*read a line of input from stdin into 'user_command'*/
	if (fgets(user_command, size, stdin) == NULL)
	{
		/* check if EOF(Ctrl+D) is encountered */
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
}

/*4. EXECUTE THE USER COMMAND */
/**
 * execute_user_command - executes a user command by forking a child process
 * and calling execve to replace the child process with specified
 * command.
 * @user_command: The name of the command to execute.
 */
void execute_user_command(char *user_comand)
{
	pid_t child_process_id = fork();
	char full_command_path[256];
	char *arguments[] = {user_command, NULL};

	if (child_process_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		snprintf(full_command_path, sizeof(full_command_path),
		"/usr/bin/%s", user_command);
		execve(full_command_path, arguments,  NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
