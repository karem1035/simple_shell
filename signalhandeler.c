#include "shell.h"
/**
 * signalhandler - Keeps interactive mood after CTRL C.
 * @n: the signal.
 * Return: Void.
*/
void signalhandler(int n __attribute__((unused)))
{
    write(2, "\n", 1);
    write(2, "$$ ", 3);
}