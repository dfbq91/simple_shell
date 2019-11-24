#include "holberton.h"

void *_getenv(const char *name)
{
	char **env = __environ;
	char **ptr;
	char *token;

	for (**ptr = **env; *ptr != name; ptr++)
		;
	return(*ptr);
}

/**
 * searchpath - take a string(command) for to search its path
 * @str: string to concatenate with a path.
 * Return: nothing.
 */

char *searchpath(char **str)
{
	char *envi = getenv("PATH");
	int i = 0;
	char *token;
	char *newpath = malloc(50);
	char **pathtocheck;
	int position = 0;
	char *slash = malloc(50);
	struct stat st;

	pathtocheck = malloc(300);
	if (pathtocheck == NULL)
	{
		free(pathtocheck);
		exit(EXIT_FAILURE);
	}

	/*Agrega "/" al input*/
	_strcpy(slash, "/");
	_strcat(slash, str[0]);

	token = strtok(envi, "=");
	printf("Complete path: %s\n", token);
	token = strtok(token, ":");
	printf("tokenpreliminar %s\n\n", token);

	while (token != NULL)
	{
		printf("Path: %s\n", token);

		pathtocheck[position] = token;

		_strcpy(newpath, pathtocheck[position]);
		_strcat(newpath, slash);

		printf("The newpath: %s\n", newpath);

		/*if (stat(pathtocheck[position], &st) == 0)
		  return (pathtocheck[position]);*/
		position++;
		token = strtok(NULL, ":");
	}

	pathtocheck[position] = NULL;

	return(*pathtocheck);
}
