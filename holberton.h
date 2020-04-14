#ifndef _HOLBERTON_H
#define _HOLBERTON_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

/*FUNCTIONS*/
extern char **environ;
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);

void _prompt(void);
char **token(char *string, const char *delim);
int execute();

#endif