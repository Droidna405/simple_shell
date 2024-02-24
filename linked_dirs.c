#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_shell.h"
/**
 * build_path_list - Build a linked list of the PATH directions.
 *
 * Return: A pointer to the head of the linked list.
 */
Path_Node *build_path_list(void)
{
	/* retrive the value of the PATH environment variable */
	char *path = getenv("PATH");
	char *token;
	Path_Node *new_node;
	Path_Node *head = NULL;
	Path_Node *prev = NULL;

	if (path == NULL)
	{
		fprintf(stderr, "PATH  environment variable not found.\n");
		return (NULL);
	}

	/* create a linked list node for each dir path */
	token = strtok(path, ":");
	while (token != NULL)
	{
		new_node = malloc(sizeof(Path_Node));
		if (new_node == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* copy the dir into the node */
		new_node->directory = strdup(token);
		if (new_node->directory == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		/* Set the pointer of the prev node to point to the new nod*/
		if (prev != NULL)
			prev->next = new_node;
		/* update the head pointer if it's the first node */
		if (head == NULL)
			head = new_node;
		/* move to the next token */
		prev = new_node;
		token = strtok(NULL, ":");
	}
	/* set the next pointer  of the last node to NULL */
	if (prev != NULL)
		prev->next = NULL;
	return (head);
}
	/* TESTING */
int main(void)
{
	/* buio the linked list of  PATH  dirs */
	Path_Node *path_list = build_path_list();

	Path_Node *current = path_list;
    while (current != NULL) {
        printf("%s\n", current->directory);
        current = current->next;
    }

    /* Free the memory allocated for the linked list nodes*/
    current = path_list;
    while (current != NULL) {
        Path_Node *temp = current;
        current = current->next;
        free(temp->directory);
        free(temp);
    }

    return (0);
}


