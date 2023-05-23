#include "shell.h"

/**
 * is_integer - checks if a string represents an integer
 * @input: the string to check
 *
 * Return: true if the string represents an integer, false otherwise
 */
int is_integer(char *input)
{
	long int num = 0;
	int negative;

	if (*input == '\0')
		return (0);

	negative = (*input == '-');
	if (negative || *input == '+')
		input++;

	while (*input != '\0')
	{
		if (*input < '0' || *input > '9')
			return (0);

		num = num * 10 + (*input - '0');
		input++;
	}

	if (negative)
		num *= -1;

	return (1);
}

/**
 * _atoi - convert a string to an integer.
 * @s: str to be converted
 *
 * Return: integer after conversion
 */

int _atoi(char *s)
{
	unsigned int len = 0, res = 0, neg = 0, i, neg2;

	while (*(s + len) != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] == '-')
			neg++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			neg2 = neg;
			res = res * 10 + (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
			{
				break;
			}
		}
	}
	if (neg2 % 2 == 1)
		res *= -1;

	return (res);
}
