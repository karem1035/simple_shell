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
	struct stat st;

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
			freeline(line);
			continue;
		}
		while (token && i < MAX_TOKENS)
		{
			argvv[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		argvv[i] = NULL;
		if (stat(argvv[0], &st) == 0)
			execute(argvv);
		else if (!_which(argvv))
			perror(argv[0]);
		freeline(line);
		n = 0;
	}
	return (0);
}
/**
 * freeline - frees the line.
 * @line: the line.
 * Return: void.
 */
void freeline(char *line)
{
	line = NULL;
	free(line);
}
