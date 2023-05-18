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
 * _strcmp - compares two strings.
 * @s1: str to be compared
 * @s2: str to be compared
 * Return: difference in ascii value
 */
int _strcmp(char *s1, char *s2)
{
	int i, res = 0;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (res);
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
