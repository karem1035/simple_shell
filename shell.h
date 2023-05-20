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

void execute(char *argvv[], char *full_path);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_which(char *argvv[]);
unsigned int var_len(char *environ_i);
unsigned int val_len(char *environ_i);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name);
char *_getenv2(char *name);
void freeline(char **line);
int if_exit(char *argvv);
char **tokenize(char *line, char *argvv[]);
void _puts(char *str);
void _puts2(char *str);
char int_to_char(int a);
void print_error(char *fname, int pnum, char *cname);
void freeargvv(char **argvv);

#define MAX_TOKENS 20
#endif
