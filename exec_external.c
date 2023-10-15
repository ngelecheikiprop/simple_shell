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
	    free(argv);
	  }
	}
	else if (argv != NULL)
	{
		fprintf(stderr, "%s: not found\n", argv[0]);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

