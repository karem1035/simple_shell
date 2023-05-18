#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
void execute(char *argv, char *argvv[]);


#define MAX_TOKENS 20
#endif
