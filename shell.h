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
void execute(char *argvv[]);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _which(char *argvv[]);
unsigned int var_len(char *environ_i);
unsigned int val_len(char *environ_i);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name);

#define MAX_TOKENS 20
#endif
