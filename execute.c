#include "shell.h"
/**
 * execute - execute programm.
 * @filename: the file name.
 * @argvv: the commands.
 * Return: void.
 */
void execute(char *argvv[])
{
	int stat;
	pid_t pid;

	pid = fork();
	if (pid == -1)
		exit(1);

	if (pid == 0)
	{
		if (execve(argvv[0], argvv, environ) == -1)
		{
			perror("");
			exit(1);
		}
	}
	else
	{
		wait(&stat);
	}

}
