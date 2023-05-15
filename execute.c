#include "shell.h"
/**
 * execute - execute programm.
 * @argvv: the executable command.
 * Return: void.
 */
void execute(char *argvv[])
{
	int id, stat;

	id = fork();
	if (id == -1)
		exit(1);

	if (id == 0)
	{
		if (execve(argvv[0], argvv, environ) == -1)
		{
			_puts(argvv[0]);
			_puts(": ");
			perror("");
			exit(1);
		}
	}
	else
	{
		wait(&stat);
	}

}
