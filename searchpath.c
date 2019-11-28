#include "holberton.h"
/**
 * searchpath - take a string(command) for to search its path
 * @str: string to concatenate with a path.
 * Return: nothing.
 */
char *searchpath(char **str)
{	char *envi, *token, *newpath, *newenvi, *pathtocheck = NULL, *slash;
	struct stat st;

	envi = _getenv("PATH");
	newenvi = malloc(_strlen(envi) + 1);
	if (newenvi == NULL)
	{	free(newenvi);
		exit(EXIT_FAILURE);
	}
	slash = malloc(_strlen(str[0]) + 2);
	if (slash == NULL)
	{	free(slash);
		exit(EXIT_FAILURE);
	}
	_strcpy(slash, "/"); /*Copy "/" to slash variable*/
	_strcat(slash, str[0]); /*Concatenate the user input to the "/"*/
	_strcpy(newenvi, envi); /*Copy path env value to newenvi*/
	token = strtok(newenvi, ":");
	while (token != NULL)
	{	pathtocheck = malloc(_strlen(token) + 1 + 300);
		if (pathtocheck == NULL)
		{	free(pathtocheck);
			exit(EXIT_FAILURE);
		}
		pathtocheck = token;
		newpath = malloc(sizeof(char *) *
				 (_strlen(pathtocheck) + _strlen(slash) + 1));
		if (newpath == NULL)
		{	free(newpath);
			exit(EXIT_FAILURE);
		}
		_strcpy(newpath, token);
		_strcat(newpath, slash);
		newpath[_strlen(pathtocheck) + _strlen(slash)] = '\0';
		if (stat(newpath, &st) == 0)
			return (newpath);
		token = strtok(NULL, ":");
		free(newpath);
	}
	free(newenvi);
	return (str[0]);
}
