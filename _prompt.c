#include "holberton.h"

/**
 * _prompt - Print prompt ($ ) and call fun for to split a string
 *
 * Return: never returns
 */

char **_prompt(void)
{
	int bytes_rd = 0;
	size_t n_bytes = 1024;
	char *str;
	char **command;

	str = malloc(n_bytes + 1);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			dollar(); /*Llama a la función dollar que imprime el dolar*/

		bytes_rd = getline(&str, &n_bytes, stdin);

		if (bytes_rd == 1) /*Si no se ingresa nada en el shell*/
			continue;

		if (bytes_rd == EOF)
		{
			_putchar('\n');
			exit(0);
		}

		if (bytes_rd == -1)
		{
			perror("Getline Error");
		}
		command = token(str);
		executor(command);
	}

	return (command);
}
