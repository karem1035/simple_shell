#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 all time
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *argvv[MAX_TOKENS], *line = NULL;
	size_t n = 0;
	struct stat st;
	int pnum = 1;

	while (1)
	{
		if (isatty(0))
			_puts("$$ ");
		if (getline(&line, &n, stdin) == -1)
		{
			if (isatty(0))
				_puts("\n");
			free(line);
			exit(0);
		}
		if (!tokenize(line, argvv))
		{
			free(line);
			line = NULL;
			continue;
		}
		if (if_exit(argvv[0]))
			exit(0);
		if (stat(argvv[0], &st) == 0)
			execute(argvv);
		else if (!_which(argvv))
		{
			print_error(argv[0], pnum, argvv[0]);
			continue;
		}
		free(line);
		line = NULL;
		n = 0;
		pnum++;
	}
	return (0);
}
/**
 * freeline - frees the line.
 * @line: the line.
 * Return: void.
 */
void freeline(char **line)
{
	free(*line);
	*line = NULL;
}
