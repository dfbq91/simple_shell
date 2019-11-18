#include "holberton.h"

/**
 * executor - execute command from stdin
 * @token: array of each word of the string
 * Return: not return, on error return -1.
 */

int executor(char *token)
{
	char *argv[2];
	int cmp;

	/*printf("Este token es impreso desde executor: %s\n", token);*/
	argv[0] = token;
	argv[1] = NULL;
	printf("Imprime: .%s.\n", argv[0]);
	printf("./bin/ls.\n");

	printf("%d\n", cmp);
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error");
	}
	return (0);
}
