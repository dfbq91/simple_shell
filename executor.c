#include "holberton.h"
/**
 * executor - execute command from stdin
 * @token: array of each word of the string
 * @inputcounter: number of user inputs (enter pressed)
 * @argv: user input
 * Return: not return, on error return -1.
 */
char *executor(char **token, int inputcounter, char *argv)
{
	int pid, status, exit_status;
	char *goexit = "exit", *envir = "env", *newstr;
	struct stat st;

	newstr = searchpath(token); /*Get path env and concatenate user input*/
	if (_strcmp(token[0], goexit) == 0) /*Go out when exit is typed*/
	{	free(token[0]);
		free(token);
		exit(0);
	}
	if (_strcmp(token[0], envir) == 0) /*Print environment when env is typed*/
	{	print_env();
		return (newstr);
	}
	if (stat(newstr, &st) == -1)
	{	command_err_message(token[0], inputcounter, argv);
		return (newstr);
	}
	if (access(newstr, X_OK) == -1)
	{	permission_err_message(token[0], inputcounter, argv);
		return (newstr);
	}
	pid = fork();
	if (pid == 0) /*Executed by the son and finish with execve*/
	{
		if (execve(newstr, token, NULL) == -1)
		{
			perror("Error de execve");
			exit(127);
		}
	}
	else if (pid > 0) /*Executed by parent and wait son finishes*/
	{
		wait(&status);
		if (WIFEXITED(status))
		{	exit_status = WEXITSTATUS(status);
			(void)exit_status;
		}
	}
	return (newstr);
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
