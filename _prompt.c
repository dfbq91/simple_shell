#include "holberton.h"

/**
 * _prompt - Print prompt ($ ) and call fun for to split a string
 * @argv: name of program
 * Return: never returns
 */

char **_prompt(char **argv)
{
	int bytes_rd = 0, inputcounter = 1;
	size_t n_bytes = 1024;
	char *str = NULL, *newstr, **command;

	signal(SIGINT, sighandler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			dollar(); /*Call fun dollar who prints a dollar(prompt)*/
		bytes_rd = getline(&str, &n_bytes, stdin);

		if (bytes_rd == EOF) /*When control + d is pressed*/
		{
			if (isatty(STDIN_FILENO) == 0)
			{
				free(str);
				exit(0);
			}
			else
			{
				free(str);
				_putchar('\n');
				exit(0);
			}
		}

		if (bytes_rd > 1)
		{
			fflush(stdin);
			command = token(str);
			newstr = executor(command, inputcounter, argv[0]);
			inputcounter++;
		}
	}

	free(str);
	free(newstr);
	return (argv);
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
