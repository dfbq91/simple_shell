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
char **_prompt(char **argv);
int executor(char **token, int inputcounter, char *argv);
char **token(char *str);
int _strcmp(char *s1, char *s2);
int dollar(void);
void command_err_message(char *is_not_command, int inputcounter, char *argv);
int getlenght(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *searchpath(char **str);
void sighandler(int sig_int);
void print_env(void);
char *_getenv(const char *name);
int _strlen(char *s);
void permission_err_message(char *no_access, int inputcounter, char *argv);

#endif
