#include "holberton.h"

/**
 * executor - execute command from stdin
 * @token: array of each word of the string
 * Return: not return, on error return -1.
 */

int executor(char *token)
{
	char *argv[2];
	int pid;
	int i;

	for (i = 0; token[i] != '\n'; i++)
		;

	token[i] = '\0';

	/*printf("Este token es impreso desde executor: %s\n", token);*/
	argv[0] = token;
	argv[1] = NULL;

	pid = fork();
	if (pid == 0) /* Lo ejecuta solo el hijo y termina con execve*/
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Execve Error");
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("Fork Error");
	return (0);
}
