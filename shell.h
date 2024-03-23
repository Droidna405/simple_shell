#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;
void handle_built_in_commands(char **av, char *buffer);
void execute_command(char **av, char **envp);


void print_env(void);
int string_cmp(const char *s1, const char *s2);
char **parse_input_str(char *buffer);
char *path_srch(char *cmd);
char *string_ncat(char *dest, const char *src, int n);
int string_len(const char *pointer);
char *string_cat(char *dest, const char *src);
char *string_chr(char *s, char c);

#endif /* SHEll_H */
