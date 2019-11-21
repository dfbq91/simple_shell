#include "holberton.h"

/**
 * token - Splits a string
 * @str: command enter for the user
 * Return: array of each word of the string splited.
 */

char **token(char *str)
{
	char *token, *dup;
	char **tokencomplete;
	int tokenposition = 0;
	int i;

	for (i = 0; str[i] != '\n'; i++)
                ;

        str[i] = '\0';

	printf("%d\n", i);
	tokencomplete = malloc(i * sizeof(char*));

	if (tokencomplete == NULL)
        {
                free(tokencomplete);
                exit(EXIT_FAILURE);
        }
	dup = strdup(str);
	printf("dup: %s\n", dup);
	token = strtok(dup, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		tokencomplete[tokenposition] = token;
		tokenposition++;
		token = strtok(NULL, " ");
	}
	tokencomplete[tokenposition] = NULL;
	printf("%s %d: %s\n",__FILE__, __LINE__, *tokencomplete);

	if (token == NULL)
		free(token);

	return (tokencomplete);
}
