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
	char *envir = "env";
	char *newstr;

	if (_strcmp(token[0], goexit) == 0) /*Go out when exit is typed*/
	{
		free(token[0]);
		free(token);
		exit(0);
	}
	if (_strcmp(token[0], envir) == 0) /*Print environment when env is typed*/
		print_env();

	newstr = searchpath(token); /*Get path env and concatenate user input*/

	pid = fork();
	if (pid == 0) /*Executed by the son and finish with execve*/
	{
		if (execve(newstr, token, NULL) == -1)
		{
			/*free(newstr);*/
			/*free(token);*/
			close(STDIN_FILENO);
		}
	}
	else if (pid > 0) /*Executed by parent and wait son finishes*/
		wait(NULL);
	else
		perror("Fork Error");

	/*free(token);*/
	return (0);
}

/**
 * print_env - print environment with command env
 * Return: nothing.
 */

void print_env(void)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			_putchar(environ[i][j]);
		}

		_putchar('\n');
	}
}
