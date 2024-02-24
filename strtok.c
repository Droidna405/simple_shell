#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - splits a stirng into an array of words.
 * @str: the string to split
 *
 * Return: an array of strings containing each word from the input string.
 */
char **split_string(const char *str)
{
	/* Initialize vars */
	char **words = NULL;
	int word_count = 0;
	const char delimiters[] = " \n\t";
	char *token;
	char *str_copy = strdup(str);

	if (str_copy == NULL)
	{
		perror("stdup");
		exit(EXIT_FAILURE);
	}

	/* tokenize string */
	token = strtok(str_copy, delimiters);
	while (token != NULL)
	{
		/* Reallocate mem for words array */
		words = realloc(words, (word_count + 1) * sizeof(char *));
		if (words == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		/* Allocate mem for the current word */
		words[word_count] = malloc(strlen(token) + 1);
		if (words[word_count] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* Copy the token into the word array */
		strcpy(words[word_count], token);
		/* increment word into the word */
		word_count++;
		token = strtok(NULL, delimiters);
	}
	/* allocate one extra element for null terminator */
	words = realloc(words, (word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	/* Set the last element to NULL to indicate the end of the array */
	words[word_count] = NULL;
	return (words);
}

int main(void)
{
	const char *input_string = "Hello Engineer! You are smashing this task";
	char **words = split_string(input_string);
	int i;

	/*print each word */
	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
	return (0);
}
