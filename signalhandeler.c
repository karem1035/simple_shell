#include "shell.h"
/**
 * signalhandler - Keeps interactive mood after CTRL C.
 * @n: the signal.
 * Return: Void.
*/
void signalhandler(int n __attribute__((unused)))
{
	_puts("\n");
	_puts("$$ ");
}
