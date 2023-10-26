#include "shell.h"

/**
 * main -this is the entry point
 * @ac: this if the argument count
 * @av: this contain the arguments
 * @env: the environment variable
 *
 * Return: nothing
 */
int main(int ac, char **av)
{
	size_t count;
	char *buffer = NULL;
	char **argv;
	char *delim = " ";
	char *prompt = "$";

	(void)ac;
	(void)av;
	while (1)
	{
		buffer = NULL;
		count = 0;
		if (isatty(fileno(stdin)))
		{
			write(STDOUT_FILENO, prompt, 1);
			fflush(stdout);
		}
		if (getline(&buffer, &count, stdin) == EOF)
		{
			free(buffer);
			return (0);
		}
		argv = list_of_words(buffer, delim);
		if (argv == NULL)
		{
			free(buffer);
			continue;
		}
		if (_getfunc(argv[0]))
		{
			free(buffer);
			exec_builtin(argv);
			free(argv);
		}
		else if (file_exists(argv))
		{
			free(buffer);
			exec_external(argv);
			free(argv);
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: not found\n", av[0], argv[0]);
			free(buffer);
			free(argv);
		}
	}
	return (0);
}
