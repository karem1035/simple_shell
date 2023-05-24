#include "shell.h"
/**
 * tokenize - splits line into tokens according to a delimeter
 * @line: line to split
 * @argvv: array to put the tokens in
 * Return: array of tokens
 */
char **tokenize(char *line, char *argvv[])
{
	char *token = strtok(line, " ");
	int i = 0;

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
/**
 * _strncmp - compares the 1st n bytes of 2 strs
 * @s1: str 1
 * @s2: str 2
 * @n: bytes to compare
 * Return: 0 if success, different chars subtraction if failure
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
