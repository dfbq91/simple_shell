#include "holberton.h"

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

	pathtocheck = malloc(300);
	if (pathtocheck == NULL)
	{
		free(newenvi);
		free(pathtocheck);
		exit(EXIT_FAILURE);
	}
	slash = malloc(strlen(str[0]) + 2);
	if (slash == NULL)
	{
		free(newenvi);
		free(pathtocheck);
		free(slash);
		exit(EXIT_FAILURE);
	}

	_strcpy(slash, "/"); /*Copy "/" to slash variable*/
	_strcat(slash, str[0]); /*Concatenate the user input to the "/"*/

	strcpy(newenvi, envi); /*Copy path env value to newenvi*/
	token = strtok(newenvi, ":");

	while (token != NULL)
	{
		pathtocheck[position] = token;

		/*Get lenght of path env value and user input to allocate in mem*/
		i = _strlen(pathtocheck[position]);
		j = _strlen(slash);
		newpath = malloc(sizeof(char *) * (i + j + 1));
		if (newpath == NULL)
		{
			free(newenvi);
			free(pathtocheck);
			free(slash);
			free(newpath);
			exit(0);
		}

		/*Create complete path (path env value and user input*/
		_strcpy(newpath, token);
		_strcat(newpath, slash);

		newpath[i + j] = '\0';

		/*If create path in newpath is an executable, return to execute*/
		if (stat(newpath, &st) == 0)
		{
			/*free(newenvi);*/
                        /*free(pathtocheck);*/
                        /*free(slash);*/
                        /*free(token);*/
			return (newpath);
		}

		position++;
		token = strtok(NULL, ":");
		free(newpath);
	}

	pathtocheck[position] = NULL;
	/*
	free(newenvi);
        free(pathtocheck);
        free(slash);
        free(newpath);
        free(token);
	*/
	return (str[0]);
}
