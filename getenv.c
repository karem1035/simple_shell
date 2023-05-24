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
char *_getenv(char *name, char *env[])
{
	size_t name_len;
	if (!name)
	{
		return NULL;
	}

	name_len = strlen(name);

	for (; *env; ++env)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
	}

	return NULL;
}
/**
 * _getenv2 - get the environment variable value.
 * @name: name of the variable.
 * Return: the value.
 */
char *_getenv2(char *name, char *env[])
{
	unsigned int i = 0;
	char *var = NULL;
	char *val = NULL;
	unsigned int var_length;
	unsigned int val_length;

	while (env[i])
	{
		var_length = var_len(env[i]);
		var = malloc(var_length + 1);
		if (!var)
			return (NULL);

		_strncpy(var, env[i], var_length);
		var[var_length] = '\0';

		if (_strcmp(var, name) == 0)
		{
			val_length = val_len(env[i] + var_length + 1);
			val = malloc(val_length + 1);
			if (!val)
			{
				free(var);
				return (NULL);
			}
			_strncpy(val, env[i] + var_length + 1, val_length);
			val[val_length] = '\0';
			free(var);
			return (val);
		}
		free(var);
		i++;
	}
	return (NULL);
}

/**
 * _setenv - sets the value of an environment variable
 * @name: the name of the environment variable to set
 * @value: the value to set the environment variable to
 * @overwrite: whether to overwrite an existing value for the variable
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value, int overwrite, char **env)
{
	size_t name_l, value_l, total_l;
	char *new_env, *p;
	int result;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		perror("setenv");
		return (-1);
	}
	if (!overwrite && _getenv2(name, env) != NULL)
		return (0);
	name_l = _strlen(name);
	if (value)
		value_l = _strlen(value);
	else
		value_l = 0;
	total_l = name_l + value_l + 2;
	new_env = malloc(total_l);
	if (new_env == NULL)
		return (-1);
	p = new_env;
	_memcpy(p, name, name_l);
	p += name_l;
	*p++ = '=';
	if (value)
	{
		_memcpy(p, value, value_l);
		p += value_l;
	}
	*p = '\0';
	result = putenv(new_env);
	if (result != 0)
	{
		perror("setenv");
		free(new_env);
		return (-1);
	}
	return (0);
}
