#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 all time
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *argvv[MAX_TOKENS], *token;
	char *line = NULL;
	size_t n = 0;
	int i;

	while (1)
	{
		if (isatty(0))
			write(1, "$$ ", 3);
		if (getline(&line, &n, stdin) == -1)
		{
			if (!isatty(0))
				write(1, "$$ ", 3);
			else
				write(1, "\n", 1);
			break;
		}
		token = strtok(line, " \n");
		i = 0;
		if (!token)
		{
			free(line);
			line = NULL;
			continue;
		}
		while (token && i < MAX_TOKENS)
		{
			argvv[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		argvv[i] = NULL;
		execute(argv[0], argvv);
		n = 0;
		free(line);
		line = NULL;
	}
	return (0);
}
