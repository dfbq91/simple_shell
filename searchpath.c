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
	int j = 0;
	char *token = NULL;
	char *copytoken = NULL;
	char *newpath = NULL;
	char **pathtocheck = NULL;
	int position = 0;
	char *slash = NULL;
	struct stat st;

	pathtocheck = malloc(300);
	if (pathtocheck == NULL)
	{
		free(pathtocheck);
		exit(EXIT_FAILURE);
	}
	slash = malloc(50);
	if (slash == NULL)
	{
		free(slash);
		exit(EXIT_FAILURE);
	}

	/*Agrega "/" al input*/
	_strcpy(slash, "/");
	_strcat(slash, str[0]);
	printf("Envi: %s\n", envi);

	token = strtok(envi, "=");
	copytoken = token;
	printf("Token: %s\n", token);
	printf("Copytoken: %s\n", copytoken);
	token = strtok(token, ":");
	printf("Copy: %s\n", copytoken);
	printf("tokenpreliminar %s\n\n", token);

	while (token != NULL)
	{
		printf("Path: %s\n", token);

		pathtocheck[position] = token;

		for (i = 0; pathtocheck[position][i] != '\0'; i++)
			;
		for (j = 0; slash[j]; j++)
			;

		newpath = malloc(sizeof(char *) * (i + j));

		_strcpy(newpath, token);
		_strcat(newpath, slash);

		newpath[i + j] = '\0';

		printf("newpath es igual: %s\n", newpath);

		if (stat(newpath, &st) == 0)
			return (newpath);

		position++;
		token = strtok(NULL, ":");
		free(newpath);
	}

	pathtocheck[position] = NULL;

	return(str[0]);
}
