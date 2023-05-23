#include "shell.h"

/**
 * _strncpy - copies up to n characters from the string.
 * @dest: where the content is to be copied.
 * @src: This is the string to be copied.
 * @n: the number of characters to be copied from source.
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int lsrc = _strlen(src), i = 0;

	while (i < lsrc && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{	dest[i] = '\0';
		i++;
	}
	return (dest);
}

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
 * _strcmp - compares two strings.
 * @s1: str to be compared
 * @s2: str to be compared
 * Return: difference in ascii value
 */
int _strcmp(char *s1, char *s2)
{
	int i, res = 0;

	if (_strlen(s1) != _strlen(s2))
		return (1);
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
