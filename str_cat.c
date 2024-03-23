#include "shell.h"

/**
 * string_cat - Concatenates two strings.
 *
 * @dest: Resulting string.
 * @src: Source string.
 * Return: Pointer to dest.
 */
char *string_cat(char *dest, const char *src)
{
int i, n;

n = string_len(dest);
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[n + i] = src[i];
}
dest[n + i] = '\0';
return (dest);
}
