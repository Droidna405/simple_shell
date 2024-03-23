#include "shell.h"

/**
 * string_compare - Compares two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 * Return: Difference of the two strings.
 */
int string_cmp(const char *s1, const char *s2)
{
int result;
int i = 0;

while (s1[i] == s2[i])
{
if (s1[i] == '\0' && s2[i] == '\0')
{
break;
}
i++;
}
result = s1[i] - s2[i];
return (result);
}
