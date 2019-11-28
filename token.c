#include "holberton.h"

/**
 * token - Splits a string
 * @str: command enter for the user
 * Return: array of each word of the string splited.
 */

char **token(char *str)
{
	char *token, **tokencomplete;
	int i = 0, j = 1, position = 0;
	char delimit[] = " \t\r\n\v\f";

	for (i = 0; str[i] != '\n'; i++)
		;
	str[i] = '\0';/*Coloca caracter nulo en la entrada del usuario*/

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			j++;
	}

	tokencomplete = malloc(j * sizeof(char*));
	if (tokencomplete == NULL)
	{
		free(tokencomplete);
		exit(0);
	}

	token = strtok(str, delimit);

	while (token != NULL)
	{
		tokencomplete[position] = malloc(sizeof(char) * _strlen(token) + 1);
		_strcpy(tokencomplete[position], token);
		token = strtok(NULL, delimit);
		position++;
	}
	tokencomplete[position] = NULL;

	return (tokencomplete);
}
