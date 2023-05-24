#include "shell.h"

/**
 * _CD - change current directory to a desired one
 * @argvv: array of tokenized command
 * @env: environ array
 * @line: a line to be freed.
 * Return: 0 if success, -1 if failure
 */
int _CD(char *argvv[], char **env, char __attribute__((unused)) *line)
{
	int i, argcc = 0, result;
	char *o_PWD = _getenv("OLDPWD", env), *cwd = NULL;

	for (i = 0; argvv[i]; i++)
		argcc++;
	if (argcc > 2)
	{
		write(STDERR_FILENO, "Usage: exit [DIRECTORY]\n", 24);
		return (-1);
	}
	if (!o_PWD)
		o_PWD = _strdup(_getenv("HOME", env));
	if (argcc == 1)
	{
		result = chdir(_getenv("HOME", env));
	}
	else if (_strcmp(argvv[1], "-") == 0)
	{
		result = chdir(o_PWD);
		write(STDOUT_FILENO, o_PWD, _strlen(o_PWD));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		result = chdir(argvv[1]);
	if (result != 0)
	{
		perror(argvv[0]);
		return (-1);
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror(argvv[0]);
		return (-1);
	}
	_setenv("OLDPWD", o_PWD, 1, env);
	_setenv("PWD", cwd, 1, env);
	free(o_PWD);
	free(cwd);
	return (0);
}

/**
 * _ENV - prints environment variables from
 * environ and you don't need env argument
 * @argvv: array of tokenized command
 * @env: environ array
 * @line: a line to be freed.
 * Return: 0 always
 */
int _ENV(char __attribute__((unused)) *argvv[], char *env[], char *line)
{
	int i = 0;
	(void) line;
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
 * @line: a line to be freed.
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
