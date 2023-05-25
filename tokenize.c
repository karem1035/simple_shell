#include "shell.h"
/**
 * tokenize - splits line into tokens according to a delimeter
 * @line: line to split
 * @argvv: array to put the tokens in
 * @input_size: input_size
 * Return: array of tokens
 */
char **tokenize(char *line, char *argvv[], ssize_t input_size)
{
	char *token = strtok(line, " ");
	int i = 0;

	line[input_size - 1] = '\0';
	if (!token)
		return (0);

	while (token && i < MAX_TOKENS)
	{
		argvv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argvv[i] = NULL;

	return (argvv);
}
/**
 * freeargvv - frees argvv array
 * @argvv: argvv array
 */
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
