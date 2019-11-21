#include "holberton.h"

/**
 * searchpath - take a string(command) for to search its path
 * @str: string to concatenate with a path.
 * Return: nothing.
 */

void searchpath(char **str)
{
	char *firstpath = malloc(100);
	char *secondpath = malloc(100);
	char *thirdpath = malloc(100);
	struct stat st;

	_strcpy(firstpath, "/bin/");
	_strcpy(secondpath, "/usr/bin/");
	_strcpy(thirdpath, "/usr/bin/");

	_strcat(firstpath, str[0]);
	_strcat(secondpath, str[0]);
	_strcat(thirdpath, str[0]);

	if (stat(firstpath, &st) == 0)
	{
		str[0] = firstpath;
		puts("pasó por first\n");
		return;
	}

	if (stat(secondpath, &st) == 0)
	{
		str[0] = secondpath;
		puts("pasó por second\n");
		return;
	}

	if (stat(thirdpath, &st) == 0)
	{
		str[0] = thirdpath;
		puts("pasó por third\n");
		return;

	}
	puts("no pasó por ninguno\n");
}
