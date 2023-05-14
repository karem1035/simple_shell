#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - UNIX command line interpreter.
 * @argc: arg count
 * @argv: args vector
 * Return: 0 all time
 */
int main(int argc, char *argv[])
{
	char *argvv[2];
	char *line = NULL;
	size_t n = 0;
	int id, stat;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&line, &n, stdin);
		line[strcspn(line, "\n")] = '\0';
		argvv[0] = line;
		argvv[1] = NULL;
		id = fork();
		if (id == 0)
		{
			if (execve(argvv[0], argvv, NULL) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			}
		}
		else
			wait(&stat);
	}

	free(line);
	return (0);
}
