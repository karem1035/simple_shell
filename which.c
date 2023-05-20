#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src
 * @src: copied str
 * @dest: place to paste
 *
 * Return: pasted string from src
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strlen - returns the length of a string.
 * @s: string to be measured
 * Return: len of string;
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - concatenates two strings.
 * @dest: appended to str
 * @src: appended str
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, const char *src)
{
	int ldst, lsrc, i, j;

	ldst = _strlen(dest);
	lsrc = _strlen(src);
	i = ldst;
	j = 0;

	while (i < ldst + lsrc)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _which - search and append command to the suitable directory in
 * path
 * @argvv: list of arguments
 * Return: 1 at success and 0 if failure
 */
char *_which(char *argvv[])
{
	char *dir = NULL;
	char *path = _getenv2("PATH");
	char *path_copy;
	char *token;
	char delim[] = ":";

	if (!path)
		return (0);

	path_copy = _strdup(path);
	token = strtok(path, delim);
	while (token)
	{
		dir = malloc(_strlen(token) + _strlen(argvv[0]) + 2);
		if (!dir)
		{
			free(path_copy);
			return (0);
		}

		dir = _strcpy(dir, token);
		_strcat(dir, "/");
		_strcat(dir, argvv[0]);
		if (!access(dir, X_OK))
		{
			free(path_copy);
			return(dir);
		}
		free(dir);
		token = strtok(NULL, delim);
	}
	free(path_copy);
	return (NULL);
}
