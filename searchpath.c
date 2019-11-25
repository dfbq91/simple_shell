#include "holberton.h"

void *_getenv(const char *name)
{
	char **env = __environ;
	char **ptr;
	char *token;

	for (**ptr = **env; *ptr != name; ptr++)
		;
	return (*ptr);
}

/**
 * searchpath - take a string(command) for to search its path
 * @str: string to concatenate with a path.
 * Return: nothing.
 */

char *searchpath(char **str)
{
	char *envi, *token, *newpath, *newenvi, **pathtocheck, *slash;
	int i, j, position = 0;
	struct stat st;

	envi = getenv("PATH");

	newenvi = malloc(strlen(envi) + 1);
	if (newenvi == NULL)
	{
		free(newenvi);
		exit(EXIT_FAILURE);
	}

	token = malloc(strlen(envi) + 1);
	if (token == NULL)
	{
		free(token);
		exit(EXIT_FAILURE);
	}

	pathtocheck = malloc(300);
	if (pathtocheck == NULL)
	{
		free(pathtocheck);
		exit(EXIT_FAILURE);
	}
	slash = malloc(strlen(str[0]) + 1);
	if (slash == NULL)
	{
		free(slash);
		exit(EXIT_FAILURE);
	}

	/*Agrega "/" al input*/
	_strcpy(slash, "/");
	_strcat(slash, str[0]);

	strcpy(newenvi, envi);
	token = strtok(newenvi, ":");

	while (token != NULL)
	{
		pathtocheck[position] = token;

		for (i = 0; pathtocheck[position][i] != '\0'; i++)
			;
		for (j = 0; slash[j]; j++)
			;

		newpath = malloc(sizeof(char *) * (i + j + 1));
		if (newpath == NULL)
		{
			free(newpath)
			exit(0);
		}

		_strcpy(newpath, token);
		_strcat(newpath, slash);

		newpath[i + j] = '\0';

		if (stat(newpath, &st) == 0)
			return (newpath);

		position++;

		token = strtok(NULL, ":");
		free(newpath);
	}

	pathtocheck[position] = NULL;

	return (str[0]);
}
