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
char *int_to_str(unsigned int a, char *str)
{
	int digit = 0, n = a, i;

	while (n != 0)
	{
		n /= 10;
		digit++;
	}

	str = malloc(sizeof(char) * (digit + 1));
	if (str == NULL)
		return (NULL);
	for (i = digit - 1; i >= 0; i--)
	{
		str[i] = (a % 10) + '0';
		a /= 10;
	}
	str[digit] = '\0';
	return (str);
}
