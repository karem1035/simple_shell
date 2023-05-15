#include "shell.h"
/**
 * execute - execute programm.
 * @argvv: the executable command.
 * Return: void.
 */
void execute(char *argvv[])
{
	int id, stat;
	char *filename = argvv[0];
	
	id = fork();
	if (id == -1)
		exit(1);

	if (id == 0)
	{
		execve(argvv[0], argvv, environ);
		write(STDOUT_FILENO, filename, strlen(filename));
		perror(" ");
		exit(1);
	}
	else
	{
		wait(&stat);
	}

}
