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
	char *str = NULL;
	char **command;

	signal(SIGINT, &siginthandler);

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
			free(str);
			exit(0);
		}

		if (bytes_rd == -1)
		{
			free(str);
			perror("Getline Error");
		}

		command = token(str);
		executor(command);
	}
	free(str);
	return (command);
}

/**
* dollar - prints dollar and space to the prompt
* Return: On sucess 2.
* On error, -1 is returned, and errno is set appropriately.
*/
int dollar(void)
{
	char c[2] = "$ ";

	return (write(1, &c, 2));
}
