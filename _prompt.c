#include "holberton.h"

/**
 * _prompt - Print prompt ($ ) and call fun for to split a string
 *
 * Return: never returns
 */

char *_prompt(void)
{
	int bytes_rd;
	size_t n_bytes = 1024;
	char *str;
	char *command;

	str = malloc(n_bytes + 1);
	while (1)
	{
		printf("$ ");
		bytes_rd = getline(&str, &n_bytes, stdin);
		if (bytes_rd == -1)
			perror("Getline Error");

		command = token(str);
		executor(command);
	}
}
