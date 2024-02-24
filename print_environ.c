#include <stdio.h>
#include <stdlib.h>

/* declare the extern  var environ */
extern char **environ;

int main(void)
{
	char **env_ptr = environ;
	
	while (*env_ptr != NULL)
	{
		/* print each environ var */
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
	return (0);
}
