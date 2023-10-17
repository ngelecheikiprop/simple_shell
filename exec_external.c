#include "shell.h"
/**
 * exec - execute a command
 * @argv: the array of commands
 * @env: the environment
 *
 * Return: nothing
*/
int exec_external(char **argv)
{
	pid_t child;
	int status;
	char **envp = environ;

	  child = fork();
	  if (child == 0)
	  {
	    execve(argv[0], argv, envp);
	  }
	  else
	  {
	    waitpid(child, &status, 0);
	    free(argv);
	  }
	return (0);
}

