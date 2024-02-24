#include <stdio.h>

int main(int ac, char **av)
{
	char **arg = av + 1;

	(void)ac;

	for (; *arg != NULL; arg++)
		printf("%s\n", *arg);
	return (0);
}
