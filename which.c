#include "shell.h"

/**
 * _strdup - returns a pointer to a copy of the string
 * @str: the string to copy
 * Return: a pointer to a copy of the string
 */
char *_strdup(char *str)
{
	int i = 0;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	i++;
	p = malloc(sizeof(char) * i);
	i = 0;
	if (p == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/**
 * _strlen - returns the length of a string.
 * @s: string to be measured
 * Return: len of string;
 */

int _strlen(char *s)
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

char *_strcat(char *dest, char *src)
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
int _which(char *argvv[])
{
	char *dir = NULL;
	char *path = _getenv("PATH");
	char *token;
	char delim[] = ":";
	struct stat sb;

	token = strtok(path, delim);
	while (token)
	{
		dir = malloc(_strlen(token) + _strlen(argvv[0]) + 2);
		if (!dir)
			return (0);

		dir = _strdup(token);
		_strcat(dir, "/");
		_strcat(dir, argvv[0]);
		if (stat(dir, &sb) == 0)
		{
			argvv[0] = dir;
			execute(argvv);
			free(dir);
			free(path);
			return (1);
		}
		free(dir);
		free(path);
		token = strtok(NULL, delim);
	}
	return (0);
}
