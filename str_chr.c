#include "shell.h"

/**
 * string_chr - Locates a character in a string.
 *
 * @s: String.
 * @c: Character to be located.
 * Return: Pointer to first occurrence of NULL if no character found.
 */
char *string_chr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
return (0);
}
