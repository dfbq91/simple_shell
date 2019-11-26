#include "holberton.h"
/**
 * print_env - function that prints the enviroment variable
*/
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
