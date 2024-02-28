#include "simple_shell.h"

/**
 * main - entry point
 * Runs the shell in interactive or non-interactive
 * mode based on command-line arguments.
 * Return: 0 on success
 */
int main(void)
{
char user_command[127]; /* Define a buffer to store user input */

while (1)
{
show_prompt(); /* Display the prompt */
get_input(user_command, sizeof(user_command)); /* Get user input */
if (feof(stdin))/*Check for EOF*/
{
my_print("\n", STDOUT_FILENO);
break;
}

/* Execute the user command */
execute_user_command(user_command);
}

return (0);
}
