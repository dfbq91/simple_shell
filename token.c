#include "holberton.h"

/**
 * token - Splits a string
 * @str: command enter for the user
 * Return: array of each word of the string splited.
 */

char **token(char *str)
{
	char *token;
	char **tokencomplete;
	int tokenposition = 0;
	int i;

	for (i = 0; str[i] != '\n'; i++)
		;

	str[i] = '\0';

	tokencomplete = malloc(i * sizeof(char *));

	if (tokencomplete == NULL)
	{
		free(tokencomplete);
		exit(0);
	}

	token = strtok(str, " ");

	while (token != NULL)
	{
		tokencomplete[tokenposition] = token;
		tokenposition++;
		token = strtok(NULL, " ");
	}
	tokencomplete[tokenposition] = NULL;

	return (tokencomplete);
}
