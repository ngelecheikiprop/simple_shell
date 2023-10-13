#include "shell.h"
/**
 * exec - execute a command
 * @argv: the array of commands
 * @env: the environment
 *
 * Return: nothing
*/
void exec(char **argv, char **env)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		execve(argv[0], argv, env);
	}
	else
	{
		waitpid(child, &status, 0);
		free(argv);
	}
}
