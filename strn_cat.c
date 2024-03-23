#include "shell.h"

/**
 * string_ncat - Concatenates two strings.
 *
 * @dest: Resulting string.
 * @src: Source string.
 * @n: String length.
 * Return: Pointer to dest.
 */
char *string_ncat(char *dest, const char *src, int n)
{
int i, m;

m = string_len(dest);
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[m + i] = src[i];
}
dest[m + i] = '\0';
return (dest);
}
