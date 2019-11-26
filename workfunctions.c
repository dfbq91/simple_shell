#include "holberton.h"

/**
 * _strcmp - compare two strings
 *@s1: first string
 *@s2: second string
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0, j = 0; s1[i] != '\0' && s1[j] != '\0'; i++, j++)
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
	}
	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - give the lenght of a string
 *@s: int pointer type variable
 * Return: Always 0.
 */

int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
	{
		c++;
	}
	return (c);

}

/**
 * command_err_message - return err message for command that doesn't exist
 * @is_not_command: command that doesn't exist
 * Return: nothing
 */

void command_err_message(char *is_not_command, int inputcounter, char *argv)
{
	char *c = ": not found";
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

	for (i = 0; is_not_command[i] != '\0'; i++)
		_putchar(is_not_command[i]);

	fflush(stdout);

	for (i = 0; c[i] != '\0'; i++)
		_putchar(c[i]);

	fflush(stdout);

	_putchar('\n');
	fflush(stdout);
}

/**
 * _strcat - Concatenate two strings.
 *@dest: destiny string that will contain concatenated string
 *@src: source string to concatenate to dest.
 * Return: dest as two strings concatenated.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; ++i)
		;

	for (j = 0; src[j] != '\0'; ++j, ++i)
	{
		dest[i] = src[j];
	}
	dest[i + 1] = '\0';
	return (dest);
}
