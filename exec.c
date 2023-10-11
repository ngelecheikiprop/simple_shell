#include "shell.h"
/**
 * exec - execute a command
 * @argv: the array of commands
 * @env: the environment
 *
 * Return: nothing
*/
void exec(char **argv)
{
	pid_t child;
	int status;
	char *file_stat = file_info(argv);
	char **envp = environ;

	if (file_stat != NULL)
	{
		child = fork();
		if (child == 0)
		{
			execve(file_stat, argv, envp);
		}
		else
		{
			waitpid(child, &status, 0);
			free(argv);
		}
	}
}
