#include "shell.h"
/**
 * print_error - prints the error message.
 * @fname: the file name argv[0].
 * @process_number: the process number.
 * @cname: the command name.
 * Return: void.
 */
void print_error(char *fname, unsigned int process_number, char *cname)
{
	char *number = NULL;

	number = int_to_str(process_number, number);

	_puts2(fname);
	_puts2(": ");
	_puts2(number);
	free(number);
	_puts2(": ");
	_puts2(cname);
	_puts2(": ");
	_puts2("not found\n");
	if (!isatty(0))
		exit(127);
}
/**
 * int_to_str - converts int to char;
 * @a: the int.
 * @str: the str.
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
