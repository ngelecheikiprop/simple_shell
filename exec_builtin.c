#include "shell.h"
/**
 * exec_builtin - executes a builtin command
 * @argv: list of string arguments
 * @command: the command to exec
 *
 *Return: nothing
*/
void exec_builtin(char **argv)
{
	int (*fun)(char **argv);

	fun = _getfunc(argv[0]);
	if (fun != NULL)
	{
		fun(argv);
		return;
	}
}
