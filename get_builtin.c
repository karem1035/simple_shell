#include "shell.h"

/**
 * is_builtin - checks if a command is built in or not and
 *		then gets the suitable functionfor this command
 * @argvv: tokenized command line
 * @env: environ array
 * @line: a line to be freed.
 * Return: 0 if failure, built in functions return value if success
 */
int is_builtin(char *argvv[], char **env, char *line)
{
	bin_cmd bin_cmds[] = {
			{"cd", _CD},
			{"env", _ENV},
			{"exit", MY_EXIT},
			{NULL, NULL},
		};
	int i;

	for (i = 0; bin_cmds[i].cmd && bin_cmds[i].function_to_execute_on_cmd; i++)
	{
		if (_strcmp(argvv[0], bin_cmds[i].cmd) == 0)
		{
			return (bin_cmds[i].function_to_execute_on_cmd(argvv, env, line));
		}
	}
	return (0);
}
