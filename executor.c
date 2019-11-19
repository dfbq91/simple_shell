#include "holberton.h"

/**
 * executor - execute command from stdin
 * @token: array of each word of the string
 * Return: not return, on error return -1.
 */

int executor(char **token)
{
	/*char *argv[2];*/
	int pid;

	/*argv[0] = token;
	  argv[1] = NULL;*/
	
	pid = fork();
	if (pid == 0) /* Lo ejecuta solo el hijo y termina con execve*/
	{
		if (execve(token[0], token, NULL) == -1)
			perror("Command not found");
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("Fork Error");
	return (0);
}
