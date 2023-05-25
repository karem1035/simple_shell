#include "shell.h"
/**
 * check_function - to check the function.
 * @cmd: the command to be checked.
 * @line: line to be freed.
 * @env: the env to be printed.
 * Return: 1 if succeded 0 if not.
*/
int check_function(char *cmd, char *line, char **env)
{
	if (_strcmp(cmd, "exit") == 0)
		my_exit2(line);
	else if (_strcmp(cmd, "env") == 0)
	{
		_ENV(env);
		return (1);
		}
	return (0);
}
