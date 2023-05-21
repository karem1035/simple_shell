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
		if (execve(argvv[0], argvv, environ) == -1)
		{
			perror("");
			exit(1);
		}
	}
	else
	{
		if (waitpid(pid, &stat, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
}
