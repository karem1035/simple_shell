#include "shell.h"


/**
 * _which - search and append command to the suitable directory in
 * path
 * @argvv: list of arguments
 * @env: environ array
 * Return: 1 at success and 0 if failure
 */
int _which(char *argvv[], char **env)
{
	char *dir = NULL;
	char *path = _getenv("PATH", env), *path_copy;
	char *token;
	char delim[] = ":";
	struct stat sb;

	if (!path)
		return (0);

	path_copy = _strdup(path);
	token = strtok(path_copy, delim);
	while (token)
	{
		dir = malloc(_strlen(token) + _strlen(argvv[0]) + 2);
		if (!dir)
		{
			free(path_copy);
			return (0);
		}
		dir = _strcpy(dir, token);
		_strcat(dir, "/");
		_strcat(dir, argvv[0]);
		if (stat(dir, &sb) == 0 && !access(dir, X_OK))
		{
			argvv[0] = dir;
			execute(argvv, env);
			free(dir);
			free(path_copy);
			return (1);
		}
		free(dir);
		token = strtok(NULL, delim);
	}
	free(path_copy);
	return (0);
}
