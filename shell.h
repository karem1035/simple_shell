#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;
void execute(char *argvv[]);


void _puts(char *str);
int _putchar(char c);
#endif
