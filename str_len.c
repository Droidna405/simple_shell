#include "shell.h"

int string_len(const char *pointer)
{
int c = 0;
while (*(pointer + c) != '\0')
{
c++;
}
return (c);
}
