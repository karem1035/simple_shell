#include "shell.h"

/**
 * _CD - change current directory to a desired one
 * @argvv: array of tokenized command
 * Return: 0 if success, -1 if failure
 */
int _CD(char *argvv[])
{
	char *o_PWD = _getenv2("PWD"), *HOME = _getenv2("HOME"), *new = NULL;
	char n_PWD[1024];

	if(!argvv[1] || _strcmp(argvv[1], "~") == 0 || _strcmp(argvv[1], "") == 0)
		new = HOME;
	else if (_strcmp(argvv[1], "-") == 0)
	{
		new = _getenv2("OLDPWD");
		if (!new)
		{
			perror("cd");
			return (-1);
		}

	}
	else
		new = argvv[1];

	if (chdir(new) != 0)
	{
		perror("cd");
		return(-1);
	}
	if (!getcwd(n_PWD, sizeof(n_PWD)))
	{
		perror("cd");
		return(-1);
	}
	_setenv("OLDPWD", o_PWD, 1);
	_setenv("PWD", n_PWD, 1);
	return(0);
}

/**
 * _ENV - prints environment variables from
 * environ and you don't need env argument
 *
 */
int _ENV(char __attribute__((unused)) *argvv[])
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		i++;
	}
	return(0);
}
/**
 * _EXIT - after checking if the command is a built_in
 *		KARIM should give me tokenized command line to handle
 *		the exit status
 * @argvv: array of tokenized command
 * Return: -1 if command is not right
 */
int _EXIT(char *argvv[])
{
	int status_code;
	int argcc = 0;
	int i = 0;

	for (i = 0; argvv[i]; i++)
		argcc++;

	if (argcc > 2 || (argcc == 2 && !is_integer(argvv[1])))
	{
		write(STDERR_FILENO, "Usage: exit [status]\n", 21);
		return (-1); /*this means the function fails ya karim */
	}				/*elmafrood ba2a y3mel continue fy elloop el2asasya fy shell.c*/
	/*and free(line) in shell.c at failure*/
	else if (argcc == 2)
	{
		status_code = _atoi(argvv[1]);
		exit(status_code);
		/*you can make the status code an argument it's up to you*/
	}
	else
		exit(EXIT_SUCCESS);
	return (1);
}
