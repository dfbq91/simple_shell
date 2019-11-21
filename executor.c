#include "holberton.h"

/**
 * executor - execute command from stdin
 * @token: array of each word of the string
 * Return: not return, on error return -1.
 */

int executor(char **token)
{
	int pid;
	char *goexit = "exit";

	if (_strcmp(token[0], goexit) == 0)
		exit(0);

	searchpath(token);

	pid = fork();
	if (pid == 0) /* Lo ejecuta solo el hijo y termina con execve*/
	{
		if (execve(token[0], token, NULL) == -1)
		{
			close(STDIN_FILENO);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("Fork Error");
	return (0);
}
