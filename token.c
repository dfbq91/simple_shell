#include "holberton.h"

/**
 * prompt - Splits a string
 * @str: command enter for the user
 * Return: array of each word of the string splited.
 */

char *token(char *str)
{
	char *token;

	token = strtok(str, " ");

        while (token != NULL)
	{
		printf("%s", token);
		token = strtok(NULL, "");
	}

	return (token);
}
