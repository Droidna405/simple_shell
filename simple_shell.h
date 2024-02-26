#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER " \t\n"

/* Function prototypes */
void read_execute_loop(void);
int handle_builtin_command(const char *command);
void tokenize_input(char *input_buffer, char *args[]);
void execute_command(char *args[]);
void my_print(char *input_string, int file_descriptor);
void show_prompt(void);
void get_input(char *user_command, size_t size);
void execute_user_command(char *user_command);

#endif /* SIMPLE_SHELL_H */
