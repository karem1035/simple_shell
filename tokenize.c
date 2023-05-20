#include "shell.h"
/**
 * tokenize - splits line into tokens according to a delimeter
 * @line: line to split
 * @argvv: array to put the tokens in
 * Return: array of tokens
 */
char **tokenize(char *line, char *argvv[])
{
	char *token = strtok(line, " \n");
	int i = 0;

	if (!token)
		return (0);

	while (token && i < MAX_TOKENS)
	{
		argvv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argvv[i] = NULL;

	return (argvv);
}


void freeargvv(char **argvv)
{
	size_t i;

	if (!argvv)
		return;
	for (i = 0; argvv && argvv[i]; i++)
	{
		free(argvv[i]);
		argvv[i] = NULL;
	}
	free(argvv);
	argvv = NULL;
}
