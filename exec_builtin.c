#include "shell.h"
/**
 * exec_builtin - executes a builtin command
 * @argv: list of string arguments
 * @command: the command to exec
 *
 *Return: nothing
*/
void exec_builtin(char *command)
{
	int (*fun)(char *command);

	fun = _getfunc(command);
	if (fun != NULL)
	{
		fun(command);
		return;
	}
}
