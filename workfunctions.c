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
 * getlenght - get lenght of string typed for user.
 * @str: str typed for user
 * Return: lenght of string
 */

/*
int getlenght(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
*/

/**
 * command_err_message - return err message for command that doesn't exist
 * @is_not_command: command that doesn't exist
 * Return: nothing
 */

/*
void command_err_message(char *is_not_command)
{
	char *c = ": Command not found";
	int len1;
	int len2;
	int i = 0;

	len1 = getlenght(c);

		write(1, is_not_command, len);
	for (i = 0; is_not_command[i] != NULL; i++)
		_putchar(is_not_command[i]);
	_putchar('\n');
}
*/

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
 * siginthandler - keep shell when user press control + c
 * @sig_int: handler
 * Return: nothing
 */
void siginthandler(int sig_int)
{
	if (sig_int == 2)
	{
		fflush(stdout);
		exit(0);
	}
}
