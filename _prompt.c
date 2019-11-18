#include "holberton.h"

/**
 * prompt - Print prompt ($ ) and call fun for to split a string
 *
 * Return: ....
 */

char *_prompt(void)
{
	size_t bytes_rd;
	size_t n_bytes = 100;
	char *str;
	char *command;
	pid_t childp;

	str = malloc(n_bytes + 1);
	while (1)
	{
		printf("$ ");
		bytes_rd = getline(&str, &n_bytes, stdin);
		if (bytes_rd == -1)
			perror("Error");

		command = token(str);
		executor(command);
	}
}
