#include "shell.h"
/**
 * main -this is the entry point
 * @ac: this if the argument count
 * @av: this contain the arguments
 * @env: the environment variable
 *
 * Return: nothing
*/
int main(int ac, char **av, char **env)
{
	size_t count;
	char *buffer = NULL;
	char **argv = NULL;
	char *delim = " ";
	char *prompt = "$";
	char *dir = NULL;
	dir_node *head;

	head = NULL;
	(void)ac;
	(void)av;
	head = _path_list(env);
	while (1)
	{
		dir = NULL;
		buffer = NULL;
		count = 0;
		argv = NULL;
		count = 0;
		if (isatty(fileno(stdin)))
		{
			write(STDOUT_FILENO, prompt, 1);
			fflush(stdout);
		}
		if (getline(&buffer, &count, stdin) == EOF)
		{
			free(buffer);
			exit(100);
		}
		strtok(buffer, "\n");
		argv = list_of_words(buffer, delim);
		dir = _getdir(head, argv[0]);
		if (dir != NULL)
		{
			argv[0] = dir;
		}
		else
		{
			perror("command not found\n");
			continue;
		}
		exec(argv, env);
		free(buffer);
	}
	return (0);
}
