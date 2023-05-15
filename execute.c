#include "shell.h"
/**
 * execute - execute programm.
 * @argvv: the executable command.
 * @argv: name of the file.
 * Return: void.
 */
void execute(char *argv, char *argvv[])
{
	int id, stat;
	char *filename = argv;

	id = fork();
	if (id == -1)
		exit(1);

	if (id == 0)
	{
		if (execve(argvv[0], argvv, environ) == -1)
		{
			write(STDOUT_FILENO, filename, _strlen(filename));
			write(STDOUT_FILENO, ": ", 2);
			perror("");
			exit(1);
		}
	}
	else
	{
		wait(&stat);
	}

}
/**
 * _strlen - calulates the length of string.
 * @s: string inut.
 *
 * Description: takes string as parameter input,
 * loops into it to calculate its length.
 * Return: i - integer with the length value.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
