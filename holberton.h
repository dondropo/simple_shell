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
int _prompt(char *buff);

#endif