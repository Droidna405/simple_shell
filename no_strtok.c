			ptr++;
		/* start of a word */
		if (*ptr)
		{
			word_start = ptr;
			/* find end of the word */
		while (*ptr && (*ptr != ' ' || *ptr != '\n'))
			ptr++;
		/* length of the word */
		word_length = ptr - word_start;
		/* allocate mem for the word */
		words[word_index] = malloc(word_length + 1);
		if (words[word_index] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* Copy the word into the array */
		strncpy(words[word_index], word_start, word_length);
		words[word_index][word_length] = '\0';

		/* move to the next word */
		word_index++;
		}
	}
	/* null terminate the array */
	words[word_count] = NULL;
	return (words);
}

int main(void)
{
	const char *input_string = "Hello Engineer! You are smashing this task";
	char **words = split_string(input_string);
	int i;

	/* print each word */
	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
	return (0);
}
