#include "shell.h"
/**
 * main - UNIX command line interpreter.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * @env: environ array
 * Return: 0 all time
 */
int main(int argc, char *argv[], char *env[])
{
	char *argvv[MAX_TOKENS], *line = NULL;
	size_t buffer_size = 0;
	ssize_t input_size = 0;
	struct stat st;
	int process_number = 1;

	if (argc < 1)
		return (-1);
	signal(SIGINT, signalhandler);
	while (1)
	{
		prompt();
		input_size = getline(&line, &buffer_size, stdin);
		if (input_size < 0)
		{
			free(line);
			break;
		}
		if (!tokenize(line, argvv, input_size))
		{
			free(line);
			continue;
		}
		if (_strcmp(argvv[0], "exit") == 0)
		{
	            free(line);
        	    _exit(0);
		}
		if (_strcmp(argvv[0], "env") == 0)
        	{
			for (i = 0; env[i]; i++)
       	     		{
				write(STDOUT_FILENO, environ[i], _strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
            		continue;
		}
		if (stat(argvv[0], &st) == 0)
			execute(argvv, env);
		else if (!_which(argvv, env))
		{
			print_error(argv[0], process_number, argvv[0]);
			continue;
		}
		free(line);
		reset_bufsize_inc_pnum(&buffer_size, &process_number);
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
/**
 * reset_bufsize_inc_pnum - reset_bufsize_inc_pnum
 * @buffer_size: buffer_size
 * @pnum: process number
 */
void reset_bufsize_inc_pnum(size_t *buffer_size, int *pnum)
{
	*buffer_size = 0;
	*pnum = *pnum + 1;
}
