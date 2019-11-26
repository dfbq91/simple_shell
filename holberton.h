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
#include <signal.h>

extern char **environ;
int _putchar(char c);
char **_prompt(void);
int executor(char **token);
char **token(char *str);
int _strcmp(char *s1, char *s2);
int dollar();
void command_err_message(char *is_not_command);
int getlenght(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *searchpath(char **str);
void siginthandler(int sig_int);
void print_env(void);
#endif
