#include "shell.c"

/**
 * is_builtin - checks if a command is built in or not and
 *		then gets the suitable functionfor this command
 * @line: untokenized command line 
 * @argvv: tokenized command line
 * Return: 0 if failure, built in functions return value if success
 */
int is_builtin(char *argvv[])
{
	bin_cmd bin_cmds[] = 
	{
		{"cd", _CD},
		{"exit", _Exit},
		{"env", _ENV},
		{NULL, NULL},
	};
	int i;



	for (i = 0; bin_cmds[i].cmd && bin_cmds[i].function_to_execute_on_cmd; i++)
	{
		if (_strcmp(argvv[0], bin_cmds[i].cmd) == 0)
		{
			return (bin_cmds[i].function_to_execute_on_cmd(argvv));
		}
	}
	return (0); 
}
