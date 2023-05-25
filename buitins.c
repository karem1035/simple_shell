#include "shell.h"
/**
 * _ENV - prints environment variables from
 * environ and you don't need env argument
 * @env: environ array
 * Return: 0 always
 */
int _ENV(char *env[])
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
/**
 * MY_EXIT - after checking if the command is a built_in
 *		KARIM should give me tokenized command line to handle
 *		the exit status
 * @argvv: array of tokenized command
 * @env: environ array
 * @line: command line
 * Return: -1 if command is not right
 */
int MY_EXIT(char *argvv[], char __attribute__((unused)) **env, char *line)
{
	int status_code;
	int argcc = 0;
	int i = 0;

	for (i = 0; argvv[i]; i++)
		argcc++;

	if (argcc > 2 || (argcc == 2 && !is_integer(argvv[1])))
	{
		write(STDERR_FILENO, "Usage: exit [status]\n", 21);
		return (-1);
	}

	else if (argcc == 2)
	{
		status_code = _atoi(argvv[1]);
		free(line);
		_exit(status_code);

	}
	else
	{
		free(line);
		_exit(EXIT_SUCCESS);
	}
	return (1);
}
