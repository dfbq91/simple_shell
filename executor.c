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
	char *newstr;

	if (_strcmp(token[0], goexit) == 0)
	{
		free(token[0]);
		free(token);
		exit(0);
	}

	newstr = searchpath(token);

	pid = fork();
	if (pid == 0) /* Lo ejecuta solo el hijo y termina con execve*/
	{
		if (execve(newstr, token, NULL) == -1)
		{
				//free(newstr);
				//free(token);
				close(STDIN_FILENO);
		}
		
	}
	else if (pid > 0)
		wait(NULL);
	else
		perror("Fork Error");

	//free(token);
	return (0);
}
