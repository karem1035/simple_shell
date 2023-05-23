#include "shell.h"
/**
 * execute - execute programm.
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
		execve(argvv[0], argvv, environ);
		perror(argvv[0]);
		free(argvv);
		exit(98);
	}
	else
		wait(&stat);
}
