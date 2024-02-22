#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define DELIMITER " \t\n"

/* Function prototypes */
void read_execute_loop(void);
int handle_builtin_command(const char *command);
void tokenize_input(char *input_buffer, char *args[]);
void execute_command(char *args[]);

#endif /* SIMPLE_SHELL_H */
