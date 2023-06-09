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
		if (execve(argvv[0], argvv, env) == -1)
		{
			perror(argvv[0]);
			freeargvv(argvv);
			exit(127);
		}
	}
	else
		wait(&stat);
}
/*{}*/
