#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/* macros */
#define BUFFER_SIZE 1024
#define DELIMITER " \t\n"

/* Function prototypes */
void my_print(char *input_string, int file_descriptor); /* printing */
void show_prompt(void); /* to display prompt */
void get_input(char *user_command, size_t size); /* get user input */
void execute_user_command(const char *user_command);
void read_execute_loop(void);
int handle_builtin_command(char *command);
void tokenize_input(char *input_buffer, char *args[]);
void execute_command(char *args[]);

#endif /* SIMPLE_SHELL_H */
