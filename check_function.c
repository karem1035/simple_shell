#include "shell.h"

int check_function(char *cmd)
{
        
	if (_strcmp(cmd, "exit") == 0)
		MY_EXIT(argvv, env, line);
        else if (_strcmp(cmd, "env") == 0)
	{
		_ENV(env);
		return (1);
	}
        return (0);
}