#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
extern char **environ;

/* main function */

int exec_command(char **av);
char *_which(char *cmd);
char *_getenv(char *gb_variable);


/* string functios */

char *_strdup(const char *string);
int _strlen(char *string);
char *_strcat(char *dest, char *source);
char *_strcpy(char *d, char *s);
int _strcmp(char *string1, char *string2);

#endif
