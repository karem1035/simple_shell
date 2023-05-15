#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * Return: 0 all time
 */
int main(void)
{
	char *argvv[20];
	char *line = NULL;
	char *token;
	char delim[] = " ";
	size_t n = 0;
	int i = 0;

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

		line = strtok(line, " \n");
		token = strtok(line, " ");
		argvv[0] = token;
		if (!argvv[0])
			continue;
		for (i = 1; argvv[i] && i < 19; i++)
		{
			token = strtok(NULL, delim);
			argvv[i] = token;
		}
		argvv[i] = NULL;

		execute(argvv);
	}
	free(line);
	return (0);
}
