#include "shell.h"
/**
 * print_error - prints the error message.
 * @fname: the file name argv[0].
 * @pnum: the process number.
 * @cname: the command name.
 * Return: void.
 */
void print_error(char *fname, unsigned int pnum, char *cname)
{
	char *number = NULL;

	number = int_to_str(pnum, number);

	_puts2(fname);
	_puts2(": ");
	_puts2(number);
	_puts2(": ");
	_puts2(cname);
	_puts2(": ");
	_puts2("not found\n");
	free(number);
}
