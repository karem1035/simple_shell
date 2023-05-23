#include "shell.h"
/**
 * prompt - prompt for input.
 * Return: Void.
*/
void prompt(void)
{
	if ((isatty(0) == 1) && (isatty(1) == 1))
		_puts("$$ ");
}
