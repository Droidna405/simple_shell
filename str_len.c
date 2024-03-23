#include "shell.h"
/**
 * string_len - gets the length of the string
 * @pointer: pointer to beginning of string
 * Return: c
 */
int string_len(const char *pointer)
{
int c = 0;
while (*(pointer + c) != '\0')
{
c++;
}
return (c);
}
