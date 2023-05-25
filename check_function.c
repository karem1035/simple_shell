#include "shell.h"
/**
 * check_function - to check the function.
 * @argvv: the command to be checked.
 * @line: line to be freed.
 * @env: the env to be printed.
 * Return: 1 if succeded 0 if not.
*/
int check_function(char **argvv, char *line, char **env)
{
	if (_strcmp(argvv[0], "exit") == 0)
		MY_EXIT(argvv, env, line);
	else if (_strcmp(argvv[0], "env") == 0)
	{
		_ENV(env);
		return (1);
	}
	return (0);
}
