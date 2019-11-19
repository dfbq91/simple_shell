#include "holberton.h"

/**
 * token - Splits a string
 * @str: command enter for the user
 * Return: array of each word of the string splited.
 */

char *token(char *str)
{
	char *token;

	token = strtok(str, " ");

	return (token);
}
