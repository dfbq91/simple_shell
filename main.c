#include "holberton.h"

/**
 * main - Call all functions ($ ) and splits a string
 *
 * Return: ....
 */

int main(void)
{
	char *command;

	command = _prompt();
	executor(command);
	return (0);
}
