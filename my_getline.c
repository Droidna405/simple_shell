#include <stdio.h>
#include <stdlib.h>

/**
 * my_getline - Read a line from a file stream.
 * @lineptr: pointer to the buffer stroing the line.
 * @n: pointer to the size of the buffer.
 * @stream: file to the read from(usually stdin)
 *
 * Description: This function reads characters from the specified file stream
 * until an newline char or EOF  is encountered. The line is stored in 
 * the buffer pointed to by lineptr, which is dynamically resized as needed.
 * The size of the buffre is updated through the pointer n
 *
 * Return: number of chars read, includeing newline char, or -1 on error
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t capacity = *n;
	size_t i = 0;
	int c;
	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1); /* invalid arguments */

	if (*lineptr == NULL)
	{
		*lineptr = malloc(capacity);
		if (*lineptr == NULL)
			return (-1); /* mem alloc failed */
	}
	/* read chars from stream until newline or EOF */
	while ((c = fgetc(stream)) != EOF)
	{
		/* Resize buffer if needed */
		if (i >= capacity - 1)
		{
			capacity *= 2;
			temp = realloc(*lineptr, capacity);
			if (temp == NULL)
				return (-1);
			*lineptr = temp;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
			break; /* reachec end of line */
	}
	(*lineptr)[i] = '\0';
	/* update buffer size if needed */
	*n = capacity;
	if (i == 0 && c == EOF)
		return (-1);
	else
		return (i);
}

/**
 * main - entry point of the program
 *
 * Description: this function demostrates the usage of my_getline by
 * continously reading lines fom stdin and printing them. It also
 * frees the allocatedm mem for the line buffer.
 *
 * Return: Always returns 0 to indicate successful completion.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	while ((bytes_read = my_getline(&line, &len,stdin)) != -1)
		printf("Read %zd bytes: %s", bytes_read, line);
	free(line);
	return (0);
}
