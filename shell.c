#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * Return: 0 all time
 */
int main(void)
{
	char *argvv[2];
	char *line = NULL;
	size_t n = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");
		if (getline(&line, &n, stdin) == -1)
		{
			if (line[0] == '\n')
				continue;
			else
			{
				if (!isatty(STDIN_FILENO))
					_puts("#cisfun$ ");
				else
					_putchar('\n');
				break;
			}
		}

		argvv[0] = strtok(line, " \n");
		if (!argvv[0])
			continue;
		argvv[1] = NULL;

		execute(argvv);
	}
	free(line);
	return (0);
}
