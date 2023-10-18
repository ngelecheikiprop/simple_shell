#include "shell.h"
/**
 * _getfunc - determines whether args is a builtin function
 * @command: double pointer to args
 * Return: 0 0r 1
*/
int (*_getfunc(char *command))(char **args)
{
	int i = 0;

	BuiltinCommand commands[] = {
		{"cd", hsh_cd},
		{"exit", hsh_exit},
		{NULL, NULL}
		};
	while (commands[i].name)
	{
		if (strcmp(command, commands[i].name) == 0)
		{
			return (commands[i].function);
		}
		i++;
	}
	return (NULL);
}