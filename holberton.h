#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int _putchar(char c);
char **_prompt(void);
int executor(char **token);
char **token(char *str);
int _strcmp(char *s1, char *s2);
int dollar();
void command_err_message(char *is_not_command);
int getlenght(char *str);

#endif
