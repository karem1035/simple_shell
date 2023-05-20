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
    ssize_t chars_n;
	int pnum = 0;
	char *full_path = NULL;

	while (1)
	{
		if (isatty(0))
		{
			_puts("$$ ");
		}
		chars_n = getline(&line, &n, stdin);
		if (chars_n == -1)
		{
			if (isatty(0))
				_puts("\n");
			free(line);
			exit(1);
		}
		line[chars_n - 1] = '\0';
		if (!tokenize(line, argvv))
		{
			free(line);
			line = NULL;
			continue;
		}
		if (if_exit(argvv[0]))
			exit(2);
		if (stat(argvv[0], &st) == 0)
			execute(argvv, argvv[0]);
		
        else
		{

			full_path = _which(argvv);
			if (!full_path)
			{
				print_error(argv[0], pnum, argvv[0]);
				continue;
			}
			execute(argvv, full_path);
			
		}	
		free(line);
		line = NULL;
		n = 0;
		pnum++;
		if (full_path)
			free(full_path);
	}
	free(line);
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
