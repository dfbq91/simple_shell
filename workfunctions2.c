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

/**
 * permission_err_message - print err message if a file can be accessed
 * @no_access: file or pathfile that doesn't be accesed
 * @inputcounter: number of inputs (enter pressed)
 * @argv: execution of shell
 * Return: nothing
 */

void permission_err_message(char *no_access, int inputcounter, char *argv)
{
	char *c = ": Permission denied";
	int i = 0;

	for (i = 0; argv[i] != '\0'; i++)
		_putchar(argv[i]);
	fflush(stdout);
	_putchar(':');
	fflush(stdout);
	_putchar(' ');
	fflush(stdout);

	if (inputcounter <= 9)
		_putchar(inputcounter + '0');
	else
	{
		_putchar((inputcounter / 10) + '0');
		_putchar((inputcounter % 10) + '0');
	}

	fflush(stdout);
	_putchar(':');
	fflush(stdout);
	_putchar(' ');
	fflush(stdout);

	for (i = 0; no_access[i] != '\0'; i++)
		_putchar(no_access[i]);

	fflush(stdout);

	for (i = 0; c[i] != '\0'; i++)
		_putchar(c[i]);

	fflush(stdout);

	_putchar('\n');
	fflush(stdout);
}
