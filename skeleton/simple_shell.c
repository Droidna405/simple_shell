#include "simple_shell.h"
/* removed the exta header files already included in "simple_shell.h" */

/**
 * main - entry point
 * Runs the shell in interactive or non-interactive
 * mode based on command-line arguments.
 * Return: 0 on success
 */
int main(void)
{
char user_command[127];

while (1)
{
show_prompt();
get_input(user_command, sizeof(user_command));
execute_user_command(user_command);
return (0);
}
}
