#include "shell.h"
/**
 * execute - execute programm.
 * @argvv: the commands.
 * @env: environ array
 * Return: void.
 */
void execute(char *argvv[], char **env)
{
	int stat;
	pid_t pid;

	pid = fork();
	if (pid == -1)
		exit(1);

	if (pid == 0)
	{
		execve(argvv[0], argvv, env);
		perror(argvv[0]);
		exit(98);
	}
	else
		wait(&stat);
}
