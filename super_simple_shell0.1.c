#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * @argc: arg count
 * @argv: args vector
 * Return: 0 all time
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *argvv[2];
	char *line = NULL;
	size_t n = 0;
	int id, stat;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (getline(&line, &n, stdin) == -1)
		{
			printf("#cisfun$ ");
			break;
		}

		argvv[0] = strtok(line, " \n");
		if (!argvv[0])
			exit(0);
		argvv[1] = NULL;

		id = fork();
		if (id == -1)
			exit(1);

		if (id == 0)
		{
			if (execve(argvv[0], argvv, environ) == -1)
			{
				_puts(argv[0]);
				_puts(": ");
				perror("");
			}
		}
		else
			wait(&stat);
	}

	free(line);
	return (0);
}
