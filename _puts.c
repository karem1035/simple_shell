#include "shell.h"
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
/**
 * int_to_char - converts int to char;
 * @a: the int.
 * Return: the char.
 */
char int_to_char(int a)
{
	char c = 48 + a;

	return (c);
}
