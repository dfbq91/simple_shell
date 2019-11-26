#include "holberton.h"

/**
 * _strcpy - copy a string into a buffer pointed
 * @dest: char type array pointer
 * @src: char type integer variable
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int j = 0;

	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

/**
 * sighandler - keep shell when user press control + c
 * @sig_int: handler
 * Return: nothing
 */
void sighandler(int sig_int)
{
	(void)sig_int;

	signal(SIGINT, sighandler);
	fflush(stdout);
}

/**
 * _getenv - get environment variable
 * @name: name of the env variable to get
 * Return: value of the environment variable
 */

char *_getenv(const char *name)
{
	char **ptr;
	int i = 0;
	int j = 0;

	for (ptr = environ; ptr[i] != NULL; i++)
	{
		for (; ptr[i][j] != '/'; j++)
		{
			if (ptr[i][j] != name[j])
				break;
		}

		if (name[j] == '\0')
		{
			return (ptr[i] + j);
		}
	}
	return (NULL);
}
