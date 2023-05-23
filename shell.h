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
/**
 * struct built_in_command - a list of built in commands.
 * @cmd: the command to be checcked.
 * @function_to_execute_on_cmd: function to check.
 */
typedef struct built_in_command
{
	char *cmd;
	int (*function_to_execute_on_cmd)(char *argvv[]);
} bin_cmd;


void signalhandler(int n __attribute__((unused)));
void prompt(void);

void execute(char *argvv[]);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
int _which(char *argvv[]);
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
char *int_to_str(unsigned int a, char *str);
void print_error(char *fname, unsigned int pnum, char *cname);
int _ENV(char *argvv[]);
int _EXIT(char *argvv[]);
int is_integer(char *input);
int _atoi(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *_memcpy(char *dest, char *src, unsigned int n);
int _setenv(char *name, char *value, int overwrite);
int _CD(char *argvv[]);
int is_builtin(char *argvv[]);

#define MAX_TOKENS 20
#endif
