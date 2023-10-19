#include "shell.h"
/**
 * exec - execute a command
 * @argv: the array of commands
 * @env: the environment
 *
 * Return: nothing
*/
void exec_external(char **argv)
{
	pid_t child;
	int status;
	char **envp = environ;
	char *file_stat = file_exists(argv);

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
	  }
			free(file_stat);
	}
}

