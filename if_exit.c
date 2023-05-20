#include "shell.h"
/**
 * if_exit - checks if the command is exit.
 * @argvv: the command.
 * Return: 1 if exit, 0 if not.
 */
int if_exit(char *argvv)
{
	if (_strcmp(argvv, "exit") == 0)
		return (1);
	return (0);
}
char *_getenv2(char *name)
{
    unsigned int i = 0;
    char *var = NULL;
    char *val = NULL;
	unsigned int var_length;
	unsigned int val_length;

    while (environ[i])
    {
        var_length = var_len(environ[i]);
        var = malloc(var_length + 1);
        if (!var)
            return (NULL);

        strncpy(var, environ[i], var_length);
        var[var_length] = '\0';

        if (_strcmp(var, name) == 0)
        {
            val_length = val_len(environ[i] + var_length + 1);
            val = malloc(val_length + 1);
            if (!val)
            {
                free(var);
                return (NULL);
            }
            strncpy(val, environ[i] + var_length + 1, val_length);
            val[val_length] = '\0';
            free(var);
            return (val);
        }
        free(var);
        i++;
    }
    return (NULL);
}
