#include "shell.h"

/**
 * _strchr - search for a character in a str
 * @s: string to search in
 * @c: char to be located
 * Return: 0 (success)
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);

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
 * _memcpy - copies memory area.
 * @dest: place to copy to
 * @src: place to copy from
 * @n: number of bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

for (i = 0; i < n; i++)
{
	dest[i] = src[i];
}
	return (dest);
}
/**
 * _puts - prints a string to STDOUT 1.
 * @str: the string.
 * Return: void.
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
/**
 * _puts2 - prints a string to STDERR 2.
 * @str: the string.
 * Return: void.
 */
void _puts2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
