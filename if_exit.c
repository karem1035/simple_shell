#include "shell.h"
/**
 * if_exit - checks if the command is exit.
 * @argvv: the command.
 * Return: 1 if exit, 0 if not.
 */
int if_exit(char *argvv)
{
	if (_strcmp(argvv, "exit") == 0)
	{
		return (1);
	}
	return (0);
}
