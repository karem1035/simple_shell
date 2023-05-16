#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 all time
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *argvv[20], *token;
	char *line = NULL;
	size_t n = 0;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$$ ", 3);
		if (getline(&line, &n, stdin) == -1)
		{
			perror("getline error.");
			break;
		}
		token = strtok(line, " \n");
		i = 0;
		while (token)
		{
			argvv[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		argvv[i] = NULL;
		execute(argv[0], argvv);
	}
	free(line);
	return (0);
}
