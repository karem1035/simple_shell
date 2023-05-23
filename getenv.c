#include "shell.h"

/**
 * var_len - get the var length.
 * @environ_i: the var name.
 * Return: the length.
 */
unsigned int var_len(char *environ_i)
{
	unsigned int i;

	for (i = 0; environ_i[i] != '='; i++)
		;
	return (i);
}
/**
 * val_len - gets the val length.
 * @environ_i: the val name.
 * Return: the length.
 */
unsigned int val_len(char *environ_i)
{
	unsigned int i;

	for (i = 0; environ_i[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _getenv - get the environment variable value.
 * @name: name of the variable.
 * Return: the value.
 */
char *_getenv(char *name)
{
	unsigned int i = 0, j, k;
	char *var = NULL;
	char *val = NULL;

	while (environ[i])
	{
		var = malloc(var_len(environ[i]) + 1);
		if (!var)
			return (NULL);

		for (j = 0; environ[i][j] != '='; j++)
			var[j] = environ[i][j];
		var[j] = '\0';

		if (_strcmp(var, name) == 0)
		{
			val = malloc(val_len(environ[i]) + 1);
			if (!val)
			{
				free(var);
				return (NULL);
			}
			j++;
			for (k = 0; environ[i][j] != '\0'; k++)
			{
				val[k] = environ[i][j];
				j++;
			}
			val[k] = '\0';
			free(var);
			return (val);
		}
		free(var);
		i++;
	}
	return (NULL);
}
/**
 * _getenv2 - get the environment variable value.
 * @name: name of the variable.
 * Return: the value.
 */
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

		_strncpy(var, environ[i], var_length);
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
			_strncpy(val, environ[i] + var_length + 1, val_length);
			val[val_length] = '\0';
			free(var);
			return (val);
		}
		free(var);
		i++;
	}
	return (NULL);
}
