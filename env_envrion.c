#include <stdio.h>
#include <stdlib.h>

/* declare the extern var environ */
extern char **environ;

int main(int argc, char *env[])
{
	(void)argc;
	/* print address of the env parameter */
	printf("Address of env parameter: %p\n", (void*)env);

	/* print the address of the environ global var */
	printf("Addrss of environ global var: %p\n", (void*)environ);
	return (0);
}
